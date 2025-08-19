%{
#include "parser.tab.h"
int yycolumn = 1;
#define YY_USER_ACTION yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; yycolumn += yyleng;
%}
%option yylineno

%%

int                         { yylval.str = strdup("int");    return TOKEN_DINT; }
float                       { yylval.str = strdup("float");  return TOKEN_DFLOAT; }
string                      { yylval.str = strdup("string"); return TOKEN_DSTRING; }
char                        { yylval.str = strdup("char");   return TOKEN_DCHAR; }
double                      { yylval.str = strdup("double"); return TOKEN_DOUBLE; }

[0-9]+                      { yylval.str = strdup(yytext); return TOKEN_NUMERO; }
[0-9]+\.[0-9]+[fF]          { yylval.str = strdup(yytext); return TOKEN_FLOAT_LITERAL; }
[0-9]+\.[0-9]+              { yylval.str = strdup(yytext); return TOKEN_DOUBLE_LITERAL; }
\"([^"\n]|\"\")*\"          { yylval.str = strdup(yytext); return TOKEN_CADENA; }
\'[^\']\'                   { yylval.str = strdup(yytext); return TOKEN_CARACTER; }
[a-zA-Z_][a-zA-Z0-9_]*      { yylval.str = strdup(yytext); return TOKEN_IDENTIFICADOR; }

\/\/[^\n]*                  { /* Ignorar comentario de línea */ }
\/\*([^*]|\*+[^*/])*\*+\/   { /* Ignorar comentario de bloque */ }


"="                         { return TOKEN_IGUAL; }
";"                         { return TOKEN_DOBLEPUNTO; }
[ \t]+                      { /* Espacios y tabs: solo actualiza columna */ }
\n                          { yycolumn = 1; }

.                           { return yytext[0]; }

%%

int yywrap(void) {
    return 1;
}