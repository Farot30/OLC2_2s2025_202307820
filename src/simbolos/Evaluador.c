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



ValorSimbolo evaluarOperaciones(NodoAST* op, ValorSimbolo a, ValorSimbolo b){
    ValorSimbolo r;
    memset(&r, 0, sizeof(r));
    printf("[DEBUG EVALUADOR] === EVALUANDO OPERACIÓN ===\n");
    
    // Operador unario '!'
    if (strcmp(op->valor, "!") == 0 && op->num_hijos == 1) {
        // Usar el parámetro 'a' en lugar de volver a evaluar
        if (a.tipo == TIPO_BOOLEAN && a.inicializado) {
            r.tipo = TIPO_BOOLEAN;
            r.v.b = !a.v.b;
            r.inicializado = 1;
            return r;
        }
        printf("[EVALUADOR] Operador '!' solo válido para boolean\n");
        return r;
    }
    if (strcmp(op->valor, "-") == 0 && op->num_hijos == 1) {
        // Usar el parámetro 'a' en lugar de volver a evaluar
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
    if (op->num_hijos == 2) {
        // Ya no necesitas evaluar los operandos aquí porque los recibiste como parámetros
        if (!a.inicializado || !b.inicializado) {
            printf("[DEBUG EVALUADOR] ERROR: Uno de los operandos no está inicializado\n");
            return r;
        }
        
        printf("[DEBUG EVALUADOR] Llamando evaluarOperacion()...\n");
        ValorSimbolo resultado = evaluarOperacion(op, a, b);
        printf("[DEBUG EVALUADOR] Resultado de evaluarOperacion(): tipo=%d, valor=%d, inicializado=%d\n", 
            resultado.tipo, resultado.v.i, resultado.inicializado);
        
        return resultado;
    }
    return r;
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
        case AST_OPERACION: 
        {
            if (e->num_hijos == 1) {
                ValorSimbolo a = evaluarExpr(e->hijos[0]);
                return evaluarOperaciones(e, a, a);
            } else if (e->num_hijos == 2) {
                ValorSimbolo a = evaluarExpr(e->hijos[0]);
                ValorSimbolo b = evaluarExpr(e->hijos[1]);
                return evaluarOperaciones(e, a, b);
            }
            return r;
        }

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
        case AST_INDEXOF: 
            return evaluarIndexof(e);
        case AST_LENGHT: 
            return evaluarLength(e);
        case AST_ADD:
            return evaluarAdd(e);
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

