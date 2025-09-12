#ifndef EVALUADOR_STRING_H
#define EVALUDARO_STRING_H

#include "../AST/ast.h"
#include "../semantico/tipos.h"
#include "../semantico/tabla_simbolo.h"

ValorSimbolo evaluarParseJoin(NodoAST* e);
ValorSimbolo evaluarValueOf(NodoAST* e);
ValorSimbolo evaluarEqual(NodoAST* e);

#endif