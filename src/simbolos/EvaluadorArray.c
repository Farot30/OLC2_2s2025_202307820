#include "Evaluador.h"
#include "Operador.h"
#include "EvaluadorArray.h"
#include "../semantico/semantico.h"
#include "../semantico/Vectores/acceso_vector.h"
#include "../AST/err.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> 
#include <limits.h>
#include <math.h>

// Función para evaluar Array.indexOf
ValorSimbolo evaluarIndexof(NodoAST* e) {
    ValorSimbolo r;
    r.inicializado = 0;
    r.tipo = TIPO_INT;
    r.v.i = -1;
    if (e->num_hijos < 2) {
        printf("[ERROR] Arrays.indexOf requiere un array y un valor a buscar\n");
        return r;
    }
            
    // Evaluar el array (solo necesitamos el identificador, no su valor)
    NodoAST* arrayNodo = e->hijos[0];
    if (arrayNodo->tipo != AST_IDENTIFICADOR) {
        printf("[ERROR] El primer argumento de Arrays.indexOf debe ser un identificador de array\n");
        return r;
    }
            
    // Buscar el símbolo en la tabla
    Simbolo* simboloArray = buscarSimbolo(arrayNodo->valor);
    if (!simboloArray) {
        printf("[ERROR] Vector '%s' no declarado\n", arrayNodo->valor);
        return r;
    }
            
    // Verificar que sea un vector o matriz
    if (simboloArray->clase != SIMBOLO_VECTOR && simboloArray->clase != SIMBOLO_MATRIZ) {
        printf("[ERROR] '%s' no es un vector o matriz\n", arrayNodo->valor);
        return r;
    }
            
    // Verificar que esté inicializado
    if (!simboloArray->valor.inicializado || !simboloArray->valor.v.s) {
        printf("[ERROR] Vector '%s' no inicializado\n", arrayNodo->valor);
        return r;
    }
        
    // Evaluar la clave a buscar
    ValorSimbolo claveVal = evaluarExpr(e->hijos[1]);
    if (!claveVal.inicializado) {
        printf("[ERROR] Clave no inicializada en Arrays.indexOf\n");
        return r;
    }
            
    printf("[DEBUG] Buscando valor en vector '%s', formato: %s\n", 
        simboloArray->nombre, simboloArray->valor.v.s);
            
    // Ahora buscamos la clave en el array
    int indice = -1;  // Por defecto, no encontrado
            
    // Extraer los elementos del array
    char* arrayStr = strdup(simboloArray->valor.v.s);
            
    // Eliminar corchetes si existen
    if (arrayStr[0] == '[') {
        memmove(arrayStr, arrayStr + 1, strlen(arrayStr));
        int len = strlen(arrayStr);
        if (len > 0 && arrayStr[len - 1] == ']') {
                arrayStr[len - 1] = '\0';
        }
    }
            
    // Extraer los elementos del array
    char* elementos[1000];  // Max 1000 elementos
    int numElementos = 0;

    char* elementosCopy = strdup(arrayStr);
    char* token = strtok(elementosCopy, ",");
            
    while (token && numElementos < 1000) {
        // Limpiar espacios al inicio y final
        while (*token && isspace(*token)) token++;
        char* end = token + strlen(token) - 1;
        while (end > token && isspace(*end)) *end-- = '\0';
                
        elementos[numElementos++] = strdup(token);
        token = strtok(NULL, ",");
    }
            
    printf("[DEBUG] Procesando %d elementos en vector\n", numElementos);
        
    // Convertir la clave al tipo adecuado y comparar
    for (int i = 0; i < numElementos; i++) {
        int found = 0;

        switch (simboloArray->tipo) {
            case TIPO_INT: {
                int elemVal = atoi(elementos[i]);
                int keyVal = (claveVal.tipo == TIPO_INT) ? claveVal.v.i : 
                            (claveVal.tipo == TIPO_FLOAT) ? (int)claveVal.v.f : 
                            (claveVal.tipo == TIPO_DOUBLE) ? (int)claveVal.v.d : 0;
                        
                printf("[DEBUG] Comparando elemento[%d]=%d con clave=%d\n", i, elemVal, keyVal);
                found = (elemVal == keyVal);
                break;
            }
            case TIPO_FLOAT: {
                float elemVal = strtof(elementos[i], NULL);
                float keyVal = (claveVal.tipo == TIPO_INT) ? (float)claveVal.v.i : 
                            (claveVal.tipo == TIPO_FLOAT) ? claveVal.v.f : 
                            (claveVal.tipo == TIPO_DOUBLE) ? (float)claveVal.v.d : 0.0f;
                    
                printf("[DEBUG] Comparando elemento[%d]=%f con clave=%f\n", i, elemVal, keyVal);
                found = (fabs(elemVal - keyVal) < 0.00001f);  // Tolerancia para float
                break;
            }
            case TIPO_DOUBLE: {
                double elemVal = strtod(elementos[i], NULL);
                double keyVal = (claveVal.tipo == TIPO_INT) ? (double)claveVal.v.i : 
                                (claveVal.tipo == TIPO_FLOAT) ? (double)claveVal.v.f : 
                                (claveVal.tipo == TIPO_DOUBLE) ? claveVal.v.d : 0.0;
                    
                printf("[DEBUG] Comparando elemento[%d]=%f con clave=%f\n", i, elemVal, keyVal);
                found = (fabs(elemVal - keyVal) < 0.00001);  // Tolerancia para double
                break;
            }
            case TIPO_CHAR: {
                char elemVal = elementos[i][0];
                char keyVal = (claveVal.tipo == TIPO_CHAR) ? claveVal.v.c : 
                        (claveVal.tipo == TIPO_INT) ? (char)claveVal.v.i : '\0';
                        
                printf("[DEBUG] Comparando elemento[%d]=%c con clave=%c\n", i, elemVal, keyVal);
                found = (elemVal == keyVal);
                break;
            }
            case TIPO_BOOLEAN: {
                int elemVal = (strcmp(elementos[i], "true") == 0) ? 1 : 0;
                int keyVal = (claveVal.tipo == TIPO_BOOLEAN) ? claveVal.v.b : 0;
                    
                printf("[DEBUG] Comparando elemento[%d]=%s con clave=%s\n", 
                    i, elemVal ? "true" : "false", keyVal ? "true" : "false");
                found = (elemVal == keyVal);
                break;
            }
            case TIPO_STRING: {
                if (claveVal.tipo == TIPO_STRING && claveVal.v.s) {
                    // Eliminar comillas de los elementos si existen
                    char* elemStrTemp = strdup(elementos[i]);
                    size_t len = strlen(elemStrTemp);

                    // Eliminar las comillas del principio y final si existen
                    if (len >= 2 && elemStrTemp[0] == '"' && elemStrTemp[len-1] == '"') {
                        elemStrTemp[len-1] = '\0';  // Eliminar comilla final
                        char* strippedElem = elemStrTemp + 1;  // Saltar comilla inicial
                                
                        printf("[DEBUG] Comparando elemento[%d]=%s con clave=%s\n", 
                            i, strippedElem, claveVal.v.s);
                                    
                        found = (strcmp(strippedElem, claveVal.v.s) == 0);
                    } else {
                        // Si no tiene comillas, comparar directamente
                        printf("[DEBUG] Comparando elemento[%d]=%s con clave=%s\n", 
                            i, elemStrTemp, claveVal.v.s);
                                
                        found = (strcmp(elemStrTemp, claveVal.v.s) == 0);
                    }
                            
                    free(elemStrTemp);
                }
                break;
            }
            default:
                break;
        }
                
        if (found) {
            indice = i;
            printf("[DEBUG] ¡Encontrado! en índice %d\n", i);
            break;  // Encontrado, salimos del bucle
        }
    }
            
    // Liberar memoria
    for (int i = 0; i < numElementos; i++) {
        free(elementos[i]);
    }
    free(elementosCopy);
    free(arrayStr);
            
    // Devolver el índice como un entero
    r = makeNum(TIPO_INT, (double)indice);
    r.tipo = TIPO_INT;
    printf("[DEBUG] Arrays.indexOf resultado: %d\n", indice);
            
    return r;
}

// Función para obtener dimensiones de un array
void obtenerDimensionesArray(Simbolo* simbolo, int* dimensiones, int* numDimensiones) {
    if (!simbolo || !simbolo->valor.v.s || !dimensiones || !numDimensiones) return;
    
    // Inicializar
    *numDimensiones = 0;
    
    // Si es una matriz, procesar su formato específico
    if (simbolo->clase == SIMBOLO_MATRIZ) {
        // Formato matriz: [[val1,val2,...],[val1,val2,...],...]
        char* matrixCopy = strdup(simbolo->valor.v.s);
        if (matrixCopy) {
            // Contar filas (corchetes internos)
            int numFilas = 0;
            int numColumnas = 0;
            char* p = matrixCopy;
            
            // Contar filas (separadas por ],[)
            while (*p) {
                if (*p == '[' && (p == matrixCopy || *(p-1) == ',')) numFilas++;
                p++;
            }
            
            // Contar columnas en la primera fila
            if (numFilas > 0) {
                p = strchr(matrixCopy, '[');
                if (p) {
                    p++; // Saltar el primer corchete
                    char* endRow = strchr(p, ']');
                    if (endRow) {
                        // Contar comas dentro de la primera fila + 1
                        numColumnas = 1; // Al menos un elemento
                        while (p < endRow) {
                            if (*p == ',') numColumnas++;
                            p++;
                        }
                    }
                }
            }
            
            printf("[EVALUADOR] Matriz '%s' detectada con formato: %d filas, %d columnas\n", 
                simbolo->nombre, numFilas, numColumnas);
            
            dimensiones[0] = numFilas;
            dimensiones[1] = numColumnas;
            *numDimensiones = 2;
            
            free(matrixCopy);
        }
    } else if (simbolo->clase == SIMBOLO_VECTOR) {
        // Vector: contar elementos directamente
        char* valorCopy = strdup(simbolo->valor.v.s);
        int count = 1; // Al menos un elemento
        
        // Eliminar corchetes si existen
        if (valorCopy[0] == '[') {
            memmove(valorCopy, valorCopy + 1, strlen(valorCopy));
            int len = strlen(valorCopy);
            if (len > 0 && valorCopy[len - 1] == ']') {
                valorCopy[len - 1] = '\0';
            }
        }
        
        // Contar comas para determinar número de elementos
        for (char* p = valorCopy; *p; p++) {
            if (*p == ',') count++;
        }
        
        dimensiones[0] = count;
        *numDimensiones = 1;
        
        free(valorCopy);
        printf("[EVALUADOR] Vector '%s' con %d elementos\n", simbolo->nombre, count);
    }
}

// Función para evaluar Array.length
ValorSimbolo evaluarLength(NodoAST* e) {
    ValorSimbolo r;
    memset(&r, 0, sizeof(r));
    r.tipo = TIPO_INT;
    r.v.i = 0;
    
    if (e->num_hijos < 1) {
        printf("[ERROR] Array.length requiere un identificador\n");
        return r;
    }
    
    NodoAST* idNodo = e->hijos[0];
    if (idNodo->tipo != AST_IDENTIFICADOR) {
        printf("[ERROR] Array.length solo se puede aplicar a identificadores\n");
        return r;
    }
    
    Simbolo* simbolo = buscarSimbolo(idNodo->valor);
    if (!simbolo) {
        printf("[ERROR] Variable '%s' no declarada\n", idNodo->valor);
        return r;
    }
    
    if (simbolo->clase != SIMBOLO_VECTOR && simbolo->clase != SIMBOLO_MATRIZ && simbolo->clase != SIMBOLO_ARRAY_MULTIDIMENSIONAL) {
        printf("[ERROR] Array.length solo se puede aplicar a arreglos\n");
        return r;
    }
    
    int dimensiones[10] = {0};
    int numDimensiones = 0;
    obtenerDimensionesArray(simbolo, dimensiones, &numDimensiones);
    
    int len = 1;
    for (int i = 0; i < numDimensiones; i++) len *= dimensiones[i];
    
    r = makeNum(TIPO_INT, (double)len);
    r.tipo = TIPO_INT;
    r.inicializado = 1;
    printf("[DEBUG] Array.length de '%s' = %d\n", idNodo->valor, len);
    
    return r;
}

// Función para evaluar Array.add
ValorSimbolo evaluarAdd(NodoAST* e) {
    ValorSimbolo r;
    memset(&r, 0, sizeof(r));
    r.tipo = TIPO_DESCONOCIDO;
    r.inicializado = 0;
    
    // Verificamos que tengamos identificador como primer hijo
    if (e->num_hijos < 1 || e->hijos[0]->tipo != AST_IDENTIFICADOR) {
        printf("[ERROR] Array.add requiere un identificador de array\n");
        return r;
    }
    
    // Verificar si hay un elemento para añadir
    if (e->num_hijos < 2) {
        printf("[ERROR] Array.add requiere un elemento para añadir\n");
        return r;
    }
    
    // Buscar el símbolo del array
    NodoAST* idNodo = e->hijos[0];
    Simbolo* simboloArray = buscarSimbolo(idNodo->valor);
    if (!simboloArray) {
        printf("[ERROR] Array '%s' no declarado\n", idNodo->valor);
        return r;
    }
    
    // Verificar que sea un vector
    if (simboloArray->clase != SIMBOLO_VECTOR) {
        printf("[ERROR] '%s' no es un vector\n", idNodo->valor);
        return r;
    }
    
    // Verificar que esté inicializado
    if (!simboloArray->valor.inicializado || !simboloArray->valor.v.s) {
        printf("[ERROR] Vector '%s' no inicializado\n", idNodo->valor);
        return r;
    }
    
    // Evaluar el elemento a añadir
    ValorSimbolo nuevoElemento = evaluarExpr(e->hijos[1]);
    if (!nuevoElemento.inicializado) {
        printf("[ERROR] Elemento a añadir no inicializado\n");
        return r;
    }
    
    // Verificar compatibilidad de tipos
    if (nuevoElemento.tipo != simboloArray->tipo) {
        printf("[ERROR] Tipo incompatible: intentando añadir %s a un array de %s\n", 
            nombreTipo(nuevoElemento.tipo), nombreTipo(simboloArray->tipo));
        return r;
    }
    
    // Obtener la representación del array actual
    char* arrayActual = strdup(simboloArray->valor.v.s);
    
    // Convertir el nuevo elemento a string según su tipo
    char elementoStr[256];
    switch (nuevoElemento.tipo) {
        case TIPO_INT:
            snprintf(elementoStr, sizeof(elementoStr), "%d", nuevoElemento.v.i);
            break;
        case TIPO_FLOAT:
            snprintf(elementoStr, sizeof(elementoStr), "%f", nuevoElemento.v.f);
            break;
        case TIPO_DOUBLE:
            snprintf(elementoStr, sizeof(elementoStr), "%f", nuevoElemento.v.d);
            break;
        case TIPO_CHAR:
            snprintf(elementoStr, sizeof(elementoStr), "'%c'", nuevoElemento.v.c);
            break;
        case TIPO_BOOLEAN:
            snprintf(elementoStr, sizeof(elementoStr), "%s", nuevoElemento.v.b ? "true" : "false");
            break;
        case TIPO_STRING:
            snprintf(elementoStr, sizeof(elementoStr), "\"%s\"", nuevoElemento.v.s ? nuevoElemento.v.s : "");
            break;
        default:
            elementoStr[0] = '\0';
            break;
    }
    
    // Crear el nuevo array con el elemento añadido
    char nuevoArray[4096]; // Tamaño suficiente para la mayoría de los arrays
    
    // Si el array actual está vacío o es [0], crear uno nuevo con solo el elemento
    if (strcmp(arrayActual, "[]") == 0 || strcmp(arrayActual, "[0]") == 0) {
        snprintf(nuevoArray, sizeof(nuevoArray), "[%s]", elementoStr);
    } else {
        // Eliminar el corchete de cierre, añadir el elemento y cerrar el array
        size_t len = strlen(arrayActual);
        if (len > 0 && arrayActual[len-1] == ']') {
            arrayActual[len-1] = '\0';
            snprintf(nuevoArray, sizeof(nuevoArray), "%s,%s]", arrayActual, elementoStr);
        } else {
            // Formato inválido, usar formato por defecto
            snprintf(nuevoArray, sizeof(nuevoArray), "[%s]", elementoStr);
        }
    }
    
    // Crear el resultado como un nuevo array del mismo tipo
    r.tipo = simboloArray->tipo;
    r.inicializado = 1;
    r.v.s = strdup(nuevoArray);
    
    printf("[DEBUG] Array.add: %s + %s = %s\n", 
        simboloArray->valor.v.s, elementoStr, nuevoArray);
    
    free(arrayActual);
    return r;
}

// Función auxiliar para evaluar índices de acceso a arrays
static int evaluarIndices(NodoAST* dimensionesNodo, int* indices, int maxDim) {
    int numIndices = 0;
    
    for (int i = 0; i < dimensionesNodo->num_hijos && numIndices < maxDim; i++) {
        NodoAST* dimNodo = dimensionesNodo->hijos[i];
        if (dimNodo->tipo == AST_1DIMENSION) {
            if (dimNodo->num_hijos < 1) {
                printf("[EVALUADOR] Dimensión sin expresión\n");
                return -1;
            }
            
            // Evaluar índice
            ValorSimbolo idxVal = evaluarExpr(dimNodo->hijos[0]);
            if (!idxVal.inicializado || idxVal.tipo != TIPO_INT) {
                printf("[EVALUADOR] Índice debe ser entero\n");
                return -1;
            }
            
            indices[numIndices++] = idxVal.v.i;
        }
    }
    
    return numIndices;
}

// Función auxiliar para procesar acceso a un vector
static ValorSimbolo procesarAccesoVector(Simbolo* simbolo, int indice) {
    ValorSimbolo r;
    memset(&r, 0, sizeof(r));
    r.tipo = simbolo->tipo;
    r.inicializado = 1;
    
    char* valCopy = strdup(simbolo->valor.v.s);
    char* valores = valCopy;
    
    // Eliminar corchetes si existen
    if (valores[0] == '[') {
        memmove(valores, valores + 1, strlen(valores));
        int len = strlen(valores);
        if (len > 0 && valores[len - 1] == ']') {
            valores[len - 1] = '\0';
        }
    }
    
    // Extraer elementos
    char* valoresCopy = strdup(valores);
    char* elementos[256]; // Máximo 256 elementos
    int numElementos = 0;
    
    char* token = strtok(valoresCopy, ",");
    while (token && numElementos < 256) {
        // Limpiar espacios
        while (*token && isspace(*token)) token++;
        char* end = token + strlen(token) - 1;
        while (end > token && isspace(*end)) *end-- = '\0';
        
        elementos[numElementos++] = strdup(token);
        token = strtok(NULL, ",");
    }
    
    // Verificar índice dentro del rango
    if (indice >= 0 && indice < numElementos) {
        // Convertir según el tipo
        switch (simbolo->tipo) {
            case TIPO_INT:
                r.v.i = atoi(elementos[indice]);
                break;
            case TIPO_FLOAT:
                r.v.f = strtof(elementos[indice], NULL);
                break;
            case TIPO_DOUBLE:
                r.v.d = strtod(elementos[indice], NULL);
                break;
            case TIPO_CHAR:
                r.v.c = elementos[indice][0];
                break;
            case TIPO_BOOLEAN:
                r.v.b = (strcmp(elementos[indice], "true") == 0);
                break;
            case TIPO_STRING:
                r.v.s = strdup(elementos[indice]);
                break;
            default:
                r.inicializado = 0;
                break;
        }
        printf("[EVALUADOR] Vector '%s[%d]' = '%s'\n", 
            simbolo->nombre, indice, elementos[indice]);
    } else {
        printf("[EVALUADOR] Índice %d fuera de rango (0-%d)\n", 
            indice, numElementos-1);
        r.inicializado = 0;
    }
    
    // Liberar memoria
    for (int i = 0; i < numElementos; i++) {
        free(elementos[i]);
    }
    free(valoresCopy);
    free(valCopy);
    
    return r;
}

// Función auxiliar para procesar acceso a una matriz
static ValorSimbolo procesarAccesoMatriz(Simbolo* simbolo, int filaIdx, int colIdx) {
    ValorSimbolo r;
    memset(&r, 0, sizeof(r));
    r.tipo = simbolo->tipo;
    r.inicializado = 1;
    
    printf("[EVALUADOR] Accediendo a matriz '%s[%d][%d]'\n", 
        simbolo->nombre, filaIdx, colIdx);
    
    char* matrixStr = strdup(simbolo->valor.v.s);
    
    // Verificar formato
    if (matrixStr[0] != '[' || matrixStr[1] != '[') {
        printf("[EVALUADOR] Formato de matriz no reconocido\n");
        free(matrixStr);
        r.inicializado = 0;
        return r;
    }
    
    // Extraer filas de la matriz
    char* matrixCopy = strdup(matrixStr);
    char* filas[50]; // Máximo 50 filas
    int numFilas = 0;
    
    // Quitar corchete externo inicial
    memmove(matrixCopy, matrixCopy + 1, strlen(matrixCopy));
    
    // Quitar corchete externo final si existe
    int len = strlen(matrixCopy);
    if (len > 0 && matrixCopy[len - 1] == ']') {
        matrixCopy[len - 1] = '\0';
    }
    
    // Extraer cada fila - tienen formato [val1,val2,...]
    char* p = matrixCopy;
    char* inicioFila = p;
    int nivel = 0;
    
    while (*p) {
        if (*p == '[') nivel++;
        else if (*p == ']') {
            nivel--;
            if (nivel == 0) {
                // Fin de una fila
                *(p+1) = '\0'; // Cortar después del corchete
                filas[numFilas++] = strdup(inicioFila);
                inicioFila = p + 2; // Saltar el corchete y la coma
                p++; // Avanzar después del corchete
            }
        }
        p++;
    }
    
    printf("[EVALUADOR] Matriz analizada con %d filas\n", numFilas);
    
    // Verificar índice de fila
    if (filaIdx < 0 || filaIdx >= numFilas) {
        printf("[EVALUADOR] Índice de fila %d fuera de rango (0-%d)\n", 
            filaIdx, numFilas-1);
        // Liberar memoria
        for (int i = 0; i < numFilas; i++) {
            free(filas[i]);
        }
        free(matrixCopy);
        free(matrixStr);
        r.inicializado = 0;
        return r;
    }
    
    // Analizar la fila seleccionada
    char* filaStr = filas[filaIdx];
    
    // Quitar corchetes de la fila
    if (filaStr[0] == '[') {
        memmove(filaStr, filaStr + 1, strlen(filaStr));
        len = strlen(filaStr);
        if (len > 0 && filaStr[len - 1] == ']') {
            filaStr[len - 1] = '\0';
        }
    }
    
    // Separar elementos de la fila
    char* elementos[100]; // Máximo 100 columnas
    int numElementos = 0;
    
    char* elementosCopy = strdup(filaStr);
    char* token = strtok(elementosCopy, ",");
    while (token && numElementos < 100) {
        // Eliminar espacios al inicio y final si existen
        while (*token && isspace(*token)) token++;
        char* end = token + strlen(token) - 1;
        while (end > token && isspace(*end)) *end-- = '\0';
        
        elementos[numElementos++] = strdup(token);
        token = strtok(NULL, ",");
    }
    
    printf("[EVALUADOR] Fila %d tiene %d elementos\n", filaIdx, numElementos);
    
    // Verificar índice de columna
    if (colIdx < 0 || colIdx >= numElementos) {
        printf("[EVALUADOR] Índice de columna %d fuera de rango (0-%d)\n", 
            colIdx, numElementos-1);
        
        // Liberar memoria
        for (int i = 0; i < numElementos; i++) {
            free(elementos[i]);
        }
        free(elementosCopy);
        
        for (int i = 0; i < numFilas; i++) {
            free(filas[i]);
        }
        free(matrixCopy);
        free(matrixStr);
        
        r.inicializado = 0;
        return r;
    }
    
    // Convertir elemento según el tipo
    printf("[EVALUADOR] Accediendo a elemento [%d][%d] = '%s'\n", 
        filaIdx, colIdx, elementos[colIdx]);
    
    switch (simbolo->tipo) {
        case TIPO_INT:
            r.v.i = atoi(elementos[colIdx]);
            break;
        case TIPO_FLOAT:
            r.v.f = strtof(elementos[colIdx], NULL);
            break;
        case TIPO_DOUBLE:
            r.v.d = strtod(elementos[colIdx], NULL);
            break;
        case TIPO_CHAR:
            r.v.c = elementos[colIdx][0];
            break;
        case TIPO_BOOLEAN:
            r.v.b = (strcmp(elementos[colIdx], "true") == 0);
            break;
        case TIPO_STRING:
            r.v.s = strdup(elementos[colIdx]);
            break;
        default:
            r.inicializado = 0;
            break;
    }
    
    // Liberar toda la memoria
    for (int i = 0; i < numElementos; i++) {
        free(elementos[i]);
    }
    free(elementosCopy);
    
    for (int i = 0; i < numFilas; i++) {
        free(filas[i]);
    }
    free(matrixCopy);
    free(matrixStr);
    
    printf("[EVALUADOR] Matriz '%s[%d][%d]' evaluada correctamente\n", 
        simbolo->nombre, filaIdx, colIdx);
    
    return r;
}

// Función principal para evaluar acceso a arrays
ValorSimbolo evaluarAccesoArrays(NodoAST* nodo) {
    ValorSimbolo r;
    memset(&r, 0, sizeof(r));
    r.tipo = TIPO_DESCONOCIDO;
    
    // Validación básica del nodo
    if (!nodo || nodo->tipo != AST_ACCESO || nodo->num_hijos < 2) {
        printf("[EVALUADOR] Nodo de acceso inválido\n");
        return r;
    }

    NodoAST* idNodo = nodo->hijos[0];
    NodoAST* dimensionesNodo = nodo->hijos[1];
    
    // Validar estructura del nodo
    if (!idNodo || idNodo->tipo != AST_IDENTIFICADOR) {
        printf("[EVALUADOR] Primer hijo no es un identificador\n");
        return r;
    }
    
    if (!dimensionesNodo || dimensionesNodo->tipo != AST_DIMENSIONES) {
        printf("[EVALUADOR] Segundo hijo no es un nodo de dimensiones\n");
        return r;
    }

    // Buscar el símbolo en la tabla
    Simbolo* simbolo = buscarSimbolo(idNodo->valor);
    if (!simbolo) {
        printf("[EVALUADOR] Variable '%s' no declarada\n", idNodo->valor);
        return r;
    }
    
    if (!simbolo->valor.inicializado) {
        printf("[EVALUADOR] Variable '%s' no inicializada\n", idNodo->valor);
        return r;
    }
    
    // Verificar que sea vector, matriz o array multidimensional
    if (simbolo->clase != SIMBOLO_VECTOR && 
        simbolo->clase != SIMBOLO_MATRIZ && 
        simbolo->clase != SIMBOLO_ARRAY_MULTIDIMENSIONAL) {
        printf("[EVALUADOR] Variable '%s' no es un vector, matriz o array\n", idNodo->valor);
        return r;
    }
    
    // Obtener dimensiones del array
    int dimensionesOriginales[10] = {0};
    int numDimensionesOriginales = 0;
    
    obtenerDimensionesArray(simbolo, dimensionesOriginales, &numDimensionesOriginales);
    
    // Verificar que tengamos dimensiones
    if (numDimensionesOriginales == 0) {
        printf("[ERROR] No se pudo determinar las dimensiones de '%s'\n", idNodo->valor);
        return r;
    }
    
    // Evaluar índices
    int indices[10] = {0};
    int numDimensionesAcceso = evaluarIndices(dimensionesNodo, indices, 10);
    
    if (numDimensionesAcceso <= 0) {
        printf("[EVALUADOR] Error al evaluar índices de acceso\n");
        return r;
    }
    
    // Verificar compatibilidad de dimensiones
    if ((simbolo->clase == SIMBOLO_VECTOR && numDimensionesAcceso != 1) ||
        (simbolo->clase == SIMBOLO_MATRIZ && numDimensionesAcceso != 2) ||
        (simbolo->clase == SIMBOLO_ARRAY_MULTIDIMENSIONAL && numDimensionesAcceso != numDimensionesOriginales)) {
        printf("[EVALUADOR] Número incorrecto de dimensiones para '%s'\n", idNodo->valor);
        return r;
    }
    
    // Verificar rangos de índices
    for (int i = 0; i < numDimensionesAcceso; i++) {
        if (indices[i] < 0 || indices[i] >= dimensionesOriginales[i]) {
            printf("[EVALUADOR] Índice %d fuera de rango: %d (válido: 0-%d)\n", 
                   i + 1, indices[i], dimensionesOriginales[i] - 1);
            return r;
        }
    }
    
    printf("[EVALUADOR] Accediendo a '%s' con %d índices\n", idNodo->valor, numDimensionesAcceso);
    
    // Procesar según el tipo de estructura
    if (simbolo->clase == SIMBOLO_VECTOR) {
        return procesarAccesoVector(simbolo, indices[0]);
    } 
    else if (simbolo->clase == SIMBOLO_MATRIZ) {
        return procesarAccesoMatriz(simbolo, indices[0], indices[1]);
    }
    // Arrays multidimensionales (caso general)
    else if (simbolo->clase == SIMBOLO_ARRAY_MULTIDIMENSIONAL) {
        // Para arrays multidimensionales, implementación más compleja
        // El array se almacena como [dim1,dim2,...,dimN][val1,val2,...]
        // donde los valores están en orden row-major
        
        char* arrayStr = strdup(simbolo->valor.v.s);
        char* dataStart = NULL;
        
        // Extraer datos según formato
        if (arrayStr[0] == '[') {
            // Formato con dimensiones
            dataStart = strstr(arrayStr, "][");
            if (dataStart) {
                dataStart += 2; // Saltar "]["
            } else {
                printf("[EVALUADOR] Formato de array incorrecto\n");
                free(arrayStr);
                return r;
            }
        } else {
            // Formato simple (improbable para arrays multidimensionales)
            dataStart = arrayStr;
        }
        
        // Quitar corchetes externos si existen
        if (dataStart[0] == '[') {
            dataStart++; // Saltar '['
            int len = strlen(dataStart);
            if (len > 0 && dataStart[len-1] == ']') {
                dataStart[len-1] = '\0';
            }
        }
        
        // Calcular posición lineal a partir de los índices
        int posLineal = 0;
        int factor = 1;
        
        // Calcular de atrás hacia adelante (row-major order)
        for (int i = numDimensionesOriginales - 1; i >= 0; i--) {
            posLineal += indices[i] * factor;
            factor *= dimensionesOriginales[i];
        }
        
        // Separar todos los elementos
        char* datosCopy = strdup(dataStart);
        char* elementos[10000]; // Un límite grande para arrays multidimensionales
        int numElementos = 0;
        
        char* token = strtok(datosCopy, ",");
        while (token && numElementos < 10000) {
            elementos[numElementos++] = strdup(token);
            token = strtok(NULL, ",");
        }
        
        // Verificar posición lineal dentro del rango
        if (posLineal >= 0 && posLineal < numElementos) {
            // Convertir según el tipo
            switch (simbolo->tipo) {
                case TIPO_INT:
                    r.v.i = atoi(elementos[posLineal]);
                    break;
                case TIPO_FLOAT:
                    r.v.f = strtof(elementos[posLineal], NULL);
                    break;
                case TIPO_DOUBLE:
                    r.v.d = strtod(elementos[posLineal], NULL);
                    break;
                case TIPO_CHAR:
                    r.v.c = elementos[posLineal][0];
                    break;
                case TIPO_BOOLEAN:
                    r.v.b = (strcmp(elementos[posLineal], "true") == 0);
                    break;
                case TIPO_STRING:
                    r.v.s = strdup(elementos[posLineal]);
                    break;
                default:
                    r.inicializado = 0;
                    break;
            }
            
            // Construir string para mostrar el acceso multidimensional
            char indicesStr[128] = "";
            for (int i = 0; i < numDimensionesAcceso; i++) {
                char temp[16];
                sprintf(temp, "[%d]", indices[i]);
                strcat(indicesStr, temp);
            }
            
            printf("[EVALUADOR] Array '%s%s' = '%s' (pos. lineal: %d)\n", 
                   idNodo->valor, indicesStr, elementos[posLineal], posLineal);
        } else {
            printf("[EVALUADOR] Posición lineal %d fuera de rango (0-%d)\n", 
                   posLineal, numElementos-1);
            r.inicializado = 0;
        }
        
        // Liberar memoria
        for (int i = 0; i < numElementos; i++) {
            free(elementos[i]);
        }
        free(datosCopy);
        free(arrayStr);
    }
    
    return r;
}
