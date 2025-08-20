#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H
#include "tipos.h"
#include "../comun/strutil.h"
typedef enum {
    SIMBOLO_VARIABLE,
    SIMBOLO_FUNCION
} TipoSimbolo;
typedef struct {
    TipoDato tipo;
    union {
        int i;
        float f;
        double d;
        char c;
        char* s;
        int b;   // boolean (0/1)
    } v;
    int inicializado;
} ValorSimbolo;

typedef struct Simbolo {
    int id;
    char* nombre;
    TipoSimbolo clase;
    TipoDato tipo;
    char* ambito;
    int linea;
    int columna;
    ValorSimbolo valor;        // <- nuevo
    struct Simbolo* siguiente;
} Simbolo;

void inicializarTabla();
void liberarTabla();
void agregarSimbolo(const char* nombre, TipoDato tipo); // compatible
void agregarSimboloDetallado(const char* nombre, TipoSimbolo clase, TipoDato tipo,
                             const char* ambito, int linea, int columna);
Simbolo* buscarSimbolo(const char* nombre);
void mostrarTablaSimbolos();
void setValorSimbolo(Simbolo* sim, TipoDato tipo, ValorSimbolo valor);
ValorSimbolo getValorSimbolo(Simbolo* sim);

#endif