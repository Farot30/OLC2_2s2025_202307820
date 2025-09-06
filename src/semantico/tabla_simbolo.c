#include "tabla_simbolo.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tipos.h"
#include "../simbolos/Evaluador.h"

static Simbolo* tabla = NULL;
static int contadorSimbolos = 0;

// tabla_simbolo.c
char* pilaAmbitos[MAX_SCOPES];
int topeAmbitos = 0;

void entrarAmbito(const char* nombre) {
    if (topeAmbitos < MAX_SCOPES) {
        pilaAmbitos[topeAmbitos++] = strdup(nombre);
        printf("[DEBUG] Entrando al ámbito: %s\n", nombre);
    }
}

void salirAmbito(void) {
    if (topeAmbitos > 0) {
        printf("[DEBUG] Saliendo del ámbito: %s\n", pilaAmbitos[topeAmbitos - 1]);
        free(pilaAmbitos[--topeAmbitos]);
    }
}

const char* ambitoActual(void) {
    return (topeAmbitos > 0) ? pilaAmbitos[topeAmbitos-1] : "global";
}

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
        if (temp->tipo == TIPO_STRING && temp->valor.v.s) {
            free(temp->valor.v.s);
        }
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
    nuevo->siguiente = NULL;
    if (!tabla) {
        tabla = nuevo;
    } else {
        Simbolo* actual = tabla;
        while (actual->siguiente) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
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

void setValorSimbolo(Simbolo* sim, TipoDato tipoValor, ValorSimbolo val) {
    if (!sim) {
        printf("[DEBUG setValorSimbolo] Símbolo es NULL\n");
        return;
    }

    /*printf("[DEBUG setValorSimbolo] === INICIANDO ASIGNACIÓN ===\n");
    printf("[DEBUG setValorSimbolo] Variable: %s\n", sim->nombre);
    printf("[DEBUG setValorSimbolo] Valor actual: %d\n", sim->valor.v.i);
    printf("[DEBUG setValorSimbolo] Tipo símbolo: %d, Tipo valor: %d\n", sim->tipo, tipoValor);
    printf("[DEBUG setValorSimbolo] Nuevo valor: %d\n", val.v.i);
    printf("[DEBUG setValorSimbolo] Valor inicializado: %d\n", val.inicializado);*/

    // Actualizar el ámbito de la asignación
    if (sim->ambito) free(sim->ambito);
    sim->ambito = strdup(ambitoActual());

    // Widening casting automático (char -> int -> float -> double)
    if (esWidening(tipoValor, sim->tipo)) {
        printf("[DEBUG setValorSimbolo] Aplicando widening casting\n");
        double base = 0;
        switch (tipoValor) {
            case TIPO_CHAR:   base = (unsigned char)val.v.c; break;
            case TIPO_INT:    base = val.v.i; break;
            case TIPO_FLOAT:  base = val.v.f; break;
            case TIPO_DOUBLE: base = val.v.d; break;
            default: break;
        }
        switch (sim->tipo) {
            case TIPO_DOUBLE: sim->valor.v.d = base; break;
            case TIPO_FLOAT:  sim->valor.v.f = (float)base; break;
            case TIPO_INT:    sim->valor.v.i = (int)base; break;
            case TIPO_CHAR:   sim->valor.v.c = (char)base; break;
            default: break;
        }
        sim->valor.tipo = sim->tipo;
        sim->valor.inicializado = 1;
        printf("[DEBUG setValorSimbolo] Widening realizado - nuevo valor: %d\n", sim->valor.v.i);
        return;
    }

    // Narrowing casting manual (double -> float -> int -> char)
    if (esNarrowing(tipoValor, sim->tipo)) {
        printf("[DEBUG setValorSimbolo] Intentando narrowing casting\n");
        // Solo permitir si el valor proviene de un cast explícito
        if (!val.es_cast) {
            printf("[ERROR] Narrowing casting solo permitido con cast explícito: %s <- %s\n",
                   nombreTipoDato(sim->tipo), nombreTipoDato(tipoValor));
            return;
        }
        double base = 0;
        switch (tipoValor) {
            case TIPO_DOUBLE: base = val.v.d; break;
            case TIPO_FLOAT:  base = val.v.f; break;
            case TIPO_INT:    base = val.v.i; break;
            case TIPO_CHAR:   base = (unsigned char)val.v.c; break;
            default: break;
        }
        switch (sim->tipo) {
            case TIPO_DOUBLE: sim->valor.v.d = base; break;
            case TIPO_FLOAT:  sim->valor.v.f = (float)base; break;
            case TIPO_INT:    sim->valor.v.i = (int)base; break;
            case TIPO_CHAR:   sim->valor.v.c = (char)base; break;
            default: break;
        }
        sim->valor.tipo = sim->tipo;
        sim->valor.inicializado = 1;
        printf("[DEBUG setValorSimbolo] Narrowing realizado - nuevo valor: %d\n", sim->valor.v.i);
        return;
    }

    // Asignación directa para tipos iguales
    if (sim->tipo == tipoValor) {
        printf("[DEBUG setValorSimbolo] Asignación directa (tipos iguales)\n");
        printf("[DEBUG setValorSimbolo] Antes: sim->valor.v.i = %d\n", sim->valor.v.i);
        sim->valor = val;
        sim->valor.tipo = sim->tipo;
        sim->valor.inicializado = 1;
        printf("[DEBUG setValorSimbolo] Después: sim->valor.v.i = %d\n", sim->valor.v.i);
        return;
    }

    // Asignación para cadenas y booleanos
    if (sim->tipo == TIPO_STRING) {
        if (sim->valor.v.s) free(sim->valor.v.s);
        sim->valor.v.s = val.v.s ? strdup(val.v.s) : NULL;
        sim->valor.tipo = TIPO_STRING;
        sim->valor.inicializado = 1;
        printf("[DEBUG setValorSimbolo] String asignado\n");
        return;
    }
    if (sim->tipo == TIPO_BOOLEAN) {
        sim->valor.v.b = val.v.b;
        sim->valor.tipo = TIPO_BOOLEAN;
        sim->valor.inicializado = 1;
        printf("[DEBUG setValorSimbolo] Boolean asignado\n");
        return;
    }

    // Si no es compatible, reporta error
    printf("[ERROR] Asignación incompatible: %s <- %s\n",
           nombreTipoDato(sim->tipo), nombreTipoDato(tipoValor));
}

ValorSimbolo getValorSimbolo(Simbolo* sim){
    ValorSimbolo dummy = { .tipo = TIPO_DESCONOCIDO, .inicializado = 0 };
    if(!sim) return dummy;
    return sim->valor;
}

void mostrarTablaSimbolos() {
    printf("\n=== Tabla de Símbolos ===\n");
    printf("%-4s %-15s %-8s %-10s %-8s %-10s %-6s %-6s\n",
           "ID", "Nombre", "Clase", "TipoDato", "Valor", "Ambito", "Linea", "Col");
    printf("-------------------------------------------------------------------------------\n");
    Simbolo* actual = tabla;

     while (actual) {
        char valor[50] = "(sin valor)";
        if (actual->inicializado) {
            switch (actual->tipo) {
                case TIPO_INT:
                    snprintf(valor, sizeof(valor), "%d", actual->valor.v.i);
                    break;
                case TIPO_FLOAT:
                    snprintf(valor, sizeof(valor), "%f", actual->valor.v.f);
                    break;
                case TIPO_STRING:
                    snprintf(valor, sizeof(valor), "\"%s\"", actual->valor.v.s);
                    break;
                case TIPO_DOUBLE:
                    snprintf(valor, sizeof(valor), "%lf", actual->valor.v.d);
                    break;
                case TIPO_CHAR:
                    snprintf(valor, sizeof(valor), "'%c'", actual->valor.v.c);
                    break;
                case TIPO_BOOLEAN:
                    snprintf(valor, sizeof(valor), "%s", actual->valor.v.b ? "true" : "false");
                    break;
                
                default:
                    snprintf(valor, sizeof(valor), "(desconocido)");
                    break;
            }
        }
        printf("%-4d %-15s %-8s %-10s %-8s %-10s %-6d %-6d\n",
               actual->id,
               actual->nombre,
               nombreClase(actual->clase),
               nombreTipoDato(actual->tipo),
               valor,
               actual->ambito,
               actual->linea,
               actual->columna);
        actual = actual->siguiente;
    }
    printf("=============================================\n");
}
