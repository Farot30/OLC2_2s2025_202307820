#include "tabla_simbolo.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tipos.h"
#include "../simbolos/Evaluador.h"

static Simbolo* tabla = NULL;
static int contadorSimbolos = 0;

void inicializarTabla() {
    tabla = NULL;
    contadorSimbolos = 0;
}

void liberarTabla() {
    Simbolo* actual = tabla;
    while (actual) {
        Simbolo* temp = actual;
        actual = actual->siguiente;
        free(temp->nombre);
        if (temp->ambito) free(temp->ambito);
        free(temp);
    }
    tabla = NULL;
}

static Simbolo* crearSimbolo(const char* nombre, TipoSimbolo clase, TipoDato tipo,
                             const char* ambito, int linea, int columna) {
    Simbolo* nuevo = (Simbolo*)malloc(sizeof(Simbolo));
    nuevo->id = ++contadorSimbolos;
    nuevo->nombre = strdup(nombre);
    nuevo->clase = clase;
    nuevo->tipo = tipo;
    nuevo->ambito = ambito ? strdup(ambito) : strdup("global");
    nuevo->linea = linea;
    nuevo->columna = columna;
    nuevo->siguiente = NULL;
    nuevo->valor.tipo = tipo;
    nuevo->valor.inicializado = 0;

    switch(tipo){
        case TIPO_INT:    nuevo->valor.v.i = 0; break;
        case TIPO_FLOAT:  nuevo->valor.v.f = 0.0f; break;
        case TIPO_DOUBLE: nuevo->valor.v.d = 0.0; break;
        case TIPO_CHAR:   nuevo->valor.v.c = '\0'; break;
        case TIPO_BOOLEAN:nuevo->valor.v.b = 0; break;
        case TIPO_STRING: nuevo->valor.v.s = NULL; break;
        default: break;
    
    }
    return nuevo;
}

void agregarSimboloDetallado(const char* nombre, TipoSimbolo clase, TipoDato tipo,
                             const char* ambito, int linea, int columna) {
    Simbolo* nuevo = crearSimbolo(nombre, clase, tipo, ambito, linea, columna);
    nuevo->siguiente = tabla;
    tabla = nuevo;
    
}


void agregarSimbolo(const char* nombre, TipoDato tipo) {
    // compatibilidad: clase variable, ámbito global, sin línea/columna
    agregarSimboloDetallado(nombre, SIMBOLO_VARIABLE, tipo, "global", -1, -1);
    
    
}

Simbolo* buscarSimbolo(const char* nombre) {
    Simbolo* actual = tabla;
    while (actual) {
        if (strcmp(actual->nombre, nombre) == 0) return actual;
        actual = actual->siguiente;
    }
    return NULL;
}

static const char* nombreTipoDato(TipoDato t){
    switch(t){
        case TIPO_INT: return "int";
        case TIPO_FLOAT: return "float";
        case TIPO_DOUBLE: return "double";
        case TIPO_CHAR: return "char";
        case TIPO_STRING: return "string";
        case TIPO_BOOLEAN: return "boolean";
        default: return "desconocido";
    }
}

static const char* nombreClase(TipoSimbolo c){
    switch(c){
        case SIMBOLO_VARIABLE: return "var";
        case SIMBOLO_FUNCION: return "func";
        default: return "?";
    }
}

void setValorSimbolo(Simbolo* sim, TipoDato tipo, ValorSimbolo val){
    if(!sim) return;
    if(sim->tipo != tipo && tipo != TIPO_DESCONOCIDO) {
        // asumir conversión simple numérica
        if((sim->tipo==TIPO_DOUBLE||sim->tipo==TIPO_FLOAT||sim->tipo==TIPO_INT||sim->tipo==TIPO_CHAR) &&
           (val.tipo==TIPO_DOUBLE||val.tipo==TIPO_FLOAT||val.tipo==TIPO_INT||val.tipo==TIPO_CHAR)) {
            // convertir
            double base;
            switch(val.tipo){
                case TIPO_DOUBLE: base = val.v.d; break;
                case TIPO_FLOAT:  base = val.v.f; break;
                case TIPO_INT:    base = val.v.i; break;
                case TIPO_CHAR:   base = (unsigned char)val.v.c; break;
                default: base = 0;
            }
            switch(sim->tipo){
                case TIPO_DOUBLE: sim->valor.v.d = base; break;
                case TIPO_FLOAT:  sim->valor.v.f = (float)base; break;
                case TIPO_INT:    sim->valor.v.i = (int)base; break;
                case TIPO_CHAR:   sim->valor.v.c = (char)base; break;
                default: break;
            }
            sim->valor.tipo = sim->tipo;
            sim->valor.inicializado = 1;
            return;
        }
    }
    // strings / boolean directos
    if(sim->tipo == TIPO_STRING){
        if(sim->valor.v.s) free(sim->valor.v.s);
        sim->valor.v.s = val.v.s ? strdup(val.v.s) : NULL;
    } else {
        sim->valor = val;
        sim->valor.tipo = sim->tipo;
    }
    sim->valor.inicializado = 1;
}

ValorSimbolo getValorSimbolo(Simbolo* sim){
    ValorSimbolo dummy = { .tipo = TIPO_DESCONOCIDO, .inicializado = 0 };
    if(!sim) return dummy;
    return sim->valor;
}

void mostrarTablaSimbolos() {
    printf("\n=== Tabla de Símbolos ===\n");
    printf("%-4s %-15s %-8s %-10s %-10s %-6s %-6s\n",
           "ID", "Nombre", "Clase", "TipoDato", "Ambito", "Linea", "Col");
    printf("-------------------------------------------------------------------------------\n");
    Simbolo* actual = tabla;
    while (actual) {
        printf("%-4d %-15s %-8s %-10s %-10s %-6d %-6d\n",
               actual->id,
               actual->nombre,
               nombreClase(actual->clase),
               nombreTipoDato(actual->tipo),
               actual->ambito,
               actual->linea,
               actual->columna);
        actual = actual->siguiente;
    }
    printf("=============================================\n");
}
