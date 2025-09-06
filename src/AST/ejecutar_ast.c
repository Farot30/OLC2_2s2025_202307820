#include "ast.h"
#include "../semantico/tabla_simbolo.h"
#include "../semantico/semantico.h"
#include "../semantico/Instrucciones/asignacion.h"
#include "../semantico/Instrucciones/declaracion.h"
#include "../semantico/Instrucciones/Print.h"
#include "../semantico/Instrucciones/SentIF.h"
#include "../semantico/Instrucciones/Switch.h"
#include "../semantico/Instrucciones/While.h"
#include "../semantico/Instrucciones/break.h"
#include "ejecutar_ast.h"
#include "err.h"

#include <stdio.h>
#include <stdlib.h>

int contexto_break = 0;

// Función para ejecutar cada nodo del AST en orden secuencial
ResultadoEjecucion ejecutarNodoAST(NodoAST* nodo) {
    if (!nodo || !nodo->valido || nodo->tipo == AST_ERROR) {
        printf("[DEBUG] Nodo inválido o de error, saltando\n");
        return EJEC_OK;
    }
    
    printf("[DEBUG] Ejecutando nodo tipo: %d, valor: %s\n", 
           nodo->tipo, nodo->valor ? nodo->valor : "NULL");
    
    switch (nodo->tipo) {
        case AST_LISTA:
        case AST_BLOQUE:
            // Ejecutar todos los hijos secuencialmente
            printf("[DEBUG] Ejecutando %d hijos secuencialmente\n", nodo->num_hijos);
            for (int i = 0; i < nodo->num_hijos; i++) {
                ResultadoEjecucion res = ejecutarNodoAST(nodo->hijos[i]);
                if (res == EJEC_BREAK) return EJEC_BREAK; // Propaga el break
            }
            return EJEC_OK;
            
        case AST_DECLARACION:
            //printf("[DEBUG] Procesando declaración\n");
            // Procesar la declaración
            verificarDeclaracion(nodo);
            return EJEC_OK;
            
        case AST_ASIGNACION:
            printf("[DEBUG] Asignación procesada para variable: %s\n", nodo->hijos[0]->valor);
            // Procesar la asignación
            verificarAsignacion(nodo);
            return EJEC_OK;

        case AST_PRINT:
           // printf("[DEBUG] Procesando print\n");
            // Ejecutar el print
            if (nodo->num_hijos > 0 && nodo->hijos[0]) {
                imprimirEvaluado(nodo->hijos[0]);
            } else {
                printf("[WARNING] Nodo PRINT sin expresión para imprimir\n");
            }
            return EJEC_OK;

        case AST_IF:
            ejecutarNodoIf(nodo);
            return EJEC_OK;
        case AST_SWITCH:
            contexto_break++;
            ResultadoEjecucion res = EjecturarNodoSwitch(nodo);
            contexto_break--;
            return res;
        case AST_WHILE:
            contexto_break++;
            ResultadoEjecucion resWHILE = ejecutarSetenciaWhile(nodo);
            Simbolo* simboloX = buscarSimbolo("x");
            if (simboloX) {
                printf("[DEBUG WHILE] Valor de 'x' después de ejecutar el bloque: %d\n", simboloX->valor.v.i);
            } else {
                printf("[DEBUG WHILE] Variable 'x' no encontrada después de ejecutar el bloque\n");
            }
            contexto_break--;
            return resWHILE;
        case AST_BREAK:
            if (contexto_break == 0) {
                addError("Sentencia BREAK debe estar dentro de un ciclo o switch", ambitoActual(), nodo->linea, nodo->columna);
                return EJEC_OK;
            } else {
                ejecutarSentenciaBreak(nodo);
            }
            return EJEC_BREAK;
        case AST_CONTINUE:
            break;
            
        default:
            printf("[DEBUG] Tipo de nodo %d no manejado específicamente\n", nodo->tipo);
            // Para otros tipos, ejecutar hijos si los hay
            for (int i = 0; i < nodo->num_hijos; i++) {
                ejecutarNodoAST(nodo->hijos[i]);
            }
            break;
    }
    return EJEC_OK;
}

// Función principal para interpretar el programa completo
void interpretarPrograma(NodoAST* raiz) {
    if (!raiz) {
        printf("[ERROR] AST raíz es NULL\n");
        return;
    }
    
    printf("\n[DEBUG] === INICIANDO INTERPRETACIÓN SECUENCIAL ===\n");
    mostrarTablaSimbolos();  // Mostrar estado inicial
    
    // Ejecutar el programa secuencialmente
    ejecutarNodoAST(raiz);
    
    printf("\n[DEBUG] === INTERPRETACIÓN COMPLETADA ===\n");
    mostrarTablaSimbolos();  // Mostrar estado final
}

// Función auxiliar para verificar la estructura del AST antes de ejecutar
void verificarEstructuraAST(NodoAST* nodo, int nivel) {
    if (!nodo) return;
    
    for (int i = 0; i < nivel; i++) printf("  ");
    printf("Nivel %d: Tipo=%d, Valor=%s, Hijos=%d, Válido=%d\n", 
           nivel, nodo->tipo, nodo->valor ? nodo->valor : "NULL", 
           nodo->num_hijos, nodo->valido);
    
    for (int i = 0; i < nodo->num_hijos; i++) {
        verificarEstructuraAST(nodo->hijos[i], nivel + 1);
    }
}