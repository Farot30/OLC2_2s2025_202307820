#ifndef EVALUADOR_H
#define EVALUADOR_H
#include "../AST/ast.h"
#include "../semantico/tipos.h"          
#include "../semantico/tabla_simbolo.h"

ValorSimbolo evaluarExpr(NodoAST* expr);

#endif