#include "declaracion_vector.h"
#include "../tipos.h"
#include "../tabla_simbolo.h"
#include "../semantico.h"
#include "../../AST/err.h"
#include "../../AST/errorTIpos.h"
#include "../../simbolos/Evaluador.h" 
#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

int verificarDeclaracionVector(NodoAST* nodo) {
    printf("[DEBUG verificarDeclaracionVector] Iniciando verificación\n");
    
    // Verificar que el nodo no sea NULL
    if (!nodo) {
        printf("[ERROR] Nodo es NULL\n");
        return 0;
    }
    
    // Verificar que tenga suficientes hijos (mínimo 3)
    if (nodo->num_hijos < 3) {
        printf("[ERROR] Nodo no tiene suficientes hijos: %d\n", nodo->num_hijos);
        return 0;
    }
    
    NodoAST* tipo = nodo->hijos[0]; // El tipo está en el primer hijo
    NodoAST* identificador = nodo->hijos[1]; // El identificador está en el segundo hijo
    NodoAST* tercer_nodo = nodo->hijos[2]; // Puede ser tipoNew o lista de elementos
    
    // Verificar que los nodos no sean NULL
    if (!tipo || !identificador || !tercer_nodo) {
        printf("[ERROR] Alguno de los nodos hijo es NULL\n");
        return 0;
    }
    
    // Verificar que los valores no sean NULL
    if (!tipo->valor || !identificador->valor) {
        printf("[ERROR] Valor de tipo o identificador es NULL\n");
        return 0;
    }

    TipoDato tipoDeclarado = obtenerTipoDesdeString(tipo->valor);

    printf("[DEBUG] Declarando vector '%s': tipo declarado=%s\n",
           identificador->valor, nombreTipo(tipoDeclarado));

    // Verificar si el identificador ya está declarado
    if (tercer_nodo->tipo == AST_LISTA_ELEMENTOS) {
        // Caso: Declaración con lista de elementos directamente
        printf("[DEBUG] Procesando vector con lista de elementos\n");
        NodoAST* contenido = tercer_nodo;

        // Verificar si el contenido tiene una lista anidada
        NodoAST* listaReal = NULL;
        int numElementos = 0;
        
        // Buscar dónde están realmente los elementos
        if (contenido->num_hijos == 1 && contenido->hijos[0]->tipo == AST_LISTA_ELEMENTOS) {
            // La lista real está en el primer hijo
            listaReal = contenido->hijos[0];
        } else if (contenido->num_hijos == 1 && contenido->hijos[0]->tipo == AST_INTERNO) {
            // Posiblemente sea una lista de elementos interna
            listaReal = contenido->hijos[0];
        } else {
            // Los elementos están directamente como hijos
            listaReal = contenido;
        }
        
        // Buscar recursivamente el nivel donde están los elementos reales
        while (listaReal->num_hijos == 1 && 
              (listaReal->hijos[0]->tipo == AST_LISTA_ELEMENTOS || 
               listaReal->hijos[0]->tipo == AST_INTERNO)) {
            listaReal = listaReal->hijos[0];
        }
        
        numElementos = listaReal->num_hijos;
        printf("[DEBUG] Encontrados %d elementos en la lista\n", numElementos);
        
        char* valores = malloc(numElementos * 32 + 1); // Espacio para los valores y separadores
        if (!valores) {
            printf("[ERROR] No se pudo asignar memoria para el vector '%s'\n", identificador->valor);
            return 0;
        }
        valores[0] = '\0';

        // Usar un depurador más detallado para ver qué contiene cada elemento
        for (int i = 0; i < numElementos; i++) {
            NodoAST* elemento = listaReal->hijos[i];
            printf("[DEBUG] Evaluando elemento %d tipo=%d valor=%s\n", 
                   i, elemento->tipo, elemento->valor ? elemento->valor : "NULL");
            
            // Para números literales, usar directamente el valor
            if (elemento->tipo == AST_NUMERO && elemento->valor) {
                // Convertir el valor directamente según el tipo
                switch (tipoDeclarado) {
                    case TIPO_INT: {
                        int val = atoi(elemento->valor);
                        char buffer[16];
                        snprintf(buffer, sizeof(buffer), "%d", val);
                        strcat(valores, buffer);
                        break;
                    }
                    case TIPO_FLOAT:
                    case TIPO_DOUBLE: {
                        double val = atof(elemento->valor);
                        char buffer[32];
                        snprintf(buffer, sizeof(buffer), "%f", val);
                        strcat(valores, buffer);
                        break;
                    }
                    case TIPO_CHAR:
                    case TIPO_BOOLEAN:
                    default: {
                        strcat(valores, elemento->valor);
                        break;
                    }
                }
            } else {
                // Para expresiones más complejas, usar evaluarExpr
                ValorSimbolo valorElemento = evaluarExpr(elemento);
                
                if (!valorElemento.inicializado) {
                    printf("[ERROR] Elemento %d no está inicializado\n", i);
                    // Intentemos obtener más información para depurar
                    printf("[DEBUG] Tipo del elemento: %d, Valor: %s\n", 
                           elemento->tipo, elemento->valor ? elemento->valor : "NULL");
                    nodo->valido = 0;
                    free(valores);
                    return 0;
                }
                
                char buffer[32];
                switch (tipoDeclarado) {
                    case TIPO_INT:
                        snprintf(buffer, sizeof(buffer), "%d", valorElemento.v.i);
                        break;
                    case TIPO_FLOAT:
                        snprintf(buffer, sizeof(buffer), "%f", valorElemento.v.f);
                        break;
                    case TIPO_DOUBLE:
                        snprintf(buffer, sizeof(buffer), "%lf", valorElemento.v.d);
                        break;
                    case TIPO_CHAR:
                        snprintf(buffer, sizeof(buffer), "%c", valorElemento.v.c);
                        break;
                    case TIPO_BOOLEAN:
                        snprintf(buffer, sizeof(buffer), "%s", valorElemento.v.b ? "true" : "false");
                        break;
                    default:
                        snprintf(buffer, sizeof(buffer), "?");
                        break;
                }
                strcat(valores, buffer);
            }
            
            if (i < numElementos - 1) strcat(valores, ",");
        }

        // Agregar el símbolo a la tabla
        char formatoCompleto[numElementos * 32 + 64];
        snprintf(formatoCompleto, sizeof(formatoCompleto), "[%s]", valores);
        
        // Agregar el símbolo a la tabla
        printf("[DEBUG] Agregando vector '%s' a la tabla de símbolos con formato: %s\n", 
               identificador->valor, formatoCompleto);
               
        agregarSimboloDetallado(
            identificador->valor,
            SIMBOLO_VECTOR,
            tipoDeclarado,
            ambitoActual(),
            identificador->linea,
            identificador->columna
        );

        Simbolo* simbolo = buscarSimbolo(identificador->valor);
        if (simbolo) {
            simbolo->valor.v.s = strdup(formatoCompleto);
            simbolo->valor.inicializado = 1;
            simbolo->valor.tipo = TIPO_STRING;

            printf("[DEBUG] Vector '%s' inicializado con lista de elementos: %s\n",
                identificador->valor, simbolo->valor.v.s);
        }

        free(valores);
    } else if (nodo->num_hijos >= 4) {
        // Caso: Declaración con 'new'
        NodoAST* tipoNew = tercer_nodo; // Tercer hijo es el tipo después de `new`
        NodoAST* contenido = nodo->hijos[3]; // Cuarto hijo es el contenido
        
        // Verificar que el tipo declarado coincida con el tipo después de `new`
        TipoDato tipoNewEnum = obtenerTipoDesdeString(tipoNew->valor);
        if (tipoDeclarado != tipoNewEnum) {
            char msg[128];
            snprintf(msg, sizeof(msg), "El tipo '%s' en 'new' no coincide con el tipo declarado '%s' en '%s'",
                     nombreTipo(tipoNewEnum), nombreTipo(tipoDeclarado), identificador->valor);
            addError(msg, ambitoActual(), tipoNew->linea, tipoNew->columna);
            printf("[ERROR] %s\n", msg);
            nodo->valido = 0;
            return 0;
        }

        printf("[DEBUG] Tipos coinciden: '%s' == '%s'\n", nombreTipo(tipoDeclarado), nombreTipo(tipoNewEnum));

        if (contenido->tipo == AST_1DIMENSION) {
            printf("[DEBUG] Procesando vector con dimensión (new)\n");

            // Verificar que tenga al menos un hijo
            if (contenido->num_hijos < 1) {
                printf("[ERROR] Nodo de dimensión no tiene hijos\n");
                return 0;
            }

            NodoAST* dimension = contenido->hijos[0]; // La dimensión está en el primer hijo de AST_1DIMENSION

            // Verificar que la dimensión sea válida
            TipoDato tipoDimension = deducirTipoExpr(dimension);
            if (tipoDimension != TIPO_INT) {
                char msg[128];
                snprintf(msg, sizeof(msg), "Dimensión de vector '%s' debe ser de tipo int, no %s", 
                         identificador->valor, nombreTipo(tipoDimension));
                addError(msg, ambitoActual(), dimension->linea, dimension->columna);
                printf("%s\n", msg);
                dimension->valido = 0;
                nodo->valido = 0;
                return 0;
            }

            ValorSimbolo valorDimension = evaluarExpr(dimension);
            if (!valorDimension.inicializado || valorDimension.v.i <= 0) {
                char msg[128];
                snprintf(msg, sizeof(msg), "Dimensión de vector '%s' debe ser mayor a 0", identificador->valor);
                addError(msg, ambitoActual(), dimension->linea, dimension->columna);
                printf("%s\n", msg);
                dimension->valido = 0;
                nodo->valido = 0;
                return 0;
            }

            // Agregar el símbolo a la tabla
            agregarSimboloDetallado(
                identificador->valor,
                SIMBOLO_VECTOR,
                tipoDeclarado,
                ambitoActual(),
                identificador->linea,
                identificador->columna
            );

            // Inicializar el vector con valores por defecto
            Simbolo* simbolo = buscarSimbolo(identificador->valor);
            if (simbolo) {
                int dimension_size = valorDimension.v.i;
                size_t buffer_size = (size_t)(dimension_size * 16 + 1); // +1 para el carácter nulo
                char* valores = malloc(buffer_size);

                if (!valores) {
                    printf("[ERROR] No se pudo asignar memoria para el vector '%s'\n", identificador->valor);
                    return 0;
                }

                valores[0] = '\0'; // Inicializa la cadena vacía

                // Inicializar todos los elementos con el valor por defecto según el tipo
                for (int i = 0; i < dimension_size; i++) {
                    char buffer[16];
                    switch (tipoDeclarado) {
                        case TIPO_INT:
                            snprintf(buffer, sizeof(buffer), "0");
                            break;
                        case TIPO_FLOAT:
                            snprintf(buffer, sizeof(buffer), "0.0");
                            break;
                        case TIPO_DOUBLE:
                            snprintf(buffer, sizeof(buffer), "0.0");
                            break;
                        case TIPO_CHAR:
                            snprintf(buffer, sizeof(buffer), "\\0");
                            break;
                        case TIPO_BOOLEAN:
                            snprintf(buffer, sizeof(buffer), "false");
                            break;
                        default:
                            snprintf(buffer, sizeof(buffer), "0");
                            break;
                    }
                    strcat(valores, buffer);
                    if (i < dimension_size - 1) strcat(valores, ",");
                }

                char formatoCompleto[buffer_size + 64];
                snprintf(formatoCompleto, sizeof(formatoCompleto), "[%s]", valores);
                
                simbolo->valor.v.s = strdup(formatoCompleto); // Usar el formato con dimensiones
                simbolo->valor.inicializado = 1;
                simbolo->valor.tipo = TIPO_STRING;

                printf("[DEBUG] Vector '%s' inicializado con %d elementos: %s\n",
                    identificador->valor, dimension_size, simbolo->valor.v.s);

                free(valores);
            }
        } else {
            printf("[ERROR] Tipo de contenido de vector desconocido: %d\n", contenido->tipo);
            return 0;
        }
    } else {
        printf("[ERROR] Estructura AST no reconocida para declaración de vector\n");
        return 0;
    }

    printf("[DEBUG verificarDeclaracionVector] Finalizando verificación exitosamente\n");
    return 1;
}