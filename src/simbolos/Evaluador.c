#include "Evaluador.h"
#include "Operador.h"
#include "../semantico/semantico.h"
#include "../semantico/Vectores/acceso_vector.h"
#include "../AST/err.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> 
#include <limits.h>
#include <math.h>

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

// Añade esta función auxiliar al principio de Evaluador.c
static char* concat3(const char* s1, const char* s2, const char* s3) {
    size_t len1 = s1 ? strlen(s1) : 0;
    size_t len2 = s2 ? strlen(s2) : 0;
    size_t len3 = s3 ? strlen(s3) : 0;
    
    char* result = (char*)malloc(len1 + len2 + len3 + 1);
    if (!result) return NULL;
    
    if (s1) strcpy(result, s1);
    else result[0] = '\0';
    
    if (s2) strcat(result, s2);
    if (s3) strcat(result, s3);
    
    return result;
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
        // En el switch de evaluarExpr, añade este caso:
        case AST_PARSEINT: {
            if (e->num_hijos < 1) {
                printf("[ERROR] Integer.parseInt requiere un argumento\n");
                break;
            }
            
            ValorSimbolo argVal = evaluarExpr(e->hijos[0]);
            
            if (!argVal.inicializado) {
                printf("[ERROR] Argumento de Integer.parseInt no inicializado\n");
                break;
            }
            
            // Verificar que el argumento sea una cadena
            if (argVal.tipo != TIPO_STRING) {
                printf("[ERROR] Integer.parseInt requiere una cadena como argumento, se recibió %s\n", 
                    nombreTipo(argVal.tipo));
                break;
            }
            
            // Verificar que la cadena contenga un número válido
            char* endptr;
            long val = strtol(argVal.v.s, &endptr, 10);
            
            if (*endptr != '\0') {
                // No se pudo convertir toda la cadena
                char msg[200];
                snprintf(msg, sizeof(msg), "La cadena '%s' no es un número válido para Integer.parseInt", 
                        argVal.v.s);
                addError(msg, ambitoActual(), e->linea, e->columna);
                printf("[ERROR] %s\n", msg);
                break;
            }
            
            // Verificar rango de int en Java (típicamente 32 bits)
            if (val < INT_MIN || val > INT_MAX) {
                char msg[200];
                snprintf(msg, sizeof(msg), "El número '%s' está fuera del rango válido para int", 
                        argVal.v.s);
                addError(msg, ambitoActual(), e->linea, e->columna);
                printf("[ERROR] %s\n", msg);
                break;
            }
            
            // Si llegamos aquí, la conversión fue exitosa
            r = makeNum(TIPO_INT, (double)val);
            r.tipo = TIPO_INT;
            printf("[DEBUG] Integer.parseInt('%s') = %d\n", argVal.v.s, r.v.i);
            
            // Liberar memoria si es necesario
            if (argVal.tipo == TIPO_STRING && argVal.v.s) {
                // Dependiendo de tu implementación, tal vez debas liberar la memoria
                // free(argVal.v.s);
            }
            
            return r;
        }
        case AST_PARSEFLOAT: {
            if (e->num_hijos < 1) {
                printf("[ERROR] Float.parseFloat requiere un argumento\n");
                return r;
            }
            
            ValorSimbolo argVal = evaluarExpr(e->hijos[0]);
            
            if (!argVal.inicializado) {
                printf("[ERROR] Argumento de Float.parseFloat no inicializado\n");
                return r;
            }
            
            // Verificar que el argumento sea una cadena
            if (argVal.tipo != TIPO_STRING) {
                char msg[200];
                snprintf(msg, sizeof(msg), "Float.parseFloat requiere una cadena como argumento, se recibió %s", 
                        nombreTipo(argVal.tipo));
                addError(msg, ambitoActual(), e->linea, e->columna);
                printf("[ERROR] %s\n", msg);
                return r;
            }
            
            // Verificar que la cadena contenga un número válido
            char* endptr;
            float val = strtof(argVal.v.s, &endptr);
            
            if (*endptr != '\0') {
                // No se pudo convertir toda la cadena
                char msg[200];
                snprintf(msg, sizeof(msg), "La cadena '%s' no es un número válido para Float.parseFloat", 
                        argVal.v.s);
                addError(msg, ambitoActual(), e->linea, e->columna);
                printf("[ERROR] %s\n", msg);
                return r;
            }
            
            // Verificar si hay overflow (menos crítico para float que para int)
            if (val == HUGE_VALF) {
                char msg[200];
                snprintf(msg, sizeof(msg), "El número '%s' está fuera del rango válido para float", 
                        argVal.v.s);
                addError(msg, ambitoActual(), e->linea, e->columna);
                printf("[ERROR] %s\n", msg);
                return r;
            }
            
            // Si llegamos aquí, la conversión fue exitosa
            r = makeNum(TIPO_FLOAT, (double)val);
            r.tipo = TIPO_FLOAT;
            printf("[DEBUG] Float.parseFloat('%s') = %f\n", argVal.v.s, r.v.f);
            
            return r;
        }

        case AST_PARSEDOUBLE: {
            if (e->num_hijos < 1) {
                printf("[ERROR] Double.parseDouble requiere un argumento\n");
                return r;
            }
            
            ValorSimbolo argVal = evaluarExpr(e->hijos[0]);
            
            if (!argVal.inicializado) {
                printf("[ERROR] Argumento de Double.parseDouble no inicializado\n");
                return r;
            }
            
            // Verificar que el argumento sea una cadena
            if (argVal.tipo != TIPO_STRING) {
                char msg[200];
                snprintf(msg, sizeof(msg), "Double.parseDouble requiere una cadena como argumento, se recibió %s", 
                        nombreTipo(argVal.tipo));
                addError(msg, ambitoActual(), e->linea, e->columna);
                printf("[ERROR] %s\n", msg);
                return r;
            }
            
            // Verificar que la cadena contenga un número válido
            char* endptr;
            double val = strtod(argVal.v.s, &endptr);
            
            if (*endptr != '\0') {
                // No se pudo convertir toda la cadena
                char msg[200];
                snprintf(msg, sizeof(msg), "La cadena '%s' no es un número válido para Double.parseDouble", 
                        argVal.v.s);
                addError(msg, ambitoActual(), e->linea, e->columna);
                printf("[ERROR] %s\n", msg);
                return r;
            }
            
            // Verificar si hay overflow (menos común en double)
            if (val == HUGE_VAL) {
                char msg[200];
                snprintf(msg, sizeof(msg), "El número '%s' está fuera del rango válido para double", 
                        argVal.v.s);
                addError(msg, ambitoActual(), e->linea, e->columna);
                printf("[ERROR] %s\n", msg);
                return r;
            }
            
            // Si llegamos aquí, la conversión fue exitosa
            r = makeNum(TIPO_DOUBLE, val);
            r.tipo = TIPO_DOUBLE;
            printf("[DEBUG] Double.parseDouble('%s') = %f\n", argVal.v.s, r.v.d);
            
            return r;
        }

        // Añade este caso al switch en la función evaluarExpr:
        case AST_PARSEJOIN: {
            if (e->num_hijos < 2) {
                printf("[ERROR] Strings.join requiere al menos un delimitador y un elemento\n");
                return r;
            }
            
            // Evaluar el delimitador
            ValorSimbolo delimitador = evaluarExpr(e->hijos[0]);
            if (!delimitador.inicializado || delimitador.tipo != TIPO_STRING) {
                printf("[ERROR] El delimitador de Strings.join debe ser una cadena\n");
                return r;
            }
            
            // Obtener el nodo de la lista de expresiones
            NodoAST* lista = e->hijos[1];
            if (lista->tipo != AST_LISTA) {
                printf("[ERROR] Se esperaba una lista de expresiones para Strings.join\n");
                return r;
            }
            
            // Inicializar resultado como cadena vacía
            r.tipo = TIPO_STRING;
            r.inicializado = 1;
            r.v.s = strdup("");
            
            // Unir las expresiones con el delimitador
            for (int i = 0; i < lista->num_hijos; i++) {
                // Evaluar la expresión actual
                ValorSimbolo elem = evaluarExpr(lista->hijos[i]);
                if (!elem.inicializado) {
                    printf("[ERROR] Elemento no inicializado en Strings.join\n");
                    if (r.v.s) free(r.v.s);
                    r.inicializado = 0;
                    return r;
                }
                
                // Convertir el elemento a string si no lo es
                char* elemStr;
                if (elem.tipo == TIPO_STRING && elem.v.s) {
                    elemStr = strdup(elem.v.s);
                } else {
                    // Convertir otros tipos a string
                    char buffer[256];
                    switch (elem.tipo) {
                        case TIPO_INT:
                            snprintf(buffer, sizeof(buffer), "%d", elem.v.i);
                            break;
                        case TIPO_FLOAT:
                            snprintf(buffer, sizeof(buffer), "%f", elem.v.f);
                            break;
                        case TIPO_DOUBLE:
                            snprintf(buffer, sizeof(buffer), "%f", elem.v.d);
                            break;
                        case TIPO_CHAR:
                            snprintf(buffer, sizeof(buffer), "%c", elem.v.c);
                            break;
                        case TIPO_BOOLEAN:
                            snprintf(buffer, sizeof(buffer), "%s", elem.v.b ? "true" : "false");
                            break;
                        default:
                            buffer[0] = '\0'; 
                            break;
                    }
                    elemStr = strdup(buffer);
                }
                
                // Si no es el primer elemento, agregar el delimitador
                if (i > 0 && delimitador.v.s) {
                    char* temp = r.v.s;
                    r.v.s = concat3(temp, delimitador.v.s, elemStr);
                    free(temp);
                } else {
                    // Para el primer elemento, simplemente asignar
                    if (r.v.s) free(r.v.s);
                    r.v.s = elemStr;
                }
            }
            
            printf("[DEBUG] Strings.join resultado: '%s'\n", r.v.s ? r.v.s : "(null)");
            return r;
        }

        case AST_VALUEOF: {
            if (e->num_hijos < 1) {
                printf("[ERROR] String.valueOf requiere un argumento\n");
                return r;
            }
            
            ValorSimbolo argVal = evaluarExpr(e->hijos[0]);
            
            if (!argVal.inicializado) {
                printf("[ERROR] Argumento de String.valueOf no inicializado\n");
                return r;
            }
            
            // Convertir el argumento a cadena según su tipo
            r.tipo = TIPO_STRING;
            r.inicializado = 1;
            char buffer[256];
            switch (argVal.tipo) {
                case TIPO_INT:
                    snprintf(buffer, sizeof(buffer), "%d", argVal.v.i);
                    break;
                case TIPO_FLOAT:
                    snprintf(buffer, sizeof(buffer), "%f", argVal.v.f);
                    break;
                case TIPO_DOUBLE:
                    snprintf(buffer, sizeof(buffer), "%f", argVal.v.d);
                    break;
                case TIPO_CHAR:
                    snprintf(buffer, sizeof(buffer), "%c", argVal.v.c);
                    break;
                case TIPO_BOOLEAN:
                    snprintf(buffer, sizeof(buffer), "%s", argVal.v.b ? "true" : "false");
                    break;
                case TIPO_STRING:
                    r.v.s = strdup(argVal.v.s ? argVal.v.s : "");
                    return r; // Ya está en formato cadena
                default:
                    buffer[0] = '\0'; 
                    break;
            }
            r.v.s = strdup(buffer);
            return r;
        }

        // Añade el siguiente caso al switch en la función evaluarExpr:
        // Reemplaza el caso AST_INDEXOF completo con esta implementación:
        case AST_INDEXOF: {
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
    return r;
}

static void obtenerDimensionesArray(Simbolo* simbolo, int* dimensiones, int* numDimensiones) {
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