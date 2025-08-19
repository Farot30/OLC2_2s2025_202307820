#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"


NodoAST* crearNodo(TipoNodoAST tipo, char* valor) {
    NodoAST* nodo = (NodoAST*)malloc(sizeof(NodoAST));
    nodo->tipo = tipo;
    nodo->valor = valor ? strdup(valor) : NULL;
    nodo->hijos = NULL;
    nodo->num_hijos = 0;
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
        default: return "UNK";
    }
}

static void escapar(const char* src, char* dst, size_t max){
    size_t j=0;
    for(size_t i=0; src && src[i] && j+2 < max; ++i){
        if(src[i]=='"' || src[i]=='\\')
            dst[j++]='\\';
        dst[j++]=src[i];
    }
    dst[j]=0;
}

static void graphvizRec(NodoAST* n){
    if(!n) return;
    char valorEsc[128];
    escapar(n->valor ? n->valor : "NULL", valorEsc, sizeof(valorEsc));
    printf("  n%p [label=\"{Tipo: %s|Valor: %s}\"];\n",
           (void*)n, nombreNodoTipo(n->tipo), valorEsc);
    for(int i=0;i<n->num_hijos;++i){
        printf("  n%p -> n%p;\n", (void*)n, (void*)n->hijos[i]);
        graphvizRec(n->hijos[i]);
    }
}

void graphvizAST(NodoAST* raiz){
    if(!raiz){
        printf("digraph AST { /* vacío */ }\n");
        return;
    }
    printf("digraph AST {\n");
    printf("  node [shape=record,fontname=\"Helvetica\"];\n");
    graphvizRec(raiz);
    printf("}\n");
}

static void graphvizRecFile(NodoAST* n, FILE* f){
    if(!n) return;
    char valorEsc[128];
    escapar(n->valor ? n->valor : "NULL", valorEsc, sizeof(valorEsc));
    fprintf(f, "  n%p [label=\"{Tipo: %s|Valor: %s}\"];\n",
            (void*)n, nombreNodoTipo(n->tipo), valorEsc);
    for(int i=0;i<n->num_hijos;++i){
        fprintf(f, "  n%p -> n%p;\n", (void*)n, (void*)n->hijos[i]);
        graphvizRecFile(n->hijos[i], f);
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