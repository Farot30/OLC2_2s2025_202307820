#include "break.h"
#include <stdlib.h>
#include "../../AST/ejecutar_ast.h"
#include "../../AST/err.h"
#include "../tabla_simbolo.h"
#include "../../simbolos/Evaluador.h"

SentenciaBreak* crearSentenciaBreak(NodoAST* nodo) {
    SentenciaBreak* sentencia = (SentenciaBreak*)malloc(sizeof(SentenciaBreak));
    sentencia->nodo = nodo;
    return sentencia;
}

void liberarSentenciaBreak(SentenciaBreak* sentencia) {
    if (!sentencia) return;
    free(sentencia);
}

ResultadoEjecucion ejecutarSentenciaBreak(NodoAST* nodo) {
    if (!nodo || nodo->tipo != AST_BREAK) return EJEC_OK;

    NodoAST* nodoBreak = nodo;

    if(!nodoBreak) {
        addError("Sentencia BREAK inválida", ambitoActual(), nodo->linea, nodo->columna);
        return EJEC_OK;
    }

    return EJEC_BREAK;
}