#include "Print.h"
#include "../tipos.h"
#include "../tabla_simbolo.h"
#include "../semantico.h"
#include <stdio.h>
#include "../../AST/err.h"  
#include "../../simbolos/Evaluador.h"

void imprimirTexto(const char* mensaje){
    printf("%s\n", mensaje ? mensaje : "(null)");
}

void imprimirValor(TipoDato tipo, const char* literal){
    // no usada directamente ahora (se deja para literales simples)
    if(!literal){ printf("null\n"); return; }
    switch(tipo){
        case TIPO_STRING: printf("\"%s\"\n", literal); break;
        case TIPO_CHAR:   printf("'%s'\n", literal); break;
        default:          printf("%s\n", literal); break;
    }
}
// añade nueva función de utilidad
void imprimirEvaluado(NodoAST* expr){
    ValorSimbolo v = evaluarExpr(expr);
    if(!v.inicializado){
        printf("[PRINT] (sin valor)\n");
        return;
    }
    switch(v.tipo){
        case TIPO_INT:    printf("%d\n", v.v.i); break;
        case TIPO_FLOAT:  printf("%f\n", v.v.f); break;
        case TIPO_DOUBLE: printf("%lf\n", v.v.d); break;
        case TIPO_CHAR:   printf("%c\n", v.v.c); break;
        case TIPO_BOOLEAN:printf("%s\n", v.v.b?"true":"false"); break;
        case TIPO_STRING: printf("%s\n", v.v.s? v.v.s : "null"); break;
        default:          printf("?\n"); break;
    }
}