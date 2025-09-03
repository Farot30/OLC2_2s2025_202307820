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
%token <str> TOKEN_BIT_AND
%token <str> TOKEN_BIT_OR
%token <str> TOKEN_XOR
%token <str> TOKEN_DESIZQ
%token <str> TOKEN_DESDER
%token <str> TOKEN_AND_IGUAL
%token <str> TOKEN_OR_IGUAL
%token <str> TOKEN_XOR_IGUAL
%token <str> TOKEN_DESIZQ_IGUAL
%token <str> TOKEN_DESDER_IGUAL
%token <str> TOKEN_STRING_VALUEOF
%token <str> TOKEN_IGUAL_IGUAL
%token <str> TOKEN_NO_IGUAL
%token <str> TOKEN_MAYOR_IGUAL
%token <str> TOKEN_MENOR_IGUAL
%token <str> TOKEN_EQUAL
%token <str> TOKEN_MAYOR
%token <str> TOKEN_MENOR
%token <str> TOKEN_AND
%token <str> TOKEN_OR
%token <str> TOKEN_NOT

%type <nodo> s Programa Lista_expresiones Declaracion expresion expr Asignacion Cast PRINT
%type <str> Tipos 

//precedencia
%right TOKEN_IGUAL TOKEN_MAS_IGUAL TOKEN_MENOS_IGUAL TOKEN_POR_IGUAL TOKEN_DIV_IGUAL TOKEN_MOD_IGUAL
%right TOKEN_NOT
%left TOKEN_AND TOKEN_OR
%left '+' '-'
%left '*' '/' '%'
%left NEG
%left TOKEN_PARIZQ TOKEN_PARDER
%left TOKEN_BIT_AND
%left TOKEN_BIT_OR
%left TOKEN_XOR
%left TOKEN_DESIZQ TOKEN_DESDER
%left TOKEN_EQUAL
%left TOKEN_IGUAL_IGUAL TOKEN_NO_IGUAL TOKEN_MAYOR TOKEN_MENOR TOKEN_MAYOR_IGUAL TOKEN_MENOR_IGUAL
%nonassoc CAST_ERROR 

%expect 0 

%%


s: Programa {
    // 2. Mostrar AST para debugging
    printf("\n=== ESTRUCTURA DEL AST ===\n");
    imprimirAST($1, 0);
    
    
    // 4. EJECUTAR/INTERPRETAR el programa (ANTES de liberar)
    interpretarPrograma($1);
    
    printf("ejecutando exportarAST\n");
    exportarAST($1, "ast.dot", "ast.png");

    //printf("verificando la semantica\n");
    //verificarSemantica($1);

    // 5. Liberar memoria AL FINAL
    printf("\n=== LIBERANDO MEMORIA ===\n");
    liberarAST($1);
    
    printf("[DEBUG] Procesamiento completado.\n");
}

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
/*
Bloque: '{' Lista_expresiones '}' {
    $$ = crearNodo(AST_BLOQUE, NULL);
    $$->linea = @1.first_line; $$->columna = @1.first_column;
    agregarHijo($$, $2);
    };
    */

expresion: Declaracion
    | Asignacion
    | PRINT
    | error TOKEN_IGUAL expr TOKEN_DOBLEPUNTO {
         addErrorSintactico("Asignación sin declaración de tipo", "variable", @1.first_line, @1.first_column);
         $$ = crearNodo(AST_ERROR, "ASIGNACION_SIN_DECLARACION");
         yyerrok;
      }
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
    | Tipos TOKEN_IDENTIFICADOR error TOKEN_DOBLEPUNTO {
        addErrorSintactico("Expresión de inicialización inválida", "global", @3.first_line, @3.first_column);
        $$ = crearNodo(AST_DECLARACION, "ERROR");
        yyerrok;
      }
    | Tipos TOKEN_IDENTIFICADOR TOKEN_IGUAL error {
        addErrorSintactico("Falta punto y coma al final de la declaración", "global", @3.first_line, @3.first_column);
        $$ = crearNodo(AST_DECLARACION, "ERROR");
        yyerrok;
      }
    | Tipos error TOKEN_DOBLEPUNTO {
        addErrorSintactico("Identificador inválido en declaración", "global", @3.first_line, @3.first_column);
        $$ = crearNodo(AST_DECLARACION, "ERROR");
        yyerrok;
      }
    | error TOKEN_IDENTIFICADOR TOKEN_IGUAL expr TOKEN_DOBLEPUNTO {
        addErrorSintactico("Tipo de dato inválido en declaración", "global", @3.first_line, @3.first_column);
        $$ = crearNodo(AST_DECLARACION, "ERROR");
        yyerrok;
      }
    ;


Asignacion:
      TOKEN_IDENTIFICADOR TOKEN_IGUAL expr TOKEN_DOBLEPUNTO {
          $$ = crearNodo(AST_ASIGNACION, "");
          $$->linea = @1.first_line; $$->columna = @1.first_column;
          NodoAST* id = crearNodo(AST_IDENTIFICADOR, $1);
          id->linea = @1.first_line; id->columna = @1.first_column;
          agregarHijo($$, id);
          agregarHijo($$, $3);
      }
    | TOKEN_IDENTIFICADOR TOKEN_MAS_IGUAL expr TOKEN_DOBLEPUNTO {
          $$ = crearNodo(AST_ASIGNACION, "");
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
          $$ = crearNodo(AST_ASIGNACION, "");
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
          $$ = crearNodo(AST_ASIGNACION, "");
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
          $$ = crearNodo(AST_ASIGNACION, "");
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
          $$ = crearNodo(AST_ASIGNACION, "");
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
    | TOKEN_IDENTIFICADOR TOKEN_AND_IGUAL expr TOKEN_DOBLEPUNTO {
          $$ = crearNodo(AST_ASIGNACION, "");
          $$->linea = @1.first_line; $$->columna = @1.first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, $1);
          idRef->linea = @1.first_line; idRef->columna = @1.first_column;
          NodoAST* op = crearNodo(AST_OPERACION, "&");
          op->linea = @2.first_line; op->columna = @2.first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, $1);
          idOp->linea = @1.first_line; idOp->columna = @1.first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, $3);
          agregarHijo($$, idRef);
          agregarHijo($$, op);
      }
    | TOKEN_IDENTIFICADOR TOKEN_OR_IGUAL expr TOKEN_DOBLEPUNTO {
          $$ = crearNodo(AST_ASIGNACION, "");
          $$->linea = @1.first_line; $$->columna = @1.first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, $1);
          idRef->linea = @1.first_line; idRef->columna = @1.first_column;
          NodoAST* op = crearNodo(AST_OPERACION, "|");
          op->linea = @2.first_line; op->columna = @2.first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, $1);
          idOp->linea = @1.first_line; idOp->columna = @1.first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, $3);
          agregarHijo($$, idRef);
          agregarHijo($$, op);
      }
    | TOKEN_IDENTIFICADOR TOKEN_XOR_IGUAL expr TOKEN_DOBLEPUNTO {
          $$ = crearNodo(AST_ASIGNACION, "");
          $$->linea = @1.first_line; $$->columna = @1.first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, $1);
          idRef->linea = @1.first_line; idRef->columna = @1.first_column;
          NodoAST* op = crearNodo(AST_OPERACION, "^");
          op->linea = @2.first_line; op->columna = @2.first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, $1);
          idOp->linea = @1.first_line; idOp->columna = @1.first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, $3);
          agregarHijo($$, idRef);
          agregarHijo($$, op);
      }
    | TOKEN_IDENTIFICADOR TOKEN_DESIZQ_IGUAL expr TOKEN_DOBLEPUNTO {
          $$ = crearNodo(AST_ASIGNACION, "");
          $$->linea = @1.first_line; $$->columna = @1.first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, $1);
          idRef->linea = @1.first_line; idRef->columna = @1.first_column;
          NodoAST* op = crearNodo(AST_OPERACION, "<<");
          op->linea = @2.first_line; op->columna = @2.first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, $1);
          idOp->linea = @1.first_line; idOp->columna = @1.first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, $3);
          agregarHijo($$, idRef);
          agregarHijo($$, op);
      }
    | TOKEN_IDENTIFICADOR TOKEN_DESDER_IGUAL expr TOKEN_DOBLEPUNTO {
          $$ = crearNodo(AST_ASIGNACION, "");
          $$->linea = @1.first_line; $$->columna = @1.first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, $1);
          idRef->linea = @1.first_line; idRef->columna = @1.first_column;
          NodoAST* op = crearNodo(AST_OPERACION, ">>");
          op->linea = @2.first_line; op->columna = @2.first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, $1);
          idOp->linea = @1.first_line; idOp->columna = @1.first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, $3);
          agregarHijo($$, idRef);
          agregarHijo($$, op);
      }
    | TOKEN_IDENTIFICADOR TOKEN_IGUAL error TOKEN_DOBLEPUNTO {
         addErrorSintactico("Expresión de asignación inválida", $1, @3.first_line, @3.first_column);
         $$ = crearNodo(AST_ASIGNACION, "ERROR");
         yyerrok;
      }
    | TOKEN_IDENTIFICADOR TOKEN_IGUAL expr error {
         addErrorSintactico("Falta punto y coma al final de la asignación", $1, @4.first_line, @4.first_column);
         $$ = crearNodo(AST_ASIGNACION, "ERROR");
         yyerrok;
      }
    | TOKEN_IDENTIFICADOR error expr TOKEN_DOBLEPUNTO {
         addErrorSintactico("Operador de asignación inválido", $1, @2.first_line, @2.first_column);
         $$ = crearNodo(AST_ASIGNACION, "ERROR");
         yyerrok;
      }
    ;

Tipos: TOKEN_DINT      { $$ = $1; }
    | TOKEN_DCHAR     { $$ = $1; }
    | TOKEN_DOUBLE    { $$ = $1; }
    | TOKEN_DFLOAT    { $$ = $1; }
    | TOKEN_DSTRING   { $$ = $1; }
    | TOKEN_DBOOLEAN  { $$ = $1; }
    ;

expr:
      expr '+' expr { $$ = crearNodo(AST_OPERACION, "+"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr '-' expr { $$ = crearNodo(AST_OPERACION, "-"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr '*' expr { $$ = crearNodo(AST_OPERACION, "*"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr '/' expr { $$ = crearNodo(AST_OPERACION, "/"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr '%' expr { $$ = crearNodo(AST_OPERACION, "%"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr TOKEN_IGUAL_IGUAL expr{ $$ = crearNodo(AST_OPERACION, "=="); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr TOKEN_NO_IGUAL expr{ $$ = crearNodo(AST_OPERACION, "!="); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr TOKEN_MAYOR expr{ $$ = crearNodo(AST_OPERACION, ">"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr TOKEN_MENOR expr{ $$ = crearNodo(AST_OPERACION, "<"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr TOKEN_MAYOR_IGUAL expr{ $$ = crearNodo(AST_OPERACION, ">="); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr TOKEN_MENOR_IGUAL expr{ $$ = crearNodo(AST_OPERACION, "<="); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr TOKEN_AND expr { $$ = crearNodo(AST_OPERACION, "&&"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr TOKEN_OR expr  { $$ = crearNodo(AST_OPERACION, "||"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | TOKEN_NOT expr %prec TOKEN_NOT  { $$ = crearNodo(AST_OPERACION, "!"); $$->linea=@1.first_line; $$->columna=@1.first_column; agregarHijo($$, $2); }
    | Cast
    | TOKEN_STRING_VALUEOF TOKEN_PARIZQ expr TOKEN_PARDER {
        $$ = crearNodo(AST_STRING, "String.valueOf");
        $$->linea = @1.first_line; $$->columna = @1.first_column;
        agregarHijo($$, $3);
    }
    | expr TOKEN_EQUAL TOKEN_PARIZQ expr TOKEN_PARDER {
        $$ = crearNodo(AST_EQUAL, ".equals");
        $$->linea = @2.first_line; $$->columna = @2.first_column;
        agregarHijo($$, $1);
        agregarHijo($$, $4);
    }
    | TOKEN_PARIZQ expr TOKEN_PARDER { $$ = $2; }
    | expr TOKEN_BIT_AND expr { $$ = crearNodo(AST_OPERACION, "&"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr TOKEN_BIT_OR expr  { $$ = crearNodo(AST_OPERACION, "|"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr TOKEN_XOR expr { $$ = crearNodo(AST_OPERACION, "^"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr TOKEN_DESIZQ expr { $$ = crearNodo(AST_OPERACION, "<<"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | expr TOKEN_DESDER expr { $$ = crearNodo(AST_OPERACION, ">>"); $$->linea=@2.first_line; $$->columna=@2.first_column; agregarHijo($$, $1); agregarHijo($$, $3); }
    | TOKEN_NUMERO         { $$ = crearNodo(AST_NUMERO, $1); $$->linea=@1.first_line; $$->columna=@1.first_column; }
    | TOKEN_FLOAT_LITERAL  { $$ = crearNodo(AST_NUMERO, $1); $$->linea=@1.first_line; $$->columna=@1.first_column; }
    | TOKEN_DOUBLE_LITERAL { $$ = crearNodo(AST_NUMERO, $1); $$->linea=@1.first_line; $$->columna=@1.first_column; }
    | TOKEN_CADENA         { $$ = crearNodo(AST_CADENA, $1); $$->linea=@1.first_line; $$->columna=@1.first_column; }
    | TOKEN_CARACTER       { $$ = crearNodo(AST_CARACTER, $1); $$->linea=@1.first_line; $$->columna=@1.first_column; }
    | TOKEN_IDENTIFICADOR  { $$ = crearNodo(AST_IDENTIFICADOR, $1); $$->linea=@1.first_line; $$->columna=@1.first_column; }
    | TOKEN_BOOLEANO       { $$ = crearNodo(AST_BOOLEAN, $1); $$->linea=@1.first_line; $$->columna=@1.first_column; }
    | expr '+' error {
         addErrorSintactico("Operando derecho faltante en suma", "+", @3.first_line, @3.first_column);
         $$ = $1;
         yyerrok;
      }
    | expr '*' error {
         addErrorSintactico("Operando derecho faltante en multiplicación", "*", @3.first_line, @3.first_column);
         $$ = $1;
         yyerrok;
      }
    ;

Cast: TOKEN_PARIZQ Tipos TOKEN_PARDER expr {
    $$ = crearNodo(AST_CAST, $2);
    $$->linea = @1.first_line; $$->columna = @1.first_column;
    agregarHijo($$, $4);
  }
  | TOKEN_PARIZQ Tipos error %prec CAST_ERROR {
      addErrorSintactico("Falta paréntesis de cierre y expresión en cast", $2, @3.first_line, @3.first_column);
      $$ = crearNodo(AST_CAST, "ERROR");
      yyerrok;
    }
  | TOKEN_PARIZQ error TOKEN_PARDER expr {
      addErrorSintactico("Tipo inválido en cast", "cast", @2.first_line, @2.first_column);
      $$ = crearNodo(AST_CAST, "ERROR");
      yyerrok;
    }
  ;

PRINT: TOKEN_PRINT TOKEN_PARIZQ expr TOKEN_PARDER TOKEN_DOBLEPUNTO {
    $$ = crearNodo(AST_PRINT, "System.out.println");
    $$->linea = @1.first_line;
    $$->columna = @1.first_column;
    agregarHijo($$, $3);
  }
    | TOKEN_PRINT TOKEN_PARIZQ expr error TOKEN_DOBLEPUNTO {
         addErrorSintactico("Falta paréntesis de cierre en System.out.println",
                            "System.out.println",
                            @4.first_line, @4.first_column);
         $$ = crearNodo(AST_PRINT, "ERROR");
         yyerrok;
      }
    | TOKEN_PRINT TOKEN_PARIZQ error TOKEN_PARDER TOKEN_DOBLEPUNTO {
         addErrorSintactico("Expresión inválida en System.out.println", 
                            "System.out.println",
                            @3.first_line, @3.first_column);
         $$ = crearNodo(AST_PRINT, "ERROR");
         yyerrok;
      }
    | TOKEN_PRINT TOKEN_PARIZQ expr TOKEN_PARDER error {
         addErrorSintactico("Falta punto y coma al final de System.out.println",
                            "System.out.println", 
                            @5.first_line, @5.first_column);
         $$ = crearNodo(AST_PRINT, "ERROR");
         yyerrok;
      }
    | TOKEN_PRINT error {
         addErrorSintactico("Sintaxis incorrecta en System.out.println",
                            "System.out.println",
                            @2.first_line, @2.first_column);
         $$ = crearNodo(AST_PRINT, "ERROR");
         yyerrok;
      }
    ;

%%

void yyerror(const char *s) {
    extern YYLTYPE yylloc;
    int linea = (yylloc.first_line > 0) ? yylloc.first_line : yylineno;
    int columna = (yylloc.first_column > 0) ? yylloc.first_column : yycolumn;
    fprintf(stderr, "%s en línea %d, columna %d\n", s, linea, columna);
}