#include "Print.h"
#include "../tipos.h"
#include "../tabla_simbolo.h"
#include "../semantico.h"
#include <stdio.h>
#include "../../AST/err.h"  
#include "../../simbolos/Evaluador.h"
#include "../../simbolos/salida.h"

extern void capture_print_output(const char* text);

static void procesarSecuenciasEscape(const char* src, char* dst, size_t max) {
    size_t j = 0;
    for (size_t i = 0; src && src[i] && j + 1 < max; ++i) {
        if (src[i] == '\\' && src[i+1]) {
            switch (src[i+1]) {
                case 'n': dst[j++] = '\n'; i++; break;
                case 'r': dst[j++] = '\n'; i++; break; // Unificar \r como salto de línea
                case 't': dst[j++] = '\t'; i++; break;
                case '\\': dst[j++] = '\\'; i++; break;
                case '"': dst[j++] = '"'; i++; break;
                default: dst[j++] = src[i]; break;
            }
        } else {
            dst[j++] = src[i];
        }
    }
    dst[j] = 0;
}

void imprimirTexto(const char* mensaje){
    if (mensaje) {
        char procesada[1024];
        procesarSecuenciasEscape(mensaje, procesada, sizeof(procesada));
        printf("%s", procesada);
        capture_print_output(procesada);
    }
}

void imprimirValor(TipoDato tipo, const char* literal){
    if(!literal){ 
        printf("null");
        capture_print_output("null");
        return; 
    }
    char procesada[256];
    procesarSecuenciasEscape(literal, procesada, sizeof(procesada));
    switch(tipo){
        case TIPO_STRING: 
            printf("\"%s\"", procesada);
            capture_print_output(procesada);
            break;
        case TIPO_CHAR:   
            printf("'%s'", procesada);
            capture_print_output(procesada);
            break;
        default:          
            printf("%s", procesada);
            capture_print_output(procesada);
            break;
    }
}

void imprimirEvaluado(NodoAST* expr) {
    printf("[DEBUG] imprimirEvaluado() llamado\n");
    
    if (!expr) {
        printf("[DEBUG] expr es NULL\n");
        printf("[PRINT] (expresión nula)\n");
        capture_print_output("[PRINT] (expresión nula)\n");
        return;
    }
    
    ValorSimbolo v = evaluarExpr(expr);
    printf("[DEBUG] Resultado evaluación - inicializado: %d, tipo: %d\n", 
           v.inicializado, v.tipo);
    
    if (!v.inicializado) {
        printf("[PRINT] (sin valor)\n");
        capture_print_output("[PRINT] (sin valor)\n");
        return;
    }

    char buffer[256];
    switch (v.tipo) {
        case TIPO_INT:
            snprintf(buffer, sizeof(buffer), "%d", v.v.i);
            break;
        case TIPO_FLOAT:
            snprintf(buffer, sizeof(buffer), "%f", v.v.f);
            break;
        case TIPO_DOUBLE:
            snprintf(buffer, sizeof(buffer), "%lf", v.v.d);
            break;
        case TIPO_CHAR:
            snprintf(buffer, sizeof(buffer), "%c", v.v.c);
            break;
        case TIPO_BOOLEAN:
            snprintf(buffer, sizeof(buffer), "%s", v.v.b ? "true" : "false");
            break;
        case TIPO_STRING:
            snprintf(buffer, sizeof(buffer), "%s", v.v.s ? v.v.s : "null");
            break;
        default:
            snprintf(buffer, sizeof(buffer), "(tipo desconocido)");
            break;
    }
    
    printf("%s\n", buffer);
    capture_print_output(buffer);
    capture_print_output("\n");
}