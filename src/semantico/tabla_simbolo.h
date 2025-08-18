#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

typedef struct Simbolo {
    char* nombre;
    int tipo;
    struct Simbolo* siguiente;
} Simbolo;

void inicializarTabla();
void liberarTabla();
void agregarSimbolo(const char* nombre, int tipo);
Simbolo* buscarSimbolo(const char* nombre);

#endif