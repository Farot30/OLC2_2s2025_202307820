%code requires {
    #include "../AST/ast.h"
}
%define parse.error verbose
%locations
%{
    #include "../comun/strutil.h"
    #include <stdio.h>
    #include <string.h>
    #include "../semantico/semantico.h"
    #include "../AST/err.h"  
    void yyerror(const char *s);
    extern int yylex(void);
%}

%union {
    char* str;
    NodoAST* nodo;
}

%token <str> TOKEN_DBOOLEAN
%token <str> TOKEN_BOOLEANO
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
%token <str> TOKEN_MAS_IGUAL
%token <str> TOKEN_MENOS_IGUAL
%token <str> TOKEN_POR_IGUAL
%token <str> TOKEN_DIV_IGUAL
%token <str> TOKEN_MOD_IGUAL
%token <str> TOKEN_PRINT
%token <str> TOKEN_PARIZQ
%token <str> TOKEN_PARDER

%type <nodo> s Programa Lista_expresiones Declaracion expresion expr Bloque Asignacion Cast PRINT 
%type <str> Tipos 

//precedencia
%left '+' '-'
%left '*' '/' '%'
%left NEG

%%


s: Programa {
    verificarSemantica($1);
    imprimirAST($1, 0);
    exportarAST($1, "ast.dot", "ast.png");
    liberarAST($1);
    };

Programa: Lista_expresiones { $$ = $1; };

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
    $$->linea = @1.first_line; $$->columna = @1.first_column;
    agregarHijo($$, $2);
};

expresion: Declaracion
    | Asignacion
    | PRINT
    ;

Declaracion:
      Tipos TOKEN_IDENTIFICADOR TOKEN_IGUAL expr TOKEN_DOBLEPUNTO {
         $$ = crearNodo(AST_DECLARACION, NULL);
         $$->valor = strdup($1);
         $$->linea=@2.first_line; $$->columna=@2.first_column;
         NodoAST* id = crearNodo(AST_IDENTIFICADOR, $2);
         id->linea=@2.first_line; id->columna=@2.first_column;
         agregarHijo($$, id);
         agregarHijo($$, $4);
      }
    | Tipos TOKEN_IDENTIFICADOR TOKEN_DOBLEPUNTO {
         $$ = crearNodo(AST_DECLARACION, NULL);
         $$->valor = strdup($1);
         $$->linea=@2.first_line; $$->columna=@2.first_column;
         NodoAST* id = crearNodo(AST_IDENTIFICADOR, $2);
         id->linea=@2.first_line; id->columna=@2.first_column;

         NodoAST* def = crearNodo(AST_CADENA, (char*)valorPorDefectoTipo(obtenerTipoDesdeString($1)));
         agregarHijo($$, id);
         agregarHijo($$, def);
      }
;


Asignacion:
      TOKEN_IDENTIFICADOR TOKEN_IGUAL expr TOKEN_DOBLEPUNTO {
          $$ = crearNodo(AST_ASIGNACION, NULL);
          $$->linea = @1.first_line; $$->columna = @1.first_column;
          NodoAST* id = crearNodo(AST_IDENTIFICADOR, $1);
          id->linea = @1.first_line; id->columna = @1.first_column;
          agregarHijo($$, id);
          agregarHijo($$, $3);
      }
    | TOKEN_IDENTIFICADOR TOKEN_MAS_IGUAL expr TOKEN_DOBLEPUNTO {
          $$ = crearNodo(AST_ASIGNACION, NULL);
          $$->linea = @1.first_line; $$->columna = @1.first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, $1);
          idRef->linea = @1.first_line; idRef->columna = @1.first_column;
          NodoAST* op = crearNodo(AST_OPERACION, "+");
          op->linea = @2.first_line; op->columna = @2.first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, $1);
          idOp->linea = @1.first_line; idOp->columna = @1.first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, $3);
          agregarHijo($$, idRef);
          agregarHijo($$, op);
      }
    | TOKEN_IDENTIFICADOR TOKEN_MENOS_IGUAL expr TOKEN_DOBLEPUNTO {
          $$ = crearNodo(AST_ASIGNACION, NULL);
          $$->linea = @1.first_line; $$->columna = @1.first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, $1);
          idRef->linea = @1.first_line; idRef->columna = @1.first_column;
          NodoAST* op = crearNodo(AST_OPERACION, "-");
          op->linea = @2.first_line; op->columna = @2.first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, $1);
          idOp->linea = @1.first_line; idOp->columna = @1.first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, $3);
          agregarHijo($$, idRef);
          agregarHijo($$, op);
      }
    | TOKEN_IDENTIFICADOR TOKEN_POR_IGUAL expr TOKEN_DOBLEPUNTO {
          $$ = crearNodo(AST_ASIGNACION, NULL);
          $$->linea = @1.first_line; $$->columna = @1.first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, $1);
          idRef->linea = @1.first_line; idRef->columna = @1.first_column;
          NodoAST* op = crearNodo(AST_OPERACION, "*");
          op->linea = @2.first_line; op->columna = @2.first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, $1);
          idOp->linea = @1.first_line; idOp->columna = @1.first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, $3);
          agregarHijo($$, idRef);
          agregarHijo($$, op);
      }
    | TOKEN_IDENTIFICADOR TOKEN_DIV_IGUAL expr TOKEN_DOBLEPUNTO {
          $$ = crearNodo(AST_ASIGNACION, NULL);
          $$->linea = @1.first_line; $$->columna = @1.first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, $1);
          idRef->linea = @1.first_line; idRef->columna = @1.first_column;
          NodoAST* op = crearNodo(AST_OPERACION, "/");
          op->linea = @2.first_line; op->columna = @2.first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, $1);
          idOp->linea = @1.first_line; idOp->columna = @1.first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, $3);
          agregarHijo($$, idRef);
          agregarHijo($$, op);
      }
    | TOKEN_IDENTIFICADOR TOKEN_MOD_IGUAL expr TOKEN_DOBLEPUNTO {
          $$ = crearNodo(AST_ASIGNACION, NULL);
          $$->linea = @1.first_line; $$->columna = @1.first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, $1);
          idRef->linea = @1.first_line; idRef->columna = @1.first_column;
          NodoAST* op = crearNodo(AST_OPERACION, "%");
          op->linea = @2.first_line; op->columna = @2.first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, $1);
          idOp->linea = @1.first_line; idOp->columna = @1.first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, $3);
          agregarHijo($$, idRef);
          agregarHijo($$, op);
      }
    ;

Tipos: TOKEN_DINT      { $$ = $1; }
    | TOKEN_DCHAR     { $$ = $1; }
    | TOKEN_DOUBLE    { $$ = $1; }
    | TOKEN_DFLOAT    { $$ = $1; }
    | TOKEN_DSTRING   { $$ = $1; }
    | TOKEN_DBOOLEAN  { $$ = $1; }

expr:
      expr '+' expr { $$ = crearNodo(AST_OPERACION, "+"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr '-' expr { $$ = crearNodo(AST_OPERACION, "-"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr '*' expr { $$ = crearNodo(AST_OPERACION, "*"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr '/' expr { $$ = crearNodo(AST_OPERACION, "/"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr '%' expr { $$ = crearNodo(AST_OPERACION, "%"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | Cast
    | TOKEN_NUMERO         { $$ = crearNodo(AST_NUMERO, $1); $$->linea=@1.first_line; $$->columna=@1.first_column; }
    | TOKEN_FLOAT_LITERAL  { $$ = crearNodo(AST_NUMERO, $1); $$->linea=@1.first_line; $$->columna=@1.first_column; }
    | TOKEN_DOUBLE_LITERAL { $$ = crearNodo(AST_NUMERO, $1); $$->linea=@1.first_line; $$->columna=@1.first_column; }
    | TOKEN_CADENA         { $$ = crearNodo(AST_CADENA, $1); $$->linea=@1.first_line; $$->columna=@1.first_column; }
    | TOKEN_CARACTER       { $$ = crearNodo(AST_CARACTER, $1); $$->linea=@1.first_line; $$->columna=@1.first_column; }
    | TOKEN_IDENTIFICADOR  { $$ = crearNodo(AST_IDENTIFICADOR, $1); $$->linea=@1.first_line; $$->columna=@1.first_column; }
    | TOKEN_BOOLEANO       { $$ = crearNodo(AST_BOOLEAN, $1); $$->linea=@1.first_line; $$->columna=@1.first_column; }
    ;

Cast: '(' Tipos ')' expr {
    $$ = crearNodo(AST_CAST, $2);
    $$->linea = @1.first_line; $$->columna=@1.first_column;
    agregarHijo($$, $4);
};
PRINT: TOKEN_PRINT TOKEN_PARIZQ expr TOKEN_PARDER TOKEN_DOBLEPUNTO {
    $$ = crearNodo(AST_PRINT, $1);
    $$->linea = @1.first_line; $$->columna = @1.first_column;
    agregarHijo($$, $3);
};

%%

// ...existing code...
void yyerror(const char *s) {
    extern YYLTYPE yylloc;
    char msg[128];
    snprintf(msg, sizeof(msg), "Sintaxis: %s", s);
    addError(msg, "global", yylloc.first_line, yylloc.first_column);
    fprintf(stderr, "%s en %d:%d\n", s, yylloc.first_line, yylloc.first_column);
}