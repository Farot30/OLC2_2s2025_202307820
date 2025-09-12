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
    nuevo->valor.tipo = tipo;
    nuevo->valor.inicializado = 0;

    switch(tipo){
        case TIPO_INT:    nuevo->valor.v.i = 0; break;
        case TIPO_FLOAT:  nuevo->valor.v.f = 0.0f; break;
        case TIPO_DOUBLE: nuevo->valor.v.d = 0.0; break;
        case TIPO_CHAR:   nuevo->valor.v.c = '\0'; break;
        case TIPO_BOOLEAN:nuevo->valor.v.b = 0; break;
        case TIPO_STRING: nuevo->valor.v.s = NULL; break;
        case TIPO_VOID:  nuevo->valor.v.s = NULL; break;
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

ValorSimbolo getValorSimbolo(Simbolo* sim){
    ValorSimbolo dummy = { .tipo = TIPO_DESCONOCIDO, .inicializado = 0 };
    if(!sim) return dummy;
    return sim->valor;
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


void asignarElementoArrayMultidimensional(Simbolo* simbolo, int* indices, int numIndices, ValorSimbolo valor) {
    if (!simbolo || simbolo->clase != SIMBOLO_ARRAY_MULTIDIMENSIONAL || !simbolo->valor.inicializado) {
        printf("[ERROR] Símbolo no es un array multidimensional inicializado\n");
        return;
    }
    
    // Extraer la representación del array
    char* arrayStr = strdup(simbolo->valor.v.s);
    if (!arrayStr) return;
    
    // Verificar formato: [dim1,dim2,...,dimN][valor]
    char* dimensionesEnd = strchr(arrayStr, ']');
    if (!dimensionesEnd) {
        free(arrayStr);
        return;
    }
    
    // Obtener dimensiones
    char dimensiones[128];
    strncpy(dimensiones, arrayStr + 1, dimensionesEnd - arrayStr - 1);
    dimensiones[dimensionesEnd - arrayStr - 1] = '\0';
    
    // Parsear dimensiones
    int dimsArray[10] = {0}; // Máximo 10 dimensiones
    int numDims = 0;
    
    char* dimToken = strtok(dimensiones, ",");
    while (dimToken && numDims < 10) {
        dimsArray[numDims++] = atoi(dimToken);
        dimToken = strtok(NULL, ",");
    }
    
    // Verificar que el número de índices sea correcto
    if (numIndices != numDims) {
        printf("[ERROR] Número incorrecto de índices: %d (esperado: %d)\n", 
               numIndices, numDims);
        free(arrayStr);
        return;
    }
    
    // Verificar que los índices estén dentro de los límites
    for (int i = 0; i < numIndices; i++) {
        if (indices[i] < 0 || indices[i] >= dimsArray[i]) {
            printf("[ERROR] Índice %d fuera de rango: %d (límite: 0-%d)\n", 
                   i, indices[i], dimsArray[i]-1);
            free(arrayStr);
            return;
        }
    }
    
    // Para arrays multidimensionales, necesitamos calcular la posición lineal
    int posicionLineal = 0;
    int multiplicador = 1;
    
    // Calcular desde la dimensión más interna hacia afuera
    for (int i = numIndices - 1; i >= 0; i--) {
        posicionLineal += indices[i] * multiplicador;
        multiplicador *= dimsArray[i];
    }
    
    // Encontrar el inicio de los datos
    char* datosInicio = strstr(arrayStr, "][") + 2;
    if (!datosInicio) {
        free(arrayStr);
        return;
    }
    
    // Eliminar el último corchete
    int longitud = strlen(datosInicio);
    if (longitud > 0 && datosInicio[longitud-1] == ']') {
        datosInicio[longitud-1] = '\0';
    }
    
    // Separar los elementos por comas
    char* elementos[10000]; // Un límite grande para arrays multidimensionales
    int numElementos = 0;
    
    // Copia para tokenizar
    char* datosCopia = strdup(datosInicio);
    
    char* elemento = strtok(datosCopia, ",");
    while (elemento && numElementos < 10000) {
        elementos[numElementos++] = strdup(elemento);
        elemento = strtok(NULL, ",");
    }
    
    // Verificar que la posición lineal sea válida
    if (posicionLineal >= numElementos) {
        printf("[ERROR] Posición %d fuera de rango (0-%d)\n", posicionLineal, numElementos-1);
        free(arrayStr);
        free(datosCopia);
        for (int i = 0; i < numElementos; i++) {
            free(elementos[i]);
        }
        return;
    }
    
    // Convertir el nuevo valor a string según el tipo
    char nuevoValorStr[64];
    switch (simbolo->tipo) {
        case TIPO_INT:
            sprintf(nuevoValorStr, "%d", valor.v.i);
            break;
        case TIPO_FLOAT:
            sprintf(nuevoValorStr, "%f", valor.v.f);
            break;
        case TIPO_DOUBLE:
            sprintf(nuevoValorStr, "%lf", valor.v.d);
            break;
        case TIPO_CHAR:
            sprintf(nuevoValorStr, "%c", valor.v.c);
            break;
        case TIPO_BOOLEAN:
            sprintf(nuevoValorStr, "%s", valor.v.b ? "true" : "false");
            break;
        case TIPO_STRING:
            if (valor.v.s)
                strncpy(nuevoValorStr, valor.v.s, sizeof(nuevoValorStr)-1);
            else
                strcpy(nuevoValorStr, "");
            nuevoValorStr[sizeof(nuevoValorStr)-1] = '\0';
            break;
        default:
            strcpy(nuevoValorStr, "");
            break;
    }
    
    // Reemplazar el valor en la posición correspondiente
    free(elementos[posicionLineal]);
    elementos[posicionLineal] = strdup(nuevoValorStr);
    
    // Reconstruir el array completo
    char nuevoArray[10240]; // Buffer grande para arrays grandes
    
    // Copiar la parte de dimensiones
    char* primeraParte = strndup(arrayStr, dimensionesEnd - arrayStr + 1);
    strcpy(nuevoArray, primeraParte);
    free(primeraParte);
    
    // Añadir corchete de inicio de datos
    strcat(nuevoArray, "[");
    
    // Añadir todos los elementos
    for (int i = 0; i < numElementos; i++) {
        strcat(nuevoArray, elementos[i]);
        if (i < numElementos - 1) {
            strcat(nuevoArray, ",");
        }
    }
    
    // Cerrar corchete de datos
    strcat(nuevoArray, "]");
    
    // Actualizar el valor en el símbolo
    if (simbolo->valor.v.s) {
        free(simbolo->valor.v.s);
    }
    simbolo->valor.v.s = strdup(nuevoArray);
    simbolo->valor.inicializado = 1;
    
    // Construir una descripción de los índices para el mensaje de debug
    char indicesStr[128] = "";
    for (int i = 0; i < numIndices; i++) {
        char temp[16];
        sprintf(temp, "[%d]", indices[i]);
        strcat(indicesStr, temp);
    }
    
    printf("[DEBUG] Array '%s%s' actualizado, valor = %s\n", 
           simbolo->nombre, indicesStr, nuevoValorStr);
    
    // Limpiar memoria
    free(arrayStr);
    free(datosCopia);
    for (int i = 0; i < numElementos; i++) {
        free(elementos[i]);
    }
}