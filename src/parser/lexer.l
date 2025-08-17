%{
#include "parser.tab.h"

int yycolumn = 1;
%}
%option yylineno

%%
int                         {return TOKEN_DINT;}
float                       {return TOKEN_DFLOAT;}
string                      {return TOKEN_DSTRING;}
char                        {return TOKEN_DCHAR;}
double                      {return TOKEN_DOUBLE;}


[0-9]+                      { yylval.str = strdup(yytext); return TOKEN_NUMERO; }
[0-9]+\.[0-9]+[fF]          { yylval.str = strdup(yytext); return TOKEN_FLOAT_LITERAL; }
[0-9]+\.[0-9]+              { yylval.str = strdup(yytext); return TOKEN_DOUBLE_LITERAL; }
\"([^"\n]|\"\")*\"          { yylval.str = strdup(yytext); return TOKEN_CADENA; }
\'[^\']\'                   { yylval.str = strdup(yytext); return TOKEN_CARACTER; }
[a-zA-Z_][a-zA-Z0-9_]*      { yylval.str = strdup(yytext); return TOKEN_IDENTIFICADOR;}


"="                         {return TOKEN_IGUAL;}
";"                         {return TOKEN_DOBLEPUNTO;}

[ \t]+                      
\
.                           { return yytext[0];} 
%%

int yywrap(void) {
    return 1;
}