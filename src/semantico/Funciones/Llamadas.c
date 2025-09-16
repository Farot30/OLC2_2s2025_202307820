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

    if (simboloFuncion->clase != SIMBOLO_FUNCION) {
        char msg[100];
        snprintf(msg, sizeof(msg), "'%s' no es una función con retorno", idNodo->valor);
        addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
        printf("[ERROR] %s\n", msg);
        return resultadoFuncion;
    }

    NodoAST* parametrosLlamada = (nodo->num_hijos > 1) ? nodo->hijos[1] : NULL;

    // Obtener parámetros desde el AST de la función
    NodoAST* parametrosDef = simboloFuncion->nodo_params;
    int numParametros = parametrosDef ? parametrosDef->num_hijos : 0;

    // Verificar número de parámetros
    int numArgs = (parametrosLlamada && parametrosLlamada->tipo == AST_LISTA_PARAMETROS) ? parametrosLlamada->num_hijos : 0;
    if (numArgs != numParametros) {
        char msg[200];
        snprintf(msg, sizeof(msg), "Número incorrecto de parámetros: esperados %d, encontrados %d",
                numParametros, numArgs);
        addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
        printf("[ERROR] %s\n", msg);
        return resultadoFuncion;
    }

    // Crear un nuevo ámbito para la ejecución de la función
    printf("[DEBUG] Entrando al ámbito de la función '%s'\n", idNodo->valor);
    contexto_funcion++;
    entrarAmbito(simboloFuncion->nombre);

    // Declarar y asignar los parámetros en el nuevo ámbito
    for (int i = 0; i < numParametros; i++) {
        NodoAST* param = parametrosDef->hijos[i];
        NodoAST* tipoParam = param->hijos[0];
        NodoAST* idParam = param->hijos[1];
        const char* nombreParam = idParam->valor;
        TipoDato tipoParametro = obtenerTipoDesdeString(tipoParam->valor);

        ValorSimbolo valorArg = evaluarExpr(parametrosLlamada->hijos[i]);
        if (!valorArg.inicializado) {
            char msg[200];
            snprintf(msg, sizeof(msg), "Valor no inicializado para parámetro '%s'", nombreParam);
            addError(msg, ambitoActual(), parametrosLlamada->hijos[i]->linea, parametrosLlamada->hijos[i]->columna);
            printf("[ERROR] %s\n", msg);
            continue;
        }
        if (valorArg.tipo != tipoParametro && !esWidening(valorArg.tipo, tipoParametro)) {
            char msg[200];
            snprintf(msg, sizeof(msg), "Tipo incompatible para parámetro '%s': esperado %s, encontrado %s",
                    nombreParam, nombreTipo(tipoParametro), nombreTipo(valorArg.tipo));
            addError(msg, ambitoActual(), parametrosLlamada->hijos[i]->linea, parametrosLlamada->hijos[i]->columna);
            printf("[ERROR] %s\n", msg);
            continue;
        }
        // Declarar el parámetro en el ámbito de la función
        if (!buscarSimboloEnAmbito(nombreParam, ambitoActual())) {
            agregarSimboloDetallado(nombreParam, SIMBOLO_VARIABLE, tipoParametro, ambitoActual(), nodo->linea, nodo->columna);
        }
        Simbolo* paramSim = buscarSimbolo(nombreParam);
        if (paramSim) {
            if (valorArg.tipo != paramSim->tipo && esWidening(valorArg.tipo, paramSim->tipo)) {
                valorArg = convertirValor(valorArg, paramSim->tipo);
            }
            paramSim->valor = valorArg;
            paramSim->inicializado = 1;
            paramSim->valor.inicializado = 1;
            printf("[DEBUG] Parámetro '%s' inicializado con valor\n", nombreParam);
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

        if (valorRetorno.inicializado) {
            if (valorRetorno.tipo == simboloFuncion->tipo || esWidening(valorRetorno.tipo, simboloFuncion->tipo)) {
                if (valorRetorno.tipo != simboloFuncion->tipo) {
                    ValorSimbolo valorConvertido = convertirValor(valorRetorno, simboloFuncion->tipo);
                    if (valorRetorno.tipo == TIPO_STRING && valorRetorno.v.s) {
                        free(valorRetorno.v.s);
                    }
                    valorRetorno = valorConvertido;
                }
                resultadoFuncion = valorRetorno;
                printf("[DEBUG] Función '%s' retorna valor de tipo %s\n", idNodo->valor, nombreTipo(resultadoFuncion.tipo));
                switch (resultadoFuncion.tipo) {
                    case TIPO_INT: printf("[DEBUG] Valor retornado: %d\n", resultadoFuncion.v.i); break;
                    case TIPO_FLOAT: printf("[DEBUG] Valor retornado: %f\n", resultadoFuncion.v.f); break;
                    case TIPO_DOUBLE: printf("[DEBUG] Valor retornado: %lf\n", resultadoFuncion.v.d); break;
                    case TIPO_CHAR: printf("[DEBUG] Valor retornado: '%c'\n", resultadoFuncion.v.c); break;
                    case TIPO_BOOLEAN: printf("[DEBUG] Valor retornado: %s\n", resultadoFuncion.v.b ? "true" : "false"); break;
                    case TIPO_STRING: printf("[DEBUG] Valor retornado: \"%s\"\n", resultadoFuncion.v.s ? resultadoFuncion.v.s : "(null)"); break;
                    default: printf("[DEBUG] Valor retornado: <tipo desconocido>\n"); break;
                }
            } else {
                char msg[200];
                snprintf(msg, sizeof(msg), "Tipo de retorno incompatible: esperado %s, encontrado %s",
                        nombreTipo(simboloFuncion->tipo), nombreTipo(valorRetorno.tipo));
                addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
                printf("[ERROR] %s\n", msg);
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
        if (simboloFuncion->tipo != TIPO_VOID) {
            char msg[200];
            snprintf(msg, sizeof(msg), "La función '%s' con tipo de retorno %s debe tener un return",
                    idNodo->valor, nombreTipo(simboloFuncion->tipo));
            addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
            printf("[ERROR] %s\n", msg);
        }
    }

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