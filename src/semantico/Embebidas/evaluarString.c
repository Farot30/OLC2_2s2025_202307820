
#include "evaluarString.h"
#include "../../simbolos/Operador.h"

#include "../../AST/ast.h"
#include "../tabla_simbolo.h"
#include "../semantico.h"
#include "../../AST/err.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static char* concat3(const char* s1, const char* s2, const char* s3) {
    size_t len1 = s1 ? strlen(s1) : 0;
    size_t len2 = s2 ? strlen(s2) : 0;
    size_t len3 = s3 ? strlen(s3) : 0;
    
    char* result = (char*)malloc(len1 + len2 + len3 + 1);
    if (!result) return NULL;
    
    if (s1) strcpy(result, s1);
    else result[0] = '\0';
    
    if (s2) strcat(result, s2);
    if (s3) strcat(result, s3);
    
    return result;
}
// Función para evaluar AST_PARSEJOIN
ValorSimbolo evaluarParseJoin(NodoAST* e) {
    ValorSimbolo r;
    memset(&r, 0, sizeof(r));
    r.tipo = TIPO_STRING;
    r.inicializado = 0;

    if (e->num_hijos < 2) {
        printf("[ERROR] String.join requiere al menos un delimitador y un elemento\n");
        return r;
    }

    // Evaluar el delimitador
    ValorSimbolo delimitador = evaluarExpr(e->hijos[0]);
    if (!delimitador.inicializado || delimitador.tipo != TIPO_STRING) {
        char msg[200];
        snprintf(msg, sizeof(msg), "El delimitador de String.join debe ser una cadena, se recibió %s", 
                nombreTipo(delimitador.tipo));
        addError(msg, ambitoActual(), e->linea, e->columna);
        printf("[ERROR] %s\n", msg);
        return r;
    }

    // Obtener el nodo de la lista de expresiones
    NodoAST* lista = e->hijos[1];
    if (lista->tipo != AST_LISTA) {
        printf("[ERROR] Se esperaba una lista de expresiones para String.join\n");
        return r;
    }

    // Inicializar resultado como cadena vacía
    r.inicializado = 1;
    r.v.s = strdup("");

    // Unir las expresiones con el delimitador
    for (int i = 0; i < lista->num_hijos; i++) {
        // Evaluar la expresión actual
        ValorSimbolo elem = evaluarExpr(lista->hijos[i]);
        if (!elem.inicializado) {
            char msg[200];
            snprintf(msg, sizeof(msg), "Elemento no inicializado en String.join");
            addError(msg, ambitoActual(), e->linea, e->columna);
            printf("[ERROR] %s\n", msg);
            if (r.v.s) free(r.v.s);
            r.inicializado = 0;
            return r;
        }

        // Convertir el elemento a string si no lo es
        char* elemStr;
        if (elem.tipo == TIPO_STRING && elem.v.s) {
            elemStr = strdup(elem.v.s);
        } else {
            // Convertir otros tipos a string
            char buffer[256];
            switch (elem.tipo) {
                case TIPO_INT:
                    snprintf(buffer, sizeof(buffer), "%d", elem.v.i);
                    break;
                case TIPO_FLOAT:
                    snprintf(buffer, sizeof(buffer), "%f", elem.v.f);
                    break;
                case TIPO_DOUBLE:
                    snprintf(buffer, sizeof(buffer), "%f", elem.v.d);
                    break;
                case TIPO_CHAR:
                    snprintf(buffer, sizeof(buffer), "%c", elem.v.c);
                    break;
                case TIPO_BOOLEAN:
                    snprintf(buffer, sizeof(buffer), "%s", elem.v.b ? "true" : "false");
                    break;
                default:
                    buffer[0] = '\0';
                    break;
            }
            elemStr = strdup(buffer);
        }

        // Si no es el primer elemento, agregar el delimitador
        if (i > 0 && delimitador.v.s) {
            char* temp = r.v.s;
            r.v.s = concat3(temp, delimitador.v.s, elemStr);
            free(temp);
        } else {
            // Para el primer elemento, simplemente asignar
            if (r.v.s) free(r.v.s);
            r.v.s = elemStr;
        }
    }

    printf("[DEBUG] String.join resultado: '%s'\n", r.v.s ? r.v.s : "(null)");
    return r;
}

ValorSimbolo evaluarValueOf(NodoAST* e) {
    ValorSimbolo r;
    memset(&r, 0, sizeof(r));
    r.tipo = TIPO_STRING;
    r.inicializado = 0;

    // Verificar que haya al menos un hijo
    if (e->num_hijos < 1) {
        printf("[ERROR] String.valueOf requiere un argumento\n");
        return r;
    }

    // Evaluar el argumento
    ValorSimbolo argVal = evaluarExpr(e->hijos[0]);

    // Verificar que el argumento esté inicializado
    if (!argVal.inicializado) {
        char msg[200];
        snprintf(msg, sizeof(msg), "Argumento de String.valueOf no inicializado");
        addError(msg, ambitoActual(), e->linea, e->columna);
        printf("[ERROR] %s\n", msg);
        return r;
    }

    // Convertir el argumento a cadena según su tipo
    r.tipo = TIPO_STRING;
    r.inicializado = 1;
    char buffer[256]; // Tamaño del buffer para la conversión

    switch (argVal.tipo) {
        case TIPO_INT:
            snprintf(buffer, sizeof(buffer), "%d", argVal.v.i);
            break;
        case TIPO_FLOAT:
            snprintf(buffer, sizeof(buffer), "%f", argVal.v.f);
            break;
        case TIPO_DOUBLE:
            snprintf(buffer, sizeof(buffer), "%f", argVal.v.d);
            break;
        case TIPO_CHAR:
            snprintf(buffer, sizeof(buffer), "%c", argVal.v.c);
            break;
        case TIPO_BOOLEAN:
            snprintf(buffer, sizeof(buffer), "%s", argVal.v.b ? "true" : "false");
            break;
        case TIPO_STRING:
            // Si ya es una cadena, simplemente duplicarla
            r.v.s = strdup(argVal.v.s ? argVal.v.s : "");
            return r;
        default:
            // Tipo no soportado
            snprintf(buffer, sizeof(buffer), "[ERROR: Tipo no soportado]");
            printf("[ERROR] String.valueOf no soporta el tipo '%d'\n", argVal.tipo);
            addError(buffer, ambitoActual(), e->linea, e->columna);
            break;
    }

    // Asignar la cadena resultante
    r.v.s = strdup(buffer);
    return r;
}

ValorSimbolo evaluarEqual(NodoAST* e) {
    ValorSimbolo r;
    memset(&r, 0, sizeof(r));
    r.tipo = TIPO_BOOLEAN; // Cambiado a TIPO_BOOLEAN porque .equals devuelve un booleano
    r.inicializado = 0;

    // Verificar que el nodo sea válido y tenga dos hijos
    if (!e || strcmp(e->valor, ".equals") != 0 || e->num_hijos != 2) {
        printf("[ERROR] Nodo inválido para .equals\n");
        return r;
    }

    // Evaluar los dos argumentos
    ValorSimbolo base = evaluarExpr(e->hijos[0]);
    ValorSimbolo arg = evaluarExpr(e->hijos[1]);

    // Verificar que ambos argumentos estén inicializados
    if (!base.inicializado || !arg.inicializado) {
        char msg[200];
        snprintf(msg, sizeof(msg), "Argumentos de .equals no inicializados");
        addError(msg, ambitoActual(), e->linea, e->columna);
        printf("[ERROR] %s\n", msg);
        return r;
    }

    // Verificar que ambos argumentos sean cadenas
    if (base.tipo != TIPO_STRING || arg.tipo != TIPO_STRING) {
        char msg[200];
        snprintf(msg, sizeof(msg), ".equals solo válido para strings, se recibieron tipos '%s' y '%s'",
                nombreTipo(base.tipo), nombreTipo(arg.tipo));
        addError(msg, ambitoActual(), e->linea, e->columna);
        printf("[ERROR] %s\n", msg);
        return r;
    }

    // Comparar las cadenas
    r.inicializado = 1;
    r.v.b = (base.v.s && arg.v.s) ? strcmp(base.v.s, arg.v.s) == 0 : (base.v.s == arg.v.s);

    // Imprimir el resultado para depuración
    printf("[DEBUG] .equals('%s', '%s') = %s\n",
           base.v.s ? base.v.s : "null",
           arg.v.s ? arg.v.s : "null",
           r.v.b ? "true" : "false");


    return r;
}

