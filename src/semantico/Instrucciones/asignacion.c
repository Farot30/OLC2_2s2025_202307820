#include "asignacion.h"
#include "../tipos.h"
#include "../tabla_simbolo.h"
#include "../semantico.h"
#include <stdio.h>

const char* nombreTipo(TipoDato tipo);

int verificarAsignacion(NodoAST* nodo) {
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
    return 1;
}