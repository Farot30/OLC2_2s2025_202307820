#include "Evaluador.h"
#include <string.h>
#include <stdio.h>

char* valorToString(ValorSimbolo val) {
    char* result = malloc(64);
    if (!result) return NULL;
    
    switch (val.tipo) {
        case TIPO_INT:
            snprintf(result, 64, "%d", val.v.i);
            break;
        case TIPO_FLOAT:
            snprintf(result, 64, "%.2f", val.v.f);
            break;
        case TIPO_DOUBLE:
            snprintf(result, 64, "%.2lf", val.v.d);
            break;
        case TIPO_CHAR:
            snprintf(result, 64, "%c", val.v.c);
            break;
        case TIPO_BOOLEAN:
            snprintf(result, 64, "%s", val.v.b ? "true" : "false");
            break;
        case TIPO_STRING:
            if (val.v.s) {
                free(result);
                return strdup(val.v.s);
            } else {
                strcpy(result, "");
            }
            break;
        default:
            strcpy(result, "");
            break;
    }
    return result;
}

ValorSimbolo evaluarOperacion(NodoAST* e, ValorSimbolo a, ValorSimbolo b) {
    printf("[DEBUG OPERADOR] === INICIANDO evaluarOperacion ===\n");
    printf("[DEBUG OPERADOR] Operador: '%s'\n", e->valor);
    printf("[DEBUG OPERADOR] Tipo a: %d, Tipo b: %d\n", a.tipo, b.tipo);
    
    ValorSimbolo r;
    memset(&r, 0, sizeof(r));
    r.tipo = TIPO_DESCONOCIDO;

    // Concatenación de cadenas - Mejorada para manejar múltiples tipos
    if (strcmp(e->valor, "+") == 0 && (a.tipo == TIPO_STRING || b.tipo == TIPO_STRING)) {
        printf("[DEBUG OPERADOR] Realizando concatenación de cadenas\n");
        r.tipo = TIPO_STRING;
        
        // Asegurarse de que ambos operandos estén completamente evaluados
        // antes de intentar la concatenación
        char* str_a = valorToString(a);
        char* str_b = valorToString(b);
        
        if (!str_a || !str_b) {
            if (str_a) free(str_a);
            if (str_b) free(str_b);
            printf("[ERROR] Error al convertir valores a string para concatenación\n");
            return r;
        }
        
        size_t len_total = strlen(str_a) + strlen(str_b) + 1;
        r.v.s = malloc(len_total);
        
        if (!r.v.s) {
            free(str_a);
            free(str_b);
            printf("[ERROR] Error al asignar memoria para la concatenación de cadenas\n");
            return r;
        }
        
        strcpy(r.v.s, str_a);
        strcat(r.v.s, str_b);
        
        free(str_a);
        free(str_b);
        
        r.inicializado = 1;
        printf("[DEBUG OPERADOR] Concatenación exitosa: '%s'\n", r.v.s);
        return r;
    }

    // Operadores de bit a bit (solo para int)
    if (strcmp(e->valor, "&") == 0) {
        if (a.tipo == TIPO_INT && b.tipo == TIPO_INT) {
            r.tipo = TIPO_INT;
            r.v.i = a.v.i & b.v.i;
            r.inicializado = 1;
            return r;
        }
        printf("[EVALUADOR] Operador '&' solo válido para int\n");
        return r;
    }
    if (strcmp(e->valor, "|") == 0) {
        if (a.tipo == TIPO_INT && b.tipo == TIPO_INT) {
            r.tipo = TIPO_INT;
            r.v.i = a.v.i | b.v.i;
            r.inicializado = 1;
            return r;
        }
        printf("[EVALUADOR] Operador '|' solo válido para int\n");
        return r;
    }
    if (strcmp(e->valor, "^") == 0) {
        if (a.tipo == TIPO_INT && b.tipo == TIPO_INT) {
            r.tipo = TIPO_INT;
            r.v.i = a.v.i ^ b.v.i;
            r.inicializado = 1;
            return r;
        }
        printf("[EVALUADOR] Operador '^' solo válido para int\n");
        return r;
    }
    if (strcmp(e->valor, "<<") == 0) {
        if (a.tipo == TIPO_INT && b.tipo == TIPO_INT) {
            r.tipo = TIPO_INT;
            r.v.i = a.v.i << b.v.i;
            r.inicializado = 1;
            return r;
        }
        printf("[EVALUADOR] Operador '<<' solo válido para int\n");
        return r;
    }
    if (strcmp(e->valor, ">>") == 0) {
        if (a.tipo == TIPO_INT && b.tipo == TIPO_INT) {
            r.tipo = TIPO_INT;
            r.v.i = a.v.i >> b.v.i;
            r.inicializado = 1;
            return r;
        }
        printf("[EVALUADOR] Operador '>>' solo válido para int\n");
        return r;
    }

    // Comparadores: solo para int
    if (strcmp(e->valor, "==") == 0) {
        if (a.tipo == TIPO_INT && b.tipo == TIPO_INT) {
            r.tipo = TIPO_BOOLEAN;
            r.v.b = (a.v.i == b.v.i);
            r.inicializado = 1;
            return r;
        }
        printf("[EVALUADOR] Comparación '==' solo válida para int\n");
        return r;
    }
    if (strcmp(e->valor, "!=") == 0) {
        if (a.tipo == TIPO_INT && b.tipo == TIPO_INT) {
            r.tipo = TIPO_BOOLEAN;
            r.v.b = (a.v.i != b.v.i);
            r.inicializado = 1;
            return r;
        }
        printf("[EVALUADOR] Comparación '!=' solo válida para int\n");
        return r;
    }
    if (strcmp(e->valor, "<") == 0) {
        if (a.tipo == TIPO_INT && b.tipo == TIPO_INT) {
            r.tipo = TIPO_BOOLEAN;
            r.v.b = (a.v.i < b.v.i);
            r.inicializado = 1;
            return r;
        }
        printf("[EVALUADOR] Comparación '<' solo válida para int\n");
        return r;
    }
    if (strcmp(e->valor, ">") == 0) {
        if (a.tipo == TIPO_INT && b.tipo == TIPO_INT) {
            r.tipo = TIPO_BOOLEAN;
            r.v.b = (a.v.i > b.v.i);
            r.inicializado = 1;
            return r;
        }
        printf("[EVALUADOR] Comparación '>' solo válida para int\n");
        return r;
    }
    if (strcmp(e->valor, "<=") == 0) {
        if (a.tipo == TIPO_INT && b.tipo == TIPO_INT) {
            r.tipo = TIPO_BOOLEAN;
            r.v.b = (a.v.i <= b.v.i);
            r.inicializado = 1;
            return r;
        }
        printf("[EVALUADOR] Comparación '<=' solo válida para int\n");
        return r;
    }
    if (strcmp(e->valor, ">=") == 0) {
        if (a.tipo == TIPO_INT && b.tipo == TIPO_INT) {
            r.tipo = TIPO_BOOLEAN;
            r.v.b = (a.v.i >= b.v.i);
            r.inicializado = 1;
            return r;
        }
        printf("[EVALUADOR] Comparación '>=' solo válida para int\n");
        return r;
    }
    if (strcmp(e->valor, "&&") == 0) {
        if (a.tipo == TIPO_BOOLEAN && b.tipo == TIPO_BOOLEAN) {
            r.tipo = TIPO_BOOLEAN;
            r.v.b = a.v.b && b.v.b;
            r.inicializado = 1;
            return r;
        }
        printf("[EVALUADOR] Operador '&&' solo válido para boolean\n");
        return r;
    }
    if (strcmp(e->valor, "||") == 0) {
        if (a.tipo == TIPO_BOOLEAN && b.tipo == TIPO_BOOLEAN) {
            r.tipo = TIPO_BOOLEAN;
            r.v.b = a.v.b || b.v.b;
            r.inicializado = 1;
            return r;
        }
        printf("[EVALUADOR] Operador '||' solo válido para boolean\n");
        return r;
    }

    // Operaciones aritméticas
    if (!esNum(a.tipo) || !esNum(b.tipo)) {
        printf("[EVALUADOR] Operación '%s' con operandos no numéricos\n", e->valor);
        return r;
    }

    double da = (a.tipo == TIPO_DOUBLE) ? a.v.d : (a.tipo == TIPO_FLOAT ? a.v.f : (a.tipo == TIPO_INT ? a.v.i : (unsigned char)a.v.c));
    double db = (b.tipo == TIPO_DOUBLE) ? b.v.d : (b.tipo == TIPO_FLOAT ? b.v.f : (b.tipo == TIPO_INT ? b.v.i : (unsigned char)b.v.c));
    
    double res = 0;
    const char* op = e->valor;
    if (strcmp(op, "+") == 0) {
        res = da + db;
        printf("[DEBUG OPERADOR] Suma: %f + %f = %f\n", da, db, res);
    }
    else if (strcmp(op, "-") == 0) {
        res = da - db;
        printf("[DEBUG OPERADOR] Resta: %f - %f = %f\n", da, db, res);
    }
    else if (strcmp(op, "*") == 0) {
        res = da * db;
        printf("[DEBUG OPERADOR] Multiplicación: %f * %f = %f\n", da, db, res);
    }
    else if (strcmp(op, "/") == 0) {
        res = db != 0 ? da / db : 0;
        printf("[DEBUG OPERADOR] División: %f / %f = %f\n", da, db, res);
    }
    else if (strcmp(op, "%") == 0) {
        long ia = (long)da;
        long ib = (long)db;
        res = (ib != 0) ? ia % ib : 0;
        printf("[DEBUG OPERADOR] Módulo: %ld %% %ld = %f\n", ia, ib, res);
    }

    TipoDato tr = TIPO_INT;
    if (a.tipo == TIPO_DOUBLE || b.tipo == TIPO_DOUBLE) tr = TIPO_DOUBLE;
    else if (a.tipo == TIPO_FLOAT || b.tipo == TIPO_FLOAT) tr = TIPO_FLOAT;
    else if (a.tipo == TIPO_INT || b.tipo == TIPO_INT) tr = TIPO_INT;
    else tr = TIPO_INT;

    r = makeNum(tr, res);
    
    return r;
}

