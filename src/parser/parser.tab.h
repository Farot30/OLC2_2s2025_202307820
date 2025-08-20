/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_PARSER_PARSER_TAB_H_INCLUDED
# define YY_YY_SRC_PARSER_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser/parser.y"

    #include "../AST/ast.h"
    #include "../AST/errorTIpos.h" 

#line 54 "src/parser/parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_DBOOLEAN = 258,          /* TOKEN_DBOOLEAN  */
    TOKEN_BOOLEANO = 259,          /* TOKEN_BOOLEANO  */
    TOKEN_IDENTIFICADOR = 260,     /* TOKEN_IDENTIFICADOR  */
    TOKEN_DINT = 261,              /* TOKEN_DINT  */
    TOKEN_DFLOAT = 262,            /* TOKEN_DFLOAT  */
    TOKEN_DSTRING = 263,           /* TOKEN_DSTRING  */
    TOKEN_DCHAR = 264,             /* TOKEN_DCHAR  */
    TOKEN_DOUBLE = 265,            /* TOKEN_DOUBLE  */
    TOKEN_IGUAL = 266,             /* TOKEN_IGUAL  */
    TOKEN_DOBLEPUNTO = 267,        /* TOKEN_DOBLEPUNTO  */
    TOKEN_NUMERO = 268,            /* TOKEN_NUMERO  */
    TOKEN_CADENA = 269,            /* TOKEN_CADENA  */
    TOKEN_CARACTER = 270,          /* TOKEN_CARACTER  */
    TOKEN_FLOAT_LITERAL = 271,     /* TOKEN_FLOAT_LITERAL  */
    TOKEN_DOUBLE_LITERAL = 272,    /* TOKEN_DOUBLE_LITERAL  */
    TOKEN_MAS_IGUAL = 273,         /* TOKEN_MAS_IGUAL  */
    TOKEN_MENOS_IGUAL = 274,       /* TOKEN_MENOS_IGUAL  */
    TOKEN_POR_IGUAL = 275,         /* TOKEN_POR_IGUAL  */
    TOKEN_DIV_IGUAL = 276,         /* TOKEN_DIV_IGUAL  */
    TOKEN_MOD_IGUAL = 277,         /* TOKEN_MOD_IGUAL  */
    TOKEN_PRINT = 278,             /* TOKEN_PRINT  */
    TOKEN_PARIZQ = 279,            /* TOKEN_PARIZQ  */
    TOKEN_PARDER = 280,            /* TOKEN_PARDER  */
    NEG = 281                      /* NEG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "src/parser/parser.y"

    char* str;
    NodoAST* nodo;

#line 102 "src/parser/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_SRC_PARSER_PARSER_TAB_H_INCLUDED  */
