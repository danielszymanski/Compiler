/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "def.yy" /* yacc.c:339  */

#include <stdio.h>
#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;


static int label_count=0;
stack<string> labels;


struct str
	{
		string value;
		int type;
	};

//nagłówki metod
void make_threes(char name);
void make_assembler(str el1, str el2, string name, char sign);
string convert(int id);
bool Exist(string el);
void make_assembler_assign(str el1,str el2);
string GetInteger(str el, int RegNum);
string GetStoreCode(int type1,int type2,string result);
string GetFloat(str el, int RegNum);
void make_assembler_print(string tmp,bool flag);
void make_assembler_read(string tmp);
void makeCompareAssembler(string sign);
void makeElse();
void make_array_symbol(string id,int type,int size);
void make_array(string id, int flag);
void array_assign(string id, int flag);

int	ARRI = 10;
int	ARRF = 11;

static int helper = 0;
static int licznik=0;


template <typename T>
string tostring(T value);

template<typename T>
void push(T arg, int type);

struct symbolinfo{
		int size;
		int type;
		string id;
		string value;
		};

//struktury danych

vector<string> assembler;
stack<str> stos;
map<string,symbolinfo> symbole;


extern FILE *yyin,*yyout;
ofstream rpn_file,trojki_file,symbole_file;

extern "C" int yylex();
extern "C" int yyerror(const char *msg,...);

#line 139 "def.tab.cc" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "def.tab.hh".  */
#ifndef YY_YY_DEF_TAB_HH_INCLUDED
# define YY_YY_DEF_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    GT = 258,
    LT = 259,
    LE = 260,
    GE = 261,
    EQ = 262,
    NE = 263,
    READ = 264,
    PRINT = 265,
    IF = 266,
    ELSE = 267,
    INT = 268,
    FLOAT = 269,
    FOR = 270,
    STRING = 271,
    ID = 272,
    LC = 273,
    LZ = 274
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 74 "def.yy" /* yacc.c:355  */
char *text;
int	ival;float fval;

#line 203 "def.tab.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_DEF_TAB_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 220 "def.tab.cc" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  109

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   274

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      23,    24,    30,    28,     2,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    20,
       2,    27,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    25,     2,    26,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    21,     2,    22,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    88,    88,    89,    93,    94,    95,    96,    97,    98,
      99,   107,   113,   122,   126,   134,   146,   150,   165,   177,
     178,   179,   180,   181,   182,   190,   194,   195,   199,   213,
     227,   229,   233,   235,   247,   248,   249,   252,   253,   254,
     257,   258,   259,   260,   262,   274
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "GT", "LT", "LE", "GE", "EQ", "NE",
  "READ", "PRINT", "IF", "ELSE", "INT", "FLOAT", "FOR", "STRING", "ID",
  "LC", "LZ", "';'", "'{'", "'}'", "'('", "')'", "'['", "']'", "'='",
  "'+'", "'-'", "'*'", "'/'", "$accept", "multiline", "line", "if_expr",
  "if_begin", "else_expr", "for_expr", "for_begin", "for_init", "for_inc",
  "cond_expr", "wczytanie", "wypisanie", "deklaracja", "przypisanie",
  "wyr", "skladnik", "czynnik", "tab_wyr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      59,   123,   125,    40,    41,    91,    93,    61,    43,    45,
      42,    47
};
# endif

#define YYPACT_NINF -38

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-38)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      33,   -12,    15,    26,    40,    46,    44,   -13,   -38,   -38,
      -2,    22,   -38,   -38,    58,   -38,    62,    74,    84,    99,
     109,   112,   -10,    57,   -38,    83,    92,    -2,    90,   108,
      74,    -2,    -2,   -38,   110,    -1,   -38,   -38,    33,    33,
      41,    -2,   114,   -38,   -38,   -38,   -38,   -38,    -2,    -2,
      -2,    -2,   113,   115,   116,   117,     1,   118,   120,   122,
      32,    95,    -2,   -38,    67,    88,    -2,   119,   -38,    57,
      57,   -38,   -38,   -38,   -38,   -38,   -38,    -2,    -2,    -2,
      -2,    -2,    -2,   121,   123,   -38,   124,    36,   132,   -38,
      66,   -38,    95,    95,    95,    95,    95,    95,   -38,   -38,
      -2,   -38,   -38,   125,   124,    95,    33,   103,   -38
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    40,    41,    42,
       0,     0,     3,     8,     0,     9,     0,     0,     0,     0,
       0,     0,     0,    36,    39,     0,     0,     0,    28,    29,
       0,     0,     0,    44,    40,     0,     1,     2,     0,     0,
       0,     0,     0,     7,     6,     5,     4,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,     0,    43,     0,     0,     0,     0,    18,    34,
      35,    37,    38,    25,    27,    26,    13,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    45,     0,    11,    15,
       0,    16,    22,    21,    23,    24,    19,    20,    30,    31,
       0,    45,    14,     0,     0,    33,     0,     0,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -37,   -11,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     104,   -38,   -38,   -38,    -4,    -7,    79,    80,   -38
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    11,    12,    13,    14,   103,    15,    16,    17,    41,
      55,    18,    19,    20,    21,    22,    23,    24,    33
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      37,    64,    65,    35,    77,    78,    79,    80,    81,    82,
      47,    25,    31,    42,    32,    34,     8,     9,    48,    49,
      56,    10,    36,    63,    60,    61,    59,    48,    49,    48,
      49,     1,     2,     3,    56,     4,     5,     6,    26,     7,
       8,     9,     1,     2,     3,    10,     4,     5,     6,    27,
       7,     8,     9,    37,    37,    87,    10,    28,    86,    90,
      48,    49,   101,    29,    48,    49,    66,    30,    32,   107,
      92,    93,    94,    95,    96,    97,     1,     2,     3,    38,
       4,     5,     6,    39,     7,     8,     9,    50,    51,    88,
      10,    40,   104,   105,    48,    49,    37,     1,     2,     3,
      52,     4,     5,     6,    43,     7,     8,     9,    53,    54,
      89,    10,     1,     2,     3,    57,     4,     5,     6,    44,
       7,     8,     9,    48,    49,   108,    10,    69,    70,    45,
      71,    72,    46,    58,    68,    62,    83,    73,    84,    74,
      75,    76,    85,    91,   102,    67,   106,    98,     0,    99,
       0,   100
};

static const yytype_int8 yycheck[] =
{
      11,    38,    39,    10,     3,     4,     5,     6,     7,     8,
      20,    23,    25,    17,    27,    17,    18,    19,    28,    29,
      27,    23,     0,    24,    31,    32,    30,    28,    29,    28,
      29,     9,    10,    11,    41,    13,    14,    15,    23,    17,
      18,    19,     9,    10,    11,    23,    13,    14,    15,    23,
      17,    18,    19,    64,    65,    62,    23,    17,    26,    66,
      28,    29,    26,    17,    28,    29,    25,    23,    27,   106,
      77,    78,    79,    80,    81,    82,     9,    10,    11,    21,
      13,    14,    15,    21,    17,    18,    19,    30,    31,    22,
      23,    17,    26,   100,    28,    29,   107,     9,    10,    11,
      17,    13,    14,    15,    20,    17,    18,    19,    16,    17,
      22,    23,     9,    10,    11,    25,    13,    14,    15,    20,
      17,    18,    19,    28,    29,    22,    23,    48,    49,    20,
      50,    51,    20,    25,    20,    25,    18,    24,    18,    24,
      24,    24,    20,    24,    12,    41,    21,    26,    -1,    26,
      -1,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    10,    11,    13,    14,    15,    17,    18,    19,
      23,    33,    34,    35,    36,    38,    39,    40,    43,    44,
      45,    46,    47,    48,    49,    23,    23,    23,    17,    17,
      23,    25,    27,    50,    17,    47,     0,    34,    21,    21,
      17,    41,    46,    20,    20,    20,    20,    20,    28,    29,
      30,    31,    17,    16,    17,    42,    47,    25,    25,    46,
      47,    47,    25,    24,    33,    33,    25,    42,    20,    48,
      48,    49,    49,    24,    24,    24,    24,     3,     4,     5,
       6,     7,     8,    18,    18,    20,    26,    47,    22,    22,
      47,    24,    47,    47,    47,    47,    47,    47,    26,    26,
      27,    26,    12,    37,    26,    47,    21,    33,    22
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    33,    34,    34,    34,    34,    34,    34,
      34,    35,    35,    36,    37,    38,    39,    40,    41,    42,
      42,    42,    42,    42,    42,    43,    44,    44,    45,    45,
      45,    45,    46,    46,    47,    47,    47,    48,    48,    48,
      49,    49,    49,    49,    49,    50
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     2,     2,     1,     1,
       2,     4,     8,     4,     1,     4,     4,     4,     2,     3,
       3,     3,     3,     3,     3,     4,     4,     4,     2,     2,
       5,     5,     3,     6,     3,     3,     1,     3,     3,     1,
       1,     1,     1,     3,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 88 "def.yy" /* yacc.c:1646  */
    {;}
#line 1369 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 89 "def.yy" /* yacc.c:1646  */
    {;}
#line 1375 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 93 "def.yy" /* yacc.c:1646  */
    {;}
#line 1381 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 5:
#line 94 "def.yy" /* yacc.c:1646  */
    {;}
#line 1387 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 6:
#line 95 "def.yy" /* yacc.c:1646  */
    {;}
#line 1393 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 96 "def.yy" /* yacc.c:1646  */
    {;}
#line 1399 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 97 "def.yy" /* yacc.c:1646  */
    {;}
#line 1405 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 98 "def.yy" /* yacc.c:1646  */
    {;}
#line 1411 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 99 "def.yy" /* yacc.c:1646  */
    {;}
#line 1417 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 108 "def.yy" /* yacc.c:1646  */
    {
			string etykieta=labels.top();
      assembler.push_back(etykieta+":");
      labels.pop();label_count++;
		}
#line 1427 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 114 "def.yy" /* yacc.c:1646  */
    {
			string etykieta=labels.top();
    	assembler.push_back(etykieta+":");
      labels.pop();label_count++;
		}
#line 1437 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 122 "def.yy" /* yacc.c:1646  */
    {;}
#line 1443 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 126 "def.yy" /* yacc.c:1646  */
    { makeElse();}
#line 1449 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 135 "def.yy" /* yacc.c:1646  */
    {
		string label = labels.top();
	  labels.pop();
	  string label2 = labels.top();
	  labels.pop();
	  assembler.push_back("j " + label2);
	  assembler.push_back(label + ":");
	}
#line 1462 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 146 "def.yy" /* yacc.c:1646  */
    {;}
#line 1468 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 151 "def.yy" /* yacc.c:1646  */
    {
		string label="FOR_L"+to_string(label_count);
		label_count++;
		string label2="FOR_L"+to_string(label_count);
		label_count++;

		labels.push(label2);
		labels.push(label);
		assembler.push_back("j " + label);
		assembler.push_back(label2 + ":");
  }
#line 1484 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 166 "def.yy" /* yacc.c:1646  */
    {
		string label=labels.top();
		labels.pop();
		assembler.push_back(label + ":");
 	}
#line 1494 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 177 "def.yy" /* yacc.c:1646  */
    {makeCompareAssembler("bne");}
#line 1500 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 178 "def.yy" /* yacc.c:1646  */
    {makeCompareAssembler("beq");}
#line 1506 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 179 "def.yy" /* yacc.c:1646  */
    {makeCompareAssembler("bge");}
#line 1512 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 180 "def.yy" /* yacc.c:1646  */
    {makeCompareAssembler("ble");}
#line 1518 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 181 "def.yy" /* yacc.c:1646  */
    {makeCompareAssembler("bgt");}
#line 1524 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 182 "def.yy" /* yacc.c:1646  */
    {makeCompareAssembler("blt");}
#line 1530 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 190 "def.yy" /* yacc.c:1646  */
    {make_assembler_read((yyvsp[-1].text));}
#line 1536 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 194 "def.yy" /* yacc.c:1646  */
    {make_assembler_print((yyvsp[-1].text),false);}
#line 1542 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 195 "def.yy" /* yacc.c:1646  */
    {make_assembler_print((yyvsp[-1].text),true);}
#line 1548 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 200 "def.yy" /* yacc.c:1646  */
    {
	 	if(Exist((yyvsp[0].text))) cout << "juz istnieje\n";
		else
		{
			symbolinfo sInfo;
			sInfo.type=LC;
			sInfo.size=1;
			sInfo.id=(yyvsp[0].text);
			sInfo.value="0";
			symbole.insert(std::pair<string,symbolinfo>((yyvsp[0].text),sInfo));
		}
	}
#line 1565 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 214 "def.yy" /* yacc.c:1646  */
    {
	 if(Exist((yyvsp[0].text))) cout << "Zmienna " << (yyvsp[0].text) << " juz istnieje\n";
	 else
		 {
		 	symbolinfo sInfo;
	 		sInfo.type=LZ;
			sInfo.size=1;
	 		sInfo.id=(yyvsp[0].text);
	 		sInfo.value="0";
			symbole.insert(std::pair<string,symbolinfo>((yyvsp[0].text),sInfo));
		}
	}
#line 1582 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 227 "def.yy" /* yacc.c:1646  */
    {make_array_symbol((yyvsp[-3].text),ARRI,(yyvsp[-1].ival));}
#line 1588 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 229 "def.yy" /* yacc.c:1646  */
    {make_array_symbol((yyvsp[-3].text),ARRF,(yyvsp[-1].ival));}
#line 1594 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 233 "def.yy" /* yacc.c:1646  */
    {push((yyvsp[-2].text),ID); make_threes('=');}
#line 1600 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 235 "def.yy" /* yacc.c:1646  */
    {
		int flag=0;

			auto it = symbole.find((yyvsp[-5].text));
			if(it->second.type==ARRI)
				flag=1;

				array_assign((yyvsp[-5].text),flag);
		}
#line 1614 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 247 "def.yy" /* yacc.c:1646  */
    {make_threes('+');}
#line 1620 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 248 "def.yy" /* yacc.c:1646  */
    {make_threes('-');}
#line 1626 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 249 "def.yy" /* yacc.c:1646  */
    {;}
#line 1632 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 252 "def.yy" /* yacc.c:1646  */
    {make_threes('*');}
#line 1638 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 253 "def.yy" /* yacc.c:1646  */
    {make_threes('/');}
#line 1644 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 254 "def.yy" /* yacc.c:1646  */
    {;}
#line 1650 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 257 "def.yy" /* yacc.c:1646  */
    {push((yyvsp[0].text),ID);}
#line 1656 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 258 "def.yy" /* yacc.c:1646  */
    {push((yyvsp[0].ival),LC);}
#line 1662 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 259 "def.yy" /* yacc.c:1646  */
    {push((yyvsp[0].fval),LZ);}
#line 1668 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 260 "def.yy" /* yacc.c:1646  */
    {;}
#line 1674 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 263 "def.yy" /* yacc.c:1646  */
    {
		int flag=0;
			auto it = symbole.find((yyvsp[-1].text));
			if(it->second.type==ARRI)
				flag=1;

		make_array((yyvsp[-1].text),flag);
	}
#line 1687 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 274 "def.yy" /* yacc.c:1646  */
    {;}
#line 1693 "def.tab.cc" /* yacc.c:1646  */
    break;


#line 1697 "def.tab.cc" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 277 "def.yy" /* yacc.c:1906  */

void make_array(string id, int flag)
{
	str var1 = stos.top();
	stos.pop();
	assembler.push_back("la $t4, " + tostring(id));

	if(var1.type == ID)
		assembler.push_back("lw $t5, " + tostring(var1.value));
	else
		assembler.push_back("li $t5, " + tostring(var1.value));

	assembler.push_back("mul $t5, $t5, 4");
	assembler.push_back("add $t4, $t4, $t5");
	string tempName="";

	if(flag==1)
	{
		assembler.push_back("lw $t0, ($t4)");
		helper++;
		tempName = "_tmp" + to_string(helper);
	}
	else
	{
		assembler.push_back("l.s $f0, ($t4)");
		licznik++;
		tempName = "_tmp" + to_string(licznik);
	}

	symbolinfo sInfo;
	sInfo.id = tempName;

	if(flag == 1)
		sInfo.type = LC;
	else
		sInfo.type = LZ;

	sInfo.size = 1;
	sInfo.value = "0";

	symbole.insert(std::pair<string,symbolinfo>(tempName,sInfo));
	push(tempName,ID);
	if(flag==1)
		assembler.push_back("sw $t0, " + tempName);
	else
		assembler.push_back("s.s $f0, " + tempName);
}

void array_assign(string id, int flag)
{
	assembler.push_back("la $t4, " + tostring(id));
	str variable1 = stos.top();
	stos.pop();
	string _asm1="";
	if(flag==1)
		_asm1 = GetInteger(variable1,0);
	else
		_asm1 = GetFloat(variable1,0);

	assembler.push_back(_asm1);

	str variable2 = stos.top();
	stos.pop();
	string _asm2 = GetInteger(variable2,5);
	assembler.push_back(_asm2);
	assembler.push_back("mul $t5, $t5, 4");
	assembler.push_back("add $t4, $t4, $t5");
	if(flag==1)
		assembler.push_back("sw $t0, ($t4)");
	else
		assembler.push_back("s.s $f0, ($t4)");
}

void make_array_symbol(string id,int type,int size)
{
		symbolinfo sinfo;
		sinfo.id=id;
		sinfo.type=type;
		sinfo.size=1;
		sinfo.value="0:"+to_string(size);
		symbole.insert(std::pair<string,symbolinfo>(sinfo.id,sinfo));
}

void makeElse()
{
	string etykieta=labels.top();
	string nowaEtykieta="ELSE_L"+to_string(label_count);

	assembler.push_back("j "+nowaEtykieta);
	assembler.push_back(etykieta+":");
	labels.pop();
	etykieta = "ELSE_L"+to_string(label_count);
	labels.push(etykieta);
}


void makeCompareAssembler(string sign){

  str variable2=stos.top();
  stos.pop();
  str variable1=stos.top();
  stos.pop();

  if(variable1.type==LZ || variable2.type==LZ)
		{
			cout << "Bledne typy do porownania\n";
			exit(-1);
		}

  string _asm1, _asm2, etykieta;

  _asm1=GetInteger(variable1,0);
  _asm2=GetInteger(variable2,1);
  etykieta = "IF_L"+to_string(label_count);

  labels.push(etykieta);
  assembler.push_back(_asm1);
  assembler.push_back(_asm2);
  assembler.push_back(sign +" $t0,$t1, "+etykieta);
  label_count++;
}

string convert(int id)
{
			if(id == LC || id == ARRI)
				return ".word";

			if(id == LZ | id == ARRF)
				return ".float";

			if(id == STRING)
				return ".asciiz";

	return ".unknown";
}

int GetType(str el)
{
	if(el.type == LC || el.type == LZ)
		return el.type;
	else if (el.type == ID)
	{
			auto it = symbole.find(el.value);

			if(it != symbole.end())
				return it->second.type;
	}
	else
	{
			cout << "Nie znaleziono symbolu.";
			exit(-1);
	}

		cout << "Nieznany typ.";
		exit(-1);

}

bool Exist(string el)
{
	auto it = symbole.find(el);

	if(it != symbole.end())
			return true;
	else
			return false;
}


void make_assembler_read(string tmp)
{
	string _asm1,_asm2,_asm3;

	map<string,symbolinfo>::iterator it;
	it=symbole.find(tmp);
	if(it!=symbole.end())
	{
		if(it->second.type == LC)
			{
				_asm1="li $v0, 5";
				_asm2="syscall";
				_asm3="sw $v0, " + tostring(tmp);
			}
		else if(it->second.type == LZ)
			{
				_asm1="li $v0, 6";
				_asm2="syscall";
				_asm3="s.s $f0, " + tostring(tmp);

			}
		}
		else
		{
			cout << "Nieznany typ zmiennej do wczytania";
			return;
		}

		assembler.push_back(_asm1);
		assembler.push_back(_asm2);
		assembler.push_back(_asm3);
}

void make_assembler_print(string tmp,bool flag){

string _asm1,_asm2,_asm3;

	if(flag){
		helper++;
		symbolinfo sinfo;
		sinfo.type=STRING;
		sinfo.size=1;
		sinfo.value=tmp;
		string nazwa="string"+to_string(helper);
		sinfo.id=nazwa;
		symbole.insert(std::pair<string,symbolinfo>(sinfo.id,sinfo));

		_asm1="li $v0, 4";
		_asm2="la $a0, "+nazwa;
		_asm3="syscall";
	}

else
{
	map<string,symbolinfo>::iterator it;
	it=symbole.find(tmp);
	if(it!=symbole.end())
	{
		if(it->second.type == LC)
			{
				_asm1="li $v0,1";
				_asm2="lw $a0 "+tmp;
				_asm3="syscall";
			}
		else if(it->second.type == LZ)
			{
				_asm1="li $v0,2";
				_asm2="lwc1 $f12 "+tmp;
				_asm3="syscall";
			}
		}
		else
		{
			cout << "Nieznany typ do wyswietlenia";
			return;
		}
}

	assembler.push_back(_asm1);
	assembler.push_back(_asm2);
	assembler.push_back(_asm3);
}

void make_assembler_assign(str el1,str el2)
{
	string _asm1,_asm2,_asm3,_asm4;
	int flaga=0;

	int type1=GetType(el1);
	int type2=GetType(el2);

	if(type1==LC && type2== LC){
			_asm1=GetInteger(el1,0);
	}
	else if(type1==LZ && type2==LZ){
			_asm1=GetFloat(el1,0);
	}
	else if(type2==LC && type1==LZ){
		cout << "Blad przypisania (int = float)" << endl;
		exit(-1);
	}

	if(type2==LZ && type1==LC){
		_asm1=GetInteger(el1,0);
		_asm2 = "mtc1 $t0 , $f0";
		_asm3 = "cvt.s.w $f0 , $f0";
		flaga=1;
	}

	assembler.push_back(_asm1);

	if(flaga)
	{
		assembler.push_back(_asm2);
		assembler.push_back(_asm3);
	}

	_asm4=GetStoreCode(type1,type2,el2.value);
	assembler.push_back(_asm4);
}


void make_threes(char name)
{
		str _temp2 = stos.top();
		stos.pop();
		str _temp1 = stos.top();
		stos.pop();


			if(name!='=')
			{
				helper++;
				int type1 = GetType(_temp1);
				int type2 = GetType(_temp2);

				string tmp_name = "_tmp"+to_string(helper);
				trojki_file << tmp_name << " = " << _temp1.value << name << _temp2.value << endl;
				push(tmp_name,ID);

				symbolinfo sinfo;
				sinfo.id=tmp_name;

				if(type1 == LZ || type2 == LZ)
					sinfo.type=LZ;
				else
					sinfo.type=LC;

				sinfo.size=1;
				sinfo.value="0";
				symbole.insert(std::pair<string,symbolinfo>(tmp_name,sinfo));
				make_assembler(_temp1,_temp2,tmp_name,name);
			}

			else
				make_assembler_assign(_temp1,_temp2);
}

string GetOperatorCode(char sign,int type1,int type2)
{
	string s;

	if(sign=='+')
		s="add";
	else if(sign=='-')
		s="sub";
	else if(sign=='*')
		s="mul";
	else if(sign=='/')
		s="div";


		if(type1 == LC && type2 == LC)
			s= s+" $t0, $t0,$t1";

		else
			s= s+".s $f0,$f0,$f1";

			return s;
}

string GetStoreCode(int type1,int type2,string result)
{
	string s;

		if(type1 == LC && type2 == LC)
			s="sw $t0,"+result;

		else
			s="s.s $f0,"+result;

			return s;
}

string GetFloat(str el, int RegNum)
{
		if(el.type==ID)
			return "l.s $f" + to_string(RegNum) + "," + el.value;

		symbolinfo sinfo;
		sinfo.id="_tmp_float"+to_string(licznik);
		licznik++;
		sinfo.type=LZ;
		sinfo.size=1;
		sinfo.value=el.value;
		symbole.insert(std::pair<string,symbolinfo>(sinfo.id,sinfo));

		return "l.s $f" + to_string(RegNum) + "," + sinfo.id;
}

string GetInteger(str el, int RegNum)
{
		if(el.type == ID)
			return "lw $t" + to_string(RegNum) + "," +el.value;
		else if(el.type == LC)
			return "li $t" + to_string(RegNum) + "," +el.value;
}

void make_assembler(str el1, str el2, string name, char sign)
{
	string _asm1,_asm2,_asm3,_asm4, _asm5,_asm_tmp1, _asm_tmp2;
	int type1, type2;
	int flaga = 0;

	type1 = GetType(el1);
	type2 = GetType(el2);

	if(type1 == LZ && type2 == LZ)
	{
		_asm1 = GetFloat(el1,0);
		_asm2 = GetFloat(el2,1);
	}

	else if (type1 == LC && type2 == LC)
	{
		_asm1=GetInteger(el1,0);
		_asm2=GetInteger(el2,1);
	}

	else
	{
		int rejestr;
		flaga=1;

		if (type1 == LZ)
		{
				rejestr = 1;
				_asm1 = GetFloat(el1,0);
				_asm2 = GetInteger(el2,rejestr);
		}

		else if(type2 == LZ)
		{
			rejestr = 0;
			_asm1 = GetInteger(el1,rejestr);
			_asm2 = GetFloat(el2,1);
		}

		_asm_tmp1 = "mtc1 $t" + to_string(rejestr) + ", " + "$f" + to_string(rejestr);
		_asm_tmp2 = "cvt.s.w $f" + to_string(rejestr) + ", " + "$f" + to_string(rejestr);
	}

	assembler.push_back(_asm1);

	if(flaga==1 && type2 == LZ)
	{
		assembler.push_back(_asm_tmp1);
		assembler.push_back(_asm_tmp2);
	}

	assembler.push_back(_asm2);

	if(flaga==1 && type1 == LZ)
	{
		assembler.push_back(_asm_tmp1);
		assembler.push_back(_asm_tmp2);
	}

	_asm3= GetOperatorCode(sign,type1,type2);
	_asm4= GetStoreCode(type1,type2,name);

	assembler.push_back(_asm3);
	assembler.push_back(_asm4);
}

template<typename T>
void push(T arg, int type)
{
	str x;
	x.value = tostring(arg);
	x.type = type;
	stos.push(x);

}

template <typename T>
string tostring(T value)
{
	stringstream sstream;
	sstream << value;
		return sstream.str();
}


int main(int argc, char *argv[])
{

	rpn_file.open("rpn.txt");
	trojki_file.open("trojki.txt");
	symbole_file.open("symbole.txt");


	if (argc>1)
	{
		yyin = fopen(argv[1], "rw");
			if (yyin==NULL)
			{
				printf("Błąd\n");
				return 0;
			}

	}

	yyparse();

		if (argc>1)
		{
			fclose(yyin);
		}

	yyout=fopen("kod.asm","w");
	fprintf(yyout,"%s",".data\n");

	for(auto sym:symbole)
	{
		fprintf(yyout,"\t%s\t:",sym.second.id.c_str());
		fprintf(yyout,"\t%s",convert(sym.second.type).c_str());
		fprintf(yyout,"\t%s\n",sym.second.value.c_str());
	}

	fprintf(yyout,"%s",".text\n\n");
	for(auto kod:assembler)
	{
		fprintf(yyout,"%s\n",kod.c_str());
	}

	for(auto sym:symbole)
	{
		symbole_file << sym.second.id << "\t";
		symbole_file << sym.second.type << "\t";
		symbole_file << sym.second.size << endl;
	}


	rpn_file.close();
	trojki_file.close();

	return 0;
}
