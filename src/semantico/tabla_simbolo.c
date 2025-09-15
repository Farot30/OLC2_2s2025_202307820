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

Simbolo* buscarSimboloPorId(int id) {
    Simbolo* actual = tabla;
    while (actual) {
        if (actual->id == id) return actual;
        actual = actual->siguiente;
    }
    return NULL;
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
        
        // Liberar nombre
        if (temp->nombre) {
            free(temp->nombre);
            temp->nombre = NULL;
        }
        
        // Liberar ámbito
        if (temp->ambito) {
            free(temp->ambito);
            temp->ambito = NULL;
        }
        
        // Liberar valor string con verificación adicional
        if (temp->tipo == TIPO_STRING && temp->valor.v.s) {
            free(temp->valor.v.s);
            temp->valor.v.s = NULL;
        } else if (temp->clase == SIMBOLO_VECTOR && temp->valor.inicializado && temp->valor.v.s) {
            free(temp->valor.v.s);
            temp->valor.v.s = NULL;
        } else if (temp->clase == SIMBOLO_MATRIZ && temp->valor.inicializado && temp->valor.v.s) {
            free(temp->valor.v.s);
            temp->valor.v.s = NULL;
        } else if (temp->clase == SIMBOLO_ARRAY_MULTIDIMENSIONAL && temp->valor.inicializado && temp->valor.v.s) {
            free(temp->valor.v.s);
            temp->valor.v.s = NULL;
        }
        
        free(temp);
    }
    tabla = NULL;
    contadorSimbolos = 0; // Reset del contador
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
    nuevo->nodo_bloque = NULL;
    nuevo->nodo_return = NULL;
    nuevo->valor.tipo = tipo;
    nuevo->valor.inicializado = 0;

    switch(tipo){
        case TIPO_INT:    nuevo->valor.v.i = 0; break;
        case TIPO_FLOAT:  nuevo->valor.v.f = 0.0f; break;
        case TIPO_DOUBLE: nuevo->valor.v.d = 0.0; break;
        case TIPO_CHAR:   nuevo->valor.v.c = '\0'; break;
        case TIPO_BOOLEAN:nuevo->valor.v.b = 0; break;
        case TIPO_STRING: nuevo->valor.v.s = strdup(""); break;
        case TIPO_VOID:  nuevo->valor.v.s = NULL; break;
        case TIPO_FUNCION: nuevo->valor.v.s = NULL; break;
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
        case TIPO_VOID: return "void";
        case TIPO_FUNCION: return "funcion";
        default: return "desconocido";
    }
}

static const char* nombreClase(TipoSimbolo c){
    switch(c){
        case SIMBOLO_VARIABLE: return "varriable";
        case SIMBOLO_FUNCION: return "funcion";
        case SIMBOLO_VECTOR: return "vector";
        case SIMBOLO_MATRIZ: return "matriz";
        case SIMBOLO_ARRAY_MULTIDIMENSIONAL: return "array_multidimensional";
        case SIMBOLO_FUNCION_VOID: return "funcion_void";
        default: return "?";
    }
}

void setValorSimbolo(Simbolo* sim, TipoDato tipoValor, ValorSimbolo val) {
    if (!sim) {
        printf("[DEBUG setValorSimbolo] Símbolo es NULL\n");
        return;
    }

    if (sim->tipo == tipoValor) {
        printf("[DEBUG setValorSimbolo] Asignación directa (tipos iguales)\n");
        printf("[DEBUG setValorSimbolo] Antes: sim->valor.v.i = %d\n", sim->valor.v.i);
        sim->valor = val;
        sim->valor.tipo = sim->tipo;
        sim->valor.inicializado = 1;
        printf("[DEBUG setValorSimbolo] Después: sim->valor.v.i = %d\n", sim->valor.v.i);
        return;
    }

    if (sim->clase == SIMBOLO_VECTOR) {
        printf("[DEBUG setValorSimbolo] ¡OPERACIÓN EN VECTOR '%s'! Tipo: %d->%d\n", 
               sim->nombre, sim->tipo, tipoValor);
    }

    if (sim->clase == SIMBOLO_MATRIZ) {
        printf("[DEBUG setValorSimbolo] ¡OPERACIÓN EN MATRIZ '%s'! Tipo: %d->%d\n", 
               sim->nombre, sim->tipo, tipoValor);
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

ValorSimbolo getValorSimbolo(Simbolo* sim) {
    ValorSimbolo r;
    memset(&r, 0, sizeof(r));
    
    if (!sim) {
        r.tipo = TIPO_DESCONOCIDO;
        r.inicializado = 0;
        return r;
    }
    
    // Copiar tipo e inicialización
    r.tipo = sim->valor.tipo;
    r.inicializado = sim->valor.inicializado;
    
    if (!r.inicializado) {
        printf("[DEBUG] Variable '%s' no está inicializada\n", sim->nombre);
        return r;
    }
    
    // Copiar valor según el tipo
    switch (r.tipo) {
        case TIPO_INT:
            r.v.i = sim->valor.v.i;
            printf("[DEBUG] getValorSimbolo: int = %d\n", r.v.i);
            break;
        case TIPO_FLOAT:
            r.v.f = sim->valor.v.f;
            printf("[DEBUG] getValorSimbolo: float = %f\n", r.v.f);
            break;
        case TIPO_DOUBLE:
            r.v.d = sim->valor.v.d;
            printf("[DEBUG] getValorSimbolo: double = %lf\n", r.v.d);
            break;
        case TIPO_CHAR:
            r.v.c = sim->valor.v.c;
            printf("[DEBUG] getValorSimbolo: char = '%c'\n", r.v.c);
            break;
        case TIPO_BOOLEAN:
            r.v.b = sim->valor.v.b;
            printf("[DEBUG] getValorSimbolo: boolean = %s\n", r.v.b ? "true" : "false");
            break;
        case TIPO_STRING:
            if (sim->valor.v.s) {
                r.v.s = strdup(sim->valor.v.s); // Crear una copia
                printf("[DEBUG] getValorSimbolo: string = '%s'\n", r.v.s);
            } else {
                r.v.s = NULL;
                printf("[DEBUG] getValorSimbolo: string = NULL\n");
            }
            break;
        default:
            printf("[DEBUG] getValorSimbolo: tipo desconocido %d\n", r.tipo);
            r.inicializado = 0;
            break;
    }
    
    return r;
}

void mostrarTablaSimbolos() {
    printf("\n=== Tabla de Símbolos ===\n");
    printf("%-4s %-15s %-25s %-10s %-67s %-10s %-6s %-6s\n",
           "ID", "Nombre", "Clase", "TipoDato", "Valor", "Ambito", "Linea", "Col");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    Simbolo* actual = tabla;

    while (actual) {
        char valor[100] = "(sin valor)";
        
        // Verificar si el símbolo está inicializado
        if (actual->valor.inicializado) {
            // Manejar vectores, matrices y arrays multidimensionales de forma especial
            if (actual->clase == SIMBOLO_VECTOR || actual->clase == SIMBOLO_MATRIZ || actual->clase == SIMBOLO_ARRAY_MULTIDIMENSIONAL) {
                if (actual->valor.v.s != NULL) {
                    // Para vectores, matrices y arrays multidimensionales, mostrar el contenido del string
                    if (strlen(actual->valor.v.s) > 40) {
                        char temp[65];
                        strncpy(temp, actual->valor.v.s, 65);
                        temp[65] = '\0';
                        snprintf(valor, sizeof(valor), "%s...", temp);
                    } else {
                        snprintf(valor, sizeof(valor), "%s", actual->valor.v.s);
                    }
                } else {
                    snprintf(valor, sizeof(valor), "[]");
                }
            } else {
                // Para variables normales, manejar según el tipo
                switch (actual->tipo) {
                    case TIPO_INT:
                        snprintf(valor, sizeof(valor), "%d", actual->valor.v.i);
                        break;
                    case TIPO_FLOAT:
                        snprintf(valor, sizeof(valor), "%.2ff", actual->valor.v.f);
                        break;
                    case TIPO_STRING:
                        if (actual->valor.v.s) {
                            snprintf(valor, sizeof(valor), "\"%s\"", actual->valor.v.s);
                        } else {
                            snprintf(valor, sizeof(valor), "null");
                        }
                        break;
                    case TIPO_DOUBLE:
                        snprintf(valor, sizeof(valor), "%.2lf", actual->valor.v.d);
                        break;
                    case TIPO_CHAR:
                        snprintf(valor, sizeof(valor), "'%c'", actual->valor.v.c);
                        break;
                    case TIPO_BOOLEAN:
                        snprintf(valor, sizeof(valor), "%s", actual->valor.v.b ? "true" : "false");
                        break;
                    default:
                        snprintf(valor, sizeof(valor), "(tipo desconocido)");
                        break;
                }
            }
        }
        
        printf("%-4d %-15s %-25s %-10s %-67s %-10s %-6d %-6d\n",
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
    printf("=========================================================================================================================================================\n");
}

// Agregar a tabla_simbolo.c o crear un archivo nuevo
void asignarValor(Simbolo* simbolo, ValorSimbolo valor) {
    if (!simbolo || !valor.inicializado) return;
    
    // Liberar memoria si ya había un valor string
    if (simbolo->valor.inicializado && simbolo->valor.tipo == TIPO_STRING && simbolo->valor.v.s) {
        free(simbolo->valor.v.s);
        simbolo->valor.v.s = NULL;
    }
    
    // Asignar según el tipo
    switch (simbolo->tipo) {
        case TIPO_INT:
            switch (valor.tipo) {
                case TIPO_INT:    simbolo->valor.v.i = valor.v.i; break;
                case TIPO_FLOAT:  simbolo->valor.v.i = (int)valor.v.f; break;
                case TIPO_DOUBLE: simbolo->valor.v.i = (int)valor.v.d; break;
                case TIPO_CHAR:   simbolo->valor.v.i = (int)valor.v.c; break;
                default: return; // Error de tipo
            }
            break;
        case TIPO_FLOAT:
            switch (valor.tipo) {
                case TIPO_INT:    simbolo->valor.v.f = (float)valor.v.i; break;
                case TIPO_FLOAT:  simbolo->valor.v.f = valor.v.f; break;
                case TIPO_DOUBLE: simbolo->valor.v.f = (float)valor.v.d; break;
                case TIPO_CHAR:   simbolo->valor.v.f = (float)valor.v.c; break;
                default: return; // Error de tipo
            }
            break;
        case TIPO_DOUBLE:
            switch (valor.tipo) {
                case TIPO_INT:    simbolo->valor.v.d = (double)valor.v.i; break;
                case TIPO_FLOAT:  simbolo->valor.v.d = (double)valor.v.f; break;
                case TIPO_DOUBLE: simbolo->valor.v.d = valor.v.d; break;
                case TIPO_CHAR:   simbolo->valor.v.d = (double)valor.v.c; break;
                default: return; // Error de tipo
            }
            break;
        case TIPO_CHAR:
            switch (valor.tipo) {
                case TIPO_CHAR: simbolo->valor.v.c = valor.v.c; break;
                case TIPO_INT:  simbolo->valor.v.c = (char)valor.v.i; break;
                default: return; // Error de tipo
            }
            break;
        case TIPO_BOOLEAN:
            if (valor.tipo == TIPO_BOOLEAN) {
                simbolo->valor.v.b = valor.v.b;
            } else {
                return; // Error de tipo
            }
            break;
        case TIPO_STRING:
            if (valor.tipo == TIPO_STRING && valor.v.s) {
                simbolo->valor.v.s = strdup(valor.v.s);
            } else {
                return; // Error de tipo
            }
            break;
        default:
            return; // Tipo desconocido
    }
    
    simbolo->valor.inicializado = 1;
    simbolo->valor.tipo = simbolo->tipo;
}


void modificarClaseSimbolo(const char* nombre, TipoSimbolo nuevaClase) {
    Simbolo* simbolo = buscarSimbolo(nombre);
    if (simbolo) {
        simbolo->clase = nuevaClase;
        printf("[DEBUG] Modificada clase de símbolo '%s' a %d\n", nombre, nuevaClase);
    }
}

