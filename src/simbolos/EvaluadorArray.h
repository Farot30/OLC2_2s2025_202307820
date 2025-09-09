#ifndef EVALUADOR_ARRAY_H
#define EVALUADOR_ARRAY_H

#include "../AST/ast.h"
#include "../semantico/tipos.h"
#include "../semantico/tabla_simbolo.h"

// Función para evaluar Arrays.indexOf
ValorSimbolo evaluarIndexof(NodoAST* e);

// Función para evaluar Array.length
ValorSimbolo evaluarLength(NodoAST* e);

// Función para evaluar Array.add
ValorSimbolo evaluarAdd(NodoAST* e);

// Función para evaluar acceso a arrays (arr[i], arr[i][j], etc.)
ValorSimbolo evaluarAccesoArrays(NodoAST* nodo);

// Función para obtener dimensiones de un array
void obtenerDimensionesArray(Simbolo* simbolo, int* dimensiones, int* numDimensiones);

#endif // EVALUADOR_ARRAY_H