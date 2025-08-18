#include "tabla_simbolo.h"
#include <stdlib.h>
#include <string.h>

static Simbolo* tabla = NULL;

void inicializarTabla() {
    tabla = NULL;
}

void liberarTabla() {
    Simbolo* actual = tabla;
    while (actual) {
        Simbolo* temp = actual;
        actual = actual->siguiente;
        free(temp->nombre);
        free(temp);
    }
    tabla = NULL;
}

void agregarSimbolo(const char* nombre, int tipo) {
    Simbolo* nuevo = (Simbolo*)malloc(sizeof(Simbolo));
    nuevo->nombre = strdup(nombre);
    nuevo->tipo = tipo;
    nuevo->siguiente = tabla;
    tabla = nuevo;
}

Simbolo* buscarSimbolo(const char* nombre) {
    Simbolo* actual = tabla;
    while (actual) {
        if (strcmp(actual->nombre, nombre) == 0) return actual;
        actual = actual->siguiente;
    }
    return NULL;
}