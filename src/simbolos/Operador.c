#include "Evaluador.h"
#include <string.h>
#include <stdio.h>

ValorSimbolo evaluarOperacion(NodoAST* e, ValorSimbolo a, ValorSimbolo b) {
    printf("[DEBUG OPERADOR] === INICIANDO evaluarOperacion ===\n");
    printf("[DEBUG OPERADOR] Operador: '%s'\n", e->valor ? e->valor : "NULL");
    printf("[DEBUG OPERADOR] Operando A: tipo=%d, valor=%d, inicializado=%d\n", a.tipo, a.v.i, a.inicializado);
    printf("[DEBUG OPERADOR] Operando B: tipo=%d, valor=%d, inicializado=%d\n", b.tipo, b.v.i, b.inicializado);
    ValorSimbolo r;
    memset(&r, 0, sizeof(r));
    r.tipo = TIPO_DESCONOCIDO;

    // Concatenación de cadenas
    if (strcmp(e->valor, "+") == 0 && (a.tipo == TIPO_STRING || b.tipo == TIPO_STRING)) {
        r.tipo = TIPO_STRING;
        size_t len_a = a.tipo == TIPO_STRING && a.v.s ? strlen(a.v.s) : 32;
        size_t len_b = b.tipo == TIPO_STRING && b.v.s ? strlen(b.v.s) : 32;
        r.v.s = malloc(len_a + len_b + 2);
        r.v.s[0] = 0;
        if (a.tipo == TIPO_STRING && a.v.s) strcat(r.v.s, a.v.s);   
        else {
            char tmp[32];
            snprintf(tmp, sizeof(tmp), "%d", a.v.i);
            strcat(r.v.s, tmp);
        }
        if (b.tipo == TIPO_STRING && b.v.s) strcat(r.v.s, b.v.s);
        else {
            char tmp[32];
            snprintf(tmp, sizeof(tmp), "%d", b.v.i);
            strcat(r.v.s, tmp);
        }
        r.inicializado = 1;
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

    printf("[DEBUG OPERADOR] Ambos operandos son numéricos, procediendo...\n");
    double da = (a.tipo == TIPO_DOUBLE) ? a.v.d : (a.tipo == TIPO_FLOAT ? a.v.f : (a.tipo == TIPO_INT ? a.v.i : (unsigned char)a.v.c));
    double db = (b.tipo == TIPO_DOUBLE) ? b.v.d : (b.tipo == TIPO_FLOAT ? b.v.f : (b.tipo == TIPO_INT ? b.v.i : (unsigned char)b.v.c));
    
    printf("[DEBUG OPERADOR] Valores convertidos a double: da=%f, db=%f\n", da, db);
    
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
    
    printf("[DEBUG OPERADOR] Resultado calculado: %f\n", res);
    
    TipoDato tr = TIPO_INT;
    if (a.tipo == TIPO_DOUBLE || b.tipo == TIPO_DOUBLE) tr = TIPO_DOUBLE;
    else if (a.tipo == TIPO_FLOAT || b.tipo == TIPO_FLOAT) tr = TIPO_FLOAT;
    else if (a.tipo == TIPO_INT || b.tipo == TIPO_INT) tr = TIPO_INT;
    else tr = TIPO_INT;
    
    printf("[DEBUG OPERADOR] Tipo resultado determinado: %d\n", tr);
    
    r = makeNum(tr, res);
    
    printf("[DEBUG OPERADOR] ValorSimbolo creado: tipo=%d, valor=%d, inicializado=%d\n", r.tipo, r.v.i, r.inicializado);
    printf("[DEBUG OPERADOR] === FIN evaluarOperacion ===\n");
    
    return r;
}