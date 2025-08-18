#ifndef TIPOS_H
#define TIPOS_H

#include "../AST/ast.h"

typedef enum {
    TIPO_INT,
    TIPO_FLOAT,
    TIPO_DOUBLE,
    TIPO_CHAR,
    TIPO_STRING,
    TIPO_DESCONOCIDO
} TipoDato;

TipoDato obtenerTipoDesdeString(const char* tipostr);
TipoDato deducirTipoExpr(NodoAST* expr); 

#endif