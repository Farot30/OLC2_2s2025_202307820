#include "declaracion.h"
#include "../tipos.h"
#include "../tabla_simbolo.h"
#include "../semantico.h"
#include "../../AST/err.h"
#include "../../AST/errorTIpos.h"
#include "../../simbolos/Evaluador.h" 
#include "../Vectores/acceso_vector.h"
#include <stdio.h>

const char* nombreTipo(TipoDato tipo);

int verificarDeclaracion(NodoAST* nodo) {
    if (!nodo || nodo->num_hijos < 2) {
        printf("[ERROR] Estructura de nodo de declaración inválida\n");
        return 0;
    }

    NodoAST* identificador = nodo->hijos[0];
    NodoAST* valor = nodo->hijos[1];
    TipoDato tipoDeclarado = obtenerTipoDesdeString(nodo->valor);

    printf("[DEBUG] Declarando '%s': tipo declarado=%s\n",
           identificador->valor, nombreTipo(tipoDeclarado));

    if (buscarSimbolo(identificador->valor)) {
        char msg[128];
        snprintf(msg, sizeof(msg), "Variable '%s' ya declarada", identificador->valor);
        addError(msg, ambitoActual(), identificador->linea, identificador->columna);
        printf("[ERROR] %s\n", msg);
        identificador->valido = 0;
        nodo->valido = 0;
        return 0;
    }

    agregarSimboloDetallado(
        identificador->valor,
        SIMBOLO_VARIABLE,
        tipoDeclarado,
        ambitoActual(),
        identificador->linea,
        identificador->columna
    );

    Simbolo* sim = buscarSimbolo(identificador->valor);
    
    if (sim && nodo->num_hijos > 1) {
        // Si el valor es un acceso a vector/matriz
        if (valor->tipo == AST_ACCESO) {
            if (verificarAccesoVector(valor)) {
                ValorSimbolo valorAcceso = evaluarAccesoArrays(valor);
                if (valorAcceso.inicializado) {
                    // Verificar compatibilidad de tipos
                    if (sim->tipo != valorAcceso.tipo && valorAcceso.tipo != TIPO_DESCONOCIDO) {
                        if (!esWidening(valorAcceso.tipo, sim->tipo)) {
                            char msg[160];
                            snprintf(msg, sizeof(msg), "Tipo incompatible en declaración '%s': %s vs %s",
                                    identificador->valor, nombreTipo(sim->tipo), nombreTipo(valorAcceso.tipo));
                            addError(msg, ambitoActual(), identificador->linea, identificador->columna);
                            printf("[ERROR] %s\n", msg);
                            valor->valido = 0;
                            nodo->valido = 0;
                            return 0;
                        }
                    }
                    setValorSimbolo(sim, valorAcceso.tipo, valorAcceso);
                    printf("[DEBUG] Variable '%s' inicializada con valor de acceso a array\n", 
                           identificador->valor);
                }
            } else {
                printf("[ERROR] Acceso inválido para inicialización de '%s'\n", identificador->valor);
                nodo->valido = 0;
                return 0;
            }
        } else {
            // Caso normal (expresión)
            ValorSimbolo v = evaluarExpr(valor);
            if(v.inicializado){
                printf("[DEBUG] Valor obtenido del acceso: %d\n", v.v.i); // Para int
                setValorSimbolo(sim, sim->tipo, v);
                printf("[DEBUG] Variable '%s' inicializada con valor %d de acceso a array\n", 
                    identificador->valor, sim->valor.v.i);
                // Compara el tipo declarado con el tipo evaluado
                if (sim->tipo != v.tipo && v.tipo != TIPO_DESCONOCIDO) {
                    if (!esWidening(v.tipo, sim->tipo)) {
                        char msg[160];
                        snprintf(msg, sizeof(msg), "Tipo incompatible en declaración '%s': %s vs %s",
                                identificador->valor, nombreTipo(sim->tipo), nombreTipo(v.tipo));
                        addError(msg, ambitoActual(), identificador->linea, identificador->columna);
                        printf("[ERROR] %s\n", msg);
                        valor->valido = 0;
                        nodo->valido = 0;
                        return 0;
                    }
                }
                setValorSimbolo(sim, sim->tipo, v);
            }
        }
    }
    
    return 1;
}