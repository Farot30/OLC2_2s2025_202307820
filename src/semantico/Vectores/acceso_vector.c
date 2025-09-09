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


int verificarAccesoVector(NodoAST* nodo) {
    printf("[DEBUG verificarAccesoVector] Iniciando verificación\n");

    if (!nodo) {
        printf("[ERROR] Nodo es NULL\n");
        return 0;
    }

    if (nodo->num_hijos < 2) {
        printf("[ERROR] Nodo no tiene suficientes hijos para un acceso a vector/matriz\n");
        return 0;
    }

    NodoAST* idNodo = nodo->hijos[0];    // Identificador
    NodoAST* dimensionesNodo = nodo->hijos[1]; // Nodo de dimensiones

    // Verificar que los nodos no sean NULL
    if (!idNodo || !dimensionesNodo) {
        printf("[ERROR] Uno de los nodos hijos es NULL\n");
        return 0;
    }

    // Verificar que el valor del identificador no sea NULL
    if (!idNodo->valor) {
        printf("[ERROR] Identificador es NULL\n");
        return 0;
    }

    // Buscar el símbolo en la tabla
    Simbolo* simbolo = buscarSimbolo(idNodo->valor);
    if (!simbolo) {
        char msg[128];
        snprintf(msg, sizeof(msg), "Variable '%s' no declarada", idNodo->valor);
        addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
        printf("[ERROR] %s\n", msg);
        idNodo->valido = 0;
        nodo->valido = 0;
        return 0;
    }

    // Verificar que el símbolo sea un vector o matriz o array dimensional
    if (simbolo->clase != SIMBOLO_VECTOR && 
        simbolo->clase != SIMBOLO_MATRIZ && 
        simbolo->clase != SIMBOLO_ARRAY_MULTIDIMENSIONAL) {
        char msg[128];
        snprintf(msg, sizeof(msg), "Variable '%s' no es un vector, matriz o array multidimensional", idNodo->valor);
        addError(msg, ambitoActual(), idNodo->linea, idNodo->columna);
        printf("[ERROR] %s\n", msg);
        idNodo->valido = 0;
        nodo->valido = 0;
        return 0;
    }

    // Verificar que el nodo de dimensiones sea del tipo correcto
    if (dimensionesNodo->tipo != AST_DIMENSIONES) {
        printf("[ERROR] Se esperaba un nodo de dimensiones, se encontró tipo %d\n", 
               dimensionesNodo->tipo);
        return 0;
    }

    // Obtener el número de dimensiones en el acceso
    int numDimensionesAcceso = 0;
    for (int i = 0; i < dimensionesNodo->num_hijos; i++) {
        if (dimensionesNodo->hijos[i]->tipo == AST_1DIMENSION) {
            numDimensionesAcceso++;
        }
    }
    
    printf("[DEBUG] Acceso a '%s' con %d dimensiones\n", idNodo->valor, numDimensionesAcceso);

    // Verificar el número correcto de dimensiones según el tipo de estructura
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

    // Evaluar cada dimensión y verificar que sean índices válidos
    int dimensionesOriginales[10] = {0}; // Máximo 10 dimensiones por simplificar
    int numDimensionesOriginales = 0;
    
    // Obtener las dimensiones originales del vector/matriz/array
    if (simbolo->valor.inicializado && simbolo->valor.v.s) {
        // Vector sin formato de dimensiones, contar elementos directamente
        char* valorCopy = strdup(simbolo->valor.v.s);
        int count = 1; // Al menos un elemento
        
        for (char* p = valorCopy; *p; p++) {
            if (*p == ',') count++;
        }
        
        dimensionesOriginales[0] = count;
        numDimensionesOriginales = 1;
        
        printf("[DEBUG] Vector '%s' con formato simple, contiene %d elementos\n", 
            idNodo->valor, count);
        
        free(valorCopy);
    }
    
    printf("[DEBUG] '%s' tiene %d dimensiones originales: ", idNodo->valor, numDimensionesOriginales);
    for (int i = 0; i < numDimensionesOriginales; i++) {
        printf("%d ", dimensionesOriginales[i]);
    }
    printf("\n");
    
    // Verificar que el array tenga las dimensiones esperadas
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
    
    // Verificar cada índice
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
                nodo->valido = 0;
                return 0;
            }
            
            printf("[DEBUG] Índice %d: %d (en rango: 0-%d)\n", 
                idx + 1, valor.v.i, max_idx);
        } else {
            printf("[ERROR] No se pudo determinar el rango para el índice %d\n", idx + 1);
            nodo->valido = 0;
            return 0;
        }
        
        printf("[DEBUG] Índice %d: %d (en rango: 0-%d)\n", 
               idx + 1, valor.v.i, dimensionesOriginales[idx] - 1);
        
        idx++;
    }
    
    // Asignar el tipo del elemento al nodo de acceso
    nodo->columna = simbolo->tipo;
    
    printf("[DEBUG verificarAccesoVector] Acceso a '%s' válido, tipo: %s\n", 
           idNodo->valor, nombreTipo(simbolo->tipo));
    
    return 1;
}