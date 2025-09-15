/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 11 "src/parser/parser.y"

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

#line 88 "src/parser/parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_LLAVEDER = 3,             /* TOKEN_LLAVEDER  */
  YYSYMBOL_TOKEN_LLAVEIZQ = 4,             /* TOKEN_LLAVEIZQ  */
  YYSYMBOL_TOKEN_CORCHETEIZQ = 5,          /* TOKEN_CORCHETEIZQ  */
  YYSYMBOL_TOKEN_CORCHETEDER = 6,          /* TOKEN_CORCHETEDER  */
  YYSYMBOL_TOKEN_NEW = 7,                  /* TOKEN_NEW  */
  YYSYMBOL_TOKEN_MULTI = 8,                /* TOKEN_MULTI  */
  YYSYMBOL_TOKEN_DIV = 9,                  /* TOKEN_DIV  */
  YYSYMBOL_TOKEN_MODULO = 10,              /* TOKEN_MODULO  */
  YYSYMBOL_TOKEN_MAS = 11,                 /* TOKEN_MAS  */
  YYSYMBOL_TOKEN_MENOS = 12,               /* TOKEN_MENOS  */
  YYSYMBOL_TOKEN_INCREMENTO = 13,          /* TOKEN_INCREMENTO  */
  YYSYMBOL_TOKEN_DECREMENTO = 14,          /* TOKEN_DECREMENTO  */
  YYSYMBOL_TOKEN_DBOOLEAN = 15,            /* TOKEN_DBOOLEAN  */
  YYSYMBOL_TOKEN_BOOLEANO = 16,            /* TOKEN_BOOLEANO  */
  YYSYMBOL_TOKEN_IDENTIFICADOR = 17,       /* TOKEN_IDENTIFICADOR  */
  YYSYMBOL_TOKEN_DINT = 18,                /* TOKEN_DINT  */
  YYSYMBOL_TOKEN_DFLOAT = 19,              /* TOKEN_DFLOAT  */
  YYSYMBOL_TOKEN_DSTRING = 20,             /* TOKEN_DSTRING  */
  YYSYMBOL_TOKEN_DCHAR = 21,               /* TOKEN_DCHAR  */
  YYSYMBOL_TOKEN_DOUBLE = 22,              /* TOKEN_DOUBLE  */
  YYSYMBOL_TOKEN_IGUAL = 23,               /* TOKEN_IGUAL  */
  YYSYMBOL_TOKEN_PUNTOCOMA = 24,           /* TOKEN_PUNTOCOMA  */
  YYSYMBOL_TOKEN_DOS_PUNTOS = 25,          /* TOKEN_DOS_PUNTOS  */
  YYSYMBOL_TOKEN_COMA = 26,                /* TOKEN_COMA  */
  YYSYMBOL_TOKEN_NUMERO = 27,              /* TOKEN_NUMERO  */
  YYSYMBOL_TOKEN_CADENA = 28,              /* TOKEN_CADENA  */
  YYSYMBOL_TOKEN_CARACTER = 29,            /* TOKEN_CARACTER  */
  YYSYMBOL_TOKEN_FLOAT_LITERAL = 30,       /* TOKEN_FLOAT_LITERAL  */
  YYSYMBOL_TOKEN_DOUBLE_LITERAL = 31,      /* TOKEN_DOUBLE_LITERAL  */
  YYSYMBOL_TOKEN_PRINT = 32,               /* TOKEN_PRINT  */
  YYSYMBOL_TOKEN_PARIZQ = 33,              /* TOKEN_PARIZQ  */
  YYSYMBOL_TOKEN_PARDER = 34,              /* TOKEN_PARDER  */
  YYSYMBOL_TOKEN_BIT_AND = 35,             /* TOKEN_BIT_AND  */
  YYSYMBOL_TOKEN_BIT_OR = 36,              /* TOKEN_BIT_OR  */
  YYSYMBOL_TOKEN_XOR = 37,                 /* TOKEN_XOR  */
  YYSYMBOL_TOKEN_DESIZQ = 38,              /* TOKEN_DESIZQ  */
  YYSYMBOL_TOKEN_DESDER = 39,              /* TOKEN_DESDER  */
  YYSYMBOL_TOKEN_IGUAL_IGUAL = 40,         /* TOKEN_IGUAL_IGUAL  */
  YYSYMBOL_TOKEN_NO_IGUAL = 41,            /* TOKEN_NO_IGUAL  */
  YYSYMBOL_TOKEN_MAYOR_IGUAL = 42,         /* TOKEN_MAYOR_IGUAL  */
  YYSYMBOL_TOKEN_MENOR_IGUAL = 43,         /* TOKEN_MENOR_IGUAL  */
  YYSYMBOL_TOKEN_MAYOR = 44,               /* TOKEN_MAYOR  */
  YYSYMBOL_TOKEN_MENOR = 45,               /* TOKEN_MENOR  */
  YYSYMBOL_TOKEN_AND = 46,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 47,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_NOT = 48,                 /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_IF = 49,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 50,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_SWITCH = 51,              /* TOKEN_SWITCH  */
  YYSYMBOL_TOKEN_CASE = 52,                /* TOKEN_CASE  */
  YYSYMBOL_TOKEN_DEFAULT = 53,             /* TOKEN_DEFAULT  */
  YYSYMBOL_TOKEN_BREAK = 54,               /* TOKEN_BREAK  */
  YYSYMBOL_TOKEN_WHILE = 55,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_CONTINUE = 56,            /* TOKEN_CONTINUE  */
  YYSYMBOL_TOKEN_FOR = 57,                 /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_STRING_VALUEOF = 58,      /* TOKEN_STRING_VALUEOF  */
  YYSYMBOL_TOKEN_EQUAL = 59,               /* TOKEN_EQUAL  */
  YYSYMBOL_TOKEN_PARSEINT = 60,            /* TOKEN_PARSEINT  */
  YYSYMBOL_TOKEN_PARSEFLOAT = 61,          /* TOKEN_PARSEFLOAT  */
  YYSYMBOL_TOKEN_PARSEDOUBLE = 62,         /* TOKEN_PARSEDOUBLE  */
  YYSYMBOL_TOKEN_PARSEJOIN = 63,           /* TOKEN_PARSEJOIN  */
  YYSYMBOL_TOKEN_INDEXOF = 64,             /* TOKEN_INDEXOF  */
  YYSYMBOL_TOKEN_LENGHT = 65,              /* TOKEN_LENGHT  */
  YYSYMBOL_TOKEN_ADD = 66,                 /* TOKEN_ADD  */
  YYSYMBOL_TOKEN_PUNTO = 67,               /* TOKEN_PUNTO  */
  YYSYMBOL_TOKEN_VOID = 68,                /* TOKEN_VOID  */
  YYSYMBOL_TOKEN_RETURN = 69,              /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_PUBLIC = 70,              /* TOKEN_PUBLIC  */
  YYSYMBOL_TOKEN_CLASS = 71,               /* TOKEN_CLASS  */
  YYSYMBOL_TOKEN_STATIC = 72,              /* TOKEN_STATIC  */
  YYSYMBOL_TOKEN_MAIN = 73,                /* TOKEN_MAIN  */
  YYSYMBOL_TOKEN_main = 74,                /* TOKEN_main  */
  YYSYMBOL_TOKEN_ARGS = 75,                /* TOKEN_ARGS  */
  YYSYMBOL_TOKEN_MAS_IGUAL = 76,           /* TOKEN_MAS_IGUAL  */
  YYSYMBOL_TOKEN_MENOS_IGUAL = 77,         /* TOKEN_MENOS_IGUAL  */
  YYSYMBOL_TOKEN_POR_IGUAL = 78,           /* TOKEN_POR_IGUAL  */
  YYSYMBOL_TOKEN_DIV_IGUAL = 79,           /* TOKEN_DIV_IGUAL  */
  YYSYMBOL_TOKEN_MOD_IGUAL = 80,           /* TOKEN_MOD_IGUAL  */
  YYSYMBOL_TOKEN_AND_IGUAL = 81,           /* TOKEN_AND_IGUAL  */
  YYSYMBOL_TOKEN_OR_IGUAL = 82,            /* TOKEN_OR_IGUAL  */
  YYSYMBOL_TOKEN_XOR_IGUAL = 83,           /* TOKEN_XOR_IGUAL  */
  YYSYMBOL_TOKEN_DESIZQ_IGUAL = 84,        /* TOKEN_DESIZQ_IGUAL  */
  YYSYMBOL_TOKEN_DESDER_IGUAL = 85,        /* TOKEN_DESDER_IGUAL  */
  YYSYMBOL_UMINUS = 86,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 87,                  /* $accept  */
  YYSYMBOL_s = 88,                         /* s  */
  YYSYMBOL_main_class = 89,                /* main_class  */
  YYSYMBOL_main_method = 90,               /* main_method  */
  YYSYMBOL_lista_sentencias = 91,          /* lista_sentencias  */
  YYSYMBOL_sentencia = 92,                 /* sentencia  */
  YYSYMBOL_declaracion = 93,               /* declaracion  */
  YYSYMBOL_declaracion_vector = 94,        /* declaracion_vector  */
  YYSYMBOL_lista_elementos = 95,           /* lista_elementos  */
  YYSYMBOL_lista_filas = 96,               /* lista_filas  */
  YYSYMBOL_declaracion_matriz = 97,        /* declaracion_matriz  */
  YYSYMBOL_declaracion_array_multidimensional = 98, /* declaracion_array_multidimensional  */
  YYSYMBOL_lista_bloques = 99,             /* lista_bloques  */
  YYSYMBOL_lista_elementos_o_bloques = 100, /* lista_elementos_o_bloques  */
  YYSYMBOL_DimensionesCorchetes = 101,     /* DimensionesCorchetes  */
  YYSYMBOL_Dimensiones = 102,              /* Dimensiones  */
  YYSYMBOL_acceso = 103,                   /* acceso  */
  YYSYMBOL_DimensionesAcceso = 104,        /* DimensionesAcceso  */
  YYSYMBOL_acceso_escritura = 105,         /* acceso_escritura  */
  YYSYMBOL_Funcion_void = 106,             /* Funcion_void  */
  YYSYMBOL_Llamadas = 107,                 /* Llamadas  */
  YYSYMBOL_lista_parametros = 108,         /* lista_parametros  */
  YYSYMBOL_Funcion_parametros = 109,       /* Funcion_parametros  */
  YYSYMBOL_parametros = 110,               /* parametros  */
  YYSYMBOL_tipo_primitivo = 111,           /* tipo_primitivo  */
  YYSYMBOL_asignacion = 112,               /* asignacion  */
  YYSYMBOL_expresion = 113,                /* expresion  */
  YYSYMBOL_expresion_or = 114,             /* expresion_or  */
  YYSYMBOL_expresion_and = 115,            /* expresion_and  */
  YYSYMBOL_expresion_bit_or = 116,         /* expresion_bit_or  */
  YYSYMBOL_expresion_bit_xor = 117,        /* expresion_bit_xor  */
  YYSYMBOL_expresion_bit_and = 118,        /* expresion_bit_and  */
  YYSYMBOL_expresion_equality = 119,       /* expresion_equality  */
  YYSYMBOL_expresion_relacional = 120,     /* expresion_relacional  */
  YYSYMBOL_expresion_shift = 121,          /* expresion_shift  */
  YYSYMBOL_expresion_aditiva = 122,        /* expresion_aditiva  */
  YYSYMBOL_expresion_multiplicativa = 123, /* expresion_multiplicativa  */
  YYSYMBOL_expresion_unaria = 124,         /* expresion_unaria  */
  YYSYMBOL_postfix = 125,                  /* postfix  */
  YYSYMBOL_primary = 126,                  /* primary  */
  YYSYMBOL_lista_expresiones_join = 127,   /* lista_expresiones_join  */
  YYSYMBOL_instruccion_print = 128,        /* instruccion_print  */
  YYSYMBOL_bloque = 129,                   /* bloque  */
  YYSYMBOL_instruccion_break = 130,        /* instruccion_break  */
  YYSYMBOL_instruccion_continue = 131,     /* instruccion_continue  */
  YYSYMBOL_instruccion_return = 132,       /* instruccion_return  */
  YYSYMBOL_instruccion_if = 133,           /* instruccion_if  */
  YYSYMBOL_intruccion_switch = 134,        /* intruccion_switch  */
  YYSYMBOL_lista_casos = 135,              /* lista_casos  */
  YYSYMBOL_caso = 136,                     /* caso  */
  YYSYMBOL_instruccion_while = 137,        /* instruccion_while  */
  YYSYMBOL_instruccion_for = 138           /* instruccion_for  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   887

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  160
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  408

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   341


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   108,   108,   118,   126,   136,   145,   155,   166,   177,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   205,   214,   224,   237,
     257,   268,   300,   311,   318,   329,   336,   360,   382,   409,
     429,   440,   447,   453,   462,   481,   487,   491,   501,   513,
     529,   539,   549,   563,   577,   585,   595,   607,   618,   625,
     640,   659,   691,   710,   711,   712,   713,   714,   715,   720,
     730,   733,   736,   739,   742,   745,   748,   751,   754,   757,
     767,   771,   772,   780,   781,   789,   790,   798,   799,   807,
     808,   816,   817,   822,   830,   831,   836,   841,   846,   854,
     855,   860,   868,   869,   874,   882,   883,   888,   893,   901,
     906,   911,   919,   923,   924,   930,   939,   944,   949,   954,
     959,   964,   968,   972,   977,   982,   987,   992,   998,  1005,
    1013,  1021,  1029,  1035,  1045,  1048,  1051,  1057,  1068,  1076,
    1081,  1097,  1102,  1112,  1119,  1126,  1136,  1143,  1153,  1162,
    1174,  1183,  1194,  1201,  1210,  1218,  1224,  1235,  1243,  1251,
    1262
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_LLAVEDER",
  "TOKEN_LLAVEIZQ", "TOKEN_CORCHETEIZQ", "TOKEN_CORCHETEDER", "TOKEN_NEW",
  "TOKEN_MULTI", "TOKEN_DIV", "TOKEN_MODULO", "TOKEN_MAS", "TOKEN_MENOS",
  "TOKEN_INCREMENTO", "TOKEN_DECREMENTO", "TOKEN_DBOOLEAN",
  "TOKEN_BOOLEANO", "TOKEN_IDENTIFICADOR", "TOKEN_DINT", "TOKEN_DFLOAT",
  "TOKEN_DSTRING", "TOKEN_DCHAR", "TOKEN_DOUBLE", "TOKEN_IGUAL",
  "TOKEN_PUNTOCOMA", "TOKEN_DOS_PUNTOS", "TOKEN_COMA", "TOKEN_NUMERO",
  "TOKEN_CADENA", "TOKEN_CARACTER", "TOKEN_FLOAT_LITERAL",
  "TOKEN_DOUBLE_LITERAL", "TOKEN_PRINT", "TOKEN_PARIZQ", "TOKEN_PARDER",
  "TOKEN_BIT_AND", "TOKEN_BIT_OR", "TOKEN_XOR", "TOKEN_DESIZQ",
  "TOKEN_DESDER", "TOKEN_IGUAL_IGUAL", "TOKEN_NO_IGUAL",
  "TOKEN_MAYOR_IGUAL", "TOKEN_MENOR_IGUAL", "TOKEN_MAYOR", "TOKEN_MENOR",
  "TOKEN_AND", "TOKEN_OR", "TOKEN_NOT", "TOKEN_IF", "TOKEN_ELSE",
  "TOKEN_SWITCH", "TOKEN_CASE", "TOKEN_DEFAULT", "TOKEN_BREAK",
  "TOKEN_WHILE", "TOKEN_CONTINUE", "TOKEN_FOR", "TOKEN_STRING_VALUEOF",
  "TOKEN_EQUAL", "TOKEN_PARSEINT", "TOKEN_PARSEFLOAT", "TOKEN_PARSEDOUBLE",
  "TOKEN_PARSEJOIN", "TOKEN_INDEXOF", "TOKEN_LENGHT", "TOKEN_ADD",
  "TOKEN_PUNTO", "TOKEN_VOID", "TOKEN_RETURN", "TOKEN_PUBLIC",
  "TOKEN_CLASS", "TOKEN_STATIC", "TOKEN_MAIN", "TOKEN_main", "TOKEN_ARGS",
  "TOKEN_MAS_IGUAL", "TOKEN_MENOS_IGUAL", "TOKEN_POR_IGUAL",
  "TOKEN_DIV_IGUAL", "TOKEN_MOD_IGUAL", "TOKEN_AND_IGUAL",
  "TOKEN_OR_IGUAL", "TOKEN_XOR_IGUAL", "TOKEN_DESIZQ_IGUAL",
  "TOKEN_DESDER_IGUAL", "UMINUS", "$accept", "s", "main_class",
  "main_method", "lista_sentencias", "sentencia", "declaracion",
  "declaracion_vector", "lista_elementos", "lista_filas",
  "declaracion_matriz", "declaracion_array_multidimensional",
  "lista_bloques", "lista_elementos_o_bloques", "DimensionesCorchetes",
  "Dimensiones", "acceso", "DimensionesAcceso", "acceso_escritura",
  "Funcion_void", "Llamadas", "lista_parametros", "Funcion_parametros",
  "parametros", "tipo_primitivo", "asignacion", "expresion",
  "expresion_or", "expresion_and", "expresion_bit_or", "expresion_bit_xor",
  "expresion_bit_and", "expresion_equality", "expresion_relacional",
  "expresion_shift", "expresion_aditiva", "expresion_multiplicativa",
  "expresion_unaria", "postfix", "primary", "lista_expresiones_join",
  "instruccion_print", "bloque", "instruccion_break",
  "instruccion_continue", "instruccion_return", "instruccion_if",
  "intruccion_switch", "lista_casos", "caso", "instruccion_while",
  "instruccion_for", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-317)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-155)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,    26,   -19,    56,  -317,  -317,     7,  -317,    96,   107,
      54,    54,    16,   143,   150,    90,  -317,  -317,     5,   132,
     135,   163,   166,   191,   192,   193,   194,   123,   126,   168,
     169,   200,   200,   226,  -317,  -317,    39,  -317,    13,  -317,
    -317,  -317,  -317,  -317,   172,   174,   175,  -317,   176,  -317,
     178,   195,   801,   361,  -317,   189,   190,   196,   197,   199,
     201,  -317,  -317,    36,   204,   207,   208,   209,   210,  -317,
    -317,  -317,  -317,  -317,  -317,  -317,   801,   801,   801,   801,
     801,   801,   801,   801,   801,   801,   801,   801,   211,   823,
     624,   801,   680,   121,   182,   801,  -317,   568,  -317,   158,
    -317,  -317,  -317,   763,   801,   185,   186,   202,   205,   206,
     217,  -317,  -317,  -317,   177,   213,   187,   203,   216,   -24,
      72,   117,   165,   162,  -317,   160,  -317,   218,  -317,  -317,
    -317,  -317,  -317,  -317,   801,  -317,   246,    53,  -317,  -317,
    -317,  -317,  -317,   251,  -317,  -317,  -317,  -317,  -317,  -317,
    -317,  -317,  -317,  -317,  -317,   801,     0,   227,   228,   229,
     230,   231,   232,   236,   -10,   243,   252,   244,   238,  -317,
     616,   237,   114,   240,   245,   250,  -317,   801,   801,   801,
     801,   801,   801,   801,   801,   801,   801,   801,   801,   801,
     801,   801,   801,   801,   801,   801,   801,   801,   801,   801,
     801,  -317,  -317,  -317,    43,   268,   801,   130,   255,  -317,
     279,   801,  -317,   200,   200,   282,   200,   200,   801,   688,
     265,   801,   200,   256,  -317,    23,  -317,   801,  -317,   259,
     801,   801,  -317,   262,   263,   267,   269,   276,   278,   213,
     187,   203,   216,   -24,    72,    72,   117,   117,   117,   117,
     165,   165,   162,   162,  -317,  -317,  -317,   287,   283,   300,
    -317,   273,    75,   292,   116,  -317,   277,  -317,   260,   129,
    -317,  -317,   288,   289,   293,   296,  -317,  -317,   801,  -317,
     290,   801,   294,  -317,  -317,  -317,  -317,  -317,   801,   801,
     305,    95,  -317,   319,   142,   338,  -317,   339,   142,  -317,
      15,   801,   321,     9,  -317,   801,   801,   801,   801,  -317,
    -317,   310,  -317,   313,    87,   314,   326,   801,   142,   284,
     456,   335,   456,   741,    17,  -317,   349,  -317,  -317,   330,
     456,  -317,  -317,   322,   323,   324,   325,  -317,  -317,   801,
    -317,  -317,   140,    18,  -317,   355,   295,   387,  -317,   430,
      20,    51,  -317,   339,   336,   360,   456,   318,   200,   200,
     200,   200,  -317,   362,   142,  -317,   801,   801,   344,  -317,
    -317,  -317,  -317,  -317,   378,   341,   499,  -317,  -317,  -317,
    -317,   801,    81,   380,  -317,   383,   801,  -317,   385,   368,
      82,  -317,   390,   801,  -317,   363,  -317,  -317,  -317,   801,
     389,  -317,    84,   391,  -317,   801,   392,  -317
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     0,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     6,     0,    68,     0,    63,
      66,    67,    64,    65,     0,     0,     0,   143,     0,   144,
       0,     0,     0,     0,     9,     0,     0,     0,     0,     0,
       0,    21,    23,     0,     0,     0,     0,     0,     0,    14,
      15,    16,    17,   142,    26,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,   122,     0,   116,   119,
     120,   118,   117,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   145,    80,    81,    83,    85,    87,    89,
      91,    94,    99,   102,   105,   112,   113,     0,   141,     8,
      10,    18,    19,    20,     0,    12,     0,    28,    11,    13,
      24,    25,    22,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,     0,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,    52,     0,     0,     0,     0,     0,    51,
       0,     0,   139,     0,     0,     0,     0,     0,     0,     0,
      28,     0,     0,     0,    54,     0,    58,     0,   128,     0,
       0,     0,   136,     0,     0,     0,     0,     0,     0,    82,
      84,    86,    88,    90,    92,    93,    98,    96,    97,    95,
     100,   101,   103,   104,   106,   107,   108,     0,     0,    45,
      27,     0,     0,     0,     0,    50,     0,   149,   146,     0,
     156,   155,     0,     0,     0,     0,    53,    56,     0,    55,
       0,     0,     0,   111,   126,   123,   125,   124,     0,     0,
       0,     0,    44,     0,     0,     0,    62,     0,     0,   140,
       0,     0,     0,     0,   152,     0,     0,     0,     0,    57,
     131,     0,   130,   138,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,   147,   148,     0,
       0,   150,   151,     0,     0,     0,     0,   129,   133,     0,
     132,   127,     0,     0,    33,     0,     0,     0,    61,     0,
       0,     0,    39,     0,     0,    38,     0,     0,     0,     0,
       0,     0,   137,     0,     0,    30,     0,     0,     0,    60,
      59,    42,    43,    40,     0,     0,     0,   159,   160,   157,
     158,     0,     0,     0,    32,     0,     0,    46,     0,     0,
       0,    37,     0,     0,    29,     0,    47,   153,    35,     0,
       0,    31,     0,     0,    34,     0,     0,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -317,  -317,  -317,   388,  -275,   -49,   307,  -317,  -316,  -317,
    -317,  -317,    78,    50,   152,  -317,   -31,  -317,  -317,  -317,
    -317,  -317,  -317,  -317,   -88,   320,   -52,  -317,   239,   241,
     235,   242,   234,     1,   -58,    -3,    -2,   -94,  -317,  -317,
    -317,  -317,   -29,  -317,  -317,  -317,   124,  -317,  -317,   111,
    -317,  -317
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     4,    13,    53,    54,    55,    56,   343,   382,
      57,    58,   324,   325,   208,   355,   111,    88,    60,    61,
     112,   225,    62,   262,    63,    64,   344,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     314,    65,    34,    66,    67,    68,    69,    70,   303,   304,
      71,    72
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     113,   169,    59,    35,   129,   166,    19,   350,     8,     1,
     176,   211,   331,    77,    75,   174,   188,   189,    76,    33,
     352,   365,    59,   371,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    77,   157,   159,   160,
     162,   136,    73,   353,   366,   347,   366,   349,   257,   278,
       5,   175,     6,   137,   372,   357,     7,   279,   205,   173,
     258,   301,   302,    74,    45,   390,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,   206,   353,     2,    20,
       9,   376,   203,   402,   391,   398,   207,   404,    15,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,   317,
      10,   294,   318,   210,   254,   255,   256,   392,   366,   295,
     366,    11,   319,   339,   190,   191,   192,   193,   226,   263,
     297,   340,   163,   298,    12,   233,   234,   235,   236,   237,
     238,   261,   246,   247,   248,   249,    37,   283,   164,    39,
      40,    41,    42,    43,   363,    37,    16,   364,    39,    40,
      41,    42,    43,    17,   260,   194,   195,    37,    18,   266,
      39,    40,    41,    42,    43,    21,   272,   274,    22,   275,
     198,   199,   200,   201,   202,   280,   196,   197,   282,   228,
     229,   301,   302,    23,   267,   268,    24,   270,   271,   244,
     245,   250,   251,   276,   252,   253,    25,    26,    29,    27,
      28,    30,    31,    32,    33,    89,   321,    90,    91,    92,
     326,    93,    94,   130,   131,   168,   155,   173,   177,   178,
     132,   133,   134,   185,   183,   135,   309,    36,   138,   311,
     345,   139,   140,   141,   142,   179,   313,   315,   180,   181,
     186,    37,    74,    38,    39,    40,    41,    42,    43,   329,
     182,   187,   204,   333,   334,   335,   336,   209,    44,   184,
     218,   212,   213,   214,   215,   216,   217,   219,   221,   220,
     227,   327,   222,   230,   259,    45,   383,    46,   264,   231,
      47,    48,    49,    50,   232,   265,   269,   362,   206,    59,
     277,    59,   281,   290,    51,    52,   284,   285,   129,    59,
     129,   286,   288,   287,   289,   205,   291,   293,   129,   296,
     300,   299,   305,   306,   384,   385,    59,   307,    59,   127,
     308,  -154,   316,   320,   310,    59,    59,   129,   312,   377,
     378,   379,   380,    37,   395,    38,    39,    40,    41,    42,
      43,   400,   322,   323,   337,    59,   330,   338,   341,   342,
      44,   346,   348,   406,   354,   356,   358,   359,   360,   361,
     367,   368,   127,   374,   128,   375,   381,    45,   388,    46,
    -154,  -154,    47,    48,    49,    50,    37,   386,    38,    39,
      40,    41,    42,    43,   387,   393,    51,    52,   127,   394,
     369,   396,   397,    44,   399,   403,   405,   401,   407,    14,
     165,   351,    37,   373,    38,    39,    40,    41,    42,    43,
      45,   292,    46,   167,   332,    47,    48,    49,    50,    44,
     241,   243,   239,     0,   328,   240,     0,     0,   242,    51,
      52,   127,     0,   370,     0,     0,    45,     0,    46,     0,
       0,    47,    48,    49,    50,    37,     0,    38,    39,    40,
      41,    42,    43,     0,     0,    51,    52,   127,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,     0,     0,
       0,    37,     0,    38,    39,    40,    41,    42,    43,    45,
       0,    46,     0,     0,    47,    48,    49,    50,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,    52,
     127,     0,     0,     0,     0,    45,     0,    46,     0,     0,
      47,    48,    49,    50,    37,     0,    38,    39,    40,    41,
      42,    43,     0,     0,    51,    52,     0,     0,     0,     0,
       0,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
      46,     0,     0,   389,    48,    49,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,    52,    75,
       0,  -121,     0,    76,  -121,     0,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -121,  -121,  -121,     0,     0,     0,     0,     0,
       0,   170,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,     0,   223,     0,     0,
       0,     0,     0,     0,     0,   158,     0,   171,    95,     0,
       0,     0,    96,    97,     0,   172,    95,     0,     0,     0,
      96,    97,     0,    98,    99,   100,   101,   102,     0,   103,
     224,    98,    99,   100,   101,   102,     0,   103,     0,     0,
       0,     0,     0,     0,   104,     0,     0,     0,     0,     0,
       0,     0,   104,     0,   105,     0,   106,   107,   108,   109,
     110,   161,   105,     0,   106,   107,   108,   109,   110,   273,
       0,     0,    95,     0,     0,     0,    96,    97,     0,     0,
      95,     0,     0,     0,    96,    97,     0,    98,    99,   100,
     101,   102,     0,   103,     0,    98,    99,   100,   101,   102,
       0,   103,     0,     0,     0,     0,     0,     0,   104,     0,
       0,     0,     0,     0,     0,     0,   104,     0,   105,     0,
     106,   107,   108,   109,   110,   323,   105,     0,   106,   107,
     108,   109,   110,    95,     0,     0,     0,    96,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,     0,   103,    95,     0,     0,    37,    96,
      97,    39,    40,    41,    42,    43,     0,     0,     0,   104,
      98,    99,   100,   101,   102,     0,   103,     0,     0,   105,
       0,   106,   107,   108,   109,   110,     0,     0,     0,     0,
       0,   104,     0,    95,     0,     0,     0,    96,    97,     0,
       0,   105,     0,   106,   107,   108,   109,   110,    98,    99,
     100,   101,   102,     0,   103,    95,     0,     0,     0,    96,
      97,     0,     0,     0,     0,     0,     0,     0,     0,   104,
      98,   156,   100,   101,   102,     0,   103,     0,     0,   105,
       0,   106,   107,   108,   109,   110,     0,     0,     0,     0,
       0,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,     0,   106,   107,   108,   109,   110
};

static const yytype_int16 yycheck[] =
{
      52,    95,    33,    32,    53,    93,     1,   323,     1,     1,
     104,    11,     3,    23,     1,   103,    40,    41,     5,     4,
       3,     3,    53,     3,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    23,    89,    90,    91,
      92,     5,     3,    26,    26,   320,    26,   322,     5,    26,
      24,   103,    71,    17,     3,   330,     0,    34,     5,    59,
      17,    52,    53,    24,    49,   381,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    23,    26,    70,    74,
      73,   356,   134,   399,     3,     3,    33,     3,    72,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     4,
       4,    26,     7,   155,   198,   199,   200,    26,    26,    34,
      26,     4,    17,    26,    42,    43,    44,    45,   170,   207,
       4,    34,     1,     7,    70,   177,   178,   179,   180,   181,
     182,     1,   190,   191,   192,   193,    15,   231,    17,    18,
      19,    20,    21,    22,     4,    15,     3,     7,    18,    19,
      20,    21,    22,     3,   206,    38,    39,    15,    68,   211,
      18,    19,    20,    21,    22,    33,   218,   219,    33,   221,
       8,     9,    10,    13,    14,   227,    11,    12,   230,    65,
      66,    52,    53,    20,   213,   214,    20,   216,   217,   188,
     189,   194,   195,   222,   196,   197,     5,     5,    75,     6,
       6,    75,    34,    34,     4,    33,   294,    33,    33,    33,
     298,    33,    17,    24,    24,    33,     5,    59,    33,    33,
      24,    24,    23,    36,    47,    24,   278,     1,    24,   281,
     318,    24,    24,    24,    24,    33,   288,   289,    33,    33,
      37,    15,    24,    17,    18,    19,    20,    21,    22,   301,
      33,    35,     6,   305,   306,   307,   308,     6,    32,    46,
      24,    34,    34,    34,    34,    34,    34,    24,    24,    17,
      33,   300,    34,    33,     6,    49,   364,    51,    23,    34,
      54,    55,    56,    57,    34,     6,     4,   339,    23,   320,
      34,   322,    33,     6,    68,    69,    34,    34,   347,   330,
     349,    34,    26,    34,    26,     5,    23,    34,   357,    17,
      50,    34,    24,    24,   366,   367,   347,    24,   349,     1,
      24,     3,    17,     4,    34,   356,   357,   376,    34,   358,
     359,   360,   361,    15,   386,    17,    18,    19,    20,    21,
      22,   393,     4,     4,    34,   376,    25,    34,    34,    23,
      32,    67,    17,   405,     5,    25,    34,    34,    34,    34,
       5,    66,     1,    27,     3,     5,     4,    49,    27,    51,
      52,    53,    54,    55,    56,    57,    15,    33,    17,    18,
      19,    20,    21,    22,     6,     5,    68,    69,     1,     6,
       3,     6,    24,    32,     4,     6,     5,    34,     6,    11,
      93,   323,    15,   353,    17,    18,    19,    20,    21,    22,
      49,   259,    51,    93,   303,    54,    55,    56,    57,    32,
     185,   187,   183,    -1,   300,   184,    -1,    -1,   186,    68,
      69,     1,    -1,     3,    -1,    -1,    49,    -1,    51,    -1,
      -1,    54,    55,    56,    57,    15,    -1,    17,    18,    19,
      20,    21,    22,    -1,    -1,    68,    69,     1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    17,    18,    19,    20,    21,    22,    49,
      -1,    51,    -1,    -1,    54,    55,    56,    57,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
       1,    -1,    -1,    -1,    -1,    49,    -1,    51,    -1,    -1,
      54,    55,    56,    57,    15,    -1,    17,    18,    19,    20,
      21,    22,    -1,    -1,    68,    69,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      51,    -1,    -1,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,     1,
      -1,     3,    -1,     5,     6,    -1,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    59,    12,    -1,
      -1,    -1,    16,    17,    -1,    67,    12,    -1,    -1,    -1,
      16,    17,    -1,    27,    28,    29,    30,    31,    -1,    33,
      34,    27,    28,    29,    30,    31,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    58,    -1,    60,    61,    62,    63,
      64,     1,    58,    -1,    60,    61,    62,    63,    64,     1,
      -1,    -1,    12,    -1,    -1,    -1,    16,    17,    -1,    -1,
      12,    -1,    -1,    -1,    16,    17,    -1,    27,    28,    29,
      30,    31,    -1,    33,    -1,    27,    28,    29,    30,    31,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    58,    -1,
      60,    61,    62,    63,    64,     4,    58,    -1,    60,    61,
      62,    63,    64,    12,    -1,    -1,    -1,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    -1,    33,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    48,
      27,    28,    29,    30,    31,    -1,    33,    -1,    -1,    58,
      -1,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    12,    -1,    -1,    -1,    16,    17,    -1,
      -1,    58,    -1,    60,    61,    62,    63,    64,    27,    28,
      29,    30,    31,    -1,    33,    12,    -1,    -1,    -1,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      27,    28,    29,    30,    31,    -1,    33,    -1,    -1,    58,
      -1,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    60,    61,    62,    63,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    70,    88,    89,    24,    71,     0,     1,    73,
       4,     4,    70,    90,    90,    72,     3,     3,    68,     1,
      74,    33,    33,    20,    20,     5,     5,     6,     6,    75,
      75,    34,    34,     4,   129,   129,     1,    15,    17,    18,
      19,    20,    21,    22,    32,    49,    51,    54,    55,    56,
      57,    68,    69,    91,    92,    93,    94,    97,    98,   103,
     105,   106,   109,   111,   112,   128,   130,   131,   132,   133,
     134,   137,   138,     3,    24,     1,     5,    23,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,   104,    33,
      33,    33,    33,    33,    17,    12,    16,    17,    27,    28,
      29,    30,    31,    33,    48,    58,    60,    61,    62,    63,
      64,   103,   107,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     1,     3,    92,
      24,    24,    24,    24,    23,    24,     5,    17,    24,    24,
      24,    24,    24,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,     5,    28,   113,     1,   113,
     113,     1,   113,     1,    17,    93,   111,   112,    33,   124,
      33,    59,    67,    59,   111,   113,   124,    33,    33,    33,
      33,    33,    33,    47,    46,    36,    37,    35,    40,    41,
      42,    43,    44,    45,    38,    39,    11,    12,     8,     9,
      10,    13,    14,   113,     6,     5,    23,    33,   101,     6,
     113,    11,    34,    34,    34,    34,    34,    34,    24,    24,
      17,    24,    34,     1,    34,   108,   113,    33,    65,    66,
      33,    34,    34,   113,   113,   113,   113,   113,   113,   115,
     116,   117,   118,   119,   120,   120,   121,   121,   121,   121,
     122,   122,   123,   123,   124,   124,   124,     5,    17,     6,
     113,     1,   110,   111,    23,     6,   113,   129,   129,     4,
     129,   129,   113,     1,   113,   113,   129,    34,    26,    34,
     113,    33,   113,   124,    34,    34,    34,    34,    26,    26,
       6,    23,   101,    34,    26,    34,    17,     4,     7,    34,
      50,    52,    53,   135,   136,    24,    24,    24,    24,   113,
      34,   113,    34,   113,   127,   113,    17,     4,     7,    17,
       4,   111,     4,     4,    99,   100,   111,   129,   133,   113,
      25,     3,   136,   113,   113,   113,   113,    34,    34,    26,
      34,    34,    23,    95,   113,   111,    67,    91,    17,    91,
      95,    99,     3,    26,     5,   102,    25,    91,    34,    34,
      34,    34,   113,     4,     7,     3,    26,     5,    66,     3,
       3,     3,     3,   100,    27,     5,    91,   129,   129,   129,
     129,     4,    96,   111,   113,   113,    33,     6,    27,    54,
      95,     3,    26,     5,     6,   113,     6,    24,     3,     4,
     113,    34,    95,     6,     3,     5,   113,     6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    89,    89,    90,    90,    91,    91,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    93,    93,    94,
      94,    94,    95,    95,    96,    96,    97,    97,    98,    98,
      99,    99,   100,   100,   101,   101,   102,   102,   103,   103,
     104,   104,   105,   106,   107,   107,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   111,   111,   111,   111,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     113,   114,   114,   115,   115,   116,   116,   117,   117,   118,
     118,   119,   119,   119,   120,   120,   120,   120,   120,   121,
     121,   121,   122,   122,   122,   123,   123,   123,   123,   124,
     124,   124,   124,   125,   125,   125,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   127,   127,   128,
     128,   129,   129,   130,   131,   132,   133,   133,   133,   133,
     134,   135,   135,   136,   136,   137,   137,   138,   138,   138,
     138
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     6,     6,    11,    11,     2,     1,
       2,     2,     2,     2,     1,     1,     1,     1,     2,     2,
       2,     1,     2,     1,     2,     2,     2,     4,     2,    10,
       8,    11,     3,     1,     5,     3,    15,    10,     7,     7,
       3,     1,     3,     3,     3,     2,     3,     4,     2,     2,
       4,     3,     3,     5,     3,     4,     4,     3,     1,     8,
       8,     4,     2,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     2,
       2,     4,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     6,     3,     6,
       5,     5,     6,     6,     1,     1,     3,     3,     1,     4,
       6,     3,     3,     1,     1,     2,     5,     7,     7,     5,
       7,     2,     1,     6,     3,     5,     5,     9,     9,     9,
       9
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* s: main_class  */
#line 108 "src/parser/parser.y"
               {
        printf("\n=== ESTRUCTURA DEL AST ===\n");
        imprimirAST((yyvsp[0].nodo), 0);
        interpretarPrograma((yyvsp[0].nodo));
        printf("ejecutando exportarAST\n");
        exportarAST((yyvsp[0].nodo), "ast.dot", "ast.png");
        printf("\n=== LIBERANDO MEMORIA ===\n");
        liberarAST((yyvsp[0].nodo));
        printf("[DEBUG] Procesamiento completado.\n");
    }
#line 1994 "src/parser/parser.tab.c"
    break;

  case 3: /* s: error TOKEN_PUNTOCOMA  */
#line 118 "src/parser/parser.y"
                            {
        addErrorSintactico("El código debe estar dentro de 'public class Main { ... }'", "global", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.nodo) = NULL;
        yyerrok;
    }
#line 2004 "src/parser/parser.tab.c"
    break;

  case 4: /* main_class: TOKEN_PUBLIC TOKEN_CLASS TOKEN_MAIN TOKEN_LLAVEIZQ main_method TOKEN_LLAVEDER  */
#line 126 "src/parser/parser.y"
                                                                                  {
        if (strcmp((yyvsp[-3].str), "Main") != 0) {
            addErrorSintactico("El nombre de la clase debe ser 'Main'", "global", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
            (yyval.nodo) = NULL;
        } else {
            (yyval.nodo) = crearNodo(AST_CLASE, "public class Main");
            (yyval.nodo)->linea = (yylsp[-4]).first_line; (yyval.nodo)->columna = (yylsp[-4]).first_column;
            agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
        }
    }
#line 2019 "src/parser/parser.tab.c"
    break;

  case 5: /* main_class: TOKEN_PUBLIC TOKEN_CLASS error TOKEN_LLAVEIZQ main_method TOKEN_LLAVEDER  */
#line 136 "src/parser/parser.y"
                                                                               {
        addErrorSintactico("Error en el nombre de la clase, debe ser 'Main'", "global", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
        (yyval.nodo) = crearNodo(AST_CLASE, "public class Main");
        (yyval.nodo)->linea = (yylsp[-4]).first_line; (yyval.nodo)->columna = (yylsp[-4]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 2030 "src/parser/parser.tab.c"
    break;

  case 6: /* main_method: TOKEN_PUBLIC TOKEN_STATIC TOKEN_VOID TOKEN_main TOKEN_PARIZQ TOKEN_DSTRING TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_ARGS TOKEN_PARDER bloque  */
#line 145 "src/parser/parser.y"
                                                                                                                                                  {
        if (strcmp((yyvsp[-7].str), "main") != 0) {
            addErrorSintactico("El método principal debe llamarse 'main'", "global", (yylsp[-7]).first_line, (yylsp[-7]).first_column);
            (yyval.nodo) = NULL;
        } else {
            (yyval.nodo) = crearNodo(AST_METODO_MAIN, "public static void main");
            (yyval.nodo)->linea = (yylsp[-9]).first_line; (yyval.nodo)->columna = (yylsp[-9]).first_column;
            agregarHijo((yyval.nodo), (yyvsp[0].nodo));
        }
    }
#line 2045 "src/parser/parser.tab.c"
    break;

  case 7: /* main_method: TOKEN_PUBLIC TOKEN_STATIC TOKEN_VOID error TOKEN_PARIZQ TOKEN_DSTRING TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_ARGS TOKEN_PARDER bloque  */
#line 155 "src/parser/parser.y"
                                                                                                                                               {
        addErrorSintactico("El método principal debe llamarse 'main'", "global", (yylsp[-7]).first_line, (yylsp[-7]).first_column);
        (yyval.nodo) = crearNodo(AST_METODO_MAIN, "public static void main");
        (yyval.nodo)->linea = (yylsp[-9]).first_line; (yyval.nodo)->columna = (yylsp[-9]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 2056 "src/parser/parser.tab.c"
    break;

  case 8: /* lista_sentencias: lista_sentencias sentencia  */
#line 166 "src/parser/parser.y"
                               { 
        if ((yyvsp[-1].nodo)->tipo != AST_LISTA) {
            NodoAST* lista = crearNodo(AST_LISTA, "Programa");
            agregarHijo(lista, (yyvsp[-1].nodo));
            if ((yyvsp[0].nodo)) agregarHijo(lista, (yyvsp[0].nodo));
            (yyval.nodo) = lista;
        } else {
            if ((yyvsp[0].nodo)) agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo));
            (yyval.nodo) = (yyvsp[-1].nodo);
        }
    }
#line 2072 "src/parser/parser.tab.c"
    break;

  case 9: /* lista_sentencias: sentencia  */
#line 177 "src/parser/parser.y"
                { 
        if ((yyvsp[0].nodo)) {
            (yyval.nodo) = (yyvsp[0].nodo);
        } else {
            (yyval.nodo) = crearNodo(AST_LISTA, "Programa");
        }
    }
#line 2084 "src/parser/parser.tab.c"
    break;

  case 10: /* sentencia: declaracion TOKEN_PUNTOCOMA  */
#line 188 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2090 "src/parser/parser.tab.c"
    break;

  case 11: /* sentencia: asignacion TOKEN_PUNTOCOMA  */
#line 189 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2096 "src/parser/parser.tab.c"
    break;

  case 12: /* sentencia: acceso_escritura TOKEN_PUNTOCOMA  */
#line 190 "src/parser/parser.y"
                                       { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2102 "src/parser/parser.tab.c"
    break;

  case 13: /* sentencia: instruccion_print TOKEN_PUNTOCOMA  */
#line 191 "src/parser/parser.y"
                                        { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2108 "src/parser/parser.tab.c"
    break;

  case 14: /* sentencia: instruccion_if  */
#line 192 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2114 "src/parser/parser.tab.c"
    break;

  case 15: /* sentencia: intruccion_switch  */
#line 193 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2120 "src/parser/parser.tab.c"
    break;

  case 16: /* sentencia: instruccion_while  */
#line 194 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2126 "src/parser/parser.tab.c"
    break;

  case 17: /* sentencia: instruccion_for  */
#line 195 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2132 "src/parser/parser.tab.c"
    break;

  case 18: /* sentencia: declaracion_vector TOKEN_PUNTOCOMA  */
#line 196 "src/parser/parser.y"
                                              { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2138 "src/parser/parser.tab.c"
    break;

  case 19: /* sentencia: declaracion_matriz TOKEN_PUNTOCOMA  */
#line 197 "src/parser/parser.y"
                                              { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2144 "src/parser/parser.tab.c"
    break;

  case 20: /* sentencia: declaracion_array_multidimensional TOKEN_PUNTOCOMA  */
#line 198 "src/parser/parser.y"
                                                         { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2150 "src/parser/parser.tab.c"
    break;

  case 21: /* sentencia: Funcion_void  */
#line 199 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2156 "src/parser/parser.tab.c"
    break;

  case 22: /* sentencia: instruccion_return TOKEN_PUNTOCOMA  */
#line 200 "src/parser/parser.y"
                                         { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2162 "src/parser/parser.tab.c"
    break;

  case 23: /* sentencia: Funcion_parametros  */
#line 201 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2168 "src/parser/parser.tab.c"
    break;

  case 24: /* sentencia: instruccion_break TOKEN_PUNTOCOMA  */
#line 202 "src/parser/parser.y"
                                        {(yyval.nodo) = (yyvsp[-1].nodo); }
#line 2174 "src/parser/parser.tab.c"
    break;

  case 25: /* sentencia: instruccion_continue TOKEN_PUNTOCOMA  */
#line 203 "src/parser/parser.y"
                                           {(yyval.nodo) = (yyvsp[-1].nodo); }
#line 2180 "src/parser/parser.tab.c"
    break;

  case 26: /* sentencia: error TOKEN_PUNTOCOMA  */
#line 205 "src/parser/parser.y"
                                    { 
        addErrorSintactico("Instrucción inválida", "global", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        yyerrok; 
        (yyval.nodo) = NULL;
    }
#line 2190 "src/parser/parser.tab.c"
    break;

  case 27: /* declaracion: tipo_primitivo TOKEN_IDENTIFICADOR TOKEN_IGUAL expresion  */
#line 214 "src/parser/parser.y"
                                                             {
        (yyval.nodo) = crearNodo(AST_DECLARACION, "declaracion");
        (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;
        agregarHijo((yyval.nodo), crearNodo(AST_TIPO, (yyvsp[-3].str)));
        
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-2].str));
        id->linea = (yylsp[-2]).first_line; id->columna = (yylsp[-2]).first_column;
        agregarHijo((yyval.nodo), id);
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 2205 "src/parser/parser.tab.c"
    break;

  case 28: /* declaracion: tipo_primitivo TOKEN_IDENTIFICADOR  */
#line 224 "src/parser/parser.y"
                                         {
        (yyval.nodo) = crearNodo(AST_DECLARACION, "declaracion");
        (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
        agregarHijo((yyval.nodo), crearNodo(AST_TIPO, (yyvsp[-1].str)));
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[0].str));
        id->linea = (yylsp[0]).first_line; id->columna = (yylsp[0]).first_column;
        NodoAST* def = crearNodo(AST_CADENA, (char*)valorPorDefectoTipo(obtenerTipoDesdeString((yyvsp[-1].str))));
        agregarHijo((yyval.nodo), id);
        agregarHijo((yyval.nodo), def);
    }
#line 2220 "src/parser/parser.tab.c"
    break;

  case 29: /* declaracion_vector: tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_NEW tipo_primitivo TOKEN_CORCHETEIZQ expresion TOKEN_CORCHETEDER  */
#line 237 "src/parser/parser.y"
                                                                                                                                                              {
        (yyval.nodo) = crearNodo(AST_DECLARACION_VECTOR, "Declaración Vector");
        (yyval.nodo)->linea = (yylsp[-6]).first_line; (yyval.nodo)->columna = (yylsp[-6]).first_column;
        agregarHijo((yyval.nodo), crearNodo(AST_TIPO, (yyvsp[-9].str)));
        
        // Crea el nodo identificador con línea y columna
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-6].str));
        id->linea = (yylsp[-6]).first_line; 
        id->columna = (yylsp[-6]).first_column;
        agregarHijo((yyval.nodo), id);

        NodoAST* id2 = crearNodo(AST_TIPO, (yyvsp[-3].str));
        id2->linea = (yylsp[-3]).first_line; 
        id2->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), id2);
        
        NodoAST* dimension = crearNodo(AST_1DIMENSION, "Dimensión");
        agregarHijo(dimension, (yyvsp[-1].nodo));
        agregarHijo((yyval.nodo), dimension);
    }
#line 2245 "src/parser/parser.tab.c"
    break;

  case 30: /* declaracion_vector: tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_LLAVEIZQ lista_elementos TOKEN_LLAVEDER  */
#line 257 "src/parser/parser.y"
                                                                                                                                       {
        (yyval.nodo) = crearNodo(AST_DECLARACION_VECTOR, "Declaración Vector");
        (yyval.nodo)->linea = (yylsp[-4]).first_line; (yyval.nodo)->columna = (yylsp[-4]).first_column;
        agregarHijo((yyval.nodo), crearNodo(AST_TIPO, (yyvsp[-7].str)));
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-4].str));
        id->linea = (yylsp[-4]).first_line; id->columna = (yylsp[-4]).first_column;
        agregarHijo((yyval.nodo), id);
        NodoAST* lista = crearNodo(AST_LISTA_ELEMENTOS, "Lista Elementos");
        agregarHijo(lista, (yyvsp[-1].nodo));
        agregarHijo((yyval.nodo), lista);
    }
#line 2261 "src/parser/parser.tab.c"
    break;

  case 31: /* declaracion_vector: tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_IDENTIFICADOR TOKEN_PUNTO TOKEN_ADD TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 268 "src/parser/parser.y"
                                                                                                                                                                       {
        (yyval.nodo) = crearNodo(AST_DECLARACION_VECTOR, "Declaración Vector");
        (yyval.nodo)->linea = (yylsp[-7]).first_line; (yyval.nodo)->columna = (yylsp[-7]).first_column;
        
        // Tipo declarado
        agregarHijo((yyval.nodo), crearNodo(AST_TIPO, (yyvsp[-10].str)));
        
        // Identificador del nuevo vector
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-7].str));
        id->linea = (yylsp[-7]).first_line; id->columna = (yylsp[-7]).first_column;
        agregarHijo((yyval.nodo), id);
        
        // Crear el nodo para la operación add
        NodoAST* addNode = crearNodo(AST_ADD, "Array.add");
        addNode->linea = (yylsp[-4]).first_line; addNode->columna = (yylsp[-4]).first_column;
        
        // Identificador del vector origen
        NodoAST* idOrig = crearNodo(AST_IDENTIFICADOR, (yyvsp[-5].str));
        idOrig->linea = (yylsp[-5]).first_line; idOrig->columna = (yylsp[-5]).first_column;
        agregarHijo(addNode, idOrig);
        
        // Valor a añadir
        agregarHijo(addNode, (yyvsp[-1].nodo));
        
        // Añadir el nodo add como lista de elementos
        NodoAST* lista = crearNodo(AST_LISTA_ELEMENTOS, "Lista Elementos");
        agregarHijo(lista, addNode);
        agregarHijo((yyval.nodo), lista);
    }
#line 2295 "src/parser/parser.tab.c"
    break;

  case 32: /* lista_elementos: lista_elementos TOKEN_COMA expresion  */
#line 300 "src/parser/parser.y"
                                         {
        if ((yyvsp[-2].nodo)->tipo != AST_INTERNO) {
            NodoAST* lista = crearNodo(AST_INTERNO, "Lista Elementos");
            agregarHijo(lista, (yyvsp[-2].nodo));
            agregarHijo(lista, (yyvsp[0].nodo));
            (yyval.nodo) = lista;
        } else {
            agregarHijo((yyvsp[-2].nodo), (yyvsp[0].nodo));
            (yyval.nodo) = (yyvsp[-2].nodo);
        }
    }
#line 2311 "src/parser/parser.tab.c"
    break;

  case 33: /* lista_elementos: expresion  */
#line 311 "src/parser/parser.y"
                {
        (yyval.nodo) = crearNodo(AST_INTERNO, "Lista Elementos");
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 2320 "src/parser/parser.tab.c"
    break;

  case 34: /* lista_filas: lista_filas TOKEN_COMA TOKEN_LLAVEIZQ lista_elementos TOKEN_LLAVEDER  */
#line 318 "src/parser/parser.y"
                                                                         {
        if ((yyvsp[-4].nodo)->tipo != AST_LISTA_ELEMENTOS) {
            NodoAST* lista = crearNodo(AST_LISTA_ELEMENTOS, "Lista Filas");
            agregarHijo(lista, (yyvsp[-4].nodo));
            agregarHijo(lista, (yyvsp[-1].nodo));
            (yyval.nodo) = lista;
        } else {
            agregarHijo((yyvsp[-4].nodo), (yyvsp[-1].nodo));
            (yyval.nodo) = (yyvsp[-4].nodo);
        }
    }
#line 2336 "src/parser/parser.tab.c"
    break;

  case 35: /* lista_filas: TOKEN_LLAVEIZQ lista_elementos TOKEN_LLAVEDER  */
#line 329 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crearNodo(AST_LISTA_ELEMENTOS, "Lista Filas");
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 2345 "src/parser/parser.tab.c"
    break;

  case 36: /* declaracion_matriz: tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_NEW tipo_primitivo TOKEN_CORCHETEIZQ expresion TOKEN_CORCHETEDER TOKEN_CORCHETEIZQ expresion TOKEN_CORCHETEDER  */
#line 336 "src/parser/parser.y"
                                                                                                                                                                                                                                                {
        (yyval.nodo) = crearNodo(AST_DECLARACION_MATRIZ, "Declaración Matriz");
        (yyval.nodo)->linea = (yylsp[-9]).first_line; (yyval.nodo)->columna = (yylsp[-9]).first_column;
        
        // Tipo declarado
        NodoAST* tipo = crearNodo(AST_TIPO, (yyvsp[-14].str));
        tipo->linea = (yylsp[-14]).first_line; tipo->columna = (yylsp[-14]).first_column;
        agregarHijo((yyval.nodo), tipo);
        
        // Identificador
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-9].str));
        id->linea = (yylsp[-9]).first_line; id->columna = (yylsp[-9]).first_column;
        agregarHijo((yyval.nodo), id);
        
        // Tipo en new
        NodoAST* tipoNew = crearNodo(AST_TIPO, (yyvsp[-6].str));
        tipoNew->linea = (yylsp[-6]).first_line; tipoNew->columna = (yylsp[-6]).first_column;
        agregarHijo((yyval.nodo), tipoNew);
        
        NodoAST* dimension = crearNodo(AST_DIMENSIONES, "Dimensiones");
        agregarHijo(dimension, (yyvsp[-4].nodo));
        agregarHijo(dimension, (yyvsp[-1].nodo));
        agregarHijo((yyval.nodo), dimension);
    }
#line 2374 "src/parser/parser.tab.c"
    break;

  case 37: /* declaracion_matriz: tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_LLAVEIZQ lista_filas TOKEN_LLAVEDER  */
#line 360 "src/parser/parser.y"
                                                                                                                                                                       {
        (yyval.nodo) = crearNodo(AST_DECLARACION_MATRIZ, "Declaración Matriz");
        (yyval.nodo)->linea = (yylsp[-4]).first_line; (yyval.nodo)->columna = (yylsp[-4]).first_column;
        
        // Tipo declarado
        NodoAST* tipo = crearNodo(AST_TIPO, (yyvsp[-9].str));
        tipo->linea = (yylsp[-9]).first_line; tipo->columna = (yylsp[-9]).first_column;
        agregarHijo((yyval.nodo), tipo);
        
        // Identificador
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-4].str));
        id->linea = (yylsp[-4]).first_line; id->columna = (yylsp[-4]).first_column;
        agregarHijo((yyval.nodo), id);
        
        // Lista de elementos
        NodoAST* lista = crearNodo(AST_LISTA_ELEMENTOS, "Lista Elementos");
        agregarHijo(lista, (yyvsp[-1].nodo));
        agregarHijo((yyval.nodo), lista);
    }
#line 2398 "src/parser/parser.tab.c"
    break;

  case 38: /* declaracion_array_multidimensional: tipo_primitivo TOKEN_IDENTIFICADOR DimensionesCorchetes TOKEN_IGUAL TOKEN_NEW tipo_primitivo Dimensiones  */
#line 382 "src/parser/parser.y"
                                                                                                             {
        (yyval.nodo) = crearNodo(AST_DECLARACION_ARRAY_MULTIDIMENSIONAL, "Declaración Array Multidimensional");
        (yyval.nodo)->linea = (yylsp[-5]).first_line; (yyval.nodo)->columna = (yylsp[-5]).first_column;

        // Tipo declarado
        NodoAST* tipo = crearNodo(AST_TIPO, (yyvsp[-6].str));
        tipo->linea = (yylsp[-6]).first_line; tipo->columna = (yylsp[-6]).first_column;
        agregarHijo((yyval.nodo), tipo);

        // Identificador
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-5].str));
        id->linea = (yylsp[-5]).first_line; id->columna = (yylsp[-5]).first_column;
        agregarHijo((yyval.nodo), id);

        // Tipo en new
        NodoAST* tipoNew = crearNodo(AST_TIPO, (yyvsp[-1].str));
        tipoNew->linea = (yylsp[-1]).first_line; tipoNew->columna = (yylsp[-1]).first_column;
        agregarHijo((yyval.nodo), tipoNew);

        // Dimensiones explícitas
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));

        // Validación de consistencia entre corchetes y dimensiones
        if ((yyvsp[-4].nodo)->num_hijos != (yyvsp[0].nodo)->num_hijos) {
            addErrorSintactico("El número de corchetes no coincide con las dimensiones especificadas", "global", (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        }
    }
#line 2430 "src/parser/parser.tab.c"
    break;

  case 39: /* declaracion_array_multidimensional: tipo_primitivo TOKEN_IDENTIFICADOR DimensionesCorchetes TOKEN_IGUAL TOKEN_LLAVEIZQ lista_bloques TOKEN_LLAVEDER  */
#line 409 "src/parser/parser.y"
                                                                                                                      {
        (yyval.nodo) = crearNodo(AST_DECLARACION_ARRAY_MULTIDIMENSIONAL, "Declaración Array Multidimensional");
        (yyval.nodo)->linea = (yylsp[-5]).first_line; (yyval.nodo)->columna = (yylsp[-5]).first_column;

        // Tipo declarado
        NodoAST* tipo = crearNodo(AST_TIPO, (yyvsp[-6].str));
        tipo->linea = (yylsp[-6]).first_line; tipo->columna = (yylsp[-6]).first_column;
        agregarHijo((yyval.nodo), tipo);

        // Identificador
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-5].str));
        id->linea = (yylsp[-5]).first_line; id->columna = (yylsp[-5]).first_column;
        agregarHijo((yyval.nodo), id);

        // Lista de bloques anidados
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 2452 "src/parser/parser.tab.c"
    break;

  case 40: /* lista_bloques: lista_bloques TOKEN_COMA lista_elementos_o_bloques  */
#line 429 "src/parser/parser.y"
                                                       {
        if ((yyvsp[-2].nodo)->tipo != AST_INTERNO) {
            NodoAST* lista = crearNodo(AST_INTERNO, "Lista Bloques");
            agregarHijo(lista, (yyvsp[-2].nodo));
            agregarHijo(lista, (yyvsp[0].nodo));
            (yyval.nodo) = lista;
        } else {
            agregarHijo((yyvsp[-2].nodo), (yyvsp[0].nodo));
            (yyval.nodo) = (yyvsp[-2].nodo);
        }
    }
#line 2468 "src/parser/parser.tab.c"
    break;

  case 41: /* lista_bloques: lista_elementos_o_bloques  */
#line 440 "src/parser/parser.y"
                                {
        (yyval.nodo) = crearNodo(AST_INTERNO, "Lista Bloques");
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 2477 "src/parser/parser.tab.c"
    break;

  case 42: /* lista_elementos_o_bloques: TOKEN_LLAVEIZQ lista_elementos TOKEN_LLAVEDER  */
#line 447 "src/parser/parser.y"
                                                  {
        // Caso: lista de elementos
        NodoAST* bloque = crearNodo(AST_INTERNO, "Bloque");
        agregarHijo(bloque, (yyvsp[-1].nodo));
        (yyval.nodo) = bloque;
    }
#line 2488 "src/parser/parser.tab.c"
    break;

  case 43: /* lista_elementos_o_bloques: TOKEN_LLAVEIZQ lista_bloques TOKEN_LLAVEDER  */
#line 453 "src/parser/parser.y"
                                                  {
        // Caso: bloques anidados
        NodoAST* bloque = crearNodo(AST_INTERNO, "Bloque");
        agregarHijo(bloque, (yyvsp[-1].nodo));
        (yyval.nodo) = bloque;
    }
#line 2499 "src/parser/parser.tab.c"
    break;

  case 44: /* DimensionesCorchetes: TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER DimensionesCorchetes  */
#line 462 "src/parser/parser.y"
                                                             {
        NodoAST* dim = crearNodo(AST_DIMENSIONES, "[]");
        if ((yyvsp[0].nodo) == NULL) {
            (yyval.nodo) = dim;
        } else if ((yyvsp[0].nodo)->tipo != AST_INTERNO) {
            NodoAST* lista = crearNodo(AST_INTERNO, "Dimensiones");
            agregarHijo(lista, dim);
            agregarHijo(lista, (yyvsp[0].nodo));
            (yyval.nodo) = lista;
        } else {
            /* Insertar al principio de la lista */
            NodoAST* nueva = crearNodo(AST_INTERNO, "Dimensiones");
            agregarHijo(nueva, dim);
            for (int i = 0; i < (yyvsp[0].nodo)->num_hijos; i++) {
                agregarHijo(nueva, (yyvsp[0].nodo)->hijos[i]);
            }
            (yyval.nodo) = nueva;
        }
    }
#line 2523 "src/parser/parser.tab.c"
    break;

  case 45: /* DimensionesCorchetes: TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER  */
#line 481 "src/parser/parser.y"
                                          {
        (yyval.nodo) = crearNodo(AST_DIMENSIONES, "[]");
    }
#line 2531 "src/parser/parser.tab.c"
    break;

  case 46: /* Dimensiones: TOKEN_CORCHETEIZQ TOKEN_NUMERO TOKEN_CORCHETEDER  */
#line 487 "src/parser/parser.y"
                                                     {
        (yyval.nodo) = crearNodo(AST_DIMENSIONES, "[]");
        agregarHijo((yyval.nodo), crearNodo(AST_NUMERO, (yyvsp[-1].str)));
    }
#line 2540 "src/parser/parser.tab.c"
    break;

  case 47: /* Dimensiones: Dimensiones TOKEN_CORCHETEIZQ TOKEN_NUMERO TOKEN_CORCHETEDER  */
#line 491 "src/parser/parser.y"
                                                                   {
        agregarHijo((yyvsp[-3].nodo), crearNodo(AST_NUMERO, (yyvsp[-1].str)));
        (yyval.nodo) = (yyvsp[-3].nodo);
    }
#line 2549 "src/parser/parser.tab.c"
    break;

  case 48: /* acceso: TOKEN_IDENTIFICADOR DimensionesAcceso  */
#line 501 "src/parser/parser.y"
                                          {
        (yyval.nodo) = crearNodo(AST_ACCESO, "Acceso");
        (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;

        // Nodo para el identificador
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-1].str));
        id->linea = (yylsp[-1]).first_line; id->columna = (yylsp[-1]).first_column;
        agregarHijo((yyval.nodo), id);

        // Nodo para las dimensiones de acceso
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 2566 "src/parser/parser.tab.c"
    break;

  case 49: /* acceso: TOKEN_IDENTIFICADOR error  */
#line 513 "src/parser/parser.y"
                                {
        addErrorSintactico("Acceso inválido a array", "global", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.nodo) = crearNodo(AST_ACCESO, "Acceso");
        (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
        
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-1].str));
        id->linea = (yylsp[-1]).first_line; id->columna = (yylsp[-1]).first_column;
        agregarHijo((yyval.nodo), id);
        
        // Crear una dimensión predeterminada
        NodoAST* dim = crearNodo(AST_DIMENSIONES, "Dimensiones");
        agregarHijo((yyval.nodo), dim);
    }
#line 2584 "src/parser/parser.tab.c"
    break;

  case 50: /* DimensionesAcceso: DimensionesAcceso TOKEN_CORCHETEIZQ expresion TOKEN_CORCHETEDER  */
#line 529 "src/parser/parser.y"
                                                                    {
        if ((yyvsp[-3].nodo) == NULL) {
            (yyval.nodo) = crearNodo(AST_DIMENSIONES, "Dimensiones");
        } else {
            (yyval.nodo) = (yyvsp[-3].nodo);
        }
        NodoAST* dim = crearNodo(AST_1DIMENSION, "Dimensión");
        agregarHijo(dim, (yyvsp[-1].nodo)); // Agregar la expresión como una dimensión
        agregarHijo((yyval.nodo), dim);
    }
#line 2599 "src/parser/parser.tab.c"
    break;

  case 51: /* DimensionesAcceso: TOKEN_CORCHETEIZQ expresion TOKEN_CORCHETEDER  */
#line 539 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crearNodo(AST_DIMENSIONES, "Dimensiones");
        NodoAST* dim = crearNodo(AST_1DIMENSION, "Dimensión");
        agregarHijo(dim, (yyvsp[-1].nodo)); // Agregar la expresión como una dimensión
        agregarHijo((yyval.nodo), dim);
    }
#line 2610 "src/parser/parser.tab.c"
    break;

  case 52: /* acceso_escritura: acceso TOKEN_IGUAL expresion  */
#line 549 "src/parser/parser.y"
                                 {
        (yyval.nodo) = crearNodo(AST_ACCESO_ESCRITURA, "Acceso Escritura");
        (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;

        // Nodo para el acceso (identificador + dimensiones)
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));

        // Nodo para la expresión (valor a asignar)
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 2625 "src/parser/parser.tab.c"
    break;

  case 53: /* Funcion_void: TOKEN_VOID TOKEN_IDENTIFICADOR TOKEN_PARIZQ TOKEN_PARDER bloque  */
#line 563 "src/parser/parser.y"
                                                                    {
        (yyval.nodo) = crearNodo(AST_FUNCION_VOID, "Función void");
        (yyval.nodo)->linea = (yylsp[-4]).first_line; (yyval.nodo)->columna = (yylsp[-4]).first_column;

        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
        id->linea = (yylsp[-3]).first_line; id->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), id);

        agregarHijo((yyval.nodo), (yyvsp[0].nodo));

    }
#line 2641 "src/parser/parser.tab.c"
    break;

  case 54: /* Llamadas: TOKEN_IDENTIFICADOR TOKEN_PARIZQ TOKEN_PARDER  */
#line 577 "src/parser/parser.y"
                                                  {
        (yyval.nodo) = crearNodo(AST_LLAMADA_VOID, "Llamada funcion void");
        (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;

        NodoAST* id1 = crearNodo(AST_IDENTIFICADOR, (yyvsp[-2].str));
        id1->linea = (yylsp[-2]).first_line; id1->columna = (yylsp[-2]).first_column;
        agregarHijo((yyval.nodo), id1);
    }
#line 2654 "src/parser/parser.tab.c"
    break;

  case 55: /* Llamadas: TOKEN_IDENTIFICADOR TOKEN_PARIZQ lista_parametros TOKEN_PARDER  */
#line 585 "src/parser/parser.y"
                                                                     {
        (yyval.nodo) = crearNodo(AST_LLAMADA, "Llamada funcion");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;

        NodoAST* id1 = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
        id1->linea = (yylsp[-3]).first_line; id1->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), id1);

        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 2669 "src/parser/parser.tab.c"
    break;

  case 56: /* Llamadas: TOKEN_IDENTIFICADOR TOKEN_PARIZQ error TOKEN_PARDER  */
#line 595 "src/parser/parser.y"
                                                          {
        addErrorSintactico("Parámetros inválidos en llamada a función", "global", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.nodo) = crearNodo(AST_LLAMADA_VOID, "Llamada funcion void");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        
        NodoAST* id1 = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
        id1->linea = (yylsp[-3]).first_line; id1->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), id1);
    }
#line 2683 "src/parser/parser.tab.c"
    break;

  case 57: /* lista_parametros: lista_parametros TOKEN_COMA expresion  */
#line 607 "src/parser/parser.y"
                                          {
        if ((yyvsp[-2].nodo)->tipo != AST_LISTA_PARAMETROS) {
            NodoAST* lista = crearNodo(AST_LISTA_PARAMETROS, "Lista Parametros");
            agregarHijo(lista, (yyvsp[-2].nodo));
            agregarHijo(lista, (yyvsp[0].nodo));
            (yyval.nodo) = lista;
        } else {
            agregarHijo((yyvsp[-2].nodo), (yyvsp[0].nodo));
            (yyval.nodo) = (yyvsp[-2].nodo);
        }
    }
#line 2699 "src/parser/parser.tab.c"
    break;

  case 58: /* lista_parametros: expresion  */
#line 618 "src/parser/parser.y"
                {
        (yyval.nodo) = crearNodo(AST_LISTA_PARAMETROS, "Lista Parametros");
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 2708 "src/parser/parser.tab.c"
    break;

  case 59: /* Funcion_parametros: tipo_primitivo TOKEN_IDENTIFICADOR TOKEN_PARIZQ parametros TOKEN_PARDER TOKEN_LLAVEIZQ lista_sentencias TOKEN_LLAVEDER  */
#line 625 "src/parser/parser.y"
                                                                                                                           {
        (yyval.nodo) = crearNodo(AST_FUNCION, "Función con parametros");
        (yyval.nodo)->linea = (yylsp[-7]).first_line; (yyval.nodo)->columna = (yylsp[-7]).first_column;

        NodoAST* tipo = crearNodo(AST_TIPO, (yyvsp[-7].str));
        tipo->linea = (yylsp[-7]).first_line; tipo->columna = (yylsp[-7]).first_column;
        agregarHijo((yyval.nodo), tipo);

        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-6].str));
        id->linea = (yylsp[-6]).first_line; id->columna = (yylsp[-6]).first_column;
        agregarHijo((yyval.nodo), id);

        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 2728 "src/parser/parser.tab.c"
    break;

  case 60: /* Funcion_parametros: tipo_primitivo TOKEN_IDENTIFICADOR TOKEN_PARIZQ error TOKEN_PARDER TOKEN_LLAVEIZQ lista_sentencias TOKEN_LLAVEDER  */
#line 640 "src/parser/parser.y"
                                                                                                                        {
        addErrorSintactico("Lista de parámetros inválida en definición de función", "global", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
        (yyval.nodo) = crearNodo(AST_FUNCION, "Función con parametros");
        (yyval.nodo)->linea = (yylsp[-7]).first_line; (yyval.nodo)->columna = (yylsp[-7]).first_column;
        
        NodoAST* tipo = crearNodo(AST_TIPO, (yyvsp[-7].str));
        tipo->linea = (yylsp[-7]).first_line; tipo->columna = (yylsp[-7]).first_column;
        agregarHijo((yyval.nodo), tipo);
        
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-6].str));
        id->linea = (yylsp[-6]).first_line; id->columna = (yylsp[-6]).first_column;
        agregarHijo((yyval.nodo), id);
        
        // Crear una lista de parámetros vacía
        agregarHijo((yyval.nodo), crearNodo(AST_PARAMETROS, "parametros"));
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 2750 "src/parser/parser.tab.c"
    break;

  case 61: /* parametros: parametros TOKEN_COMA tipo_primitivo TOKEN_IDENTIFICADOR  */
#line 659 "src/parser/parser.y"
                                                             {
        if((yyvsp[-3].nodo)->tipo != AST_PARAMETROS) {
            NodoAST* lista = crearNodo(AST_PARAMETROS, "parametros");
            agregarHijo(lista, (yyvsp[-3].nodo));
            
            NodoAST* param = crearNodo(AST_PARAMETRO, "parametro");
            
            NodoAST* tipo = crearNodo(AST_TIPO, (yyvsp[-1].str));
            tipo->linea = (yylsp[-1]).first_line; tipo->columna = (yylsp[-1]).first_column;
            agregarHijo(param, tipo);
            
            NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[0].str));
            id->linea = (yylsp[0]).first_line; id->columna = (yylsp[0]).first_column;
            agregarHijo(param, id);
            
            agregarHijo(lista, param);
            (yyval.nodo) = lista;
        } else {
            NodoAST* param = crearNodo(AST_PARAMETRO, "parametro");
            
            NodoAST* tipo = crearNodo(AST_TIPO, (yyvsp[-1].str));
            tipo->linea = (yylsp[-1]).first_line; tipo->columna = (yylsp[-1]).first_column;
            agregarHijo(param, tipo);
            
            NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[0].str));
            id->linea = (yylsp[0]).first_line; id->columna = (yylsp[0]).first_column;
            agregarHijo(param, id);
            
            agregarHijo((yyvsp[-3].nodo), param);
            (yyval.nodo) = (yyvsp[-3].nodo);
        }
    }
#line 2787 "src/parser/parser.tab.c"
    break;

  case 62: /* parametros: tipo_primitivo TOKEN_IDENTIFICADOR  */
#line 691 "src/parser/parser.y"
                                         {
        (yyval.nodo) = crearNodo(AST_PARAMETROS, "parametros");
        
        NodoAST* param = crearNodo(AST_PARAMETRO, "parametro");
        
        NodoAST* tipo = crearNodo(AST_TIPO, (yyvsp[-1].str));
        tipo->linea = (yylsp[-1]).first_line; tipo->columna = (yylsp[-1]).first_column;
        agregarHijo(param, tipo);
        
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[0].str));
        id->linea = (yylsp[0]).first_line; id->columna = (yylsp[0]).first_column;
        agregarHijo(param, id);
        
        agregarHijo((yyval.nodo), param);
    }
#line 2807 "src/parser/parser.tab.c"
    break;

  case 63: /* tipo_primitivo: TOKEN_DINT  */
#line 710 "src/parser/parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2813 "src/parser/parser.tab.c"
    break;

  case 64: /* tipo_primitivo: TOKEN_DCHAR  */
#line 711 "src/parser/parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2819 "src/parser/parser.tab.c"
    break;

  case 65: /* tipo_primitivo: TOKEN_DOUBLE  */
#line 712 "src/parser/parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2825 "src/parser/parser.tab.c"
    break;

  case 66: /* tipo_primitivo: TOKEN_DFLOAT  */
#line 713 "src/parser/parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2831 "src/parser/parser.tab.c"
    break;

  case 67: /* tipo_primitivo: TOKEN_DSTRING  */
#line 714 "src/parser/parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2837 "src/parser/parser.tab.c"
    break;

  case 68: /* tipo_primitivo: TOKEN_DBOOLEAN  */
#line 715 "src/parser/parser.y"
                     { (yyval.str) = (yyvsp[0].str); }
#line 2843 "src/parser/parser.tab.c"
    break;

  case 69: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_IGUAL expresion  */
#line 720 "src/parser/parser.y"
                                              {
        (yyval.nodo) = crearNodo(AST_ASIGNACION, "");
        (yyval.nodo)->linea = (yylsp[-2]).first_line; 
        (yyval.nodo)->columna = (yylsp[-2]).first_column;
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-2].str));
        id->linea = (yylsp[-2]).first_line; 
        id->columna = (yylsp[-2]).first_column;
        agregarHijo((yyval.nodo), id);
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 2858 "src/parser/parser.tab.c"
    break;

  case 70: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_MAS_IGUAL expresion  */
#line 730 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "+", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2866 "src/parser/parser.tab.c"
    break;

  case 71: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_MENOS_IGUAL expresion  */
#line 733 "src/parser/parser.y"
                                                      {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "-", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2874 "src/parser/parser.tab.c"
    break;

  case 72: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_POR_IGUAL expresion  */
#line 736 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "*", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2882 "src/parser/parser.tab.c"
    break;

  case 73: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_DIV_IGUAL expresion  */
#line 739 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "/", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2890 "src/parser/parser.tab.c"
    break;

  case 74: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_MOD_IGUAL expresion  */
#line 742 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "%", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2898 "src/parser/parser.tab.c"
    break;

  case 75: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_AND_IGUAL expresion  */
#line 745 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "&", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2906 "src/parser/parser.tab.c"
    break;

  case 76: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_OR_IGUAL expresion  */
#line 748 "src/parser/parser.y"
                                                   {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "|", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2914 "src/parser/parser.tab.c"
    break;

  case 77: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_XOR_IGUAL expresion  */
#line 751 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "^", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2922 "src/parser/parser.tab.c"
    break;

  case 78: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_DESIZQ_IGUAL expresion  */
#line 754 "src/parser/parser.y"
                                                       {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "<<", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2930 "src/parser/parser.tab.c"
    break;

  case 79: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_DESDER_IGUAL expresion  */
#line 757 "src/parser/parser.y"
                                                       {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), ">>", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2938 "src/parser/parser.tab.c"
    break;

  case 80: /* expresion: expresion_or  */
#line 767 "src/parser/parser.y"
                   { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2944 "src/parser/parser.tab.c"
    break;

  case 81: /* expresion_or: expresion_and  */
#line 771 "src/parser/parser.y"
                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2950 "src/parser/parser.tab.c"
    break;

  case 82: /* expresion_or: expresion_or TOKEN_OR expresion_and  */
#line 772 "src/parser/parser.y"
                                          {
          (yyval.nodo) = crearNodo(AST_OPERACION, "||");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2960 "src/parser/parser.tab.c"
    break;

  case 83: /* expresion_and: expresion_bit_or  */
#line 780 "src/parser/parser.y"
                       { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2966 "src/parser/parser.tab.c"
    break;

  case 84: /* expresion_and: expresion_and TOKEN_AND expresion_bit_or  */
#line 781 "src/parser/parser.y"
                                               {
          (yyval.nodo) = crearNodo(AST_OPERACION, "&&");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2976 "src/parser/parser.tab.c"
    break;

  case 85: /* expresion_bit_or: expresion_bit_xor  */
#line 789 "src/parser/parser.y"
                        { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2982 "src/parser/parser.tab.c"
    break;

  case 86: /* expresion_bit_or: expresion_bit_or TOKEN_BIT_OR expresion_bit_xor  */
#line 790 "src/parser/parser.y"
                                                      {
          (yyval.nodo) = crearNodo(AST_OPERACION, "|");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2992 "src/parser/parser.tab.c"
    break;

  case 87: /* expresion_bit_xor: expresion_bit_and  */
#line 798 "src/parser/parser.y"
                        { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2998 "src/parser/parser.tab.c"
    break;

  case 88: /* expresion_bit_xor: expresion_bit_xor TOKEN_XOR expresion_bit_and  */
#line 799 "src/parser/parser.y"
                                                    {
          (yyval.nodo) = crearNodo(AST_OPERACION, "^");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3008 "src/parser/parser.tab.c"
    break;

  case 89: /* expresion_bit_and: expresion_equality  */
#line 807 "src/parser/parser.y"
                         { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3014 "src/parser/parser.tab.c"
    break;

  case 90: /* expresion_bit_and: expresion_bit_and TOKEN_BIT_AND expresion_equality  */
#line 808 "src/parser/parser.y"
                                                         {
          (yyval.nodo) = crearNodo(AST_OPERACION, "&");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3024 "src/parser/parser.tab.c"
    break;

  case 91: /* expresion_equality: expresion_relacional  */
#line 816 "src/parser/parser.y"
                           { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3030 "src/parser/parser.tab.c"
    break;

  case 92: /* expresion_equality: expresion_equality TOKEN_IGUAL_IGUAL expresion_relacional  */
#line 817 "src/parser/parser.y"
                                                                {
          (yyval.nodo) = crearNodo(AST_OPERACION, "==");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3040 "src/parser/parser.tab.c"
    break;

  case 93: /* expresion_equality: expresion_equality TOKEN_NO_IGUAL expresion_relacional  */
#line 822 "src/parser/parser.y"
                                                             {
          (yyval.nodo) = crearNodo(AST_OPERACION, "!=");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3050 "src/parser/parser.tab.c"
    break;

  case 94: /* expresion_relacional: expresion_shift  */
#line 830 "src/parser/parser.y"
                      { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3056 "src/parser/parser.tab.c"
    break;

  case 95: /* expresion_relacional: expresion_relacional TOKEN_MENOR expresion_shift  */
#line 831 "src/parser/parser.y"
                                                       {
          (yyval.nodo) = crearNodo(AST_OPERACION, "<");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3066 "src/parser/parser.tab.c"
    break;

  case 96: /* expresion_relacional: expresion_relacional TOKEN_MENOR_IGUAL expresion_shift  */
#line 836 "src/parser/parser.y"
                                                             {
          (yyval.nodo) = crearNodo(AST_OPERACION, "<=");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3076 "src/parser/parser.tab.c"
    break;

  case 97: /* expresion_relacional: expresion_relacional TOKEN_MAYOR expresion_shift  */
#line 841 "src/parser/parser.y"
                                                       {
          (yyval.nodo) = crearNodo(AST_OPERACION, ">");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3086 "src/parser/parser.tab.c"
    break;

  case 98: /* expresion_relacional: expresion_relacional TOKEN_MAYOR_IGUAL expresion_shift  */
#line 846 "src/parser/parser.y"
                                                             {
          (yyval.nodo) = crearNodo(AST_OPERACION, ">=");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3096 "src/parser/parser.tab.c"
    break;

  case 99: /* expresion_shift: expresion_aditiva  */
#line 854 "src/parser/parser.y"
                        { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3102 "src/parser/parser.tab.c"
    break;

  case 100: /* expresion_shift: expresion_shift TOKEN_DESIZQ expresion_aditiva  */
#line 855 "src/parser/parser.y"
                                                     {
          (yyval.nodo) = crearNodo(AST_OPERACION, "<<");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3112 "src/parser/parser.tab.c"
    break;

  case 101: /* expresion_shift: expresion_shift TOKEN_DESDER expresion_aditiva  */
#line 860 "src/parser/parser.y"
                                                     {
          (yyval.nodo) = crearNodo(AST_OPERACION, ">>");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3122 "src/parser/parser.tab.c"
    break;

  case 102: /* expresion_aditiva: expresion_multiplicativa  */
#line 868 "src/parser/parser.y"
                               { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3128 "src/parser/parser.tab.c"
    break;

  case 103: /* expresion_aditiva: expresion_aditiva TOKEN_MAS expresion_multiplicativa  */
#line 869 "src/parser/parser.y"
                                                           {
          (yyval.nodo) = crearNodo(AST_OPERACION, "+");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3138 "src/parser/parser.tab.c"
    break;

  case 104: /* expresion_aditiva: expresion_aditiva TOKEN_MENOS expresion_multiplicativa  */
#line 874 "src/parser/parser.y"
                                                             {
          (yyval.nodo) = crearNodo(AST_OPERACION, "-");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3148 "src/parser/parser.tab.c"
    break;

  case 105: /* expresion_multiplicativa: expresion_unaria  */
#line 882 "src/parser/parser.y"
                       { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3154 "src/parser/parser.tab.c"
    break;

  case 106: /* expresion_multiplicativa: expresion_multiplicativa TOKEN_MULTI expresion_unaria  */
#line 883 "src/parser/parser.y"
                                                            {
          (yyval.nodo) = crearNodo(AST_OPERACION, "*");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3164 "src/parser/parser.tab.c"
    break;

  case 107: /* expresion_multiplicativa: expresion_multiplicativa TOKEN_DIV expresion_unaria  */
#line 888 "src/parser/parser.y"
                                                          {
          (yyval.nodo) = crearNodo(AST_OPERACION, "/");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3174 "src/parser/parser.tab.c"
    break;

  case 108: /* expresion_multiplicativa: expresion_multiplicativa TOKEN_MODULO expresion_unaria  */
#line 893 "src/parser/parser.y"
                                                             {
          (yyval.nodo) = crearNodo(AST_OPERACION, "%");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3184 "src/parser/parser.tab.c"
    break;

  case 109: /* expresion_unaria: TOKEN_NOT expresion_unaria  */
#line 901 "src/parser/parser.y"
                                 {
          (yyval.nodo) = crearNodo(AST_OPERACION, "!");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3194 "src/parser/parser.tab.c"
    break;

  case 110: /* expresion_unaria: TOKEN_MENOS expresion_unaria  */
#line 906 "src/parser/parser.y"
                                                {
          (yyval.nodo) = crearNodo(AST_OPERACION, "uminus");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3204 "src/parser/parser.tab.c"
    break;

  case 111: /* expresion_unaria: TOKEN_PARIZQ tipo_primitivo TOKEN_PARDER expresion_unaria  */
#line 911 "src/parser/parser.y"
                                                                {
          /* crear un nodo específico para cast; guardamos el tipo en ->valor */
          (yyval.nodo) = crearNodo(AST_CAST, "cast");
          (yyval.nodo)->valor = strdup((yyvsp[-2].str));    
          (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[0].nodo));
          free((yyvsp[-2].str)); 
      }
#line 3217 "src/parser/parser.tab.c"
    break;

  case 112: /* expresion_unaria: postfix  */
#line 919 "src/parser/parser.y"
              { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3223 "src/parser/parser.tab.c"
    break;

  case 113: /* postfix: primary  */
#line 923 "src/parser/parser.y"
              { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3229 "src/parser/parser.tab.c"
    break;

  case 114: /* postfix: postfix TOKEN_INCREMENTO  */
#line 924 "src/parser/parser.y"
                               {
          /* transforma (postfix ++) — el hijo es la expresión previa */
          (yyval.nodo) = crearNodo(AST_OPERACION, "++");
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
      }
#line 3240 "src/parser/parser.tab.c"
    break;

  case 115: /* postfix: postfix TOKEN_DECREMENTO  */
#line 930 "src/parser/parser.y"
                               {
          (yyval.nodo) = crearNodo(AST_OPERACION, "--");
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
      }
#line 3250 "src/parser/parser.tab.c"
    break;

  case 116: /* primary: TOKEN_NUMERO  */
#line 939 "src/parser/parser.y"
                   {
          (yyval.nodo) = crearNodo(AST_NUMERO, NULL);
          (yyval.nodo)->valor = strdup((yyvsp[0].str));
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
      }
#line 3260 "src/parser/parser.tab.c"
    break;

  case 117: /* primary: TOKEN_DOUBLE_LITERAL  */
#line 944 "src/parser/parser.y"
                           {
          (yyval.nodo) = crearNodo(AST_NUMERO, NULL);
          (yyval.nodo)->valor = strdup((yyvsp[0].str));
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
      }
#line 3270 "src/parser/parser.tab.c"
    break;

  case 118: /* primary: TOKEN_FLOAT_LITERAL  */
#line 949 "src/parser/parser.y"
                          {
          (yyval.nodo) = crearNodo(AST_NUMERO, NULL);
          (yyval.nodo)->valor = strdup((yyvsp[0].str));
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
      }
#line 3280 "src/parser/parser.tab.c"
    break;

  case 119: /* primary: TOKEN_CADENA  */
#line 954 "src/parser/parser.y"
                   {
          (yyval.nodo) = crearNodo(AST_CADENA, NULL);
          (yyval.nodo)->valor = strdup((yyvsp[0].str));
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
      }
#line 3290 "src/parser/parser.tab.c"
    break;

  case 120: /* primary: TOKEN_CARACTER  */
#line 959 "src/parser/parser.y"
                     {
          (yyval.nodo) = crearNodo(AST_CARACTER, NULL);
          (yyval.nodo)->valor = strdup((yyvsp[0].str));
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
      }
#line 3300 "src/parser/parser.tab.c"
    break;

  case 121: /* primary: TOKEN_IDENTIFICADOR  */
#line 964 "src/parser/parser.y"
                          {
          (yyval.nodo) = crearNodo(AST_IDENTIFICADOR, (yyvsp[0].str));
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
      }
#line 3309 "src/parser/parser.tab.c"
    break;

  case 122: /* primary: TOKEN_BOOLEANO  */
#line 968 "src/parser/parser.y"
                     {
        (yyval.nodo) = crearNodo(AST_BOOLEAN, (yyvsp[0].str));
        (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
    }
#line 3318 "src/parser/parser.tab.c"
    break;

  case 123: /* primary: TOKEN_PARSEINT TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 972 "src/parser/parser.y"
                                                         {
        (yyval.nodo) = crearNodo(AST_PARSEINT, "Integer.parseInt");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3328 "src/parser/parser.tab.c"
    break;

  case 124: /* primary: TOKEN_PARSEDOUBLE TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 977 "src/parser/parser.y"
                                                            {
        (yyval.nodo) = crearNodo(AST_PARSEDOUBLE, "Double.parseDouble");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3338 "src/parser/parser.tab.c"
    break;

  case 125: /* primary: TOKEN_PARSEFLOAT TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 982 "src/parser/parser.y"
                                                           {
        (yyval.nodo) = crearNodo(AST_PARSEFLOAT, "Float.parseFloat");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3348 "src/parser/parser.tab.c"
    break;

  case 126: /* primary: TOKEN_STRING_VALUEOF TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 987 "src/parser/parser.y"
                                                               {
        (yyval.nodo) = crearNodo(AST_VALUEOF, "String.valueOf");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3358 "src/parser/parser.tab.c"
    break;

  case 127: /* primary: TOKEN_INDEXOF TOKEN_PARIZQ expresion TOKEN_COMA expresion TOKEN_PARDER  */
#line 992 "src/parser/parser.y"
                                                                             {
        (yyval.nodo) = crearNodo(AST_INDEXOF, "Arrays.indexOf");
        (yyval.nodo)->linea = (yylsp[-5]).first_line; (yyval.nodo)->columna = (yylsp[-5]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-3].nodo));  // El array/vector
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));  // La clave a buscar
    }
#line 3369 "src/parser/parser.tab.c"
    break;

  case 128: /* primary: TOKEN_IDENTIFICADOR TOKEN_PUNTO TOKEN_LENGHT  */
#line 998 "src/parser/parser.y"
                                                   {
        (yyval.nodo) = crearNodo(AST_LENGHT, "Array.length");
        (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-2].str));
        id->linea = (yylsp[-2]).first_line; id->columna = (yylsp[-2]).first_column;
        agregarHijo((yyval.nodo), id);
    }
#line 3381 "src/parser/parser.tab.c"
    break;

  case 129: /* primary: TOKEN_IDENTIFICADOR TOKEN_PUNTO TOKEN_ADD TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 1005 "src/parser/parser.y"
                                                                                    {
        (yyval.nodo) = crearNodo(AST_ADD, "Array.add");
        (yyval.nodo)->linea = (yylsp[-5]).first_line; (yyval.nodo)->columna = (yylsp[-5]).first_column;
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-5].str));
        id->linea = (yylsp[-5]).first_line; id->columna = (yylsp[-5]).first_column;
        agregarHijo((yyval.nodo), id);
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));  // El elemento a añadir
    }
#line 3394 "src/parser/parser.tab.c"
    break;

  case 130: /* primary: TOKEN_CADENA TOKEN_EQUAL TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 1013 "src/parser/parser.y"
                                                                   {
        (yyval.nodo) = crearNodo(AST_EQUAL, ".equals");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        NodoAST* cadena = crearNodo(AST_CADENA, (yyvsp[-4].str));
        cadena->linea = (yylsp[-4]).first_line; cadena->columna = (yylsp[-4]).first_column;
        agregarHijo((yyval.nodo), cadena);
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3407 "src/parser/parser.tab.c"
    break;

  case 131: /* primary: TOKEN_IDENTIFICADOR TOKEN_EQUAL TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 1021 "src/parser/parser.y"
                                                                          {
        (yyval.nodo) = crearNodo(AST_EQUAL, ".equals");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-4].str));
        id->linea = (yylsp[-4]).first_line; id->columna = (yylsp[-4]).first_column;
        agregarHijo((yyval.nodo), id);
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3420 "src/parser/parser.tab.c"
    break;

  case 132: /* primary: TOKEN_PARSEJOIN TOKEN_PARIZQ expresion TOKEN_COMA lista_expresiones_join TOKEN_PARDER  */
#line 1029 "src/parser/parser.y"
                                                                                            {
        (yyval.nodo) = crearNodo(AST_PARSEJOIN, "Strings.join");
        (yyval.nodo)->linea = (yylsp[-5]).first_line; (yyval.nodo)->columna = (yylsp[-5]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-3].nodo));  // El delimitador
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));  // Lista de expresiones a unir
    }
#line 3431 "src/parser/parser.tab.c"
    break;

  case 133: /* primary: TOKEN_PARSEJOIN TOKEN_PARIZQ expresion TOKEN_COMA expresion TOKEN_PARDER  */
#line 1035 "src/parser/parser.y"
                                                                               {
        (yyval.nodo) = crearNodo(AST_PARSEJOIN, "Strings.join");
        (yyval.nodo)->linea = (yylsp[-5]).first_line; (yyval.nodo)->columna = (yylsp[-5]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-3].nodo));  // El delimitador
        
        // Para un solo elemento, creamos una lista con ese elemento
        NodoAST* lista = crearNodo(AST_LISTA, "Lista Strings");
        agregarHijo(lista, (yyvsp[-1].nodo));
        agregarHijo((yyval.nodo), lista);
    }
#line 3446 "src/parser/parser.tab.c"
    break;

  case 134: /* primary: acceso  */
#line 1045 "src/parser/parser.y"
             {
          (yyval.nodo) = (yyvsp[0].nodo);
      }
#line 3454 "src/parser/parser.tab.c"
    break;

  case 135: /* primary: Llamadas  */
#line 1048 "src/parser/parser.y"
              {
        (yyval.nodo) = (yyvsp[0].nodo);
    }
#line 3462 "src/parser/parser.tab.c"
    break;

  case 136: /* primary: TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 1051 "src/parser/parser.y"
                                          {
          (yyval.nodo) = (yyvsp[-1].nodo);
      }
#line 3470 "src/parser/parser.tab.c"
    break;

  case 137: /* lista_expresiones_join: lista_expresiones_join TOKEN_COMA expresion  */
#line 1057 "src/parser/parser.y"
                                                {
        if ((yyvsp[-2].nodo)->tipo != AST_LISTA) {
            NodoAST* lista = crearNodo(AST_LISTA, "Lista Strings");
            agregarHijo(lista, (yyvsp[-2].nodo));
            agregarHijo(lista, (yyvsp[0].nodo));
            (yyval.nodo) = lista;
        } else {
            agregarHijo((yyvsp[-2].nodo), (yyvsp[0].nodo));
            (yyval.nodo) = (yyvsp[-2].nodo);
        }
    }
#line 3486 "src/parser/parser.tab.c"
    break;

  case 138: /* lista_expresiones_join: expresion  */
#line 1068 "src/parser/parser.y"
                {
        (yyval.nodo) = crearNodo(AST_LISTA, "Lista Strings");
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3495 "src/parser/parser.tab.c"
    break;

  case 139: /* instruccion_print: TOKEN_PRINT TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 1076 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crearNodo(AST_PRINT, "System.out.println");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3505 "src/parser/parser.tab.c"
    break;

  case 140: /* instruccion_print: TOKEN_PRINT TOKEN_PARIZQ TOKEN_CADENA TOKEN_MAS expresion TOKEN_PARDER  */
#line 1081 "src/parser/parser.y"
                                                                             {
        // Manejo específico para concatenación en print
        NodoAST* concat = crearNodo(AST_OPERACION, "+");
        concat->linea = (yylsp[-2]).first_line; concat->columna = (yylsp[-2]).first_column;
        NodoAST* cadena = crearNodo(AST_CADENA, (yyvsp[-3].str));
        cadena->linea = (yylsp[-3]).first_line; cadena->columna = (yylsp[-3]).first_column;
        agregarHijo(concat, cadena);
        agregarHijo(concat, (yyvsp[-1].nodo));
        
        (yyval.nodo) = crearNodo(AST_PRINT, "System.out.println");
        (yyval.nodo)->linea = (yylsp[-5]).first_line; (yyval.nodo)->columna = (yylsp[-5]).first_column;
        agregarHijo((yyval.nodo), concat);
    }
#line 3523 "src/parser/parser.tab.c"
    break;

  case 141: /* bloque: TOKEN_LLAVEIZQ lista_sentencias TOKEN_LLAVEDER  */
#line 1097 "src/parser/parser.y"
                                                   {
        (yyval.nodo) = crearNodo(AST_BLOQUE, NULL);
        (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3533 "src/parser/parser.tab.c"
    break;

  case 142: /* bloque: TOKEN_LLAVEIZQ error TOKEN_LLAVEDER  */
#line 1102 "src/parser/parser.y"
                                          {
        addErrorSintactico("Error sintáctico en el bloque", "global", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.nodo) = crearNodo(AST_BLOQUE, NULL);
        (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;
        // Crear un bloque vacío para continuar
        agregarHijo((yyval.nodo), crearNodo(AST_LISTA, "Programa"));
    }
#line 3545 "src/parser/parser.tab.c"
    break;

  case 143: /* instruccion_break: TOKEN_BREAK  */
#line 1112 "src/parser/parser.y"
                {
        (yyval.nodo) = crearNodo(AST_BREAK, "break");
        (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
    }
#line 3554 "src/parser/parser.tab.c"
    break;

  case 144: /* instruccion_continue: TOKEN_CONTINUE  */
#line 1119 "src/parser/parser.y"
                   {
        (yyval.nodo) = crearNodo(AST_CONTINUE, "continue");
        (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
    }
#line 3563 "src/parser/parser.tab.c"
    break;

  case 145: /* instruccion_return: TOKEN_RETURN expresion  */
#line 1126 "src/parser/parser.y"
                           {
        (yyval.nodo) = crearNodo(AST_RETURN, "return");
        (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3573 "src/parser/parser.tab.c"
    break;

  case 146: /* instruccion_if: TOKEN_IF TOKEN_PARIZQ expresion TOKEN_PARDER bloque  */
#line 1136 "src/parser/parser.y"
                                                                       {
        printf("[DEBUG] Procesando if en línea %d, columna %d\n", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
        (yyval.nodo) = crearNodo(AST_IF, "if");
        (yyval.nodo)->linea = (yylsp[-4]).first_line; (yyval.nodo)->columna = (yylsp[-4]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));   // condición
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));   // bloque if
    }
#line 3585 "src/parser/parser.tab.c"
    break;

  case 147: /* instruccion_if: TOKEN_IF TOKEN_PARIZQ expresion TOKEN_PARDER bloque TOKEN_ELSE bloque  */
#line 1143 "src/parser/parser.y"
                                                                            {
        printf("[DEBUG] Procesando if-else en línea %d, columna %d\n", (yylsp[-6]).first_line, (yylsp[-6]).first_column);
        (yyval.nodo) = crearNodo(AST_IF, "if");
        (yyval.nodo)->linea = (yylsp[-6]).first_line; (yyval.nodo)->columna = (yylsp[-6]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));   // condición
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));   // bloque if
        NodoAST* else_node = crearNodo(AST_ELSE, "else");
        agregarHijo(else_node, (yyvsp[0].nodo));
        agregarHijo((yyval.nodo), else_node);
    }
#line 3600 "src/parser/parser.tab.c"
    break;

  case 148: /* instruccion_if: TOKEN_IF TOKEN_PARIZQ expresion TOKEN_PARDER bloque TOKEN_ELSE instruccion_if  */
#line 1153 "src/parser/parser.y"
                                                                                    {
        (yyval.nodo) = crearNodo(AST_IF, "if");
        (yyval.nodo)->linea = (yylsp[-6]).first_line; (yyval.nodo)->columna = (yylsp[-6]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));   // condición
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));   // bloque if
        NodoAST* elseif_node = crearNodo(AST_ELSEIF, "elseif");
        agregarHijo(elseif_node, (yyvsp[0].nodo));
        agregarHijo((yyval.nodo), elseif_node);
    }
#line 3614 "src/parser/parser.tab.c"
    break;

  case 149: /* instruccion_if: TOKEN_IF TOKEN_PARIZQ error TOKEN_PARDER bloque  */
#line 1162 "src/parser/parser.y"
                                                                     {
        printf("[DEBUG] Error en condición del if en línea %d, columna %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        addErrorSintactico("Expresión inválida en condición if", "global", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        (yyval.nodo) = crearNodo(AST_IF, "if");
        (yyval.nodo)->linea = (yylsp[-4]).first_line; (yyval.nodo)->columna = (yylsp[-4]).first_column;
        agregarHijo((yyval.nodo), crearNodo(AST_BOOLEAN, "false"));  // condición predeterminada
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));  // bloque if
    }
#line 3627 "src/parser/parser.tab.c"
    break;

  case 150: /* intruccion_switch: TOKEN_SWITCH TOKEN_PARIZQ expresion TOKEN_PARDER TOKEN_LLAVEIZQ lista_casos TOKEN_LLAVEDER  */
#line 1174 "src/parser/parser.y"
                                                                                               {
        (yyval.nodo) = crearNodo(AST_SWITCH, "switch");
        (yyval.nodo)->linea = (yylsp[-6]).first_line; (yyval.nodo)->columna = (yylsp[-6]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3638 "src/parser/parser.tab.c"
    break;

  case 151: /* lista_casos: lista_casos caso  */
#line 1183 "src/parser/parser.y"
                     {
        if ((yyvsp[-1].nodo)->tipo != AST_LISTA) {
            NodoAST* lista = crearNodo(AST_LISTA, "Casos");
            agregarHijo(lista, (yyvsp[-1].nodo));
            agregarHijo(lista, (yyvsp[0].nodo));
            (yyval.nodo) = lista;
        } else {
            agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo));
            (yyval.nodo) = (yyvsp[-1].nodo);
        }
    }
#line 3654 "src/parser/parser.tab.c"
    break;

  case 152: /* lista_casos: caso  */
#line 1194 "src/parser/parser.y"
           {
        (yyval.nodo) = crearNodo(AST_LISTA, "Casos");
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3663 "src/parser/parser.tab.c"
    break;

  case 153: /* caso: TOKEN_CASE expresion TOKEN_DOS_PUNTOS lista_sentencias TOKEN_BREAK TOKEN_PUNTOCOMA  */
#line 1201 "src/parser/parser.y"
                                                                                      {
        (yyval.nodo) = crearNodo(AST_CASE, "CASE");
        (yyval.nodo)->linea = (yylsp[-5]).first_line; (yyval.nodo)->columna = (yylsp[-5]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));
        NodoAST* nodoBreak = crearNodo(AST_BREAK, "break");
        nodoBreak->linea = (yylsp[-1]).first_line; nodoBreak->columna = (yylsp[-1]).first_column;
        agregarHijo((yyval.nodo), nodoBreak);
    }
#line 3677 "src/parser/parser.tab.c"
    break;

  case 154: /* caso: TOKEN_DEFAULT TOKEN_DOS_PUNTOS lista_sentencias  */
#line 1210 "src/parser/parser.y"
                                                      {
        (yyval.nodo) = crearNodo(AST_DEFAULT, "DEFAULT");
        (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3687 "src/parser/parser.tab.c"
    break;

  case 155: /* instruccion_while: TOKEN_WHILE TOKEN_PARIZQ expresion TOKEN_PARDER bloque  */
#line 1218 "src/parser/parser.y"
                                                           {
        (yyval.nodo) = crearNodo(AST_WHILE, "while");
        (yyval.nodo)->linea = (yylsp[-4]).first_line; (yyval.nodo)->columna = (yylsp[-4]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3698 "src/parser/parser.tab.c"
    break;

  case 156: /* instruccion_while: TOKEN_WHILE TOKEN_PARIZQ error TOKEN_PARDER bloque  */
#line 1224 "src/parser/parser.y"
                                                         {
        addErrorSintactico("Expresión inválida en condición while", "global", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        (yyval.nodo) = crearNodo(AST_WHILE, "while");
        (yyval.nodo)->linea = (yylsp[-4]).first_line; (yyval.nodo)->columna = (yylsp[-4]).first_column;
        // Agregar una condición predeterminada (false)
        agregarHijo((yyval.nodo), crearNodo(AST_BOOLEAN, "false"));
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));  // bloque while
    }
#line 3711 "src/parser/parser.tab.c"
    break;

  case 157: /* instruccion_for: TOKEN_FOR TOKEN_PARIZQ declaracion TOKEN_PUNTOCOMA expresion TOKEN_PUNTOCOMA expresion TOKEN_PARDER bloque  */
#line 1235 "src/parser/parser.y"
                                                                                                              {
        (yyval.nodo) = crearNodo(AST_FOR, "FOR");
        (yyval.nodo)->linea = (yylsp[-8]).first_line; (yyval.nodo)->columna = (yylsp[-8]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-6].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3724 "src/parser/parser.tab.c"
    break;

  case 158: /* instruccion_for: TOKEN_FOR TOKEN_PARIZQ asignacion TOKEN_PUNTOCOMA expresion TOKEN_PUNTOCOMA expresion TOKEN_PARDER bloque  */
#line 1243 "src/parser/parser.y"
                                                                                                               {
        (yyval.nodo) = crearNodo(AST_FOR, "FOR");
        (yyval.nodo)->linea = (yylsp[-8]).first_line; (yyval.nodo)->columna = (yylsp[-8]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-6].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3737 "src/parser/parser.tab.c"
    break;

  case 159: /* instruccion_for: TOKEN_FOR TOKEN_PARIZQ error TOKEN_PUNTOCOMA expresion TOKEN_PUNTOCOMA expresion TOKEN_PARDER bloque  */
#line 1251 "src/parser/parser.y"
                                                                                                           {
        addErrorSintactico("Inicialización inválida en bucle for", "global", (yylsp[-6]).first_line, (yylsp[-6]).first_column);
        (yyval.nodo) = crearNodo(AST_FOR, "FOR");
        (yyval.nodo)->linea = (yylsp[-8]).first_line; (yyval.nodo)->columna = (yylsp[-8]).first_column;
        // Crear una declaración vacía
        NodoAST* decl = crearNodo(AST_DECLARACION, "declaracion");
        agregarHijo((yyval.nodo), decl);
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3753 "src/parser/parser.tab.c"
    break;

  case 160: /* instruccion_for: TOKEN_FOR TOKEN_PARIZQ declaracion TOKEN_PUNTOCOMA error TOKEN_PUNTOCOMA expresion TOKEN_PARDER bloque  */
#line 1262 "src/parser/parser.y"
                                                                                                             {
        addErrorSintactico("Condición inválida en bucle for", "global", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
        (yyval.nodo) = crearNodo(AST_FOR, "FOR");
        (yyval.nodo)->linea = (yylsp[-8]).first_line; (yyval.nodo)->columna = (yylsp[-8]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-6].nodo));
        // Crear una condición predeterminada (true)
        agregarHijo((yyval.nodo), crearNodo(AST_BOOLEAN, "true"));
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3768 "src/parser/parser.tab.c"
    break;


#line 3772 "src/parser/parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1274 "src/parser/parser.y"


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
