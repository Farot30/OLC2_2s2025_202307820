#include <stdlib.h>
#include "for_vector.h"
#include <string.h>
#include <stdbool.h>
#include "../../AST/ejecutar_ast.h"
#include "../../AST/err.h"
#include "../tipos.h"
#include "../tabla_simbolo.h"
#include "../../simbolos/Evaluador.h"

SentenciaForVector* crearSentenciaForVector(NodoAST* variable_iteracion, NodoAST* coleccion, NodoAST* bloque) {
    SentenciaForVector* sentencia = (SentenciaForVector*)malloc(sizeof(SentenciaForVector));
    sentencia->variable_iteracion = variable_iteracion;
    sentencia->coleccion = coleccion;
    sentencia->bloque = bloque;
    return sentencia;
}

void liberarSentenciaForVector(SentenciaForVector* sentencia) {
    if (!sentencia) return;
    free(sentencia);
}

// Función auxiliar para parsear el contenido de un vector desde string
int* parsearVectorEnteros(const char* str, int* tamanio) {
    if (!str || !tamanio) return NULL;
    
    // El formato esperado es "[10,20,30]"
    if (str[0] != '[') return NULL;
    
    // Contar elementos
    *tamanio = 0;
    int len = strlen(str);
    for (int i = 1; i < len - 1; i++) {
        if (str[i] == ',') (*tamanio)++;
    }
    if (len > 2) (*tamanio)++; // El último elemento
    
    if (*tamanio == 0) return NULL;
    
    // Allocar memoria
    int* elementos = malloc(*tamanio * sizeof(int));
    if (!elementos) return NULL;
    
    // Parsear elementos
    char* copia = strdup(str);
    char* inicio = copia + 1; // Saltar '['
    char* fin = strchr(inicio, ']');
    if (fin) *fin = '\0';
    
    char* token = strtok(inicio, ",");
    int indice = 0;
    while (token && indice < *tamanio) {
        elementos[indice] = atoi(token);
        token = strtok(NULL, ",");
        indice++;
    }
    
    free(copia);
    return elementos;
}

// Función auxiliar para parsear vectores de float
float* parsearVectorFloat(const char* str, int* tamanio) {
    if (!str || !tamanio) return NULL;
    
    if (str[0] != '[') return NULL;
    
    *tamanio = 0;
    int len = strlen(str);
    for (int i = 1; i < len - 1; i++) {
        if (str[i] == ',') (*tamanio)++;
    }
    if (len > 2) (*tamanio)++;
    
    if (*tamanio == 0) return NULL;
    
    float* elementos = malloc(*tamanio * sizeof(float));
    if (!elementos) return NULL;
    
    char* copia = strdup(str);
    char* inicio = copia + 1;
    char* fin = strchr(inicio, ']');
    if (fin) *fin = '\0';
    
    char* token = strtok(inicio, ",");
    int indice = 0;
    while (token && indice < *tamanio) {
        elementos[indice] = atof(token);
        token = strtok(NULL, ",");
        indice++;
    }
    
    free(copia);
    return elementos;
}

// Función auxiliar para parsear vectores de string
char** parsearVectorString(const char* str, int* tamanio) {
    if (!str || !tamanio) return NULL;
    
    if (str[0] != '[') return NULL;
    
    *tamanio = 0;
    int len = strlen(str);
    for (int i = 1; i < len - 1; i++) {
        if (str[i] == ',') (*tamanio)++;
    }
    if (len > 2) (*tamanio)++;
    
    if (*tamanio == 0) return NULL;
    
    char** elementos = malloc(*tamanio * sizeof(char*));
    if (!elementos) return NULL;
    
    char* copia = strdup(str);
    char* inicio = copia + 1;
    char* fin = strchr(inicio, ']');
    if (fin) *fin = '\0';
    
    char* token = strtok(inicio, ",");
    int indice = 0;
    while (token && indice < *tamanio) {
        // Remover espacios en blanco
        while (*token == ' ') token++;
        char* end = token + strlen(token) - 1;
        while (end > token && *end == ' ') {
            *end = '\0';
            end--;
        }
        elementos[indice] = strdup(token);
        token = strtok(NULL, ",");
        indice++;
    }
    
    free(copia);
    return elementos;
}

ResultadoEjecucion ejecutarSentenciaForVector(NodoAST* nodo) {
    if (!nodo || nodo->tipo != AST_FOR_VECTOR) {
        printf("[ERROR FOR_VECTOR] Nodo inválido o no es tipo FOR_VECTOR\n");
        return EJEC_OK;
    }

    if (nodo->num_hijos < 3) {
        printf("[ERROR FOR_VECTOR] FOR_VECTOR incompleto - esperados al menos 3 hijos, encontrados %d\n", nodo->num_hijos);
        return EJEC_OK;
    }

    NodoAST* variable_iteracion = nodo->hijos[0];
    NodoAST* coleccion = nodo->hijos[1];
    NodoAST* bloque = nodo->hijos[2];

    printf("[DEBUG FOR_VECTOR] === INICIANDO BUCLE FOR_VECTOR ===\n");

    // Evaluar la colección
    ValorSimbolo valorColeccion = evaluarExpr(coleccion);
    if (!valorColeccion.inicializado) {
        printf("[ERROR FOR_VECTOR] Colección no inicializada o inválida\n");
        addError("Colección no inicializada en FOR_VECTOR", ambitoActual(), coleccion->linea, coleccion->columna);
        return EJEC_OK;
    }

    // Buscar el símbolo de la colección
    Simbolo* simboloColeccion = buscarSimbolo(coleccion->valor);
    if (!simboloColeccion) {
        printf("[ERROR FOR_VECTOR] Símbolo de colección no encontrado\n");
        addError("Símbolo de colección no encontrado en FOR_VECTOR", ambitoActual(), coleccion->linea, coleccion->columna);
        return EJEC_OK;
    }

    // CORRECCIÓN: Usar AND (&&) en lugar de OR (||)
    if (simboloColeccion->clase != SIMBOLO_VECTOR && simboloColeccion->clase != SIMBOLO_MATRIZ) {
        printf("[ERROR FOR_VECTOR] La colección no es un vector ni una matriz\n");
        addError("La colección no es un vector ni una matriz en FOR_VECTOR", ambitoActual(), coleccion->linea, coleccion->columna);
        return EJEC_OK;
    }

    printf("[DEBUG FOR_VECTOR] Colección encontrada: %s, tipo: %d, clase: %d\n", 
           simboloColeccion->nombre, simboloColeccion->tipo, simboloColeccion->clase);
    printf("[DEBUG FOR_VECTOR] Valor de colección: %s\n", valorColeccion.v.s ? valorColeccion.v.s : "NULL");

    // Parsear los elementos según el tipo
    int tamanio = 0;
    void* elementos = NULL;
    
    switch (simboloColeccion->tipo) {
        case TIPO_INT: {
            int* enteros = parsearVectorEnteros(valorColeccion.v.s, &tamanio);
            elementos = enteros;
            printf("[DEBUG FOR_VECTOR] Vector de enteros parseado: %d elementos\n", tamanio);
            break;
        }
        case TIPO_FLOAT: {
            float* flotantes = parsearVectorFloat(valorColeccion.v.s, &tamanio);
            elementos = flotantes;
            printf("[DEBUG FOR_VECTOR] Vector de float parseado: %d elementos\n", tamanio);
            break;
        }
        case TIPO_STRING: {
            char** strings = parsearVectorString(valorColeccion.v.s, &tamanio);
            elementos = strings;
            printf("[DEBUG FOR_VECTOR] Vector de strings parseado: %d elementos\n", tamanio);
            break;
        }
        default:
            printf("[ERROR FOR_VECTOR] Tipo de vector no soportado: %d\n", simboloColeccion->tipo);
            return EJEC_OK;
    }

    if (!elementos || tamanio == 0) {
        printf("[ERROR FOR_VECTOR] No se pudieron parsear los elementos del vector\n");
        return EJEC_OK;
    }

    printf("[DEBUG FOR_VECTOR] Iniciando iteraciones sobre %d elementos\n", tamanio);

    // CORRECCIÓN: Usar un límite fijo y local, no una variable global incremental
    //const int LIMITE_ITERACIONES = 1000; // Límite de seguridad

    // IMPORTANTE: Crear el ámbito UNA SOLA VEZ antes del bucle
    entrarAmbito("for_vector");
    
    // Obtener el nombre de la variable de iteración UNA SOLA VEZ
    const char* nombre_var_iter = variable_iteracion->hijos[1]->valor;
    printf("[DEBUG FOR_VECTOR] Nombre de variable de iteración: %s\n", nombre_var_iter);
    
    // DECLARAR LA VARIABLE UNA SOLA VEZ al principio
    agregarSimboloSiNoExiste(nombre_var_iter, SIMBOLO_VARIABLE, simboloColeccion->tipo, 
                            ambitoActual(), variable_iteracion->linea, variable_iteracion->columna);
    
    Simbolo* var_iter = buscarSimboloEnAmbito(nombre_var_iter, ambitoActual());
    if (!var_iter) {
        printf("[ERROR FOR_VECTOR] No se pudo declarar la variable de iteración\n");
        salirAmbitoForLoop(nombre_var_iter);
        goto cleanup;
    }
    
    printf("[DEBUG FOR_VECTOR] Variable de iteración '%s' declarada una sola vez\n", nombre_var_iter);

    for (int i = 0; i < tamanio; i++) {
        // Verificación de seguridad
        /*if (i >= LIMITE_ITERACIONES) {
            printf("[ERROR FOR_VECTOR] Límite máximo de iteraciones alcanzado (%d)\n", LIMITE_ITERACIONES);
            addError("Límite máximo de iteraciones alcanzado en FOR_VECTOR", ambitoActual(), nodo->linea, nodo->columna);
            break;
        }*/

        printf("[DEBUG FOR_VECTOR] === ITERACIÓN %d de %d ===\n", i + 1, tamanio);

        // SOLO ASIGNAR EL NUEVO VALOR, NO RECREAR LA VARIABLE
        switch (simboloColeccion->tipo) {
            case TIPO_INT:
                var_iter->valor.v.i = ((int*)elementos)[i];
                printf("[DEBUG FOR_VECTOR] Asignado int: %d\n", var_iter->valor.v.i);
                break;
            case TIPO_FLOAT:
                var_iter->valor.v.f = ((float*)elementos)[i];
                printf("[DEBUG FOR_VECTOR] Asignado float: %f\n", var_iter->valor.v.f);
                break;
            case TIPO_STRING:
                if (var_iter->valor.v.s) free(var_iter->valor.v.s);
                var_iter->valor.v.s = strdup(((char**)elementos)[i]);
                printf("[DEBUG FOR_VECTOR] Asignado string: %s\n", var_iter->valor.v.s);
                break;
            default:
                printf("[ERROR FOR_VECTOR] Tipo de vector no soportado en asignación\n");
                salirAmbitoForLoop(nombre_var_iter);
                goto cleanup;
        }
        
        // Marcar como inicializado (solo la primera vez es necesario, pero no hace daño)
        var_iter->valor.inicializado = 1;
        var_iter->valor.tipo = simboloColeccion->tipo;

        printf("[DEBUG FOR_VECTOR] Variable '%s' actualizada con nuevo valor\n", nombre_var_iter);

        // Ejecutar el bloque de instrucciones
        if (bloque) {
            printf("[DEBUG FOR_VECTOR] Ejecutando bloque de instrucciones\n");
            ResultadoEjecucion resBloque = ejecutarNodoAST(bloque);
            if (resBloque == EJEC_BREAK) {
                printf("[DEBUG FOR_VECTOR] Break encontrado, saliendo del bucle\n");
                break;
            } else if (resBloque == EJEC_CONTINUE) {
                printf("[DEBUG FOR_VECTOR] Continue encontrado, siguiente iteración\n");
                continue;
            } else if (resBloque != EJEC_OK) {
                printf("[ERROR FOR_VECTOR] Error al ejecutar el bloque del FOR_VECTOR\n");
                salirAmbitoForLoop(nombre_var_iter);
                goto cleanup;
            }
        }

        printf("[DEBUG FOR_VECTOR] === FIN ITERACIÓN %d ===\n", i + 1);
    }

    // SALIR DEL ÁMBITO PRESERVANDO LA VARIABLE DE ITERACIÓN
    salirAmbitoForLoop(nombre_var_iter);

cleanup:
    // Liberar memoria de los elementos parseados
    if (elementos) {
        if (simboloColeccion->tipo == TIPO_STRING) {
            char** strings = (char**)elementos;
            for (int i = 0; i < tamanio; i++) {
                if (strings[i]) free(strings[i]);
            }
        }
        free(elementos);
    }

    printf("[DEBUG FOR_VECTOR] === BUCLE FOR_VECTOR COMPLETADO ===\n");
    return EJEC_OK;
}