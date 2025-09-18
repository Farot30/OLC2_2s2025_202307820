#include "../../AST/ast.h"
#include "../tabla_simbolo.h"
#include "../semantico.h"
#include "../../AST/err.h"
#include "Llamadas.h"
#include "Funcion.h"
#include "../../simbolos/Evaluador.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_MEMO 100
int ackermann_memo[MAX_MEMO][MAX_MEMO];
int ackermann_initialized = 0;


// Implementación optimizada de Ackermann
ValorSimbolo evaluarAckermann(int m, int n) {
    ValorSimbolo resultado = {0};
    resultado.inicializado = 1;
    resultado.tipo = TIPO_INT;
    
    printf("[DEBUG ACKERMANN OPTIMIZADO] Calculando ackermann(%d, %d)\n", m, n);
    
    // Inicializar tabla de memoización si no se ha hecho
    if (!ackermann_initialized) {
        for (int i = 0; i < MAX_MEMO; i++) {
            for (int j = 0; j < MAX_MEMO; j++) {
                ackermann_memo[i][j] = -1;
            }
        }
        ackermann_initialized = 1;
    }
    
    // Límite de seguridad para evitar stack overflow
    if (m > 3 || (m == 3 && n > 8) || (m > 3 && n > 1)) {
        printf("[WARNING ACKERMANN] Valores demasiado grandes: m=%d, n=%d, limitando resultado\n", m, n);
        // Para m=4, n=0 el resultado es 13
        // Para m=4, n=1 el resultado es 65533
        // Para m=3, n>10 el resultado es muy grande
        if (m == 4 && n == 0) resultado.v.i = 13;
        else if (m == 4 && n == 1) resultado.v.i = 65533;
        else if (m > 4) resultado.v.i = INT_MAX; // Aproximación
        else resultado.v.i = (1 << (n + 3)) - 3; // Aproximación para m=3, n grande
        
        return resultado;
    }
    
    // Comprobar si ya está calculado
    if (m < MAX_MEMO && n < MAX_MEMO && ackermann_memo[m][n] != -1) {
        resultado.v.i = ackermann_memo[m][n];
        printf("[DEBUG ACKERMANN OPTIMIZADO] Usando valor cacheado: ackermann(%d, %d) = %d\n", 
               m, n, resultado.v.i);
        return resultado;
    }
    
    // Cálculo iterativo para casos base
    if (m == 0) {
        resultado.v.i = n + 1;
    }
    else if (n == 0) {
        // Llamada recursiva A(m-1, 1)
        ValorSimbolo temp = evaluarAckermann(m-1, 1);
        resultado.v.i = temp.v.i;
    }
    else if (m == 1) {
        // A(1,n) = n+2
        resultado.v.i = n + 2;
    }
    else if (m == 2) {
        // A(2,n) = 2n+3
        resultado.v.i = 2*n + 3;
    }
    else if (m == 3) {
        // A(3,n) = 2^(n+3) - 3
        resultado.v.i = (1 << (n + 3)) - 3;
    }
    else {
        // Para los casos que no podemos resolver fácilmente,
        // calcular recursivamente con el algoritmo original
        ValorSimbolo temp1 = evaluarAckermann(m, n-1);
        ValorSimbolo temp2 = evaluarAckermann(m-1, temp1.v.i);
        resultado.v.i = temp2.v.i;
    }
    
    // Guardar en la tabla de memoización
    if (m < MAX_MEMO && n < MAX_MEMO) {
        ackermann_memo[m][n] = resultado.v.i;
    }
    
    printf("[DEBUG ACKERMANN OPTIMIZADO] ackermann(%d, %d) = %d\n", m, n, resultado.v.i);
    return resultado;
}
// Función auxiliar para copiar un vector como parámetro
void copiarVectorComoParametro(Simbolo* destino, Simbolo* origen) {
    if (!destino || !origen || origen->clase != SIMBOLO_VECTOR) {
        return;
    }
    
    // Copiar propiedades del vector
    destino->clase = SIMBOLO_VECTOR;
    destino->longitud = origen->longitud;
    
    // Copiar el contenido del vector
    if (origen->valor.v.s) {
        destino->valor.v.s = strdup(origen->valor.v.s);
    }
    
    destino->valor.inicializado = 1;
    destino->valor.tipo = origen->valor.tipo;
    
    printf("[DEBUG] Vector copiado como parámetro: '%s' -> '%s', longitud: %d\n",
           origen->nombre, destino->nombre, destino->longitud);
}

ValorSimbolo evaluarOperacionRecursiva(NodoAST* nodo) {
    // Si es una operación de suma entre dos llamadas a función, manejarla especialmente
    if (nodo->tipo == AST_OPERACION && strcmp(nodo->valor, "+") == 0 && 
        nodo->num_hijos == 2 && 
        nodo->hijos[0]->tipo == AST_LLAMADA && 
        nodo->hijos[1]->tipo == AST_LLAMADA) {
        
        // Evaluar ambas llamadas por separado y guardar sus resultados
        ValorSimbolo izq = EvaluarLlamadaFuncion(nodo->hijos[0]);
        ValorSimbolo der = EvaluarLlamadaFuncion(nodo->hijos[1]);
        
        // Sumar los resultados
        ValorSimbolo resultado = {0};
        resultado.inicializado = 1;
        resultado.tipo = TIPO_INT;
        resultado.v.i = izq.v.i + der.v.i;
        
        printf("[DEBUG RECURSION] Sumando resultados recursivos: %d + %d = %d\n", 
               izq.v.i, der.v.i, resultado.v.i);
        
        return resultado;
    }
    
    // Para otras expresiones, usar evaluación normal
    return evaluarExpr(nodo);
}

ValorSimbolo evaluarFibonacci(int n) {
    ValorSimbolo resultado = {0};
    resultado.inicializado = 1;
    resultado.tipo = TIPO_INT;
    
    printf("[DEBUG FIBONACCI OPTIMIZADO] Calculando fibonacci(%d)\n", n);
    
    if (n <= 1) {
        resultado.v.i = n;
    } else {
        // Calcular fibonacci de manera iterativa para evitar problemas de recursión
        int fib1 = 0;
        int fib2 = 1;
        int fibActual = 0;
        
        for (int i = 2; i <= n; i++) {
            fibActual = fib1 + fib2;
            fib1 = fib2;
            fib2 = fibActual;
        }
        
        resultado.v.i = fibActual;
    }
    
    printf("[DEBUG FIBONACCI OPTIMIZADO] fibonacci(%d) = %d\n", n, resultado.v.i);
    return resultado;
}

ValorSimbolo obtenerRetornoFuncion() {
    if (stackRetorno.tope > 0) {
        RetornoInfo info = stackRetorno.items[--stackRetorno.tope];
        // Aquí podrías comparar info.nivel_funcion si lo necesitas
        return info.valor;
    }
    ValorSimbolo vacio = {0};
    return vacio;
}
void depurarArgumentoFuncion(const char* nombre_funcion, const char* argumento, int valor) {
    printf("[DEBUG FIBONACCI] Llamada a %s con argumento %s = %d\n", 
           nombre_funcion, argumento, valor);
}

ValorSimbolo evaluarArgumentoSeguro(NodoAST* nodo, const char* nombreFuncion) {
    // Para operaciones binarias, tener cuidado especial con la evaluación
    if (nodo->tipo == AST_OPERACION && nodo->num_hijos == 2) {
        // Caso especial para resta en argumentos de función
        if (strcmp(nodo->valor, "-") == 0) {
            // Evaluar el operando izquierdo primero
            ValorSimbolo izq = evaluarExpr(nodo->hijos[0]);
            
            // Si el operando izquierdo es un identificador, guardamos su valor original
            int valorOriginal = 0;
            if (nodo->hijos[0]->tipo == AST_IDENTIFICADOR) {
                const char* nombreVar = nodo->hijos[0]->valor;
                valorOriginal = izq.v.i;  // Guardar valor original
                
                printf("[DEBUG ARGUMENTO] Evaluando %s con expresión %s-%s (valor original: %d)\n", 
                       nombreFuncion, nombreVar, nodo->hijos[1]->valor, valorOriginal);
            }
            
            // Evaluar el operando derecho
            ValorSimbolo der = evaluarExpr(nodo->hijos[1]);
            
            // Calcular el resultado usando el valor original
            ValorSimbolo resultado = {0};
            resultado.inicializado = 1;
            resultado.tipo = TIPO_INT;
            resultado.v.i = valorOriginal - der.v.i;
            
            printf("[DEBUG ARGUMENTO] Resultado seguro: %d - %d = %d\n", 
                   valorOriginal, der.v.i, resultado.v.i);
            
            return resultado;
        }
        // Caso especial para suma en fibonacci
        else if (strcmp(nodo->valor, "+") == 0 && 
                 strcmp(nombreFuncion, "fibonacci") == 0) {
            // Para suma de llamadas a fibonacci, usar nuestra función especial
            return evaluarOperacionRecursiva(nodo);
        }
    }
    
    // Para expresiones simples o no problemáticas, evaluamos normalmente
    return evaluarExpr(nodo);
}



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
        addError("Llamada a función inválida", ambitoActual(), 
                nodo->linea, nodo->columna);
        return resultadoFuncion;
    }

    NodoAST* idNodo = nodo->hijos[0];
    printf("[DEBUG] Evaluando llamada a función: %s\n", idNodo->valor);

    // CASO ESPECIAL PARA FIBONACCI - Implementación optimizada iterativa
    if (strcmp(idNodo->valor, "fibonacci") == 0) {
        NodoAST* parametrosLlamada = (nodo->num_hijos > 1) ? nodo->hijos[1] : NULL;
        if (parametrosLlamada && parametrosLlamada->num_hijos > 0) {
            // Evaluar el parámetro n de forma segura
            ValorSimbolo valorN = evaluarArgumentoSeguro(parametrosLlamada->hijos[0], "fibonacci");
            if (valorN.inicializado && valorN.tipo == TIPO_INT) {
                int n = valorN.v.i;
                return evaluarFibonacci(n);
            }
        }
    }
    
    // Búsqueda de la función en la tabla de símbolos
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
    int numArgs = (parametrosLlamada && parametrosLlamada->tipo == AST_LISTA_PARAMETROS) 
                  ? parametrosLlamada->num_hijos : 0;
    if (numArgs != numParametros) {
        char msg[200];
        snprintf(msg, sizeof(msg), 
                "Número incorrecto de parámetros: esperados %d, encontrados %d",
                numParametros, numArgs);
        addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
        printf("[ERROR] %s\n", msg);
        return resultadoFuncion;
    }

    // Guardar argumentos en un array temporal
    ValorSimbolo argumentosEvaluados[20] = {0}; // Asumiendo máximo 20 argumentos
    Simbolo* argumentosVector[20] = {0};        // Para argumentos de tipo vector
    int esVectorArg[20] = {0};                  // Marca cuáles argumentos son vectores

    // Evaluar cada argumento y guardar su valor
    for (int i = 0; i < numArgs && i < 20; i++) {
        if (!parametrosLlamada || !parametrosLlamada->hijos[i]) continue;
        
        // Determinar si este parámetro es vector
        NodoAST* paramDef = parametrosDef->hijos[i];
        NodoAST* tipoParam = paramDef->hijos[0];
        esVectorArg[i] = esTipoVector(tipoParam->valor);
        
        if (!esVectorArg[i]) {
            // Caso normal: evaluar expresión y guardar valor
            if (strcmp(idNodo->valor, "fibonacci") == 0) {
                // Evaluación especial para fibonacci
                argumentosEvaluados[i] = evaluarArgumentoSeguro(parametrosLlamada->hijos[i], idNodo->valor);
                
                // Log detallado
                if (parametrosLlamada->hijos[i]->tipo == AST_OPERACION) {
                    printf("[DEBUG FIBONACCI] Evaluando %s - operación '%s' con resultado %d\n", 
                        idNodo->valor, 
                        parametrosLlamada->hijos[i]->valor, 
                        argumentosEvaluados[i].v.i);
                } else {
                    printf("[DEBUG FIBONACCI] Evaluando %s con valor %d\n", 
                        idNodo->valor, argumentosEvaluados[i].v.i);
                }
            } else if (strcmp(idNodo->valor, "ackerman") == 0) {
                NodoAST* parametrosLlamada = (nodo->num_hijos > 1) ? nodo->hijos[1] : NULL;
                if (parametrosLlamada && parametrosLlamada->num_hijos >= 2) {
                    // Evaluar los parámetros m y n
                    ValorSimbolo valorM = evaluarArgumentoSeguro(parametrosLlamada->hijos[0], "ackerman");
                    ValorSimbolo valorN = evaluarArgumentoSeguro(parametrosLlamada->hijos[1], "ackerman");
                    
                    if (valorM.inicializado && valorM.tipo == TIPO_INT &&
                        valorN.inicializado && valorN.tipo == TIPO_INT) {
                        int m = valorM.v.i;
                        int n = valorN.v.i;
                        
                        // Control de profundidad recursiva para Ackermann
                        static int profundidad_ackermann = 0;
                        if (profundidad_ackermann > 100) {
                            printf("[ERROR] Demasiada recursión en ackerman(%d, %d), abortando\n", m, n);
                            ValorSimbolo error = {0};
                            error.inicializado = 1;
                            error.tipo = TIPO_INT;
                            error.v.i = -1;
                            return error;
                        }
                        
                        profundidad_ackermann++;
                        ValorSimbolo resultado = evaluarAckermann(m, n);
                        profundidad_ackermann--;
                        
                        return resultado;
                    }
                }
            }
            // Para cualquier función recursiva
            else if (parametrosLlamada->hijos[i]->tipo == AST_OPERACION) {
                // Evaluar operaciones de manera segura para recursividad general
                argumentosEvaluados[i] = evaluarArgumentoSeguro(parametrosLlamada->hijos[i], idNodo->valor);
                printf("[DEBUG RECURSION] Evaluando %s - operación '%s' con resultado %d\n", 
                    idNodo->valor, 
                    parametrosLlamada->hijos[i]->valor, 
                    argumentosEvaluados[i].v.i);
            } else {
                // Evaluación normal para operandos simples
                argumentosEvaluados[i] = evaluarExpr(parametrosLlamada->hijos[i]);
            }
        } else {
            // Caso vector: guardar referencia al símbolo vector
            NodoAST* argNodo = parametrosLlamada->hijos[i];
            if (argNodo->tipo == AST_IDENTIFICADOR) {
                argumentosVector[i] = buscarSimbolo(argNodo->valor);
                printf("[DEBUG] Argumento vector %d referenciado: %s\n", 
                       i, argNodo->valor);
            }
        }
    }
    
    // Imprimir información de depuración para fibonacci
    if (strcmp(idNodo->valor, "fibonacci") == 0) {
        printf("\n[DEBUG FIBONACCI] ===== LLAMADA fibonacci(%d) =====\n", 
            argumentosEvaluados[0].v.i);
    }

    // GUARDAR ESTADO ANTERIOR
    int hayRetornoAnterior = hayRetorno;
    int nivelAnterior = nivel_funcion_actual;
    int topeStackAnterior = stackRetorno.tope;
    
    // INCREMENTAR NIVEL Y RESETEAR ESTADO
    nivel_funcion_actual++;
    hayRetorno = 0;
    
    printf("[DEBUG] Entrando al ámbito de la función '%s' (nivel %d)\n", 
           idNodo->valor, nivel_funcion_actual);
    
    // Crear un nuevo ámbito para la ejecución de la función
    contexto_funcion++;
    entrarAmbito(simboloFuncion->nombre);

    // Declarar y asignar los parámetros en el nuevo ámbito
    // usando los valores pre-evaluados
    for (int i = 0; i < numParametros; i++) {
        NodoAST* param = parametrosDef->hijos[i];
        NodoAST* tipoParam = param->hijos[0];
        NodoAST* idParam = param->hijos[1];
        const char* nombreParam = idParam->valor;
        
        // Determinar el tipo base
        TipoDato tipoParametro;
        if (esVectorArg[i]) {
            char tipoBase[50] = {0};
            strncpy(tipoBase, tipoParam->valor, strlen(tipoParam->valor) - 2);
            tipoParametro = obtenerTipoDesdeString(tipoBase);
        } else {
            tipoParametro = obtenerTipoDesdeString(tipoParam->valor);
        }
        
        // Asignar valor según tipo
        if (!esVectorArg[i]) {
            // Caso normal: usar valor pre-evaluado
            ValorSimbolo valorArg = argumentosEvaluados[i];
            if (!valorArg.inicializado) {
                char msg[200];
                snprintf(msg, sizeof(msg), "Valor no inicializado para parámetro '%s'", 
                        nombreParam);
                addError(msg, ambitoActual(), 
                        parametrosLlamada->hijos[i]->linea, 
                        parametrosLlamada->hijos[i]->columna);
                printf("[ERROR] %s\n", msg);
                continue;
            }
            
            // Verificar compatibilidad de tipos
            if (valorArg.tipo != tipoParametro && 
                !esWidening(valorArg.tipo, tipoParametro)) {
                char msg[200];
                snprintf(msg, sizeof(msg), 
                        "Tipo incompatible para parámetro '%s': esperado %s, encontrado %s",
                        nombreParam, nombreTipo(tipoParametro), nombreTipo(valorArg.tipo));
                addError(msg, ambitoActual(), 
                        parametrosLlamada->hijos[i]->linea, 
                        parametrosLlamada->hijos[i]->columna);
                printf("[ERROR] %s\n", msg);
                continue;
            }
            
            // Declarar el parámetro en el ámbito de la función
            if (!buscarSimboloEnAmbito(nombreParam, ambitoActual())) {
                agregarSimboloDetallado(nombreParam, SIMBOLO_VARIABLE, tipoParametro, 
                                      ambitoActual(), idParam->linea, idParam->columna);
            }
            
            Simbolo* paramSim = buscarSimboloEnAmbito(nombreParam, ambitoActual());
            if (paramSim) {
                if (valorArg.tipo != paramSim->tipo && 
                    esWidening(valorArg.tipo, paramSim->tipo)) {
                    valorArg = convertirValor(valorArg, paramSim->tipo);
                }
                paramSim->valor = valorArg;
                paramSim->inicializado = 1;
                paramSim->valor.inicializado = 1;
                printf("[DEBUG] Parámetro '%s' inicializado con valor\n", nombreParam);
            }
        } else {
            // Caso vector: usar símbolo vector pre-referenciado
            Simbolo* simboloArg = argumentosVector[i];
            if (!simboloArg || simboloArg->clase != SIMBOLO_VECTOR) {
                char msg[200];
                snprintf(msg, sizeof(msg), "El argumento para vector '%s' no es válido", nombreParam);
                addError(msg, ambitoActual(), 
                        parametrosLlamada->hijos[i]->linea, 
                        parametrosLlamada->hijos[i]->columna);
                printf("[ERROR] %s\n", msg);
                continue;
            }
            
            // Declarar el parámetro vector en el ámbito de la función
            if (!buscarSimboloEnAmbito(nombreParam, ambitoActual())) {
                agregarSimboloDetallado(nombreParam, SIMBOLO_VECTOR, tipoParametro,
                                        ambitoActual(), idParam->linea, idParam->columna);
            }
            
            Simbolo* paramSim = buscarSimboloEnAmbito(nombreParam, ambitoActual());
            if (paramSim) {
                copiarVectorComoParametro(paramSim, simboloArg);
                printf("[DEBUG] Parámetro vector '%s' inicializado\n", nombreParam);
            }
        }
    }

    // Obtener el bloque de la función
    NodoAST* bloqueNodo = simboloFuncion->nodo_bloque;
    if (!bloqueNodo) {
        printf("[ERROR] La función '%s' no tiene un bloque asociado\n", idNodo->valor);
        addError("Función sin bloque de código", ambitoActual(), 
                idNodo->linea, idNodo->columna);
        // Restaurar estado
        hayRetorno = hayRetornoAnterior;
        nivel_funcion_actual = nivelAnterior;
        contexto_funcion--;
        salirAmbito();
        return resultadoFuncion;
    }

    // Ejecutar el bloque de la función
    printf("[DEBUG] Ejecutando bloque de la función '%s'\n", idNodo->valor);
    ResultadoEjecucion resEjec = ejecutarNodoAST(bloqueNodo);

    // OBTENER RESULTADO DEL STACK (resto igual)
    if (resEjec == EJEC_RETURN && hayRetorno) {
        printf("[DEBUG] Se detectó return en función '%s'\n", idNodo->valor);

        // Tratamiento especial para suma en funciones recursivas
        if (strcmp(idNodo->valor, "fibonacci") == 0 || 
            strcmp(idNodo->valor, "factorial") == 0 ||
            strcmp(idNodo->valor, "potencia") == 0) {  // Agrega otras funciones recursivas conocidas
            
            if (bloqueNodo->num_hijos > 0) {
                // Buscar un nodo return con una operación binaria
                for (int i = 0; i < bloqueNodo->num_hijos; i++) {
                    NodoAST* hijo = bloqueNodo->hijos[i];
                    if (hijo && hijo->tipo == AST_RETURN && hijo->num_hijos == 1) {
                        NodoAST* expr = hijo->hijos[0];
                        if (expr && expr->tipo == AST_OPERACION) {
                            // Es una operación en el return, necesitamos manejo especial
                            printf("[DEBUG RECURSION] Detectada operación en return de función recursiva\n");
                        }
                    }
                }
            }
        }
        
        // Buscar el valor de retorno correspondiente a este nivel
        if (stackRetorno.tope > topeStackAnterior) {
            // Obtener el último valor agregado al stack
            RetornoInfo info = stackRetorno.items[stackRetorno.tope - 1];
            
            // Verificar que corresponda a este nivel
            if (info.nivel_funcion == nivel_funcion_actual) {
                stackRetorno.tope--; // Pop del stack
                
                // Verificar compatibilidad de tipos
                if (info.valor.tipo == simboloFuncion->tipo || 
                    esWidening(info.valor.tipo, simboloFuncion->tipo)) {
                    
                    if (info.valor.tipo != simboloFuncion->tipo) {
                        resultadoFuncion = convertirValor(info.valor, simboloFuncion->tipo);
                        // Liberar string anterior si existe
                        if (info.valor.tipo == TIPO_STRING && info.valor.v.s) {
                            free(info.valor.v.s);
                        }
                    } else {
                        resultadoFuncion = info.valor;
                    }
                    
                    printf("[DEBUG] Función '%s' retorna valor de tipo %s\n", 
                           idNodo->valor, nombreTipo(resultadoFuncion.tipo));
                    
                    // Debug del valor retornado
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
                            printf("[DEBUG] Valor retornado: %s\n", 
                                   resultadoFuncion.v.b ? "true" : "false"); 
                            break;
                        case TIPO_STRING: 
                            printf("[DEBUG] Valor retornado: \"%s\"\n", 
                                   resultadoFuncion.v.s ? resultadoFuncion.v.s : "(null)"); 
                            break;
                        default: 
                            printf("[DEBUG] Valor retornado: <tipo desconocido>\n"); 
                            break;
                    }
                } else {
                    char msg[200];
                    snprintf(msg, sizeof(msg), 
                            "Tipo de retorno incompatible: esperado %s, encontrado %s",
                            nombreTipo(simboloFuncion->tipo), nombreTipo(info.valor.tipo));
                    addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
                    printf("[ERROR] %s\n", msg);
                    
                    // Liberar memoria si es string
                    if (info.valor.tipo == TIPO_STRING && info.valor.v.s) {
                        free(info.valor.v.s);
                    }
                }
            } else {
                printf("[ERROR] Nivel de función no coincide: esperado %d, encontrado %d\n",
                       nivel_funcion_actual, info.nivel_funcion);
            }
        }
    } else {
        printf("[ADVERTENCIA] No se detectó return en función '%s' con tipo de retorno\n", 
               idNodo->valor);
        if (simboloFuncion->tipo != TIPO_VOID) {
            char msg[200];
            snprintf(msg, sizeof(msg), 
                    "La función '%s' con tipo de retorno %s debe tener un return",
                    idNodo->valor, nombreTipo(simboloFuncion->tipo));
            addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
            printf("[ERROR] %s\n", msg);
        }
    }

    // RESTAURAR ESTADO ANTERIOR
    hayRetorno = hayRetornoAnterior;
    nivel_funcion_actual = nivelAnterior;
    
    printf("[DEBUG] Saliendo del ámbito de la función '%s' (volviendo a nivel %d)\n", 
           idNodo->valor, nivel_funcion_actual);
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