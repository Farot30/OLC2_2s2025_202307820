#include "semantico.h"
#include "tabla_simbolo.h"
#include "tipos.h"
#include <stdio.h>
#include <string.h>
#include "Instrucciones/declaracion.h"
#include "Instrucciones/asignacion.h"
#include "Expresiones/aritmeticas.h"

int error_semantico = 0;

const char* nombreTipo(TipoDato tipo) {
    switch(tipo) {
        case TIPO_INT: return "int";
        case TIPO_FLOAT: return "float";
        case TIPO_DOUBLE: return "double";
        case TIPO_CHAR: return "char";
        case TIPO_STRING: return "string";
        default: return "desconocido";
    }
}

int verificarSemantica(NodoAST* nodo) {
    if (!nodo) return 1;

    switch (nodo->tipo) {
        case AST_LISTA:
            for (int i = 0; i < nodo->num_hijos; ++i) {
                if (!verificarSemantica(nodo->hijos[i])) return 0;
            }
            return 1;
        case AST_DECLARACION: {
            if (!verificarDeclaracion(nodo)) { error_semantico = 1; return 0; }
            return 1;
        }
        case AST_ASIGNACION: {
            if (!verificarAsignacion(nodo)) { error_semantico = 1; return 0; }
            return 1;
        }
        case AST_OPERACION: {
            if (!verificacionAritmetico(nodo)) { error_semantico = 1; return 0; }
            return 1;
        }
        case AST_IDENTIFICADOR: {
            if (!buscarSimbolo(nodo->valor)) {
                printf("Error: Variable '%s' no declarada.\n", nodo->valor);
                error_semantico = 1;
                return 0;
            }
            return 1;
        }
        default:
            break;
    }

    for (int i = 0; i < nodo->num_hijos; ++i) {
        if (!verificarSemantica(nodo->hijos[i])) return 0;
    }
    return 1;
}