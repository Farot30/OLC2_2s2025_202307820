#include "Evaluador.h"
#include "Operador.h"
#include "../semantico/semantico.h"
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