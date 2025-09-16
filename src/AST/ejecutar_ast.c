#include "ast.h"
#include "../semantico/tabla_simbolo.h"
#include "../semantico/semantico.h"
#include "../semantico/Instrucciones/asignacion.h"
#include "../semantico/Instrucciones/declaracion.h"
#include "../semantico/Instrucciones/Print.h"
#include "../semantico/Instrucciones/SentIF.h"
#include "../semantico/Instrucciones/Switch.h"
#include "../semantico/Instrucciones/While.h"
#include "../semantico/Instrucciones/break.h"
#include "../semantico/Instrucciones/continue.h"
#include "../semantico/Instrucciones/for.h"
#include "../semantico/Instrucciones/for_vector.h"
#include "../semantico/Vectores/declaracion_vector.h"
#include "../semantico/Vectores/declaracion_matriz.h"
#include "../semantico/Vectores/declaracion_array.h"
#include "../semantico/Vectores/acceso_vector.h"
#include "../semantico/Vectores/acceso_matriz.h"
#include "../semantico/Vectores/acceso_arrays.h"
#include "../simbolos/Evaluador.h"
#include "../simbolos/salida.h"
#include "../semantico/Funciones/FuncionVoid.h"
#include "../semantico/Funciones/LlamadasVoid.h"
#include "../semantico/Funciones/Llamadas.h"
#include "../semantico/Funciones/Funcion.h"
#include "../semantico/Instrucciones/return.h"
#include "ejecutar_ast.h"
#include "err.h"
#include <stdio.h>
#include "stdbool.h"
#include <stdlib.h>

int contexto_break = 0;
int contexto_continue = 0;
int contexto_funcion = 0;
ValorSimbolo valorRetorno;
int hayRetorno = 0;
int contadorBloques = 0;
int bloquePrincipalMain = 0;
int dentroDelMain = 0; // Para trackear si estamos dentro del main

ResultadoEjecucion ejecutarNodoAST(NodoAST* nodo) {
    // Verificación más robusta de nodos
    if (!nodo) {
        printf("[DEBUG] Nodo es NULL, saltando\n");
        return EJEC_OK;
    }
    
    if (!nodo->valido || nodo->tipo == AST_ERROR) {
        printf("[DEBUG] Nodo inválido o de error (tipo: %d, válido: %d), saltando\n", 
               nodo->tipo, nodo->valido);
        return EJEC_OK;
    }

    printf("[DEBUG] Ejecutando nodo tipo: %d, valor: %s\n", 
           nodo->tipo, nodo->valor ? nodo->valor : "NULL");
    
    switch (nodo->tipo) {
        case AST_METODO_MAIN:
            entrarAmbito("main");
            dentroDelMain = 1; // Marcamos que estamos dentro del main
            bloquePrincipalMain = 0; // Resetear contador para el bloque principal
            ejecutarNodoAST(nodo->hijos[0]);
            dentroDelMain = 0; // Salimos del main
            salirAmbito();
            return EJEC_OK;
            
        case AST_LISTA:
        case AST_BLOQUE: {
            bool crearAmbito = true;
            const char* ambitoActualNombre = ambitoActual();

            // Lógica corregida para ámbitos:
            
            // 1. Si estamos en el ámbito "global" y es un bloque de funciones, NO crear ámbito
            if (strcmp(ambitoActualNombre, "global") == 0 && 
                nodo->valor && (strcmp(nodo->valor, "Funciones") == 0 || strcmp(nodo->valor, "Programa") == 0)) {
                crearAmbito = false;
                printf("[DEBUG BLOQUE] Bloque '%s' en ámbito global, no creando nuevo ámbito\n", nodo->valor);
            }
            // 1.5 Si estamos en el ámbito "main" y es un bloque "Programa", NO crear ámbito
            else if (strcmp(ambitoActualNombre, "main") == 0 && 
                     nodo->valor && strcmp(nodo->valor, "Programa") == 0) {
                crearAmbito = false;
                printf("[DEBUG BLOQUE] Bloque 'Programa' en ámbito main, no creando nuevo ámbito\n");
            }
            // 2. Si estamos en el ámbito "main" y es el primer bloque, NO crear ámbito
            else if (strcmp(ambitoActualNombre, "main") == 0 && bloquePrincipalMain == 0) {
                crearAmbito = false;
                bloquePrincipalMain = 1; // Marcar que ya procesamos el bloque principal
                printf("[DEBUG BLOQUE] Usando ámbito 'main' para bloque principal\n");
            }
            // 3. Si estamos en contextos especiales, NO crear ámbito
            else if (strcmp(ambitoActualNombre, "funcion") == 0 ||
                     strcmp(ambitoActualNombre, "funcion_void") == 0 ||
                     strcmp(ambitoActualNombre, "for") == 0 ||
                     strcmp(ambitoActualNombre, "while") == 0 ||
                     strcmp(ambitoActualNombre, "switch") == 0 ||
                     strcmp(ambitoActualNombre, "if") == 0 ||
                     strcmp(ambitoActualNombre, "else") == 0) {
                crearAmbito = false;
                printf("[DEBUG BLOQUE] No creando ámbito, usando contexto actual: %s\n", ambitoActualNombre);
            }
            else {
                crearAmbito = true;
            }

            char nombreAmbito[32];
            if (crearAmbito) {
                snprintf(nombreAmbito, sizeof(nombreAmbito), "bloque_%d", ++contadorBloques);
                printf("[DEBUG BLOQUE] Entrando al ámbito: %s\n", nombreAmbito);
                entrarAmbito(nombreAmbito);
            }

            // Ejecutar hijos
            for (int i = 0; i < nodo->num_hijos; i++) {
                if (nodo->hijos[i] == NULL) continue;
                ResultadoEjecucion res = ejecutarNodoAST(nodo->hijos[i]);
                if (res != EJEC_OK) {
                    if (crearAmbito) salirAmbito();
                    return res;
                }
            }

            if (crearAmbito) {
                salirAmbito();
                printf("[DEBUG BLOQUE] Saliendo del ámbito: %s\n", nombreAmbito);
            }
            return EJEC_OK;
        }
            
        case AST_DECLARACION:
            printf("[DEBUG] Procesando declaración\n");
            verificarDeclaracion(nodo);
            return EJEC_OK;
            
        case AST_ASIGNACION: {
            if (nodo->num_hijos < 2) {
                printf("[ERROR] Asignación sin destino o valor\n");
                return EJEC_OK;
            }
            
            NodoAST* destino = nodo->hijos[0];
            NodoAST* valorNodo = nodo->hijos[1];
            
            // Caso 1: Asignación a variable simple
            if (destino->tipo == AST_IDENTIFICADOR) {
                printf("[DEBUG] Asignación a variable '%s'\n", destino->valor);
                verificarAsignacion(nodo);
            }
            // Caso 2: Asignación a elemento de array
            else if (destino->tipo == AST_ACCESO) {
                printf("[DEBUG] Asignación a elemento de array\n");
                
                // Verificar que el acceso sea válido
                if (!verificarAccesoVector(destino)) {
                    printf("[ERROR] Acceso inválido en asignación\n");
                    return EJEC_OK;
                }
                
                // Obtener el identificador y los índices del acceso
                NodoAST* idNodo = destino->hijos[0];
                NodoAST* dimensionesNodo = destino->hijos[1];
                
                // Obtener el símbolo del array
                Simbolo* simbolo = buscarSimbolo(idNodo->valor);
                if (!simbolo) {
                    printf("[ERROR] Variable '%s' no encontrada\n", idNodo->valor);
                    return EJEC_OK;
                }
                
                // Evaluar el valor a asignar
                ValorSimbolo valor = evaluarExpr(valorNodo);
                if (!valor.inicializado) {
                    printf("[ERROR] Valor no inicializado en asignación\n");
                    return EJEC_OK;
                }
                
                // Verificar compatibilidad de tipos
                if (valor.tipo != simbolo->tipo && !esWidening(valor.tipo, simbolo->tipo)) {
                    printf("[ERROR] Tipo incompatible en asignación a array\n");
                    return EJEC_OK;
                }
                
                // Obtener los índices evaluados
                int indices[10] = {0};
                int numIndices = 0;
                
                for (int i = 0; i < dimensionesNodo->num_hijos && numIndices < 10; i++) {
                    NodoAST* dimNodo = dimensionesNodo->hijos[i];
                    if (dimNodo->tipo == AST_1DIMENSION && dimNodo->num_hijos > 0) {
                        ValorSimbolo idxVal = evaluarExpr(dimNodo->hijos[0]);
                        if (idxVal.inicializado && idxVal.tipo == TIPO_INT) {
                            indices[numIndices++] = idxVal.v.i;
                        }
                    }
                }
                
                // Realizar la asignación según el tipo de array
                if (simbolo->clase == SIMBOLO_VECTOR && numIndices == 1) {
                    asignarValorVector(simbolo, indices[0], valor);
                    printf("[DEBUG] Asignado valor a %s[%d]\n", idNodo->valor, indices[0]);
                }
                else if (simbolo->clase == SIMBOLO_MATRIZ && numIndices == 2) {
                    asignarValorMatriz(simbolo, indices[0], indices[1], valor);
                    printf("[DEBUG] Asignado valor a %s[%d][%d]\n", idNodo->valor, indices[0], indices[1]);
                }
                else if (simbolo->clase == SIMBOLO_ARRAY_MULTIDIMENSIONAL) {
                    asignarElementoArrayMultidimensional(simbolo, indices, numIndices, valor);
                    printf("[DEBUG] Asignado valor a elemento de array multidimensional\n");
                }
            }
            else {
                printf("[ERROR] Destino de asignación inválido\n");
            }
            
            return EJEC_OK;
        }

        case AST_PRINT:
            printf("[DEBUG] Procesando print\n");
            if (nodo->num_hijos > 0 && nodo->hijos[0]) {
                imprimirEvaluado(nodo->hijos[0]);
            } else {
                printf("\n");  // Print empty line if no expression
                capture_print_output("\n");
            }
            return EJEC_OK;

        case AST_INCREMENTO: // Tipo 25
        case AST_DECREMENTO: // Si tienes decrementos
            printf("[DEBUG] Procesando incremento/decremento\n");
            if (nodo->num_hijos > 0 && nodo->hijos[0] && nodo->hijos[0]->valor) {
                // Obtener la variable a incrementar
                const char* nombreVar = nodo->hijos[0]->valor;
                Simbolo* simbolo = buscarSimbolo(nombreVar);
                
                if (!simbolo) {
                    printf("[ERROR] Variable '%s' no encontrada para incremento\n", nombreVar);
                    return EJEC_OK;
                }
                
                if (simbolo->tipo != TIPO_INT) {
                    printf("[ERROR] Incremento solo soportado para variables int\n");
                    return EJEC_OK;
                }
                
                // Incrementar el valor
                if (nodo->valor && strcmp(nodo->valor, "++") == 0) {
                    simbolo->valor.v.i++;
                    printf("[DEBUG] Variable '%s' incrementada a: %d\n", nombreVar, simbolo->valor.v.i);
                } else if (nodo->valor && strcmp(nodo->valor, "--") == 0) {
                    simbolo->valor.v.i--;
                    printf("[DEBUG] Variable '%s' decrementada a: %d\n", nombreVar, simbolo->valor.v.i);
                }
                
                simbolo->valor.inicializado = 1;
            } else {
                printf("[ERROR] Nodo incremento sin variable válida\n");
            }
            return EJEC_OK;

        case AST_IF:
            return ejecutarNodoIf(nodo);
            
        case AST_SWITCH:
            contexto_break++;
            contexto_continue++;
            ResultadoEjecucion res_switch = EjecturarNodoSwitch(nodo);
            contexto_break--;
            contexto_continue--;
            return res_switch;
            
        case AST_WHILE:
            contexto_break++;
            contexto_continue++;
            ResultadoEjecucion resWHILE = ejecutarSetenciaWhile(nodo);
            contexto_break--;
            contexto_continue--;
            return resWHILE;
            
        case AST_FOR:
            contexto_break++;
            contexto_continue++;
            ResultadoEjecucion resFOR = ejecutarSentenciaFor(nodo);
            contexto_break--;
            contexto_continue--;
            return resFOR;

        case AST_FOR_VECTOR:
            contexto_break++;
            contexto_continue++;
            ResultadoEjecucion resFORV = ejecutarSentenciaForVector(nodo);
            contexto_break--;
            contexto_continue--;
            return resFORV;
        case AST_BREAK:
            printf("[DEBUG AST_BREAK] Ejecutando break\n");
            return ejecutarSentenciaBreak(nodo);
            
        case AST_CONTINUE:
            return ejecutarSentenciaContinue(nodo);
        case AST_DECLARACION_VECTOR:
            printf("[DEBUG] Procesando declaración de vector\n");
            verificarDeclaracionVector(nodo);
            return EJEC_OK;
            
        case AST_DECLARACION_MATRIZ:
            printf("[DEBUG] Procesando declaración de matriz\n");
            verificarDeclaracionMatriz(nodo);
            return EJEC_OK;
        case AST_DECLARACION_ARRAY_MULTIDIMENSIONAL:
            printf("[DEBUG] Procesando declaración de array multidimensional\n");
            verificarDeclaracionArray(nodo);
            return EJEC_OK;
        case AST_ACCESO: {
            printf("[DEBUG] Procesando acceso a array/vector/matriz\n");
            
            // Obtener el identificador para determinar si es vector o matriz
            if (nodo->num_hijos < 1 || nodo->hijos[0]->tipo != AST_IDENTIFICADOR) {
                printf("[ERROR] Estructura de acceso inválida\n");
                return EJEC_OK;
            }
            
            NodoAST* idNodo = nodo->hijos[0];
            Simbolo* simbolo = buscarSimbolo(idNodo->valor);
            
            if (!simbolo) {
                printf("[ERROR] Variable '%s' no declarada\n", idNodo->valor);
                return EJEC_OK;
            }
            
            // Dirigir a la función específica según el tipo de estructura
            if (simbolo->clase == SIMBOLO_MATRIZ) {
                printf("[DEBUG] Detectada MATRIZ '%s', verificando acceso...\n", idNodo->valor);
                // Verificar que el acceso a matriz sea válido
                if (!verificarAccesoMatriz(nodo)) {
                    printf("[ERROR] Acceso inválido a matriz '%s'\n", idNodo->valor);
                    return EJEC_OK;
                }
                
                // Evaluar acceso a matriz (solo para depuración)
                ValorSimbolo valorMatriz = evaluarAccesoMatriz(nodo);
                if (valorMatriz.inicializado) {
                    printf("[DEBUG] Acceso a matriz evaluado exitosamente, valor = ");
                    // Imprimir el valor según su tipo
                    switch (valorMatriz.tipo) {
                        case TIPO_INT: printf("%d\n", valorMatriz.v.i); break;
                        case TIPO_FLOAT: printf("%f\n", valorMatriz.v.f); break;
                        case TIPO_DOUBLE: printf("%lf\n", valorMatriz.v.d); break;
                        case TIPO_CHAR: printf("'%c'\n", valorMatriz.v.c); break;
                        case TIPO_BOOLEAN: printf("%s\n", valorMatriz.v.b ? "true" : "false"); break;
                        case TIPO_STRING: printf("\"%s\"\n", valorMatriz.v.s ? valorMatriz.v.s : "null"); break;
                        default: printf("tipo desconocido\n"); break;
                    }
                } else {
                    printf("[ERROR] No se pudo obtener valor del acceso a matriz\n");
                }
            } 
            else if (simbolo->clase == SIMBOLO_VECTOR) {
                printf("[DEBUG] Detectado VECTOR '%s', verificando acceso...\n", idNodo->valor);
                // Verificar que el acceso a vector sea válido
                if (!verificarAccesoVector(nodo)) {
                    printf("[ERROR] Acceso inválido a vector '%s'\n", idNodo->valor);
                    return EJEC_OK;
                }
                
                // Evaluar acceso a vector (solo para depuración)
                ValorSimbolo valorVector = evaluarAccesoVector(nodo);
                if (valorVector.inicializado) {
                    printf("[DEBUG] Acceso a vector evaluado exitosamente, valor = ");
                    // Imprimir valor según su tipo
                    switch (valorVector.tipo) {
                        case TIPO_INT: printf("%d\n", valorVector.v.i); break;
                        case TIPO_FLOAT: printf("%f\n", valorVector.v.f); break;
                        case TIPO_DOUBLE: printf("%lf\n", valorVector.v.d); break;
                        case TIPO_CHAR: printf("'%c'\n", valorVector.v.c); break;
                        case TIPO_BOOLEAN: printf("%s\n", valorVector.v.b ? "true" : "false"); break;
                        case TIPO_STRING: printf("\"%s\"\n", valorVector.v.s ? valorVector.v.s : "null"); break;
                        default: printf("tipo desconocido\n"); break;
                    }
                } else {
                    printf("[ERROR] No se pudo obtener valor del acceso a vector\n");
                }
            }else if (simbolo->clase == SIMBOLO_ARRAY_MULTIDIMENSIONAL) {
                printf("[DEBUG] Detectado ARRAY '%s', verificando acceso...\n", idNodo->valor);
                // Verificar que el acceso a array sea válido
                if (!verificarAccesoArray(nodo)) {
                    printf("[ERROR] Acceso inválido a array '%s'\n", idNodo->valor);
                    return EJEC_OK;
                }
                
                // Evaluar acceso a array (solo para depuración)
                ValorSimbolo valorArray = evaluarAccesoArray(nodo);
                if (valorArray.inicializado) {
                    printf("[DEBUG] Acceso a array evaluado exitosamente\n");
                } else {
                    printf("[ERROR] No se pudo obtener valor del acceso a array\n");
                }
            }
            else {
                printf("[ERROR] Variable '%s' no es un vector ni matriz ni array (clase: %d)\n", 
                    idNodo->valor, simbolo->clase);
            }
            
            return EJEC_OK;
        }
        case AST_ACCESO_ESCRITURA: {
            printf("[DEBUG] Procesando acceso de escritura\n");
            
            interpretarAccesoEscritura(nodo);
            
            return EJEC_OK;
        }

        case AST_FUNCION_VOID:{
            printf("[DEBUG] Procesando función void\n");
            return DeclararFuncionVoid(nodo);
        }

        case AST_LLAMADA_VOID:{
            printf("[DEBUG] Procesando llamada a función void\n");
            return EjecutarLlamadaVoid(nodo);
        }
        case AST_FUNCION:{
            printf("[DEBUG] Procesando función\n");
            contexto_funcion++;
            ResultadoEjecucion res = DeclararFuncion(nodo);
            contexto_funcion--;
            return res;
        }
        case AST_LLAMADA:{
            printf("[DEBUG] Procesando llamada a función\n");
            contexto_funcion++;
            ResultadoEjecucion res = EjecutarLlamadas(nodo);
            contexto_funcion--;
            return res;
        }
        case AST_RETURN:
            printf("[DEBUG] Procesando return\n");
            return ejecutarSentenciaReturn(nodo);

        case AST_PROGRAMA: // Agregar caso específico para nodo Programa
            printf("[DEBUG] Procesando nodo Programa\n");
            // No crear ámbito para el nodo Programa, solo ejecutar hijos
            for (int i = 0; i < nodo->num_hijos; i++) {
                if (nodo->hijos[i] != NULL) {
                    ejecutarNodoAST(nodo->hijos[i]);
                }
            }
            return EJEC_OK;

        default:
            printf("[DEBUG] Nodo tipo %d no manejado específicamente, procesando hijos\n", nodo->tipo);
            for (int i = 0; i < nodo->num_hijos; i++) {
                if (nodo->hijos[i] != NULL) {
                    ejecutarNodoAST(nodo->hijos[i]);
                }
            }
            break;
    }
    return EJEC_OK;
}

// Función principal para interpretar el programa completo
void interpretarPrograma(NodoAST* raiz) {
    if (!raiz) {
        printf("[ERROR] AST raíz es NULL\n");
        return;
    }
    
    // Inicializar contador de bloques
    contadorBloques = 0;
    dentroDelMain = 0;
    bloquePrincipalMain = 0;
    
    // IMPORTANTE: Inicializar con ámbito global
    // Esto asegura que las variables declaradas fuera del main tengan ámbito "global"
    entrarAmbito("global");
    
    printf("\n[DEBUG] === INICIANDO INTERPRETACIÓN SECUENCIAL ===\n");
    printf("[DEBUG] Ámbito inicial: %s\n", ambitoActual());
    mostrarTablaSimbolos();  // Mostrar estado inicial
    
    // Ejecutar el programa secuencialmente
    ejecutarNodoAST(raiz);
    
    // Salir del ámbito global al final
    salirAmbito();
    
    printf("\n[DEBUG] === INTERPRETACIÓN COMPLETADA ===\n");
    mostrarTablaSimbolos();  // Mostrar estado final
}

// Función auxiliar para verificar la estructura del AST antes de ejecutar
void verificarEstructuraAST(NodoAST* nodo, int nivel) {
    if (!nodo) return;
    
    for (int i = 0; i < nivel; i++) printf("  ");
    printf("Nivel %d: Tipo=%d, Valor=%s, Hijos=%d, Válido=%d\n", 
           nivel, nodo->tipo, nodo->valor ? nodo->valor : "NULL", 
           nodo->num_hijos, nodo->valido);
    
    for (int i = 0; i < nodo->num_hijos; i++) {
        verificarEstructuraAST(nodo->hijos[i], nivel + 1);
    }
}