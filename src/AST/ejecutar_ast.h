#ifndef EJECUTOR_AST_H
#define EJECUTOR_AST_H

#include "ast.h"

// Función principal para interpretar el programa completo
void interpretarPrograma(NodoAST* raiz);

// Función para ejecutar cada nodo del AST en orden secuencial
void ejecutarNodoAST(NodoAST* nodo);

// Función auxiliar para verificar la estructura del AST
void verificarEstructuraAST(NodoAST* nodo, int nivel);

#endif // EJECUTOR_AST_H