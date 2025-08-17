%{
    #include <stdio.h>
    extern int yylex(void);
    void yyerror(const char *s) {printf("error: %s\n", s); }

%}

%union {
    char* str;
}

%token <str> TOKEN_IDENTIFICADOR TOKEN_DINT TOKEN_DFLOAT TOKEN_DSTRING TOKEN_DCHAR TOKEN_DOUBLE TOKEN_IGUAL TOKEN_DOBLEPUNTO TOKEN_NUMERO TOKEN_CADENA TOKEN_CARACTER TOKEN_FLOAT_LITERAL TOKEN_DOUBLE_LITERAL

%type <str> s Lista_expresiones Declaracion expresion Tipos expr

//precedencia
%left '+' '-'
%left '*' '/' 
%left NEG

%%


s: Lista_expresiones{ printf("Cadena valida: %s\n", $1);}
    ;

Lista_expresiones: Lista_expresiones expresion
    | expresion
    ;

expresion: Declaracion
    ;

Declaracion: Tipos TOKEN_IDENTIFICADOR TOKEN_IGUAL expr TOKEN_DOBLEPUNTO

Tipos: TOKEN_DINT
    | TOKEN_DCHAR
    | TOKEN_DOUBLE
    | TOKEN_DFLOAT
    | TOKEN_DSTRING

expr: TOKEN_NUMERO
    | TOKEN_FLOAT_LITERAL
    | TOKEN_DOUBLE_LITERAL
    | TOKEN_CADENA
    | TOKEN_CARACTER
    | TOKEN_IDENTIFICADOR
    


%%
