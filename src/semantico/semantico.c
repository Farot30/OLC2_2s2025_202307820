#include "semantico.h"
#include "tabla_simbolo.h"
#include "tipos.h"
#include <stdio.h>
#include <string.h>

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
            NodoAST* identificador = nodo->hijos[0];
            NodoAST* valor = nodo->hijos[1];
            TipoDato tipoDeclarado = obtenerTipoDesdeString(nodo->valor);
            TipoDato tipoValor = deducirTipoExpr(valor);

            // Depuración
            printf("[DEBUG] Declarando '%s': tipo declarado=%s, tipo valor=%s\n",
                   identificador->valor, nombreTipo(tipoDeclarado), nombreTipo(tipoValor));

            if (buscarSimbolo(identificador->valor)) {
                printf("Error: Variable '%s' ya declarada.\n", identificador->valor);
                error_semantico = 1;
                return 0;
            }
            if (tipoDeclarado != tipoValor && tipoValor != TIPO_DESCONOCIDO) {
                printf("Error: Tipo incompatible en declaración de '%s'. Esperado %s, encontrado %s\n",
                    identificador->valor, nombreTipo(tipoDeclarado), nombreTipo(tipoValor));
                error_semantico = 1;
                return 0;
            }
            agregarSimbolo(identificador->valor, tipoDeclarado);
            break;
        }
        case AST_ASIGNACION: {
            NodoAST* identificador = nodo->hijos[0];
            NodoAST* valor = nodo->hijos[1];
            Simbolo* sim = buscarSimbolo(identificador->valor);
            TipoDato tipoValor = deducirTipoExpr(valor);

            // Depuración
            printf("[DEBUG] Asignando a '%s': tipo variable=%s, tipo valor=%s\n",
                   identificador->valor, sim ? nombreTipo(sim->tipo) : "no declarada", nombreTipo(tipoValor));

            if (!sim) {
                printf("Error: Variable '%s' no declarada.\n", identificador->valor);
                return 0;
            }
            if (sim->tipo != tipoValor && tipoValor != TIPO_DESCONOCIDO) {
                printf("Error: Tipo incompatible en asignación a '%s'. Esperado %s, encontrado %s\n",
                    identificador->valor, nombreTipo(sim->tipo), nombreTipo(tipoValor));
                return 0;
            }
            break;
        }
        case AST_IDENTIFICADOR: {
            if (!buscarSimbolo(nodo->valor)) {
                printf("Error: Variable '%s' no declarada.\n", nodo->valor);
                return 0;
            }
            break;
        }
        default:
            break;
    }

    for (int i = 0; i < nodo->num_hijos; ++i) {
        if (!verificarSemantica(nodo->hijos[i])) return 0;
    }
    return 1;
}