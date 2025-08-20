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

    printf("[DEBUG] Asignando a '%s': tipo variable=%s, tipo valor=%s\n",
           identificador->valor, sim ? nombreTipo(sim->tipo) : "NO DECLARADA", nombreTipo(tipoValor));

    // ERROR CRÍTICO: Variable no declarada
    if (!sim) {
        char msg[128];
        snprintf(msg, sizeof(msg), "Variable '%s' no declarada. Debe declararse primero con su tipo (ej: int %s;)", 
                identificador->valor, identificador->valor);
        
        // Sistema antiguo
        addError(msg, "global", identificador->linea, identificador->columna);

        printf("%s\n", msg);
        identificador->valido = 0;  // ← AÑADIR ESTA LÍNEA
        nodo->valido = 0;           // ← AÑADIR ESTA LÍNEA
        return 0;
    }

    // Verificar compatibilidad de tipos
    if (sim->tipo != tipoValor && tipoValor != TIPO_DESCONOCIDO) {
        if (!esWidening(tipoValor, sim->tipo)) {
            char msg[160];
            snprintf(msg, sizeof(msg), "Tipo incompatible en asignación '%s': se esperaba %s, se recibió %s",
                     identificador->valor, nombreTipo(sim->tipo), nombreTipo(tipoValor));
            
            // Sistema antiguo
            addError(msg, "global", identificador->linea, identificador->columna);

            printf("%s\n", msg);
            identificador->valido = 0;  // ← AÑADIR ESTA LÍNEA
            nodo->valido = 0;           // ← AÑADIR ESTA LÍNEA
            return 0;
        }
    }
    
    // Asignar valor si todo está correcto
    ValorSimbolo v = evaluarExpr(valor);
    if(v.inicializado){
        setValorSimbolo(sim, sim->tipo, v);
    }
    return 1;
}