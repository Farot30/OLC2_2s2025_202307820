#ifndef EJECUTOR_AST_H
#define EJECUTOR_AST_H

#include "ast.h"

typedef enum {
    EJEC_OK,
    EJEC_BREAK,
    EJEC_CONTINUE,
    EJEC_RETURN,
} ResultadoEjecucion;

extern int contexto_break;
extern int contexto_continue;
// Función principal para interpretar el programa completo
void interpretarPrograma(NodoAST* raiz);

// Función para ejecutar cada nodo del AST en orden secuencial
ResultadoEjecucion ejecutarNodoAST(NodoAST* nodo);

// Función auxiliar para verificar la estructura del AST
void verificarEstructuraAST(NodoAST* nodo, int nivel);

#endif