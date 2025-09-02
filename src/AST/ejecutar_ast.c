#include "ast.h"
#include "../semantico/tabla_simbolo.h"
#include "../semantico/semantico.h"
#include "../semantico/Instrucciones/asignacion.h"
#include "../semantico/Instrucciones/declaracion.h"
#include "../semantico/Instrucciones/Print.h"
#include <stdio.h>
#include <stdlib.h>

// Función para ejecutar cada nodo del AST en orden secuencial
void ejecutarNodoAST(NodoAST* nodo) {
    if (!nodo || !nodo->valido) {
        printf("[DEBUG] Nodo inválido o NULL, saltando\n");
        return;
    }
    
    printf("[DEBUG] Ejecutando nodo tipo: %d, valor: %s\n", 
           nodo->tipo, nodo->valor ? nodo->valor : "NULL");
    
    switch (nodo->tipo) {
        case AST_LISTA:
        case AST_BLOQUE:
            // Ejecutar todos los hijos secuencialmente
            printf("[DEBUG] Ejecutando %d hijos secuencialmente\n", nodo->num_hijos);
            for (int i = 0; i < nodo->num_hijos; i++) {
                printf("[DEBUG] --- Ejecutando hijo %d/%d ---\n", i+1, nodo->num_hijos);
                ejecutarNodoAST(nodo->hijos[i]);
            }
            break;
            
        case AST_DECLARACION:
            printf("[DEBUG] Procesando declaración\n");
            // Procesar la declaración
            verificarDeclaracion(nodo);
            break;
            
        case AST_ASIGNACION:
            printf("[DEBUG] Procesando asignación\n");
            // Procesar la asignación
            verificarAsignacion(nodo);
            break;
            
        case AST_PRINT:
            printf("[DEBUG] Procesando print\n");
            // Ejecutar el print
            if (nodo->num_hijos > 0 && nodo->hijos[0]) {
                imprimirEvaluado(nodo->hijos[0]);
            } else {
                printf("[WARNING] Nodo PRINT sin expresión para imprimir\n");
            }
            break;
            
        default:
            printf("[DEBUG] Tipo de nodo %d no manejado específicamente\n", nodo->tipo);
            // Para otros tipos, ejecutar hijos si los hay
            for (int i = 0; i < nodo->num_hijos; i++) {
                ejecutarNodoAST(nodo->hijos[i]);
            }
            break;
    }
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