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

    printf("[DEBUG AST] === VERIFICANDO ASIGNACIÓN ===\n");
    printf("[DEBUG AST] Nodo principal: tipo=%d, valor='%s', hijos=%d\n", 
           nodo->tipo, nodo->valor ? nodo->valor : "NULL", nodo->num_hijos);
    
    if (nodo->num_hijos >= 2) {
        NodoAST* identificador = nodo->hijos[0];
        NodoAST* valor = nodo->hijos[1];
        
        printf("[DEBUG AST] Identificador: tipo=%d, valor='%s'\n", 
               identificador->tipo, identificador->valor ? identificador->valor : "NULL");
        printf("[DEBUG AST] Expresión valor: tipo=%d, valor='%s', hijos=%d\n", 
               valor->tipo, valor->valor ? valor->valor : "NULL", valor->num_hijos);
        
        // Si la expresión tiene hijos, mostrarlos
        if (valor->num_hijos > 0) {
            printf("[DEBUG AST] Hijos de la expresión:\n");
            for (int i = 0; i < valor->num_hijos; i++) {
                if (valor->hijos[i]) {
                    printf("[DEBUG AST]   Hijo %d: tipo=%d, valor='%s'\n", 
                           i, valor->hijos[i]->tipo, 
                           valor->hijos[i]->valor ? valor->hijos[i]->valor : "NULL");
                }
            }
        }
        
        // Verificar si es una operación
        if (valor->tipo == AST_OPERACION) {
            printf("[DEBUG AST] ¡ES UNA OPERACIÓN! Operador: '%s'\n", valor->valor);
        } else {
            printf("[DEBUG AST] ¡NO ES UNA OPERACIÓN! Tipo: %d\n", valor->tipo);
        }
    }
    NodoAST* identificador = nodo->hijos[0];
    NodoAST* valor = nodo->hijos[1];
    Simbolo* sim = buscarSimbolo(identificador->valor);
    TipoDato tipoValor = deducirTipoExpr(valor);

    if (!sim) {
        char msg[128];
        snprintf(msg, sizeof(msg), "Variable '%s' no declarada", identificador->valor);
        addError(msg, ambitoActual(), identificador->linea, identificador->columna);
        nodo->valido = 0;
        return 0;
    }

    if (sim->tipo != tipoValor && tipoValor != TIPO_DESCONOCIDO) {
        if (!esWidening(tipoValor, sim->tipo)) {
            char msg[160];
            snprintf(msg, sizeof(msg), "Tipo incompatible en asignación '%s': se esperaba %s, se recibió %s",
                     identificador->valor, nombreTipo(sim->tipo), nombreTipo(tipoValor));
            addError(msg, ambitoActual(), identificador->linea, identificador->columna);
            nodo->valido = 0;
            return 0;
        }
    }

    printf("[DEBUG] Variable '%s' antes de asignar: tipo=%d, valor=%d\n", 
           identificador->valor, sim->valor.tipo, sim->valor.v.i);

    // Evaluar la expresión del lado derecho y asignar el valor al símbolo
    ValorSimbolo valorEvaluado = evaluarExpr(valor);
    if (valorEvaluado.inicializado) {
        printf("[DEBUG] Valor evaluado para '%s': tipo=%d, valor=%d\n", 
           identificador->valor, valorEvaluado.tipo, valorEvaluado.v.i);
        setValorSimbolo(sim, valorEvaluado.tipo, valorEvaluado);
        
    } else {
        printf("[DEBUG] Error: no se pudo evaluar la expresión para '%s'\n", identificador->valor);
        nodo->valido = 0;
        return 0;
    }

    printf("[DEBUG] Variable '%s' después de asignar: tipo=%d, valor=%d\n", 
           identificador->valor, sim->valor.tipo, sim->valor.v.i);


    return 1;
}