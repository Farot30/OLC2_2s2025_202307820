#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "../simbolos/Evaluador.h"
#include "../semantico/tipos.h"


NodoAST* crearNodo(TipoNodoAST tipo, char* valor) {
    NodoAST* nodo = (NodoAST*)malloc(sizeof(NodoAST));
    nodo->tipo = tipo;
    nodo->valor = valor ? strdup(valor) : NULL;
    nodo->hijos = NULL;
    nodo->num_hijos = 0;
    nodo->linea = -1;
    nodo->columna = -1;
    nodo->valido = 1;
    
    return nodo;
}

void agregarHijo(NodoAST* padre, NodoAST* hijo) {
    padre->hijos = (NodoAST**)realloc(padre->hijos, sizeof(NodoAST*) * (padre->num_hijos + 1));
    padre->hijos[padre->num_hijos] = hijo;
    padre->num_hijos++;
}


void liberarAST(NodoAST* nodo) {
    if (!nodo) return;
    for (int i = 0; i < nodo->num_hijos; ++i)
        liberarAST(nodo->hijos[i]);
    free(nodo->hijos);
    if (nodo->valor) free(nodo->valor);
    free(nodo);
}


void imprimirAST(NodoAST* nodo, int nivel) {
    if (!nodo) return;
    for (int i = 0; i < nivel; ++i) printf("  ");
    printf("Tipo: %d", nodo->tipo);
    if (nodo->valor) printf(", Valor: %s", nodo->valor);
    printf("\n");
    for (int i = 0; i < nodo->num_hijos; ++i)
        imprimirAST(nodo->hijos[i], nivel + 1);
}


static const char* nombreNodoTipo(TipoNodoAST t){
    switch(t){
        case AST_NUMERO: return "NUMERO";
        case AST_IDENTIFICADOR: return "IDENT";
        case AST_DECLARACION: return "DECL";
        case AST_LISTA: return "LISTA";
        case AST_BLOQUE: return "BLOQUE";
        case AST_ASIGNACION: return "ASIG";
        case AST_CADENA: return "CADENA";
        case AST_CARACTER: return "CARACTER";
        case AST_OPERACION: return "OP";
        case AST_CAST: return "CAST";
        case AST_PRINT: return "PRINT";
        case AST_BOOLEAN: return "BOOLEAN";
        case AST_ERROR: return "ERROR";
        case AST_STRING: return "STRING";
        case AST_EQUAL: return "EQUAL";
        case AST_IF: return "IF";
        case AST_ELSE : return "ELSE";
        case AST_ELSEIF: return "ELSEIF";
        case AST_SWITCH: return "SWITCH";
        case AST_CASE: return "CASE";
        case AST_BREAK: return "BREAK";
        case AST_DEFAULT: return "DEFAULT";
        case AST_WHILE: return "WHILE";
        case AST_CONTINUE: return "CONTINUE";
        case AST_FOR: return "FOR";
        case AST_INCREMENTO: return "INCREMENTO";
        case AST_DECREMENTO: return "DECREMENTO";
        case AST_DECLARACION_VECTOR: return "DECLARACION_VECTOR";
        case AST_DECLARACION_MATRIZ: return "DECLARACION_MATRIZ";
        case AST_DECLARACION_ARRAY_MULTIDIMENSIONAL: return "DECLARACION_ARRAY_MULTIDIMENSIONAL";
        case AST_DIMENSIONES: return "DIMENSIONES";
        case AST_TIPO: return "TIPO";
        case AST_INTERNO: return "INTERNO";
        case AST_LISTA_ELEMENTOS: return "LISTA_ELEMENTOS";
        case AST_1DIMENSION: return "1DIMENSION";
        case AST_ACCESO: return "ACCESO";
        case AST_PARSEINT: return "PARSEINT";
        case AST_PARSEFLOAT: return "PARSEFLOAT";
        case AST_PARSEDOUBLE: return "PARSEDOUBLE";
        case AST_PARSEJOIN: return "PARSEJOIN";
        case AST_VALUEOF: return "VALUEOF";
        case AST_INDEXOF: return "INDEXOF";
        case AST_LENGHT: return "LENGHT";
        case AST_ADD: return "ADD";

        default: return "UNK";
    }
}


static void escaparLabel(const char* src, char* dst, size_t max){
    size_t j=0;
    for(size_t i=0; src && src[i] && j+6 < max; ++i){
        if(src[i]=='|'){
            strcpy(&dst[j], "&#124;");
            j += 6;
        } else if(src[i]=='<'){
            strcpy(&dst[j], "&lt;");
            j += 4;
        } else if(src[i]=='>'){
            strcpy(&dst[j], "&gt;");
            j += 4;
        } else if(src[i]=='"'){
            dst[j++]='\\';
            dst[j++]=src[i];
        } else {
            dst[j++]=src[i];
        }
    }
    dst[j]=0;
}

static void graphvizRec(NodoAST* n, FILE* f) {
    if (!n || !n->valido) return;

    char valorEsc[128];
    escaparLabel(n->valor ? n->valor : "NULL", valorEsc, sizeof(valorEsc));

    // Mostrar el valor evaluado en el nodo PRINT
    if (n->tipo == AST_PRINT && n->num_hijos > 0 && n->hijos[0]) {
        // Evaluar la expresión a imprimir
        ValorSimbolo valorEvaluado = evaluarExpr(n->hijos[0]);
        char valorPrint[256] = "sin valor";
        
        if (valorEvaluado.inicializado) {
            switch (valorEvaluado.tipo) {
                case TIPO_INT:
                    snprintf(valorPrint, sizeof(valorPrint), "%d", valorEvaluado.v.i);
                    break;
                case TIPO_FLOAT:
                    snprintf(valorPrint, sizeof(valorPrint), "%f", valorEvaluado.v.f);
                    break;
                case TIPO_DOUBLE:
                    snprintf(valorPrint, sizeof(valorPrint), "%lf", valorEvaluado.v.d);
                    break;
                case TIPO_CHAR:
                    snprintf(valorPrint, sizeof(valorPrint), "%c", valorEvaluado.v.c);
                    break;
                case TIPO_BOOLEAN:
                    snprintf(valorPrint, sizeof(valorPrint), "%s", valorEvaluado.v.b ? "true" : "false");
                    break;
                case TIPO_STRING:
                    if (valorEvaluado.v.s) {
                        // Para strings, limitar a 40 caracteres para no sobrecargar el gráfico
                        if (strlen(valorEvaluado.v.s) > 40) {
                            char temp[44];
                            strncpy(temp, valorEvaluado.v.s, 40);
                            temp[40] = '\0';
                            snprintf(valorPrint, sizeof(valorPrint), "%s...", temp);
                        } else {
                            snprintf(valorPrint, sizeof(valorPrint), "%s", valorEvaluado.v.s);
                        }
                    } else {
                        snprintf(valorPrint, sizeof(valorPrint), "null");
                    }
                    break;
                default:
                    snprintf(valorPrint, sizeof(valorPrint), "?");
                    break;
            }
        }
        
        // Escapar el valor para Graphviz
        char valorPrintEsc[256];
        escaparLabel(valorPrint, valorPrintEsc, sizeof(valorPrintEsc));
        
        fprintf(f, "  n%p [label=\"{Tipo: %s|Imprime: %s}\"];\n",
                (void*)n, nombreNodoTipo(n->tipo), valorPrintEsc);
    } else {
        fprintf(f, "  n%p [label=\"{Tipo: %s|Valor: %s}\"];\n",
                (void*)n, nombreNodoTipo(n->tipo), valorEsc);
    }

    for (int i = 0; i < n->num_hijos; ++i) {
        if (n->hijos[i] && n->hijos[i]->valido) {
            fprintf(f, "  n%p -> n%p;\n", (void*)n, (void*)n->hijos[i]);
            graphvizRec(n->hijos[i], f);
        }
    }
}

void graphvizAST(NodoAST* raiz){
    if(!raiz){
        printf("digraph AST { /* vacío */ }\n");
        return;
    }
    printf("digraph AST {\n");
    printf("  node [shape=record,fontname=\"Helvetica\"];\n");
    graphvizRec(raiz, stdout);
    printf("}\n");
}


static void graphvizRecFile(NodoAST* n, FILE* f){
    if(!n || !n->valido) return;

    char valorEsc[128];
    escaparLabel(n->valor ? n->valor : "NULL", valorEsc, sizeof(valorEsc));
    
    // Mostrar el valor evaluado en el nodo PRINT (igual que en graphvizRec)
    if (n->tipo == AST_PRINT && n->num_hijos > 0 && n->hijos[0]) {
        // Evaluar la expresión a imprimir
        ValorSimbolo valorEvaluado = evaluarExpr(n->hijos[0]);
        char valorPrint[256] = "sin valor";
        
        if (valorEvaluado.inicializado) {
            switch (valorEvaluado.tipo) {
                case TIPO_INT:
                    snprintf(valorPrint, sizeof(valorPrint), "%d", valorEvaluado.v.i);
                    break;
                case TIPO_FLOAT:
                    snprintf(valorPrint, sizeof(valorPrint), "%f", valorEvaluado.v.f);
                    break;
                case TIPO_DOUBLE:
                    snprintf(valorPrint, sizeof(valorPrint), "%lf", valorEvaluado.v.d);
                    break;
                case TIPO_CHAR:
                    snprintf(valorPrint, sizeof(valorPrint), "%c", valorEvaluado.v.c);
                    break;
                case TIPO_BOOLEAN:
                    snprintf(valorPrint, sizeof(valorPrint), "%s", valorEvaluado.v.b ? "true" : "false");
                    break;
                case TIPO_STRING:
                    if (valorEvaluado.v.s) {
                        // Para strings, limitar a 40 caracteres para no sobrecargar el gráfico
                        if (strlen(valorEvaluado.v.s) > 40) {
                            char temp[44];
                            strncpy(temp, valorEvaluado.v.s, 40);
                            temp[40] = '\0';
                            snprintf(valorPrint, sizeof(valorPrint), "%s...", temp);
                        } else {
                            snprintf(valorPrint, sizeof(valorPrint), "%s", valorEvaluado.v.s);
                        }
                    } else {
                        snprintf(valorPrint, sizeof(valorPrint), "null");
                    }
                    break;
                default:
                    snprintf(valorPrint, sizeof(valorPrint), "?");
                    break;
            }
        }
        
        // Escapar el valor para Graphviz
        char valorPrintEsc[256];
        escaparLabel(valorPrint, valorPrintEsc, sizeof(valorPrintEsc));
        
        fprintf(f, "  n%p [label=\"{Tipo: %s|Imprime: %s}\"];\n",
                (void*)n, nombreNodoTipo(n->tipo), valorPrintEsc);
    } else {
        fprintf(f, "  n%p [label=\"{Tipo: %s|Valor: %s}\"];\n",
                (void*)n, nombreNodoTipo(n->tipo), valorEsc);
    }

    for(int i=0; i<n->num_hijos; ++i){
        if(n->hijos[i] && n->hijos[i]->valido) {
            fprintf(f, "  n%p -> n%p;\n", (void*)n, (void*)n->hijos[i]);
            graphvizRecFile(n->hijos[i], f);
        }
    }
}

void graphvizAST_ToFile(NodoAST* raiz, FILE* f){
    if(!f) return;
    if(!raiz){
        fprintf(f, "digraph AST { /* vacío */ }\n");
        return;
    }
    fprintf(f, "digraph AST {\n");
    fprintf(f, "  node [shape=record,fontname=\"Helvetica\"];\n");
    graphvizRecFile(raiz, f);
    fprintf(f, "}\n");
}

int exportarAST(NodoAST* raiz, const char* rutaDot, const char* rutaPNG){
    if(!rutaDot) return 1;
    FILE* f = fopen(rutaDot, "w");
    if(!f){
        perror("fopen DOT");
        return 2;
    }
    graphvizAST_ToFile(raiz, f);
    fclose(f);
    if(rutaPNG){
        char cmd[512];
        snprintf(cmd, sizeof(cmd), "dot -Tpng \"%s\" -o \"%s\"", rutaDot, rutaPNG);
        int r = system(cmd);
        if(r != 0){
            fprintf(stderr, "Error ejecutando Graphviz (dot). Código=%d\n", r);
            return 3;
        }
    }
    return 0;
}

