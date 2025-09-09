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
  YYSYMBOL_TOKEN_MAS_IGUAL = 68,           /* TOKEN_MAS_IGUAL  */
  YYSYMBOL_TOKEN_MENOS_IGUAL = 69,         /* TOKEN_MENOS_IGUAL  */
  YYSYMBOL_TOKEN_POR_IGUAL = 70,           /* TOKEN_POR_IGUAL  */
  YYSYMBOL_TOKEN_DIV_IGUAL = 71,           /* TOKEN_DIV_IGUAL  */
  YYSYMBOL_TOKEN_MOD_IGUAL = 72,           /* TOKEN_MOD_IGUAL  */
  YYSYMBOL_TOKEN_AND_IGUAL = 73,           /* TOKEN_AND_IGUAL  */
  YYSYMBOL_TOKEN_OR_IGUAL = 74,            /* TOKEN_OR_IGUAL  */
  YYSYMBOL_TOKEN_XOR_IGUAL = 75,           /* TOKEN_XOR_IGUAL  */
  YYSYMBOL_TOKEN_DESIZQ_IGUAL = 76,        /* TOKEN_DESIZQ_IGUAL  */
  YYSYMBOL_TOKEN_DESDER_IGUAL = 77,        /* TOKEN_DESDER_IGUAL  */
  YYSYMBOL_UMINUS = 78,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 79,                  /* $accept  */
  YYSYMBOL_s = 80,                         /* s  */
  YYSYMBOL_programa = 81,                  /* programa  */
  YYSYMBOL_lista_sentencias = 82,          /* lista_sentencias  */
  YYSYMBOL_sentencia = 83,                 /* sentencia  */
  YYSYMBOL_declaracion = 84,               /* declaracion  */
  YYSYMBOL_declaracion_vector = 85,        /* declaracion_vector  */
  YYSYMBOL_lista_elementos = 86,           /* lista_elementos  */
  YYSYMBOL_lista_filas = 87,               /* lista_filas  */
  YYSYMBOL_declaracion_matriz = 88,        /* declaracion_matriz  */
  YYSYMBOL_declaracion_array_multidimensional = 89, /* declaracion_array_multidimensional  */
  YYSYMBOL_lista_bloques = 90,             /* lista_bloques  */
  YYSYMBOL_lista_elementos_o_bloques = 91, /* lista_elementos_o_bloques  */
  YYSYMBOL_DimensionesCorchetes = 92,      /* DimensionesCorchetes  */
  YYSYMBOL_Dimensiones = 93,               /* Dimensiones  */
  YYSYMBOL_acceso = 94,                    /* acceso  */
  YYSYMBOL_DimensionesAcceso = 95,         /* DimensionesAcceso  */
  YYSYMBOL_tipo_primitivo = 96,            /* tipo_primitivo  */
  YYSYMBOL_asignacion = 97,                /* asignacion  */
  YYSYMBOL_expresion = 98,                 /* expresion  */
  YYSYMBOL_expresion_or = 99,              /* expresion_or  */
  YYSYMBOL_expresion_and = 100,            /* expresion_and  */
  YYSYMBOL_expresion_bit_or = 101,         /* expresion_bit_or  */
  YYSYMBOL_expresion_bit_xor = 102,        /* expresion_bit_xor  */
  YYSYMBOL_expresion_bit_and = 103,        /* expresion_bit_and  */
  YYSYMBOL_expresion_equality = 104,       /* expresion_equality  */
  YYSYMBOL_expresion_relacional = 105,     /* expresion_relacional  */
  YYSYMBOL_expresion_shift = 106,          /* expresion_shift  */
  YYSYMBOL_expresion_aditiva = 107,        /* expresion_aditiva  */
  YYSYMBOL_expresion_multiplicativa = 108, /* expresion_multiplicativa  */
  YYSYMBOL_expresion_unaria = 109,         /* expresion_unaria  */
  YYSYMBOL_postfix = 110,                  /* postfix  */
  YYSYMBOL_primary = 111,                  /* primary  */
  YYSYMBOL_lista_expresiones_join = 112,   /* lista_expresiones_join  */
  YYSYMBOL_instruccion_print = 113,        /* instruccion_print  */
  YYSYMBOL_bloque = 114,                   /* bloque  */
  YYSYMBOL_instruccion_break = 115,        /* instruccion_break  */
  YYSYMBOL_instruccion_continue = 116,     /* instruccion_continue  */
  YYSYMBOL_instruccion_if = 117,           /* instruccion_if  */
  YYSYMBOL_intruccion_switch = 118,        /* intruccion_switch  */
  YYSYMBOL_lista_casos = 119,              /* lista_casos  */
  YYSYMBOL_caso = 120,                     /* caso  */
  YYSYMBOL_instruccion_while = 121,        /* instruccion_while  */
  YYSYMBOL_instruccion_for = 122           /* instruccion_for  */
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
#define YYFINAL  97
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   655

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  310

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   333


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
      75,    76,    77,    78
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   101,   101,   113,   118,   129,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     155,   164,   175,   190,   210,   221,   253,   264,   271,   282,
     289,   313,   335,   362,   382,   393,   400,   406,   415,   434,
     440,   444,   454,   469,   479,   489,   490,   491,   492,   493,
     494,   499,   509,   512,   515,   518,   521,   524,   527,   530,
     533,   536,   546,   550,   551,   559,   560,   568,   569,   577,
     578,   586,   587,   595,   596,   601,   609,   610,   615,   620,
     625,   633,   634,   639,   647,   648,   653,   661,   662,   667,
     672,   680,   685,   690,   698,   702,   703,   709,   718,   723,
     728,   733,   738,   743,   747,   751,   756,   761,   766,   771,
     777,   784,   792,   798,   808,   811,   817,   828,   836,   841,
     857,   865,   872,   879,   885,   894,   907,   916,   927,   934,
     943,   951,   960,   968
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
  "TOKEN_PUNTO", "TOKEN_MAS_IGUAL", "TOKEN_MENOS_IGUAL", "TOKEN_POR_IGUAL",
  "TOKEN_DIV_IGUAL", "TOKEN_MOD_IGUAL", "TOKEN_AND_IGUAL",
  "TOKEN_OR_IGUAL", "TOKEN_XOR_IGUAL", "TOKEN_DESIZQ_IGUAL",
  "TOKEN_DESDER_IGUAL", "UMINUS", "$accept", "s", "programa",
  "lista_sentencias", "sentencia", "declaracion", "declaracion_vector",
  "lista_elementos", "lista_filas", "declaracion_matriz",
  "declaracion_array_multidimensional", "lista_bloques",
  "lista_elementos_o_bloques", "DimensionesCorchetes", "Dimensiones",
  "acceso", "DimensionesAcceso", "tipo_primitivo", "asignacion",
  "expresion", "expresion_or", "expresion_and", "expresion_bit_or",
  "expresion_bit_xor", "expresion_bit_and", "expresion_equality",
  "expresion_relacional", "expresion_shift", "expresion_aditiva",
  "expresion_multiplicativa", "expresion_unaria", "postfix", "primary",
  "lista_expresiones_join", "instruccion_print", "bloque",
  "instruccion_break", "instruccion_continue", "instruccion_if",
  "intruccion_switch", "lista_casos", "caso", "instruccion_while",
  "instruccion_for", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-234)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-131)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     467,   -13,   467,   584,  -234,  -234,    15,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,   -15,   177,   584,
      -7,    -2,  -234,    73,  -234,    75,    81,    83,    88,   125,
     127,   136,    33,  -234,   275,  -234,    -9,    29,   151,   153,
    -234,    24,   163,   164,   -24,    -4,   165,   166,    12,    79,
      99,    87,   134,   102,  -234,   138,  -234,   176,  -234,   178,
     187,  -234,  -234,  -234,  -234,  -234,   403,     5,  -234,   584,
     584,   114,   584,   584,   584,   584,   584,   584,   584,   584,
     584,   584,   210,   591,   183,   184,  -234,   584,   584,   584,
     118,   584,   584,   584,   584,   584,   584,  -234,  -234,  -234,
    -234,  -234,  -234,   213,    20,  -234,  -234,   584,   584,   584,
     584,   584,   584,   584,   584,   584,   584,   584,   584,   584,
     584,   584,   584,   584,   584,  -234,  -234,  -234,  -234,  -234,
    -234,   215,  -234,  -234,   189,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,   584,   216,   190,   584,  -234,
     192,   195,   196,    25,   207,   219,   208,   199,   209,   211,
     212,   218,   223,    98,   236,   584,   227,    -4,   165,   166,
      12,    79,    99,    99,    87,    87,    87,    87,   134,   134,
     102,   102,  -234,  -234,  -234,  -234,   584,   245,   584,  -234,
    -234,   248,   249,   248,   584,   233,   584,  -234,  -234,  -234,
    -234,   584,   584,   251,   235,   255,  -234,    42,   228,  -234,
     229,   217,   129,  -234,   237,   242,   234,   -10,   238,   252,
      23,  -234,   267,   135,  -234,  -234,    60,   584,   253,    14,
    -234,   584,   584,  -234,   584,  -234,  -234,   250,   584,   135,
     214,   101,     2,  -234,   269,  -234,  -234,   257,   467,  -234,
    -234,   246,   254,  -234,   100,     6,  -234,   279,   220,     9,
      10,  -234,   267,   258,   293,   467,   339,   248,   248,   295,
     135,  -234,   584,   584,   268,  -234,  -234,  -234,   294,   282,
     531,  -234,  -234,   584,    11,   305,  -234,   306,   584,  -234,
     307,   287,    18,  -234,   310,   584,  -234,   281,  -234,  -234,
    -234,   584,   311,  -234,    19,   313,  -234,   584,   314,  -234
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    50,   104,   103,    45,    48,    49,
      46,    47,    98,   101,   102,   100,    99,     0,     0,     0,
       0,     0,   121,     0,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     5,     0,     0,     0,     0,
     114,     0,     0,     0,    62,    63,    65,    67,    69,    71,
      73,    76,    81,    84,    87,    94,    95,     0,    16,     0,
       0,     9,    10,    11,    12,    20,     0,   103,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     4,     6,
      13,    14,    15,     0,    22,     7,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,     8,    18,    19,
     120,     0,    51,   110,     0,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,     0,   101,     0,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    64,    66,    68,
      70,    72,    74,    75,    80,    78,    79,    77,    82,    83,
      85,    86,    88,    89,    90,    44,     0,     0,     0,   118,
      93,     0,     0,     0,     0,    22,     0,   108,   105,   107,
     106,     0,     0,     0,     0,    39,    21,     0,     0,    43,
       0,   123,     0,   131,     0,     0,   117,     0,     0,     0,
       0,    38,     0,     0,   111,   119,     0,     0,     0,     0,
     128,     0,     0,   113,     0,   112,   109,     0,     0,     0,
       0,     0,     0,    35,     0,   124,   125,     0,     0,   126,
     127,     0,     0,   116,     0,     0,    27,     0,     0,     0,
       0,    33,     0,     0,    32,     0,     0,     0,     0,     0,
       0,    24,     0,     0,     0,    36,    37,    34,     0,     0,
       0,   132,   133,     0,     0,     0,    26,     0,     0,    40,
       0,     0,     0,    31,     0,     0,    23,     0,    41,   129,
      29,     0,     0,    25,     0,     0,    28,     0,     0,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -234,  -234,  -234,    -1,   -32,   226,  -234,  -233,  -234,  -234,
    -234,    78,    59,   117,  -234,  -234,  -234,   -11,   244,   -18,
    -234,   221,   239,   232,   240,   241,    54,    57,    67,    70,
       0,  -234,  -234,  -234,  -234,  -187,  -234,  -234,   119,  -234,
    -234,    96,  -234,  -234
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    32,    33,    34,    35,    36,    37,   255,   284,    38,
      39,   242,   243,   166,   264,    40,    82,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,   217,    57,    58,    59,    60,    61,    62,
     229,   230,    63,    64
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,    66,    98,    68,   211,   261,   213,    84,   259,   271,
      69,    65,   275,   276,   293,    99,   234,   249,    83,    86,
      69,   300,   306,   107,   235,   164,    87,   238,   262,   103,
     239,    88,   272,    97,    98,   272,   262,   294,    70,   245,
     240,   104,   108,   165,   272,   272,   222,   111,    70,   223,
     292,   131,   132,   100,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,     2,   147,   227,   228,   304,   150,
     151,   152,    71,   157,   158,   159,   160,   161,   162,   155,
     281,   282,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,   203,   269,   241,    89,   270,    90,    20,
     122,   123,   124,     3,    91,   204,    92,     5,    67,   112,
     113,    93,   182,   183,   184,   118,   119,   187,    12,    13,
      14,    15,    16,     4,    18,   153,     7,     8,     9,    10,
      11,   114,   115,   116,   117,   120,   121,   206,   190,    19,
       4,   125,   126,     7,     8,     9,    10,    11,    94,    26,
      95,    27,    28,    29,    30,    31,   172,   173,   208,    96,
     210,   174,   175,   176,   177,   101,   214,   102,   215,   133,
     134,   227,   228,   216,   218,   178,   179,   105,   106,     3,
     180,   181,     4,     5,    67,     7,     8,     9,    10,    11,
     127,   109,   128,   110,    12,    13,    14,    15,    16,   247,
      18,   129,   244,   251,   252,   145,   253,   148,   149,   163,
     256,   185,   186,   256,   189,    19,   191,   188,   257,   192,
     193,   194,   196,   197,    98,    26,   195,    27,    28,    29,
      30,    31,   205,   198,   201,   199,   200,   266,    98,   202,
     207,   209,     2,   212,   286,   287,   165,   219,   220,   285,
     164,   231,   224,   225,   280,   256,   232,   226,   233,   237,
     297,   241,   236,   254,   263,    -3,     1,   302,   248,     2,
     267,   258,   265,   256,   273,   278,   274,     3,   268,   308,
       4,     5,     6,     7,     8,     9,    10,    11,   279,   283,
     289,   288,    12,    13,    14,    15,    16,    17,    18,   290,
     295,   299,   296,   298,   301,   303,   154,   305,   307,   260,
     309,   277,   221,    19,    20,   250,    21,     0,   167,    22,
      23,    24,    25,    26,   156,    27,    28,    29,    30,    31,
       1,   169,  -130,     2,     0,   246,     0,   168,     0,     0,
     170,     3,   171,     0,     4,     5,     6,     7,     8,     9,
      10,    11,     0,     0,     0,     0,    12,    13,    14,    15,
      16,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,     0,
      21,  -130,  -130,    22,    23,    24,    25,    26,     0,    27,
      28,    29,    30,    31,     1,     0,   130,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,     0,     0,     0,     0,
      12,    13,    14,    15,    16,    17,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    20,     0,    21,     0,     0,    22,    23,    24,
      25,    26,     0,    27,    28,    29,    30,    31,     1,     0,
       0,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
       0,     0,     0,     0,    12,    13,    14,    15,    16,    17,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    20,     0,    21,     0,
       0,    22,    23,    24,    25,    26,     0,    27,    28,    29,
      30,    31,     1,     0,     0,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,     0,     0,     0,     0,    12,    13,
      14,    15,    16,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
      20,     0,    21,     0,     0,   291,    23,    24,    25,    26,
       0,    27,    28,    29,    30,    31,     3,     0,     0,     0,
       5,    67,     0,     3,     0,     0,     0,     5,    67,     0,
       0,    12,    13,    14,    15,    16,     0,    18,    12,   146,
      14,    15,    16,     0,    18,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,     0,     0,     0,     0,    19,
       0,     0,    26,     0,    27,    28,    29,    30,    31,    26,
       0,    27,    28,    29,    30,    31
};

static const yytype_int16 yycheck[] =
{
      18,     2,    34,     3,   191,     3,   193,    18,   241,     3,
       5,    24,     3,     3,     3,    24,    26,     3,    33,    19,
       5,     3,     3,    47,    34,     5,    33,     4,    26,     5,
       7,    33,    26,     0,    66,    26,    26,    26,    23,   226,
      17,    17,    46,    23,    26,    26,     4,    35,    23,     7,
     283,    69,    70,    24,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     4,    83,    52,    53,   301,    87,
      88,    89,    67,    91,    92,    93,    94,    95,    96,    90,
     267,   268,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     5,     4,     4,    33,     7,    33,    49,
       8,     9,    10,    12,    33,    17,    33,    16,    17,    40,
      41,    33,   122,   123,   124,    38,    39,   145,    27,    28,
      29,    30,    31,    15,    33,    17,    18,    19,    20,    21,
      22,    42,    43,    44,    45,    11,    12,   165,   148,    48,
      15,    13,    14,    18,    19,    20,    21,    22,    33,    58,
      33,    60,    61,    62,    63,    64,   112,   113,   186,    33,
     188,   114,   115,   116,   117,    24,   194,    24,   196,    65,
      66,    52,    53,   201,   202,   118,   119,    24,    24,    12,
     120,   121,    15,    16,    17,    18,    19,    20,    21,    22,
      24,    36,    24,    37,    27,    28,    29,    30,    31,   227,
      33,    24,   223,   231,   232,     5,   234,    34,    34,     6,
     238,     6,    33,   241,    34,    48,    34,    11,   239,    34,
      34,    24,    24,    34,   266,    58,    17,    60,    61,    62,
      63,    64,     6,    34,    26,    34,    34,   248,   280,    26,
      23,     6,     4,     4,   272,   273,    23,     6,    23,   270,
       5,    24,    34,    34,   265,   283,    24,    50,    34,    17,
     288,     4,    34,    23,     5,     0,     1,   295,    25,     4,
      34,    67,    25,   301,     5,    27,    66,    12,    34,   307,
      15,    16,    17,    18,    19,    20,    21,    22,     5,     4,
       6,    33,    27,    28,    29,    30,    31,    32,    33,    27,
       5,    24,     6,     6,     4,    34,    90,     6,     5,   241,
       6,   262,   205,    48,    49,   229,    51,    -1,   107,    54,
      55,    56,    57,    58,    90,    60,    61,    62,    63,    64,
       1,   109,     3,     4,    -1,   226,    -1,   108,    -1,    -1,
     110,    12,   111,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      61,    62,    63,    64,     1,    -1,     3,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    -1,    51,    -1,    -1,    54,    55,    56,
      57,    58,    -1,    60,    61,    62,    63,    64,     1,    -1,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    51,    -1,
      -1,    54,    55,    56,    57,    58,    -1,    60,    61,    62,
      63,    64,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    51,    -1,    -1,    54,    55,    56,    57,    58,
      -1,    60,    61,    62,    63,    64,    12,    -1,    -1,    -1,
      16,    17,    -1,    12,    -1,    -1,    -1,    16,    17,    -1,
      -1,    27,    28,    29,    30,    31,    -1,    33,    27,    28,
      29,    30,    31,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    58,    -1,    60,    61,    62,    63,    64,    58,
      -1,    60,    61,    62,    63,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     4,    12,    15,    16,    17,    18,    19,    20,
      21,    22,    27,    28,    29,    30,    31,    32,    33,    48,
      49,    51,    54,    55,    56,    57,    58,    60,    61,    62,
      63,    64,    80,    81,    82,    83,    84,    85,    88,    89,
      94,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   113,   114,   115,
     116,   117,   118,   121,   122,    24,    82,    17,   109,     5,
      23,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    95,    33,    96,    98,   109,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,     0,    83,    24,
      24,    24,    24,     5,    17,    24,    24,    47,    46,    36,
      37,    35,    40,    41,    42,    43,    44,    45,    38,    39,
      11,    12,     8,     9,    10,    13,    14,    24,    24,    24,
       3,    98,    98,    65,    66,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,     5,    28,    98,    34,    34,
      98,    98,    98,    17,    84,    96,    97,    98,    98,    98,
      98,    98,    98,     6,     5,    23,    92,   100,   101,   102,
     103,   104,   105,   105,   106,   106,   106,   106,   107,   107,
     108,   108,   109,   109,   109,     6,    33,    98,    11,    34,
     109,    34,    34,    34,    24,    17,    24,    34,    34,    34,
      34,    26,    26,     5,    17,     6,    98,    23,    98,     6,
      98,   114,     4,   114,    98,    98,    98,   112,    98,     6,
      23,    92,     4,     7,    34,    34,    50,    52,    53,   119,
     120,    24,    24,    34,    26,    34,    34,    17,     4,     7,
      17,     4,    90,    91,    96,   114,   117,    98,    25,     3,
     120,    98,    98,    98,    23,    86,    98,    96,    67,    86,
      90,     3,    26,     5,    93,    25,    82,    34,    34,     4,
       7,     3,    26,     5,    66,     3,     3,    91,    27,     5,
      82,   114,   114,     4,    87,    96,    98,    98,    33,     6,
      27,    54,    86,     3,    26,     5,     6,    98,     6,    24,
       3,     4,    98,    34,    86,     6,     3,     5,    98,     6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    79,    80,    81,    82,    82,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    84,    84,    85,    85,    85,    86,    86,    87,    87,
      88,    88,    89,    89,    90,    90,    91,    91,    92,    92,
      93,    93,    94,    95,    95,    96,    96,    96,    96,    96,
      96,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    98,    99,    99,   100,   100,   101,   101,   102,
     102,   103,   103,   104,   104,   104,   105,   105,   105,   105,
     105,   106,   106,   106,   107,   107,   107,   108,   108,   108,
     108,   109,   109,   109,   109,   110,   110,   110,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   112,   112,   113,   113,
     114,   115,   116,   117,   117,   117,   118,   119,   119,   120,
     120,   121,   122,   122
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     2,     2,     1,
       1,     1,     1,     2,     2,     2,     1,     2,     2,     2,
       2,     4,     2,    10,     8,    11,     3,     1,     5,     3,
      15,    10,     7,     7,     3,     1,     3,     3,     3,     2,
       3,     4,     2,     4,     3,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     2,     2,     4,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     6,
       3,     6,     6,     6,     1,     3,     3,     1,     4,     6,
       3,     1,     1,     5,     7,     7,     7,     2,     1,     6,
       3,     5,     9,     9
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
#line 101 "src/parser/parser.y"
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
#line 1886 "src/parser/parser.tab.c"
    break;

  case 3: /* programa: lista_sentencias  */
#line 113 "src/parser/parser.y"
                           { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1892 "src/parser/parser.tab.c"
    break;

  case 4: /* lista_sentencias: lista_sentencias sentencia  */
#line 118 "src/parser/parser.y"
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
#line 1908 "src/parser/parser.tab.c"
    break;

  case 5: /* lista_sentencias: sentencia  */
#line 129 "src/parser/parser.y"
                { 
        if ((yyvsp[0].nodo)) {
            (yyval.nodo) = (yyvsp[0].nodo);
        } else {
            (yyval.nodo) = crearNodo(AST_LISTA, "Programa");
        }
    }
#line 1920 "src/parser/parser.tab.c"
    break;

  case 6: /* sentencia: declaracion TOKEN_PUNTOCOMA  */
#line 140 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1926 "src/parser/parser.tab.c"
    break;

  case 7: /* sentencia: asignacion TOKEN_PUNTOCOMA  */
#line 141 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1932 "src/parser/parser.tab.c"
    break;

  case 8: /* sentencia: instruccion_print TOKEN_PUNTOCOMA  */
#line 142 "src/parser/parser.y"
                                        { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1938 "src/parser/parser.tab.c"
    break;

  case 9: /* sentencia: instruccion_if  */
#line 143 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1944 "src/parser/parser.tab.c"
    break;

  case 10: /* sentencia: intruccion_switch  */
#line 144 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1950 "src/parser/parser.tab.c"
    break;

  case 11: /* sentencia: instruccion_while  */
#line 145 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1956 "src/parser/parser.tab.c"
    break;

  case 12: /* sentencia: instruccion_for  */
#line 146 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1962 "src/parser/parser.tab.c"
    break;

  case 13: /* sentencia: declaracion_vector TOKEN_PUNTOCOMA  */
#line 147 "src/parser/parser.y"
                                              { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1968 "src/parser/parser.tab.c"
    break;

  case 14: /* sentencia: declaracion_matriz TOKEN_PUNTOCOMA  */
#line 148 "src/parser/parser.y"
                                              { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1974 "src/parser/parser.tab.c"
    break;

  case 15: /* sentencia: declaracion_array_multidimensional TOKEN_PUNTOCOMA  */
#line 149 "src/parser/parser.y"
                                                         { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1980 "src/parser/parser.tab.c"
    break;

  case 16: /* sentencia: bloque  */
#line 150 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1986 "src/parser/parser.tab.c"
    break;

  case 17: /* sentencia: expresion TOKEN_PUNTOCOMA  */
#line 151 "src/parser/parser.y"
                                    { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1992 "src/parser/parser.tab.c"
    break;

  case 18: /* sentencia: instruccion_break TOKEN_PUNTOCOMA  */
#line 152 "src/parser/parser.y"
                                        {(yyval.nodo) = (yyvsp[-1].nodo); }
#line 1998 "src/parser/parser.tab.c"
    break;

  case 19: /* sentencia: instruccion_continue TOKEN_PUNTOCOMA  */
#line 153 "src/parser/parser.y"
                                           {(yyval.nodo) = (yyvsp[-1].nodo); }
#line 2004 "src/parser/parser.tab.c"
    break;

  case 20: /* sentencia: error TOKEN_PUNTOCOMA  */
#line 155 "src/parser/parser.y"
                                    { 
        addErrorSintactico("Instrucción inválida", "global", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        yyerrok; 
        (yyval.nodo) = NULL;
    }
#line 2014 "src/parser/parser.tab.c"
    break;

  case 21: /* declaracion: tipo_primitivo TOKEN_IDENTIFICADOR TOKEN_IGUAL expresion  */
#line 164 "src/parser/parser.y"
                                                             {
        (yyval.nodo) = crearNodo(AST_DECLARACION, NULL);
        (yyval.nodo)->valor = strdup((yyvsp[-3].str));
        (yyval.nodo)->linea = (yylsp[-2]).first_line; 
        (yyval.nodo)->columna = (yylsp[-2]).first_column;
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-2].str));
        id->linea = (yylsp[-2]).first_line; // Cambia @3 a @2
        id->columna = (yylsp[-2]).first_column;
        agregarHijo((yyval.nodo), id);
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 2030 "src/parser/parser.tab.c"
    break;

  case 22: /* declaracion: tipo_primitivo TOKEN_IDENTIFICADOR  */
#line 175 "src/parser/parser.y"
                                         {
        (yyval.nodo) = crearNodo(AST_DECLARACION, NULL);
        (yyval.nodo)->valor = strdup((yyvsp[-1].str));
        (yyval.nodo)->linea = (yylsp[0]).first_line; 
        (yyval.nodo)->columna = (yylsp[0]).first_column;
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[0].str));
        id->linea = (yylsp[0]).first_line; // Cambia @3 a @2
        id->columna = (yylsp[0]).first_column;
        NodoAST* def = crearNodo(AST_CADENA, (char*)valorPorDefectoTipo(obtenerTipoDesdeString((yyvsp[-1].str))));
        agregarHijo((yyval.nodo), id);
        agregarHijo((yyval.nodo), def);
    }
#line 2047 "src/parser/parser.tab.c"
    break;

  case 23: /* declaracion_vector: tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_NEW tipo_primitivo TOKEN_CORCHETEIZQ expresion TOKEN_CORCHETEDER  */
#line 190 "src/parser/parser.y"
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
#line 2072 "src/parser/parser.tab.c"
    break;

  case 24: /* declaracion_vector: tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_LLAVEIZQ lista_elementos TOKEN_LLAVEDER  */
#line 210 "src/parser/parser.y"
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
#line 2088 "src/parser/parser.tab.c"
    break;

  case 25: /* declaracion_vector: tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_IDENTIFICADOR TOKEN_PUNTO TOKEN_ADD TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 221 "src/parser/parser.y"
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
#line 2122 "src/parser/parser.tab.c"
    break;

  case 26: /* lista_elementos: lista_elementos TOKEN_COMA expresion  */
#line 253 "src/parser/parser.y"
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
#line 2138 "src/parser/parser.tab.c"
    break;

  case 27: /* lista_elementos: expresion  */
#line 264 "src/parser/parser.y"
                {
        (yyval.nodo) = crearNodo(AST_INTERNO, "Lista Elementos");
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 2147 "src/parser/parser.tab.c"
    break;

  case 28: /* lista_filas: lista_filas TOKEN_COMA TOKEN_LLAVEIZQ lista_elementos TOKEN_LLAVEDER  */
#line 271 "src/parser/parser.y"
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
#line 2163 "src/parser/parser.tab.c"
    break;

  case 29: /* lista_filas: TOKEN_LLAVEIZQ lista_elementos TOKEN_LLAVEDER  */
#line 282 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crearNodo(AST_LISTA_ELEMENTOS, "Lista Filas");
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 2172 "src/parser/parser.tab.c"
    break;

  case 30: /* declaracion_matriz: tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_NEW tipo_primitivo TOKEN_CORCHETEIZQ expresion TOKEN_CORCHETEDER TOKEN_CORCHETEIZQ expresion TOKEN_CORCHETEDER  */
#line 289 "src/parser/parser.y"
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
#line 2201 "src/parser/parser.tab.c"
    break;

  case 31: /* declaracion_matriz: tipo_primitivo TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER TOKEN_IDENTIFICADOR TOKEN_IGUAL TOKEN_LLAVEIZQ lista_filas TOKEN_LLAVEDER  */
#line 313 "src/parser/parser.y"
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
#line 2225 "src/parser/parser.tab.c"
    break;

  case 32: /* declaracion_array_multidimensional: tipo_primitivo TOKEN_IDENTIFICADOR DimensionesCorchetes TOKEN_IGUAL TOKEN_NEW tipo_primitivo Dimensiones  */
#line 335 "src/parser/parser.y"
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
#line 2257 "src/parser/parser.tab.c"
    break;

  case 33: /* declaracion_array_multidimensional: tipo_primitivo TOKEN_IDENTIFICADOR DimensionesCorchetes TOKEN_IGUAL TOKEN_LLAVEIZQ lista_bloques TOKEN_LLAVEDER  */
#line 362 "src/parser/parser.y"
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
#line 2279 "src/parser/parser.tab.c"
    break;

  case 34: /* lista_bloques: lista_bloques TOKEN_COMA lista_elementos_o_bloques  */
#line 382 "src/parser/parser.y"
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
#line 2295 "src/parser/parser.tab.c"
    break;

  case 35: /* lista_bloques: lista_elementos_o_bloques  */
#line 393 "src/parser/parser.y"
                                {
        (yyval.nodo) = crearNodo(AST_INTERNO, "Lista Bloques");
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 2304 "src/parser/parser.tab.c"
    break;

  case 36: /* lista_elementos_o_bloques: TOKEN_LLAVEIZQ lista_elementos TOKEN_LLAVEDER  */
#line 400 "src/parser/parser.y"
                                                  {
        // Caso: lista de elementos
        NodoAST* bloque = crearNodo(AST_INTERNO, "Bloque");
        agregarHijo(bloque, (yyvsp[-1].nodo));
        (yyval.nodo) = bloque;
    }
#line 2315 "src/parser/parser.tab.c"
    break;

  case 37: /* lista_elementos_o_bloques: TOKEN_LLAVEIZQ lista_bloques TOKEN_LLAVEDER  */
#line 406 "src/parser/parser.y"
                                                  {
        // Caso: bloques anidados
        NodoAST* bloque = crearNodo(AST_INTERNO, "Bloque");
        agregarHijo(bloque, (yyvsp[-1].nodo));
        (yyval.nodo) = bloque;
    }
#line 2326 "src/parser/parser.tab.c"
    break;

  case 38: /* DimensionesCorchetes: TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER DimensionesCorchetes  */
#line 415 "src/parser/parser.y"
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
#line 2350 "src/parser/parser.tab.c"
    break;

  case 39: /* DimensionesCorchetes: TOKEN_CORCHETEIZQ TOKEN_CORCHETEDER  */
#line 434 "src/parser/parser.y"
                                          {
        (yyval.nodo) = crearNodo(AST_DIMENSIONES, "[]");
    }
#line 2358 "src/parser/parser.tab.c"
    break;

  case 40: /* Dimensiones: TOKEN_CORCHETEIZQ TOKEN_NUMERO TOKEN_CORCHETEDER  */
#line 440 "src/parser/parser.y"
                                                     {
        (yyval.nodo) = crearNodo(AST_DIMENSIONES, "[]");
        agregarHijo((yyval.nodo), crearNodo(AST_NUMERO, (yyvsp[-1].str)));
    }
#line 2367 "src/parser/parser.tab.c"
    break;

  case 41: /* Dimensiones: Dimensiones TOKEN_CORCHETEIZQ TOKEN_NUMERO TOKEN_CORCHETEDER  */
#line 444 "src/parser/parser.y"
                                                                   {
        agregarHijo((yyvsp[-3].nodo), crearNodo(AST_NUMERO, (yyvsp[-1].str)));
        (yyval.nodo) = (yyvsp[-3].nodo);
    }
#line 2376 "src/parser/parser.tab.c"
    break;

  case 42: /* acceso: TOKEN_IDENTIFICADOR DimensionesAcceso  */
#line 454 "src/parser/parser.y"
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
#line 2393 "src/parser/parser.tab.c"
    break;

  case 43: /* DimensionesAcceso: DimensionesAcceso TOKEN_CORCHETEIZQ expresion TOKEN_CORCHETEDER  */
#line 469 "src/parser/parser.y"
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
#line 2408 "src/parser/parser.tab.c"
    break;

  case 44: /* DimensionesAcceso: TOKEN_CORCHETEIZQ expresion TOKEN_CORCHETEDER  */
#line 479 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crearNodo(AST_DIMENSIONES, "Dimensiones");
        NodoAST* dim = crearNodo(AST_1DIMENSION, "Dimensión");
        agregarHijo(dim, (yyvsp[-1].nodo)); // Agregar la expresión como una dimensión
        agregarHijo((yyval.nodo), dim);
    }
#line 2419 "src/parser/parser.tab.c"
    break;

  case 45: /* tipo_primitivo: TOKEN_DINT  */
#line 489 "src/parser/parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2425 "src/parser/parser.tab.c"
    break;

  case 46: /* tipo_primitivo: TOKEN_DCHAR  */
#line 490 "src/parser/parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2431 "src/parser/parser.tab.c"
    break;

  case 47: /* tipo_primitivo: TOKEN_DOUBLE  */
#line 491 "src/parser/parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2437 "src/parser/parser.tab.c"
    break;

  case 48: /* tipo_primitivo: TOKEN_DFLOAT  */
#line 492 "src/parser/parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2443 "src/parser/parser.tab.c"
    break;

  case 49: /* tipo_primitivo: TOKEN_DSTRING  */
#line 493 "src/parser/parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2449 "src/parser/parser.tab.c"
    break;

  case 50: /* tipo_primitivo: TOKEN_DBOOLEAN  */
#line 494 "src/parser/parser.y"
                     { (yyval.str) = (yyvsp[0].str); }
#line 2455 "src/parser/parser.tab.c"
    break;

  case 51: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_IGUAL expresion  */
#line 499 "src/parser/parser.y"
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
#line 2470 "src/parser/parser.tab.c"
    break;

  case 52: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_MAS_IGUAL expresion  */
#line 509 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "+", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2478 "src/parser/parser.tab.c"
    break;

  case 53: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_MENOS_IGUAL expresion  */
#line 512 "src/parser/parser.y"
                                                      {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "-", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2486 "src/parser/parser.tab.c"
    break;

  case 54: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_POR_IGUAL expresion  */
#line 515 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "*", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2494 "src/parser/parser.tab.c"
    break;

  case 55: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_DIV_IGUAL expresion  */
#line 518 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "/", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2502 "src/parser/parser.tab.c"
    break;

  case 56: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_MOD_IGUAL expresion  */
#line 521 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "%", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2510 "src/parser/parser.tab.c"
    break;

  case 57: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_AND_IGUAL expresion  */
#line 524 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "&", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2518 "src/parser/parser.tab.c"
    break;

  case 58: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_OR_IGUAL expresion  */
#line 527 "src/parser/parser.y"
                                                   {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "|", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2526 "src/parser/parser.tab.c"
    break;

  case 59: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_XOR_IGUAL expresion  */
#line 530 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "^", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2534 "src/parser/parser.tab.c"
    break;

  case 60: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_DESIZQ_IGUAL expresion  */
#line 533 "src/parser/parser.y"
                                                       {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), "<<", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2542 "src/parser/parser.tab.c"
    break;

  case 61: /* asignacion: TOKEN_IDENTIFICADOR TOKEN_DESDER_IGUAL expresion  */
#line 536 "src/parser/parser.y"
                                                       {
        (yyval.nodo) = crear_asignacion_compuesta((yyvsp[-2].str), ">>", (yyvsp[0].nodo), (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2550 "src/parser/parser.tab.c"
    break;

  case 62: /* expresion: expresion_or  */
#line 546 "src/parser/parser.y"
                   { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2556 "src/parser/parser.tab.c"
    break;

  case 63: /* expresion_or: expresion_and  */
#line 550 "src/parser/parser.y"
                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2562 "src/parser/parser.tab.c"
    break;

  case 64: /* expresion_or: expresion_or TOKEN_OR expresion_and  */
#line 551 "src/parser/parser.y"
                                          {
          (yyval.nodo) = crearNodo(AST_OPERACION, "||");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2572 "src/parser/parser.tab.c"
    break;

  case 65: /* expresion_and: expresion_bit_or  */
#line 559 "src/parser/parser.y"
                       { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2578 "src/parser/parser.tab.c"
    break;

  case 66: /* expresion_and: expresion_and TOKEN_AND expresion_bit_or  */
#line 560 "src/parser/parser.y"
                                               {
          (yyval.nodo) = crearNodo(AST_OPERACION, "&&");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2588 "src/parser/parser.tab.c"
    break;

  case 67: /* expresion_bit_or: expresion_bit_xor  */
#line 568 "src/parser/parser.y"
                        { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2594 "src/parser/parser.tab.c"
    break;

  case 68: /* expresion_bit_or: expresion_bit_or TOKEN_BIT_OR expresion_bit_xor  */
#line 569 "src/parser/parser.y"
                                                      {
          (yyval.nodo) = crearNodo(AST_OPERACION, "|");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2604 "src/parser/parser.tab.c"
    break;

  case 69: /* expresion_bit_xor: expresion_bit_and  */
#line 577 "src/parser/parser.y"
                        { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2610 "src/parser/parser.tab.c"
    break;

  case 70: /* expresion_bit_xor: expresion_bit_xor TOKEN_XOR expresion_bit_and  */
#line 578 "src/parser/parser.y"
                                                    {
          (yyval.nodo) = crearNodo(AST_OPERACION, "^");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2620 "src/parser/parser.tab.c"
    break;

  case 71: /* expresion_bit_and: expresion_equality  */
#line 586 "src/parser/parser.y"
                         { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2626 "src/parser/parser.tab.c"
    break;

  case 72: /* expresion_bit_and: expresion_bit_and TOKEN_BIT_AND expresion_equality  */
#line 587 "src/parser/parser.y"
                                                         {
          (yyval.nodo) = crearNodo(AST_OPERACION, "&");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2636 "src/parser/parser.tab.c"
    break;

  case 73: /* expresion_equality: expresion_relacional  */
#line 595 "src/parser/parser.y"
                           { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2642 "src/parser/parser.tab.c"
    break;

  case 74: /* expresion_equality: expresion_equality TOKEN_IGUAL_IGUAL expresion_relacional  */
#line 596 "src/parser/parser.y"
                                                                {
          (yyval.nodo) = crearNodo(AST_OPERACION, "==");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2652 "src/parser/parser.tab.c"
    break;

  case 75: /* expresion_equality: expresion_equality TOKEN_NO_IGUAL expresion_relacional  */
#line 601 "src/parser/parser.y"
                                                             {
          (yyval.nodo) = crearNodo(AST_OPERACION, "!=");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2662 "src/parser/parser.tab.c"
    break;

  case 76: /* expresion_relacional: expresion_shift  */
#line 609 "src/parser/parser.y"
                      { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2668 "src/parser/parser.tab.c"
    break;

  case 77: /* expresion_relacional: expresion_relacional TOKEN_MENOR expresion_shift  */
#line 610 "src/parser/parser.y"
                                                       {
          (yyval.nodo) = crearNodo(AST_OPERACION, "<");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2678 "src/parser/parser.tab.c"
    break;

  case 78: /* expresion_relacional: expresion_relacional TOKEN_MENOR_IGUAL expresion_shift  */
#line 615 "src/parser/parser.y"
                                                             {
          (yyval.nodo) = crearNodo(AST_OPERACION, "<=");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2688 "src/parser/parser.tab.c"
    break;

  case 79: /* expresion_relacional: expresion_relacional TOKEN_MAYOR expresion_shift  */
#line 620 "src/parser/parser.y"
                                                       {
          (yyval.nodo) = crearNodo(AST_OPERACION, ">");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2698 "src/parser/parser.tab.c"
    break;

  case 80: /* expresion_relacional: expresion_relacional TOKEN_MAYOR_IGUAL expresion_shift  */
#line 625 "src/parser/parser.y"
                                                             {
          (yyval.nodo) = crearNodo(AST_OPERACION, ">=");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2708 "src/parser/parser.tab.c"
    break;

  case 81: /* expresion_shift: expresion_aditiva  */
#line 633 "src/parser/parser.y"
                        { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2714 "src/parser/parser.tab.c"
    break;

  case 82: /* expresion_shift: expresion_shift TOKEN_DESIZQ expresion_aditiva  */
#line 634 "src/parser/parser.y"
                                                     {
          (yyval.nodo) = crearNodo(AST_OPERACION, "<<");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2724 "src/parser/parser.tab.c"
    break;

  case 83: /* expresion_shift: expresion_shift TOKEN_DESDER expresion_aditiva  */
#line 639 "src/parser/parser.y"
                                                     {
          (yyval.nodo) = crearNodo(AST_OPERACION, ">>");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2734 "src/parser/parser.tab.c"
    break;

  case 84: /* expresion_aditiva: expresion_multiplicativa  */
#line 647 "src/parser/parser.y"
                               { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2740 "src/parser/parser.tab.c"
    break;

  case 85: /* expresion_aditiva: expresion_aditiva TOKEN_MAS expresion_multiplicativa  */
#line 648 "src/parser/parser.y"
                                                           {
          (yyval.nodo) = crearNodo(AST_OPERACION, "+");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2750 "src/parser/parser.tab.c"
    break;

  case 86: /* expresion_aditiva: expresion_aditiva TOKEN_MENOS expresion_multiplicativa  */
#line 653 "src/parser/parser.y"
                                                             {
          (yyval.nodo) = crearNodo(AST_OPERACION, "-");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2760 "src/parser/parser.tab.c"
    break;

  case 87: /* expresion_multiplicativa: expresion_unaria  */
#line 661 "src/parser/parser.y"
                       { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2766 "src/parser/parser.tab.c"
    break;

  case 88: /* expresion_multiplicativa: expresion_multiplicativa TOKEN_MULTI expresion_unaria  */
#line 662 "src/parser/parser.y"
                                                            {
          (yyval.nodo) = crearNodo(AST_OPERACION, "*");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2776 "src/parser/parser.tab.c"
    break;

  case 89: /* expresion_multiplicativa: expresion_multiplicativa TOKEN_DIV expresion_unaria  */
#line 667 "src/parser/parser.y"
                                                          {
          (yyval.nodo) = crearNodo(AST_OPERACION, "/");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2786 "src/parser/parser.tab.c"
    break;

  case 90: /* expresion_multiplicativa: expresion_multiplicativa TOKEN_MODULO expresion_unaria  */
#line 672 "src/parser/parser.y"
                                                             {
          (yyval.nodo) = crearNodo(AST_OPERACION, "%");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2796 "src/parser/parser.tab.c"
    break;

  case 91: /* expresion_unaria: TOKEN_NOT expresion_unaria  */
#line 680 "src/parser/parser.y"
                                 {
          (yyval.nodo) = crearNodo(AST_OPERACION, "!");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2806 "src/parser/parser.tab.c"
    break;

  case 92: /* expresion_unaria: TOKEN_MENOS expresion_unaria  */
#line 685 "src/parser/parser.y"
                                                {
          (yyval.nodo) = crearNodo(AST_OPERACION, "uminus");
          (yyval.nodo)->linea = (yylsp[-1]).first_line; (yyval.nodo)->columna = (yylsp[-1]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[0].nodo));
      }
#line 2816 "src/parser/parser.tab.c"
    break;

  case 93: /* expresion_unaria: TOKEN_PARIZQ tipo_primitivo TOKEN_PARDER expresion_unaria  */
#line 690 "src/parser/parser.y"
                                                                {
          /* crear un nodo específico para cast; guardamos el tipo en ->valor */
          (yyval.nodo) = crearNodo(AST_CAST, "cast");
          (yyval.nodo)->valor = strdup((yyvsp[-2].str));    
          (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[0].nodo));
          free((yyvsp[-2].str)); 
      }
#line 2829 "src/parser/parser.tab.c"
    break;

  case 94: /* expresion_unaria: postfix  */
#line 698 "src/parser/parser.y"
              { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2835 "src/parser/parser.tab.c"
    break;

  case 95: /* postfix: primary  */
#line 702 "src/parser/parser.y"
              { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2841 "src/parser/parser.tab.c"
    break;

  case 96: /* postfix: postfix TOKEN_INCREMENTO  */
#line 703 "src/parser/parser.y"
                               {
          /* transforma (postfix ++) — el hijo es la expresión previa */
          (yyval.nodo) = crearNodo(AST_OPERACION, "++");
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
      }
#line 2852 "src/parser/parser.tab.c"
    break;

  case 97: /* postfix: postfix TOKEN_DECREMENTO  */
#line 709 "src/parser/parser.y"
                               {
          (yyval.nodo) = crearNodo(AST_OPERACION, "--");
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
          agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
      }
#line 2862 "src/parser/parser.tab.c"
    break;

  case 98: /* primary: TOKEN_NUMERO  */
#line 718 "src/parser/parser.y"
                   {
          (yyval.nodo) = crearNodo(AST_NUMERO, NULL);
          (yyval.nodo)->valor = strdup((yyvsp[0].str));
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
      }
#line 2872 "src/parser/parser.tab.c"
    break;

  case 99: /* primary: TOKEN_DOUBLE_LITERAL  */
#line 723 "src/parser/parser.y"
                           {
          (yyval.nodo) = crearNodo(AST_NUMERO, NULL);
          (yyval.nodo)->valor = strdup((yyvsp[0].str));
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
      }
#line 2882 "src/parser/parser.tab.c"
    break;

  case 100: /* primary: TOKEN_FLOAT_LITERAL  */
#line 728 "src/parser/parser.y"
                          {
          (yyval.nodo) = crearNodo(AST_NUMERO, NULL);
          (yyval.nodo)->valor = strdup((yyvsp[0].str));
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
      }
#line 2892 "src/parser/parser.tab.c"
    break;

  case 101: /* primary: TOKEN_CADENA  */
#line 733 "src/parser/parser.y"
                   {
          (yyval.nodo) = crearNodo(AST_CADENA, NULL);
          (yyval.nodo)->valor = strdup((yyvsp[0].str));
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
      }
#line 2902 "src/parser/parser.tab.c"
    break;

  case 102: /* primary: TOKEN_CARACTER  */
#line 738 "src/parser/parser.y"
                     {
          (yyval.nodo) = crearNodo(AST_CARACTER, NULL);
          (yyval.nodo)->valor = strdup((yyvsp[0].str));
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
      }
#line 2912 "src/parser/parser.tab.c"
    break;

  case 103: /* primary: TOKEN_IDENTIFICADOR  */
#line 743 "src/parser/parser.y"
                          {
          (yyval.nodo) = crearNodo(AST_IDENTIFICADOR, (yyvsp[0].str));
          (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
      }
#line 2921 "src/parser/parser.tab.c"
    break;

  case 104: /* primary: TOKEN_BOOLEANO  */
#line 747 "src/parser/parser.y"
                     {
        (yyval.nodo) = crearNodo(AST_BOOLEAN, (yyvsp[0].str));
        (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
    }
#line 2930 "src/parser/parser.tab.c"
    break;

  case 105: /* primary: TOKEN_PARSEINT TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 751 "src/parser/parser.y"
                                                         {
        (yyval.nodo) = crearNodo(AST_PARSEINT, "Integer.parseInt");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 2940 "src/parser/parser.tab.c"
    break;

  case 106: /* primary: TOKEN_PARSEDOUBLE TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 756 "src/parser/parser.y"
                                                            {
        (yyval.nodo) = crearNodo(AST_PARSEDOUBLE, "Double.parseDouble");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 2950 "src/parser/parser.tab.c"
    break;

  case 107: /* primary: TOKEN_PARSEFLOAT TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 761 "src/parser/parser.y"
                                                           {
        (yyval.nodo) = crearNodo(AST_PARSEFLOAT, "Float.parseFloat");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 2960 "src/parser/parser.tab.c"
    break;

  case 108: /* primary: TOKEN_STRING_VALUEOF TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 766 "src/parser/parser.y"
                                                               {
        (yyval.nodo) = crearNodo(AST_VALUEOF, "String.valueOf");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 2970 "src/parser/parser.tab.c"
    break;

  case 109: /* primary: TOKEN_INDEXOF TOKEN_PARIZQ expresion TOKEN_COMA expresion TOKEN_PARDER  */
#line 771 "src/parser/parser.y"
                                                                             {
        (yyval.nodo) = crearNodo(AST_INDEXOF, "Arrays.indexOf");
        (yyval.nodo)->linea = (yylsp[-5]).first_line; (yyval.nodo)->columna = (yylsp[-5]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-3].nodo));  // El array/vector
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));  // La clave a buscar
    }
#line 2981 "src/parser/parser.tab.c"
    break;

  case 110: /* primary: TOKEN_IDENTIFICADOR TOKEN_PUNTO TOKEN_LENGHT  */
#line 777 "src/parser/parser.y"
                                                   {
        (yyval.nodo) = crearNodo(AST_LENGHT, "Array.length");
        (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-2].str));
        id->linea = (yylsp[-2]).first_line; id->columna = (yylsp[-2]).first_column;
        agregarHijo((yyval.nodo), id);
    }
#line 2993 "src/parser/parser.tab.c"
    break;

  case 111: /* primary: TOKEN_IDENTIFICADOR TOKEN_PUNTO TOKEN_ADD TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 784 "src/parser/parser.y"
                                                                                    {
        (yyval.nodo) = crearNodo(AST_ADD, "Array.add");
        (yyval.nodo)->linea = (yylsp[-5]).first_line; (yyval.nodo)->columna = (yylsp[-5]).first_column;
        NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-5].str));
        id->linea = (yylsp[-5]).first_line; id->columna = (yylsp[-5]).first_column;
        agregarHijo((yyval.nodo), id);
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));  // El elemento a añadir
    }
#line 3006 "src/parser/parser.tab.c"
    break;

  case 112: /* primary: TOKEN_PARSEJOIN TOKEN_PARIZQ expresion TOKEN_COMA lista_expresiones_join TOKEN_PARDER  */
#line 792 "src/parser/parser.y"
                                                                                            {
        (yyval.nodo) = crearNodo(AST_PARSEJOIN, "Strings.join");
        (yyval.nodo)->linea = (yylsp[-5]).first_line; (yyval.nodo)->columna = (yylsp[-5]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-3].nodo));  // El delimitador
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));  // Lista de expresiones a unir
    }
#line 3017 "src/parser/parser.tab.c"
    break;

  case 113: /* primary: TOKEN_PARSEJOIN TOKEN_PARIZQ expresion TOKEN_COMA expresion TOKEN_PARDER  */
#line 798 "src/parser/parser.y"
                                                                               {
        (yyval.nodo) = crearNodo(AST_PARSEJOIN, "Strings.join");
        (yyval.nodo)->linea = (yylsp[-5]).first_line; (yyval.nodo)->columna = (yylsp[-5]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-3].nodo));  // El delimitador
        
        // Para un solo elemento, creamos una lista con ese elemento
        NodoAST* lista = crearNodo(AST_LISTA, "Lista Strings");
        agregarHijo(lista, (yyvsp[-1].nodo));
        agregarHijo((yyval.nodo), lista);
    }
#line 3032 "src/parser/parser.tab.c"
    break;

  case 114: /* primary: acceso  */
#line 808 "src/parser/parser.y"
             {
          (yyval.nodo) = (yyvsp[0].nodo);
      }
#line 3040 "src/parser/parser.tab.c"
    break;

  case 115: /* primary: TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 811 "src/parser/parser.y"
                                          {
          (yyval.nodo) = (yyvsp[-1].nodo);
      }
#line 3048 "src/parser/parser.tab.c"
    break;

  case 116: /* lista_expresiones_join: lista_expresiones_join TOKEN_COMA expresion  */
#line 817 "src/parser/parser.y"
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
#line 3064 "src/parser/parser.tab.c"
    break;

  case 117: /* lista_expresiones_join: expresion  */
#line 828 "src/parser/parser.y"
                {
        (yyval.nodo) = crearNodo(AST_LISTA, "Lista Strings");
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3073 "src/parser/parser.tab.c"
    break;

  case 118: /* instruccion_print: TOKEN_PRINT TOKEN_PARIZQ expresion TOKEN_PARDER  */
#line 836 "src/parser/parser.y"
                                                    {
        (yyval.nodo) = crearNodo(AST_PRINT, "System.out.println");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3083 "src/parser/parser.tab.c"
    break;

  case 119: /* instruccion_print: TOKEN_PRINT TOKEN_PARIZQ TOKEN_CADENA TOKEN_MAS expresion TOKEN_PARDER  */
#line 841 "src/parser/parser.y"
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
#line 3101 "src/parser/parser.tab.c"
    break;

  case 120: /* bloque: TOKEN_LLAVEIZQ lista_sentencias TOKEN_LLAVEDER  */
#line 857 "src/parser/parser.y"
                                                   {
        (yyval.nodo) = crearNodo(AST_BLOQUE, NULL);
        (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3111 "src/parser/parser.tab.c"
    break;

  case 121: /* instruccion_break: TOKEN_BREAK  */
#line 865 "src/parser/parser.y"
                {
        (yyval.nodo) = crearNodo(AST_BREAK, "break");
        (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
    }
#line 3120 "src/parser/parser.tab.c"
    break;

  case 122: /* instruccion_continue: TOKEN_CONTINUE  */
#line 872 "src/parser/parser.y"
                   {
        (yyval.nodo) = crearNodo(AST_CONTINUE, "continue");
        (yyval.nodo)->linea = (yylsp[0]).first_line; (yyval.nodo)->columna = (yylsp[0]).first_column;
    }
#line 3129 "src/parser/parser.tab.c"
    break;

  case 123: /* instruccion_if: TOKEN_IF TOKEN_PARIZQ expresion TOKEN_PARDER bloque  */
#line 879 "src/parser/parser.y"
                                                                       {
        (yyval.nodo) = crearNodo(AST_IF, "if");
        (yyval.nodo)->linea = (yylsp[-4]).first_line; (yyval.nodo)->columna = (yylsp[-4]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));   // condición
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));   // bloque if
    }
#line 3140 "src/parser/parser.tab.c"
    break;

  case 124: /* instruccion_if: TOKEN_IF TOKEN_PARIZQ expresion TOKEN_PARDER bloque TOKEN_ELSE bloque  */
#line 885 "src/parser/parser.y"
                                                                            {
        (yyval.nodo) = crearNodo(AST_IF, "if");
        (yyval.nodo)->linea = (yylsp[-6]).first_line; (yyval.nodo)->columna = (yylsp[-6]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));   // condición
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));   // bloque if
        NodoAST* else_node = crearNodo(AST_ELSE, "else");
        agregarHijo(else_node, (yyvsp[0].nodo));
        agregarHijo((yyval.nodo), else_node);
    }
#line 3154 "src/parser/parser.tab.c"
    break;

  case 125: /* instruccion_if: TOKEN_IF TOKEN_PARIZQ expresion TOKEN_PARDER bloque TOKEN_ELSE instruccion_if  */
#line 894 "src/parser/parser.y"
                                                                                    {
        (yyval.nodo) = crearNodo(AST_IF, "if");
        (yyval.nodo)->linea = (yylsp[-6]).first_line; (yyval.nodo)->columna = (yylsp[-6]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));   // condición
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));   // bloque if
        NodoAST* elseif_node = crearNodo(AST_ELSEIF, "elseif");
        agregarHijo(elseif_node, (yyvsp[0].nodo));
        agregarHijo((yyval.nodo), elseif_node);
    }
#line 3168 "src/parser/parser.tab.c"
    break;

  case 126: /* intruccion_switch: TOKEN_SWITCH TOKEN_PARIZQ expresion TOKEN_PARDER TOKEN_LLAVEIZQ lista_casos TOKEN_LLAVEDER  */
#line 907 "src/parser/parser.y"
                                                                                               {
        (yyval.nodo) = crearNodo(AST_SWITCH, "switch");
        (yyval.nodo)->linea = (yylsp[-6]).first_line; (yyval.nodo)->columna = (yylsp[-6]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 3179 "src/parser/parser.tab.c"
    break;

  case 127: /* lista_casos: lista_casos caso  */
#line 916 "src/parser/parser.y"
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
#line 3195 "src/parser/parser.tab.c"
    break;

  case 128: /* lista_casos: caso  */
#line 927 "src/parser/parser.y"
           {
        (yyval.nodo) = crearNodo(AST_LISTA, "Casos");
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3204 "src/parser/parser.tab.c"
    break;

  case 129: /* caso: TOKEN_CASE expresion TOKEN_DOS_PUNTOS lista_sentencias TOKEN_BREAK TOKEN_PUNTOCOMA  */
#line 934 "src/parser/parser.y"
                                                                                      {
        (yyval.nodo) = crearNodo(AST_CASE, "CASE");
        (yyval.nodo)->linea = (yylsp[-5]).first_line; (yyval.nodo)->columna = (yylsp[-5]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));
        NodoAST* nodoBreak = crearNodo(AST_BREAK, "break");
        nodoBreak->linea = (yylsp[-1]).first_line; nodoBreak->columna = (yylsp[-1]).first_column;
        agregarHijo((yyval.nodo), nodoBreak);
    }
#line 3218 "src/parser/parser.tab.c"
    break;

  case 130: /* caso: TOKEN_DEFAULT TOKEN_DOS_PUNTOS lista_sentencias  */
#line 943 "src/parser/parser.y"
                                                      {
        (yyval.nodo) = crearNodo(AST_DEFAULT, "DEFAULT");
        (yyval.nodo)->linea = (yylsp[-2]).first_line; (yyval.nodo)->columna = (yylsp[-2]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3228 "src/parser/parser.tab.c"
    break;

  case 131: /* instruccion_while: TOKEN_WHILE TOKEN_PARIZQ expresion TOKEN_PARDER bloque  */
#line 951 "src/parser/parser.y"
                                                           {
        (yyval.nodo) = crearNodo(AST_WHILE, "while");
        (yyval.nodo)->linea = (yylsp[-4]).first_line; (yyval.nodo)->columna = (yylsp[-4]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3239 "src/parser/parser.tab.c"
    break;

  case 132: /* instruccion_for: TOKEN_FOR TOKEN_PARIZQ declaracion TOKEN_PUNTOCOMA expresion TOKEN_PUNTOCOMA expresion TOKEN_PARDER bloque  */
#line 960 "src/parser/parser.y"
                                                                                                              {
        (yyval.nodo) = crearNodo(AST_FOR, "FOR");
        (yyval.nodo)->linea = (yylsp[-8]).first_line; (yyval.nodo)->columna = (yylsp[-8]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-6].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3252 "src/parser/parser.tab.c"
    break;

  case 133: /* instruccion_for: TOKEN_FOR TOKEN_PARIZQ asignacion TOKEN_PUNTOCOMA expresion TOKEN_PUNTOCOMA expresion TOKEN_PARDER bloque  */
#line 968 "src/parser/parser.y"
                                                                                                               {
        (yyval.nodo) = crearNodo(AST_FOR, "FOR");
        (yyval.nodo)->linea = (yylsp[-8]).first_line; (yyval.nodo)->columna = (yylsp[-8]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-6].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-2].nodo));
        agregarHijo((yyval.nodo), (yyvsp[0].nodo));
    }
#line 3265 "src/parser/parser.tab.c"
    break;


#line 3269 "src/parser/parser.tab.c"

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

#line 978 "src/parser/parser.y"


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
