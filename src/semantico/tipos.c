#include "tipos.h"
#include "tabla_simbolo.h"
#include "semantico.h"
#include <string.h>
#include <stdlib.h>

TipoDato obtenerTipoDesdeString(const char* tipoStr) {
    if (strcmp(tipoStr, "int") == 0) return TIPO_INT;
    if (strcmp(tipoStr, "float") == 0) return TIPO_FLOAT;
    if (strcmp(tipoStr, "double") == 0) return TIPO_DOUBLE;
    if (strcmp(tipoStr, "char") == 0) return TIPO_CHAR;
    if (strcmp(tipoStr, "string") == 0) return TIPO_STRING;
    return TIPO_DESCONOCIDO;
}

TipoDato deducirTipoExpr(NodoAST* expr) {
    if (!expr) return TIPO_DESCONOCIDO;

    switch (expr->tipo) {
        case AST_NUMERO:
            if (strchr(expr->valor, '.')) {
                size_t len = strlen(expr->valor);
                if (len > 0 && (expr->valor[len-1] == 'f' || expr->valor[len-1] == 'F'))
                    return TIPO_FLOAT;
                return TIPO_DOUBLE;
            }
            
            return TIPO_INT;
        case AST_CADENA:
            return TIPO_STRING;
        case AST_CARACTER:
            return TIPO_CHAR;
        case AST_IDENTIFICADOR: {
            Simbolo* sim = buscarSimbolo(expr->valor);
            if (sim) return sim->tipo;
            return TIPO_DESCONOCIDO;
        }
        default:
            return TIPO_DESCONOCIDO;
    }
}
