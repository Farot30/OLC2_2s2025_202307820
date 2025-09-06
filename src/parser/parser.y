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
%token <str> TOKEN_LLAVEDER TOKEN_LLAVEIZQ
%token <str> TOKEN_MULTI TOKEN_DIV TOKEN_MODULO TOKEN_MAS TOKEN_MENOS
%token <str> TOKEN_DBOOLEAN TOKEN_BOOLEANO
%token <str> TOKEN_IDENTIFICADOR
%token <str> TOKEN_DINT TOKEN_DFLOAT TOKEN_DSTRING TOKEN_DCHAR TOKEN_DOUBLE
%token <str> TOKEN_IGUAL TOKEN_PUNTOCOMA TOKEN_DOS_PUNTOS
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
%type <nodo> declaracion asignacion
%type <nodo> expresion
%type <nodo> instruccion_print instruccion_if bloque
%type <nodo> cast
%type <nodo> intruccion_switch lista_casos caso
%type <nodo> instruccion_while instruccion_break instruccion_continue
%type <nodo> instruccion_for
%type <str> tipo_primitivo

/* ========== PRECEDENCIA MÍNIMA ========== */
%right TOKEN_IGUAL TOKEN_MAS_IGUAL TOKEN_MENOS_IGUAL TOKEN_POR_IGUAL TOKEN_DIV_IGUAL TOKEN_MOD_IGUAL 
%right TOKEN_AND_IGUAL TOKEN_OR_IGUAL TOKEN_XOR_IGUAL TOKEN_DESIZQ_IGUAL TOKEN_DESDER_IGUAL
%left TOKEN_OR
%left TOKEN_AND
%left TOKEN_BIT_OR
%left TOKEN_XOR
%left TOKEN_BIT_AND
%left TOKEN_IGUAL_IGUAL TOKEN_NO_IGUAL
%left TOKEN_MENOR TOKEN_MENOR_IGUAL TOKEN_MAYOR TOKEN_MAYOR_IGUAL
%left TOKEN_DESIZQ TOKEN_DESDER
%left TOKEN_MAS TOKEN_MENOS
%left TOKEN_MULTI TOKEN_DIV TOKEN_MODULO
%right TOKEN_NOT UMINUS
%left TOKEN_EQUAL
%nonassoc TOKEN_IF
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
        id->linea = @2.first_line; 
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
        id->linea = @2.first_line; 
        id->columna = @2.first_column;
        NodoAST* def = crearNodo(AST_CADENA, (char*)valorPorDefectoTipo(obtenerTipoDesdeString($1)));
        agregarHijo($$, id);
        agregarHijo($$, def);
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

/* ========== EXPRESIONES ========== */
expresion:
    expresion TOKEN_MAS expresion {
        $$ = crearNodo(AST_OPERACION, "+");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1); agregarHijo($$, $3);
    }
    | expresion TOKEN_MENOS expresion {
        $$ = crearNodo(AST_OPERACION, "-");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1); agregarHijo($$, $3);
    }
    | TOKEN_IDENTIFICADOR TOKEN_MAS TOKEN_MAS {
        $$ = crearNodo(AST_INCREMENTO, "++");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, $1);
        id->linea = @1.first_line; id->columna = @1.first_column;
        agregarHijo($$, id);
    }
    | TOKEN_IDENTIFICADOR TOKEN_MENOS TOKEN_MENOS {
        $$ = crearNodo(AST_DECREMENTO, "--");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, $1);
        id->linea = @1.first_line; id->columna = @1.first_column;
        agregarHijo($$, id);
    }
    | expresion TOKEN_MULTI expresion {
        $$ = crearNodo(AST_OPERACION, "*");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1); agregarHijo($$, $3);
    }
    | expresion TOKEN_DIV expresion {
        $$ = crearNodo(AST_OPERACION, "/");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1); agregarHijo($$, $3);
    }
    | expresion TOKEN_MODULO expresion {
        $$ = crearNodo(AST_OPERACION, "%");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1); agregarHijo($$, $3);
    }
    | expresion TOKEN_IGUAL_IGUAL expresion {
        $$ = crearNodo(AST_OPERACION, "==");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1); agregarHijo($$, $3);
    }
    | expresion TOKEN_NO_IGUAL expresion {
        $$ = crearNodo(AST_OPERACION, "!=");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1); agregarHijo($$, $3);
    }
    | expresion TOKEN_MENOR expresion {
        $$ = crearNodo(AST_OPERACION, "<");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1); agregarHijo($$, $3);
    }
    | expresion TOKEN_MAYOR expresion {
        $$ = crearNodo(AST_OPERACION, ">");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1); agregarHijo($$, $3);
    }
    | expresion TOKEN_MENOR_IGUAL expresion {
        $$ = crearNodo(AST_OPERACION, "<=");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1); agregarHijo($$, $3);
    }
    | expresion TOKEN_MAYOR_IGUAL expresion {
        $$ = crearNodo(AST_OPERACION, ">=");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1); agregarHijo($$, $3);
    }
    | expresion TOKEN_AND expresion {
        $$ = crearNodo(AST_OPERACION, "&&");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1); agregarHijo($$, $3);
    }
    | expresion TOKEN_OR expresion {
        $$ = crearNodo(AST_OPERACION, "||");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1); agregarHijo($$, $3);
    }
    | expresion TOKEN_BIT_AND expresion {
        $$ = crearNodo(AST_OPERACION, "&");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1); agregarHijo($$, $3);
    }
    | expresion TOKEN_BIT_OR expresion {
        $$ = crearNodo(AST_OPERACION, "|");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1); agregarHijo($$, $3);
    }
    | expresion TOKEN_XOR expresion {
        $$ = crearNodo(AST_OPERACION, "^");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1); agregarHijo($$, $3);
    }
    | expresion TOKEN_DESIZQ expresion {
        $$ = crearNodo(AST_OPERACION, "<<");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1); agregarHijo($$, $3);
    }
    | expresion TOKEN_DESDER expresion {
        $$ = crearNodo(AST_OPERACION, ">>");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1); agregarHijo($$, $3);
    }
    | expresion TOKEN_EQUAL TOKEN_PARIZQ expresion TOKEN_PARDER {
        $$ = crearNodo(AST_EQUAL, ".equals");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1);
        agregarHijo($$, $4);
    }
    | TOKEN_NOT expresion {
        $$ = crearNodo(AST_OPERACION, "!");
        $$->linea = @1.first_line; $$->columna = @1.first_column;
        agregarHijo($$, $2);
    }
    | TOKEN_MENOS expresion %prec UMINUS {
        $$ = crearNodo(AST_OPERACION, "-");
        $$->linea = @1.first_line; $$->columna = @1.first_column;
        agregarHijo($$, $2);
    }
    | TOKEN_PARIZQ expresion TOKEN_PARDER {
        $$ = $2;
    }
    | TOKEN_NUMERO {
        $$ = crearNodo(AST_NUMERO, $1);
        $$->linea = @1.first_line; $$->columna = @1.first_column;
    }
    | TOKEN_FLOAT_LITERAL {
        $$ = crearNodo(AST_NUMERO, $1);
        $$->linea = @1.first_line; $$->columna = @1.first_column;
    }
    | TOKEN_DOUBLE_LITERAL {
        $$ = crearNodo(AST_NUMERO, $1);
        $$->linea = @1.first_line; $$->columna = @1.first_column;
    }
    | TOKEN_CADENA {
        $$ = crearNodo(AST_CADENA, $1);
        $$->linea = @1.first_line; $$->columna = @1.first_column;
    }
    | TOKEN_CARACTER {
        $$ = crearNodo(AST_CARACTER, $1);
        $$->linea = @1.first_line; $$->columna = @1.first_column;
    }
    | TOKEN_BOOLEANO {
        $$ = crearNodo(AST_BOOLEAN, $1);
        $$->linea = @1.first_line; $$->columna = @1.first_column;
    }
    | TOKEN_IDENTIFICADOR {
        $$ = crearNodo(AST_IDENTIFICADOR, $1);
        $$->linea = @1.first_line; $$->columna = @1.first_column;
    }
    | cast {
        $$ = $1;
    }
    | TOKEN_STRING_VALUEOF TOKEN_PARIZQ expresion TOKEN_PARDER {
        $$ = crearNodo(AST_STRING, "String.valueOf");
        $$->linea = @1.first_line; $$->columna = @1.first_column;
        agregarHijo($$, $3);
    }
;

/* ========== CAST ========== */
cast:
    TOKEN_PARIZQ tipo_primitivo TOKEN_PARDER expresion {
        $$ = crearNodo(AST_CAST, $2);
        $$->linea = @1.first_line; $$->columna = @1.first_column;
        agregarHijo($$, $4);
    }
;

/* ========== INSTRUCCIONES ESPECÍFICAS ========== */
instruccion_print:
    TOKEN_PRINT TOKEN_PARIZQ expresion TOKEN_PARDER {
        $$ = crearNodo(AST_PRINT, "System.out.println");
        $$->linea = @1.first_line; $$->columna = @1.first_column;
        agregarHijo($$, $3);
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