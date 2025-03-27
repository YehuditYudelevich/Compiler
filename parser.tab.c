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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
#include "ast.h"
extern int yylex();
extern int yylineno;     
extern char *yytext;
void yyerror(const char *s);
ASTNode *root;

// פונקציה שמונעת קריסת strdup אם NULL
char* strdup_safe(const char *s) {
    return s ? strdup(s) : strdup("UNKNOWN");
}

#line 89 "parser.tab.c"

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
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_NUM = 4,                        /* NUM  */
  YYSYMBOL_RELOP = 5,                      /* RELOP  */
  YYSYMBOL_ADDOP = 6,                      /* ADDOP  */
  YYSYMBOL_MULOP = 7,                      /* MULOP  */
  YYSYMBOL_AND = 8,                        /* AND  */
  YYSYMBOL_OR = 9,                         /* OR  */
  YYSYMBOL_NOT = 10,                       /* NOT  */
  YYSYMBOL_CAST = 11,                      /* CAST  */
  YYSYMBOL_BREAK = 12,                     /* BREAK  */
  YYSYMBOL_CASE = 13,                      /* CASE  */
  YYSYMBOL_DEFAULT = 14,                   /* DEFAULT  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_FLOAT = 16,                     /* FLOAT  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_INPUT = 18,                     /* INPUT  */
  YYSYMBOL_INT = 19,                       /* INT  */
  YYSYMBOL_OUTPUT = 20,                    /* OUTPUT  */
  YYSYMBOL_SWITCH = 21,                    /* SWITCH  */
  YYSYMBOL_WHILE = 22,                     /* WHILE  */
  YYSYMBOL_LPAREN = 23,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 24,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 25,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 26,                    /* RBRACE  */
  YYSYMBOL_COLON = 27,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 28,                 /* SEMICOLON  */
  YYSYMBOL_EQUAL = 29,                     /* EQUAL  */
  YYSYMBOL_30_ = 30,                       /* ','  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_program = 32,                   /* program  */
  YYSYMBOL_declarations = 33,              /* declarations  */
  YYSYMBOL_declaration = 34,               /* declaration  */
  YYSYMBOL_idlist = 35,                    /* idlist  */
  YYSYMBOL_type = 36,                      /* type  */
  YYSYMBOL_stmt_block = 37,                /* stmt_block  */
  YYSYMBOL_stmtlist = 38,                  /* stmtlist  */
  YYSYMBOL_stmt = 39,                      /* stmt  */
  YYSYMBOL_assignment_stmt = 40,           /* assignment_stmt  */
  YYSYMBOL_input_stmt = 41,                /* input_stmt  */
  YYSYMBOL_output_stmt = 42,               /* output_stmt  */
  YYSYMBOL_if_stmt = 43,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 44,                /* while_stmt  */
  YYSYMBOL_switch_stmt = 45,               /* switch_stmt  */
  YYSYMBOL_break_stmt = 46,                /* break_stmt  */
  YYSYMBOL_caselist = 47,                  /* caselist  */
  YYSYMBOL_boolexpr = 48,                  /* boolexpr  */
  YYSYMBOL_boolterm = 49,                  /* boolterm  */
  YYSYMBOL_boolfactor = 50,                /* boolfactor  */
  YYSYMBOL_expression = 51,                /* expression  */
  YYSYMBOL_term = 52,                      /* term  */
  YYSYMBOL_factor = 53                     /* factor  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   105

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  99

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
       2,     2,     2,     2,    30,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    36,    36,    44,    45,    47,    52,    56,    61,    62,
      64,    66,    67,    69,    70,    71,    72,    73,    74,    75,
      76,    78,    83,    88,    93,   100,   106,   112,   117,   121,
     123,   124,   126,   127,   129,   130,   132,   133,   135,   136,
     138,   145,   146,   147,   148
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUM", "RELOP",
  "ADDOP", "MULOP", "AND", "OR", "NOT", "CAST", "BREAK", "CASE", "DEFAULT",
  "ELSE", "FLOAT", "IF", "INPUT", "INT", "OUTPUT", "SWITCH", "WHILE",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "COLON", "SEMICOLON", "EQUAL",
  "','", "$accept", "program", "declarations", "declaration", "idlist",
  "type", "stmt_block", "stmtlist", "stmt", "assignment_stmt",
  "input_stmt", "output_stmt", "if_stmt", "while_stmt", "switch_stmt",
  "break_stmt", "caselist", "boolexpr", "boolterm", "boolfactor",
  "expression", "term", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-64)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -64,    13,     3,   -64,   -64,   -64,   -64,   -19,   -64,    -2,
      55,    18,     9,     2,    20,    36,    45,    49,    64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,    61,   -64,    59,   -64,    50,    80,    59,    59,    50,
     -64,   -64,   -64,    59,    65,    59,     1,    83,   -64,    68,
       8,    84,   -64,    72,    69,    40,    43,    57,   -64,    59,
      51,    59,   -64,    59,    50,    50,    30,    50,    59,    67,
      70,    71,    30,    52,   -64,    83,   -64,    60,    84,    79,
     -64,    91,   -64,   -64,   -64,   -64,   -64,   -64,    30,    66,
     -64,    95,    73,    74,   -64,   -64,    19,    30,   -64
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,     7,    12,     3,     0,     2,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      20,    11,    13,    14,    15,    16,    17,    18,    19,     9,
       8,     0,     6,     0,    27,     0,     0,     0,     0,     0,
       5,    43,    44,     0,     0,     0,     0,    37,    39,     0,
       0,    31,    33,     0,     0,     0,     0,     0,    40,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,    36,    38,     0,    30,     0,
      32,    35,    22,    23,    29,    25,    42,    34,     0,     0,
      24,     0,     0,     0,    12,    12,     0,    28,    26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,   -64,   -64,   -64,   -64,   -64,   100,    -9,   -63,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -37,    38,    37,
     -33,    44,   -29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     6,     7,    31,    20,     9,    21,    22,
      23,    24,    25,    26,    27,    28,    89,    50,    51,    52,
      53,    47,    48
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      46,    12,    57,    79,    55,    56,     4,    61,    10,    85,
      13,    11,    60,     3,    58,    14,    15,    65,    16,    17,
      18,    32,    12,     5,    19,    90,    73,    77,     5,    62,
      34,    13,    66,    12,    76,    81,    14,    15,    33,    16,
      17,    18,    13,    35,     5,    98,    61,    14,    15,    61,
      16,    17,    18,    41,    42,     5,    43,    61,    61,    36,
      49,    44,    41,    42,    70,    43,    65,    71,    37,    65,
      44,    29,    38,    45,    30,    74,    86,    68,    61,    91,
      92,    72,    45,    54,    87,    96,    97,    39,    59,    40,
      63,    64,    67,    69,    88,    82,    84,    61,    83,    93,
      94,    95,     8,    78,    80,    75
};

static const yytype_int8 yycheck[] =
{
      33,     3,    39,    66,    37,    38,     3,     6,    27,    72,
      12,    30,    45,     0,    43,    17,    18,     9,    20,    21,
      22,     3,     3,    25,    26,    88,    59,    64,    25,    28,
      28,    12,    24,     3,    63,    68,    17,    18,    29,    20,
      21,    22,    12,    23,    25,    26,     6,    17,    18,     6,
      20,    21,    22,     3,     4,    25,     6,     6,     6,    23,
      10,    11,     3,     4,    24,     6,     9,    24,    23,     9,
      11,    16,    23,    23,    19,    24,    24,     5,     6,    13,
      14,    24,    23,     3,    24,    94,    95,    23,    23,    28,
       7,    23,     8,    24,    15,    28,    25,     6,    28,     4,
      27,    27,     2,    65,    67,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    33,     0,     3,    25,    34,    35,    37,    38,
      27,    30,     3,    12,    17,    18,    20,    21,    22,    26,
      37,    39,    40,    41,    42,    43,    44,    45,    46,    16,
      19,    36,     3,    29,    28,    23,    23,    23,    23,    23,
      28,     3,     4,     6,    11,    23,    51,    52,    53,    10,
      48,    49,    50,    51,     3,    51,    51,    48,    53,    23,
      51,     6,    28,     7,    23,     9,    24,     8,     5,    24,
      24,    24,    24,    51,    24,    52,    53,    48,    49,    39,
      50,    51,    28,    28,    25,    39,    24,    24,    15,    47,
      39,    13,    14,     4,    27,    27,    38,    38,    26
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    35,    35,    36,    36,
      37,    38,    38,    39,    39,    39,    39,    39,    39,    39,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    47,
      48,    48,    49,    49,    50,    50,    51,    51,    52,    52,
      53,    53,    53,    53,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     4,     3,     1,     1,     1,
       3,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     5,     5,     7,     5,    10,     2,     5,     0,
       3,     1,     3,     1,     4,     3,     3,     1,     3,     1,
       2,     3,     4,     1,     1
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
  case 2: /* program: declarations stmt_block  */
#line 36 "parser.y"
                                  { 
    printf("[DEBUG] Creating program node\n");
    root = createNode(NODE_PROGRAM, "program", (yyvsp[-1].node), (yyvsp[0].node));
    printf("\U0001F44C AST נבנה בהצלחה!\n");
    printAST(root, 0);
    (yyval.node) = root;
}
#line 1194 "parser.tab.c"
    break;

  case 3: /* declarations: declarations declaration  */
#line 44 "parser.y"
                                        { (yyval.node) = appendNode((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1200 "parser.tab.c"
    break;

  case 4: /* declarations: %empty  */
#line 45 "parser.y"
               { (yyval.node) = NULL; }
#line 1206 "parser.tab.c"
    break;

  case 5: /* declaration: idlist COLON type SEMICOLON  */
#line 47 "parser.y"
                                          {
    printf("[DEBUG] Creating declaration node (%s)\n", (yyvsp[-1].str));
    (yyval.node) = createNode(NODE_DECLARATION, strdup_safe((yyvsp[-1].str)), (yyvsp[-3].node), NULL);
}
#line 1215 "parser.tab.c"
    break;

  case 6: /* idlist: idlist ',' ID  */
#line 52 "parser.y"
                       { 
    printf("[DEBUG] Appending ID: %s\n", (yyvsp[0].str));
    (yyval.node) = appendNode((yyvsp[-2].node), createNode(NODE_ID, strdup_safe((yyvsp[0].str)), NULL, NULL)); 
}
#line 1224 "parser.tab.c"
    break;

  case 7: /* idlist: ID  */
#line 56 "parser.y"
            { 
    printf("[DEBUG] Creating ID node: %s\n", (yyvsp[0].str));
    (yyval.node) = createNode(NODE_ID, strdup_safe((yyvsp[0].str)), NULL, NULL); 
}
#line 1233 "parser.tab.c"
    break;

  case 8: /* type: INT  */
#line 61 "parser.y"
           { (yyval.str) = strdup("int"); }
#line 1239 "parser.tab.c"
    break;

  case 9: /* type: FLOAT  */
#line 62 "parser.y"
             { (yyval.str) = strdup("float"); }
#line 1245 "parser.tab.c"
    break;

  case 10: /* stmt_block: LBRACE stmtlist RBRACE  */
#line 64 "parser.y"
                                    { (yyval.node) = createNode(NODE_STMT_BLOCK, "stmt_block", (yyvsp[-1].node), NULL); }
#line 1251 "parser.tab.c"
    break;

  case 11: /* stmtlist: stmtlist stmt  */
#line 66 "parser.y"
                         { (yyval.node) = appendNode((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1257 "parser.tab.c"
    break;

  case 12: /* stmtlist: %empty  */
#line 67 "parser.y"
           { (yyval.node) = NULL; }
#line 1263 "parser.tab.c"
    break;

  case 13: /* stmt: assignment_stmt  */
#line 69 "parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1269 "parser.tab.c"
    break;

  case 14: /* stmt: input_stmt  */
#line 70 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1275 "parser.tab.c"
    break;

  case 15: /* stmt: output_stmt  */
#line 71 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1281 "parser.tab.c"
    break;

  case 16: /* stmt: if_stmt  */
#line 72 "parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1287 "parser.tab.c"
    break;

  case 17: /* stmt: while_stmt  */
#line 73 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1293 "parser.tab.c"
    break;

  case 18: /* stmt: switch_stmt  */
#line 74 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1299 "parser.tab.c"
    break;

  case 19: /* stmt: break_stmt  */
#line 75 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1305 "parser.tab.c"
    break;

  case 20: /* stmt: stmt_block  */
#line 76 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1311 "parser.tab.c"
    break;

  case 21: /* assignment_stmt: ID EQUAL expression SEMICOLON  */
#line 78 "parser.y"
                                                {
     printf("[DEBUG] Creating assignment: %s = ...\n", (yyvsp[-3].str));
     (yyval.node) = createNode(NODE_ASSIGNMENT, strdup_safe((yyvsp[-3].str)), createNode(NODE_ID, strdup_safe((yyvsp[-3].str)), NULL, NULL), (yyvsp[-1].node));
}
#line 1320 "parser.tab.c"
    break;

  case 22: /* input_stmt: INPUT LPAREN ID RPAREN SEMICOLON  */
#line 83 "parser.y"
                                              {
    printf("[DEBUG] Creating input statement for: %s\n", (yyvsp[-2].str));
    (yyval.node) = createNode(NODE_INPUT, strdup_safe((yyvsp[-2].str)), NULL, NULL);
}
#line 1329 "parser.tab.c"
    break;

  case 23: /* output_stmt: OUTPUT LPAREN expression RPAREN SEMICOLON  */
#line 88 "parser.y"
                                                        {
    printf("[DEBUG] Creating output statement\n");
    (yyval.node) = createNode(NODE_OUTPUT, NULL, (yyvsp[-2].node), NULL);
}
#line 1338 "parser.tab.c"
    break;

  case 24: /* if_stmt: IF LPAREN boolexpr RPAREN stmt ELSE stmt  */
#line 93 "parser.y"
                                                   {
    printf("[DEBUG] Creating if-else statement\n");
    (yyval.node) = createNode(NODE_IF, "if-else", (yyvsp[-4].node), 
                    createNode(NODE_STMT_BLOCK, "if-body", (yyvsp[-2].node) ? (yyvsp[-2].node) : createNode(NODE_EMPTY, "EMPTY_BLOCK", NULL, NULL),
                                                        (yyvsp[0].node) ? (yyvsp[0].node) : createNode(NODE_EMPTY, "EMPTY_BLOCK", NULL, NULL)));
}
#line 1349 "parser.tab.c"
    break;

  case 25: /* while_stmt: WHILE LPAREN boolexpr RPAREN stmt  */
#line 100 "parser.y"
                                               {
    printf("[DEBUG] Creating while loop\n");
    (yyval.node) = createNode(NODE_WHILE, "while-loop", (yyvsp[-2].node), 
                    (yyvsp[0].node) ? (yyvsp[0].node) : createNode(NODE_EMPTY, "EMPTY_BLOCK", NULL, NULL));
}
#line 1359 "parser.tab.c"
    break;

  case 26: /* switch_stmt: SWITCH LPAREN expression RPAREN LBRACE caselist DEFAULT COLON stmtlist RBRACE  */
#line 106 "parser.y"
                                                                                            {
    printf("[DEBUG] Creating switch statement\n");
    (yyval.node) = createNode(NODE_SWITCH, "switch", (yyvsp[-7].node), 
                    appendNode((yyvsp[-4].node), createNode(NODE_CASE, "default", (yyvsp[-1].node) ? (yyvsp[-1].node) : createNode(NODE_EMPTY, "EMPTY_BLOCK", NULL, NULL), NULL)));
}
#line 1369 "parser.tab.c"
    break;

  case 27: /* break_stmt: BREAK SEMICOLON  */
#line 112 "parser.y"
                             {
    printf("[DEBUG] Creating break statement\n");
    (yyval.node) = createNode(NODE_BREAK, "break", NULL, NULL); 
}
#line 1378 "parser.tab.c"
    break;

  case 28: /* caselist: caselist CASE NUM COLON stmtlist  */
#line 117 "parser.y"
                                            { 
    printf("[DEBUG] Creating case: %s\n", (yyvsp[-2].str));
    (yyval.node) = appendNode((yyvsp[-4].node), createNode(NODE_CASE, strdup_safe((yyvsp[-2].str)), (yyvsp[0].node) ? (yyvsp[0].node) : createNode(NODE_EMPTY, "EMPTY_BLOCK", NULL, NULL), NULL)); 
}
#line 1387 "parser.tab.c"
    break;

  case 29: /* caselist: %empty  */
#line 121 "parser.y"
           { (yyval.node) = NULL; }
#line 1393 "parser.tab.c"
    break;

  case 30: /* boolexpr: boolexpr OR boolterm  */
#line 123 "parser.y"
                                { (yyval.node) = createNode(NODE_EXPR, strdup_safe((yyvsp[-1].str)), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1399 "parser.tab.c"
    break;

  case 31: /* boolexpr: boolterm  */
#line 124 "parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1405 "parser.tab.c"
    break;

  case 32: /* boolterm: boolterm AND boolfactor  */
#line 126 "parser.y"
                                   { (yyval.node) = createNode(NODE_EXPR, strdup_safe((yyvsp[-1].str)), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1411 "parser.tab.c"
    break;

  case 33: /* boolterm: boolfactor  */
#line 127 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1417 "parser.tab.c"
    break;

  case 34: /* boolfactor: NOT LPAREN boolexpr RPAREN  */
#line 129 "parser.y"
                                        { (yyval.node) = createNode(NODE_EXPR, strdup_safe((yyvsp[-3].str)), (yyvsp[-1].node), NULL); }
#line 1423 "parser.tab.c"
    break;

  case 35: /* boolfactor: expression RELOP expression  */
#line 130 "parser.y"
                                         { (yyval.node) = createNode(NODE_EXPR, strdup_safe((yyvsp[-1].str)), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1429 "parser.tab.c"
    break;

  case 36: /* expression: expression ADDOP term  */
#line 132 "parser.y"
                                   { (yyval.node) = createNode(NODE_EXPR, strdup_safe((yyvsp[-1].str)), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1435 "parser.tab.c"
    break;

  case 37: /* expression: term  */
#line 133 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1441 "parser.tab.c"
    break;

  case 38: /* term: term MULOP factor  */
#line 135 "parser.y"
                         { (yyval.node) = createNode(NODE_EXPR, strdup_safe((yyvsp[-1].str)), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1447 "parser.tab.c"
    break;

  case 39: /* term: factor  */
#line 136 "parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1453 "parser.tab.c"
    break;

  case 40: /* factor: ADDOP factor  */
#line 138 "parser.y"
                      {
            if (strcmp((yyvsp[-1].str), "-") == 0) {
                (yyval.node) = createNode(NODE_EXPR, "-", (yyvsp[0].node), NULL);
            } else {
                (yyval.node) = (yyvsp[0].node); 
            }
        }
#line 1465 "parser.tab.c"
    break;

  case 41: /* factor: LPAREN expression RPAREN  */
#line 145 "parser.y"
                                  { (yyval.node) = (yyvsp[-1].node); }
#line 1471 "parser.tab.c"
    break;

  case 42: /* factor: CAST LPAREN expression RPAREN  */
#line 146 "parser.y"
                                       { (yyval.node) = createNode(NODE_EXPR, "cast", (yyvsp[-1].node), NULL); }
#line 1477 "parser.tab.c"
    break;

  case 43: /* factor: ID  */
#line 147 "parser.y"
            { (yyval.node) = createNode(NODE_ID, strdup_safe((yyvsp[0].str)), NULL, NULL); }
#line 1483 "parser.tab.c"
    break;

  case 44: /* factor: NUM  */
#line 148 "parser.y"
             { (yyval.node) = createNode(NODE_NUM, strdup_safe((yyvsp[0].str)), NULL, NULL); }
#line 1489 "parser.tab.c"
    break;


#line 1493 "parser.tab.c"

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

#line 151 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "\U0001F6A8 Syntax error at line %d: %s\n", yylineno, s);
    fprintf(stderr, "Last token read: '%s'\n", yytext);
}
