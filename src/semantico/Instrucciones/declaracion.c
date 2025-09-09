#include "declaracion.h"
#include "../tipos.h"
#include "../tabla_simbolo.h"
#include "../semantico.h"
#include "../../AST/err.h"
#include "../../AST/errorTIpos.h"
#include "../../simbolos/Evaluador.h" 
#include "../Vectores/acceso_vector.h"
#include <stdio.h>

const char* nombreTipo(TipoDato tipo);

int verificarDeclaracion(NodoAST* nodo) {
    if (!nodo || nodo->num_hijos < 2) {
        printf("[ERROR] Estructura de nodo de declaración inválida\n");
        return 0;
    }

    NodoAST* identificador = nodo->hijos[0];
    NodoAST* valor = nodo->hijos[1];
    TipoDato tipoDeclarado = obtenerTipoDesdeString(nodo->valor);

    printf("[DEBUG] Declarando '%s': tipo declarado=%s\n",
           identificador->valor, nombreTipo(tipoDeclarado));

    if (buscarSimbolo(identificador->valor)) {
        char msg[128];
        snprintf(msg, sizeof(msg), "Variable '%s' ya declarada", identificador->valor);
        addError(msg, ambitoActual(), identificador->linea, identificador->columna);
        printf("[ERROR] %s\n", msg);
        identificador->valido = 0;
        nodo->valido = 0;
        return 0;
    }

    agregarSimboloDetallado(
        identificador->valor,
        SIMBOLO_VARIABLE,
        tipoDeclarado,
        ambitoActual(),
        identificador->linea,
        identificador->columna
    );

    Simbolo* sim = buscarSimbolo(identificador->valor);
    
    if (sim && nodo->num_hijos > 1) {
        // Verificación para métodos de parseo
        if (valor->tipo == AST_PARSEINT || valor->tipo == AST_PARSEFLOAT || valor->tipo == AST_PARSEDOUBLE) {
            TipoDato tipoParse;
            const char* nombreFuncion;
            
            if (valor->tipo == AST_PARSEINT) {
                tipoParse = TIPO_INT;
                nombreFuncion = "Integer.parseInt";
            } else if (valor->tipo == AST_PARSEFLOAT) {
                tipoParse = TIPO_FLOAT;
                nombreFuncion = "Float.parseFloat";
            } else {
                tipoParse = TIPO_DOUBLE;
                nombreFuncion = "Double.parseDouble";
            }
            
            // Verificar que el tipo de la declaración coincida con el tipo del parse
            if (tipoDeclarado != tipoParse) {
                char msg[200];
                snprintf(msg, sizeof(msg), 
                        "Tipo incompatible: '%s' devuelve %s pero se está asignando a una variable de tipo %s", 
                        nombreFuncion, nombreTipo(tipoParse), nombreTipo(tipoDeclarado));
                addError(msg, ambitoActual(), identificador->linea, identificador->columna);
                printf("[ERROR] %s\n", msg);
                identificador->valido = 0;
                nodo->valido = 0;
                return 0;
            }
            
            printf("[DEBUG] Tipo correcto para %s: %s\n", nombreFuncion, nombreTipo(tipoParse));
            
            // Continuar con la evaluación normal después de verificar el tipo
            ValorSimbolo v = evaluarExpr(valor);
            if(v.inicializado){
                setValorSimbolo(sim, sim->tipo, v);
                
                // Mostrar valor convertido según el tipo
                if (tipoParse == TIPO_INT) {
                    printf("[DEBUG] Variable '%s' inicializada con valor %d\n", identificador->valor, v.v.i);
                } else if (tipoParse == TIPO_FLOAT) {
                    printf("[DEBUG] Variable '%s' inicializada con valor %f\n", identificador->valor, v.v.f);
                } else {
                    printf("[DEBUG] Variable '%s' inicializada con valor %f\n", identificador->valor, v.v.d);
                }
            } else {
                printf("[ERROR] Error al evaluar %s para '%s'\n", nombreFuncion, identificador->valor);
                nodo->valido = 0;
                return 0;
            }
        }
        // Si el valor es un acceso a vector/matriz
        else if (valor->tipo == AST_ACCESO) {
            // Verificar primero que el acceso sea válido
            if (verificarAccesoVector(valor)) {
                // Obtener el símbolo del vector/matriz accedido
                NodoAST* idVectorNodo = valor->hijos[0];
                Simbolo* simboloVector = buscarSimbolo(idVectorNodo->valor);
                
                if (simboloVector) {
                    // Verificar compatibilidad de tipos entre la variable y el tipo del vector
                    if (sim->tipo != simboloVector->tipo) {
                        char msg[200];
                        snprintf(msg, sizeof(msg), 
                                "Tipo incompatible en declaración '%s': el tipo de la variable (%s) no coincide con el tipo del vector '%s' (%s)",
                                identificador->valor, nombreTipo(sim->tipo), 
                                idVectorNodo->valor, nombreTipo(simboloVector->tipo));
                        addError(msg, ambitoActual(), identificador->linea, identificador->columna);
                        printf("[ERROR] %s\n", msg);
                        nodo->valido = 0;
                        return 0;
                    }
                    
                    printf("[DEBUG] Tipos compatibles: variable '%s' (%s) y vector '%s' (%s)\n",
                           identificador->valor, nombreTipo(sim->tipo),
                           idVectorNodo->valor, nombreTipo(simboloVector->tipo));
                }
                
                // Evaluar el acceso para obtener el valor concreto
                ValorSimbolo valorAcceso = evaluarAccesoArrays(valor);
                if (valorAcceso.inicializado) {
                    // Verificar compatibilidad del valor obtenido
                    if (sim->tipo != valorAcceso.tipo && valorAcceso.tipo != TIPO_DESCONOCIDO) {
                        if (!esWidening(valorAcceso.tipo, sim->tipo)) {
                            char msg[200];
                            snprintf(msg, sizeof(msg), 
                                    "Tipo incompatible en declaración '%s': el valor obtenido (%s) no es compatible con el tipo de la variable (%s)",
                                    identificador->valor, nombreTipo(valorAcceso.tipo), nombreTipo(sim->tipo));
                            addError(msg, ambitoActual(), identificador->linea, identificador->columna);
                            printf("[ERROR] %s\n", msg);
                            nodo->valido = 0;
                            return 0;
                        }
                        
                        printf("[DEBUG] Conversión implícita: de %s a %s\n", 
                               nombreTipo(valorAcceso.tipo), nombreTipo(sim->tipo));
                    }
                    
                    // Asignar el valor obtenido
                    setValorSimbolo(sim, sim->tipo, valorAcceso);
                    printf("[DEBUG] Variable '%s' inicializada con valor de acceso a array\n", 
                           identificador->valor);
                } else {
                    printf("[ERROR] No se pudo obtener un valor válido del acceso para inicializar '%s'\n", 
                           identificador->valor);
                    nodo->valido = 0;
                    return 0;
                }
            } else {
                printf("[ERROR] Acceso inválido para inicialización de '%s'\n", identificador->valor);
                nodo->valido = 0;
                return 0;
            }
        } else if (valor->tipo == AST_ADD) {
            // Verifica que haya al menos un hijo (el identificador del array)
            if (valor->num_hijos < 1 || valor->hijos[0]->tipo != AST_IDENTIFICADOR) {
                printf("[ERROR] Estructura inválida para Array.add\n");
                nodo->valido = 0;
                return 0;
            }
            
            // Obtén el identificador del array original
            NodoAST* idArrayNodo = valor->hijos[0];
            Simbolo* simboloArray = buscarSimbolo(idArrayNodo->valor);
            
            if (!simboloArray) {
                printf("[ERROR] Array '%s' no declarado\n", idArrayNodo->valor);
                nodo->valido = 0;
                return 0;
            }
            
            // Verifica que sea realmente un vector
            if (simboloArray->clase != SIMBOLO_VECTOR) {
                printf("[ERROR] '%s' no es un vector\n", idArrayNodo->valor);
                nodo->valido = 0;
                return 0;
            }
            
            // Verifica compatibilidad de tipos
            if (tipoDeclarado != simboloArray->tipo) {
                char msg[200];
                snprintf(msg, sizeof(msg), 
                    "Tipo incompatible en declaración '%s': el método add() de '%s' devuelve %s[] pero se está asignando a %s[]",
                    identificador->valor, idArrayNodo->valor, 
                    nombreTipo(simboloArray->tipo), nombreTipo(tipoDeclarado));
                addError(msg, ambitoActual(), identificador->linea, identificador->columna);
                printf("[ERROR] %s\n", msg);
                nodo->valido = 0;
                return 0;
            }
            
            printf("[DEBUG] Tipos compatibles: nuevo vector '%s' (%s[]) y vector original '%s' (%s[])\n",
                identificador->valor, nombreTipo(tipoDeclarado),
                idArrayNodo->valor, nombreTipo(simboloArray->tipo));
            
            // Evalúa la expresión para obtener el nuevo array
            ValorSimbolo nuevoArray = evaluarExpr(valor);
            if (nuevoArray.inicializado) {
                // Actualiza el tipo de símbolo a VECTOR para que se maneje correctamente
                modificarClaseSimbolo(identificador->valor, SIMBOLO_VECTOR);
                
                // Asigna el valor (formato del array como string)
                setValorSimbolo(sim, sim->tipo, nuevoArray);
                
                printf("[DEBUG] Vector '%s' inicializado con el resultado de '%s.add()': %s\n",
                    identificador->valor, idArrayNodo->valor, 
                    nuevoArray.v.s ? nuevoArray.v.s : "(formato inválido)");
            } else {
                printf("[ERROR] Error al evaluar Array.add para '%s'\n", identificador->valor);
                nodo->valido = 0;
                return 0;
            }
        }else {
            // Caso normal (expresión)
            ValorSimbolo v = evaluarExpr(valor);
            if(v.inicializado){
                // Compara el tipo declarado con el tipo evaluado
                if (sim->tipo != v.tipo && v.tipo != TIPO_DESCONOCIDO) {
                    if (!esWidening(v.tipo, sim->tipo)) {
                        char msg[160];
                        snprintf(msg, sizeof(msg), "Tipo incompatible en declaración '%s': %s vs %s",
                                identificador->valor, nombreTipo(sim->tipo), nombreTipo(v.tipo));
                        addError(msg, ambitoActual(), identificador->linea, identificador->columna);
                        printf("[ERROR] %s\n", msg);
                        valor->valido = 0;
                        nodo->valido = 0;
                        return 0;
                    }
                    
                    printf("[DEBUG] Conversión implícita en asignación: de %s a %s\n", 
                           nombreTipo(v.tipo), nombreTipo(sim->tipo));
                }
                
                setValorSimbolo(sim, sim->tipo, v);
                
                // Mostrar valor según el tipo
                if (sim->tipo == TIPO_INT) {
                    printf("[DEBUG] Variable '%s' inicializada con valor %d\n", identificador->valor, v.v.i);
                } else if (sim->tipo == TIPO_FLOAT) {
                    printf("[DEBUG] Variable '%s' inicializada con valor %f\n", identificador->valor, v.v.f);
                } else if (sim->tipo == TIPO_DOUBLE) {
                    printf("[DEBUG] Variable '%s' inicializada con valor %f\n", identificador->valor, v.v.d);
                } else if (sim->tipo == TIPO_CHAR) {
                    printf("[DEBUG] Variable '%s' inicializada con valor '%c'\n", identificador->valor, v.v.c);
                } else if (sim->tipo == TIPO_BOOLEAN) {
                    printf("[DEBUG] Variable '%s' inicializada con valor %s\n", 
                           identificador->valor, v.v.b ? "true" : "false");
                } else if (sim->tipo == TIPO_STRING) {
                    printf("[DEBUG] Variable '%s' inicializada con valor \"%s\"\n", 
                           identificador->valor, v.v.s ? v.v.s : "(null)");
                } else {
                    printf("[DEBUG] Variable '%s' inicializada con valor (tipo desconocido)\n", identificador->valor);
                }
            } else {
                printf("[ERROR] Expresión no inicializada para '%s'\n", identificador->valor);
                nodo->valido = 0;
                return 0;
            }
        }
    }
    
    return 1;
}