#include "Evaluador.h"
#include "Operador.h"
#include "../semantico/semantico.h"
#include "../semantico/Vectores/acceso_vector.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Función auxiliar para crear un ValorSimbolo numérico
ValorSimbolo makeNum(TipoDato tipo, double d) {
    ValorSimbolo v;
    memset(&v, 0, sizeof(v));
    v.tipo = tipo;
    v.inicializado = 1;
    switch (tipo) {
        case TIPO_DOUBLE: v.v.d = d; break;
        case TIPO_FLOAT:  v.v.f = (float)d; break;
        case TIPO_INT:    v.v.i = (int)d; break;
        case TIPO_CHAR:   v.v.c = (char)d; break;
        default: break;
    }
    return v;
}

// Función auxiliar para verificar si un tipo es numérico
int esNum(TipoDato t) {
    return t == TIPO_INT || t == TIPO_FLOAT || t == TIPO_DOUBLE || t == TIPO_CHAR;
}

// Función para evaluar expresiones
ValorSimbolo evaluarExpr(NodoAST* e) {
    ValorSimbolo r;
    memset(&r, 0, sizeof(r));
    r.tipo = TIPO_DESCONOCIDO;
    if (!e) return r;

    switch (e->tipo) {
        case AST_NUMERO: {
                if (strchr(e->valor, '.')) {
                    size_t L = strlen(e->valor);
                    if (L > 0 && (e->valor[L - 1] == 'f' || e->valor[L - 1] == 'F')) {
                        r.tipo = TIPO_FLOAT;
                        r.v.f = strtof(e->valor, NULL);
                    } else {
                        r.tipo = TIPO_DOUBLE;
                        r.v.d = strtod(e->valor, NULL);
                    }
                } else {
                    r.tipo = TIPO_INT;
                    r.v.i = atoi(e->valor);
                }
                r.inicializado = 1;
                return r;
            }
        case AST_CADENA: {
            r.tipo = TIPO_STRING;
            r.v.s = e->valor ? strdup(e->valor) : NULL;
            r.inicializado = 1;
            return r;
        }
        case AST_CARACTER: {
            r.tipo = TIPO_CHAR;
            r.v.c = e->valor && *e->valor ? e->valor[0] : '\0';
            r.inicializado = 1;
            return r;
        }
        case AST_BOOLEAN: {
            r.tipo = TIPO_BOOLEAN;
            r.v.b = (e->valor && strcmp(e->valor, "true") == 0);
            r.inicializado = 1;
            return r;
        }
        case AST_IDENTIFICADOR: {
            Simbolo* s = buscarSimbolo(e->valor);
            if (s) {
                if (!s->valor.inicializado) {
                    printf("[EVALUADOR] Variable '%s' no inicializada\n", e->valor);
                    return r;  // Retorna un ValorSimbolo no inicializado
                }
                printf("[EVALUADOR] Variable '%s' encontrada con valor: %d\n", e->valor, s->valor.v.i);
                return getValorSimbolo(s);  // Devuelve el valor actualizado
            }
            printf("[EVALUADOR] Variable '%s' no declarada\n", e->valor);
            return r;
        }
        case AST_OPERACION: {
            printf("[DEBUG EVALUADOR] === EVALUANDO OPERACIÓN ===\n");
            
            // Operador unario '!'
            if (strcmp(e->valor, "!") == 0 && e->num_hijos == 1) {
                ValorSimbolo a = evaluarExpr(e->hijos[0]);
                if (a.tipo == TIPO_BOOLEAN && a.inicializado) {
                    r.tipo = TIPO_BOOLEAN;
                    r.v.b = !a.v.b;
                    r.inicializado = 1;
                    return r;
                }
                printf("[EVALUADOR] Operador '!' solo válido para boolean\n");
                return r;
            }
            if (strcmp(e->valor, "-") == 0 && e->num_hijos == 1) {
                ValorSimbolo a = evaluarExpr(e->hijos[0]);
                if (esNum(a.tipo) && a.inicializado) {
                    r.tipo = a.tipo;
                    switch (a.tipo) {
                        case TIPO_INT:    r.v.i = -a.v.i; break;
                        case TIPO_FLOAT:  r.v.f = -a.v.f; break;
                        case TIPO_DOUBLE: r.v.d = -a.v.d; break;
                        default: break;
                    }
                    r.inicializado = 1;
                    return r;
                }
                if (!esNum(a.tipo)) {
                    printf("[EVALUADOR] Operador '-' no válido para tipo '%d'\n", a.tipo);
                    return r;
                }
                printf("[EVALUADOR] Operador '-' solo válido para números o variable no inicializada\n");
                return r;
            }
            
            // Operadores binarios
            if (e->num_hijos == 2) {
                printf("[DEBUG EVALUADOR] Evaluando operandos...\n");
                
                // Evaluar primer operando
                printf("[DEBUG EVALUADOR] Tipo nodo izq: %d, valor: '%s'\n", 
                    e->hijos[0]->tipo, e->hijos[0]->valor ? e->hijos[0]->valor : "NULL");
                ValorSimbolo a = evaluarExpr(e->hijos[0]);
                
                // Evaluar segundo operando
                printf("[DEBUG EVALUADOR] Tipo nodo der: %d, valor: '%s'\n", 
                    e->hijos[1]->tipo, e->hijos[1]->valor ? e->hijos[1]->valor : "NULL");
                ValorSimbolo b = evaluarExpr(e->hijos[1]);
                
                if (!a.inicializado || !b.inicializado) {
                    printf("[DEBUG EVALUADOR] ERROR: Uno de los operandos no está inicializado\n");
                    return r;
                }
                
                printf("[DEBUG EVALUADOR] Llamando evaluarOperacion()...\n");
                ValorSimbolo resultado = evaluarOperacion(e, a, b);
                printf("[DEBUG EVALUADOR] Resultado de evaluarOperacion(): tipo=%d, valor=%d, inicializado=%d\n", 
                    resultado.tipo, resultado.v.i, resultado.inicializado);
                
                return resultado;
            }
            return r;
        }

        case AST_ACCESO: {
            printf("[DEBUG EVALUADOR] Evaluando acceso a vector/matriz en expresión\n");
            
            // Verificar que el acceso sea válido
            if (!verificarAccesoVector(e)) {
                printf("[ERROR EVALUADOR] Acceso inválido en expresión\n");
                return r;
            }
            
            // Evaluar el acceso y retornar su valor
            ValorSimbolo valorAcceso = evaluarAccesoArrays(e);
            if (valorAcceso.inicializado) {
                printf("[DEBUG EVALUADOR] Acceso evaluado exitosamente en expresión, valor = ");
                switch (valorAcceso.tipo) {
                    case TIPO_INT: printf("%d\n", valorAcceso.v.i); break;
                    case TIPO_FLOAT: printf("%f\n", valorAcceso.v.f); break;
                    case TIPO_DOUBLE: printf("%lf\n", valorAcceso.v.d); break;
                    case TIPO_CHAR: printf("'%c'\n", valorAcceso.v.c); break;
                    case TIPO_BOOLEAN: printf("%s\n", valorAcceso.v.b ? "true" : "false"); break;
                    case TIPO_STRING: printf("\"%s\"\n", valorAcceso.v.s ? valorAcceso.v.s : "null"); break;
                    default: printf("tipo desconocido\n"); break;
                }
                return valorAcceso;
            } else {
                printf("[ERROR EVALUADOR] No se pudo obtener valor de acceso en expresión\n");
            }
            return r;
        }
           
        case AST_CAST: {
            if (e->num_hijos != 1) return r;
            ValorSimbolo orig = evaluarExpr(e->hijos[0]);
            TipoDato destino = obtenerTipoDesdeString(e->valor);
            if (!orig.inicializado) return r;
            if (esNum(destino) && esNum(orig.tipo)) {
                double base = 0;
                switch (orig.tipo) {
                    case TIPO_DOUBLE: base = orig.v.d; break;
                    case TIPO_FLOAT:  base = orig.v.f; break;
                    case TIPO_INT:    base = orig.v.i; break;
                    case TIPO_CHAR:   base = (unsigned char)orig.v.c; break;
                    default: break;
                }
                ValorSimbolo r = makeNum(destino, base);
                r.es_cast = 1; // <--- Marca que es resultado de un cast explícito
                return r;
            }
            if (destino == orig.tipo) return orig;
            return r;
        }
        case AST_STRING: {
            if (strcmp(e->valor, "String.valueOf") == 0 && e->num_hijos == 1) {
                ValorSimbolo arg = evaluarExpr(e->hijos[0]);
                r.tipo = TIPO_STRING;
                r.inicializado = 1;
                char buffer[64];
                switch (arg.tipo) {
                    case TIPO_INT:     snprintf(buffer, sizeof(buffer), "%d", arg.v.i); break;
                    case TIPO_FLOAT:   snprintf(buffer, sizeof(buffer), "%f", arg.v.f); break;
                    case TIPO_DOUBLE:  snprintf(buffer, sizeof(buffer), "%lf", arg.v.d); break;
                    case TIPO_CHAR:    snprintf(buffer, sizeof(buffer), "%c", arg.v.c); break;
                    case TIPO_BOOLEAN: snprintf(buffer, sizeof(buffer), "%s", arg.v.b ? "true" : "false"); break;
                    case TIPO_STRING:  snprintf(buffer, sizeof(buffer), "%s", arg.v.s ? arg.v.s : ""); break;
                    default:           buffer[0] = '\0'; break;
                }
                r.v.s = strdup(buffer);
                return r;
            }
            return r;
        }
        case AST_EQUAL: {
            if (strcmp(e->valor, ".equals") == 0 && e->num_hijos == 2) {
                ValorSimbolo base = evaluarExpr(e->hijos[0]);
                ValorSimbolo arg = evaluarExpr(e->hijos[1]);
                r.tipo = TIPO_BOOLEAN;
                r.inicializado = 1;
                if (base.tipo == TIPO_STRING && arg.tipo == TIPO_STRING) {
                    r.v.b = (base.v.s && arg.v.s) ? strcmp(base.v.s, arg.v.s) == 0 : 0;
                } else {
                    printf("[EVALUADOR] .equals solo válido para strings\n");
                    r.v.b = 0;
                }
                return r;
            }
            return r;
        }

        
        default: return r;
    }
}

ValorSimbolo evaluarAccesoArrays(NodoAST* nodo) {
    ValorSimbolo r;
    memset(&r, 0, sizeof(r));
    r.tipo = TIPO_DESCONOCIDO;
    
    if (!nodo || nodo->tipo != AST_ACCESO || nodo->num_hijos < 2) {
        printf("[EVALUADOR] Nodo de acceso inválido\n");
        return r;
    }

    NodoAST* idNodo = nodo->hijos[0];
    NodoAST* dimensionesNodo = nodo->hijos[1];
    
    if (!idNodo || idNodo->tipo != AST_IDENTIFICADOR) {
        printf("[EVALUADOR] Primer hijo no es un identificador\n");
        return r;
    }
    
    if (!dimensionesNodo || dimensionesNodo->tipo != AST_DIMENSIONES) {
        printf("[EVALUADOR] Segundo hijo no es un nodo de dimensiones\n");
        return r;
    }

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
    
    if (simbolo->valor.v.s) {
        // Verificar formato con mayor flexibilidad
        if (simbolo->valor.v.s[0] == '[' && simbolo->valor.v.s[1] != '[') {
            // NUEVO: Formato especial [2,3,5,7,11] - corchetes simples sin indicar dimensión
            char* valorCopy = strdup(simbolo->valor.v.s);
            
            // Eliminar corchetes
            if (valorCopy[0] == '[') {
                memmove(valorCopy, valorCopy + 1, strlen(valorCopy));
            }
            int len = strlen(valorCopy);
            if (len > 0 && valorCopy[len - 1] == ']') {
                valorCopy[len - 1] = '\0';
            }
            
            // Contar elementos
            int count = 1;
            for (char* p = valorCopy; *p; p++) {
                if (*p == ',') count++;
            }
            
            dimensionesOriginales[0] = count;
            numDimensionesOriginales = 1;
            
            free(valorCopy);
            printf("[EVALUADOR] Vector '%s' con formato [valores], contiene %d elementos\n", 
                idNodo->valor, dimensionesOriginales[0]);
        } else if (simbolo->clase == SIMBOLO_VECTOR) {
            // Formato simple: valores separados por comas
            char* valorCopy = strdup(simbolo->valor.v.s);
            int count = 1; // Al menos un elemento
            
            for (char* p = valorCopy; *p; p++) {
                if (*p == ',') count++;
            }
            
            dimensionesOriginales[0] = count;
            numDimensionesOriginales = 1;
            
            free(valorCopy);
            printf("[EVALUADOR] Vector '%s' con formato simple tiene %d elementos\n", 
                   idNodo->valor, dimensionesOriginales[0]);
        }
    }
    
    // Verificar que tengamos dimensiones
    if (numDimensionesOriginales == 0) {
        printf("[ERROR] No se pudo determinar las dimensiones de '%s'\n", idNodo->valor);
        return r;
    }
    
    // Contar dimensiones de acceso y evaluar índices
    int numDimensionesAcceso = 0;
    int indices[10] = {0}; // Guardar índices evaluados
    
    for (int i = 0; i < dimensionesNodo->num_hijos; i++) {
        NodoAST* dimNodo = dimensionesNodo->hijos[i];
        if (dimNodo->tipo == AST_1DIMENSION) {
            if (dimNodo->num_hijos < 1) {
                printf("[EVALUADOR] Dimensión sin expresión\n");
                return r;
            }
            
            // Evaluar índice
            ValorSimbolo idxVal = evaluarExpr(dimNodo->hijos[0]);
            if (!idxVal.inicializado || idxVal.tipo != TIPO_INT) {
                printf("[EVALUADOR] Índice debe ser entero\n");
                return r;
            }
            
            // Verificar rango
            if (numDimensionesAcceso < numDimensionesOriginales) {
                if (idxVal.v.i < 0 || idxVal.v.i >= dimensionesOriginales[numDimensionesAcceso]) {
                    printf("[EVALUADOR] Índice %d fuera de rango: %d (válido: 0-%d)\n", 
                           numDimensionesAcceso + 1, idxVal.v.i, 
                           dimensionesOriginales[numDimensionesAcceso] - 1);
                    return r;
                }
            } else {
                printf("[EVALUADOR] Acceso con más dimensiones de las que tiene el array\n");
                return r;
            }
            
            // Guardar índice validado
            indices[numDimensionesAcceso++] = idxVal.v.i;
        }
    }
    
    printf("[EVALUADOR] Accediendo a '%s' con %d índices\n", idNodo->valor, numDimensionesAcceso);
    
    // El tipo del resultado será el tipo del elemento del array
    r.tipo = simbolo->tipo;
    r.inicializado = 1;
    
    // Vector unidimensional
    if (simbolo->clase == SIMBOLO_VECTOR) {
        char* valCopy = strdup(simbolo->valor.v.s);
        char* valores = NULL;
        
        // Determinar formato y extraer valores
        if (valCopy[0] == '[' && strstr(valCopy, "][")){
            // Formato con dimensiones: [dim][val1,val2,...]
            char* secondPartStart = strstr(valCopy, "][");
            if (secondPartStart) {
                valores = secondPartStart + 2; // Saltar "]["
                
                // Quitar último corchete si existe
                int len = strlen(valores);
                if (len > 0 && valores[len-1] == ']') {
                    valores[len-1] = '\0';
                }
            } else {
                printf("[EVALUADOR] Formato de vector incorrecto\n");
                free(valCopy);
                return r;
            }
        } else {
            // MODIFICAR: Para formato [2,3,5,7,11] o val1,val2,...
            valores = valCopy;
            
            // Eliminar corchetes si existen
            if (valores[0] == '[') {
                // Hacer una copia antes de modificar
                char* temp = strdup(valores);
                // Quitar corchete inicial
                memmove(temp, temp + 1, strlen(temp));
                // Quitar corchete final si existe
                int len = strlen(temp);
                if (len > 0 && temp[len - 1] == ']') {
                    temp[len - 1] = '\0';
                }
                free(valCopy);
                valCopy = temp;
                valores = valCopy;
            }
        }
        
        
        // Ahora necesitamos una copia independiente para tokenizar sin afectar valores/valCopy
        char* valoresCopy = strdup(valores);
        char* elementos[256]; // Máximo 256 elementos
        int numElementos = 0;
        
        char* token = strtok(valoresCopy, ",");
        while (token && numElementos < 256) {
            elementos[numElementos++] = strdup(token);
            token = strtok(NULL, ",");
        }
        
        // Verificar índice dentro del rango
        if (indices[0] >= 0 && indices[0] < numElementos) {
            // Convertir según el tipo
            switch (simbolo->tipo) {
                case TIPO_INT:
                    r.v.i = atoi(elementos[indices[0]]);
                    break;
                case TIPO_FLOAT:
                    r.v.f = strtof(elementos[indices[0]], NULL);
                    break;
                case TIPO_DOUBLE:
                    r.v.d = strtod(elementos[indices[0]], NULL);
                    break;
                case TIPO_CHAR:
                    r.v.c = elementos[indices[0]][0];
                    break;
                case TIPO_BOOLEAN:
                    r.v.b = (strcmp(elementos[indices[0]], "true") == 0);
                    break;
                case TIPO_STRING:
                    r.v.s = strdup(elementos[indices[0]]);
                    break;
                default:
                    r.inicializado = 0;
                    break;
            }
            printf("[EVALUADOR] Vector '%s[%d]' = '%s'\n", 
                idNodo->valor, indices[0], elementos[indices[0]]);
        } else {
            printf("[EVALUADOR] Índice %d fuera de rango (0-%d)\n", 
                indices[0], numElementos-1);
            r.inicializado = 0;
        }
        
        // Liberar memoria
        for (int i = 0; i < numElementos; i++) {
            free(elementos[i]);
        }
        free(valoresCopy);
        free(valCopy);
    }
    // Matriz bidimensional
    else if (simbolo->clase == SIMBOLO_MATRIZ && numDimensionesAcceso == 2) {
        char* matrixStr = strdup(simbolo->valor.v.s);
        char* dataStart = NULL;
        
        // Extraer datos según formato
        if (matrixStr[0] == '[') {
            // Formato con dimensiones: [filas,columnas][[val1,val2,...],[val1,val2,...],...]
            dataStart = strstr(matrixStr, "][");
            if (dataStart) {
                dataStart += 2; // Saltar "]["
            } else {
                printf("[EVALUADOR] Formato de matriz incorrecto\n");
                free(matrixStr);
                return r;
            }
        } else {
            // Formato simple (improbable para matrices, pero por si acaso)
            dataStart = matrixStr;
        }
        
        // Quitar corchetes externos si existen
        if (dataStart[0] == '[') {
            dataStart++; // Saltar '['
            int len = strlen(dataStart);
            if (len > 0 && dataStart[len-1] == ']') {
                dataStart[len-1] = '\0';
            }
        }
        
        // Separar filas: [val1,val2,...],[val1,val2,...],...]
        char* filasCopy = strdup(dataStart);
        char* filas[50]; // Máximo 50 filas
        int numFilas = 0;
        
        // Extraer filas (más complejo porque cada fila tiene corchetes)
        char* p = filasCopy;
        int nivel = 0;
        char* inicioFila = p;
        
        while (*p) {
            if (*p == '[') nivel++;
            else if (*p == ']') nivel--;
            else if (*p == ',' && nivel == 0) {
                // Fin de una fila
                *p = '\0';
                filas[numFilas++] = strdup(inicioFila);
                inicioFila = p + 1;
            }
            p++;
        }
        
        // Última fila
        if (*inicioFila) {
            filas[numFilas++] = strdup(inicioFila);
        }
        
        // Verificar fila dentro del rango
        if (indices[0] >= 0 && indices[0] < numFilas) {
            // Extraer elementos de la fila seleccionada
            char* filaStr = filas[indices[0]];
            
            // Quitar corchetes de la fila si existen
            if (filaStr[0] == '[') {
                filaStr++; // Saltar '['
                int len = strlen(filaStr);
                if (len > 0 && filaStr[len-1] == ']') {
                    filaStr[len-1] = '\0';
                }
            }
            
            // Separar elementos de la fila
            char* elementosCopy = strdup(filaStr);
            char* elementos[100]; // Máximo 100 columnas
            int numElementos = 0;
            
            char* token = strtok(elementosCopy, ",");
            while (token && numElementos < 100) {
                elementos[numElementos++] = strdup(token);
                token = strtok(NULL, ",");
            }
            
            // Verificar columna dentro del rango
            if (indices[1] >= 0 && indices[1] < numElementos) {
                // Convertir según el tipo
                switch (simbolo->tipo) {
                    case TIPO_INT:
                        r.v.i = atoi(elementos[indices[1]]);
                        break;
                    case TIPO_FLOAT:
                        r.v.f = strtof(elementos[indices[1]], NULL);
                        break;
                    case TIPO_DOUBLE:
                        r.v.d = strtod(elementos[indices[1]], NULL);
                        break;
                    case TIPO_CHAR:
                        r.v.c = elementos[indices[1]][0];
                        break;
                    case TIPO_BOOLEAN:
                        r.v.b = (strcmp(elementos[indices[1]], "true") == 0);
                        break;
                    case TIPO_STRING:
                        r.v.s = strdup(elementos[indices[1]]);
                        break;
                    default:
                        r.inicializado = 0;
                        break;
                }
                printf("[EVALUADOR] Matriz '%s[%d][%d]' = '%s'\n", 
                       idNodo->valor, indices[0], indices[1], elementos[indices[1]]);
            } else {
                printf("[EVALUADOR] Índice de columna %d fuera de rango (0-%d)\n", 
                       indices[1], numElementos-1);
                r.inicializado = 0;
            }
            
            // Liberar memoria de elementos
            for (int i = 0; i < numElementos; i++) {
                free(elementos[i]);
            }
            free(elementosCopy);
        } else {
            printf("[EVALUADOR] Índice de fila %d fuera de rango (0-%d)\n", 
                   indices[0], numFilas-1);
            r.inicializado = 0;
        }
        
        // Liberar memoria de filas
        for (int i = 0; i < numFilas; i++) {
            free(filas[i]);
        }
        free(filasCopy);
        free(matrixStr);
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