#include "Print.h"
#include "../tipos.h"
#include "../tabla_simbolo.h"
#include "../semantico.h"
#include <stdio.h>
#include "../../AST/err.h"  
#include "../../simbolos/Evaluador.h"
#include "../../simbolos/salida.h"

extern void capture_print_output(const char* text);

void imprimirTexto(const char* mensaje){
    if (mensaje) {
        printf("%s\n", mensaje);
        // NUEVO: Capturar para GUI
        char buffer[1024];
        snprintf(buffer, sizeof(buffer), "%s\n", mensaje);
        capture_print_output(buffer);
    }
}
void imprimirValor(TipoDato tipo, const char* literal){
    if(!literal){ 
        printf("null\n"); 
        capture_print_output("null\n");  // NUEVO
        return; 
    }
    char buffer[256];
    switch(tipo){
        case TIPO_STRING: 
            snprintf(buffer, sizeof(buffer), "\"%s\"\n", literal);
            printf("%s", buffer);
            capture_print_output(buffer);  // NUEVO
            break;
        case TIPO_CHAR:   
            snprintf(buffer, sizeof(buffer), "'%s'\n", literal);
            printf("%s", buffer);
            capture_print_output(buffer);  // NUEVO
            break;
        default:          
            snprintf(buffer, sizeof(buffer), "%s\n", literal);
            printf("%s", buffer);
            capture_print_output(buffer);  // NUEVO
            break;
    }
}

void imprimirEvaluado(NodoAST* expr){
    ValorSimbolo v = evaluarExpr(expr);
    if(!v.inicializado){
        printf("[PRINT] (sin valor)\n");
        capture_print_output("[PRINT] (sin valor)\n");  // NUEVO
        return;
    }
    
    char buffer[256];
    switch(v.tipo){
        case TIPO_INT:    
            snprintf(buffer, sizeof(buffer), "%d\n", v.v.i);
            printf("%s", buffer);
            capture_print_output(buffer);  // NUEVO
            break;
        case TIPO_FLOAT:  
            snprintf(buffer, sizeof(buffer), "%f\n", v.v.f);
            printf("%s", buffer);
            capture_print_output(buffer);  // NUEVO
            break;
        case TIPO_DOUBLE: 
            snprintf(buffer, sizeof(buffer), "%lf\n", v.v.d);
            printf("%s", buffer);
            capture_print_output(buffer);  // NUEVO
            break;
        case TIPO_CHAR:   
            snprintf(buffer, sizeof(buffer), "%c\n", v.v.c);
            printf("%s", buffer);
            capture_print_output(buffer);  // NUEVO
            break;
        case TIPO_BOOLEAN:
            snprintf(buffer, sizeof(buffer), "%s\n", v.v.b?"true":"false");
            printf("%s", buffer);
            capture_print_output(buffer);  // NUEVO
            break;
        case TIPO_STRING: 
            snprintf(buffer, sizeof(buffer), "%s\n", v.v.s? v.v.s : "null");
            printf("%s", buffer);
            capture_print_output(buffer);  // NUEVO
            break;
        default:          
            printf("?\n"); 
            capture_print_output("?\n");  // NUEVO
            break;
    }
}