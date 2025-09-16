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

    extern NodoAST* astGlobal;
    
    /* Función auxiliar para crear asignaciones compuestas */
    NodoAST* crear_asignacion_compuesta(char* id, char* operador, NodoAST* expr, 
                                       int id_linea, int id_columna, int op_linea, int op_columna);

#line 90 "src/parser/parser.tab.c"

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
  YYSYMBOL_TOKEN_STATIC = 71,              /* TOKEN_STATIC  */
  YYSYMBOL_TOKEN_main = 72,                /* TOKEN_main  */
  YYSYMBOL_TOKEN_MAS_IGUAL = 73,           /* TOKEN_MAS_IGUAL  */
  YYSYMBOL_TOKEN_MENOS_IGUAL = 74,         /* TOKEN_MENOS_IGUAL  */
  YYSYMBOL_TOKEN_POR_IGUAL = 75,           /* TOKEN_POR_IGUAL  */
  YYSYMBOL_TOKEN_DIV_IGUAL = 76,           /* TOKEN_DIV_IGUAL  */
  YYSYMBOL_TOKEN_MOD_IGUAL = 77,           /* TOKEN_MOD_IGUAL  */
  YYSYMBOL_TOKEN_AND_IGUAL = 78,           /* TOKEN_AND_IGUAL  */
  YYSYMBOL_TOKEN_OR_IGUAL = 79,            /* TOKEN_OR_IGUAL  */
  YYSYMBOL_TOKEN_XOR_IGUAL = 80,           /* TOKEN_XOR_IGUAL  */
  YYSYMBOL_TOKEN_DESIZQ_IGUAL = 81,        /* TOKEN_DESIZQ_IGUAL  */
  YYSYMBOL_TOKEN_DESDER_IGUAL = 82,        /* TOKEN_DESDER_IGUAL  */
  YYSYMBOL_UMINUS = 83,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 84,                  /* $accept  */
  YYSYMBOL_s = 85,                         /* s  */
  YYSYMBOL_programa = 86,                  /* programa  */
  YYSYMBOL_lista_funciones = 87,           /* lista_funciones  */
  YYSYMBOL_main_class = 88,                /* main_class  */
  YYSYMBOL_lista_sentencias = 89,          /* lista_sentencias  */
  YYSYMBOL_sentencia = 90,                 /* sentencia  */
  YYSYMBOL_expresion_sentencia = 91,       /* expresion_sentencia  */
  YYSYMBOL_postfix_incremento = 92,        /* postfix_incremento  */
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
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   909

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  176
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  410

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   338


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
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   112,   112,   116,   122,   130,   141,   152,   157,   162,
     168,   178,   185,   189,   193,   197,   206,   217,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   247,   255,   256,   260,
     265,   274,   284,   297,   317,   328,   360,   371,   378,   389,
     396,   420,   442,   469,   489,   500,   507,   513,   522,   541,
     547,   551,   561,   573,   589,   599,   609,   623,   637,   645,
     655,   667,   678,   685,   700,   719,   751,   770,   771,   772,
     773,   774,   775,   780,   790,   793,   796,   799,   802,   805,
     808,   811,   814,   817,   827,   831,   832,   840,   841,   849,
     850,   858,   859,   867,   868,   876,   877,   882,   890,   891,
     896,   901,   906,   914,   915,   920,   928,   929,   934,   942,
     943,   948,   953,   961,   966,   971,   979,   983,   984,   989,
     998,  1003,  1008,  1013,  1018,  1023,  1027,  1031,  1036,  1041,
    1046,  1051,  1057,  1064,  1072,  1080,  1088,  1094,  1104,  1107,
    1110,  1116,  1127,  1135,  1141,  1153,  1161,  1166,  1176,  1183,
    1190,  1200,  1207,  1217,  1226,  1238,  1247,  1258,  1265,  1274,
    1282,  1288,  1299,  1307,  1315,  1322,  1332
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
  "TOKEN_STATIC", "TOKEN_main", "TOKEN_MAS_IGUAL", "TOKEN_MENOS_IGUAL",
  "TOKEN_POR_IGUAL", "TOKEN_DIV_IGUAL", "TOKEN_MOD_IGUAL",
  "TOKEN_AND_IGUAL", "TOKEN_OR_IGUAL", "TOKEN_XOR_IGUAL",
  "TOKEN_DESIZQ_IGUAL", "TOKEN_DESDER_IGUAL", "UMINUS", "$accept", "s",
  "programa", "lista_funciones", "main_class", "lista_sentencias",
  "sentencia", "expresion_sentencia", "postfix_incremento", "declaracion",
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

#define YYPACT_NINF (-326)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-170)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      64,  -326,  -326,  -326,  -326,  -326,  -326,  -326,    -7,     7,
      29,  -326,    64,  -326,  -326,  -326,    -1,    27,  -326,     6,
    -326,  -326,  -326,  -326,    42,    74,  -326,     5,   154,   112,
    -326,    77,    95,    -3,   114,   451,  -326,    99,   132,   197,
     134,  -326,    10,    86,   115,   144,   150,  -326,   158,  -326,
     170,   845,   356,  -326,     9,  -326,   173,   181,   196,   198,
     202,   210,  -326,  -326,  -326,     4,   215,   223,  -326,   230,
     235,   237,  -326,  -326,  -326,  -326,    26,   494,   245,   494,
    -326,  -326,  -326,   845,  -326,  -326,   845,   637,   845,   845,
     845,   845,   845,   845,   845,   845,   845,   845,   258,   822,
     645,   845,   701,   125,   845,  -326,   589,  -326,   206,  -326,
    -326,  -326,   784,   845,   233,   234,   238,   240,   242,   243,
    -326,  -326,  -326,   227,   231,   244,   246,   247,    81,   137,
     119,   159,   241,  -326,   172,  -326,   254,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,   845,  -326,   273,    47,  -326,  -326,
    -326,  -326,  -326,  -326,  -326,   382,  -326,   425,   275,  -326,
     261,  -326,    63,  -326,  -326,  -326,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,   845,     3,  -326,   262,   264,   265,
     267,   268,   269,   280,   212,   164,   289,   284,  -326,   276,
     135,   277,   278,   279,  -326,   845,   845,   845,   845,   845,
     845,   845,   845,   845,   845,   845,   845,   845,   845,   845,
     845,   845,   845,   845,   845,   845,   845,   845,   845,  -326,
    -326,  -326,    21,   308,   845,   292,  -326,  -326,  -326,  -326,
     845,  -326,   311,   845,  -326,   112,   112,   314,   112,   112,
     845,   709,   845,   296,   845,   845,  -326,   288,   845,   845,
    -326,   295,   297,   298,   299,   300,   304,   231,   244,   246,
     247,    81,   137,   137,   119,   119,   119,   119,   159,   159,
     241,   241,  -326,  -326,  -326,   316,   312,   318,  -326,   113,
    -326,  -326,   302,  -326,   287,   161,  -326,  -326,   310,   315,
     319,   313,   322,   320,   845,   321,  -326,  -326,  -326,  -326,
    -326,   845,   845,   331,    18,  -326,   334,   197,  -326,    20,
     845,   338,    15,  -326,   845,   845,   845,   112,   845,  -326,
     330,  -326,   332,    67,   333,   342,   845,   197,   303,   762,
      68,  -326,   351,  -326,  -326,   344,   494,  -326,  -326,   345,
     346,   347,  -326,   348,  -326,  -326,   845,  -326,  -326,   123,
      69,  -326,   367,   323,    70,    78,  -326,   334,   357,   385,
     494,   189,   112,   112,   112,   112,  -326,   383,   197,  -326,
     845,   845,   358,  -326,  -326,  -326,   386,   366,   520,  -326,
    -326,  -326,  -326,   845,    85,   389,  -326,   390,   845,  -326,
     392,   371,    87,  -326,   402,   845,  -326,   374,  -326,  -326,
    -326,   845,   403,  -326,    89,   410,  -326,   845,   411,  -326
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    15,    82,    77,    80,    81,    78,    79,     0,     0,
       0,     2,     0,     4,     7,     8,     0,     0,    14,     0,
       1,     3,     5,     6,     0,     0,    13,     0,     0,     0,
      12,     0,     0,     0,     0,     0,    67,     0,     0,     0,
       0,    76,     0,     0,     0,     0,     0,   158,     0,   159,
       0,     0,     0,    17,     0,    37,     0,     0,     0,     0,
       0,     0,    29,    38,    31,     0,     0,     0,    35,     0,
       0,     0,    22,    23,    24,    25,     0,     0,     0,     0,
     157,    36,    63,     0,    39,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,     0,
       0,     0,     0,     0,     0,   136,     0,   130,   133,   134,
     132,   131,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   149,   160,    94,    95,    97,    99,   101,   103,   105,
     108,   113,   116,   119,   126,   127,     0,   156,    16,    33,
      18,    26,    27,    28,     0,    20,     0,    42,    19,    21,
      32,    34,    30,    11,    10,     0,    75,     0,     0,    83,
       0,    68,     0,    72,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,   133,   155,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,     0,
       0,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128,
     129,    66,     0,     0,     0,     0,    74,    73,    65,    70,
       0,    69,     0,     0,   153,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,     0,   142,     0,     0,     0,
     150,     0,     0,     0,     0,     0,     0,    96,    98,   100,
     102,   104,   106,   107,   112,   110,   111,   109,   114,   115,
     117,   118,   120,   121,   122,     0,     0,    59,    41,     0,
      71,    64,     0,   164,   161,     0,   171,   170,     0,     0,
       0,     0,     0,     0,     0,     0,   125,   140,   137,   139,
     138,     0,     0,     0,     0,    58,     0,     0,   154,     0,
       0,     0,     0,   167,     0,     0,     0,     0,     0,   145,
       0,   144,   152,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,   162,   163,     0,     0,   165,   166,     0,
       0,     0,   174,     0,   143,   147,     0,   146,   141,     0,
       0,    47,     0,     0,     0,     0,    53,     0,     0,    52,
       0,     0,     0,     0,     0,     0,   151,     0,     0,    44,
       0,     0,     0,    56,    57,    54,     0,     0,     0,   175,
     176,   172,   173,     0,     0,     0,    46,     0,     0,    60,
       0,     0,     0,    51,     0,     0,    43,     0,    61,   168,
      49,     0,     0,    45,     0,     0,    48,     0,     0,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -326,  -326,  -326,  -326,   404,   -76,   -50,  -326,  -326,   317,
    -326,  -325,  -326,  -326,  -326,    90,    61,   145,  -326,   -20,
    -326,  -326,   102,   -16,  -326,   106,  -326,     0,   324,   -46,
    -326,   220,   221,   229,   226,   236,    30,    22,    16,    38,
     -93,  -326,  -326,  -326,  -326,   -12,  -326,  -326,  -326,   126,
    -326,  -326,   122,  -326,  -326
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    10,    11,    12,    13,    52,    53,    54,    55,    56,
      57,   350,   384,    58,    59,   330,   331,   225,   359,   120,
      98,    61,    62,   121,   162,    64,    33,    65,    66,   351,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   323,    67,    68,    69,    70,    71,    72,
      73,   312,   313,    74,    75
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      16,   155,   138,   157,   354,   122,    30,    26,    18,   146,
      17,   188,    16,    80,   233,    60,    24,    36,   337,    63,
     194,   147,   326,    39,    35,   327,   275,   153,    34,    20,
      35,    40,    60,   139,    81,   328,    63,   158,   276,    78,
     159,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   223,   177,   179,   180,   182,    60,   392,    60,
      25,    63,   191,    63,   154,     1,   193,   310,   311,    45,
     224,   356,   369,   373,    27,    28,   404,    31,    19,     2,
      28,   374,     3,     4,     5,     6,     7,    82,   393,   230,
     400,    83,   406,   346,   357,   370,   370,   231,   221,    84,
      85,   347,    14,   186,   357,   138,    15,   138,    29,    86,
      37,   394,   192,   370,    22,   370,    35,   306,    23,    87,
     307,   206,   207,   272,   273,   274,   183,   367,   232,    38,
     368,    41,     8,    76,     9,    60,    77,    60,    79,    63,
       2,    63,   184,     3,     4,     5,     6,     7,    99,   251,
     252,   253,   254,   255,   256,    32,   296,   212,   213,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,     2,
     214,   215,     3,     4,     5,     6,     7,   100,   278,   208,
     209,   210,   211,   101,   280,   219,   220,   282,   241,   242,
     136,   102,  -169,    35,   288,   290,   291,   140,   292,   293,
     246,   247,   295,   103,     2,   141,    43,     3,     4,     5,
       6,     7,     2,   310,   311,     3,     4,     5,     6,     7,
     142,    44,   143,   283,   284,   144,   286,   287,   268,   269,
     264,   265,   266,   267,   145,    86,   262,   263,    45,   148,
      46,  -169,  -169,    47,    48,    49,    50,   149,   320,   216,
     217,   218,   270,   271,   150,   322,   324,     8,    51,   151,
     361,   152,   156,   174,   335,   191,   195,   196,   339,   340,
     341,   197,   343,   198,   201,   199,   200,   202,    81,   222,
     203,   228,   205,   204,   378,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,   229,   234,   333,   235,   236,
     366,   237,   238,   239,   240,   342,   243,   332,   244,   245,
     248,   138,   249,   250,   277,   279,    60,   281,   285,   224,
      63,   294,   303,   223,   386,   387,   301,   352,   138,   297,
     302,   298,   299,   300,   314,   304,   308,   309,   329,   315,
      60,    60,   397,   316,    63,    63,   318,   317,   325,   402,
     379,   380,   381,   382,   319,   321,   358,   136,    60,   137,
      35,   408,    63,   336,   344,   349,   345,   348,   385,   360,
     353,     2,   371,    43,     3,     4,     5,     6,     7,   362,
     363,   364,   365,   136,   376,   226,    35,   383,    44,   372,
     377,   388,   389,   390,   395,   399,   396,     2,   398,    43,
       3,     4,     5,     6,     7,    45,   401,    46,   403,   405,
      47,    48,    49,    50,    44,   407,    21,   409,   375,   355,
     185,   257,   305,   258,     8,    51,   136,   187,   227,    35,
     260,    45,   259,    46,   338,   334,    47,    48,    49,    50,
       2,   261,    43,     3,     4,     5,     6,     7,     0,     0,
       8,    51,    42,     0,     0,    35,     0,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,    43,     3,
       4,     5,     6,     7,    45,     0,    46,     0,     0,    47,
      48,    49,    50,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,    51,   136,     0,     0,    35,     0,
      45,     0,    46,     0,     0,    47,    48,    49,    50,     2,
       0,    43,     3,     4,     5,     6,     7,     0,     0,     8,
      51,   136,     0,     0,    35,     0,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,    43,     3,     4,
       5,     6,     7,    45,     0,    46,     0,     0,    47,    48,
      49,    50,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,    51,     0,     0,     0,     0,     0,    45,
       0,    46,     0,     0,   391,    48,    49,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,    51,
      82,     0,  -135,     0,    83,  -135,     0,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -135,  -135,  -135,     0,     0,     0,     0,
       0,     0,    87,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,     0,   160,     0,
       0,     0,     0,     0,     0,     0,   178,     0,   189,   104,
       0,     0,     0,   105,   106,     0,   190,   104,     0,     0,
       0,   105,   106,     0,   107,   108,   109,   110,   111,     0,
     112,   161,   107,   108,   109,   110,   111,     0,   112,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,   113,     0,   114,     0,   115,   116,   117,
     118,   119,   181,   114,     0,   115,   116,   117,   118,   119,
     289,     0,     0,   104,     0,     0,     0,   105,   106,     0,
       0,   104,     0,     0,     0,   105,   106,     0,   107,   108,
     109,   110,   111,     0,   112,     0,   107,   108,   109,   110,
     111,     0,   112,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,   113,     0,   114,
       0,   115,   116,   117,   118,   119,   329,   114,     0,   115,
     116,   117,   118,   119,   104,     0,     0,     0,   105,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
     108,   109,   110,   111,     0,   112,   104,     0,     0,     2,
     105,   106,     3,     4,     5,     6,     7,     0,     0,     0,
     113,   107,   108,   109,   110,   111,     0,   112,     0,     0,
     114,     0,   115,   116,   117,   118,   119,     0,     0,     0,
       0,     0,   113,     0,   104,     0,     0,     0,   105,   106,
       0,     0,   114,     0,   115,   116,   117,   118,   119,   107,
     175,   109,   110,   111,     0,   112,   176,   104,     0,     0,
       0,   105,   106,     0,     0,     0,     0,     0,     0,     0,
     113,     0,   107,   108,   109,   110,   111,     0,   112,     0,
     114,     0,   115,   116,   117,   118,   119,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,     0,   115,   116,   117,   118,   119
};

static const yytype_int16 yycheck[] =
{
       0,    77,    52,    79,   329,    51,     1,     1,     1,     5,
      17,   104,    12,     3,    11,    35,    17,    29,     3,    35,
     113,    17,     4,    26,     4,     7,     5,     1,    28,     0,
       4,    34,    52,    24,    24,    17,    52,    83,    17,    39,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,     5,    99,   100,   101,   102,    77,   383,    79,
      33,    77,    59,    79,    76,     1,   112,    52,    53,    49,
      23,     3,     3,     3,    68,    33,   401,    72,    71,    15,
      33,     3,    18,    19,    20,    21,    22,     1,     3,    26,
       3,     5,     3,    26,    26,    26,    26,    34,   144,    13,
      14,    34,     0,   103,    26,   155,     0,   157,    34,    23,
      33,    26,   112,    26,    12,    26,     4,     4,    12,    33,
       7,    40,    41,   216,   217,   218,     1,     4,   174,    34,
       7,    17,    68,    34,    70,   155,     4,   157,     4,   155,
      15,   157,    17,    18,    19,    20,    21,    22,    33,   195,
     196,   197,   198,   199,   200,     1,   249,    38,    39,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    15,
      11,    12,    18,    19,    20,    21,    22,    33,   224,    42,
      43,    44,    45,    33,   230,    13,    14,   233,    24,    25,
       1,    33,     3,     4,   240,   241,   242,    24,   244,   245,
      65,    66,   248,    33,    15,    24,    17,    18,    19,    20,
      21,    22,    15,    52,    53,    18,    19,    20,    21,    22,
      24,    32,    24,   235,   236,    23,   238,   239,   212,   213,
     208,   209,   210,   211,    24,    23,   206,   207,    49,    24,
      51,    52,    53,    54,    55,    56,    57,    24,   294,     8,
       9,    10,   214,   215,    24,   301,   302,    68,    69,    24,
     336,    24,    17,     5,   310,    59,    33,    33,   314,   315,
     316,    33,   318,    33,    47,    33,    33,    46,    24,     6,
      36,     6,    35,    37,   360,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    34,    34,   309,    34,    34,
     346,    34,    34,    34,    24,   317,    17,   307,    24,    33,
      33,   361,    34,    34,     6,    23,   336,     6,     4,    23,
     336,    33,     6,     5,   370,   371,    26,   327,   378,    34,
      26,    34,    34,    34,    24,    23,    34,    50,     4,    24,
     360,   361,   388,    24,   360,   361,    24,    34,    17,   395,
     362,   363,   364,   365,    34,    34,     5,     1,   378,     3,
       4,   407,   378,    25,    34,    23,    34,    34,   368,    25,
      67,    15,     5,    17,    18,    19,    20,    21,    22,    34,
      34,    34,    34,     1,    27,     3,     4,     4,    32,    66,
       5,    33,     6,    27,     5,    24,     6,    15,     6,    17,
      18,    19,    20,    21,    22,    49,     4,    51,    34,     6,
      54,    55,    56,    57,    32,     5,    12,     6,   357,   329,
     103,   201,   277,   202,    68,    69,     1,   103,     3,     4,
     204,    49,   203,    51,   312,   309,    54,    55,    56,    57,
      15,   205,    17,    18,    19,    20,    21,    22,    -1,    -1,
      68,    69,     1,    -1,    -1,     4,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    18,
      19,    20,    21,    22,    49,    -1,    51,    -1,    -1,    54,
      55,    56,    57,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,     1,    -1,    -1,     4,    -1,
      49,    -1,    51,    -1,    -1,    54,    55,    56,    57,    15,
      -1,    17,    18,    19,    20,    21,    22,    -1,    -1,    68,
      69,     1,    -1,    -1,     4,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    18,    19,
      20,    21,    22,    49,    -1,    51,    -1,    -1,    54,    55,
      56,    57,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    51,    -1,    -1,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
       1,    -1,     3,    -1,     5,     6,    -1,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    59,    12,
      -1,    -1,    -1,    16,    17,    -1,    67,    12,    -1,    -1,
      -1,    16,    17,    -1,    27,    28,    29,    30,    31,    -1,
      33,    34,    27,    28,    29,    30,    31,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    58,    -1,    60,    61,    62,
      63,    64,     1,    58,    -1,    60,    61,    62,    63,    64,
       1,    -1,    -1,    12,    -1,    -1,    -1,    16,    17,    -1,
      -1,    12,    -1,    -1,    -1,    16,    17,    -1,    27,    28,
      29,    30,    31,    -1,    33,    -1,    27,    28,    29,    30,
      31,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    58,
      -1,    60,    61,    62,    63,    64,     4,    58,    -1,    60,
      61,    62,    63,    64,    12,    -1,    -1,    -1,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    -1,    33,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      48,    27,    28,    29,    30,    31,    -1,    33,    -1,    -1,
      58,    -1,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    12,    -1,    -1,    -1,    16,    17,
      -1,    -1,    58,    -1,    60,    61,    62,    63,    64,    27,
      28,    29,    30,    31,    -1,    33,    34,    12,    -1,    -1,
      -1,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    27,    28,    29,    30,    31,    -1,    33,    -1,
      58,    -1,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    60,    61,    62,    63,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    15,    18,    19,    20,    21,    22,    68,    70,
      85,    86,    87,    88,   106,   109,   111,    17,     1,    71,
       0,    88,   106,   109,    17,    33,     1,    68,    33,    34,
       1,    72,     1,   110,   111,     4,   129,    33,    34,    26,
      34,    17,     1,    17,    32,    49,    51,    54,    55,    56,
      57,    69,    89,    90,    91,    92,    93,    94,    97,    98,
     103,   105,   106,   107,   109,   111,   112,   128,   129,   130,
     131,   132,   133,   134,   137,   138,    34,     4,   111,     4,
       3,    24,     1,     5,    13,    14,    23,    33,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,   104,    33,
      33,    33,    33,    33,    12,    16,    17,    27,    28,    29,
      30,    31,    33,    48,    58,    60,    61,    62,    63,    64,
     103,   107,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,     1,     3,    90,    24,
      24,    24,    24,    24,    23,    24,     5,    17,    24,    24,
      24,    24,    24,     1,   129,    89,    17,    89,   113,   113,
       1,    34,   108,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,     5,    28,    34,   113,     1,   113,
     113,     1,   113,     1,    17,    93,   111,   112,   124,    59,
      67,    59,   111,   113,   124,    33,    33,    33,    33,    33,
      33,    47,    46,    36,    37,    35,    40,    41,    42,    43,
      44,    45,    38,    39,    11,    12,     8,     9,    10,    13,
      14,   113,     6,     5,    23,   101,     3,     3,     6,    34,
      26,    34,   113,    11,    34,    34,    34,    34,    34,    34,
      24,    24,    25,    17,    24,    33,    65,    66,    33,    34,
      34,   113,   113,   113,   113,   113,   113,   115,   116,   117,
     118,   119,   120,   120,   121,   121,   121,   121,   122,   122,
     123,   123,   124,   124,   124,     5,    17,     6,   113,    23,
     113,     6,   113,   129,   129,     4,   129,   129,   113,     1,
     113,   113,   113,   113,    33,   113,   124,    34,    34,    34,
      34,    26,    26,     6,    23,   101,     4,     7,    34,    50,
      52,    53,   135,   136,    24,    24,    24,    34,    24,    34,
     113,    34,   113,   127,   113,    17,     4,     7,    17,     4,
      99,   100,   111,   129,   133,   113,    25,     3,   136,   113,
     113,   113,   129,   113,    34,    34,    26,    34,    34,    23,
      95,   113,   111,    67,    95,    99,     3,    26,     5,   102,
      25,    89,    34,    34,    34,    34,   113,     4,     7,     3,
      26,     5,    66,     3,     3,   100,    27,     5,    89,   129,
     129,   129,   129,     4,    96,   111,   113,   113,    33,     6,
      27,    54,    95,     3,    26,     5,     6,   113,     6,    24,
       3,     4,   113,    34,    95,     6,     3,     5,   113,     6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    86,    86,    87,    87,    87,    87,    87,
      88,    88,    88,    88,    88,    88,    89,    89,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    91,    91,    92,
      92,    93,    93,    94,    94,    94,    95,    95,    96,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   102,   103,   103,   104,   104,   105,   106,   107,   107,
     107,   108,   108,   109,   109,   110,   110,   111,   111,   111,
     111,   111,   111,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   113,   114,   114,   115,   115,   116,
     116,   117,   117,   118,   118,   119,   119,   119,   120,   120,
     120,   120,   120,   121,   121,   121,   122,   122,   122,   123,
     123,   123,   123,   124,   124,   124,   124,   125,   125,   125,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   127,   127,   128,   128,   128,   129,   129,   130,   131,
     132,   133,   133,   133,   133,   134,   135,   135,   136,   136,
     137,   137,   138,   138,   138,   138,   138
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     1,     1,     0,
       7,     7,     4,     3,     2,     1,     2,     1,     2,     2,
       2,     2,     1,     1,     1,     1,     2,     2,     2,     1,
       2,     1,     2,     2,     2,     1,     2,     1,     1,     2,
       2,     4,     2,    10,     8,    11,     3,     1,     5,     3,
      15,    10,     7,     7,     3,     1,     3,     3,     3,     2,
       3,     4,     2,     2,     4,     3,     3,     5,     3,     4,
       4,     3,     1,     8,     8,     4,     2,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     2,     2,     4,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     6,     3,     6,     5,     5,     6,     6,     1,     1,
       3,     3,     1,     4,     6,     3,     3,     3,     1,     1,
       2,     5,     7,     7,     5,     7,     2,     1,     6,     3,
       5,     5,     9,     9,     7,     9,     9
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
  case 2: /* s: programa  */
#line 112 "src/parser/parser.y"
             { astGlobal = (yyvsp[0].nodo); }
#line 1993 "src/parser/parser.tab.c"
    break;

  case 3: /* programa: lista_funciones main_class  */
#line 116 "src/parser/parser.y"
                                 {
          NodoAST* raiz = crearNodo(AST_PROGRAMA, "Programa");
          agregarHijo(raiz, (yyvsp[-1].nodo));
          agregarHijo(raiz, (yyvsp[0].nodo));
          (yyval.nodo) = raiz;
      }
#line 2004 "src/parser/parser.tab.c"
    break;

  case 4: /* programa: main_class  */
#line 122 "src/parser/parser.y"
                 {
          NodoAST* raiz = crearNodo(AST_PROGRAMA, "Programa");
          agregarHijo(raiz, (yyvsp[0].nodo));
          (yyval.nodo) = raiz;
      }
#line 2014 "src/parser/parser.tab.c"
    break;

  case 5: /* lista_funciones: lista_funciones Funcion_void  */
#line 130 "src/parser/parser.y"
                                   {
          if ((yyvsp[-1].nodo)->tipo != AST_LISTA) {
              NodoAST* lista = crearNodo(AST_LISTA, "Funciones");
              agregarHijo(lista, (yyvsp[-1].nodo));
              agregarHijo(lista, (yyvsp[0].nodo));
              (yyval.nodo) = lista;
          } else {
              agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo));
              (yyval.nodo) = (yyvsp[-1].nodo);
          }
      }
#line 2030 "src/parser/parser.tab.c"
    break;

  case 6: /* lista_funciones: lista_funciones Funcion_parametros  */
#line 141 "src/parser/parser.y"
                                         {
          if ((yyvsp[-1].nodo)->tipo != AST_LISTA) {
              NodoAST* lista = crearNodo(AST_LISTA, "Funciones");
              agregarHijo(lista, (yyvsp[-1].nodo));
              agregarHijo(lista, (yyvsp[0].nodo));
              (yyval.nodo) = lista;
          } else {
              agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo));
              (yyval.nodo) = (yyvsp[-1].nodo);
          }
      }
#line 2046 "src/parser/parser.tab.c"
    break;

  case 7: /* lista_funciones: Funcion_void  */
#line 152 "src/parser/parser.y"
                   {
          NodoAST* lista = crearNodo(AST_LISTA, "Funciones");
          agregarHijo(lista, (yyvsp[0].nodo));
          (yyval.nodo) = lista;
      }
#line 2056 "src/parser/parser.tab.c"
    break;

  case 8: /* lista_funciones: Funcion_parametros  */
#line 157 "src/parser/parser.y"
                         {
          NodoAST* lista = crearNodo(AST_LISTA, "Funciones");
          agregarHijo(lista, (yyvsp[0].nodo));
          (yyval.nodo) = lista;
      }
#line 2066 "src/parser/parser.tab.c"
    break;

  case 9: /* lista_funciones: %empty  */
#line 162 "src/parser/parser.y"
                   {
          (yyval.nodo) = crearNodo(AST_LISTA, "Funciones");
      }
#line 2074 "src/parser/parser.tab.c"
    break;

  case 10: /* main_class: TOKEN_PUBLIC TOKEN_STATIC TOKEN_VOID TOKEN_main TOKEN_PARIZQ TOKEN_PARDER bloque  */
#line 168 "src/parser/parser.y"
                                                                                     {
        if (strcmp((yyvsp[-3].str), "main") != 0) {
            addErrorSintactico("El método principal debe llamarse 'main'", "global", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
            (yyval.nodo) = NULL;
        } else {
            (yyval.nodo) = crearNodo(AST_METODO_MAIN, "public static void main");
            (yyval.nodo)->linea = (yylsp[-6]).first_line; (yyval.nodo)->columna = (yylsp[-6]).first_column;
            agregarHijo((yyval.nodo), (yyvsp[0].nodo)); // Agregar el bloque como hijo
        }
    }
#line 2089 "src/parser/parser.tab.c"
    break;

  case 11: /* main_class: TOKEN_PUBLIC TOKEN_STATIC TOKEN_VOID TOKEN_main TOKEN_PARIZQ TOKEN_PARDER error  */
#line 178 "src/parser/parser.y"
                                                                                      {
        addErrorSintactico("Error en el bloque del método 'main'", "global", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.nodo) = crearNodo(AST_METODO_MAIN, "public static void main");
        (yyval.nodo)->linea = (yylsp[-6]).first_line; (yyval.nodo)->columna = (yylsp[-6]).first_column;
        NodoAST* bloqueVacio = crearNodo(AST_BLOQUE, "Bloque vacío");
        agregarHijo((yyval.nodo), bloqueVacio);
    }
#line 2101 "src/parser/parser.tab.c"
    break;

  case 12: /* main_class: TOKEN_PUBLIC TOKEN_STATIC TOKEN_VOID error  */
#line 185 "src/parser/parser.y"
                                                 {
        addErrorSintactico("Falta el nombre del método principal 'main'", "global", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.nodo) = NULL;
    }
#line 2110 "src/parser/parser.tab.c"
    break;

  case 13: /* main_class: TOKEN_PUBLIC TOKEN_STATIC error  */
#line 189 "src/parser/parser.y"
                                      {
        addErrorSintactico("Falta el tipo de retorno 'void' en el método principal", "global", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.nodo) = NULL;
    }
#line 2119 "src/parser/parser.tab.c"
    break;

  case 14: /* main_class: TOKEN_PUBLIC error  */
#line 193 "src/parser/parser.y"
                         {
        addErrorSintactico("Falta la palabra clave 'static' en el método principal", "global", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.nodo) = NULL;
    }
#line 2128 "src/parser/parser.tab.c"
    break;

  case 15: /* main_class: error  */
#line 197 "src/parser/parser.y"
            {
        addErrorSintactico("Error en la declaración del método principal", "global", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.nodo) = NULL;
    }
#line 2137 "src/parser/parser.tab.c"
    break;

  case 16: /* lista_sentencias: lista_sentencias sentencia  */
#line 206 "src/parser/parser.y"
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
#line 2153 "src/parser/parser.tab.c"
    break;

  case 17: /* lista_sentencias: sentencia  */
#line 217 "src/parser/parser.y"
                { 
        if ((yyvsp[0].nodo)) {
            (yyval.nodo) = (yyvsp[0].nodo);
        } else {
            (yyval.nodo) = crearNodo(AST_LISTA, "Programa");
        }
    }
#line 2165 "src/parser/parser.tab.c"
    break;

  case 18: /* sentencia: declaracion TOKEN_PUNTOCOMA  */
#line 228 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2171 "src/parser/parser.tab.c"
    break;

  case 19: /* sentencia: asignacion TOKEN_PUNTOCOMA  */
#line 229 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2177 "src/parser/parser.tab.c"
    break;

  case 20: /* sentencia: acceso_escritura TOKEN_PUNTOCOMA  */
#line 230 "src/parser/parser.y"
                                       { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2183 "src/parser/parser.tab.c"
    break;

  case 21: /* sentencia: instruccion_print TOKEN_PUNTOCOMA  */
#line 231 "src/parser/parser.y"
                                        { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2189 "src/parser/parser.tab.c"
    break;

  case 22: /* sentencia: instruccion_if  */
#line 232 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2195 "src/parser/parser.tab.c"
    break;

  case 23: /* sentencia: intruccion_switch  */
#line 233 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2201 "src/parser/parser.tab.c"
    break;

  case 24: /* sentencia: instruccion_while  */
#line 234 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2207 "src/parser/parser.tab.c"
    break;

  case 25: /* sentencia: instruccion_for  */
#line 235 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2213 "src/parser/parser.tab.c"
    break;

  case 26: /* sentencia: declaracion_vector TOKEN_PUNTOCOMA  */
#line 236 "src/parser/parser.y"
                                              { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2219 "src/parser/parser.tab.c"
    break;

  case 27: /* sentencia: declaracion_matriz TOKEN_PUNTOCOMA  */
#line 237 "src/parser/parser.y"
                                              { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2225 "src/parser/parser.tab.c"
    break;

  case 28: /* sentencia: declaracion_array_multidimensional TOKEN_PUNTOCOMA  */
#line 238 "src/parser/parser.y"
                                                         { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2231 "src/parser/parser.tab.c"
    break;

  case 29: /* sentencia: Funcion_void  */
#line 239 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2237 "src/parser/parser.tab.c"
    break;

  case 30: /* sentencia: instruccion_return TOKEN_PUNTOCOMA  */
#line 240 "src/parser/parser.y"
                                         { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2243 "src/parser/parser.tab.c"
    break;

  case 31: /* sentencia: Funcion_parametros  */
#line 241 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2249 "src/parser/parser.tab.c"
    break;

  case 32: /* sentencia: instruccion_break TOKEN_PUNTOCOMA  */
#line 242 "src/parser/parser.y"
                                        {(yyval.nodo) = (yyvsp[-1].nodo); }
#line 2255 "src/parser/parser.tab.c"
    break;

  case 33: /* sentencia: expresion_sentencia TOKEN_PUNTOCOMA  */
#line 243 "src/parser/parser.y"
                                              { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2261 "src/parser/parser.tab.c"
    break;

  case 34: /* sentencia: instruccion_continue TOKEN_PUNTOCOMA  */
#line 244 "src/parser/parser.y"
                                           {(yyval.nodo) = (yyvsp[-1].nodo); }
#line 2267 "src/parser/parser.tab.c"
    break;

  case 35: /* sentencia: bloque  */
#line 245 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2273 "src/parser/parser.tab.c"
    break;

  case 36: /* sentencia: error TOKEN_PUNTOCOMA  */
#line 247 "src/parser/parser.y"
                                    { 
        addErrorSintactico("Instrucción inválida", "global", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        yyerrok; 
        (yyval.nodo) = NULL;
    }
#line 2283 "src/parser/parser.tab.c"
    break;

  case 39: /* postfix_incremento: TOKEN_IDENTIFICADOR TOKEN_INCREMENTO  */
#line 260 "src/parser/parser.y"
                                           {
          (yyval.nodo) = crearNodo(AST_INCREMENTO, "++");
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
          agregarHijo((yyval.nodo), crearNodo(AST_IDENTIFICADOR, (yyvsp[-1].str)));
      }
#line 2293 "src/parser/parser.tab.c"
    break;

  case 40: /* postfix_incremento: TOKEN_IDENTIFICADOR TOKEN_DECREMENTO  */
#line 265 "src/parser/parser.y"
                                           {
          (yyval.nodo) = crearNodo(AST_DECREMENTO, "--");
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
          agregarHijo((yyval.nodo), crearNodo(AST_IDENTIFICADOR, (yyvsp[-1].str)));
      }
#line 2303 "src/parser/parser.tab.c"
    break;

  case 41: /* declaracion: tipo_primitivo TOKEN_IDENTIFICADOR TOKEN_IGUAL expresion  */
#line 274 "src/parser/parser.y"
                                                             {
        (yyval.nodo) = crearNodo(AST_DECLARACION, "declaracion");
        (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;
        agregarHijo((yyval.nodo), crearNodo(AST_TIPO, (yyvsp[-3].str)));
        
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-2].str));
        id->linea = (yylsp[-2]).first_line; id->columna = (yylsp[-2]).first_column;
        agregarHijo((yyval.nodo), id);
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 2318 "src/parser/parser.tab.c"
    break;

  case 42: /* declaracion: tipo_primitivo TOKEN_IDENTIFICADOR  */
#line 284 "src/parser/parser.y"
                                         {
        (yyval.nodo) = crearNodo(AST_DECLARACION, "declaracion");
        (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
        agregarHijo((yyval.nodo), crearNodo(AST_TIPO, (yyvsp[-1].str)));
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[0].str));
        id->linea = (yylsp[0]).first_line; id->columna = (yylsp[0]).first_column;
        NodoAST* def = crearNodo(AST_NUMERO, (char*)valorPorDefectoTipo(obtenerTipoDesdeString((yyvsp[-1].str))));
        agregarHijo((yyval.nodo), id);
        agregarHijo((yyval.nodo), def);
    }
#line 2333 "src/parser/parser.tab.c"
    break;

  case 43: /* declaracion_vector: tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_NEW tipo_primitivo TOKEN_CORCHETEIZQ expresion TOKEN_CORCHETEDER  */
#line 297 "src/parser/parser.y"
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
#line 2358 "src/parser/parser.tab.c"
    break;

  case 44: /* declaracion_vector: tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_LLAVEIZQ lista_elementos TOKEN_LLAVEDER  */
#line 317 "src/parser/parser.y"
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
#line 2374 "src/parser/parser.tab.c"
    break;

  case 45: /* declaracion_vector: tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_IDENTIFICADOR TOKEN_PUNTO TOKEN_ADD TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 328 "src/parser/parser.y"
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
#line 2408 "src/parser/parser.tab.c"
    break;

  case 46: /* lista_elementos: lista_elementos TOKEN_COMA expresion  */
#line 360 "src/parser/parser.y"
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
#line 2424 "src/parser/parser.tab.c"
    break;

  case 47: /* lista_elementos: expresion  */
#line 371 "src/parser/parser.y"
                {
        (yyval.nodo) = crearNodo(AST_INTERNO, "Lista Elementos");
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 2433 "src/parser/parser.tab.c"
    break;

  case 48: /* lista_filas: lista_filas TOKEN_COMA TOKEN_LLAVEIZQ lista_elementos TOKEN_LLAVEDER  */
#line 378 "src/parser/parser.y"
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
#line 2449 "src/parser/parser.tab.c"
    break;

  case 49: /* lista_filas: TOKEN_LLAVEIZQ lista_elementos TOKEN_LLAVEDER  */
#line 389 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crearNodo(AST_LISTA_ELEMENTOS, "Lista Filas");
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 2458 "src/parser/parser.tab.c"
    break;

  case 50: /* declaracion_matriz: tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_NEW tipo_primitivo TOKEN_CORCHETEIZQ expresion TOKEN_CORCHETEDER TOKEN_CORCHETEIZQ expresion TOKEN_CORCHETEDER  */
#line 396 "src/parser/parser.y"
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
#line 2487 "src/parser/parser.tab.c"
    break;

  case 51: /* declaracion_matriz: tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_LLAVEIZQ lista_filas TOKEN_LLAVEDER  */
#line 420 "src/parser/parser.y"
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
#line 2511 "src/parser/parser.tab.c"
    break;

  case 52: /* declaracion_array_multidimensional: tipo_primitivo TOKEN_IDENTIFICADOR DimensionesCorchetes TOKEN_IGUAL TOKEN_NEW tipo_primitivo Dimensiones  */
#line 442 "src/parser/parser.y"
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
#line 2543 "src/parser/parser.tab.c"
    break;

  case 53: /* declaracion_array_multidimensional: tipo_primitivo TOKEN_IDENTIFICADOR DimensionesCorchetes TOKEN_IGUAL TOKEN_LLAVEIZQ lista_bloques TOKEN_LLAVEDER  */
#line 469 "src/parser/parser.y"
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
#line 2565 "src/parser/parser.tab.c"
    break;

  case 54: /* lista_bloques: lista_bloques TOKEN_COMA lista_elementos_o_bloques  */
#line 489 "src/parser/parser.y"
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
#line 2581 "src/parser/parser.tab.c"
    break;

  case 55: /* lista_bloques: lista_elementos_o_bloques  */
#line 500 "src/parser/parser.y"
                                {
        (yyval.nodo) = crearNodo(AST_INTERNO, "Lista Bloques");
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 2590 "src/parser/parser.tab.c"
    break;

  case 56: /* lista_elementos_o_bloques: TOKEN_LLAVEIZQ lista_elementos TOKEN_LLAVEDER  */
#line 507 "src/parser/parser.y"
                                                  {
        // Caso: lista de elementos
        NodoAST* bloque = crearNodo(AST_INTERNO, "Bloque");
        agregarHijo(bloque, (yyvsp[-1].nodo));
        (yyval.nodo) = bloque;
    }
#line 2601 "src/parser/parser.tab.c"
    break;

  case 57: /* lista_elementos_o_bloques: TOKEN_LLAVEIZQ lista_bloques TOKEN_LLAVEDER  */
#line 513 "src/parser/parser.y"
                                                  {
        // Caso: bloques anidados
        NodoAST* bloque = crearNodo(AST_INTERNO, "Bloque");
        agregarHijo(bloque, (yyvsp[-1].nodo));
        (yyval.nodo) = bloque;
    }
#line 2612 "src/parser/parser.tab.c"
    break;

  case 58: /* DimensionesCorchetes: TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER DimensionesCorchetes  */
#line 522 "src/parser/parser.y"
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
#line 2636 "src/parser/parser.tab.c"
    break;

  case 59: /* DimensionesCorchetes: TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER  */
#line 541 "src/parser/parser.y"
                                          {
        (yyval.nodo) = crearNodo(AST_DIMENSIONES, "[]");
    }
#line 2644 "src/parser/parser.tab.c"
    break;

  case 60: /* Dimensiones: TOKEN_CORCHETEIZQ TOKEN_NUMERO TOKEN_CORCHETEDER  */
#line 547 "src/parser/parser.y"
                                                     {
        (yyval.nodo) = crearNodo(AST_DIMENSIONES, "[]");
        agregarHijo((yyval.nodo), crearNodo(AST_NUMERO, (yyvsp[-1].str)));
    }
#line 2653 "src/parser/parser.tab.c"
    break;

  case 61: /* Dimensiones: Dimensiones TOKEN_CORCHETEIZQ TOKEN_NUMERO TOKEN_CORCHETEDER  */
#line 551 "src/parser/parser.y"
                                                                   {
        agregarHijo((yyvsp[-3].nodo), crearNodo(AST_NUMERO, (yyvsp[-1].str)));
        (yyval.nodo) = (yyvsp[-3].nodo);
    }
#line 2662 "src/parser/parser.tab.c"
    break;

  case 62: /* acceso: TOKEN_IDENTIFICADOR DimensionesAcceso  */
#line 561 "src/parser/parser.y"
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
#line 2679 "src/parser/parser.tab.c"
    break;

  case 63: /* acceso: TOKEN_IDENTIFICADOR error  */
#line 573 "src/parser/parser.y"
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
#line 2697 "src/parser/parser.tab.c"
    break;

  case 64: /* DimensionesAcceso: DimensionesAcceso TOKEN_CORCHETEIZQ expresion TOKEN_CORCHETEDER  */
#line 589 "src/parser/parser.y"
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
#line 2712 "src/parser/parser.tab.c"
    break;

  case 65: /* DimensionesAcceso: TOKEN_CORCHETEIZQ expresion TOKEN_CORCHETEDER  */
#line 599 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crearNodo(AST_DIMENSIONES, "Dimensiones");
        NodoAST* dim = crearNodo(AST_1DIMENSION, "Dimensión");
        agregarHijo(dim, (yyvsp[-1].nodo)); // Agregar la expresión como una dimensión
        agregarHijo((yyval.nodo), dim);
    }
#line 2723 "src/parser/parser.tab.c"
    break;

  case 66: /* acceso_escritura: acceso TOKEN_IGUAL expresion  */
#line 609 "src/parser/parser.y"
                                 {
        (yyval.nodo) = crearNodo(AST_ACCESO_ESCRITURA, "Acceso Escritura");
        (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;

        // Nodo para el acceso (identificador + dimensiones)
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));

        // Nodo para la expresión (valor a asignar)
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 2738 "src/parser/parser.tab.c"
    break;

  case 67: /* Funcion_void: TOKEN_VOID TOKEN_IDENTIFICADOR TOKEN_PARIZQ TOKEN_PARDER bloque  */
#line 623 "src/parser/parser.y"
                                                                    {
        (yyval.nodo) = crearNodo(AST_FUNCION_VOID, "Función void");
        (yyval.nodo)->linea = (yylsp[-4]).first_line; (yyval.nodo)->columna = (yylsp[-4]).first_column;

        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
        id->linea = (yylsp[-3]).first_line; id->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), id);

        agregarHijo((yyval.nodo), (yyvsp[0].nodo));

    }
#line 2754 "src/parser/parser.tab.c"
    break;

  case 68: /* Llamadas: TOKEN_IDENTIFICADOR TOKEN_PARIZQ TOKEN_PARDER  */
#line 637 "src/parser/parser.y"
                                                  {
        (yyval.nodo) = crearNodo(AST_LLAMADA_VOID, "Llamada funcion void");
        (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;

        NodoAST* id1 = crearNodo(AST_IDENTIFICADOR, (yyvsp[-2].str));
        id1->linea = (yylsp[-2]).first_line; id1->columna = (yylsp[-2]).first_column;
        agregarHijo((yyval.nodo), id1);
    }
#line 2767 "src/parser/parser.tab.c"
    break;

  case 69: /* Llamadas: TOKEN_IDENTIFICADOR TOKEN_PARIZQ lista_parametros TOKEN_PARDER  */
#line 645 "src/parser/parser.y"
                                                                     {
        (yyval.nodo) = crearNodo(AST_LLAMADA, "Llamada funcion");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;

        NodoAST* id1 = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
        id1->linea = (yylsp[-3]).first_line; id1->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), id1);

        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 2782 "src/parser/parser.tab.c"
    break;

  case 70: /* Llamadas: TOKEN_IDENTIFICADOR TOKEN_PARIZQ error TOKEN_PARDER  */
#line 655 "src/parser/parser.y"
                                                          {
        addErrorSintactico("Parámetros inválidos en llamada a función", "global", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.nodo) = crearNodo(AST_LLAMADA_VOID, "Llamada funcion void");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        
        NodoAST* id1 = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
        id1->linea = (yylsp[-3]).first_line; id1->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), id1);
    }
#line 2796 "src/parser/parser.tab.c"
    break;

  case 71: /* lista_parametros: lista_parametros TOKEN_COMA expresion  */
#line 667 "src/parser/parser.y"
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
#line 2812 "src/parser/parser.tab.c"
    break;

  case 72: /* lista_parametros: expresion  */
#line 678 "src/parser/parser.y"
                {
        (yyval.nodo) = crearNodo(AST_LISTA_PARAMETROS, "Lista Parametros");
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 2821 "src/parser/parser.tab.c"
    break;

  case 73: /* Funcion_parametros: tipo_primitivo TOKEN_IDENTIFICADOR TOKEN_PARIZQ parametros TOKEN_PARDER TOKEN_LLAVEIZQ lista_sentencias TOKEN_LLAVEDER  */
#line 685 "src/parser/parser.y"
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
#line 2841 "src/parser/parser.tab.c"
    break;

  case 74: /* Funcion_parametros: tipo_primitivo TOKEN_IDENTIFICADOR TOKEN_PARIZQ error TOKEN_PARDER TOKEN_LLAVEIZQ lista_sentencias TOKEN_LLAVEDER  */
#line 700 "src/parser/parser.y"
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
#line 2863 "src/parser/parser.tab.c"
    break;

  case 75: /* parametros: parametros TOKEN_COMA tipo_primitivo TOKEN_IDENTIFICADOR  */
#line 719 "src/parser/parser.y"
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
#line 2900 "src/parser/parser.tab.c"
    break;

  case 76: /* parametros: tipo_primitivo TOKEN_IDENTIFICADOR  */
#line 751 "src/parser/parser.y"
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
#line 2920 "src/parser/parser.tab.c"
    break;

  case 77: /* tipo_primitivo: TOKEN_DINT  */
#line 770 "src/parser/parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2926 "src/parser/parser.tab.c"
    break;

  case 78: /* tipo_primitivo: TOKEN_DCHAR  */
#line 771 "src/parser/parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2932 "src/parser/parser.tab.c"
    break;

  case 79: /* tipo_primitivo: TOKEN_DOUBLE  */
#line 772 "src/parser/parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2938 "src/parser/parser.tab.c"
    break;

  case 80: /* tipo_primitivo: TOKEN_DFLOAT  */
#line 773 "src/parser/parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2944 "src/parser/parser.tab.c"
    break;

  case 81: /* tipo_primitivo: TOKEN_DSTRING  */
#line 774 "src/parser/parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2950 "src/parser/parser.tab.c"
    break;

  case 82: /* tipo_primitivo: TOKEN_DBOOLEAN  */
#line 775 "src/parser/parser.y"
                     { (yyval.str) = (yyvsp[0].str); }
#line 2956 "src/parser/parser.tab.c"
    break;

  case 83: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_IGUAL expresion  */
#line 780 "src/parser/parser.y"
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
#line 2971 "src/parser/parser.tab.c"
    break;

  case 84: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_MAS_IGUAL expresion  */
#line 790 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "+", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2979 "src/parser/parser.tab.c"
    break;

  case 85: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_MENOS_IGUAL expresion  */
#line 793 "src/parser/parser.y"
                                                      {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "-", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2987 "src/parser/parser.tab.c"
    break;

  case 86: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_POR_IGUAL expresion  */
#line 796 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "*", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2995 "src/parser/parser.tab.c"
    break;

  case 87: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_DIV_IGUAL expresion  */
#line 799 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "/", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3003 "src/parser/parser.tab.c"
    break;

  case 88: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_MOD_IGUAL expresion  */
#line 802 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "%", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3011 "src/parser/parser.tab.c"
    break;

  case 89: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_AND_IGUAL expresion  */
#line 805 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "&", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3019 "src/parser/parser.tab.c"
    break;

  case 90: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_OR_IGUAL expresion  */
#line 808 "src/parser/parser.y"
                                                   {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "|", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3027 "src/parser/parser.tab.c"
    break;

  case 91: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_XOR_IGUAL expresion  */
#line 811 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "^", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3035 "src/parser/parser.tab.c"
    break;

  case 92: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_DESIZQ_IGUAL expresion  */
#line 814 "src/parser/parser.y"
                                                       {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "<<", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3043 "src/parser/parser.tab.c"
    break;

  case 93: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_DESDER_IGUAL expresion  */
#line 817 "src/parser/parser.y"
                                                       {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), ">>", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3051 "src/parser/parser.tab.c"
    break;

  case 94: /* expresion: expresion_or  */
#line 827 "src/parser/parser.y"
                   { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3057 "src/parser/parser.tab.c"
    break;

  case 95: /* expresion_or: expresion_and  */
#line 831 "src/parser/parser.y"
                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3063 "src/parser/parser.tab.c"
    break;

  case 96: /* expresion_or: expresion_or TOKEN_OR expresion_and  */
#line 832 "src/parser/parser.y"
                                          {
          (yyval.nodo) = crearNodo(AST_OPERACION, "||");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3073 "src/parser/parser.tab.c"
    break;

  case 97: /* expresion_and: expresion_bit_or  */
#line 840 "src/parser/parser.y"
                       { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3079 "src/parser/parser.tab.c"
    break;

  case 98: /* expresion_and: expresion_and TOKEN_AND expresion_bit_or  */
#line 841 "src/parser/parser.y"
                                               {
          (yyval.nodo) = crearNodo(AST_OPERACION, "&&");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3089 "src/parser/parser.tab.c"
    break;

  case 99: /* expresion_bit_or: expresion_bit_xor  */
#line 849 "src/parser/parser.y"
                        { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3095 "src/parser/parser.tab.c"
    break;

  case 100: /* expresion_bit_or: expresion_bit_or TOKEN_BIT_OR expresion_bit_xor  */
#line 850 "src/parser/parser.y"
                                                      {
          (yyval.nodo) = crearNodo(AST_OPERACION, "|");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3105 "src/parser/parser.tab.c"
    break;

  case 101: /* expresion_bit_xor: expresion_bit_and  */
#line 858 "src/parser/parser.y"
                        { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3111 "src/parser/parser.tab.c"
    break;

  case 102: /* expresion_bit_xor: expresion_bit_xor TOKEN_XOR expresion_bit_and  */
#line 859 "src/parser/parser.y"
                                                    {
          (yyval.nodo) = crearNodo(AST_OPERACION, "^");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3121 "src/parser/parser.tab.c"
    break;

  case 103: /* expresion_bit_and: expresion_equality  */
#line 867 "src/parser/parser.y"
                         { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3127 "src/parser/parser.tab.c"
    break;

  case 104: /* expresion_bit_and: expresion_bit_and TOKEN_BIT_AND expresion_equality  */
#line 868 "src/parser/parser.y"
                                                         {
          (yyval.nodo) = crearNodo(AST_OPERACION, "&");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3137 "src/parser/parser.tab.c"
    break;

  case 105: /* expresion_equality: expresion_relacional  */
#line 876 "src/parser/parser.y"
                           { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3143 "src/parser/parser.tab.c"
    break;

  case 106: /* expresion_equality: expresion_equality TOKEN_IGUAL_IGUAL expresion_relacional  */
#line 877 "src/parser/parser.y"
                                                                {
          (yyval.nodo) = crearNodo(AST_OPERACION, "==");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3153 "src/parser/parser.tab.c"
    break;

  case 107: /* expresion_equality: expresion_equality TOKEN_NO_IGUAL expresion_relacional  */
#line 882 "src/parser/parser.y"
                                                             {
          (yyval.nodo) = crearNodo(AST_OPERACION, "!=");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3163 "src/parser/parser.tab.c"
    break;

  case 108: /* expresion_relacional: expresion_shift  */
#line 890 "src/parser/parser.y"
                      { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3169 "src/parser/parser.tab.c"
    break;

  case 109: /* expresion_relacional: expresion_relacional TOKEN_MENOR expresion_shift  */
#line 891 "src/parser/parser.y"
                                                       {
          (yyval.nodo) = crearNodo(AST_OPERACION, "<");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3179 "src/parser/parser.tab.c"
    break;

  case 110: /* expresion_relacional: expresion_relacional TOKEN_MENOR_IGUAL expresion_shift  */
#line 896 "src/parser/parser.y"
                                                             {
          (yyval.nodo) = crearNodo(AST_OPERACION, "<=");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3189 "src/parser/parser.tab.c"
    break;

  case 111: /* expresion_relacional: expresion_relacional TOKEN_MAYOR expresion_shift  */
#line 901 "src/parser/parser.y"
                                                       {
          (yyval.nodo) = crearNodo(AST_OPERACION, ">");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3199 "src/parser/parser.tab.c"
    break;

  case 112: /* expresion_relacional: expresion_relacional TOKEN_MAYOR_IGUAL expresion_shift  */
#line 906 "src/parser/parser.y"
                                                             {
          (yyval.nodo) = crearNodo(AST_OPERACION, ">=");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3209 "src/parser/parser.tab.c"
    break;

  case 113: /* expresion_shift: expresion_aditiva  */
#line 914 "src/parser/parser.y"
                        { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3215 "src/parser/parser.tab.c"
    break;

  case 114: /* expresion_shift: expresion_shift TOKEN_DESIZQ expresion_aditiva  */
#line 915 "src/parser/parser.y"
                                                     {
          (yyval.nodo) = crearNodo(AST_OPERACION, "<<");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3225 "src/parser/parser.tab.c"
    break;

  case 115: /* expresion_shift: expresion_shift TOKEN_DESDER expresion_aditiva  */
#line 920 "src/parser/parser.y"
                                                     {
          (yyval.nodo) = crearNodo(AST_OPERACION, ">>");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3235 "src/parser/parser.tab.c"
    break;

  case 116: /* expresion_aditiva: expresion_multiplicativa  */
#line 928 "src/parser/parser.y"
                               { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3241 "src/parser/parser.tab.c"
    break;

  case 117: /* expresion_aditiva: expresion_aditiva TOKEN_MAS expresion_multiplicativa  */
#line 929 "src/parser/parser.y"
                                                           {
          (yyval.nodo) = crearNodo(AST_OPERACION, "+");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3251 "src/parser/parser.tab.c"
    break;

  case 118: /* expresion_aditiva: expresion_aditiva TOKEN_MENOS expresion_multiplicativa  */
#line 934 "src/parser/parser.y"
                                                             {
          (yyval.nodo) = crearNodo(AST_OPERACION, "-");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3261 "src/parser/parser.tab.c"
    break;

  case 119: /* expresion_multiplicativa: expresion_unaria  */
#line 942 "src/parser/parser.y"
                       { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3267 "src/parser/parser.tab.c"
    break;

  case 120: /* expresion_multiplicativa: expresion_multiplicativa TOKEN_MULTI expresion_unaria  */
#line 943 "src/parser/parser.y"
                                                            {
          (yyval.nodo) = crearNodo(AST_OPERACION, "*");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3277 "src/parser/parser.tab.c"
    break;

  case 121: /* expresion_multiplicativa: expresion_multiplicativa TOKEN_DIV expresion_unaria  */
#line 948 "src/parser/parser.y"
                                                          {
          (yyval.nodo) = crearNodo(AST_OPERACION, "/");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3287 "src/parser/parser.tab.c"
    break;

  case 122: /* expresion_multiplicativa: expresion_multiplicativa TOKEN_MODULO expresion_unaria  */
#line 953 "src/parser/parser.y"
                                                             {
          (yyval.nodo) = crearNodo(AST_OPERACION, "%");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3297 "src/parser/parser.tab.c"
    break;

  case 123: /* expresion_unaria: TOKEN_NOT expresion_unaria  */
#line 961 "src/parser/parser.y"
                                 {
          (yyval.nodo) = crearNodo(AST_OPERACION, "!");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3307 "src/parser/parser.tab.c"
    break;

  case 124: /* expresion_unaria: TOKEN_MENOS expresion_unaria  */
#line 966 "src/parser/parser.y"
                                                {
          (yyval.nodo) = crearNodo(AST_OPERACION, "uminus");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 3317 "src/parser/parser.tab.c"
    break;

  case 125: /* expresion_unaria: TOKEN_PARIZQ tipo_primitivo TOKEN_PARDER expresion_unaria  */
#line 971 "src/parser/parser.y"
                                                                {
          /* crear un nodo específico para cast; guardamos el tipo en ->valor */
          (yyval.nodo) = crearNodo(AST_CAST, "cast");
          (yyval.nodo)->valor = strdup((yyvsp[-2].str));    
          (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[0].nodo));
          free((yyvsp[-2].str)); 
      }
#line 3330 "src/parser/parser.tab.c"
    break;

  case 126: /* expresion_unaria: postfix  */
#line 979 "src/parser/parser.y"
              { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3336 "src/parser/parser.tab.c"
    break;

  case 127: /* postfix: primary  */
#line 983 "src/parser/parser.y"
              { (yyval.nodo) = (yyvsp[0].nodo); }
#line 3342 "src/parser/parser.tab.c"
    break;

  case 128: /* postfix: postfix TOKEN_INCREMENTO  */
#line 984 "src/parser/parser.y"
                               {
          (yyval.nodo) = crearNodo(AST_INCREMENTO, "++");
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
      }
#line 3352 "src/parser/parser.tab.c"
    break;

  case 129: /* postfix: postfix TOKEN_DECREMENTO  */
#line 989 "src/parser/parser.y"
                               {
          (yyval.nodo) = crearNodo(AST_DECREMENTO, "--");
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
      }
#line 3362 "src/parser/parser.tab.c"
    break;

  case 130: /* primary: TOKEN_NUMERO  */
#line 998 "src/parser/parser.y"
                   {
          (yyval.nodo) = crearNodo(AST_NUMERO, NULL);
          (yyval.nodo)->valor = strdup((yyvsp[0].str));
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
      }
#line 3372 "src/parser/parser.tab.c"
    break;

  case 131: /* primary: TOKEN_DOUBLE_LITERAL  */
#line 1003 "src/parser/parser.y"
                           {
          (yyval.nodo) = crearNodo(AST_NUMERO, NULL);
          (yyval.nodo)->valor = strdup((yyvsp[0].str));
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
      }
#line 3382 "src/parser/parser.tab.c"
    break;

  case 132: /* primary: TOKEN_FLOAT_LITERAL  */
#line 1008 "src/parser/parser.y"
                          {
          (yyval.nodo) = crearNodo(AST_NUMERO, NULL);
          (yyval.nodo)->valor = strdup((yyvsp[0].str));
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
      }
#line 3392 "src/parser/parser.tab.c"
    break;

  case 133: /* primary: TOKEN_CADENA  */
#line 1013 "src/parser/parser.y"
                   {
          (yyval.nodo) = crearNodo(AST_CADENA, NULL);
          (yyval.nodo)->valor = strdup((yyvsp[0].str));
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
      }
#line 3402 "src/parser/parser.tab.c"
    break;

  case 134: /* primary: TOKEN_CARACTER  */
#line 1018 "src/parser/parser.y"
                     {
          (yyval.nodo) = crearNodo(AST_CARACTER, NULL);
          (yyval.nodo)->valor = strdup((yyvsp[0].str));
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
      }
#line 3412 "src/parser/parser.tab.c"
    break;

  case 135: /* primary: TOKEN_IDENTIFICADOR  */
#line 1023 "src/parser/parser.y"
                          {
          (yyval.nodo) = crearNodo(AST_IDENTIFICADOR, (yyvsp[0].str));
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
      }
#line 3421 "src/parser/parser.tab.c"
    break;

  case 136: /* primary: TOKEN_BOOLEANO  */
#line 1027 "src/parser/parser.y"
                     {
        (yyval.nodo) = crearNodo(AST_BOOLEAN, (yyvsp[0].str));
        (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
    }
#line 3430 "src/parser/parser.tab.c"
    break;

  case 137: /* primary: TOKEN_PARSEINT TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 1031 "src/parser/parser.y"
                                                         {
        (yyval.nodo) = crearNodo(AST_PARSEINT, "Integer.parseInt");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3440 "src/parser/parser.tab.c"
    break;

  case 138: /* primary: TOKEN_PARSEDOUBLE TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 1036 "src/parser/parser.y"
                                                            {
        (yyval.nodo) = crearNodo(AST_PARSEDOUBLE, "Double.parseDouble");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3450 "src/parser/parser.tab.c"
    break;

  case 139: /* primary: TOKEN_PARSEFLOAT TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 1041 "src/parser/parser.y"
                                                           {
        (yyval.nodo) = crearNodo(AST_PARSEFLOAT, "Float.parseFloat");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3460 "src/parser/parser.tab.c"
    break;

  case 140: /* primary: TOKEN_STRING_VALUEOF TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 1046 "src/parser/parser.y"
                                                               {
        (yyval.nodo) = crearNodo(AST_VALUEOF, "String.valueOf");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3470 "src/parser/parser.tab.c"
    break;

  case 141: /* primary: TOKEN_INDEXOF TOKEN_PARIZQ expresion TOKEN_COMA expresion TOKEN_PARDER  */
#line 1051 "src/parser/parser.y"
                                                                             {
        (yyval.nodo) = crearNodo(AST_INDEXOF, "Arrays.indexOf");
        (yyval.nodo)->linea = (yylsp[-5]).first_line; (yyval.nodo)->columna = (yylsp[-5]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-3].nodo));  // El array/vector
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));  // La clave a buscar
    }
#line 3481 "src/parser/parser.tab.c"
    break;

  case 142: /* primary: TOKEN_IDENTIFICADOR TOKEN_PUNTO TOKEN_LENGHT  */
#line 1057 "src/parser/parser.y"
                                                   {
        (yyval.nodo) = crearNodo(AST_LENGHT, "Array.length");
        (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-2].str));
        id->linea = (yylsp[-2]).first_line; id->columna = (yylsp[-2]).first_column;
        agregarHijo((yyval.nodo), id);
    }
#line 3493 "src/parser/parser.tab.c"
    break;

  case 143: /* primary: TOKEN_IDENTIFICADOR TOKEN_PUNTO TOKEN_ADD TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 1064 "src/parser/parser.y"
                                                                                    {
        (yyval.nodo) = crearNodo(AST_ADD, "Array.add");
        (yyval.nodo)->linea = (yylsp[-5]).first_line; (yyval.nodo)->columna = (yylsp[-5]).first_column;
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-5].str));
        id->linea = (yylsp[-5]).first_line; id->columna = (yylsp[-5]).first_column;
        agregarHijo((yyval.nodo), id);
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));  // El elemento a añadir
    }
#line 3506 "src/parser/parser.tab.c"
    break;

  case 144: /* primary: TOKEN_CADENA TOKEN_EQUAL TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 1072 "src/parser/parser.y"
                                                                   {
        (yyval.nodo) = crearNodo(AST_EQUAL, ".equals");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        NodoAST* cadena = crearNodo(AST_CADENA, (yyvsp[-4].str));
        cadena->linea = (yylsp[-4]).first_line; cadena->columna = (yylsp[-4]).first_column;
        agregarHijo((yyval.nodo), cadena);
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3519 "src/parser/parser.tab.c"
    break;

  case 145: /* primary: TOKEN_IDENTIFICADOR TOKEN_EQUAL TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 1080 "src/parser/parser.y"
                                                                          {
        (yyval.nodo) = crearNodo(AST_EQUAL, ".equals");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-4].str));
        id->linea = (yylsp[-4]).first_line; id->columna = (yylsp[-4]).first_column;
        agregarHijo((yyval.nodo), id);
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3532 "src/parser/parser.tab.c"
    break;

  case 146: /* primary: TOKEN_PARSEJOIN TOKEN_PARIZQ expresion TOKEN_COMA lista_expresiones_join TOKEN_PARDER  */
#line 1088 "src/parser/parser.y"
                                                                                            {
        (yyval.nodo) = crearNodo(AST_PARSEJOIN, "Strings.join");
        (yyval.nodo)->linea = (yylsp[-5]).first_line; (yyval.nodo)->columna = (yylsp[-5]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-3].nodo));  // El delimitador
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));  // Lista de expresiones a unir
    }
#line 3543 "src/parser/parser.tab.c"
    break;

  case 147: /* primary: TOKEN_PARSEJOIN TOKEN_PARIZQ expresion TOKEN_COMA expresion TOKEN_PARDER  */
#line 1094 "src/parser/parser.y"
                                                                               {
        (yyval.nodo) = crearNodo(AST_PARSEJOIN, "Strings.join");
        (yyval.nodo)->linea = (yylsp[-5]).first_line; (yyval.nodo)->columna = (yylsp[-5]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-3].nodo));  // El delimitador
        
        // Para un solo elemento, creamos una lista con ese elemento
        NodoAST* lista = crearNodo(AST_LISTA, "Lista Strings");
        agregarHijo(lista, (yyvsp[-1].nodo));
        agregarHijo((yyval.nodo), lista);
    }
#line 3558 "src/parser/parser.tab.c"
    break;

  case 148: /* primary: acceso  */
#line 1104 "src/parser/parser.y"
             {
          (yyval.nodo) = (yyvsp[0].nodo);
      }
#line 3566 "src/parser/parser.tab.c"
    break;

  case 149: /* primary: Llamadas  */
#line 1107 "src/parser/parser.y"
              {
        (yyval.nodo) = (yyvsp[0].nodo);
    }
#line 3574 "src/parser/parser.tab.c"
    break;

  case 150: /* primary: TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 1110 "src/parser/parser.y"
                                          {
          (yyval.nodo) = (yyvsp[-1].nodo);
      }
#line 3582 "src/parser/parser.tab.c"
    break;

  case 151: /* lista_expresiones_join: lista_expresiones_join TOKEN_COMA expresion  */
#line 1116 "src/parser/parser.y"
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
#line 3598 "src/parser/parser.tab.c"
    break;

  case 152: /* lista_expresiones_join: expresion  */
#line 1127 "src/parser/parser.y"
                {
        (yyval.nodo) = crearNodo(AST_LISTA, "Lista Strings");
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3607 "src/parser/parser.tab.c"
    break;

  case 153: /* instruccion_print: TOKEN_PRINT TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 1135 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crearNodo(AST_PRINT, "System.out.println");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3617 "src/parser/parser.tab.c"
    break;

  case 154: /* instruccion_print: TOKEN_PRINT TOKEN_PARIZQ TOKEN_CADENA TOKEN_MAS expresion TOKEN_PARDER  */
#line 1141 "src/parser/parser.y"
                                                                             {
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
#line 3634 "src/parser/parser.tab.c"
    break;

  case 155: /* instruccion_print: TOKEN_PRINT TOKEN_PARIZQ TOKEN_PARDER  */
#line 1153 "src/parser/parser.y"
                                            {
        (yyval.nodo) = crearNodo(AST_PRINT, "System.out.println");
        (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;
        // No hijos, print vacío
    }
#line 3644 "src/parser/parser.tab.c"
    break;

  case 156: /* bloque: TOKEN_LLAVEIZQ lista_sentencias TOKEN_LLAVEDER  */
#line 1161 "src/parser/parser.y"
                                                   {
        (yyval.nodo) = crearNodo(AST_BLOQUE, "Bloque");
        (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3654 "src/parser/parser.tab.c"
    break;

  case 157: /* bloque: TOKEN_LLAVEIZQ error TOKEN_LLAVEDER  */
#line 1166 "src/parser/parser.y"
                                          {
        addErrorSintactico("Error sintáctico en el bloque", "global", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.nodo) = crearNodo(AST_BLOQUE, "Bloque");
        (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;
        // Crear un bloque vacío para continuar
        agregarHijo((yyval.nodo), crearNodo(AST_LISTA, "Programa"));
    }
#line 3666 "src/parser/parser.tab.c"
    break;

  case 158: /* instruccion_break: TOKEN_BREAK  */
#line 1176 "src/parser/parser.y"
                {
        (yyval.nodo) = crearNodo(AST_BREAK, "break");
        (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
    }
#line 3675 "src/parser/parser.tab.c"
    break;

  case 159: /* instruccion_continue: TOKEN_CONTINUE  */
#line 1183 "src/parser/parser.y"
                   {
        (yyval.nodo) = crearNodo(AST_CONTINUE, "continue");
        (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
    }
#line 3684 "src/parser/parser.tab.c"
    break;

  case 160: /* instruccion_return: TOKEN_RETURN expresion  */
#line 1190 "src/parser/parser.y"
                           {
        (yyval.nodo) = crearNodo(AST_RETURN, "return");
        (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3694 "src/parser/parser.tab.c"
    break;

  case 161: /* instruccion_if: TOKEN_IF TOKEN_PARIZQ expresion TOKEN_PARDER bloque  */
#line 1200 "src/parser/parser.y"
                                                                       {
        printf("[DEBUG] Procesando if en línea %d, columna %d\n", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
        (yyval.nodo) = crearNodo(AST_IF, "if");
        (yyval.nodo)->linea = (yylsp[-4]).first_line; (yyval.nodo)->columna = (yylsp[-4]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));   // condición
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));   // bloque if
    }
#line 3706 "src/parser/parser.tab.c"
    break;

  case 162: /* instruccion_if: TOKEN_IF TOKEN_PARIZQ expresion TOKEN_PARDER bloque TOKEN_ELSE bloque  */
#line 1207 "src/parser/parser.y"
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
#line 3721 "src/parser/parser.tab.c"
    break;

  case 163: /* instruccion_if: TOKEN_IF TOKEN_PARIZQ expresion TOKEN_PARDER bloque TOKEN_ELSE instruccion_if  */
#line 1217 "src/parser/parser.y"
                                                                                    {
        (yyval.nodo) = crearNodo(AST_IF, "if");
        (yyval.nodo)->linea = (yylsp[-6]).first_line; (yyval.nodo)->columna = (yylsp[-6]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));   // condición
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));   // bloque if
        NodoAST* elseif_node = crearNodo(AST_ELSEIF, "elseif");
        agregarHijo(elseif_node, (yyvsp[0].nodo));
        agregarHijo((yyval.nodo), elseif_node);
    }
#line 3735 "src/parser/parser.tab.c"
    break;

  case 164: /* instruccion_if: TOKEN_IF TOKEN_PARIZQ error TOKEN_PARDER bloque  */
#line 1226 "src/parser/parser.y"
                                                                     {
        printf("[DEBUG] Error en condición del if en línea %d, columna %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        addErrorSintactico("Expresión inválida en condición if", "global", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        (yyval.nodo) = crearNodo(AST_IF, "if");
        (yyval.nodo)->linea = (yylsp[-4]).first_line; (yyval.nodo)->columna = (yylsp[-4]).first_column;
        agregarHijo((yyval.nodo), crearNodo(AST_BOOLEAN, "false"));  // condición predeterminada
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));  // bloque if
    }
#line 3748 "src/parser/parser.tab.c"
    break;

  case 165: /* intruccion_switch: TOKEN_SWITCH TOKEN_PARIZQ expresion TOKEN_PARDER TOKEN_LLAVEIZQ lista_casos TOKEN_LLAVEDER  */
#line 1238 "src/parser/parser.y"
                                                                                               {
        (yyval.nodo) = crearNodo(AST_SWITCH, "switch");
        (yyval.nodo)->linea = (yylsp[-6]).first_line; (yyval.nodo)->columna = (yylsp[-6]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3759 "src/parser/parser.tab.c"
    break;

  case 166: /* lista_casos: lista_casos caso  */
#line 1247 "src/parser/parser.y"
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
#line 3775 "src/parser/parser.tab.c"
    break;

  case 167: /* lista_casos: caso  */
#line 1258 "src/parser/parser.y"
           {
        (yyval.nodo) = crearNodo(AST_LISTA, "Casos");
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3784 "src/parser/parser.tab.c"
    break;

  case 168: /* caso: TOKEN_CASE expresion TOKEN_DOS_PUNTOS lista_sentencias TOKEN_BREAK TOKEN_PUNTOCOMA  */
#line 1265 "src/parser/parser.y"
                                                                                      {
        (yyval.nodo) = crearNodo(AST_CASE, "CASE");
        (yyval.nodo)->linea = (yylsp[-5]).first_line; (yyval.nodo)->columna = (yylsp[-5]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));
        NodoAST* nodoBreak = crearNodo(AST_BREAK, "break");
        nodoBreak->linea = (yylsp[-1]).first_line; nodoBreak->columna = (yylsp[-1]).first_column;
        agregarHijo((yyval.nodo), nodoBreak);
    }
#line 3798 "src/parser/parser.tab.c"
    break;

  case 169: /* caso: TOKEN_DEFAULT TOKEN_DOS_PUNTOS lista_sentencias  */
#line 1274 "src/parser/parser.y"
                                                      {
        (yyval.nodo) = crearNodo(AST_DEFAULT, "DEFAULT");
        (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3808 "src/parser/parser.tab.c"
    break;

  case 170: /* instruccion_while: TOKEN_WHILE TOKEN_PARIZQ expresion TOKEN_PARDER bloque  */
#line 1282 "src/parser/parser.y"
                                                           {
        (yyval.nodo) = crearNodo(AST_WHILE, "while");
        (yyval.nodo)->linea = (yylsp[-4]).first_line; (yyval.nodo)->columna = (yylsp[-4]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3819 "src/parser/parser.tab.c"
    break;

  case 171: /* instruccion_while: TOKEN_WHILE TOKEN_PARIZQ error TOKEN_PARDER bloque  */
#line 1288 "src/parser/parser.y"
                                                         {
        addErrorSintactico("Expresión inválida en condición while", "global", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        (yyval.nodo) = crearNodo(AST_WHILE, "while");
        (yyval.nodo)->linea = (yylsp[-4]).first_line; (yyval.nodo)->columna = (yylsp[-4]).first_column;
        // Agregar una condición predeterminada (false)
        agregarHijo((yyval.nodo), crearNodo(AST_BOOLEAN, "false"));
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));  // bloque while
    }
#line 3832 "src/parser/parser.tab.c"
    break;

  case 172: /* instruccion_for: TOKEN_FOR TOKEN_PARIZQ declaracion TOKEN_PUNTOCOMA expresion TOKEN_PUNTOCOMA expresion TOKEN_PARDER bloque  */
#line 1299 "src/parser/parser.y"
                                                                                                              {
        (yyval.nodo) = crearNodo(AST_FOR, "FOR");
        (yyval.nodo)->linea = (yylsp[-8]).first_line; (yyval.nodo)->columna = (yylsp[-8]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-6].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3845 "src/parser/parser.tab.c"
    break;

  case 173: /* instruccion_for: TOKEN_FOR TOKEN_PARIZQ asignacion TOKEN_PUNTOCOMA expresion TOKEN_PUNTOCOMA expresion TOKEN_PARDER bloque  */
#line 1307 "src/parser/parser.y"
                                                                                                               {
        (yyval.nodo) = crearNodo(AST_FOR, "FOR");
        (yyval.nodo)->linea = (yylsp[-8]).first_line; (yyval.nodo)->columna = (yylsp[-8]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-6].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3858 "src/parser/parser.tab.c"
    break;

  case 174: /* instruccion_for: TOKEN_FOR TOKEN_PARIZQ declaracion TOKEN_DOS_PUNTOS expresion TOKEN_PARDER bloque  */
#line 1315 "src/parser/parser.y"
                                                                                        {
        (yyval.nodo) = crearNodo(AST_FOR_VECTOR, "FOR");
        (yyval.nodo)->linea = (yylsp[-6]).first_line; (yyval.nodo)->columna = (yylsp[-6]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3870 "src/parser/parser.tab.c"
    break;

  case 175: /* instruccion_for: TOKEN_FOR TOKEN_PARIZQ error TOKEN_PUNTOCOMA expresion TOKEN_PUNTOCOMA expresion TOKEN_PARDER bloque  */
#line 1322 "src/parser/parser.y"
                                                                                                           {
        addErrorSintactico("Inicialización inválida en bucle for", "global", (yylsp[-6]).first_line, (yylsp[-6]).first_column);
        (yyval.nodo) = crearNodo(AST_FOR, "FOR");
        (yyval.nodo)->linea = (yylsp[-8]).first_line; (yyval.nodo)->columna = (yylsp[-8]).first_column;
        NodoAST* decl = crearNodo(AST_DECLARACION, "declaracion");
        agregarHijo((yyval.nodo), decl);
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3885 "src/parser/parser.tab.c"
    break;

  case 176: /* instruccion_for: TOKEN_FOR TOKEN_PARIZQ declaracion TOKEN_PUNTOCOMA error TOKEN_PUNTOCOMA expresion TOKEN_PARDER bloque  */
#line 1332 "src/parser/parser.y"
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
#line 3900 "src/parser/parser.tab.c"
    break;


#line 3904 "src/parser/parser.tab.c"

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

#line 1345 "src/parser/parser.y"


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
