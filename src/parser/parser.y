%code requires {
    #include "../AST/ast.h"
}
%define parse.error verbose
%locations
%{
    #include <stdio.h>
    #include <string.h>
    #include "../semantico/semantico.h"
    void yyerror(const char *s);
    extern int yylex(void);
%}

%union {
    char* str;
    NodoAST* nodo;
}

%token <str> TOKEN_IDENTIFICADOR
%token <str> TOKEN_DINT
%token <str> TOKEN_DFLOAT
%token <str> TOKEN_DSTRING
%token <str> TOKEN_DCHAR
%token <str> TOKEN_DOUBLE
%token <str> TOKEN_IGUAL
%token <str> TOKEN_DOBLEPUNTO
%token <str> TOKEN_NUMERO
%token <str> TOKEN_CADENA
%token <str> TOKEN_CARACTER
%token <str> TOKEN_FLOAT_LITERAL
%token <str> TOKEN_DOUBLE_LITERAL 

%type <nodo> s Lista_expresiones Declaracion expresion expr Bloque Asignacion 
%type <str> Tipos

//precedencia
%left '+' '-'
%left '*' '/' '%'
%left NEG

%%

s: Lista_expresiones {
        verificarSemantica($1);
        imprimirAST($1, 0);
        exportarAST($1, "ast.dot", "ast.png");
        liberarAST($1);
    }
    ;

Lista_expresiones: Lista_expresiones expresion {
        if ($1->tipo != AST_LISTA) {
            NodoAST* lista = crearNodo(AST_LISTA, "Arbol AST");
            agregarHijo(lista, $1);
            agregarHijo(lista, $2);
            $$ = lista;
        } else {
            agregarHijo($1, $2);
            $$ = $1;
        }
    }
    | expresion {
        $$ = $1;
    }
    ;

Bloque: '{' Lista_expresiones '}' {
    $$ = crearNodo(AST_BLOQUE, NULL);
    agregarHijo($$, $2);
}

expresion: Declaracion
    | Asignacion
    
    ;

Declaracion: Tipos TOKEN_IDENTIFICADOR TOKEN_IGUAL expr TOKEN_DOBLEPUNTO {
    $$ = crearNodo(AST_DECLARACION, NULL); 
    $$->valor = strdup($1);              
    agregarHijo($$, crearNodo(AST_IDENTIFICADOR, $2));
    agregarHijo($$, $4);
}

Asignacion: TOKEN_IDENTIFICADOR TOKEN_IGUAL expr TOKEN_DOBLEPUNTO {
    $$ = crearNodo(AST_ASIGNACION, $1);
    agregarHijo($$, crearNodo(AST_IDENTIFICADOR, $1));
    agregarHijo($$, $3);
}

Tipos: TOKEN_DINT      { $$ = $1; }
    | TOKEN_DCHAR     { $$ = $1; }
    | TOKEN_DOUBLE    { $$ = $1; }
    | TOKEN_DFLOAT    { $$ = $1; }
    | TOKEN_DSTRING   { $$ = $1; }

expr: expr '+' expr         { $$ = crearNodo(AST_OPERACION, "+");
                            agregarHijo($$, $1); 
                            agregarHijo($$, $3);}
    | expr '-' expr         { $$ = crearNodo(AST_OPERACION, "-");
                            agregarHijo($$, $1);
                            agregarHijo($$, $3);}
    | expr '*' expr         { $$ = crearNodo(AST_OPERACION, "*");
                            agregarHijo($$, $1);
                            agregarHijo($$, $3);}
    | expr '/' expr         { $$ = crearNodo(AST_OPERACION, "/");
                            agregarHijo($$, $1);
                            agregarHijo($$, $3);}
    | expr '%' expr         { $$ = crearNodo(AST_OPERACION, "%");
                            agregarHijo($$, $1);
                            agregarHijo($$, $3);}
    | TOKEN_NUMERO          { $$ = crearNodo(AST_NUMERO, $1); }
    | TOKEN_FLOAT_LITERAL   { $$ = crearNodo(AST_NUMERO, $1); }
    | TOKEN_DOUBLE_LITERAL  { $$ = crearNodo(AST_NUMERO, $1); }
    | TOKEN_CADENA          { $$ = crearNodo(AST_CADENA, $1); }
    | TOKEN_CARACTER        { $$ = crearNodo(AST_CARACTER, $1); }
    | TOKEN_IDENTIFICADOR   { $$ = crearNodo(AST_IDENTIFICADOR, $1); }
%%

void yyerror(const char *s) {
    extern YYLTYPE yylloc;
    fprintf(stderr, "%s en %d:%d\n", 
    s, 
    yylloc.first_line, 
    yylloc.first_column);
}