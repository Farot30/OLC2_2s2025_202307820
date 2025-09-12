#ifndef FUNCIONVOID_H
#define FUNCIONVOID_H

#include "../../AST/ast.h"
#include "../tabla_simbolo.h"
#include "../../AST/ejecutar_ast.h"

// Función para declarar una función void (registro en tabla de símbolos)
ResultadoEjecucion DeclararFuncionVoid(NodoAST* nodo);

#endif