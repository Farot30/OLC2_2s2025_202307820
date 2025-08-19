#include "declaracion.h"
#include "../tipos.h"
#include "../tabla_simbolo.h"
#include "../semantico.h"
#include <stdio.h>

const char* nombreTipo(TipoDato tipo);

int verificarDeclaracion(NodoAST* nodo) {
    NodoAST* identificador = nodo->hijos[0];
    NodoAST* valor = nodo->hijos[1];
    TipoDato tipoDeclarado = obtenerTipoDesdeString(nodo->valor);
    TipoDato tipoValor = deducirTipoExpr(valor);

    printf("[DEBUG] Declarando '%s': tipo declarado=%s, tipo valor=%s\n",
           identificador->valor, nombreTipo(tipoDeclarado), nombreTipo(tipoValor));

    if (buscarSimbolo(identificador->valor)) {
        printf("Error: Variable '%s' ya declarada.\n", identificador->valor);
        return 0;
    }
    if (tipoDeclarado != tipoValor && tipoValor != TIPO_DESCONOCIDO) {
        printf("Error: Tipo incompatible en declaración de '%s'. Esperado %s, encontrado %s\n",
            identificador->valor, nombreTipo(tipoDeclarado), nombreTipo(tipoValor));
        return 0;
    }
    agregarSimbolo(identificador->valor, tipoDeclarado);
    return 1;
}