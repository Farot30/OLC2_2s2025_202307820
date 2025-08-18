#ifndef SEMANTICO_H
#define SEMANTICO_H

#include "../AST/ast.h"

extern int error_semantico;
// Función principal de análisis semántico
int verificarSemantica(NodoAST* raiz);

#endif