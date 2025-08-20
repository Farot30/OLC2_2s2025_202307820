#ifndef ERROR_TYPES_H
#define ERROR_TYPES_H

typedef enum {
    // Errores sintácticos
    ERROR_SINTACTICO_GENERAL,
    ERROR_SINTACTICO_DECLARACION,
    ERROR_SINTACTICO_ASIGNACION,
    ERROR_SINTACTICO_PRINT,
    ERROR_SINTACTICO_CAST,
    ERROR_SINTACTICO_EXPRESION,
    ERROR_SINTACTICO_IDENTIFICADOR,
    ERROR_SINTACTICO_EOF,
    
    // Errores semánticos
    ERROR_SEMANTICO_VARIABLE_NO_DECLARADA,
    ERROR_SEMANTICO_VARIABLE_YA_DECLARADA,
    ERROR_SEMANTICO_TIPO_INCOMPATIBLE,
    ERROR_SEMANTICO_CAST_INVALIDO,
    ERROR_SEMANTICO_OPERACION_INVALIDA
} TipoErrorSintactico;  // <- CAMBIAR a este nombre

typedef struct ErrorSintactico {  // <- CAMBIAR a este nombre
    int id;
    TipoErrorSintactico tipo;  // <- CAMBIAR a este nombre
    char* mensaje;
    char* contexto;
    char* sugerencia;
    int linea;
    int columna;
    struct ErrorSintactico* sig;  // <- CAMBIAR a este nombre
} ErrorSintactico;  // <- CAMBIAR a este nombre

// Funciones para el sistema de errores sintácticos
void initErroresSintacticos(void);
void addErrorSintactico(TipoErrorSintactico tipo, const char* mensaje, 
                        const char* contexto, const char* sugerencia, 
                        int linea, int columna);
void mostrarErroresSintacticos(void);
void mostrarErroresPorCategoria(void);
int hayErroresSintacticos(void);
int hayErroresDeTipo(TipoErrorSintactico tipo);
void liberarErroresSintacticos(void);
const char* nombreTipoErrorSintactico(TipoErrorSintactico tipo);

void mostrarTablaUnificadaErrores(void);

#endif