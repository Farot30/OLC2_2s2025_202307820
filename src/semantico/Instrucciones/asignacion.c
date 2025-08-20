#include "asignacion.h"
#include "../tipos.h"
#include "../tabla_simbolo.h"
#include "../semantico.h"
#include <stdio.h>
#include "../../AST/err.h"  
#include "../../simbolos/Evaluador.h"

const char* nombreTipo(TipoDato tipo);


int verificarAsignacion(NodoAST* nodo) {
    NodoAST* identificador = nodo->hijos[0];
    NodoAST* valor = nodo->hijos[1];
    Simbolo* sim = buscarSimbolo(identificador->valor);
    TipoDato tipoValor = deducirTipoExpr(valor);

    printf("[DEBUG] Asignando a '%s': tipo variable=%s, tipo valor=%s\n",
           identificador->valor, sim ? nombreTipo(sim->tipo) : "no declarada", nombreTipo(tipoValor));

    if (!sim) {
        char msg[128];
        snprintf(msg, sizeof(msg), "Variable '%s' no declarada", identificador->valor);
        addError(msg, "global", identificador->linea, identificador->columna);
        printf("%s\n", msg);
        return 0;
    }

    if (sim->tipo != tipoValor && tipoValor != TIPO_DESCONOCIDO) {
        if (!esWidening(tipoValor, sim->tipo)) {
            char msg[160];
            snprintf(msg, sizeof(msg), "Tipo incompatible en asignación '%s': %s vs %s",
                     identificador->valor, nombreTipo(sim->tipo), nombreTipo(tipoValor));
            addError(msg, "global", identificador->linea, identificador->columna);
            printf("%s\n", msg);
            return 0;
        }
    }
    
    ValorSimbolo v = evaluarExpr(valor);
    if(v.inicializado){
        setValorSimbolo(sim, sim->tipo, v);
    }
    return 1;
}
