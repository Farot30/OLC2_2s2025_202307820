#include "declaracion.h"
#include "../tipos.h"
#include "../tabla_simbolo.h"
#include "../semantico.h"
#include "../../AST/err.h"
#include "../../AST/errorTIpos.h"
#include "../../simbolos/Evaluador.h" 
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
        char msg[128];
        snprintf(msg, sizeof(msg), "Variable '%s' ya declarada", identificador->valor);
        addError(msg, "global", identificador->linea, identificador->columna);
        addErrorSintactico(ERROR_SEMANTICO_VARIABLE_YA_DECLARADA,
                          msg, identificador->valor, 
                          "Cambiar nombre de variable",
                          identificador->linea, identificador->columna);
        printf("%s\n", msg);
        return 0;
    }

    if (tipoDeclarado != tipoValor && tipoValor != TIPO_DESCONOCIDO) {
        // Permitir widening implícito
        if (!esWidening(tipoValor, tipoDeclarado)) {
            char msg[160];
            snprintf(msg, sizeof(msg), "Tipo incompatible en declaración '%s': %s vs %s",
                     identificador->valor, nombreTipo(tipoDeclarado), nombreTipo(tipoValor));
            addError(msg, "global", identificador->linea, identificador->columna);
            addErrorSintactico(ERROR_SEMANTICO_TIPO_INCOMPATIBLE,
                    msg, identificador->valor, 
                    "Verificar tipos compatibles o hacer cast explícito",
                    identificador->linea, identificador->columna);
            printf("%s\n", msg);
            return 0;
        }
    }

    agregarSimboloDetallado(
        identificador->valor,
        SIMBOLO_VARIABLE,
        tipoDeclarado,
        "global",
        identificador->linea,
        identificador->columna
    );

    Simbolo* sim = buscarSimbolo(identificador->valor);
    if(sim && nodo->num_hijos > 1){
        ValorSimbolo v = evaluarExpr(nodo->hijos[1]);
        if(v.inicializado){
            setValorSimbolo(sim, sim->tipo, v);
        }
    }
    
    return 1;
}