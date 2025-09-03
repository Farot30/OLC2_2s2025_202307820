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
#line 9 "src/parser/parser.y"

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

#line 84 "src/parser/parser.tab.c"

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
  YYSYMBOL_TOKEN_DBOOLEAN = 3,             /* TOKEN_DBOOLEAN  */
  YYSYMBOL_TOKEN_BOOLEANO = 4,             /* TOKEN_BOOLEANO  */
  YYSYMBOL_TOKEN_IDENTIFICADOR = 5,        /* TOKEN_IDENTIFICADOR  */
  YYSYMBOL_TOKEN_DINT = 6,                 /* TOKEN_DINT  */
  YYSYMBOL_TOKEN_DFLOAT = 7,               /* TOKEN_DFLOAT  */
  YYSYMBOL_TOKEN_DSTRING = 8,              /* TOKEN_DSTRING  */
  YYSYMBOL_TOKEN_DCHAR = 9,                /* TOKEN_DCHAR  */
  YYSYMBOL_TOKEN_DOUBLE = 10,              /* TOKEN_DOUBLE  */
  YYSYMBOL_TOKEN_IGUAL = 11,               /* TOKEN_IGUAL  */
  YYSYMBOL_TOKEN_DOBLEPUNTO = 12,          /* TOKEN_DOBLEPUNTO  */
  YYSYMBOL_TOKEN_NUMERO = 13,              /* TOKEN_NUMERO  */
  YYSYMBOL_TOKEN_CADENA = 14,              /* TOKEN_CADENA  */
  YYSYMBOL_TOKEN_CARACTER = 15,            /* TOKEN_CARACTER  */
  YYSYMBOL_TOKEN_FLOAT_LITERAL = 16,       /* TOKEN_FLOAT_LITERAL  */
  YYSYMBOL_TOKEN_DOUBLE_LITERAL = 17,      /* TOKEN_DOUBLE_LITERAL  */
  YYSYMBOL_TOKEN_MAS_IGUAL = 18,           /* TOKEN_MAS_IGUAL  */
  YYSYMBOL_TOKEN_MENOS_IGUAL = 19,         /* TOKEN_MENOS_IGUAL  */
  YYSYMBOL_TOKEN_POR_IGUAL = 20,           /* TOKEN_POR_IGUAL  */
  YYSYMBOL_TOKEN_DIV_IGUAL = 21,           /* TOKEN_DIV_IGUAL  */
  YYSYMBOL_TOKEN_MOD_IGUAL = 22,           /* TOKEN_MOD_IGUAL  */
  YYSYMBOL_TOKEN_PRINT = 23,               /* TOKEN_PRINT  */
  YYSYMBOL_TOKEN_PARIZQ = 24,              /* TOKEN_PARIZQ  */
  YYSYMBOL_TOKEN_PARDER = 25,              /* TOKEN_PARDER  */
  YYSYMBOL_TOKEN_BIT_AND = 26,             /* TOKEN_BIT_AND  */
  YYSYMBOL_TOKEN_BIT_OR = 27,              /* TOKEN_BIT_OR  */
  YYSYMBOL_TOKEN_XOR = 28,                 /* TOKEN_XOR  */
  YYSYMBOL_TOKEN_DESIZQ = 29,              /* TOKEN_DESIZQ  */
  YYSYMBOL_TOKEN_DESDER = 30,              /* TOKEN_DESDER  */
  YYSYMBOL_TOKEN_AND_IGUAL = 31,           /* TOKEN_AND_IGUAL  */
  YYSYMBOL_TOKEN_OR_IGUAL = 32,            /* TOKEN_OR_IGUAL  */
  YYSYMBOL_TOKEN_XOR_IGUAL = 33,           /* TOKEN_XOR_IGUAL  */
  YYSYMBOL_TOKEN_DESIZQ_IGUAL = 34,        /* TOKEN_DESIZQ_IGUAL  */
  YYSYMBOL_TOKEN_DESDER_IGUAL = 35,        /* TOKEN_DESDER_IGUAL  */
  YYSYMBOL_TOKEN_STRING_VALUEOF = 36,      /* TOKEN_STRING_VALUEOF  */
  YYSYMBOL_TOKEN_IGUAL_IGUAL = 37,         /* TOKEN_IGUAL_IGUAL  */
  YYSYMBOL_TOKEN_NO_IGUAL = 38,            /* TOKEN_NO_IGUAL  */
  YYSYMBOL_TOKEN_MAYOR_IGUAL = 39,         /* TOKEN_MAYOR_IGUAL  */
  YYSYMBOL_TOKEN_MENOR_IGUAL = 40,         /* TOKEN_MENOR_IGUAL  */
  YYSYMBOL_TOKEN_EQUAL = 41,               /* TOKEN_EQUAL  */
  YYSYMBOL_TOKEN_MAYOR = 42,               /* TOKEN_MAYOR  */
  YYSYMBOL_TOKEN_MENOR = 43,               /* TOKEN_MENOR  */
  YYSYMBOL_TOKEN_AND = 44,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 45,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_NOT = 46,                 /* TOKEN_NOT  */
  YYSYMBOL_47_ = 47,                       /* '+'  */
  YYSYMBOL_48_ = 48,                       /* '-'  */
  YYSYMBOL_49_ = 49,                       /* '*'  */
  YYSYMBOL_50_ = 50,                       /* '/'  */
  YYSYMBOL_51_ = 51,                       /* '%'  */
  YYSYMBOL_NEG = 52,                       /* NEG  */
  YYSYMBOL_CAST_ERROR = 53,                /* CAST_ERROR  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_s = 55,                         /* s  */
  YYSYMBOL_Programa = 56,                  /* Programa  */
  YYSYMBOL_Lista_expresiones = 57,         /* Lista_expresiones  */
  YYSYMBOL_expresion = 58,                 /* expresion  */
  YYSYMBOL_Declaracion = 59,               /* Declaracion  */
  YYSYMBOL_Asignacion = 60,                /* Asignacion  */
  YYSYMBOL_Tipos = 61,                     /* Tipos  */
  YYSYMBOL_expr = 62,                      /* expr  */
  YYSYMBOL_Cast = 63,                      /* Cast  */
  YYSYMBOL_PRINT = 64                      /* PRINT  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   989

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


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
       2,     2,     2,     2,     2,     2,     2,    51,     2,     2,
       2,     2,    49,    47,     2,    48,     2,    50,     2,     2,
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
      45,    46,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    96,    96,   118,   120,   131,   143,   144,   145,   146,
     154,   163,   173,   178,   183,   188,   197,   205,   219,   233,
     247,   261,   275,   289,   303,   317,   331,   345,   350,   355,
     362,   363,   364,   365,   366,   367,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   391,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   415,   422,   427,
     432,   439,   445,   452,   459,   466
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
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_DBOOLEAN",
  "TOKEN_BOOLEANO", "TOKEN_IDENTIFICADOR", "TOKEN_DINT", "TOKEN_DFLOAT",
  "TOKEN_DSTRING", "TOKEN_DCHAR", "TOKEN_DOUBLE", "TOKEN_IGUAL",
  "TOKEN_DOBLEPUNTO", "TOKEN_NUMERO", "TOKEN_CADENA", "TOKEN_CARACTER",
  "TOKEN_FLOAT_LITERAL", "TOKEN_DOUBLE_LITERAL", "TOKEN_MAS_IGUAL",
  "TOKEN_MENOS_IGUAL", "TOKEN_POR_IGUAL", "TOKEN_DIV_IGUAL",
  "TOKEN_MOD_IGUAL", "TOKEN_PRINT", "TOKEN_PARIZQ", "TOKEN_PARDER",
  "TOKEN_BIT_AND", "TOKEN_BIT_OR", "TOKEN_XOR", "TOKEN_DESIZQ",
  "TOKEN_DESDER", "TOKEN_AND_IGUAL", "TOKEN_OR_IGUAL", "TOKEN_XOR_IGUAL",
  "TOKEN_DESIZQ_IGUAL", "TOKEN_DESDER_IGUAL", "TOKEN_STRING_VALUEOF",
  "TOKEN_IGUAL_IGUAL", "TOKEN_NO_IGUAL", "TOKEN_MAYOR_IGUAL",
  "TOKEN_MENOR_IGUAL", "TOKEN_EQUAL", "TOKEN_MAYOR", "TOKEN_MENOR",
  "TOKEN_AND", "TOKEN_OR", "TOKEN_NOT", "'+'", "'-'", "'*'", "'/'", "'%'",
  "NEG", "CAST_ERROR", "$accept", "s", "Programa", "Lista_expresiones",
  "expresion", "Declaracion", "Asignacion", "Tipos", "expr", "Cast",
  "PRINT", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-21)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-4)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     911,    10,   -21,    11,   -21,   -21,   -21,   -21,   -21,    15,
      17,   -21,    78,   -21,   -21,   -21,    18,   -21,     9,   248,
     248,   163,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   -21,   180,   -21,   -21,    25,    23,   248,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   146,     3,   248,   259,
     -21,   293,    28,    65,   327,   361,   395,   429,   463,   497,
     531,   565,   599,   633,    16,    95,   -21,    35,   197,   -21,
     667,    26,    13,   728,   248,   808,   -21,   248,   248,   248,
     248,   248,   248,   248,   248,   248,    29,   248,   248,   248,
     248,   214,   248,   231,   248,   248,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
      37,    38,    24,   -21,   -21,   701,   -21,   248,   -21,   248,
     -21,   755,   915,   931,   946,   274,   274,   -21,   -21,   -21,
     -21,   248,   -21,   -21,   834,   834,   -21,   860,   860,   -21,
     898,   898,   898,   -21,   -21,   -21,   -21,   -21,   898,   898,
     -21,   782,   -21
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    35,     0,    30,    33,    34,    31,    32,     0,
       0,     2,     0,     5,     6,     7,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,     0,     1,     4,     0,     0,     0,    65,
      64,    59,    62,    63,    60,    61,     0,     0,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,    11,
       0,     0,     0,     0,     0,    49,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,    27,    28,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       0,     0,     0,    12,    13,     0,    15,     0,    69,     0,
      53,     0,    54,    55,    56,    57,    58,    41,    42,    45,
      46,     0,    43,    44,    47,    48,    66,    36,    37,    67,
      38,    39,    40,    73,    72,    74,    71,    10,    70,    68,
      51,     0,    52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -21,   -21,   -21,   -21,    40,   -21,   -21,    30,   -20,   -21,
     -21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    10,    11,    12,    13,    14,    15,    16,    49,    50,
      17
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    20,    65,   118,    18,    32,    34,    70,    36,
      38,    19,    21,    37,    67,   145,    73,    74,    75,    22,
      23,    24,    25,    26,    68,    69,   146,    66,   119,    33,
      97,   110,    27,    28,    29,    30,    31,   113,   115,   143,
     144,   117,    35,   131,   121,     0,     0,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    98,   132,   133,   134,
     135,   137,   138,   140,   141,   142,    72,    99,    -3,     1,
       0,     2,     0,     3,     4,     5,     6,     7,     8,     0,
       0,    77,    78,    79,    80,    81,   111,   148,     0,   149,
       0,     9,    82,    83,    84,    85,    86,    87,    88,    89,
      90,   151,    91,    92,    93,    94,    95,     0,     0,     0,
     112,    77,    78,    79,    80,    81,     0,     0,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,    92,    93,    94,    95,    71,     0,     2,
      39,    40,     4,     5,     6,     7,     8,     0,     0,    41,
      42,    43,    44,    45,    52,     0,     0,    39,    40,     0,
      46,     0,     0,     0,     0,     0,    41,    42,    43,    44,
      45,    64,    47,     0,    39,    40,     0,    46,     0,     0,
       0,     0,    48,    41,    42,    43,    44,    45,   114,    47,
       0,    39,    40,     0,    46,     0,     0,     0,     0,    48,
      41,    42,    43,    44,    45,   136,    47,     0,    39,    40,
       0,    46,     0,     0,     0,     0,    48,    41,    42,    43,
      44,    45,   139,    47,     0,    39,    40,     0,    46,     0,
       0,     0,     0,    48,    41,    42,    43,    44,    45,     0,
      47,     0,    39,    40,     0,    46,     0,     0,     0,     0,
      48,    41,    42,    43,    44,    45,     0,    47,     0,     0,
       0,    76,    46,     0,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,    47,    77,    78,    79,    80,    81,
       0,     0,     0,     0,    48,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    96,    91,    92,    93,    94,
      95,    82,    83,    84,    85,    86,    87,    88,     0,    77,
      78,    79,    80,    81,     0,     0,     0,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,   100,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    78,    79,    80,    81,     0,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,   101,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,     0,     0,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,   102,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    80,    81,     0,     0,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,   103,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    78,    79,    80,    81,
       0,     0,     0,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,   104,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,    79,    80,    81,     0,     0,     0,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,   105,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    78,    79,    80,    81,     0,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,   106,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,     0,     0,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,   107,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    80,    81,     0,     0,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,   108,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    78,    79,    80,    81,
       0,     0,     0,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,   109,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,    79,    80,    81,     0,     0,     0,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,   116,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    78,    79,    80,    81,     0,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,   147,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,     0,     0,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,    91,    92,
      93,    94,    95,   120,    77,    78,    79,    80,    81,     0,
       0,     0,     0,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,    91,    92,    93,    94,    95,
     150,    77,    78,    79,    80,    81,     0,     0,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,    92,    93,    94,    95,   152,    77,    78,
      79,    80,    81,     0,     0,     0,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     0,    91,
      92,    93,    94,    95,    77,    78,    79,    80,    81,     0,
       0,     0,     0,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,    91,    92,    93,    94,    95,
      77,    78,    79,    80,    81,     0,     0,     0,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,    91,    92,    93,    94,    95,    77,    78,    79,    80,
      81,     0,     0,     0,     0,     0,     0,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,     0,     0,    93,
      94,    95,     1,     0,     2,     0,     3,     4,     5,     6,
       7,     8,     0,     0,    77,    78,    79,    80,    81,     0,
       0,     0,     0,     0,     9,    82,    83,    84,    85,    86,
      87,    88,    78,    79,    80,    81,     0,     0,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    79,
      80,    81,     0,     0,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    80,    81,     0,     0,     0,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    88
};

static const yytype_int16 yycheck[] =
{
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     1,    33,     1,     5,     1,     0,    38,     1,
      11,    11,    11,     5,     1,     1,    46,    24,    48,    18,
      19,    20,    21,    22,    11,    12,    12,    12,    25,    24,
      12,    25,    31,    32,    33,    34,    35,    12,    68,    12,
      12,    25,    12,    24,    74,    -1,    -1,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     1,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    46,    12,     0,     1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      -1,    26,    27,    28,    29,    30,     1,   117,    -1,   119,
      -1,    23,    37,    38,    39,    40,    41,    42,    43,    44,
      45,   131,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    47,    48,    49,    50,    51,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    13,
      14,    15,    16,    17,     1,    -1,    -1,     4,     5,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,
      17,     1,    36,    -1,     4,     5,    -1,    24,    -1,    -1,
      -1,    -1,    46,    13,    14,    15,    16,    17,     1,    36,
      -1,     4,     5,    -1,    24,    -1,    -1,    -1,    -1,    46,
      13,    14,    15,    16,    17,     1,    36,    -1,     4,     5,
      -1,    24,    -1,    -1,    -1,    -1,    46,    13,    14,    15,
      16,    17,     1,    36,    -1,     4,     5,    -1,    24,    -1,
      -1,    -1,    -1,    46,    13,    14,    15,    16,    17,    -1,
      36,    -1,     4,     5,    -1,    24,    -1,    -1,    -1,    -1,
      46,    13,    14,    15,    16,    17,    -1,    36,    -1,    -1,
      -1,    12,    24,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    46,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    12,    47,    48,    49,    50,
      51,    37,    38,    39,    40,    41,    42,    43,    -1,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    12,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    12,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    12,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    12,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    12,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    12,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    12,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    12,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    12,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    12,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    12,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    12,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    47,    48,
      49,    50,    51,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    50,    51,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    47,    48,    49,    50,    51,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    47,
      48,    49,    50,    51,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    50,    51,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    26,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,     1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    -1,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    23,    37,    38,    39,    40,    41,
      42,    43,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    42,    43
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     5,     6,     7,     8,     9,    10,    23,
      55,    56,    57,    58,    59,    60,    61,    64,     5,    11,
       1,    11,    18,    19,    20,    21,    22,    31,    32,    33,
      34,    35,     1,    24,     0,    58,     1,     5,    11,     4,
       5,    13,    14,    15,    16,    17,    24,    36,    46,    62,
      63,    62,     1,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,     1,    62,    12,     1,    11,    12,
      62,     1,    61,    62,    24,    62,    12,    26,    27,    28,
      29,    30,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    47,    48,    49,    50,    51,    12,    12,     1,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      25,     1,    25,    12,     1,    62,    12,    25,     1,    25,
      25,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    24,    62,    62,    62,    62,     1,    62,    62,     1,
      62,    62,    62,    12,    12,     1,    12,    12,    62,    62,
      25,    62,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    57,    57,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    63,    63,
      63,    64,    64,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     4,
       5,     3,     4,     4,     3,     5,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     4,     5,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     4,     3,
       4,     5,     5,     5,     5,     2
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
  case 2: /* s: Programa  */
#line 96 "src/parser/parser.y"
            {
    // 2. Mostrar AST para debugging
    printf("\n=== ESTRUCTURA DEL AST ===\n");
    imprimirAST((yyvsp[0].nodo), 0);
    
    
    // 4. EJECUTAR/INTERPRETAR el programa (ANTES de liberar)
    interpretarPrograma((yyvsp[0].nodo));
    
    printf("ejecutando exportarAST\n");
    exportarAST((yyvsp[0].nodo), "ast.dot", "ast.png");

    //printf("verificando la semantica\n");
    //verificarSemantica($1);

    // 5. Liberar memoria AL FINAL
    printf("\n=== LIBERANDO MEMORIA ===\n");
    liberarAST((yyvsp[0].nodo));
    
    printf("[DEBUG] Procesamiento completado.\n");
}
#line 1811 "src/parser/parser.tab.c"
    break;

  case 3: /* Programa: Lista_expresiones  */
#line 118 "src/parser/parser.y"
                            { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1817 "src/parser/parser.tab.c"
    break;

  case 4: /* Lista_expresiones: Lista_expresiones expresion  */
#line 120 "src/parser/parser.y"
                                               {
        if ((yyvsp[-1].nodo)->tipo != AST_LISTA) {
            NodoAST* lista = crearNodo(AST_LISTA, "Arbol AST");
            agregarHijo(lista, (yyvsp[-1].nodo));
            agregarHijo(lista, (yyvsp[0].nodo));
            (yyval.nodo) = lista;
        } else {
            agregarHijo((yyvsp[-1].nodo), (yyvsp[0].nodo));
            (yyval.nodo) = (yyvsp[-1].nodo);
        }
    }
#line 1833 "src/parser/parser.tab.c"
    break;

  case 5: /* Lista_expresiones: expresion  */
#line 131 "src/parser/parser.y"
                {
        (yyval.nodo) = (yyvsp[0].nodo);
    }
#line 1841 "src/parser/parser.tab.c"
    break;

  case 9: /* expresion: error TOKEN_IGUAL expr TOKEN_DOBLEPUNTO  */
#line 146 "src/parser/parser.y"
                                              {
         addErrorSintactico("Asignación sin declaración de tipo", "variable", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
         (yyval.nodo) = crearNodo(AST_ERROR, "ASIGNACION_SIN_DECLARACION");
         yyerrok;
      }
#line 1851 "src/parser/parser.tab.c"
    break;

  case 10: /* Declaracion: Tipos TOKEN_IDENTIFICADOR TOKEN_IGUAL expr TOKEN_DOBLEPUNTO  */
#line 154 "src/parser/parser.y"
                                                                  {
         (yyval.nodo) = crearNodo(AST_DECLARACION, NULL);
         (yyval.nodo)->valor = strdup((yyvsp[-4].str));
         (yyval.nodo)->linea=(yylsp[-3]).first_line; (yyval.nodo)->columna=(yylsp[-3]).first_column;
         NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
         id->linea=(yylsp[-3]).first_line; id->columna=(yylsp[-3]).first_column;
         agregarHijo((yyval.nodo), id);
         agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
      }
#line 1865 "src/parser/parser.tab.c"
    break;

  case 11: /* Declaracion: Tipos TOKEN_IDENTIFICADOR TOKEN_DOBLEPUNTO  */
#line 163 "src/parser/parser.y"
                                                 {
         (yyval.nodo) = crearNodo(AST_DECLARACION, NULL);
         (yyval.nodo)->valor = strdup((yyvsp[-2].str));
         (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column;
         NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-1].str));
         id->linea=(yylsp[-1]).first_line; id->columna=(yylsp[-1]).first_column;
         NodoAST* def = crearNodo(AST_CADENA, (char*)valorPorDefectoTipo(obtenerTipoDesdeString((yyvsp[-2].str))));
         agregarHijo((yyval.nodo), id);
         agregarHijo((yyval.nodo), def);
      }
#line 1880 "src/parser/parser.tab.c"
    break;

  case 12: /* Declaracion: Tipos TOKEN_IDENTIFICADOR error TOKEN_DOBLEPUNTO  */
#line 173 "src/parser/parser.y"
                                                       {
        addErrorSintactico("Expresión de inicialización inválida", "global", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.nodo) = crearNodo(AST_DECLARACION, "ERROR");
        yyerrok;
      }
#line 1890 "src/parser/parser.tab.c"
    break;

  case 13: /* Declaracion: Tipos TOKEN_IDENTIFICADOR TOKEN_IGUAL error  */
#line 178 "src/parser/parser.y"
                                                  {
        addErrorSintactico("Falta punto y coma al final de la declaración", "global", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.nodo) = crearNodo(AST_DECLARACION, "ERROR");
        yyerrok;
      }
#line 1900 "src/parser/parser.tab.c"
    break;

  case 14: /* Declaracion: Tipos error TOKEN_DOBLEPUNTO  */
#line 183 "src/parser/parser.y"
                                   {
        addErrorSintactico("Identificador inválido en declaración", "global", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.nodo) = crearNodo(AST_DECLARACION, "ERROR");
        yyerrok;
      }
#line 1910 "src/parser/parser.tab.c"
    break;

  case 15: /* Declaracion: error TOKEN_IDENTIFICADOR TOKEN_IGUAL expr TOKEN_DOBLEPUNTO  */
#line 188 "src/parser/parser.y"
                                                                  {
        addErrorSintactico("Tipo de dato inválido en declaración", "global", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        (yyval.nodo) = crearNodo(AST_DECLARACION, "ERROR");
        yyerrok;
      }
#line 1920 "src/parser/parser.tab.c"
    break;

  case 16: /* Asignacion: TOKEN_IDENTIFICADOR TOKEN_IGUAL expr TOKEN_DOBLEPUNTO  */
#line 197 "src/parser/parser.y"
                                                            {
          (yyval.nodo) = crearNodo(AST_ASIGNACION, "");
          (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
          NodoAST* id = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          id->linea = (yylsp[-3]).first_line; id->columna = (yylsp[-3]).first_column;
          agregarHijo((yyval.nodo), id);
          agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
      }
#line 1933 "src/parser/parser.tab.c"
    break;

  case 17: /* Asignacion: TOKEN_IDENTIFICADOR TOKEN_MAS_IGUAL expr TOKEN_DOBLEPUNTO  */
#line 205 "src/parser/parser.y"
                                                                {
          (yyval.nodo) = crearNodo(AST_ASIGNACION, "");
          (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idRef->linea = (yylsp[-3]).first_line; idRef->columna = (yylsp[-3]).first_column;
          NodoAST* op = crearNodo(AST_OPERACION, "+");
          op->linea = (yylsp[-2]).first_line; op->columna = (yylsp[-2]).first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idOp->linea = (yylsp[-3]).first_line; idOp->columna = (yylsp[-3]).first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, (yyvsp[-1].nodo));
          agregarHijo((yyval.nodo), idRef);
          agregarHijo((yyval.nodo), op);
      }
#line 1952 "src/parser/parser.tab.c"
    break;

  case 18: /* Asignacion: TOKEN_IDENTIFICADOR TOKEN_MENOS_IGUAL expr TOKEN_DOBLEPUNTO  */
#line 219 "src/parser/parser.y"
                                                                  {
          (yyval.nodo) = crearNodo(AST_ASIGNACION, "");
          (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idRef->linea = (yylsp[-3]).first_line; idRef->columna = (yylsp[-3]).first_column;
          NodoAST* op = crearNodo(AST_OPERACION, "-");
          op->linea = (yylsp[-2]).first_line; op->columna = (yylsp[-2]).first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idOp->linea = (yylsp[-3]).first_line; idOp->columna = (yylsp[-3]).first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, (yyvsp[-1].nodo));
          agregarHijo((yyval.nodo), idRef);
          agregarHijo((yyval.nodo), op);
      }
#line 1971 "src/parser/parser.tab.c"
    break;

  case 19: /* Asignacion: TOKEN_IDENTIFICADOR TOKEN_POR_IGUAL expr TOKEN_DOBLEPUNTO  */
#line 233 "src/parser/parser.y"
                                                                {
          (yyval.nodo) = crearNodo(AST_ASIGNACION, "");
          (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idRef->linea = (yylsp[-3]).first_line; idRef->columna = (yylsp[-3]).first_column;
          NodoAST* op = crearNodo(AST_OPERACION, "*");
          op->linea = (yylsp[-2]).first_line; op->columna = (yylsp[-2]).first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idOp->linea = (yylsp[-3]).first_line; idOp->columna = (yylsp[-3]).first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, (yyvsp[-1].nodo));
          agregarHijo((yyval.nodo), idRef);
          agregarHijo((yyval.nodo), op);
      }
#line 1990 "src/parser/parser.tab.c"
    break;

  case 20: /* Asignacion: TOKEN_IDENTIFICADOR TOKEN_DIV_IGUAL expr TOKEN_DOBLEPUNTO  */
#line 247 "src/parser/parser.y"
                                                                {
          (yyval.nodo) = crearNodo(AST_ASIGNACION, "");
          (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idRef->linea = (yylsp[-3]).first_line; idRef->columna = (yylsp[-3]).first_column;
          NodoAST* op = crearNodo(AST_OPERACION, "/");
          op->linea = (yylsp[-2]).first_line; op->columna = (yylsp[-2]).first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idOp->linea = (yylsp[-3]).first_line; idOp->columna = (yylsp[-3]).first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, (yyvsp[-1].nodo));
          agregarHijo((yyval.nodo), idRef);
          agregarHijo((yyval.nodo), op);
      }
#line 2009 "src/parser/parser.tab.c"
    break;

  case 21: /* Asignacion: TOKEN_IDENTIFICADOR TOKEN_MOD_IGUAL expr TOKEN_DOBLEPUNTO  */
#line 261 "src/parser/parser.y"
                                                                {
          (yyval.nodo) = crearNodo(AST_ASIGNACION, "");
          (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idRef->linea = (yylsp[-3]).first_line; idRef->columna = (yylsp[-3]).first_column;
          NodoAST* op = crearNodo(AST_OPERACION, "%");
          op->linea = (yylsp[-2]).first_line; op->columna = (yylsp[-2]).first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idOp->linea = (yylsp[-3]).first_line; idOp->columna = (yylsp[-3]).first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, (yyvsp[-1].nodo));
          agregarHijo((yyval.nodo), idRef);
          agregarHijo((yyval.nodo), op);
      }
#line 2028 "src/parser/parser.tab.c"
    break;

  case 22: /* Asignacion: TOKEN_IDENTIFICADOR TOKEN_AND_IGUAL expr TOKEN_DOBLEPUNTO  */
#line 275 "src/parser/parser.y"
                                                                {
          (yyval.nodo) = crearNodo(AST_ASIGNACION, "");
          (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idRef->linea = (yylsp[-3]).first_line; idRef->columna = (yylsp[-3]).first_column;
          NodoAST* op = crearNodo(AST_OPERACION, "&");
          op->linea = (yylsp[-2]).first_line; op->columna = (yylsp[-2]).first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idOp->linea = (yylsp[-3]).first_line; idOp->columna = (yylsp[-3]).first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, (yyvsp[-1].nodo));
          agregarHijo((yyval.nodo), idRef);
          agregarHijo((yyval.nodo), op);
      }
#line 2047 "src/parser/parser.tab.c"
    break;

  case 23: /* Asignacion: TOKEN_IDENTIFICADOR TOKEN_OR_IGUAL expr TOKEN_DOBLEPUNTO  */
#line 289 "src/parser/parser.y"
                                                               {
          (yyval.nodo) = crearNodo(AST_ASIGNACION, "");
          (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idRef->linea = (yylsp[-3]).first_line; idRef->columna = (yylsp[-3]).first_column;
          NodoAST* op = crearNodo(AST_OPERACION, "|");
          op->linea = (yylsp[-2]).first_line; op->columna = (yylsp[-2]).first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idOp->linea = (yylsp[-3]).first_line; idOp->columna = (yylsp[-3]).first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, (yyvsp[-1].nodo));
          agregarHijo((yyval.nodo), idRef);
          agregarHijo((yyval.nodo), op);
      }
#line 2066 "src/parser/parser.tab.c"
    break;

  case 24: /* Asignacion: TOKEN_IDENTIFICADOR TOKEN_XOR_IGUAL expr TOKEN_DOBLEPUNTO  */
#line 303 "src/parser/parser.y"
                                                                {
          (yyval.nodo) = crearNodo(AST_ASIGNACION, "");
          (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idRef->linea = (yylsp[-3]).first_line; idRef->columna = (yylsp[-3]).first_column;
          NodoAST* op = crearNodo(AST_OPERACION, "^");
          op->linea = (yylsp[-2]).first_line; op->columna = (yylsp[-2]).first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idOp->linea = (yylsp[-3]).first_line; idOp->columna = (yylsp[-3]).first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, (yyvsp[-1].nodo));
          agregarHijo((yyval.nodo), idRef);
          agregarHijo((yyval.nodo), op);
      }
#line 2085 "src/parser/parser.tab.c"
    break;

  case 25: /* Asignacion: TOKEN_IDENTIFICADOR TOKEN_DESIZQ_IGUAL expr TOKEN_DOBLEPUNTO  */
#line 317 "src/parser/parser.y"
                                                                   {
          (yyval.nodo) = crearNodo(AST_ASIGNACION, "");
          (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idRef->linea = (yylsp[-3]).first_line; idRef->columna = (yylsp[-3]).first_column;
          NodoAST* op = crearNodo(AST_OPERACION, "<<");
          op->linea = (yylsp[-2]).first_line; op->columna = (yylsp[-2]).first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idOp->linea = (yylsp[-3]).first_line; idOp->columna = (yylsp[-3]).first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, (yyvsp[-1].nodo));
          agregarHijo((yyval.nodo), idRef);
          agregarHijo((yyval.nodo), op);
      }
#line 2104 "src/parser/parser.tab.c"
    break;

  case 26: /* Asignacion: TOKEN_IDENTIFICADOR TOKEN_DESDER_IGUAL expr TOKEN_DOBLEPUNTO  */
#line 331 "src/parser/parser.y"
                                                                   {
          (yyval.nodo) = crearNodo(AST_ASIGNACION, "");
          (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
          NodoAST* idRef = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idRef->linea = (yylsp[-3]).first_line; idRef->columna = (yylsp[-3]).first_column;
          NodoAST* op = crearNodo(AST_OPERACION, ">>");
          op->linea = (yylsp[-2]).first_line; op->columna = (yylsp[-2]).first_column;
          NodoAST* idOp = crearNodo(AST_IDENTIFICADOR, (yyvsp[-3].str));
          idOp->linea = (yylsp[-3]).first_line; idOp->columna = (yylsp[-3]).first_column;
          agregarHijo(op, idOp);
          agregarHijo(op, (yyvsp[-1].nodo));
          agregarHijo((yyval.nodo), idRef);
          agregarHijo((yyval.nodo), op);
      }
#line 2123 "src/parser/parser.tab.c"
    break;

  case 27: /* Asignacion: TOKEN_IDENTIFICADOR TOKEN_IGUAL error TOKEN_DOBLEPUNTO  */
#line 345 "src/parser/parser.y"
                                                             {
         addErrorSintactico("Expresión de asignación inválida", (yyvsp[-3].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
         (yyval.nodo) = crearNodo(AST_ASIGNACION, "ERROR");
         yyerrok;
      }
#line 2133 "src/parser/parser.tab.c"
    break;

  case 28: /* Asignacion: TOKEN_IDENTIFICADOR TOKEN_IGUAL expr error  */
#line 350 "src/parser/parser.y"
                                                 {
         addErrorSintactico("Falta punto y coma al final de la asignación", (yyvsp[-3].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
         (yyval.nodo) = crearNodo(AST_ASIGNACION, "ERROR");
         yyerrok;
      }
#line 2143 "src/parser/parser.tab.c"
    break;

  case 29: /* Asignacion: TOKEN_IDENTIFICADOR error expr TOKEN_DOBLEPUNTO  */
#line 355 "src/parser/parser.y"
                                                      {
         addErrorSintactico("Operador de asignación inválido", (yyvsp[-3].str), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
         (yyval.nodo) = crearNodo(AST_ASIGNACION, "ERROR");
         yyerrok;
      }
#line 2153 "src/parser/parser.tab.c"
    break;

  case 30: /* Tipos: TOKEN_DINT  */
#line 362 "src/parser/parser.y"
                       { (yyval.str) = (yyvsp[0].str); }
#line 2159 "src/parser/parser.tab.c"
    break;

  case 31: /* Tipos: TOKEN_DCHAR  */
#line 363 "src/parser/parser.y"
                      { (yyval.str) = (yyvsp[0].str); }
#line 2165 "src/parser/parser.tab.c"
    break;

  case 32: /* Tipos: TOKEN_DOUBLE  */
#line 364 "src/parser/parser.y"
                      { (yyval.str) = (yyvsp[0].str); }
#line 2171 "src/parser/parser.tab.c"
    break;

  case 33: /* Tipos: TOKEN_DFLOAT  */
#line 365 "src/parser/parser.y"
                      { (yyval.str) = (yyvsp[0].str); }
#line 2177 "src/parser/parser.tab.c"
    break;

  case 34: /* Tipos: TOKEN_DSTRING  */
#line 366 "src/parser/parser.y"
                      { (yyval.str) = (yyvsp[0].str); }
#line 2183 "src/parser/parser.tab.c"
    break;

  case 35: /* Tipos: TOKEN_DBOOLEAN  */
#line 367 "src/parser/parser.y"
                      { (yyval.str) = (yyvsp[0].str); }
#line 2189 "src/parser/parser.tab.c"
    break;

  case 36: /* expr: expr '+' expr  */
#line 371 "src/parser/parser.y"
                    { (yyval.nodo) = crearNodo(AST_OPERACION, "+"); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2195 "src/parser/parser.tab.c"
    break;

  case 37: /* expr: expr '-' expr  */
#line 372 "src/parser/parser.y"
                    { (yyval.nodo) = crearNodo(AST_OPERACION, "-"); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2201 "src/parser/parser.tab.c"
    break;

  case 38: /* expr: expr '*' expr  */
#line 373 "src/parser/parser.y"
                    { (yyval.nodo) = crearNodo(AST_OPERACION, "*"); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2207 "src/parser/parser.tab.c"
    break;

  case 39: /* expr: expr '/' expr  */
#line 374 "src/parser/parser.y"
                    { (yyval.nodo) = crearNodo(AST_OPERACION, "/"); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2213 "src/parser/parser.tab.c"
    break;

  case 40: /* expr: expr '%' expr  */
#line 375 "src/parser/parser.y"
                    { (yyval.nodo) = crearNodo(AST_OPERACION, "%"); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2219 "src/parser/parser.tab.c"
    break;

  case 41: /* expr: expr TOKEN_IGUAL_IGUAL expr  */
#line 376 "src/parser/parser.y"
                                 { (yyval.nodo) = crearNodo(AST_OPERACION, "=="); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2225 "src/parser/parser.tab.c"
    break;

  case 42: /* expr: expr TOKEN_NO_IGUAL expr  */
#line 377 "src/parser/parser.y"
                              { (yyval.nodo) = crearNodo(AST_OPERACION, "!="); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2231 "src/parser/parser.tab.c"
    break;

  case 43: /* expr: expr TOKEN_MAYOR expr  */
#line 378 "src/parser/parser.y"
                           { (yyval.nodo) = crearNodo(AST_OPERACION, ">"); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2237 "src/parser/parser.tab.c"
    break;

  case 44: /* expr: expr TOKEN_MENOR expr  */
#line 379 "src/parser/parser.y"
                           { (yyval.nodo) = crearNodo(AST_OPERACION, "<"); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2243 "src/parser/parser.tab.c"
    break;

  case 45: /* expr: expr TOKEN_MAYOR_IGUAL expr  */
#line 380 "src/parser/parser.y"
                                 { (yyval.nodo) = crearNodo(AST_OPERACION, ">="); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2249 "src/parser/parser.tab.c"
    break;

  case 46: /* expr: expr TOKEN_MENOR_IGUAL expr  */
#line 381 "src/parser/parser.y"
                                 { (yyval.nodo) = crearNodo(AST_OPERACION, "<="); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2255 "src/parser/parser.tab.c"
    break;

  case 47: /* expr: expr TOKEN_AND expr  */
#line 382 "src/parser/parser.y"
                          { (yyval.nodo) = crearNodo(AST_OPERACION, "&&"); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2261 "src/parser/parser.tab.c"
    break;

  case 48: /* expr: expr TOKEN_OR expr  */
#line 383 "src/parser/parser.y"
                          { (yyval.nodo) = crearNodo(AST_OPERACION, "||"); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2267 "src/parser/parser.tab.c"
    break;

  case 49: /* expr: TOKEN_NOT expr  */
#line 384 "src/parser/parser.y"
                                      { (yyval.nodo) = crearNodo(AST_OPERACION, "!"); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2273 "src/parser/parser.tab.c"
    break;

  case 51: /* expr: TOKEN_STRING_VALUEOF TOKEN_PARIZQ expr TOKEN_PARDER  */
#line 386 "src/parser/parser.y"
                                                          {
        (yyval.nodo) = crearNodo(AST_STRING, "String.valueOf");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 2283 "src/parser/parser.tab.c"
    break;

  case 52: /* expr: expr TOKEN_EQUAL TOKEN_PARIZQ expr TOKEN_PARDER  */
#line 391 "src/parser/parser.y"
                                                      {
        (yyval.nodo) = crearNodo(AST_EQUAL, ".equals");
        (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
        agregarHijo((yyval.nodo), (yyvsp[-4].nodo));
        agregarHijo((yyval.nodo), (yyvsp[-1].nodo));
    }
#line 2294 "src/parser/parser.tab.c"
    break;

  case 53: /* expr: TOKEN_PARIZQ expr TOKEN_PARDER  */
#line 397 "src/parser/parser.y"
                                     { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2300 "src/parser/parser.tab.c"
    break;

  case 54: /* expr: expr TOKEN_BIT_AND expr  */
#line 398 "src/parser/parser.y"
                              { (yyval.nodo) = crearNodo(AST_OPERACION, "&"); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2306 "src/parser/parser.tab.c"
    break;

  case 55: /* expr: expr TOKEN_BIT_OR expr  */
#line 399 "src/parser/parser.y"
                              { (yyval.nodo) = crearNodo(AST_OPERACION, "|"); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2312 "src/parser/parser.tab.c"
    break;

  case 56: /* expr: expr TOKEN_XOR expr  */
#line 400 "src/parser/parser.y"
                          { (yyval.nodo) = crearNodo(AST_OPERACION, "^"); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2318 "src/parser/parser.tab.c"
    break;

  case 57: /* expr: expr TOKEN_DESIZQ expr  */
#line 401 "src/parser/parser.y"
                             { (yyval.nodo) = crearNodo(AST_OPERACION, "<<"); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2324 "src/parser/parser.tab.c"
    break;

  case 58: /* expr: expr TOKEN_DESDER expr  */
#line 402 "src/parser/parser.y"
                             { (yyval.nodo) = crearNodo(AST_OPERACION, ">>"); (yyval.nodo)->linea=(yylsp[-1]).first_line; (yyval.nodo)->columna=(yylsp[-1]).first_column; agregarHijo((yyval.nodo), (yyvsp[-2].nodo)); agregarHijo((yyval.nodo), (yyvsp[0].nodo)); }
#line 2330 "src/parser/parser.tab.c"
    break;

  case 59: /* expr: TOKEN_NUMERO  */
#line 403 "src/parser/parser.y"
                           { (yyval.nodo) = crearNodo(AST_NUMERO, (yyvsp[0].str)); (yyval.nodo)->linea=(yylsp[0]).first_line; (yyval.nodo)->columna=(yylsp[0]).first_column; }
#line 2336 "src/parser/parser.tab.c"
    break;

  case 60: /* expr: TOKEN_FLOAT_LITERAL  */
#line 404 "src/parser/parser.y"
                           { (yyval.nodo) = crearNodo(AST_NUMERO, (yyvsp[0].str)); (yyval.nodo)->linea=(yylsp[0]).first_line; (yyval.nodo)->columna=(yylsp[0]).first_column; }
#line 2342 "src/parser/parser.tab.c"
    break;

  case 61: /* expr: TOKEN_DOUBLE_LITERAL  */
#line 405 "src/parser/parser.y"
                           { (yyval.nodo) = crearNodo(AST_NUMERO, (yyvsp[0].str)); (yyval.nodo)->linea=(yylsp[0]).first_line; (yyval.nodo)->columna=(yylsp[0]).first_column; }
#line 2348 "src/parser/parser.tab.c"
    break;

  case 62: /* expr: TOKEN_CADENA  */
#line 406 "src/parser/parser.y"
                           { (yyval.nodo) = crearNodo(AST_CADENA, (yyvsp[0].str)); (yyval.nodo)->linea=(yylsp[0]).first_line; (yyval.nodo)->columna=(yylsp[0]).first_column; }
#line 2354 "src/parser/parser.tab.c"
    break;

  case 63: /* expr: TOKEN_CARACTER  */
#line 407 "src/parser/parser.y"
                           { (yyval.nodo) = crearNodo(AST_CARACTER, (yyvsp[0].str)); (yyval.nodo)->linea=(yylsp[0]).first_line; (yyval.nodo)->columna=(yylsp[0]).first_column; }
#line 2360 "src/parser/parser.tab.c"
    break;

  case 64: /* expr: TOKEN_IDENTIFICADOR  */
#line 408 "src/parser/parser.y"
                           { (yyval.nodo) = crearNodo(AST_IDENTIFICADOR, (yyvsp[0].str)); (yyval.nodo)->linea=(yylsp[0]).first_line; (yyval.nodo)->columna=(yylsp[0]).first_column; }
#line 2366 "src/parser/parser.tab.c"
    break;

  case 65: /* expr: TOKEN_BOOLEANO  */
#line 409 "src/parser/parser.y"
                           { (yyval.nodo) = crearNodo(AST_BOOLEAN, (yyvsp[0].str)); (yyval.nodo)->linea=(yylsp[0]).first_line; (yyval.nodo)->columna=(yylsp[0]).first_column; }
#line 2372 "src/parser/parser.tab.c"
    break;

  case 66: /* expr: expr '+' error  */
#line 410 "src/parser/parser.y"
                     {
         addErrorSintactico("Operando derecho faltante en suma", "+", (yylsp[0]).first_line, (yylsp[0]).first_column);
         (yyval.nodo) = (yyvsp[-2].nodo);
         yyerrok;
      }
#line 2382 "src/parser/parser.tab.c"
    break;

  case 67: /* expr: expr '*' error  */
#line 415 "src/parser/parser.y"
                     {
         addErrorSintactico("Operando derecho faltante en multiplicación", "*", (yylsp[0]).first_line, (yylsp[0]).first_column);
         (yyval.nodo) = (yyvsp[-2].nodo);
         yyerrok;
      }
#line 2392 "src/parser/parser.tab.c"
    break;

  case 68: /* Cast: TOKEN_PARIZQ Tipos TOKEN_PARDER expr  */
#line 422 "src/parser/parser.y"
                                           {
    (yyval.nodo) = crearNodo(AST_CAST, (yyvsp[-2].str));
    (yyval.nodo)->linea = (yylsp[-3]).first_line; (yyval.nodo)->columna = (yylsp[-3]).first_column;
    agregarHijo((yyval.nodo), (yyvsp[0].nodo));
  }
#line 2402 "src/parser/parser.tab.c"
    break;

  case 69: /* Cast: TOKEN_PARIZQ Tipos error  */
#line 427 "src/parser/parser.y"
                                              {
      addErrorSintactico("Falta paréntesis de cierre y expresión en cast", (yyvsp[-1].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
      (yyval.nodo) = crearNodo(AST_CAST, "ERROR");
      yyerrok;
    }
#line 2412 "src/parser/parser.tab.c"
    break;

  case 70: /* Cast: TOKEN_PARIZQ error TOKEN_PARDER expr  */
#line 432 "src/parser/parser.y"
                                         {
      addErrorSintactico("Tipo inválido en cast", "cast", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
      (yyval.nodo) = crearNodo(AST_CAST, "ERROR");
      yyerrok;
    }
#line 2422 "src/parser/parser.tab.c"
    break;

  case 71: /* PRINT: TOKEN_PRINT TOKEN_PARIZQ expr TOKEN_PARDER TOKEN_DOBLEPUNTO  */
#line 439 "src/parser/parser.y"
                                                                   {
    (yyval.nodo) = crearNodo(AST_PRINT, "System.out.println");
    (yyval.nodo)->linea = (yylsp[-4]).first_line;
    (yyval.nodo)->columna = (yylsp[-4]).first_column;
    agregarHijo((yyval.nodo), (yyvsp[-2].nodo));
  }
#line 2433 "src/parser/parser.tab.c"
    break;

  case 72: /* PRINT: TOKEN_PRINT TOKEN_PARIZQ expr error TOKEN_DOBLEPUNTO  */
#line 445 "src/parser/parser.y"
                                                           {
         addErrorSintactico("Falta paréntesis de cierre en System.out.println",
                            "System.out.println",
                            (yylsp[-1]).first_line, (yylsp[-1]).first_column);
         (yyval.nodo) = crearNodo(AST_PRINT, "ERROR");
         yyerrok;
      }
#line 2445 "src/parser/parser.tab.c"
    break;

  case 73: /* PRINT: TOKEN_PRINT TOKEN_PARIZQ error TOKEN_PARDER TOKEN_DOBLEPUNTO  */
#line 452 "src/parser/parser.y"
                                                                   {
         addErrorSintactico("Expresión inválida en System.out.println", 
                            "System.out.println",
                            (yylsp[-2]).first_line, (yylsp[-2]).first_column);
         (yyval.nodo) = crearNodo(AST_PRINT, "ERROR");
         yyerrok;
      }
#line 2457 "src/parser/parser.tab.c"
    break;

  case 74: /* PRINT: TOKEN_PRINT TOKEN_PARIZQ expr TOKEN_PARDER error  */
#line 459 "src/parser/parser.y"
                                                       {
         addErrorSintactico("Falta punto y coma al final de System.out.println",
                            "System.out.println", 
                            (yylsp[0]).first_line, (yylsp[0]).first_column);
         (yyval.nodo) = crearNodo(AST_PRINT, "ERROR");
         yyerrok;
      }
#line 2469 "src/parser/parser.tab.c"
    break;

  case 75: /* PRINT: TOKEN_PRINT error  */
#line 466 "src/parser/parser.y"
                        {
         addErrorSintactico("Sintaxis incorrecta en System.out.println",
                            "System.out.println",
                            (yylsp[0]).first_line, (yylsp[0]).first_column);
         (yyval.nodo) = crearNodo(AST_PRINT, "ERROR");
         yyerrok;
      }
#line 2481 "src/parser/parser.tab.c"
    break;


#line 2485 "src/parser/parser.tab.c"

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

#line 475 "src/parser/parser.y"


void yyerror(const char *s) {
    extern YYLTYPE yylloc;
    int linea = (yylloc.first_line > 0) ? yylloc.first_line : yylineno;
    int columna = (yylloc.first_column > 0) ? yylloc.first_column : yycolumn;
    fprintf(stderr, "%s en línea %d, columna %d\n", s, linea, columna);
}
