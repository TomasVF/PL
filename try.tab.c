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
#line 1 "try.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *archivo;
int nTabs;
extern int yylex();
extern int yyparse();
extern int line_num;
void yyerror(const char *s);

void addTab(){
    nTabs++;
}

#line 88 "try.tab.c"

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

#include "try.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ADD = 3,                        /* ADD  */
  YYSYMBOL_SUB = 4,                        /* SUB  */
  YYSYMBOL_MUL = 5,                        /* MUL  */
  YYSYMBOL_DIV = 6,                        /* DIV  */
  YYSYMBOL_ASSIGN = 7,                     /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 8,                  /* SEMICOLON  */
  YYSYMBOL_LPAREN = 9,                     /* LPAREN  */
  YYSYMBOL_RPAREN = 10,                    /* RPAREN  */
  YYSYMBOL_INT = 11,                       /* INT  */
  YYSYMBOL_FLOAT = 12,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 13,                    /* DOUBLE  */
  YYSYMBOL_CHAR = 14,                      /* CHAR  */
  YYSYMBOL_VOID = 15,                      /* VOID  */
  YYSYMBOL_COLON = 16,                     /* COLON  */
  YYSYMBOL_LBRACE = 17,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 18,                    /* RBRACE  */
  YYSYMBOL_RETURN = 19,                    /* RETURN  */
  YYSYMBOL_IF = 20,                        /* IF  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_WHILE = 22,                     /* WHILE  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_EQ = 24,                        /* EQ  */
  YYSYMBOL_NE = 25,                        /* NE  */
  YYSYMBOL_GE = 26,                        /* GE  */
  YYSYMBOL_GT = 27,                        /* GT  */
  YYSYMBOL_LE = 28,                        /* LE  */
  YYSYMBOL_LT = 29,                        /* LT  */
  YYSYMBOL_IDENTIFIER = 30,                /* IDENTIFIER  */
  YYSYMBOL_INTEGER = 31,                   /* INTEGER  */
  YYSYMBOL_CHARVALUE = 32,                 /* CHARVALUE  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_program = 34,                   /* program  */
  YYSYMBOL_statements = 35,                /* statements  */
  YYSYMBOL_error_handling = 36,            /* error_handling  */
  YYSYMBOL_lbrace = 37,                    /* lbrace  */
  YYSYMBOL_rbrace = 38,                    /* rbrace  */
  YYSYMBOL_funcs = 39,                     /* funcs  */
  YYSYMBOL_statementsf = 40,               /* statementsf  */
  YYSYMBOL_declaration_list = 41,          /* declaration_list  */
  YYSYMBOL_lastdec = 42,                   /* lastdec  */
  YYSYMBOL_declaration = 43,               /* declaration  */
  YYSYMBOL_thingThatCanHappen = 44,        /* thingThatCanHappen  */
  YYSYMBOL_funcCallList = 45,              /* funcCallList  */
  YYSYMBOL_statement = 46,                 /* statement  */
  YYSYMBOL_elseOp = 47,                    /* elseOp  */
  YYSYMBOL_felements = 48,                 /* felements  */
  YYSYMBOL_actualizacion = 49,             /* actualizacion  */
  YYSYMBOL_boolElement = 50,               /* boolElement  */
  YYSYMBOL_bcomparator = 51,               /* bcomparator  */
  YYSYMBOL_expression = 52,                /* expression  */
  YYSYMBOL_term = 53,                      /* term  */
  YYSYMBOL_factor = 54,                    /* factor  */
  YYSYMBOL_etype = 55                      /* etype  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    47,    47,    53,    54,    55,    69,    83,    84,    88,
      90,    92,    94,    96,    98,   100,   102,   104,   106,   108,
     110,   112,   116,   119,   123,   148,   166,   184,   204,   226,
     227,   241,   246,   262,   278,   279,   293,   309,   310,   311,
     328,   343,   360,   377,   400,   416,   431,   445,   526,   540,
     554,   569,   583,   586,   589,   592,   595,   598,   601,   606,
     607,   622,   639,   640,   655,   673,   674,   675,   680,   683,
     686,   689
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ADD", "SUB", "MUL",
  "DIV", "ASSIGN", "SEMICOLON", "LPAREN", "RPAREN", "INT", "FLOAT",
  "DOUBLE", "CHAR", "VOID", "COLON", "LBRACE", "RBRACE", "RETURN", "IF",
  "ELSE", "WHILE", "FOR", "EQ", "NE", "GE", "GT", "LE", "LT", "IDENTIFIER",
  "INTEGER", "CHARVALUE", "$accept", "program", "statements",
  "error_handling", "lbrace", "rbrace", "funcs", "statementsf",
  "declaration_list", "lastdec", "declaration", "thingThatCanHappen",
  "funcCallList", "statement", "elseOp", "felements", "actualizacion",
  "boolElement", "bcomparator", "expression", "term", "factor", "etype", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-88)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      85,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,    26,    -3,    28,    35,   -88,
     -88,   -88,   -88,   -88,   -88,    60,    17,   -88,   -88,    85,
      85,   -88,   -88,   -88,    29,    26,   -88,   -88,     5,    44,
     -88,    32,    32,   105,    26,    -4,   -88,   -88,   -88,   113,
      62,    26,    26,   -88,    26,    26,    49,    77,    83,    32,
      40,     8,    67,   -88,    96,    18,    16,   105,   -88,    44,
      44,   -88,   -88,    26,   104,   104,   121,   123,   -88,    -4,
     124,   125,    76,   126,   -88,   105,   101,    18,   -88,    41,
      41,   107,   -88,   -88,   -88,   -88,   104,   -88,   118,    60,
     117,    41,    41,   117,    78,   128,    41,   -88,   -88,   119,
     -88,   -88,   -88,   136,   137,    26,   104,   117,   104,   -88,
     -88,   -88,    18,    41,   -88,    41,   117,   117,   -88,   -88
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    16,    13,    20,    19,    21,    14,    15,    68,    69,
      70,    71,    10,    17,    18,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,     9,     0,     2,     7,     4,
       3,    34,     8,    12,    11,     0,    65,    66,     0,    59,
      62,     0,     0,     0,     0,     0,     1,     6,     5,     0,
       0,     0,     0,    46,     0,     0,    52,     0,     0,     0,
       0,     0,    65,    38,     0,    37,     0,    31,    67,    60,
      61,    63,    64,     0,     0,     0,     0,     0,    35,     0,
       0,     0,     0,     0,    29,    31,     0,    51,    22,     0,
       0,     0,    39,    36,    41,    40,     0,    30,    32,     0,
       0,    25,    26,     0,     0,     0,     0,    33,    23,    44,
      28,    27,    45,     0,     0,     0,     0,     0,     0,    43,
      48,    49,    50,     0,    24,     0,     0,     0,    47,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -88,    94,   -88,   -73,   -85,   -88,   -87,    57,   -88,
     -88,     4,    64,   102,   -88,    10,   -88,   -35,    88,   -15,
      74,    73,     1
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    26,    27,    28,    89,   109,    29,   100,    83,    84,
      85,   101,    64,    31,   119,   102,   105,    57,    33,    65,
      39,    40,    60
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      38,    34,    90,   103,    30,    35,    41,    58,    51,    52,
      32,    51,    52,    53,   110,   111,    78,    46,   112,   117,
      50,    51,    52,   106,    76,    35,    62,    37,    63,    61,
      34,    34,   124,    30,    30,    35,   126,    42,   127,    32,
      32,   128,   129,   123,    43,   125,    36,    37,    81,    54,
      55,    82,     8,     9,    10,    11,    36,    37,    87,    49,
      15,    16,    56,    17,    18,    51,    52,    44,    86,    45,
      77,    99,    68,    19,    20,    21,    22,    23,    24,    51,
      52,   113,   114,    79,    95,   115,    86,    74,     1,     2,
       3,     4,     5,    75,     6,     7,     8,     9,    10,    11,
     122,    12,    13,    14,    15,    16,    80,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     8,     9,    10,    11,
      66,    88,    67,    47,    48,    69,    70,    71,    72,    91,
      66,    98,    93,    94,   107,   108,    96,   104,   116,   120,
     118,   121,    97,    92,    73,    59
};

static const yytype_int8 yycheck[] =
{
      15,     0,    75,    90,     0,     9,     9,    42,     3,     4,
       0,     3,     4,     8,   101,   102,     8,     0,   103,   106,
      35,     3,     4,    96,    59,     9,    30,    31,    32,    44,
      29,    30,   117,    29,    30,     9,   123,     9,   125,    29,
      30,   126,   127,   116,     9,   118,    30,    31,    32,     5,
       6,    66,    11,    12,    13,    14,    30,    31,    73,    30,
      19,    20,    30,    22,    23,     3,     4,     7,    67,     9,
      30,    30,    10,    24,    25,    26,    27,    28,    29,     3,
       4,     3,     4,    16,     8,     7,    85,    10,     3,     4,
       5,     6,     7,    10,     9,    10,    11,    12,    13,    14,
     115,    16,    17,    18,    19,    20,    10,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    11,    12,    13,    14,
       7,    17,     9,    29,    30,    51,    52,    54,    55,     8,
       7,    30,     8,     8,    16,    18,    10,    30,    10,     3,
      21,     4,    85,    79,    56,    43
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    11,    12,
      13,    14,    16,    17,    18,    19,    20,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    34,    35,    36,    39,
      44,    46,    48,    51,    55,     9,    30,    31,    52,    53,
      54,     9,     9,     9,     7,     9,     0,    35,    35,    30,
      52,     3,     4,     8,     5,     6,    30,    50,    50,    46,
      55,    52,    30,    32,    45,    52,     7,     9,    10,    53,
      53,    54,    54,    51,    10,    10,    50,    30,     8,    16,
      10,    32,    52,    41,    42,    43,    55,    52,    17,    37,
      37,     8,    45,     8,     8,     8,    10,    41,    30,    30,
      40,    44,    48,    40,    30,    49,    37,    16,    18,    38,
      40,    40,    38,     3,     4,     7,    10,    40,    21,    47,
       3,     4,    52,    37,    38,    37,    40,    40,    38,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    35,    35,    35,    35,    35,    35,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    37,    38,    39,    40,    40,    40,    40,    41,
      41,    41,    42,    43,    44,    44,    44,    45,    45,    45,
      46,    46,    47,    48,    48,    48,    48,    48,    49,    49,
      49,    50,    50,    51,    51,    51,    51,    51,    51,    52,
      52,    52,    53,    53,    53,    54,    54,    54,    55,    55,
      55,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     8,     1,     1,     2,     2,     1,
       2,     0,     2,     3,     1,     4,     5,     1,     1,     3,
       5,     5,     4,     8,     7,     7,     3,    10,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     3,     3,     1,     1,     3,     1,     1,
       1,     1
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: statements  */
#line 47 "try.y"
                     {
            printf("%s", (yyvsp[0].string));
            fprintf(archivo, "%s", (yyvsp[0].string));
        }
#line 1218 "try.tab.c"
    break;

  case 5: /* statements: thingThatCanHappen statements  */
#line 55 "try.y"
                                          {
                char str[40];
                strcpy(str, (yyvsp[-1].string));
                strcat(str, "\n");
                strcat(str, (yyvsp[0].string));
                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                (yyval.string) = copiedString;
           }
#line 1237 "try.tab.c"
    break;

  case 6: /* statements: funcs statements  */
#line 69 "try.y"
                              {
                char str[40];
                strcpy(str, (yyvsp[-1].string));
                strcat(str, "\n");
                strcat(str, (yyvsp[0].string));
                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                (yyval.string) = copiedString;
           }
#line 1256 "try.tab.c"
    break;

  case 7: /* statements: error_handling  */
#line 83 "try.y"
                           {exit(2);}
#line 1262 "try.tab.c"
    break;

  case 8: /* statements: felements  */
#line 84 "try.y"
                      {printf("Error de compilación en la línea: %d", line_num);
                        exit(2);}
#line 1269 "try.tab.c"
    break;

  case 9: /* error_handling: IDENTIFIER  */
#line 88 "try.y"
                           {printf("Error de compilación en la línea: %d", line_num);
                        exit(2);}
#line 1276 "try.tab.c"
    break;

  case 10: /* error_handling: COLON  */
#line 90 "try.y"
                   {printf("Error de compilación en la línea: %d", line_num);
                        exit(2);}
#line 1283 "try.tab.c"
    break;

  case 11: /* error_handling: etype  */
#line 92 "try.y"
                    {printf("Error de compilación en la línea: %d", line_num);
                        exit(2);}
#line 1290 "try.tab.c"
    break;

  case 12: /* error_handling: bcomparator  */
#line 94 "try.y"
                          {printf("Error de compilación en la línea: %d", line_num);
                        exit(2);}
#line 1297 "try.tab.c"
    break;

  case 13: /* error_handling: SUB  */
#line 96 "try.y"
                 {printf("Error de compilación en la línea: %d", line_num);
                        exit(2);}
#line 1304 "try.tab.c"
    break;

  case 14: /* error_handling: LPAREN  */
#line 98 "try.y"
                    {printf("Error de compilación en la línea: %d", line_num);
                exit(2);}
#line 1311 "try.tab.c"
    break;

  case 15: /* error_handling: RPAREN  */
#line 100 "try.y"
                    {printf("Error de compilación en la línea: %d", line_num);
                exit(2);}
#line 1318 "try.tab.c"
    break;

  case 16: /* error_handling: ADD  */
#line 102 "try.y"
                 {printf("Error de compilación en la línea: %d", line_num);
                exit(2);}
#line 1325 "try.tab.c"
    break;

  case 17: /* error_handling: LBRACE  */
#line 104 "try.y"
                    {printf("Error de compilación en la línea: %d", line_num);
                exit(2);}
#line 1332 "try.tab.c"
    break;

  case 18: /* error_handling: RBRACE  */
#line 106 "try.y"
                    {printf("Error de compilación en la línea: %d", line_num);
                exit(2);}
#line 1339 "try.tab.c"
    break;

  case 19: /* error_handling: DIV  */
#line 108 "try.y"
                 {printf("Error de compilación en la línea: %d", line_num);
                exit(2);}
#line 1346 "try.tab.c"
    break;

  case 20: /* error_handling: MUL  */
#line 110 "try.y"
                 {printf("Error de compilación en la línea: %d", line_num);
                exit(2);}
#line 1353 "try.tab.c"
    break;

  case 21: /* error_handling: ASSIGN  */
#line 112 "try.y"
                    {printf("Error de compilación en la línea: %d", line_num);
                exit(2);}
#line 1360 "try.tab.c"
    break;

  case 22: /* lbrace: LBRACE  */
#line 116 "try.y"
               {nTabs++;}
#line 1366 "try.tab.c"
    break;

  case 23: /* rbrace: RBRACE  */
#line 119 "try.y"
               {nTabs--;}
#line 1372 "try.tab.c"
    break;

  case 24: /* funcs: etype IDENTIFIER LPAREN declaration_list RPAREN lbrace statementsf rbrace  */
#line 123 "try.y"
                                                                                  {



            //QUITAR TIPO, PONER DEF, : FINALES
            char str[2048];

            if(strcmp((yyvsp[-6].string), "main")==0){
                sprintf(str, "def %s(%s):\n%s\n%s", (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-1].string), "\nif __name__ == '__main__':\n\tmain()\n");
            }else{
                sprintf(str, "def %s(%s):\n%s\n", (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-1].string));
            }

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);



            (yyval.string) = copiedString;
        }
#line 1401 "try.tab.c"
    break;

  case 25: /* statementsf: thingThatCanHappen  */
#line 148 "try.y"
                                {
                    char str[40];
                    if(nTabs > 0){
                        strcpy(str, "\t");
                        for(int i = 1; i<nTabs;i++){
                            strcat(str, "\t");
                        }
                    }
                    strcat(str, (yyvsp[0].string));
                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    (yyval.string) = copiedString;
                }
#line 1424 "try.tab.c"
    break;

  case 26: /* statementsf: felements  */
#line 166 "try.y"
                       {
                    char str[40];
                    if(nTabs > 0){
                        strcpy(str, "\t");
                        for(int i = 1; i<nTabs;i++){
                            strcat(str, "\t");
                        }
                    }
                    strcat(str, (yyvsp[0].string));
                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    (yyval.string) = copiedString;
                }
#line 1447 "try.tab.c"
    break;

  case 27: /* statementsf: felements statementsf  */
#line 184 "try.y"
                                   {
                    char str[40];
                    if(nTabs > 0){
                        strcpy(str, "\t");
                        for(int i = 1; i<nTabs;i++){
                            strcat(str, "\t");
                        }
                    }
                    strcat(str, (yyvsp[-1].string));
                    strcat(str, "\n");
                    strcat(str, (yyvsp[0].string));
                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    (yyval.string) = copiedString;
            }
#line 1472 "try.tab.c"
    break;

  case 28: /* statementsf: thingThatCanHappen statementsf  */
#line 204 "try.y"
                                             {
                    char str[40];
                    if(nTabs > 0){
                        strcpy(str, "\t");
                        for(int i = 1; i<nTabs;i++){
                            strcat(str, "\t");
                        }
                    }
                    strcat(str, (yyvsp[-1].string));
                    strcat(str, "\n");
                    strcat(str, (yyvsp[0].string));
                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    (yyval.string) = copiedString;
                }
#line 1497 "try.tab.c"
    break;

  case 30: /* declaration_list: declaration declaration_list  */
#line 227 "try.y"
                                               {
                    char str[40];
                    strcpy(str, (yyvsp[-1].string));
                    strcat(str, ", ");
                    strcat(str, (yyvsp[0].string));
                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    (yyval.string) = copiedString;
                 }
#line 1516 "try.tab.c"
    break;

  case 31: /* declaration_list: %empty  */
#line 241 "try.y"
                  {
                    (yyval.string) = "";
                 }
#line 1524 "try.tab.c"
    break;

  case 32: /* lastdec: etype IDENTIFIER  */
#line 246 "try.y"
                          {
            //QUITAR TIPO
            char str[40];
            strcpy(str, (yyvsp[0].string));

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            (yyval.string) = copiedString;
}
#line 1543 "try.tab.c"
    break;

  case 33: /* declaration: etype IDENTIFIER COLON  */
#line 262 "try.y"
                                    {
                //QUITAR TIPO
                char str[40];
                strcpy(str, (yyvsp[-1].string));
                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                (yyval.string) = copiedString;
                }
#line 1561 "try.tab.c"
    break;

  case 35: /* thingThatCanHappen: IDENTIFIER ASSIGN expression SEMICOLON  */
#line 279 "try.y"
                                                            {
                        char str[40];

                        sprintf(str, "%s = %s", (yyvsp[-3].string), (yyvsp[-1].string));
                        
                        size_t originalStringLength = strlen(str);

                        char *copiedString;
                        copiedString = (char *)malloc(originalStringLength+1);

                        strcpy(copiedString, str);

                        (yyval.string) = copiedString;
                    }
#line 1580 "try.tab.c"
    break;

  case 36: /* thingThatCanHappen: IDENTIFIER LPAREN funcCallList RPAREN SEMICOLON  */
#line 293 "try.y"
                                                                     {
                        char str[40];

                        sprintf(str, "%s(%s)", (yyvsp[-4].string), (yyvsp[-2].string));
                        
                        size_t originalStringLength = strlen(str);

                        char *copiedString;
                        copiedString = (char *)malloc(originalStringLength+1);

                        strcpy(copiedString, str);

                        (yyval.string) = copiedString;
                    }
#line 1599 "try.tab.c"
    break;

  case 39: /* funcCallList: IDENTIFIER COLON funcCallList  */
#line 311 "try.y"
                                             {
                    char str[40];

                    sprintf(str, "%s, %s", (yyvsp[-2].string), (yyvsp[0].string));
                    
                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    (yyval.string) = copiedString;
                }
#line 1618 "try.tab.c"
    break;

  case 40: /* statement: etype IDENTIFIER ASSIGN expression SEMICOLON  */
#line 328 "try.y"
                                                         {
                //QUITAR TIPO
                char str[40];
                strcpy(str, (yyvsp[-3].string));
                strcat(str, " = ");
                strcat(str, (yyvsp[-1].string));
                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                (yyval.string) = copiedString;
            }
#line 1638 "try.tab.c"
    break;

  case 41: /* statement: etype IDENTIFIER ASSIGN CHARVALUE SEMICOLON  */
#line 343 "try.y"
                                                          {
                //QUITAR TIPO
                char str[40];
                strcpy(str, (yyvsp[-3].string));
                strcat(str, " = ");
                strcat(str, (yyvsp[-1].string));
                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                (yyval.string) = copiedString;
            }
#line 1658 "try.tab.c"
    break;

  case 42: /* elseOp: ELSE lbrace statementsf rbrace  */
#line 360 "try.y"
                                       {
            //TODO
            char str[1024];

            sprintf(str, "else:\n%s\n", (yyvsp[-1].string));

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            (yyval.string) = copiedString;
        }
#line 1678 "try.tab.c"
    break;

  case 43: /* felements: IF LPAREN boolElement RPAREN lbrace statementsf rbrace elseOp  */
#line 377 "try.y"
                                                                         {
            //TODO
            char str[2048];

            sprintf(str, "if(%s):\n%s\n", (yyvsp[-5].string), (yyvsp[-2].string));

            if(nTabs > 0){
                for(int i = 0; i<nTabs;i++){
                    strcat(str, "\t");
                }
                strcat(str, (yyvsp[0].string));
            }

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            (yyval.string) = copiedString;
        }
#line 1705 "try.tab.c"
    break;

  case 44: /* felements: IF LPAREN boolElement RPAREN lbrace statementsf rbrace  */
#line 400 "try.y"
                                                               {
            //TODO
            char str[2048];

            sprintf(str, "if(%s):\n%s\n", (yyvsp[-4].string), (yyvsp[-1].string));

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            (yyval.string) = copiedString;
        }
#line 1725 "try.tab.c"
    break;

  case 45: /* felements: WHILE LPAREN boolElement RPAREN lbrace statementsf rbrace  */
#line 416 "try.y"
                                                                   {
            //TODO
            char str[2048];

            sprintf(str, "while(%s):\n%s\n", (yyvsp[-4].string), (yyvsp[-1].string));

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            (yyval.string) = copiedString;
        }
#line 1745 "try.tab.c"
    break;

  case 46: /* felements: RETURN expression SEMICOLON  */
#line 431 "try.y"
                                     {
            char str[40];

            sprintf(str, "return %s", (yyvsp[-1].string));

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            (yyval.string) = copiedString;
        }
#line 1764 "try.tab.c"
    break;

  case 47: /* felements: FOR LPAREN statement boolElement SEMICOLON actualizacion RPAREN lbrace statementsf rbrace  */
#line 445 "try.y"
                                                                                                   {

            char delimitador[] = "= ";
            char *nombreVariable = strtok((yyvsp[-7].string), delimitador);
            char *valorInicial = strtok(NULL, delimitador);


            //TODO
            char str[1024];

            int aumento = 0;
            if(strstr((yyvsp[-4].string), "++") != NULL){
                aumento = 1;
            }else if(strstr((yyvsp[-4].string), "--") != NULL){
                aumento = 0;
            }


            //vamos a hacer como si siempre es i++ o i--
            if (strstr((yyvsp[-6].string), "<=") != NULL) {
                char delimitador2[] = "<=";
                char *nombreVariable2 = strtok((yyvsp[-6].string), delimitador2);
                char *valorCondicion = strtok(NULL, delimitador2);
                if(atoi(valorInicial)==0 && aumento){
                    sprintf(str, "for %s in range(%d):\n%s\n", nombreVariable, (atoi(valorCondicion)+1), (yyvsp[-1].string));
                }else if(aumento){
                    sprintf(str, "for %s in range(%s, %d):\n%s\n", nombreVariable, valorInicial, (atoi(valorCondicion)+1), (yyvsp[-1].string));
                }else{
                    yyerror("No tiene sentido usar un for disminuyendo con <=");
                    exit(2);
                }
            } else if (strstr((yyvsp[-6].string), ">=") != NULL) {
                char delimitador2[] = "<=";
                char *nombreVariable2 = strtok((yyvsp[-6].string), delimitador2);
                char *valorCondicion = strtok(NULL, delimitador2);
                if(aumento){
                    yyerror("No tiene sentido usar un for aumentando con >=");
                    exit(2);
                }
                sprintf(str, "for %s in range(%s, %d, -1):\n%s\n", nombreVariable, valorInicial, (atoi(valorCondicion)-1), (yyvsp[-1].string));
            } else if (strstr((yyvsp[-6].string), "<") != NULL) {
                char delimitador2[] = "<";
                char *nombreVariable2 = strtok((yyvsp[-6].string), delimitador2);
                char *valorCondicion = strtok(NULL, delimitador2);
                if(atoi(valorInicial)==0 && aumento){
                    sprintf(str, "for %s in range(%s):\n%s\n", nombreVariable, valorCondicion, (yyvsp[-1].string));
                }else if(aumento){
                    sprintf(str, "for %s in range(%s, %s):\n%s\n", nombreVariable, valorInicial, valorCondicion, (yyvsp[-1].string));
                }else{
                    yyerror("No tiene sentido usar un for disminuyendo con <");
                    exit(2);
                }
            } else if (strstr((yyvsp[-6].string), ">") != NULL) {
                char delimitador2[] = "<=";
                char *nombreVariable2 = strtok((yyvsp[-6].string), delimitador2);
                char *valorCondicion = strtok(NULL, delimitador2);
                if(aumento){
                    yyerror("No tiene sentido usar un for aumentando con >");
                    exit(2);
                }
                sprintf(str, "for %s in range(%s, %s, -1):\n%s\n", nombreVariable, valorInicial, valorCondicion, (yyvsp[-1].string));
            }if (strstr((yyvsp[-6].string), "==") != NULL) {
                yyerror("No tiene sentido usar un for con ==, usa un while");
                exit(2);
            }if (strstr((yyvsp[-6].string), "!=") != NULL) {
                yyerror("No tiene sentido usar un for con !=, usa un while");
                exit(2);
            }

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            (yyval.string) = copiedString;
        }
#line 1847 "try.tab.c"
    break;

  case 48: /* actualizacion: IDENTIFIER ADD ADD  */
#line 526 "try.y"
                                  {
                    char str[40];

                    sprintf(str, "%s++", (yyvsp[-2].string));

                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    (yyval.string) = copiedString;
                }
#line 1866 "try.tab.c"
    break;

  case 49: /* actualizacion: IDENTIFIER SUB SUB  */
#line 540 "try.y"
                                    {
                    char str[40];

                    sprintf(str, "%s--", (yyvsp[-2].string));

                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    (yyval.string) = copiedString;
                }
#line 1885 "try.tab.c"
    break;

  case 50: /* actualizacion: IDENTIFIER ASSIGN expression  */
#line 554 "try.y"
                                              {
                    char str[100];

                    sprintf(str, "%s = %s", (yyvsp[-2].string), (yyvsp[0].string));

                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    (yyval.string) = copiedString;
                }
#line 1904 "try.tab.c"
    break;

  case 51: /* boolElement: IDENTIFIER bcomparator expression  */
#line 569 "try.y"
                                               {
                char str[40];
                strcpy(str, (yyvsp[-2].string));
                strcat(str, (yyvsp[-1].string));
                strcat(str, (yyvsp[0].string));
                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                (yyval.string) = copiedString;
            }
#line 1923 "try.tab.c"
    break;

  case 53: /* bcomparator: EQ  */
#line 586 "try.y"
                 {
            (yyval.string) = "==";
        }
#line 1931 "try.tab.c"
    break;

  case 54: /* bcomparator: NE  */
#line 589 "try.y"
              {
            (yyval.string) = "!=";
        }
#line 1939 "try.tab.c"
    break;

  case 55: /* bcomparator: GE  */
#line 592 "try.y"
              {
            (yyval.string) = ">=";
        }
#line 1947 "try.tab.c"
    break;

  case 56: /* bcomparator: GT  */
#line 595 "try.y"
              {
            (yyval.string) = ">";
        }
#line 1955 "try.tab.c"
    break;

  case 57: /* bcomparator: LE  */
#line 598 "try.y"
              {
            (yyval.string) = "<=";
        }
#line 1963 "try.tab.c"
    break;

  case 58: /* bcomparator: LT  */
#line 601 "try.y"
              {
            (yyval.string) = "<";
        }
#line 1971 "try.tab.c"
    break;

  case 60: /* expression: expression ADD term  */
#line 607 "try.y"
                                 {
                char str[40];
                strcpy(str, (yyvsp[-2].string));
                strcat(str, " + ");
                strcat(str, (yyvsp[0].string));

                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                (yyval.string) = copiedString;
            }
#line 1991 "try.tab.c"
    break;

  case 61: /* expression: expression SUB term  */
#line 622 "try.y"
                                 {
                char str[40];
                strcpy(str, (yyvsp[-2].string));
                strcat(str, " - ");
                strcat(str, (yyvsp[0].string));

                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                (yyval.string) = copiedString;
            }
#line 2011 "try.tab.c"
    break;

  case 63: /* term: term MUL factor  */
#line 640 "try.y"
                       {
        char str[40];
        strcpy(str, (yyvsp[-2].string));
        strcat(str, " * ");
        strcat(str, (yyvsp[0].string));

        size_t originalStringLength = strlen(str);

        char *copiedString;
        copiedString = (char *)malloc(originalStringLength+1);

        strcpy(copiedString, str);

        (yyval.string) = copiedString;
        }
#line 2031 "try.tab.c"
    break;

  case 64: /* term: term DIV factor  */
#line 655 "try.y"
                       {
        char str[40];
        strcpy(str, (yyvsp[-2].string));
        strcat(str, " / ");
        strcat(str, (yyvsp[0].string));

        size_t originalStringLength = strlen(str);

        char *copiedString;
        copiedString = (char *)malloc(originalStringLength+1);

        strcpy(copiedString, str);


        (yyval.string) = copiedString;
        }
#line 2052 "try.tab.c"
    break;

  case 67: /* factor: LPAREN expression RPAREN  */
#line 675 "try.y"
                                  {
            (yyval.string) = (yyvsp[-1].string);
        }
#line 2060 "try.tab.c"
    break;

  case 68: /* etype: INT  */
#line 680 "try.y"
            {
            (yyval.string) = "int";
        }
#line 2068 "try.tab.c"
    break;

  case 69: /* etype: FLOAT  */
#line 683 "try.y"
                 {
            (yyval.string) = "float";
        }
#line 2076 "try.tab.c"
    break;

  case 70: /* etype: DOUBLE  */
#line 686 "try.y"
                  {
            (yyval.string) = "double";
        }
#line 2084 "try.tab.c"
    break;

  case 71: /* etype: CHAR  */
#line 689 "try.y"
                {
            (yyval.string) = "char";
        }
#line 2092 "try.tab.c"
    break;


#line 2096 "try.tab.c"

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
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 695 "try.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    
    archivo = fopen("archivo.py", "w");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    yyparse();

    fclose(archivo);
    return 0;
}

