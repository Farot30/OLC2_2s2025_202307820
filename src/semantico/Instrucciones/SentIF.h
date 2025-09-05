#ifndef SENTIF_H
#define SENTIF_H

#include "../../AST/ast.h"

typedef struct {
    NodoAST* condicion;
    NodoAST* bloqueVerdadero;
    NodoAST* bloqueFalso;
} SentenciaIf;

SentenciaIf* crearSentenciaIf(NodoAST* condicion, NodoAST* bloqueVerdadero, NodoAST* bloqueFalso);
void liberarSentenciaIf(SentenciaIf* sentencia);

void ejecutarNodoIf(NodoAST* nodo);

#endif