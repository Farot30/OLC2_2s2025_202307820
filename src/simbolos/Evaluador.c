#include "Evaluador.h"
#include "Operador.h"
#include "EvaluadorArray.h"
#include "EvaluadoresArrays.h"
#include "evaluarString.h"
#include "EvaluadorNumerico.h"
#include "../semantico/semantico.h"
#include "../semantico/Vectores/acceso_vector.h"
#include "../semantico/Vectores/acceso_matriz.h"
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

// Función auxiliar para imprimir valores en modo depuración
static void imprimirValor(ValorSimbolo valor) {
    switch (valor.tipo) {
        case TIPO_INT: 
            printf("%d\n", valor.v.i); 
            break;
        case TIPO_FLOAT: 
            printf("%f\n", valor.v.f); 
            break;
        case TIPO_DOUBLE: 
            printf("%lf\n", valor.v.d); 
            break;
        case TIPO_CHAR: 
            printf("'%c'\n", valor.v.c); 
            break;
        case TIPO_BOOLEAN: 
            printf("%s\n", valor.v.b ? "true" : "false"); 
            break;
        case TIPO_STRING: 
            printf("\"%s\"\n", valor.v.s ? valor.v.s : "null"); 
            break;
        default: 
            printf("tipo desconocido\n"); 
            break;
    }
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

        case AST_PARSEINT: 
            return evaluarParseInt(e);
        case AST_PARSEFLOAT:
            return evaluarParseFloat(e);

        case AST_PARSEDOUBLE:
            return evaluarParseDouble(e);

        // Añade este caso al switch en la función evaluarExpr:
        case AST_PARSEJOIN:    
            return evaluarParseJoin(e);
        case AST_VALUEOF: 
            return evaluarValueOf(e);
        case AST_INDEXOF: 
            return evaluarIndexof(e);
        case AST_LENGHT: 
            return evaluarLength(e);
        case AST_ADD:
            return evaluarAdd(e);
        case AST_ACCESO: {
            printf("[DEBUG EVALUADOR] Evaluando acceso a vector/matriz en expresión\n");
            
            // Obtener el identificador para determinar si es vector o matriz
            if (e->num_hijos < 1 || e->hijos[0]->tipo != AST_IDENTIFICADOR) {
                printf("[ERROR EVALUADOR] Estructura de acceso inválida\n");
                return r;
            }
            
            NodoAST* idNodo = e->hijos[0];
            Simbolo* simbolo = buscarSimbolo(idNodo->valor);
            
            if (!simbolo) {
                printf("[ERROR EVALUADOR] Variable '%s' no declarada\n", idNodo->valor);
                return r;
            }
            
            // Dirigir a la función específica según el tipo de estructura
            // y verificar los índices para determinar si estamos accediendo a matriz o vector
            if (simbolo->clase == SIMBOLO_MATRIZ) {
                // Verificar que el acceso a matriz sea válido
                if (!verificarAccesoMatriz(e)) {
                    printf("[ERROR EVALUADOR] Acceso inválido a matriz '%s'\n", idNodo->valor);
                    return r;
                }
                
                // Evaluar acceso a matriz
                ValorSimbolo valorMatriz = evaluarAccesoMatriz(e);
                if (valorMatriz.inicializado) {
                    printf("[DEBUG EVALUADOR] Acceso a matriz evaluado exitosamente, valor = ");
                    imprimirValor(valorMatriz);
                    return valorMatriz;
                }
            } 
            else if (simbolo->clase == SIMBOLO_VECTOR) {
                // Verificar que el acceso a vector sea válido
                if (!verificarAccesoVector(e)) {
                    printf("[ERROR EVALUADOR] Acceso inválido a vector '%s'\n", idNodo->valor);
                    return r;
                }
                
                // Evaluar acceso a vector
                ValorSimbolo valorVector = evaluarAccesoVector(e);
                if (valorVector.inicializado) {
                    printf("[DEBUG EVALUADOR] Acceso a vector evaluado exitosamente, valor = ");
                    imprimirValor(valorVector);
                    return valorVector;
                }
            }
            else {
                printf("[ERROR EVALUADOR] Variable '%s' no es un vector ni matriz (clase: %d)\n", 
                    idNodo->valor, simbolo->clase);
            }
            
            printf("[ERROR EVALUADOR] No se pudo obtener valor del acceso\n");
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
        case AST_EQUAL: 
            return evaluarEqual(e);
        
        default: return r;
    }
    return r;
}

