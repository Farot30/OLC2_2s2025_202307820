%code requires {
    #include "../AST/ast.h"
    #include "../AST/errorTIpos.h" 
    #include "../semantico/Instrucciones/Print.h"
    #include "../AST/ejecutar_ast.h"
}

%define parse.error verbose
%locations

%{
    #include "../comun/strutil.h"
    #include <stdio.h>
    #include <string.h>
    #include "../semantico/semantico.h"
    #include "../AST/err.h"  
    #include "../AST/errorTIpos.h" 
    void yyerror(const char *s);
    extern int yylex(void);
    extern int yylineno;
    extern int yycolumn;
    
    /* Función auxiliar para crear asignaciones compuestas */
    NodoAST* crear_asignacion_compuesta(char* id, char* operador, NodoAST* expr, 
                                       int id_linea, int id_columna, int op_linea, int op_columna);
%}

%union {
    char* str;
    NodoAST* nodo;
}

/* ========== TOKENS ========== */
%token <str> TOKEN_LLAVEDER TOKEN_LLAVEIZQ TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_NEW
%token <str> TOKEN_MULTI TOKEN_DIV TOKEN_MODULO TOKEN_MAS TOKEN_MENOS TOKEN_INCREMENTO TOKEN_DECREMENTO
%token <str> TOKEN_DBOOLEAN TOKEN_BOOLEANO
%token <str> TOKEN_IDENTIFICADOR
%token <str> TOKEN_DINT TOKEN_DFLOAT TOKEN_DSTRING TOKEN_DCHAR TOKEN_DOUBLE
%token <str> TOKEN_IGUAL TOKEN_PUNTOCOMA TOKEN_DOS_PUNTOS TOKEN_COMA
%token <str> TOKEN_NUMERO TOKEN_CADENA TOKEN_CARACTER
%token <str> TOKEN_FLOAT_LITERAL TOKEN_DOUBLE_LITERAL 
%token <str> TOKEN_PRINT
%token <str> TOKEN_PARIZQ TOKEN_PARDER
%token <str> TOKEN_BIT_AND TOKEN_BIT_OR TOKEN_XOR
%token <str> TOKEN_DESIZQ TOKEN_DESDER
%token <str> TOKEN_IGUAL_IGUAL TOKEN_NO_IGUAL
%token <str> TOKEN_MAYOR_IGUAL TOKEN_MENOR_IGUAL
%token <str> TOKEN_MAYOR TOKEN_MENOR
%token <str> TOKEN_AND TOKEN_OR TOKEN_NOT
%token <str> TOKEN_IF TOKEN_ELSE
%token <str> TOKEN_SWITCH TOKEN_CASE TOKEN_DEFAULT TOKEN_BREAK
%token <str> TOKEN_WHILE TOKEN_CONTINUE
%token <str> TOKEN_FOR
%token <str> TOKEN_STRING_VALUEOF TOKEN_EQUAL

/* Tokens para asignaciones compuestas */
%token <str> TOKEN_MAS_IGUAL TOKEN_MENOS_IGUAL TOKEN_POR_IGUAL
%token <str> TOKEN_DIV_IGUAL TOKEN_MOD_IGUAL
%token <str> TOKEN_AND_IGUAL TOKEN_OR_IGUAL TOKEN_XOR_IGUAL
%token <str> TOKEN_DESIZQ_IGUAL TOKEN_DESDER_IGUAL

/* ========== TIPOS DE NODOS ========== */
%type <nodo> s programa
%type <nodo> lista_sentencias sentencia
%type <nodo> declaracion asignacion declaracion_vector declaracion_matriz 
%type <nodo> declaracion_array_multidimensional Dimensiones lista_bloques lista_filas lista_elementos DimensionesCorchetes
%type <nodo> expresion expresion_or expresion_and expresion_bit_or expresion_bit_xor 
%type <nodo> expresion_bit_and expresion_equality expresion_relacional expresion_shift 
%type <nodo> expresion_aditiva expresion_multiplicativa expresion_unaria postfix primary
%type <nodo> instruccion_print instruccion_if bloque
%type <nodo> intruccion_switch lista_casos caso
%type <nodo> instruccion_while instruccion_break instruccion_continue
%type <nodo> instruccion_for
%type <str> tipo_primitivo

/* ========== PRECEDENCIA CORREGIDA ========== */
%right TOKEN_IGUAL TOKEN_MAS_IGUAL TOKEN_MENOS_IGUAL TOKEN_POR_IGUAL TOKEN_DIV_IGUAL TOKEN_MOD_IGUAL 
%right TOKEN_AND_IGUAL TOKEN_OR_IGUAL TOKEN_XOR_IGUAL TOKEN_DESIZQ_IGUAL TOKEN_DESDER_IGUAL
%left TOKEN_OR                          /* || - menor precedencia */
%left TOKEN_AND                         /* && */
%left TOKEN_BIT_OR                      /* | */
%left TOKEN_XOR                         /* ^ */
%left TOKEN_BIT_AND                     /* & */
%left TOKEN_IGUAL_IGUAL TOKEN_NO_IGUAL  /* == != */
%left TOKEN_MENOR TOKEN_MENOR_IGUAL TOKEN_MAYOR TOKEN_MAYOR_IGUAL  /* < <= > >= */
%left TOKEN_DESIZQ TOKEN_DESDER         /* << >> */
%left TOKEN_MAS TOKEN_MENOS             /* + - */
%left TOKEN_MULTI TOKEN_DIV TOKEN_MODULO /* * / % */
%right TOKEN_NOT UMINUS                 /* ! - (unario) */
%left TOKEN_EQUAL                       /* .equals() */%nonassoc TOKEN_IF
%nonassoc TOKEN_ELSE
%start s

%%

/* ========== PROGRAMA PRINCIPAL ========== */
s: programa {
    printf("\n=== ESTRUCTURA DEL AST ===\n");
    imprimirAST($1, 0);
    interpretarPrograma($1);
    printf("ejecutando exportarAST\n");
    exportarAST($1, "ast.dot", "ast.png");
    printf("\n=== LIBERANDO MEMORIA ===\n");
    liberarAST($1);
    printf("[DEBUG] Procesamiento completado.\n");
}
;

programa: lista_sentencias { $$ = $1; }
;

/* ========== LISTA DE SENTENCIAS ========== */
lista_sentencias: 
    lista_sentencias sentencia { 
        if ($1->tipo != AST_LISTA) {
            NodoAST* lista = crearNodo(AST_LISTA, "Programa");
            agregarHijo(lista, $1);
            if ($2) agregarHijo(lista, $2);
            $$ = lista;
        } else {
            if ($2) agregarHijo($1, $2);
            $$ = $1;
        }
    }
    | sentencia { 
        if ($1) {
            $$ = $1;
        } else {
            $$ = crearNodo(AST_LISTA, "Programa");
        }
    }
;

/* ========== SENTENCIAS ========== */
sentencia:
    declaracion TOKEN_PUNTOCOMA     { $$ = $1; }
    | asignacion TOKEN_PUNTOCOMA    { $$ = $1; }
    | instruccion_print TOKEN_PUNTOCOMA { $$ = $1; }
    | instruccion_if                { $$ = $1; }
    | intruccion_switch             { $$ = $1; }
    | instruccion_while             { $$ = $1; }
    | instruccion_for               { $$ = $1; }
    | declaracion_vector TOKEN_PUNTOCOMA      { $$ = $1; }
    | declaracion_matriz TOKEN_PUNTOCOMA      { $$ = $1; }
    | declaracion_array_multidimensional TOKEN_PUNTOCOMA { $$ = $1; }
    | bloque                        { $$ = $1; }
    | expresion TOKEN_PUNTOCOMA     { $$ = $1; }
    | instruccion_break TOKEN_PUNTOCOMA {$$ = $1; }
    | instruccion_continue TOKEN_PUNTOCOMA {$$ = $1; }

    | error TOKEN_PUNTOCOMA         { 
        addErrorSintactico("Instrucción inválida", "global", @1.first_line, @1.first_column);
        yyerrok; 
        $$ = NULL;
    }
;

/* ========== DECLARACIONES ========== */
declaracion:
    tipo_primitivo TOKEN_IDENTIFICADOR TOKEN_IGUAL expresion {
        $$ = crearNodo(AST_DECLARACION, NULL);
        $$->valor = strdup($1);
        $$->linea = @2.first_line; 
        $$->columna = @2.first_column;
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, $2);
        id->linea = @2.first_line; // Cambia @3 a @2
        id->columna = @2.first_column;
        agregarHijo($$, id);
        agregarHijo($$, $4);
    }
    | tipo_primitivo TOKEN_IDENTIFICADOR {
        $$ = crearNodo(AST_DECLARACION, NULL);
        $$->valor = strdup($1);
        $$->linea = @2.first_line; 
        $$->columna = @2.first_column;
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, $2);
        id->linea = @2.first_line; // Cambia @3 a @2
        id->columna = @2.first_column;
        NodoAST* def = crearNodo(AST_CADENA, (char*)valorPorDefectoTipo(obtenerTipoDesdeString($1)));
        agregarHijo($$, id);
        agregarHijo($$, def);
    }
;

declaracion_vector:
    tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_NEW tipo_primitivo TOKEN_CORCHETEIZQ expresion TOKEN_CORCHETEDER {
        $$ = crearNodo(AST_DECLARACION_VECTOR, "Declaración Vector");
        $$->linea = @4.first_line; $$->columna = @4.first_column;
        agregarHijo($$, crearNodo(AST_TIPO, $1));
        agregarHijo($$, crearNodo(AST_IDENTIFICADOR, $4));
        agregarHijo($$, $9); // Dimensión
    }
    | tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_LLAVEIZQ lista_elementos TOKEN_LLAVEDER{
        $$ = crearNodo(AST_DECLARACION_VECTOR, "Declaración Vector");
        $$->linea = @4.first_line; $$->columna = @4.first_column;
        agregarHijo($$, crearNodo(AST_TIPO, $1));
        agregarHijo($$, crearNodo(AST_IDENTIFICADOR, $4));
        agregarHijo($$, $7); // lista_elementos
    }
;

lista_elementos:
    lista_elementos TOKEN_COMA expresion {
        if ($1->tipo != AST_INTERNO) {
            NodoAST* lista = crearNodo(AST_INTERNO, "Lista Elementos");
            agregarHijo(lista, $1);
            agregarHijo(lista, $3);
            $$ = lista;
        } else {
            agregarHijo($1, $3);
            $$ = $1;
        }
    }
    | expresion {
        $$ = crearNodo(AST_INTERNO, "Lista Elementos");
        agregarHijo($$, $1);
    }
;

lista_filas:
    lista_filas TOKEN_COMA TOKEN_LLAVEIZQ lista_elementos TOKEN_LLAVEDER {
        if ($1->tipo != AST_INTERNO) {
            NodoAST* lista = crearNodo(AST_INTERNO, "Lista Filas");
            agregarHijo(lista, $1);
            NodoAST* fila = crearNodo(AST_INTERNO, "Fila");
            agregarHijo(fila, $4);
            agregarHijo(lista, fila);
            $$ = lista;
        } else {
            NodoAST* fila = crearNodo(AST_INTERNO, "Fila");
            agregarHijo(fila, $4);
            agregarHijo($1, fila);
            $$ = $1;
        }
    }
    | TOKEN_LLAVEIZQ lista_elementos TOKEN_LLAVEDER {
        NodoAST* fila = crearNodo(AST_INTERNO, "Fila");
        agregarHijo(fila, $2);
        $$ = crearNodo(AST_INTERNO, "Lista Filas");
        agregarHijo($$, fila);
    }
;

declaracion_matriz:
    tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_NEW tipo_primitivo TOKEN_CORCHETEIZQ expresion TOKEN_CORCHETEDER TOKEN_CORCHETEIZQ expresion TOKEN_CORCHETEDER {
        $$ = crearNodo(AST_DECLARACION_MATRIZ, "Declaración Matriz");
        $$->linea = @6.first_line; $$->columna = @6.first_column;
        agregarHijo($$, crearNodo(AST_TIPO, $1));
        agregarHijo($$, crearNodo(AST_IDENTIFICADOR, $6));
        agregarHijo($$, $11); // Filas
        agregarHijo($$, $14); // Columnas
    }
    | tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_LLAVEIZQ lista_filas TOKEN_LLAVEDER {
        $$ = crearNodo(AST_DECLARACION_MATRIZ, "Declaración Matriz");
        $$->linea = @6.first_line; $$->columna = @6.first_column;
        agregarHijo($$, crearNodo(AST_TIPO, $1));
        agregarHijo($$, crearNodo(AST_IDENTIFICADOR, $6));
        agregarHijo($$, $9);
    }
;

declaracion_array_multidimensional:
    tipo_primitivo DimensionesCorchetes TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_NEW tipo_primitivo Dimensiones {
        $$ = crearNodo(AST_DECLARACION_ARRAY_MULTIDIMENSIONAL, "Declaración Array Multidimensional");
        $$->linea = @3.first_line; $$->columna = @3.first_column;
        agregarHijo($$, crearNodo(AST_TIPO, $1));
        agregarHijo($$, crearNodo(AST_IDENTIFICADOR, $3));
        agregarHijo($$, $7); // Dimensiones
    }
    | tipo_primitivo DimensionesCorchetes TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_LLAVEIZQ lista_bloques TOKEN_LLAVEDER {
        $$ = crearNodo(AST_DECLARACION_ARRAY_MULTIDIMENSIONAL, "Declaración Array Multidimensional");
        $$->linea = @3.first_line; $$->columna = @3.first_column;
        agregarHijo($$, crearNodo(AST_TIPO, $1));
        agregarHijo($$, crearNodo(AST_IDENTIFICADOR, $3));
        agregarHijo($$, $6);
    }
;

lista_bloques:
    lista_bloques TOKEN_COMA TOKEN_LLAVEIZQ lista_bloques TOKEN_LLAVEDER {
        if ($1->tipo != AST_INTERNO) {
            NodoAST* lista = crearNodo(AST_INTERNO, "Lista Bloques");
            agregarHijo(lista, $1);
            NodoAST* bloque = crearNodo(AST_INTERNO, "Bloque");
            agregarHijo(bloque, $4);
            agregarHijo(lista, bloque);
            $$ = lista;
        } else {
            NodoAST* bloque = crearNodo(AST_INTERNO, "Bloque");
            agregarHijo(bloque, $4);
            agregarHijo($1, bloque);
            $$ = $1;
        }
    }
    | TOKEN_LLAVEIZQ lista_elementos TOKEN_LLAVEDER {
        NodoAST* bloque = crearNodo(AST_INTERNO, "Bloque");
        agregarHijo(bloque, $2);
        $$ = bloque;
    }
;

DimensionesCorchetes:
    TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER DimensionesCorchetes {
        NodoAST* dim = crearNodo(AST_DIMENSION, "[]");
        if ($3 == NULL) {
            $$ = dim;
        } else if ($3->tipo != AST_INTERNO) {
            NodoAST* lista = crearNodo(AST_INTERNO, "Dimensiones");
            agregarHijo(lista, dim);
            agregarHijo(lista, $3);
            $$ = lista;
        } else {
            /* Insertar al principio de la lista */
            NodoAST* nueva = crearNodo(AST_INTERNO, "Dimensiones");
            agregarHijo(nueva, dim);
            for (int i = 0; i < $3->num_hijos; i++) {
                agregarHijo(nueva, $3->hijos[i]);
            }
            $$ = nueva;
        }
    }
    | TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER {
        $$ = crearNodo(AST_DIMENSION, "[]");
    }
;

Dimensiones:
    TOKEN_CORCHETEIZQ TOKEN_NUMERO TOKEN_CORCHETEDER {
        $$ = crearNodo(AST_DIMENSION, "[]");
        agregarHijo($$, crearNodo(AST_NUMERO, $2));
    }
    | Dimensiones TOKEN_CORCHETEIZQ TOKEN_NUMERO TOKEN_CORCHETEDER {
        agregarHijo($1, crearNodo(AST_NUMERO, $3));
        $$ = $1;
    }
;

tipo_primitivo:
    TOKEN_DINT      { $$ = $1; }
    | TOKEN_DCHAR   { $$ = $1; }
    | TOKEN_DOUBLE  { $$ = $1; }
    | TOKEN_DFLOAT  { $$ = $1; }
    | TOKEN_DSTRING { $$ = $1; }
    | TOKEN_DBOOLEAN { $$ = $1; }
;
    
/* ========== ASIGNACIONES ========== */
asignacion:
    TOKEN_IDENTIFICADOR TOKEN_IGUAL expresion {
        $$ = crearNodo(AST_ASIGNACION, "");
        $$->linea = @1.first_line; 
        $$->columna = @1.first_column;
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, $1);
        id->linea = @1.first_line; 
        id->columna = @1.first_column;
        agregarHijo($$, id);
        agregarHijo($$, $3);
    }
    | TOKEN_IDENTIFICADOR TOKEN_MAS_IGUAL expresion {
        $$ = crear_asignacion_compuesta($1, "+", $3, @1.first_line, @1.first_column, @2.first_line, @2.first_column);
    }
    | TOKEN_IDENTIFICADOR TOKEN_MENOS_IGUAL expresion {
        $$ = crear_asignacion_compuesta($1, "-", $3, @1.first_line, @1.first_column, @2.first_line, @2.first_column);
    }
    | TOKEN_IDENTIFICADOR TOKEN_POR_IGUAL expresion {
        $$ = crear_asignacion_compuesta($1, "*", $3, @1.first_line, @1.first_column, @2.first_line, @2.first_column);
    }
    | TOKEN_IDENTIFICADOR TOKEN_DIV_IGUAL expresion {
        $$ = crear_asignacion_compuesta($1, "/", $3, @1.first_line, @1.first_column, @2.first_line, @2.first_column);
    }
    | TOKEN_IDENTIFICADOR TOKEN_MOD_IGUAL expresion {
        $$ = crear_asignacion_compuesta($1, "%", $3, @1.first_line, @1.first_column, @2.first_line, @2.first_column);
    }
    | TOKEN_IDENTIFICADOR TOKEN_AND_IGUAL expresion {
        $$ = crear_asignacion_compuesta($1, "&", $3, @1.first_line, @1.first_column, @2.first_line, @2.first_column);
    }
    | TOKEN_IDENTIFICADOR TOKEN_OR_IGUAL expresion {
        $$ = crear_asignacion_compuesta($1, "|", $3, @1.first_line, @1.first_column, @2.first_line, @2.first_column);
    }
    | TOKEN_IDENTIFICADOR TOKEN_XOR_IGUAL expresion {
        $$ = crear_asignacion_compuesta($1, "^", $3, @1.first_line, @1.first_column, @2.first_line, @2.first_column);
    }
    | TOKEN_IDENTIFICADOR TOKEN_DESIZQ_IGUAL expresion {
        $$ = crear_asignacion_compuesta($1, "<<", $3, @1.first_line, @1.first_column, @2.first_line, @2.first_column);
    }
    | TOKEN_IDENTIFICADOR TOKEN_DESDER_IGUAL expresion {
        $$ = crear_asignacion_compuesta($1, ">>", $3, @1.first_line, @1.first_column, @2.first_line, @2.first_column);
    }
;

/* ============================
   Expresiones por niveles
   ============================ */

expresion:
      expresion_or { $$ = $1; }
    ;

expresion_or:
      expresion_and { $$ = $1; }
    | expresion_or TOKEN_OR expresion_and {
          $$ = crearNodo(AST_OPERACION, "||");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1); agregarHijo($$, $3);
      }
    ;

expresion_and:
      expresion_bit_or { $$ = $1; }
    | expresion_and TOKEN_AND expresion_bit_or {
          $$ = crearNodo(AST_OPERACION, "&&");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1); agregarHijo($$, $3);
      }
    ;

expresion_bit_or:
      expresion_bit_xor { $$ = $1; }
    | expresion_bit_or TOKEN_BIT_OR expresion_bit_xor {
          $$ = crearNodo(AST_OPERACION, "|");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1); agregarHijo($$, $3);
      }
    ;

expresion_bit_xor:
      expresion_bit_and { $$ = $1; }
    | expresion_bit_xor TOKEN_XOR expresion_bit_and {
          $$ = crearNodo(AST_OPERACION, "^");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1); agregarHijo($$, $3);
      }
    ;

expresion_bit_and:
      expresion_equality { $$ = $1; }
    | expresion_bit_and TOKEN_BIT_AND expresion_equality {
          $$ = crearNodo(AST_OPERACION, "&");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1); agregarHijo($$, $3);
      }
    ;

expresion_equality:
      expresion_relacional { $$ = $1; }
    | expresion_equality TOKEN_IGUAL_IGUAL expresion_relacional {
          $$ = crearNodo(AST_OPERACION, "==");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1); agregarHijo($$, $3);
      }
    | expresion_equality TOKEN_NO_IGUAL expresion_relacional {
          $$ = crearNodo(AST_OPERACION, "!=");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1); agregarHijo($$, $3);
      }
    ;

expresion_relacional:
      expresion_shift { $$ = $1; }
    | expresion_relacional TOKEN_MENOR expresion_shift {
          $$ = crearNodo(AST_OPERACION, "<");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1); agregarHijo($$, $3);
      }
    | expresion_relacional TOKEN_MENOR_IGUAL expresion_shift {
          $$ = crearNodo(AST_OPERACION, "<=");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1); agregarHijo($$, $3);
      }
    | expresion_relacional TOKEN_MAYOR expresion_shift {
          $$ = crearNodo(AST_OPERACION, ">");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1); agregarHijo($$, $3);
      }
    | expresion_relacional TOKEN_MAYOR_IGUAL expresion_shift {
          $$ = crearNodo(AST_OPERACION, ">=");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1); agregarHijo($$, $3);
      }
    ;

expresion_shift:
      expresion_aditiva { $$ = $1; }
    | expresion_shift TOKEN_DESIZQ expresion_aditiva {
          $$ = crearNodo(AST_OPERACION, "<<");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1); agregarHijo($$, $3);
      }
    | expresion_shift TOKEN_DESDER expresion_aditiva {
          $$ = crearNodo(AST_OPERACION, ">>");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1); agregarHijo($$, $3);
      }
    ;

expresion_aditiva:
      expresion_multiplicativa { $$ = $1; }
    | expresion_aditiva TOKEN_MAS expresion_multiplicativa {
          $$ = crearNodo(AST_OPERACION, "+");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1); agregarHijo($$, $3);
      }
    | expresion_aditiva TOKEN_MENOS expresion_multiplicativa {
          $$ = crearNodo(AST_OPERACION, "-");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1); agregarHijo($$, $3);
      }
    ;

expresion_multiplicativa:
      expresion_unaria { $$ = $1; }
    | expresion_multiplicativa TOKEN_MULTI expresion_unaria {
          $$ = crearNodo(AST_OPERACION, "*");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1); agregarHijo($$, $3);
      }
    | expresion_multiplicativa TOKEN_DIV expresion_unaria {
          $$ = crearNodo(AST_OPERACION, "/");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1); agregarHijo($$, $3);
      }
    | expresion_multiplicativa TOKEN_MODULO expresion_unaria {
          $$ = crearNodo(AST_OPERACION, "%");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1); agregarHijo($$, $3);
      }
    ;

expresion_unaria:
      TOKEN_NOT expresion_unaria {
          $$ = crearNodo(AST_OPERACION, "!");
          $$->linea = @1.first_line; $$->columna = @1.first_column;
          agregarHijo($$, $2);
      }
    | TOKEN_MENOS expresion_unaria %prec UMINUS {
          $$ = crearNodo(AST_OPERACION, "uminus");
          $$->linea = @1.first_line; $$->columna = @1.first_column;
          agregarHijo($$, $2);
      }
    | TOKEN_PARIZQ tipo_primitivo TOKEN_PARDER expresion_unaria {
          /* crear un nodo específico para cast; guardamos el tipo en ->valor */
          $$ = crearNodo(AST_CAST, "cast");
          $$->valor = strdup($2);    
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $4);
          free($2); 
      }
    | postfix { $$ = $1; }
    ;

postfix:
      primary { $$ = $1; }
    | postfix TOKEN_INCREMENTO {
          /* transforma (postfix ++) — el hijo es la expresión previa */
          $$ = crearNodo(AST_OPERACION, "++");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1);
      }
    | postfix TOKEN_DECREMENTO {
          $$ = crearNodo(AST_OPERACION, "--");
          $$->linea = @2.first_line; $$->columna = @2.first_column;
          agregarHijo($$, $1);
      }
    ;


primary:
      TOKEN_NUMERO {
          $$ = crearNodo(AST_NUMERO, NULL);
          $$->valor = strdup($1);
          $$->linea = @1.first_line; $$->columna = @1.first_column;
      }
    | TOKEN_DOUBLE_LITERAL {
          $$ = crearNodo(AST_NUMERO, NULL);
          $$->valor = strdup($1);
          $$->linea = @1.first_line; $$->columna = @1.first_column;
      }
    | TOKEN_FLOAT_LITERAL {
          $$ = crearNodo(AST_NUMERO, NULL);
          $$->valor = strdup($1);
          $$->linea = @1.first_line; $$->columna = @1.first_column;
      }
    | TOKEN_CADENA {
          $$ = crearNodo(AST_CADENA, NULL);
          $$->valor = strdup($1);
          $$->linea = @1.first_line; $$->columna = @1.first_column;
      }
    | TOKEN_CARACTER {
          $$ = crearNodo(AST_CARACTER, NULL);
          $$->valor = strdup($1);
          $$->linea = @1.first_line; $$->columna = @1.first_column;
      }
    | TOKEN_IDENTIFICADOR {
          $$ = crearNodo(AST_IDENTIFICADOR, $1);
          $$->linea = @1.first_line; $$->columna = @1.first_column;
      }
    | TOKEN_PARIZQ expresion TOKEN_PARDER {
          $$ = $2;
      }
    ;



/* ========== INSTRUCCIONES ESPECÍFICAS ========== */
instruccion_print:
    TOKEN_PRINT TOKEN_PARIZQ expresion TOKEN_PARDER {
        $$ = crearNodo(AST_PRINT, "System.out.println");
        $$->linea = @1.first_line; $$->columna = @1.first_column;
        agregarHijo($$, $3);
    }
    | TOKEN_PRINT TOKEN_PARIZQ TOKEN_CADENA TOKEN_MAS expresion TOKEN_PARDER {
        // Manejo específico para concatenación en print
        NodoAST* concat = crearNodo(AST_OPERACION, "+");
        concat->linea = @4.first_line; concat->columna = @4.first_column;
        NodoAST* cadena = crearNodo(AST_CADENA, $3);
        cadena->linea = @3.first_line; cadena->columna = @3.first_column;
        agregarHijo(concat, cadena);
        agregarHijo(concat, $5);
        
        $$ = crearNodo(AST_PRINT, "System.out.println");
        $$->linea = @1.first_line; $$->columna = @1.first_column;
        agregarHijo($$, concat);
    }
;

bloque:
    TOKEN_LLAVEIZQ lista_sentencias TOKEN_LLAVEDER {
        $$ = crearNodo(AST_BLOQUE, NULL);
        $$->linea = @1.first_line; $$->columna = @1.first_column;
        agregarHijo($$, $2);
    }
;

instruccion_break:
    TOKEN_BREAK {
        $$ = crearNodo(AST_BREAK, "break");
        $$->linea = @1.first_line; $$->columna = @1.first_column;
    }
;

instruccion_continue:
    TOKEN_CONTINUE {
        $$ = crearNodo(AST_CONTINUE, "continue");
        $$->linea = @1.first_line; $$->columna = @1.first_column;
    }

/* ========== CONTROL DE FLUJOS ========== */
instruccion_if:
    TOKEN_IF TOKEN_PARIZQ expresion TOKEN_PARDER bloque %prec TOKEN_IF {
        $$ = crearNodo(AST_IF, "if");
        $$->linea = @1.first_line; $$->columna = @1.first_column;
        agregarHijo($$, $3);   // condición
        agregarHijo($$, $5);   // bloque if
    }
    | TOKEN_IF TOKEN_PARIZQ expresion TOKEN_PARDER bloque TOKEN_ELSE bloque {
        $$ = crearNodo(AST_IF, "if");
        $$->linea = @1.first_line; $$->columna = @1.first_column;
        agregarHijo($$, $3);   // condición
        agregarHijo($$, $5);   // bloque if
        NodoAST* else_node = crearNodo(AST_ELSE, "else");
        agregarHijo(else_node, $7);
        agregarHijo($$, else_node);
    }
    | TOKEN_IF TOKEN_PARIZQ expresion TOKEN_PARDER bloque TOKEN_ELSE instruccion_if {
        $$ = crearNodo(AST_IF, "if");
        $$->linea = @1.first_line; $$->columna = @1.first_column;
        agregarHijo($$, $3);   // condición
        agregarHijo($$, $5);   // bloque if
        NodoAST* elseif_node = crearNodo(AST_ELSEIF, "elseif");
        agregarHijo(elseif_node, $7);
        agregarHijo($$, elseif_node);
    }
;


intruccion_switch:
    TOKEN_SWITCH TOKEN_PARIZQ expresion TOKEN_PARDER TOKEN_LLAVEIZQ lista_casos TOKEN_LLAVEDER {
        $$ = crearNodo(AST_SWITCH, "switch");
        $$->linea = @1.first_line; $$->columna = @1.first_column;
        agregarHijo($$, $3);
        agregarHijo($$, $6);
    }
    ;

lista_casos: 
    lista_casos caso {
        if ($1->tipo != AST_LISTA) {
            NodoAST* lista = crearNodo(AST_LISTA, "Casos");
            agregarHijo(lista, $1);
            agregarHijo(lista, $2);
            $$ = lista;
        } else {
            agregarHijo($1, $2);
            $$ = $1;
        }
    }
    | caso {
        $$ = crearNodo(AST_LISTA, "Casos");
        agregarHijo($$, $1);
    }
    ;

caso: 
    TOKEN_CASE expresion TOKEN_DOS_PUNTOS lista_sentencias TOKEN_BREAK TOKEN_PUNTOCOMA{
        $$ = crearNodo(AST_CASE, "CASE");
        $$->linea = @1.first_line; $$->columna = @1.first_column;
        agregarHijo($$, $2);
        agregarHijo($$, $4);
        NodoAST* nodoBreak = crearNodo(AST_BREAK, "break");
        nodoBreak->linea = @5.first_line; nodoBreak->columna = @5.first_column;
        agregarHijo($$, nodoBreak);
    }
    | TOKEN_DEFAULT TOKEN_DOS_PUNTOS lista_sentencias {
        $$ = crearNodo(AST_DEFAULT, "DEFAULT");
        $$->linea = @1.first_line; $$->columna = @1.first_column;
        agregarHijo($$, $3);
    }
    ;

instruccion_while:
    TOKEN_WHILE TOKEN_PARIZQ expresion TOKEN_PARDER bloque {
        $$ = crearNodo(AST_WHILE, "while");
        $$->linea = @1.first_line; $$->columna = @1.first_column;
        agregarHijo($$, $3);
        agregarHijo($$, $5);
    } 
;

instruccion_for:
    TOKEN_FOR TOKEN_PARIZQ declaracion TOKEN_PUNTOCOMA expresion TOKEN_PUNTOCOMA expresion TOKEN_PARDER bloque{
        $$ = crearNodo(AST_FOR, "FOR");
        $$->linea = @1.first_line; $$->columna = @1.first_column;
        agregarHijo($$, $3);
        agregarHijo($$, $5);
        agregarHijo($$, $7);
        agregarHijo($$, $9);
    }
    | TOKEN_FOR TOKEN_PARIZQ asignacion TOKEN_PUNTOCOMA expresion TOKEN_PUNTOCOMA expresion TOKEN_PARDER bloque{
        $$ = crearNodo(AST_FOR, "FOR");
        $$->linea = @1.first_line; $$->columna = @1.first_column;
        agregarHijo($$, $3);
        agregarHijo($$, $5);
        agregarHijo($$, $7);
        agregarHijo($$, $9);
    }
;

%%

/* ========== FUNCIONES AUXILIARES ========== */

NodoAST* crear_asignacion_compuesta(char* id, char* operador, NodoAST* expr, 
                                   int id_linea, int id_columna, int op_linea, int op_columna) {
    NodoAST* asig = crearNodo(AST_ASIGNACION, "");
    asig->linea = id_linea; 
    asig->columna = id_columna;
    
    NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, strdup(id));
    idRef->linea = id_linea; 
    idRef->columna = id_columna;
    
    NodoAST* op = crearNodo(AST_OPERACION, strdup(operador));
    op->linea = op_linea; 
    op->columna = op_columna;
    
    NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, strdup(id));
    idOp->linea = id_linea; 
    idOp->columna = id_columna;
    
    agregarHijo(op, idOp);
    agregarHijo(op, expr);
    agregarHijo(asig, idRef);
    agregarHijo(asig, op);
    
    return asig;
}

void yyerror(const char *s) {
    extern YYLTYPE yylloc;
    int linea = (yylloc.first_line > 0) ? yylloc.first_line : yylineno;
    int columna = (yylloc.first_column > 0) ? yylloc.first_column : yycolumn;
    fprintf(stderr, "%s en línea %d, columna %d\n", s, linea, columna);
}