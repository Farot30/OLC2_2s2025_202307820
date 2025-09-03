#include "asignacion.h"
#include "../tipos.h"
#include "../tabla_simbolo.h"
#include "../semantico.h"
#include <stdio.h>
#include "../../AST/err.h"  
#include "../../AST/errorTIpos.h"
#include "../../simbolos/Evaluador.h"

const char* nombreTipo(TipoDato tipo);

int verificarAsignacion(NodoAST* nodo) {
    NodoAST* identificador = nodo->hijos[0];
    NodoAST* valor = nodo->hijos[1];
    Simbolo* sim = buscarSimbolo(identificador->valor);
    TipoDato tipoValor = deducirTipoExpr(valor);

    if (!sim) {
        char msg[128];
        snprintf(msg, sizeof(msg), "Variable '%s' no declarada", identificador->valor);
        addError(msg, "global", identificador->linea, identificador->columna);
        nodo->valido = 0;
        return 0;
    }

    if (sim->tipo != tipoValor && tipoValor != TIPO_DESCONOCIDO) {
        if (!esWidening(tipoValor, sim->tipo)) {
            char msg[160];
            snprintf(msg, sizeof(msg), "Tipo incompatible en asignación '%s': se esperaba %s, se recibió %s",
                     identificador->valor, nombreTipo(sim->tipo), nombreTipo(tipoValor));
            addError(msg, "global", identificador->linea, identificador->columna);
            nodo->valido = 0;
            return 0;
        }
    }

    // *** AQUÍ ESTÁ LA CORRECCIÓN ***
    // Evaluar la expresión del lado derecho y asignar el valor al símbolo
    ValorSimbolo valorEvaluado = evaluarExpr(valor);
    if (valorEvaluado.inicializado) {
        setValorSimbolo(sim, valorEvaluado.tipo, valorEvaluado);
       // printf("[DEBUG] Asignando a '%s': valor actualizado\n", identificador->valor);
    } else {
        printf("[DEBUG] Error: no se pudo evaluar la expresión para '%s'\n", identificador->valor);
        nodo->valido = 0;
        return 0;
    }

    // Mapear el tipo de valor al tipo de nodo AST
    switch (sim->tipo) {
        case TIPO_INT:
            valor->tipo = AST_NUMERO;
            break;
        case TIPO_FLOAT:
            valor->tipo = AST_NUMERO;
            break;
        case TIPO_STRING:
            valor->tipo = AST_CADENA;
            break;
        case TIPO_DOUBLE:
            valor->tipo = AST_NUMERO;
            break;
        case TIPO_CHAR:
            valor->tipo = AST_CARACTER;
            break;
        case TIPO_BOOLEAN:
            valor->tipo = AST_BOOLEAN;
            break;
        default:
            valor->tipo = AST_ERROR;
            break;
    }

    return 1;
}