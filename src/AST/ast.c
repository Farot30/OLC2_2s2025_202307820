#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"


NodoAST* crearNodo(TipoNodoAST tipo, char* valor) {
    NodoAST* nodo = (NodoAST*)malloc(sizeof(NodoAST));
    nodo->tipo = tipo;
    nodo->valor = valor ? strdup(valor) : NULL;
    nodo->hijos = NULL;
    nodo->num_hijos = 0;
    return nodo;
}

void agregarHijo(NodoAST* padre, NodoAST* hijo) {
    padre->hijos = (NodoAST**)realloc(padre->hijos, sizeof(NodoAST*) * (padre->num_hijos + 1));
    padre->hijos[padre->num_hijos] = hijo;
    padre->num_hijos++;
}


void liberarAST(NodoAST* nodo) {
    if (!nodo) return;
    for (int i = 0; i < nodo->num_hijos; ++i)
        liberarAST(nodo->hijos[i]);
    free(nodo->hijos);
    if (nodo->valor) free(nodo->valor);
    free(nodo);
}


void imprimirAST(NodoAST* nodo, int nivel) {
    if (!nodo) return;
    for (int i = 0; i < nivel; ++i) printf("  ");
    printf("Tipo: %d", nodo->tipo);
    if (nodo->valor) printf(", Valor: %s", nodo->valor);
    printf("\n");
    for (int i = 0; i < nodo->num_hijos; ++i)
        imprimirAST(nodo->hijos[i], nivel + 1);
}