#include "errorTIpos.h" 
#include "err.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static ErrorSintactico* listaErroresSintacticos = NULL;
static int contadorErroresSintacticos = 0;

void initErroresSintacticos(void) {
    listaErroresSintacticos = NULL;
    contadorErroresSintacticos = 0;
}

static char* dupstr_safe(const char* s) {
    return s ? strdup(s) : strdup("");
}

void addErrorSintactico(TipoErrorSintactico tipo, const char* mensaje, 
                        const char* contexto, const char* sugerencia, 
                        int linea, int columna) {
    ErrorSintactico* nuevo = (ErrorSintactico*)malloc(sizeof(ErrorSintactico));
    nuevo->id = ++contadorErroresSintacticos;
    nuevo->tipo = tipo;
    nuevo->mensaje = dupstr_safe(mensaje);
    nuevo->contexto = dupstr_safe(contexto);
    nuevo->sugerencia = dupstr_safe(sugerencia);
    nuevo->linea = linea;
    nuevo->columna = columna;
    nuevo->sig = listaErroresSintacticos;
    listaErroresSintacticos = nuevo;
}

const char* nombreTipoErrorSintactico(TipoErrorSintactico tipo) {
    switch(tipo) {
        case ERROR_SINTACTICO_GENERAL: return "General";
        case ERROR_SINTACTICO_DECLARACION: return "Declaración";
        case ERROR_SINTACTICO_ASIGNACION: return "Asignación";
        case ERROR_SINTACTICO_PRINT: return "Print";
        case ERROR_SINTACTICO_CAST: return "Cast";
        case ERROR_SINTACTICO_EXPRESION: return "Expresión";
        case ERROR_SINTACTICO_IDENTIFICADOR: return "Identificador";
        case ERROR_SINTACTICO_EOF: return "Fin de Archivo";
        default: return "Desconocido";
    }
}

void mostrarErroresSintacticos(void) {
    if (!listaErroresSintacticos) {
        printf("\n== Sin errores sintácticos ==\n");
        return;
    }
    
    printf("\n== Reporte de Errores Sintácticos ==\n");
    printf("%-3s | %-12s | %-40s | %-15s | %-5s | %-3s | %-30s\n",
           "ID", "Categoría", "Mensaje", "Contexto", "Línea", "Col", "Sugerencia");
    printf("----------------------------------------------------------------------------------------------------\n");
    
    ErrorSintactico* actual = listaErroresSintacticos;
    while (actual) {
        printf("%-3d | %-12s | %-40s | %-15s | %-5d | %-3d | %-30s\n",
               actual->id,
               nombreTipoErrorSintactico(actual->tipo),
               actual->mensaje,
               actual->contexto,
               actual->linea,
               actual->columna,
               actual->sugerencia);
        actual = actual->sig;
    }
    printf("====================================================================================================\n");
}

void mostrarErroresPorCategoria(void) {
    if (!listaErroresSintacticos) {
        printf("\n== Sin errores sintácticos ==\n");
        return;
    }

    printf("\n== Errores Sintácticos por Categoría ==\n");
    
    // ARREGLAR: Cast explícito para evitar warning
    for (TipoErrorSintactico tipoActual = ERROR_SINTACTICO_GENERAL; tipoActual <= ERROR_SINTACTICO_EOF; tipoActual++) {
        int encontrados = 0;
        ErrorSintactico* actual = listaErroresSintacticos;
        
        // Contar errores de este tipo
        while (actual) {
            if (actual->tipo == tipoActual) encontrados++;
            actual = actual->sig;
        }
        
        if (encontrados > 0) {
            printf("\n--- %s (%d errores) ---\n", nombreTipoErrorSintactico(tipoActual), encontrados);
            actual = listaErroresSintacticos;
            while (actual) {
                if (actual->tipo == tipoActual) {
                    printf("  [%d:%d] %s", actual->linea, actual->columna, actual->mensaje);
                    if (strlen(actual->contexto) > 0) printf(" (en: %s)", actual->contexto);
                    if (strlen(actual->sugerencia) > 0) printf(" -> %s", actual->sugerencia);
                    printf("\n");
                }
                actual = actual->sig;
            }
        }
    }
    printf("\n");
}

int hayErroresSintacticos(void) {
    return contadorErroresSintacticos > 0;
}

int hayErroresDeTipo(TipoErrorSintactico tipo) {
    ErrorSintactico* actual = listaErroresSintacticos;
    while (actual) {
        if (actual->tipo == tipo) return 1;
        actual = actual->sig;
    }
    return 0;
}

void liberarErroresSintacticos(void) {
    ErrorSintactico* actual = listaErroresSintacticos;
    while (actual) {
        ErrorSintactico* temp = actual;
        actual = actual->sig;
        free(temp->mensaje);
        free(temp->contexto);
        free(temp->sugerencia);
        free(temp);
    }
    listaErroresSintacticos = NULL;
    contadorErroresSintacticos = 0;
}

const char* nombreTipoError(TipoErrorSintactico tipo) {
    switch(tipo) {
        case ERROR_SINTACTICO_GENERAL: return "Sintáctico General";
        case ERROR_SINTACTICO_DECLARACION: return "Sintáctico Declaración";
        case ERROR_SINTACTICO_ASIGNACION: return "Sintáctico Asignación";
        case ERROR_SINTACTICO_PRINT: return "Sintáctico Print";
        case ERROR_SINTACTICO_CAST: return "Sintáctico Cast";
        case ERROR_SINTACTICO_EXPRESION: return "Sintáctico Expresión";
        case ERROR_SINTACTICO_IDENTIFICADOR: return "Sintáctico Identificador";
        case ERROR_SINTACTICO_EOF: return "Sintáctico EOF";
        case ERROR_SEMANTICO_VARIABLE_NO_DECLARADA: return "Semántico Variable No Declarada";
        case ERROR_SEMANTICO_VARIABLE_YA_DECLARADA: return "Semántico Variable Ya Declarada";
        case ERROR_SEMANTICO_TIPO_INCOMPATIBLE: return "Semántico Tipo Incompatible";
        case ERROR_SEMANTICO_CAST_INVALIDO: return "Semántico Cast Inválido";
        case ERROR_SEMANTICO_OPERACION_INVALIDA: return "Semántico Operación Inválida";
        
        default: return "Desconocido";
    }
}


int hayErroresSemanticos(void) {
    ErrorSintactico* actual = listaErroresSintacticos;
    while (actual) {
        if (actual->tipo >= ERROR_SEMANTICO_VARIABLE_NO_DECLARADA) return 1;
        actual = actual->sig;
    }
    return 0;
}

void mostrarTablaUnificadaErrores(void) {
    // Incluir errores del sistema anterior (err.c)
    extern ErrorSem* lista;  // Necesitas exponerla desde err.c
    extern int contador;
    
    int totalErrores = contadorErroresSintacticos + contador;
    
    if (totalErrores == 0) {
        printf("\n== Sin errores ==\n");
        return;
    }
    
    printf("\n=== REPORTE UNIFICADO DE ERRORES ===\n");
    printf("%-4s | %-20s | %-40s | %-15s | %-5s | %-3s | %-25s\n",
           "ID", "Categoría", "Descripción", "Contexto/Ámbito", "Línea", "Col", "Sugerencia");
    printf("---------------------------------------------------------------------------------------------------------------\n");
    
    int idGlobal = 1;
    
    // 1. Mostrar errores sintácticos (nuevos)
    ErrorSintactico* actualSint = listaErroresSintacticos;
    while (actualSint) {
        printf("%-4d | %-20s | %-40s | %-15s | %-5d | %-3d | %-25s\n",
               idGlobal++,
               nombreTipoErrorSintactico(actualSint->tipo),
               actualSint->mensaje,
               actualSint->contexto,
               actualSint->linea,
               actualSint->columna,
               actualSint->sugerencia);
        actualSint = actualSint->sig;
    }
    
    // 2. Mostrar errores semánticos (sistema anterior)
    ErrorSem* actualSem = lista;
    while (actualSem) {
        printf("%-4d | %-20s | %-40s | %-15s | %-5d | %-3d | %-25s\n",
               idGlobal++,
               "Semántico",
               actualSem->descripcion,
               actualSem->ambito,
               actualSem->linea,
               actualSem->columna,
               "");  // Sin sugerencia en errores antiguos
        actualSem = actualSem->sig;
    }
    
    printf("===============================================================================================================\n");
    printf("Total de errores: %d (Sintácticos: %d, Semánticos: %d)\n", 
           totalErrores, contadorErroresSintacticos, contador);
}