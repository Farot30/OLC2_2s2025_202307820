#ifndef AST_H
#define AST_H

#include <stdio.h>
typedef enum {
    AST_NUMERO,
    AST_IDENTIFICADOR,
    AST_DECLARACION,
    AST_LISTA,
    AST_BLOQUE,
    AST_ASIGNACION,
    AST_CADENA,
    AST_CARACTER,
    AST_OPERACION,

    // Por si se me olvida, aquí es agregar más tipos
} TipoNodoAST;

typedef struct NodoAST {
    TipoNodoAST tipo;
    char* valor; // Para números, identificadores
    struct NodoAST** hijos;
    int num_hijos;
} NodoAST;

// Funciones para crear nodos
NodoAST* crearNodo(TipoNodoAST tipo, char* valor);
void agregarHijo(NodoAST* padre, NodoAST* hijo);
void liberarAST(NodoAST* nodo);
void imprimirAST(NodoAST* nodo, int nivel);
void graphvizAST(NodoAST* nodo);
void graphvizAST_ToFile(NodoAST* nodo, FILE* f);
int exportarAST(NodoAST* nodo, const char* rutaDot, const char* rutaPNG);

#endif