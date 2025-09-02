%{
#define _POSIX_C_SOURCE 200809L
#include "parser.tab.h"
#include "../comun/strutil.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int yycolumn = 1;
#define YY_USER_ACTION \
    yylloc.first_line = yylineno; \
    yylloc.first_column = yycolumn; \
    yylloc.last_line = yylineno; \
    yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng;

static char map_escape(char c){
    switch(c){
        case 'n': return '\n';
        case 'r': return '\r';
        case 't': return '\t';
        case '\\': return '\\';
        case '"': return '"';
        case '\'': return '\'';
        default: return c;
    }
}

static char* unescape(const char* yytext){
    size_t len = strlen(yytext);
    if(len < 2) return strdup("");
    const char* p = yytext + 1;           // salta comilla inicial
    const char* end = yytext + len - 1;   // antes de comilla final
    char* out = (char*)malloc(len + 1);
    size_t j=0;
    while(p < end){
        if(*p == '\\' && p + 1 < end){
            out[j++] = map_escape(*(p+1));
            p += 2;
        } else {
            out[j++] = *p++;
        }
    }
    out[j] = 0;
    return out;
}
%}
%option yylineno
%option noinput nounput

%%
System.out.println          { yylval.str = strdup("System.out.println"); return TOKEN_PRINT;}
int                         { yylval.str = strdup("int");    return TOKEN_DINT; }
float                       { yylval.str = strdup("float");  return TOKEN_DFLOAT; }
string                      { yylval.str = strdup("string"); return TOKEN_DSTRING; }
char                        { yylval.str = strdup("char");   return TOKEN_DCHAR; }
double                      { yylval.str = strdup("double"); return TOKEN_DOUBLE; }
boolean                     { yylval.str = strdup("boolean"); return TOKEN_DBOOLEAN; }
true                        { yylval.str = strdup("true"); return TOKEN_BOOLEANO; }
false                       { yylval.str = strdup("false"); return TOKEN_BOOLEANO; }

[0-9]+                      { yylval.str = strdup(yytext); return TOKEN_NUMERO; }
[0-9]+\.[0-9]+[fF]          { yylval.str = strdup(yytext); return TOKEN_FLOAT_LITERAL; }
[0-9]+\.[0-9]+              { yylval.str = strdup(yytext); return TOKEN_DOUBLE_LITERAL; }


\"([^\\\"\n]|\\[nrt\"\'\\])*\" {
    yylval.str = unescape(yytext);
    return TOKEN_CADENA;
}


\'([^\\\'\n]|\\[nrt\"\'\\])\' {
    char* tmp = unescape(yytext);
    if(strlen(tmp) != 1){
        fprintf(stderr, "Carácter inválido en línea %d\n", yylineno);
        free(tmp);
        yylval.str = strdup("?");
    } else {
        yylval.str = tmp;
    }
    return TOKEN_CARACTER;
}

[a-zA-Z_][a-zA-Z0-9_]*      { yylval.str = strdup(yytext); return TOKEN_IDENTIFICADOR; }

\/\/[^\n]*                  { }
\/\*([^*]|\*+[^*/])*\*+\/   { }

"="              { return TOKEN_IGUAL; }
";"              { return TOKEN_DOBLEPUNTO; }
"+="             { return TOKEN_MAS_IGUAL; }
"-="             { return TOKEN_MENOS_IGUAL; }
"*="             { return TOKEN_POR_IGUAL; }
"/="             { return TOKEN_DIV_IGUAL; }
"%="             { return TOKEN_MOD_IGUAL; }
"("              { return TOKEN_PARIZQ; }
")"              { return TOKEN_PARDER; }



[ \t]+                      { }
\n                          { yycolumn = 1; }

.                           { fprintf(stderr, "Carácter no reconocido '%c' en línea %d, columna %d\n", 
                              yytext[0], yylineno, yycolumn);
                              return yytext[0];  
                            }

%%

int yywrap(void){ return 1; }