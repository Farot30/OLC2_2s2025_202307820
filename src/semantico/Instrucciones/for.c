#include <stdlib.h>
#include "for.h"
#include <string.h>
#include <stdbool.h>
#include "../../AST/ejecutar_ast.h"
#include "../../AST/err.h"
#include "../tipos.h"
#include "../tabla_simbolo.h"
#include "../../simbolos/Evaluador.h"

SentenciaFor* crearSentenciaFor(NodoAST* inicializacion, NodoAST* condicion, NodoAST* actualizacion, NodoAST* bloque) {
    SentenciaFor* sentencia = (SentenciaFor*)malloc(sizeof(SentenciaFor));
    sentencia->inicializacion = inicializacion;
    sentencia->condicion = condicion;
    sentencia->incremento = actualizacion;
    sentencia->bloque = bloque;
    return sentencia;
}

void liberarSentenciaFor(SentenciaFor* sentencia) {
    if(!sentencia) return;
    free(sentencia);
}

ResultadoEjecucion ejecutarSentenciaFor(NodoAST* nodo) {
    if (!nodo || nodo->tipo != AST_FOR) {
        printf("[ERROR FOR] Nodo inválido o no es tipo FOR\n");
        return EJEC_OK;
    }

    // Verificar que tenemos al menos 3 hijos (inicialización, condición, incremento)
    if (nodo->num_hijos < 3) {
        printf("[ERROR FOR] FOR incompleto - esperados al menos 3 hijos, encontrados %d\n", nodo->num_hijos);
        return EJEC_OK;
    }

    NodoAST* inicializacion = nodo->hijos[0];
    NodoAST* condicion = nodo->hijos[1];
    NodoAST* incremento = nodo->hijos[2];
    NodoAST* bloque = (nodo->num_hijos >= 4) ? nodo->hijos[3] : NULL;

    printf("[DEBUG FOR] === INICIANDO BUCLE FOR ===\n");
    printf("[DEBUG FOR] Número de hijos: %d\n", nodo->num_hijos);
    printf("[DEBUG FOR] Inicialización: %s\n", inicializacion ? "presente" : "NULL");
    printf("[DEBUG FOR] Condición: %s\n", condicion ? "presente" : "NULL");
    printf("[DEBUG FOR] Incremento: %s\n", incremento ? "presente" : "NULL");
    printf("[DEBUG FOR] Bloque: %s\n", bloque ? "presente" : "NULL (vacío)");

    // Ejecutar inicialización
    if(inicializacion) {
        printf("[DEBUG FOR] Ejecutando inicialización\n");
        ResultadoEjecucion res_init = ejecutarNodoAST(inicializacion);
        if (res_init != EJEC_OK) {
            printf("[ERROR FOR] Error en inicialización\n");
            return res_init;
        }
    }
    
    while (true) { // Mantener límite de seguridad
        
        // Evaluar condición
        if (condicion) {
            printf("[DEBUG FOR] Evaluando condición\n");
            ValorSimbolo vCond = evaluarExpr(condicion);
            if (!vCond.inicializado) {
                printf("[ERROR FOR] Condición del FOR no está inicializada\n");
                addError("Condición del FOR no está inicializada", ambitoActual(), nodo->linea, nodo->columna);
                break;
            }
            if (vCond.tipo != TIPO_BOOLEAN) {
                printf("[ERROR FOR] Condición del FOR no es booleana (tipo: %d)\n", vCond.tipo);
                addError("Condición del FOR no es booleana", ambitoActual(), nodo->linea, nodo->columna);
                break;
            }
            printf("[DEBUG FOR] Condición evaluada: %s\n", vCond.v.b ? "true" : "false");
            if (!vCond.v.b) {
                printf("[DEBUG FOR] Condición falsa, saliendo del bucle\n");
                break;
            }
        }
    


        // Ejecutar bloque (si existe)
        if (bloque) {
            printf("[DEBUG FOR] Verificando bloque: tipo=%d, válido=%d, hijos=%d\n", 
                   bloque->tipo, bloque->valido, bloque->num_hijos);
            
            // Verificar que el bloque es válido
            if (!bloque->valido || bloque->tipo == AST_ERROR) {
                printf("[WARNING FOR] Bloque inválido o con errores, saltando\n");
            } else {
                // Ejecutar bloque
                entrarAmbito("for");
                printf("[DEBUG FOR] Ejecutando bloque de código\n");
                
                // Si es un bloque vacío, no hacer nada
                if (bloque->num_hijos == 0) {
                    printf("[DEBUG FOR] Bloque vacío\n");
                } else {
                    ResultadoEjecucion res = ejecutarNodoAST(bloque);
                    if (res == EJEC_BREAK) {
                        printf("[DEBUG FOR] Break detectado, saliendo del bucle\n");
                        salirAmbito();
                        break; 
                    } else if (res == EJEC_CONTINUE) {
                        printf("[DEBUG FOR] Continue detectado, continuando con incremento\n");
                        // continuar con el incremento
                    }
                }
                salirAmbito();
            }
        } else {
            printf("[INFO FOR] No hay bloque de código, ejecutando bucle vacío\n");
            // Para testing, puedes agregar aquí alguna acción por defecto
        }

        // Ejecutar incremento
        if(incremento) {
            printf("[DEBUG FOR] Ejecutando incremento: tipo=%d, valor='%s'\n", 
                   incremento->tipo, incremento->valor ? incremento->valor : "NULL");
            
            if (incremento->valido && incremento->tipo != AST_ERROR) {
                ResultadoEjecucion res_inc = ejecutarNodoAST(incremento);
                if (res_inc != EJEC_OK) {
                    printf("[WARNING FOR] Error en incremento, continuando\n");
                }
            } else {
                printf("[WARNING FOR] Nodo incremento inválido\n");
            }
        }
        
        
        // Mostrar estado de la variable después del incremento
        Simbolo* var_i = buscarSimbolo("i");
        if (var_i) {
            printf("[DEBUG FOR] Valor de 'i' después del incremento: %d\n", var_i->valor.v.i);
        }
    }
    
    printf("[DEBUG FOR] === BUCLE FOR COMPLETADO ===\n");
    return EJEC_OK;
}