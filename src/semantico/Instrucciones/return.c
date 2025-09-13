#include "return.h"
#include <stdlib.h>
#include "../../AST/ejecutar_ast.h"
#include "../../AST/err.h"
#include "../tabla_simbolo.h"
#include "../../simbolos/Evaluador.h"
#include "../semantico.h"
#include <string.h>

SentenciaReturn* crearSentenciaReturn(NodoAST* nodo) {
    SentenciaReturn* sentencia = (SentenciaReturn*)malloc(sizeof(SentenciaReturn));
    sentencia->nodo = nodo;
    memset(&sentencia->valor, 0, sizeof(ValorSimbolo));
    sentencia->valor.inicializado = 0;
    return sentencia;
}

void liberarSentenciaReturn(SentenciaReturn* sentencia) {
    if (!sentencia) return;
    if (sentencia->valor.tipo == TIPO_STRING && sentencia->valor.v.s) {
        free(sentencia->valor.v.s);
    }
    free(sentencia);
}

ResultadoEjecucion ejecutarSentenciaReturn(NodoAST* nodo) {
    if (!nodo || nodo->tipo != AST_RETURN) return EJEC_OK;

    // Verificar si estamos dentro de una función
    if (contexto_funcion == 0) {
        addError("Sentencia RETURN debe estar dentro de una función", 
                 ambitoActual(), nodo->linea, nodo->columna);
        printf("[ERROR] La instrucción 'return' solo puede aparecer dentro de una función\n");
        return EJEC_OK;
    }

    // Inicializar variables globales de retorno
    hayRetorno = 0;
    memset(&valorRetorno, 0, sizeof(ValorSimbolo));

    // Evaluar la expresión de retorno si existe
    if (nodo->num_hijos > 0) {
        valorRetorno = evaluarExpr(nodo->hijos[0]);
        if (valorRetorno.inicializado) {
            printf("[DEBUG RETURN] Return con valor de tipo %s\n", nombreTipo(valorRetorno.tipo));
            
            // Buscar la función actual en la tabla de símbolos
            Simbolo* funcionActual = buscarSimbolo(ambitoActual());
            if (funcionActual && funcionActual->clase == SIMBOLO_FUNCION) {
                // Verificar compatibilidad de tipos
                TipoDato tipoFuncion = funcionActual->tipo;
                if (valorRetorno.tipo != tipoFuncion && !esWidening(valorRetorno.tipo, tipoFuncion)) {
                    char msg[200];
                    snprintf(msg, sizeof(msg), "Tipo de retorno incompatible: esperado %s, encontrado %s",
                            nombreTipo(tipoFuncion), nombreTipo(valorRetorno.tipo));
                    addError(msg, ambitoActual(), nodo->linea, nodo->columna);
                    printf("[ERROR RETURN] %s\n", msg);
                    
                    // Podemos decidir si continuar o detener la ejecución
                    // En este caso continuamos pero con un error reportado
                }
                // No hacemos la conversión aquí, la dejamos para cuando se capture el valor
            }
            
            hayRetorno = 1;
            
            // Si el valor es un string, necesitamos hacer una copia
            if (valorRetorno.tipo == TIPO_STRING && valorRetorno.v.s) {
                char* copia = strdup(valorRetorno.v.s);
                valorRetorno.v.s = copia;
            }
        } else {
            // Código existente...
        }
    } else {
        // Return sin valor (para funciones void)
        // Verificar que estemos en una función void
        Simbolo* funcionActual = buscarSimbolo(ambitoActual());
        if (funcionActual && funcionActual->clase == SIMBOLO_FUNCION && funcionActual->tipo != TIPO_VOID) {
            char msg[200];
            snprintf(msg, sizeof(msg), "Función con tipo de retorno %s no puede tener un return vacío", 
                     nombreTipo(funcionActual->tipo));
            addError(msg, ambitoActual(), nodo->linea, nodo->columna);
            printf("[ERROR RETURN] %s\n", msg);
        }
        
        printf("[DEBUG RETURN] Return sin valor\n");
        valorRetorno.tipo = TIPO_VOID;
        valorRetorno.inicializado = 1;
        hayRetorno = 1;
    }
    
    return EJEC_RETURN;
}