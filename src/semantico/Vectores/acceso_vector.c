#include "acceso_vector.h"
#include "../tipos.h"
#include "../tabla_simbolo.h"
#include "../semantico.h"
#include "../../AST/err.h"
#include "../../AST/errorTIpos.h"
#include "../../simbolos/Evaluador.h" 
#include "../../simbolos/Operador.h"
#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

// Función para validar la estructura básica del nodo
static int validarEstructuraNodo(NodoAST* nodo, NodoAST** idNodo, NodoAST** dimensionesNodo) {
    if (!nodo) {
        printf("[ERROR] Nodo es NULL\n");
        return 0;
    }

    if (nodo->num_hijos < 2) {
        printf("[ERROR] Nodo no tiene suficientes hijos para un acceso a vector/matriz\n");
        return 0;
    }

    *idNodo = nodo->hijos[0];             // Identificador
    *dimensionesNodo = nodo->hijos[1];    // Nodo de dimensiones

    // Verificar que los nodos no sean NULL
    if (!(*idNodo) || !(*dimensionesNodo)) {
        printf("[ERROR] Uno de los nodos hijos es NULL\n");
        return 0;
    }

    // Verificar que el valor del identificador no sea NULL
    if (!(*idNodo)->valor) {
        printf("[ERROR] Identificador es NULL\n");
        return 0;
    }

    // Verificar que el nodo de dimensiones sea del tipo correcto
    if ((*dimensionesNodo)->tipo != AST_DIMENSIONES) {
        printf("[ERROR] Se esperaba un nodo de dimensiones, se encontró tipo %d\n", 
               (*dimensionesNodo)->tipo);
        return 0;
    }

    return 1;
}

// Función para verificar el símbolo buscado
static int validarSimbolo(NodoAST* nodo, NodoAST* idNodo, Simbolo** simbolo) {
    // Buscar el símbolo en la tabla
    *simbolo = buscarSimbolo(idNodo->valor);
    if (!(*simbolo)) {
        char msg[128];
        snprintf(msg, sizeof(msg), "Variable '%s' no declarada", idNodo->valor);
        addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
        printf("[ERROR] %s\n", msg);
        idNodo->valido = 0;
        nodo->valido = 0;
        return 0;
    }

    // Verificar que el símbolo sea un vector o matriz o array dimensional
    if ((*simbolo)->clase != SIMBOLO_VECTOR && 
        (*simbolo)->clase != SIMBOLO_MATRIZ && 
        (*simbolo)->clase != SIMBOLO_ARRAY_MULTIDIMENSIONAL) {
        char msg[128];
        snprintf(msg, sizeof(msg), "Variable '%s' no es un vector, matriz o array multidimensional", idNodo->valor);
        addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
        printf("[ERROR] %s\n", msg);
        idNodo->valido = 0;
        nodo->valido = 0;
        return 0;
    }

    return 1;
}

// Función para contar las dimensiones de acceso
static int contarDimensionesAcceso(NodoAST* dimensionesNodo) {
    int numDimensionesAcceso = 0;
    for (int i = 0; i < dimensionesNodo->num_hijos; i++) {
        if (dimensionesNodo->hijos[i]->tipo == AST_1DIMENSION) {
            numDimensionesAcceso++;
        }
    }
    return numDimensionesAcceso;
}

// Función para verificar compatibilidad de dimensiones
static int verificarCompatibilidadDimensiones(NodoAST* nodo, NodoAST* idNodo, Simbolo* simbolo, int numDimensionesAcceso) {
    if (simbolo->clase == SIMBOLO_VECTOR && numDimensionesAcceso != 1) {
        char msg[128];
        snprintf(msg, sizeof(msg), "Vector '%s' requiere exactamente 1 índice, se proporcionaron %d", 
                 idNodo->valor, numDimensionesAcceso);
        addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
        printf("[ERROR] %s\n", msg);
        nodo->valido = 0;
        return 0;
    } else if (simbolo->clase == SIMBOLO_MATRIZ && numDimensionesAcceso != 2) {
        char msg[128];
        snprintf(msg, sizeof(msg), "Matriz '%s' requiere exactamente 2 índices, se proporcionaron %d", 
                 idNodo->valor, numDimensionesAcceso);
        addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
        printf("[ERROR] %s\n", msg);
        nodo->valido = 0;
        return 0;
    }
    return 1;
}

// Función para analizar las dimensiones de una matriz
static void analizarDimensionesMatriz(const char* matrixStr, int* numFilas, int* numColumnas) {
    char* matrixCopy = strdup(matrixStr);
    if (!matrixCopy) return;
    
    // Contar filas (corchetes internos)
    *numFilas = 0;
    *numColumnas = 0;
    char* p = matrixCopy;
    
    // Contar filas (separadas por ],[)
    while (*p) {
        if (*p == '[' && (p == matrixCopy || *(p-1) == ',')) (*numFilas)++;
        p++;
    }
    
    // Contar columnas en la primera fila
    if (*numFilas > 0) {
        p = strchr(matrixCopy, '[');
        if (p) {
            p++; // Saltar el primer corchete
            char* endRow = strchr(p, ']');
            if (endRow) {
                // Contar comas dentro de la primera fila + 1
                *numColumnas = 1; // Al menos un elemento
                while (p < endRow) {
                    if (*p == ',') (*numColumnas)++;
                    p++;
                }
            }
        }
    }
    
    free(matrixCopy);
}

// Función para analizar las dimensiones de un vector
static int contarElementosVector(const char* vectorStr) {
    char* valorCopy = strdup(vectorStr);
    if (!valorCopy) return 0;
    
    int count = 1; // Al menos un elemento
    
    for (char* p = valorCopy; *p; p++) {
        if (*p == ',') count++;
    }
    
    free(valorCopy);
    return count;
}

// Función para obtener dimensiones originales del símbolo
static int obtenerDimensionesOriginales(Simbolo* simbolo, NodoAST* idNodo, int* dimensionesOriginales) {
    int numDimensionesOriginales = 0;
    
    if (simbolo->valor.inicializado && simbolo->valor.v.s) {
        // Detectar si es una matriz analizando el formato
        if (simbolo->clase == SIMBOLO_MATRIZ) {
            int numFilas = 0, numColumnas = 0;
            analizarDimensionesMatriz(simbolo->valor.v.s, &numFilas, &numColumnas);
            
            printf("[DEBUG] Matriz '%s' detectada con formato: %d filas, %d columnas\n", 
                   idNodo->valor, numFilas, numColumnas);
            
            dimensionesOriginales[0] = numFilas;
            dimensionesOriginales[1] = numColumnas;
            numDimensionesOriginales = 2;
        } else {
            // Vector sin formato de dimensiones, contar elementos directamente
            int count = contarElementosVector(simbolo->valor.v.s);
            
            dimensionesOriginales[0] = count;
            numDimensionesOriginales = 1;
            
            printf("[DEBUG] Vector '%s' con formato simple, contiene %d elementos\n", 
                idNodo->valor, count);
        }
    }
    
    return numDimensionesOriginales;
}

// Función para validar un índice específico
static int validarIndice(NodoAST* nodo, NodoAST* idNodo, NodoAST* exprNodo, int idx, int numDimensionesOriginales, int* dimensionesOriginales) {
    ValorSimbolo valor = evaluarExpr(exprNodo);
    
    // Verificar que el índice sea entero
    if (!valor.inicializado || valor.tipo != TIPO_INT) {
        char msg[128];
        snprintf(msg, sizeof(msg), "El índice %d de '%s' debe ser entero", 
                 idx + 1, idNodo->valor);
        addError(msg, ambitoActual(), exprNodo->linea, exprNodo->columna);
        printf("[ERROR] %s\n", msg);
        nodo->valido = 0;
        return 0;
    }
    
    // Verificar que el índice esté dentro de los límites
    if (idx < numDimensionesOriginales) {
        int max_idx = dimensionesOriginales[idx] - 1;
        if (max_idx < 0) max_idx = 0; // Evitar rangos negativos
        
        if (valor.v.i < 0 || valor.v.i > max_idx) {
            char msg[128];
            snprintf(msg, sizeof(msg), "Índice %d fuera de rango: %d (rango válido: 0-%d)", 
                    idx + 1, valor.v.i, max_idx);
            addError(msg, ambitoActual(), exprNodo->linea, exprNodo->columna);
            printf("[ERROR] %s\n", msg);
            return 0;
        }
        
        printf("[DEBUG] Índice %d: %d (en rango: 0-%d)\n", 
            idx + 1, valor.v.i, max_idx);
        
        return 1;
    } else {
        printf("[ERROR] No se pudo determinar el rango para el índice %d\n", idx + 1);
        nodo->valido = 0;
        return 0;
    }
}

// Función para validar todos los índices de acceso
static int validarIndices(NodoAST* nodo, NodoAST* idNodo, NodoAST* dimensionesNodo, int numDimensionesOriginales, int* dimensionesOriginales) {
    int idx = 0;
    for (int i = 0; i < dimensionesNodo->num_hijos; i++) {
        if (dimensionesNodo->hijos[i]->tipo != AST_1DIMENSION) continue;
        
        NodoAST* dimNodo = dimensionesNodo->hijos[i];
        if (dimNodo->num_hijos < 1) {
            printf("[ERROR] Nodo de dimensión sin expresión\n");
            nodo->valido = 0;
            return 0;
        }
        
        NodoAST* exprNodo = dimNodo->hijos[0];
        if (!validarIndice(nodo, idNodo, exprNodo, idx, numDimensionesOriginales, dimensionesOriginales)) {
            return 0;
        }
        
        idx++;
    }
    
    return 1;
}

// Función principal refactorizada
int verificarAccesoVector(NodoAST* nodo) {
    printf("[DEBUG verificarAccesoVector] Iniciando verificación\n");

    NodoAST* idNodo = NULL;
    NodoAST* dimensionesNodo = NULL;
    Simbolo* simbolo = NULL;
    
    // Validar estructura básica del nodo
    if (!validarEstructuraNodo(nodo, &idNodo, &dimensionesNodo)) {
        return 0;
    }
    
    // Validar el símbolo
    if (!validarSimbolo(nodo, idNodo, &simbolo)) {
        return 0;
    }
    
    // Contar dimensiones de acceso
    int numDimensionesAcceso = contarDimensionesAcceso(dimensionesNodo);
    printf("[DEBUG] Acceso a '%s' con %d dimensiones\n", idNodo->valor, numDimensionesAcceso);
    
    // Verificar compatibilidad de dimensiones
    if (!verificarCompatibilidadDimensiones(nodo, idNodo, simbolo, numDimensionesAcceso)) {
        return 0;
    }
    
    // Obtener dimensiones originales
    int dimensionesOriginales[10] = {0}; // Máximo 10 dimensiones por simplificar
    int numDimensionesOriginales = obtenerDimensionesOriginales(simbolo, idNodo, dimensionesOriginales);
    
    printf("[DEBUG] '%s' tiene %d dimensiones originales: ", idNodo->valor, numDimensionesOriginales);
    for (int i = 0; i < numDimensionesOriginales; i++) {
        printf("%d ", dimensionesOriginales[i]);
    }
    printf("\n");
    
    // Verificar dimensiones para arrays multidimensionales
    if (simbolo->clase == SIMBOLO_ARRAY_MULTIDIMENSIONAL && 
        numDimensionesAcceso != numDimensionesOriginales) {
        char msg[128];
        snprintf(msg, sizeof(msg), "Array '%s' requiere %d índices, se proporcionaron %d", 
                 idNodo->valor, numDimensionesOriginales, numDimensionesAcceso);
        addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
        printf("[ERROR] %s\n", msg);
        nodo->valido = 0;
        return 0;
    }
    
    // Validar todos los índices
    if (!validarIndices(nodo, idNodo, dimensionesNodo, numDimensionesOriginales, dimensionesOriginales)) {
        return 0;
    }
    
    // Asignar el tipo del elemento al nodo de acceso
    nodo->columna = simbolo->tipo;
    
    printf("[DEBUG verificarAccesoVector] Acceso a '%s' válido, tipo: %s\n", 
           idNodo->valor, nombreTipo(simbolo->tipo));
    
    return 1;
}