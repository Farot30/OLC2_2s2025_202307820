#include "../../AST/ast.h"
#include "../tabla_simbolo.h"
#include "../semantico.h"
#include "../../AST/err.h"
#include "Llamadas.h"
#include "../../simbolos/Evaluador.h"
#include <stdio.h>
#include <string.h>

// Función para evaluar la llamada y obtener el valor de retorno
ValorSimbolo EvaluarLlamadaFuncion(NodoAST* nodo) {
    ValorSimbolo resultadoFuncion;
    memset(&resultadoFuncion, 0, sizeof(ValorSimbolo));
    
    if (!nodo || nodo->tipo != AST_LLAMADA) {
        printf("[ERROR] Nodo inválido para llamada a función\n");
        return resultadoFuncion;
    }

    if (nodo->num_hijos < 1 || nodo->hijos[0]->tipo != AST_IDENTIFICADOR) {
        printf("[ERROR] Llamada a función requiere un identificador\n");
        addError("Llamada a función inválida", ambitoActual(), nodo->linea, nodo->columna);
        return resultadoFuncion;
    }

    NodoAST* idNodo = nodo->hijos[0];
    printf("[DEBUG] Evaluando llamada a función: %s\n", idNodo->valor);

    // Buscar la función en la tabla de símbolos
    Simbolo* simboloFuncion = buscarSimbolo(idNodo->valor);
    if (!simboloFuncion) {
        char msg[100];
        snprintf(msg, sizeof(msg), "Función '%s' no declarada", idNodo->valor);
        addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
        printf("[ERROR] %s\n", msg);
        return resultadoFuncion;
    }

    // Verificar que sea una función con retorno
    if (simboloFuncion->clase != SIMBOLO_FUNCION) {
        char msg[100];
        snprintf(msg, sizeof(msg), "'%s' no es una función con retorno", idNodo->valor);
        addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
        printf("[ERROR] %s\n", msg);
        return resultadoFuncion;
    }

    // Procesar parámetros si existen
    NodoAST* parametrosLlamada = (nodo->num_hijos > 1) ? nodo->hijos[1] : NULL;
    
    // Crear un nuevo ámbito para la ejecución de la función
    printf("[DEBUG] Entrando al ámbito de la función '%s'\n", idNodo->valor);
    contexto_funcion++;
    entrarAmbito(simboloFuncion->nombre);
    
    // Procesar parámetros si existen
    if (parametrosLlamada && parametrosLlamada->tipo == AST_LISTA_PARAMETROS) {
        
        // Los parámetros tienen como ámbito el nombre de la función
        int numParametros = 0;
        char* nombresParametros[100]; // Asumimos máximo 100 parámetros
        TipoDato tiposParametros[100];
        
        // Recorrer la tabla de símbolos buscando parámetros
        for (int i = 1; i <= 1000; i++) { // Límite arbitrario
            Simbolo* simbolo = buscarSimboloPorId(i);
            if (simbolo && simbolo->clase == SIMBOLO_VARIABLE && 
                strcmp(simbolo->ambito, simboloFuncion->nombre) == 0) {
                
                // Verificar que el símbolo sea parámetro, no variable local
                // Podemos asumir que los primeros símbolos en el ámbito son parámetros
                nombresParametros[numParametros] = simbolo->nombre;
                tiposParametros[numParametros] = simbolo->tipo;
                numParametros++;
            }
        }
        
        // Verificar que el número de parámetros coincida
        if (parametrosLlamada->num_hijos != numParametros) {
            char msg[200];
            snprintf(msg, sizeof(msg), "Número incorrecto de parámetros: esperados %d, encontrados %d",
                    numParametros, parametrosLlamada->num_hijos);
            addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
            printf("[ERROR] %s\n", msg);
            contexto_funcion--;
            salirAmbito();
            return resultadoFuncion;
        }
        
        // Procesar cada parámetro
        for (int i = 0; i < parametrosLlamada->num_hijos; i++) {
            // Evaluar el argumento pasado
            ValorSimbolo valorArg = evaluarExpr(parametrosLlamada->hijos[i]);
            if (!valorArg.inicializado) {
                char msg[200];
                snprintf(msg, sizeof(msg), "Valor no inicializado para parámetro '%s'", 
                         nombresParametros[i]);
                addError(msg, ambitoActual(), parametrosLlamada->hijos[i]->linea, 
                         parametrosLlamada->hijos[i]->columna);
                printf("[ERROR] %s\n", msg);
                continue;
            }
            
            // Verificar compatibilidad de tipos
            if (valorArg.tipo != tiposParametros[i] && 
                !esWidening(valorArg.tipo, tiposParametros[i])) {
                char msg[200];
                snprintf(msg, sizeof(msg), "Tipo incompatible para parámetro '%s': esperado %s, encontrado %s",
                        nombresParametros[i], nombreTipo(tiposParametros[i]), 
                        nombreTipo(valorArg.tipo));
                addError(msg, ambitoActual(), parametrosLlamada->hijos[i]->linea, 
                         parametrosLlamada->hijos[i]->columna);
                printf("[ERROR] %s\n", msg);
                continue;
            }
            
            // Declarar la variable en el ámbito de la función con el valor del argumento
            // Asegurarnos de inicializar el símbolo del parámetro con el valor correcto
            Simbolo* paramSim = buscarSimbolo(nombresParametros[i]);
            if (paramSim) {
                // Si es necesario, convertir el valor
                if (valorArg.tipo != paramSim->tipo && 
                    esWidening(valorArg.tipo, paramSim->tipo)) {
                    valorArg = convertirValor(valorArg, paramSim->tipo);
                }
                
                paramSim->valor = valorArg;
                paramSim->inicializado = 1;
                paramSim->valor.inicializado = 1;
                printf("[DEBUG] Parámetro '%s' inicializado con valor\n", nombresParametros[i]);
            } else {
                printf("[ERROR] No se encontró el parámetro '%s' en la tabla de símbolos\n", 
                       nombresParametros[i]);
                
                // Intentar crear el parámetro si no existe
                agregarSimboloDetallado(nombresParametros[i], SIMBOLO_VARIABLE, 
                                       tiposParametros[i], ambitoActual(), 
                                       nodo->linea, nodo->columna);
                
                paramSim = buscarSimbolo(nombresParametros[i]);
                if (paramSim) {
                    paramSim->valor = valorArg;
                    paramSim->inicializado = 1;
                    paramSim->valor.inicializado = 1;
                    printf("[DEBUG] Parámetro '%s' creado e inicializado\n", nombresParametros[i]);
                }
            }
        }
    }

    // Obtener el bloque de la función
    NodoAST* bloqueNodo = simboloFuncion->nodo_bloque;
    if (!bloqueNodo) {
        printf("[ERROR] La función '%s' no tiene un bloque asociado\n", idNodo->valor);
        addError("Función sin bloque de código", ambitoActual(), idNodo->linea, idNodo->columna);
        contexto_funcion--;
        salirAmbito();
        return resultadoFuncion;
    }

    // Ejecutar el bloque de la función
    printf("[DEBUG] Ejecutando bloque de la función '%s'\n", idNodo->valor);

    hayRetorno = 0;
    memset(&valorRetorno, 0, sizeof(ValorSimbolo));
    ResultadoEjecucion resEjec = ejecutarNodoAST(bloqueNodo);
    
    // Verificar si hubo un return
    if (resEjec == EJEC_RETURN) {
        printf("[DEBUG] Se detectó return en función '%s'\n", idNodo->valor);

        printf("[DEBUG] Resultado de ejecución: %d\n", resEjec);
        printf("[DEBUG] hayRetorno: %d, valorRetorno.inicializado: %d\n", hayRetorno, valorRetorno.inicializado);
        
        // Verificar sólo si el valor está inicializado, que es lo importante
        if (valorRetorno.inicializado) {
            // El código para verificar compatibilidad y conversión queda igual
            if (valorRetorno.tipo == simboloFuncion->tipo || esWidening(valorRetorno.tipo, simboloFuncion->tipo)) {
                // Si es necesario, hacer conversión de tipo
                if (valorRetorno.tipo != simboloFuncion->tipo) {
                    ValorSimbolo valorConvertido = convertirValor(valorRetorno, simboloFuncion->tipo);
                    
                    // Liberar memoria si hay cadenas involucradas
                    if (valorRetorno.tipo == TIPO_STRING && valorRetorno.v.s) {
                        free(valorRetorno.v.s);
                    }
                    
                    valorRetorno = valorConvertido;
                }
                
                // Asignar el valor retornado al resultado
                resultadoFuncion = valorRetorno;
                printf("[DEBUG] Función '%s' retorna valor de tipo %s\n", 
                      idNodo->valor, nombreTipo(resultadoFuncion.tipo));
                
                // Mostrar el valor retornado para depuración
                switch (resultadoFuncion.tipo) {
                    case TIPO_INT:
                        printf("[DEBUG] Valor retornado: %d\n", resultadoFuncion.v.i);
                        break;
                    case TIPO_FLOAT:
                        printf("[DEBUG] Valor retornado: %f\n", resultadoFuncion.v.f);
                        break;
                    case TIPO_DOUBLE:
                        printf("[DEBUG] Valor retornado: %lf\n", resultadoFuncion.v.d);
                        break;
                    case TIPO_CHAR:
                        printf("[DEBUG] Valor retornado: '%c'\n", resultadoFuncion.v.c);
                        break;
                    case TIPO_BOOLEAN:
                        printf("[DEBUG] Valor retornado: %s\n", resultadoFuncion.v.b ? "true" : "false");
                        break;
                    case TIPO_STRING:
                        printf("[DEBUG] Valor retornado: \"%s\"\n", resultadoFuncion.v.s ? resultadoFuncion.v.s : "(null)");
                        break;
                    default:
                        printf("[DEBUG] Valor retornado: <tipo desconocido>\n");
                        break;
                }
            } else {
                char msg[200];
                snprintf(msg, sizeof(msg), "Tipo de retorno incompatible: esperado %s, encontrado %s",
                        nombreTipo(simboloFuncion->tipo), nombreTipo(valorRetorno.tipo));
                addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
                printf("[ERROR] %s\n", msg);
                
                // Limpiar el valor si es una cadena
                if (valorRetorno.tipo == TIPO_STRING && valorRetorno.v.s) {
                    free(valorRetorno.v.s);
                    valorRetorno.v.s = NULL;
                }
            }
        } else {
            printf("[ERROR] Valor de retorno no inicializado en función '%s'\n", idNodo->valor);
            addError("Valor de retorno no inicializado", ambitoActual(), idNodo->linea, idNodo->columna);
        }
    } else {
        printf("[ADVERTENCIA] No se detectó return en función '%s' con tipo de retorno\n", idNodo->valor);
        
        // Para funciones no void, debería haber un return
        if (simboloFuncion->tipo != TIPO_VOID) {
            char msg[200];
            snprintf(msg, sizeof(msg), "La función '%s' con tipo de retorno %s debe tener un return",
                    idNodo->valor, nombreTipo(simboloFuncion->tipo));
            addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
            printf("[ERROR] %s\n", msg);
        }
    }

    // Salir del ámbito de la función
    printf("[DEBUG] Saliendo del ámbito de la función '%s'\n", idNodo->valor);
    contexto_funcion--;
    salirAmbito();

    return resultadoFuncion;
}

// Función para ejecutar la llamada sin capturar el valor (como sentencia)
ResultadoEjecucion EjecutarLlamadas(NodoAST* nodo) {
    if (!nodo || nodo->tipo != AST_LLAMADA) {
        printf("[ERROR] Nodo inválido para llamada a función\n");
        return EJEC_OK; 
    }

    // Evaluar la llamada a función (que procesa parámetros y ejecuta el cuerpo)
    // pero descartamos el valor de retorno ya que estamos ejecutando como sentencia
    EvaluarLlamadaFuncion(nodo);
    
    return EJEC_OK;
}