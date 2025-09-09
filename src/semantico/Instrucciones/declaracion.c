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
            // Verificar primero que el acceso sea válido
            if (verificarAccesoVector(valor)) {
                // Obtener el símbolo del vector/matriz accedido
                NodoAST* idVectorNodo = valor->hijos[0];
                Simbolo* simboloVector = buscarSimbolo(idVectorNodo->valor);
                
                if (simboloVector) {
                    // Verificar compatibilidad de tipos entre la variable y el tipo del vector
                    if (sim->tipo != simboloVector->tipo) {
                        char msg[200];
                        snprintf(msg, sizeof(msg), 
                                "Tipo incompatible en declaración '%s': el tipo de la variable (%s) no coincide con el tipo del vector '%s' (%s)",
                                identificador->valor, nombreTipo(sim->tipo), 
                                idVectorNodo->valor, nombreTipo(simboloVector->tipo));
                        addError(msg, ambitoActual(), identificador->linea, identificador->columna);
                        printf("[ERROR] %s\n", msg);
                        nodo->valido = 0;
                        return 0;
                    }
                    
                    printf("[DEBUG] Tipos compatibles: variable '%s' (%s) y vector '%s' (%s)\n",
                           identificador->valor, nombreTipo(sim->tipo),
                           idVectorNodo->valor, nombreTipo(simboloVector->tipo));
                }
                
                // Evaluar el acceso para obtener el valor concreto
                ValorSimbolo valorAcceso = evaluarAccesoArrays(valor);
                if (valorAcceso.inicializado) {
                    // Verificar compatibilidad del valor obtenido
                    if (sim->tipo != valorAcceso.tipo && valorAcceso.tipo != TIPO_DESCONOCIDO) {
                        if (!esWidening(valorAcceso.tipo, sim->tipo)) {
                            char msg[200];
                            snprintf(msg, sizeof(msg), 
                                    "Tipo incompatible en declaración '%s': el valor obtenido (%s) no es compatible con el tipo de la variable (%s)",
                                    identificador->valor, nombreTipo(valorAcceso.tipo), nombreTipo(sim->tipo));
                            addError(msg, ambitoActual(), identificador->linea, identificador->columna);
                            printf("[ERROR] %s\n", msg);
                            nodo->valido = 0;
                            return 0;
                        }
                        
                        printf("[DEBUG] Conversión implícita: de %s a %s\n", 
                               nombreTipo(valorAcceso.tipo), nombreTipo(sim->tipo));
                    }
                    
                    // Asignar el valor obtenido
                    setValorSimbolo(sim, sim->tipo, valorAcceso);
                    printf("[DEBUG] Variable '%s' inicializada con valor de acceso a array\n", 
                           identificador->valor);
                } else {
                    printf("[ERROR] No se pudo obtener un valor válido del acceso para inicializar '%s'\n", 
                           identificador->valor);
                    nodo->valido = 0;
                    return 0;
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
                    
                    printf("[DEBUG] Conversión implícita en asignación: de %s a %s\n", 
                           nombreTipo(v.tipo), nombreTipo(sim->tipo));
                }
                
                setValorSimbolo(sim, sim->tipo, v);
                printf("[DEBUG] Variable '%s' inicializada con valor %d\n", 
                       identificador->valor, v.v.i); // Para valores enteros
            } else {
                printf("[ERROR] Expresión no inicializada para '%s'\n", identificador->valor);
                nodo->valido = 0;
                return 0;
            }
        }
    }
    
    return 1;
}