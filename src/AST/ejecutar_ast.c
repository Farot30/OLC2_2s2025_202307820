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
#include "../semantico/Instrucciones/continue.h"
#include "../semantico/Instrucciones/for.h"

#include "ejecutar_ast.h"
#include "err.h"

#include <stdio.h>
#include <stdlib.h>

int contexto_break = 0;
int contexto_continue = 0;

// Función para ejecutar cada nodo del AST en orden secuencial
ResultadoEjecucion ejecutarNodoAST(NodoAST* nodo) {
    // Verificación más robusta de nodos
    if (!nodo) {
        printf("[DEBUG] Nodo es NULL, saltando\n");
        return EJEC_OK;
    }
    
    if (!nodo->valido || nodo->tipo == AST_ERROR) {
        printf("[DEBUG] Nodo inválido o de error (tipo: %d, válido: %d), saltando\n", 
               nodo->tipo, nodo->valido);
        return EJEC_OK;
    }

    printf("[DEBUG] Ejecutando nodo tipo: %d, valor: %s\n", 
           nodo->tipo, nodo->valor ? nodo->valor : "NULL");
    
    switch (nodo->tipo) {
        case AST_LISTA:
        case AST_BLOQUE:
            printf("[DEBUG BLOQUE] Procesando bloque con %d hijos\n", nodo->num_hijos);
            for (int i = 0; i < nodo->num_hijos; i++) {
                if (nodo->hijos[i] == NULL) {
                    printf("[WARNING BLOQUE] Hijo %d es NULL, saltando\n", i);
                    continue;
                }
                printf("[DEBUG BLOQUE] Ejecutando hijo %d (tipo: %d)\n", i, nodo->hijos[i]->tipo);
                ResultadoEjecucion res = ejecutarNodoAST(nodo->hijos[i]);
                if (res == EJEC_BREAK) {
                    printf("[DEBUG BLOQUE] Propagando BREAK desde hijo %d\n", i);
                    return EJEC_BREAK;
                }
                if (res == EJEC_CONTINUE) {
                    printf("[DEBUG BLOQUE] Propagando CONTINUE desde hijo %d\n", i);
                    return EJEC_CONTINUE;
                }
            }
            return EJEC_OK;
            
        case AST_DECLARACION:
            printf("[DEBUG] Procesando declaración\n");
            verificarDeclaracion(nodo);
            return EJEC_OK;
            
        case AST_ASIGNACION:
            if (nodo->num_hijos > 0 && nodo->hijos[0] && nodo->hijos[0]->valor) {
                printf("[DEBUG] Asignación procesada para variable: %s\n", nodo->hijos[0]->valor);
            } else {
                printf("[DEBUG] Asignación con datos incompletos\n");
            }
            verificarAsignacion(nodo);
            return EJEC_OK;

        case AST_PRINT:
            printf("[DEBUG] Procesando print\n");
            if (nodo->num_hijos > 0 && nodo->hijos[0]) {
                imprimirEvaluado(nodo->hijos[0]);
            } else {
                printf("[WARNING] Nodo PRINT sin expresión para imprimir\n");
            }
            return EJEC_OK;

        case AST_INCREMENTO: // Tipo 25
        case AST_DECREMENTO: // Si tienes decrementos
            printf("[DEBUG] Procesando incremento/decremento\n");
            if (nodo->num_hijos > 0 && nodo->hijos[0] && nodo->hijos[0]->valor) {
                // Obtener la variable a incrementar
                const char* nombreVar = nodo->hijos[0]->valor;
                Simbolo* simbolo = buscarSimbolo(nombreVar);
                
                if (!simbolo) {
                    printf("[ERROR] Variable '%s' no encontrada para incremento\n", nombreVar);
                    return EJEC_OK;
                }
                
                if (simbolo->tipo != TIPO_INT) {
                    printf("[ERROR] Incremento solo soportado para variables int\n");
                    return EJEC_OK;
                }
                
                // Incrementar el valor
                if (nodo->valor && strcmp(nodo->valor, "++") == 0) {
                    simbolo->valor.v.i++;
                    printf("[DEBUG] Variable '%s' incrementada a: %d\n", nombreVar, simbolo->valor.v.i);
                } else if (nodo->valor && strcmp(nodo->valor, "--") == 0) {
                    simbolo->valor.v.i--;
                    printf("[DEBUG] Variable '%s' decrementada a: %d\n", nombreVar, simbolo->valor.v.i);
                }
                
                simbolo->valor.inicializado = 1;
            } else {
                printf("[ERROR] Nodo incremento sin variable válida\n");
            }
            return EJEC_OK;

        case AST_IF:
            return ejecutarNodoIf(nodo);
            
        case AST_SWITCH:
            contexto_break++;
            contexto_continue++;
            ResultadoEjecucion res_switch = EjecturarNodoSwitch(nodo);
            contexto_break--;
            contexto_continue--;
            return res_switch;
            
        case AST_WHILE:
            contexto_break++;
            contexto_continue++;
            ResultadoEjecucion resWHILE = ejecutarSetenciaWhile(nodo);
            contexto_break--;
            contexto_continue--;
            return resWHILE;
            
        case AST_FOR:
            contexto_break++;
            contexto_continue++;
            ResultadoEjecucion resFOR = ejecutarSentenciaFor(nodo);
            contexto_break--;
            contexto_continue--;
            return resFOR;

        case AST_BREAK:
            printf("[DEBUG AST_BREAK] Ejecutando break\n");
            return ejecutarSentenciaBreak(nodo);
            
        case AST_CONTINUE:
            return ejecutarSentenciaContinue(nodo);
            
        default:
            printf("[DEBUG] Nodo tipo %d no manejado específicamente, procesando hijos\n", nodo->tipo);
            for (int i = 0; i < nodo->num_hijos; i++) {
                if (nodo->hijos[i] != NULL) {
                    ejecutarNodoAST(nodo->hijos[i]);
                }
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