/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

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


/* Código C, use para #include, variáveis globais e constantes
 * este código ser adicionado no início do arquivo fonte em C
 * que será gerado.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char token[50];
    int num_filhos;
    struct No** filhos;
} No;

enum tipos{INT, FLOAT, CHAR, STR};

typedef struct registro_da_tabela_de_simbolo {
    char token[50];
    char lexema[50];
    char tipo[50];
    int endereco;
} RegistroTS;

#define TAM_TABELA_DE_SIMBOLOS 1024

RegistroTS tabela_de_simbolos[TAM_TABELA_DE_SIMBOLOS];
int prox_posicao_livre = 0;
int prox_mem_livre = 0;

No* allocar_no();
void liberar_no(No* no);
void imprimir_arvore(No* raiz);
No* novo_no(char[50], No**, int);
void imprimir_tabela_de_simbolos(RegistroTS*);
void inserir_na_tabela_de_simbolos(RegistroTS);


#line 110 "parser.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    PRIMITIVAS = 258,
    PALAVRAS_RESERVADAS = 259,
    ESTRUTURAS = 260,
    CONDICIONAL = 261,
    LOOP = 262,
    NUMBER = 263,
    NUMBER_FLOAT = 264,
    VARIAVEL = 265,
    OPERACAO_LOGICA = 266,
    OPERADOR_SOMA = 267,
    OPERADOR_MUL = 268,
    OPERADOR_SUB = 269,
    OPERADOR_DIV = 270,
    OPERADOR_LOGICO_ADD = 271,
    OPERADOR_LOGICO_OR = 272,
    OPERADOR_LOGICO_COMPARACAO = 273,
    OPERADOR_LOGICO_NOT = 274,
    OPERADOR_LOGICO_NOT_EQ = 275,
    OPERADOR_UNARIO = 276,
    OPERADOR_ATRIBUICAO = 277,
    ABERTURA_PAR = 278,
    ABERTURA_CHAVE = 279,
    ABERTURA_COLCHETE = 280,
    FECHAMENTO_PAR = 281,
    FECHAMENTO_CHAVE = 282,
    FECHAMENTO_COLCHETE = 283,
    STRING = 284,
    CARACTER = 285,
    FUNCAO = 286,
    VETOR = 287,
    TAMANHO_VETOR = 288,
    ELSE = 289,
    EOL = 290,
    VIRGULA = 291,
    PV = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "parser.y"

    int number;
    char simbolo[50];
    struct No* no;

#line 197 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  104

#define YYUNDEFTOK  2
#define YYMAXUTOK   292

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   134,   134,   135,   141,   147,   156,   157,   165,   173,
     181,   189,   194,   201,   210,   218,   219,   227,   233,   242,
     243,   250,   256,   257,   265,   273,   281,   289,   297,   305,
     329,   337,   345,   353,   390,   427,   438,   439,   449,   460,
     462,   463,   464,   466,   467,   468,   470,   472,   473,   474,
     475
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRIMITIVAS", "PALAVRAS_RESERVADAS",
  "ESTRUTURAS", "CONDICIONAL", "LOOP", "NUMBER", "NUMBER_FLOAT",
  "VARIAVEL", "OPERACAO_LOGICA", "OPERADOR_SOMA", "OPERADOR_MUL",
  "OPERADOR_SUB", "OPERADOR_DIV", "OPERADOR_LOGICO_ADD",
  "OPERADOR_LOGICO_OR", "OPERADOR_LOGICO_COMPARACAO",
  "OPERADOR_LOGICO_NOT", "OPERADOR_LOGICO_NOT_EQ", "OPERADOR_UNARIO",
  "OPERADOR_ATRIBUICAO", "ABERTURA_PAR", "ABERTURA_CHAVE",
  "ABERTURA_COLCHETE", "FECHAMENTO_PAR", "FECHAMENTO_CHAVE",
  "FECHAMENTO_COLCHETE", "STRING", "CARACTER", "FUNCAO", "VETOR",
  "TAMANHO_VETOR", "ELSE", "EOL", "VIRGULA", "PV", "$accept", "prog",
  "stmts", "stmt", "else", "args", "arg", "exp", "fator", "primitivas",
  "abertura", "fechamento", "operador", "termo", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

#define YYPACT_NINF -43

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-43)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -43,   112,   -43,   -43,    68,    68,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -31,   139,   216,    37,   177,    -1,    68,
      -1,    -1,   -43,   -43,   -43,    94,    94,    94,    94,    94,
      94,   139,    94,    94,    94,   201,    -1,   -43,   193,   177,
      68,   147,   193,   193,    37,    37,    37,    37,    37,    37,
     -43,    37,   -43,   -43,   139,   147,   193,   -43,   -43,   -43,
     -43,    -3,    94,   -10,   -43,    94,   -43,    80,   139,    68,
     -43,   -10,    68,   -43,    -1,    80,    46,   -43,   -43,    -8,
     -43,   139,   139,    68,   139,   216,   -43,    -1,    80,   193,
      80,   139,    80,   216,   -23,   -43,    80,   -43,    68,   -43,
     -43,   139,    80,   -43
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    39,     0,     0,    47,    48,    49,    40,
      41,    42,    50,     0,     4,     6,    22,     0,     0,    36,
       0,     0,     3,     5,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,     0,    36,     0,     0,
      36,    19,     0,     0,    23,    24,    25,    26,    27,    28,
      30,    31,    37,    38,     0,    19,     0,    43,    44,    45,
      32,    33,     0,     0,    17,     0,    11,    21,     0,     0,
      29,     0,     0,    21,     0,     0,    19,    12,    20,     0,
       7,     0,     0,     0,     0,    34,    18,     0,     0,     0,
       0,     0,     0,    35,     8,    10,     0,    14,     0,     9,
      13,     0,     0,    16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -43,   -43,    11,   -11,   -43,   -28,   -42,   -15,   152,    40,
      -4,    42,   -43,    12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    13,    14,    99,    63,    64,    15,    16,    17,
      18,    60,    32,    19
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,    21,     3,    38,    22,    42,    43,     6,     7,     8,
      33,    98,    34,    36,    87,    41,    57,    58,    59,    54,
      50,    56,     9,    10,    11,    23,    76,    71,    12,    37,
      40,    55,    40,    40,    86,    36,    62,    37,    37,    37,
      37,    37,    37,    70,    37,    52,    53,     0,    40,     3,
      33,    37,    34,    67,     6,     7,     8,    80,    39,    85,
      39,    39,     0,     0,    81,    82,    89,    73,    84,     0,
      88,    90,    93,    92,    75,    12,    39,    78,     0,    91,
      96,    65,     0,    66,    68,    69,    40,     0,    73,     0,
     102,     9,    10,    11,   101,    65,     0,    72,    74,    40,
       0,     0,     6,     7,     8,    77,    57,    58,    59,    79,
       0,     0,     2,    83,    39,     3,    65,    79,     4,     5,
       6,     7,     8,    12,     0,     0,     0,    39,     0,     0,
      94,     0,    95,     0,    97,     9,    10,    11,   100,     0,
       0,    12,     3,     0,   103,     4,     5,     6,     7,     8,
       3,     0,     0,     0,     0,     6,     7,     8,     0,     0,
       0,     0,     9,    10,    11,     0,     0,     0,    12,    35,
       0,     0,     0,    57,    58,    59,    12,    44,    45,    46,
      47,    48,    49,     0,    51,     6,     7,     8,     0,     0,
       0,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       9,    10,    11,     0,    24,    25,    12,    26,     0,    27,
      28,    29,     0,    30,    33,    31,    34,     0,     0,    57,
      58,    59,     0,    54,     9,    10,    11,    24,    25,     0,
      26,     0,    27,    28,    29,     0,    30,     0,    31
};

static const yytype_int8 yycheck[] =
{
       4,     5,     3,    18,    35,    20,    21,     8,     9,    10,
      13,    34,    15,    17,    22,    19,    26,    27,    28,    22,
      31,    36,    23,    24,    25,    14,    36,    55,    29,    17,
      18,    35,    20,    21,    76,    39,    40,    25,    26,    27,
      28,    29,    30,    54,    32,    33,    34,    -1,    36,     3,
      13,    39,    15,    41,     8,     9,    10,    68,    18,    74,
      20,    21,    -1,    -1,    68,    69,    81,    55,    72,    -1,
      81,    82,    87,    84,    62,    29,    36,    65,    -1,    83,
      91,    41,    -1,    41,    42,    43,    74,    -1,    76,    -1,
     101,    23,    24,    25,    98,    55,    -1,    55,    56,    87,
      -1,    -1,     8,     9,    10,    63,    26,    27,    28,    67,
      -1,    -1,     0,    71,    74,     3,    76,    75,     6,     7,
       8,     9,    10,    29,    -1,    -1,    -1,    87,    -1,    -1,
      88,    -1,    90,    -1,    92,    23,    24,    25,    96,    -1,
      -1,    29,     3,    -1,   102,     6,     7,     8,     9,    10,
       3,    -1,    -1,    -1,    -1,     8,     9,    10,    -1,    -1,
      -1,    -1,    23,    24,    25,    -1,    -1,    -1,    29,    17,
      -1,    -1,    -1,    26,    27,    28,    29,    25,    26,    27,
      28,    29,    30,    -1,    32,     8,     9,    10,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    -1,    11,    12,    29,    14,    -1,    16,
      17,    18,    -1,    20,    13,    22,    15,    -1,    -1,    26,
      27,    28,    -1,    22,    23,    24,    25,    11,    12,    -1,
      14,    -1,    16,    17,    18,    -1,    20,    -1,    22
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,     0,     3,     6,     7,     8,     9,    10,    23,
      24,    25,    29,    40,    41,    45,    46,    47,    48,    51,
      48,    48,    35,    40,    11,    12,    14,    16,    17,    18,
      20,    22,    50,    13,    15,    46,    48,    51,    45,    47,
      51,    48,    45,    45,    46,    46,    46,    46,    46,    46,
      41,    46,    51,    51,    22,    48,    45,    26,    27,    28,
      49,    46,    48,    43,    44,    47,    49,    51,    49,    49,
      41,    43,    49,    51,    49,    51,    36,    49,    51,    49,
      41,    48,    48,    49,    48,    45,    44,    22,    41,    45,
      41,    48,    41,    45,    49,    49,    41,    49,    34,    42,
      49,    48,    41,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    40,    40,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    42,    42,    43,    43,    44,
      44,    44,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    46,    46,    46,    47,
      48,    48,    48,    49,    49,    49,    50,    51,    51,    51,
      51
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     1,     2,     1,     5,     7,     8,
       7,     3,     4,     8,     7,     0,     4,     1,     3,     0,
       2,     1,     1,     3,     3,     3,     3,     3,     3,     4,
       3,     3,     3,     2,     5,     6,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

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
  case 3:
#line 135 "parser.y"
    { imprimir_arvore((yyvsp[-1].no)); 
                            printf("\n");
                            imprimir_tabela_de_simbolos(tabela_de_simbolos);
                            printf("\n"); }
#line 1391 "parser.tab.c"
    break;

  case 4:
#line 141 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*) * 1);
                            filhos[0] = (yyvsp[0].no);

                            (yyval.no) = novo_no("stmt", filhos, 1);
}
#line 1402 "parser.tab.c"
    break;

  case 5:
#line 147 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*) * 2);
                            filhos[0] = (yyvsp[-1].no);
                            filhos[1] = (yyvsp[0].no);

                            (yyval.no) = novo_no("stmts", filhos, 2);
    }
#line 1414 "parser.tab.c"
    break;

  case 7:
#line 157 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*) * 3);
                            filhos[0] = novo_no("if", NULL, 0);
                            filhos[1] = (yyvsp[-2].no);
                            filhos[2] = (yyvsp[0].no);

                            (yyval.no) = novo_no("stmt", filhos, 3);
    }
#line 1427 "parser.tab.c"
    break;

  case 8:
#line 165 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*) * 3);
                            filhos[0] = novo_no("if", NULL, 0);
                            filhos[1] = (yyvsp[-4].no);
                            filhos[2] = (yyvsp[-2].no);

                            (yyval.no) = novo_no("stmt", filhos, 3);
    }
#line 1440 "parser.tab.c"
    break;

  case 9:
#line 173 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*) * 3);
                            filhos[0] = novo_no("if", NULL, 0);
                            filhos[1] = (yyvsp[-5].no);
                            filhos[2] = (yyvsp[-3].no);

                            (yyval.no) = novo_no("stmt", filhos, 3);
    }
#line 1453 "parser.tab.c"
    break;

  case 10:
#line 181 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*) * 3);
                            filhos[0] = novo_no("while", NULL, 0);
                            filhos[1] = (yyvsp[-4].no);
                            filhos[2] = (yyvsp[-1].no);

                            (yyval.no) = novo_no("stmt", filhos, 3);
    }
#line 1466 "parser.tab.c"
    break;

  case 11:
#line 189 "parser.y"
    {                          
                            No** filhos = (No**) malloc(sizeof(No*));
                            filhos[0] = novo_no((yyvsp[-2].no), NULL, 0);
                            (yyval.no) = novo_no("funcao", filhos, 1); 
    }
#line 1476 "parser.tab.c"
    break;

  case 12:
#line 194 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*) * 2);
                            filhos[0] = (yyvsp[-3].no);
                            filhos[1] = (yyvsp[-1].no);

                            (yyval.no) = novo_no("funcao", filhos, 2);
    }
#line 1488 "parser.tab.c"
    break;

  case 13:
#line 201 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*) * 4);
                            filhos[0] = novo_no((yyvsp[-6].no), NULL, 0);
                            filhos[1] = (yyvsp[-4].no);
                            filhos[2] = (yyvsp[-3].no);
                            filhos[3] = (yyvsp[-1].no);

                            (yyval.no) = novo_no("funcao", filhos, 4);
    }
#line 1502 "parser.tab.c"
    break;

  case 14:
#line 210 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*) * 2);
                            filhos[0] = novo_no((yyvsp[-5].no), NULL, 0);
                            filhos[1] = (yyvsp[-1].no);

                            (yyval.no) = novo_no("funcao", filhos, 2);
    }
#line 1514 "parser.tab.c"
    break;

  case 16:
#line 219 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*) * 2);
                            filhos[0] = novo_no("if", NULL, 0);
                            filhos[1] = (yyvsp[-1].no);

                            (yyval.no) = novo_no("stmt", filhos, 2);
    }
#line 1526 "parser.tab.c"
    break;

  case 17:
#line 227 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*) * 1);
                            filhos[0] = (yyvsp[0].no);

                            (yyval.no) = novo_no("args", filhos, 1);
}
#line 1537 "parser.tab.c"
    break;

  case 18:
#line 233 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*) * 2);
                            filhos[0] = (yyvsp[-2].no);
                            filhos[1] = (yyvsp[0].no);

                            (yyval.no) = novo_no("args", filhos, 2);

}
#line 1550 "parser.tab.c"
    break;

  case 20:
#line 243 "parser.y"
    {
                        No** filhos = (No**) malloc(sizeof(No*) * 2);
                        filhos[0] = (yyvsp[-1].no);
                        filhos[1] = novo_no((yyvsp[0].no), NULL, 0);;

                        (yyval.no) = novo_no("arg", filhos, 2);
    }
#line 1562 "parser.tab.c"
    break;

  case 21:
#line 250 "parser.y"
    {
                        No** filhos = (No**) malloc(sizeof(No*) * 1);
                        filhos[0] = (yyvsp[0].no);

                        (yyval.no) = novo_no("arg", filhos, 1);
    }
#line 1573 "parser.tab.c"
    break;

  case 23:
#line 257 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = (yyvsp[-2].no);
                            filhos[1] = novo_no("+", NULL, 0);
                            filhos[2] = (yyvsp[0].no);

                            (yyval.no) = novo_no("exp", filhos, 3);
                            }
#line 1586 "parser.tab.c"
    break;

  case 24:
#line 265 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = (yyvsp[-2].no);
                            filhos[1] = novo_no("-", NULL, 0);
                            filhos[2] = (yyvsp[0].no);

                            (yyval.no) = novo_no("exp", filhos, 3);
                            }
#line 1599 "parser.tab.c"
    break;

  case 25:
#line 273 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = (yyvsp[-2].no);
                            filhos[1] = novo_no("&&", NULL, 0);
                            filhos[2] = (yyvsp[0].no);

                            (yyval.no) = novo_no("exp", filhos, 3);
    }
#line 1612 "parser.tab.c"
    break;

  case 26:
#line 281 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = (yyvsp[-2].no);
                            filhos[1] = novo_no("||", NULL, 0);
                            filhos[2] = (yyvsp[0].no);

                            (yyval.no) = novo_no("exp", filhos, 3);
    }
#line 1625 "parser.tab.c"
    break;

  case 27:
#line 289 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = (yyvsp[-2].no);
                            filhos[1] = novo_no("==", NULL, 0);
                            filhos[2] = (yyvsp[0].no);

                            (yyval.no) = novo_no("exp", filhos, 3);
    }
#line 1638 "parser.tab.c"
    break;

  case 28:
#line 297 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = (yyvsp[-2].no);
                            filhos[1] = novo_no("!=", NULL, 0);
                            filhos[2] = (yyvsp[0].no);

                            (yyval.no) = novo_no("exp", filhos, 3);
    }
#line 1651 "parser.tab.c"
    break;

  case 29:
#line 305 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*)*4);
                            filhos[0] = (yyvsp[-3].no);
                            filhos[1] = (yyvsp[-2].no);
                            filhos[2] = novo_no("=", NULL, 0);
                            filhos[3] = (yyvsp[0].no);

                            for(int i = 0; i < prox_posicao_livre; i++){
                                if(!strcmp((yyvsp[-2].no), tabela_de_simbolos[i].lexema)){
                                    printf("Variavel ja declarada! %s", (yyvsp[-2].no));
                                    return;
                                }
                            }

                            RegistroTS registro;
                            strncpy(registro.token, "ID", 50);
                            strncpy(registro.lexema, (yyvsp[-2].no), 50);
                            strncpy(registro.tipo, (yyvsp[-3].no), 50);
                            registro.endereco = prox_mem_livre;
                            inserir_na_tabela_de_simbolos(registro);
                            prox_mem_livre += 4;

                            (yyval.no) = novo_no("exp", filhos, 4);
    }
#line 1680 "parser.tab.c"
    break;

  case 30:
#line 329 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = (yyvsp[-2].no);
                            filhos[1] = novo_no("=", NULL, 0);
                            filhos[2] = (yyvsp[0].no);

                            (yyval.no) = novo_no("exp", filhos, 3);
    }
#line 1693 "parser.tab.c"
    break;

  case 31:
#line 337 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = (yyvsp[-2].no);
                            filhos[1] = (yyvsp[-1].no);
                            filhos[2] = (yyvsp[0].no);

                            (yyval.no) = novo_no("exp", filhos, 3);
    }
#line 1706 "parser.tab.c"
    break;

  case 32:
#line 345 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = (yyvsp[-2].no);
                            filhos[1] = (yyvsp[-1].no);
                            filhos[2] = (yyvsp[0].no);

                            (yyval.no) = novo_no("exp", filhos, 3);  
    }
#line 1719 "parser.tab.c"
    break;

  case 33:
#line 353 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*)*2);
                            filhos[0] = (yyvsp[-1].no);
                            filhos[1] = (yyvsp[0].no);

                            for(int i = 0; i < prox_posicao_livre; i++){
                                if(!strcmp((yyvsp[0].no), tabela_de_simbolos[i].lexema)){
                                    printf("Variavel ja declarada! %s", (yyvsp[0].no));
                                    return;
                                }
                            }
                            RegistroTS registro;
                            strncpy(registro.token, "ID", 50);
                            strncpy(registro.lexema, (yyvsp[0].no), 50);
                            strncpy(registro.tipo, (yyvsp[-1].no), 50);
                            registro.endereco = prox_mem_livre;
                            inserir_na_tabela_de_simbolos(registro);
                            if(strcmp((yyvsp[-1].no), "int") == 0){
                                prox_mem_livre += 4;
                                break;
                            }
                            if(strcmp((yyvsp[-1].no), "int") == -3){
                                prox_mem_livre += 32;
                                break;
                            }
                            if(strcmp((yyvsp[-1].no), "int") == -5){
                                prox_mem_livre += 64;
                                break;
                            }
                            if(strcmp((yyvsp[-1].no), "int") == -6){
                                prox_mem_livre += 4;
                                break;
                            }
                            

                            (yyval.no) = novo_no("exp", filhos, 2);  
    }
#line 1761 "parser.tab.c"
    break;

  case 34:
#line 390 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = (yyvsp[-4].no);
                            filhos[1] = (yyvsp[-2].no);
                            filhos[2] = (yyvsp[0].no);

                            for(int i = 0; i < prox_posicao_livre; i++){
                                if(!strcmp((yyvsp[0].no), tabela_de_simbolos[i].lexema)){
                                    printf("Variavel ja declarada! %s", (yyvsp[0].no));
                                    return;
                                }
                            }
                            RegistroTS registro;
                            strncpy(registro.token, "ID", 50);
                            strncpy(registro.lexema, (yyvsp[0].no), 50);
                            strncpy(registro.tipo, (yyvsp[-4].no), 50);
                            registro.endereco = prox_mem_livre;
                            inserir_na_tabela_de_simbolos(registro);
                            if(strcmp((yyvsp[-4].no), "int") == 0){
                                prox_mem_livre += (4 * atoi((yyvsp[-2].no)));
                                break;
                            }
                            if(strcmp((yyvsp[-4].no), "int") == -3){
                                prox_mem_livre += (32 * atoi((yyvsp[-2].no)));
                                break;
                            }
                            if(strcmp((yyvsp[-4].no), "int") == -5){
                                prox_mem_livre += (64 * atoi((yyvsp[-2].no)));
                                break;
                            }
                            if(strcmp((yyvsp[-4].no), "int") == -6){
                                prox_mem_livre += (4 * atoi((yyvsp[-2].no)));
                                break;
                            }

                            (yyval.no) = novo_no("exp", filhos, 3);  
    }
#line 1803 "parser.tab.c"
    break;

  case 35:
#line 427 "parser.y"
    {
                            No** filhos = (No**) malloc(sizeof(No*)*4);
                            filhos[0] = (yyvsp[-4].no);
                            filhos[1] = (yyvsp[-2].no);
                            filhos[2] = novo_no("=", NULL, 0);
                            filhos[3] = (yyvsp[0].no);

                            (yyval.no) = novo_no("exp", filhos, 4);
    }
#line 1817 "parser.tab.c"
    break;

  case 37:
#line 439 "parser.y"
    {
                                No** filhos = (No**) malloc(sizeof(No*)*3);
                                filhos[0] = (yyvsp[-2].no);
                                filhos[1] = novo_no("*", NULL, 0);
                                filhos[2] = (yyvsp[0].no);

                                (yyval.no) = novo_no("termo", filhos, 3);


                                }
#line 1832 "parser.tab.c"
    break;

  case 38:
#line 449 "parser.y"
    {
                                No** filhos = (No**) malloc(sizeof(No*)*3);
                                filhos[0] = (yyvsp[-2].no);
                                filhos[1] = novo_no("/", NULL, 0);
                                filhos[2] = (yyvsp[0].no);

                                (yyval.no) = novo_no("termo", filhos, 3);
                                }
#line 1845 "parser.tab.c"
    break;

  case 39:
#line 460 "parser.y"
    { (yyval.no) = novo_no((yyvsp[0].simbolo), NULL, 0); }
#line 1851 "parser.tab.c"
    break;

  case 40:
#line 462 "parser.y"
    { (yyval.no) = novo_no((yyvsp[0].simbolo), NULL, 0); }
#line 1857 "parser.tab.c"
    break;

  case 41:
#line 463 "parser.y"
    { (yyval.no) = novo_no((yyvsp[0].simbolo), NULL, 0); }
#line 1863 "parser.tab.c"
    break;

  case 42:
#line 464 "parser.y"
    { (yyval.no) = novo_no((yyvsp[0].simbolo), NULL, 0); }
#line 1869 "parser.tab.c"
    break;

  case 43:
#line 466 "parser.y"
    { (yyval.no) = novo_no((yyvsp[0].simbolo), NULL, 0); }
#line 1875 "parser.tab.c"
    break;

  case 44:
#line 467 "parser.y"
    { (yyval.no) = novo_no((yyvsp[0].simbolo), NULL, 0); }
#line 1881 "parser.tab.c"
    break;

  case 45:
#line 468 "parser.y"
    { (yyval.no) = novo_no((yyvsp[0].simbolo), NULL, 0); }
#line 1887 "parser.tab.c"
    break;

  case 46:
#line 470 "parser.y"
    { (yyval.no) = novo_no((yyvsp[0].simbolo), NULL, 0); }
#line 1893 "parser.tab.c"
    break;

  case 47:
#line 472 "parser.y"
    { (yyval.no) = novo_no((yyvsp[0].simbolo), NULL, 0);}
#line 1899 "parser.tab.c"
    break;

  case 48:
#line 473 "parser.y"
    { (yyval.no) = novo_no((yyvsp[0].simbolo), NULL, 0); }
#line 1905 "parser.tab.c"
    break;

  case 49:
#line 474 "parser.y"
    { (yyval.no) = novo_no((yyvsp[0].simbolo), NULL, 0); }
#line 1911 "parser.tab.c"
    break;

  case 50:
#line 475 "parser.y"
    { (yyval.no) = novo_no((yyvsp[0].simbolo), NULL, 0); }
#line 1917 "parser.tab.c"
    break;


#line 1921 "parser.tab.c"

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 478 "parser.y"


/* Código C geral, será adicionado ao final do código fonte 
 * C gerado.
 */

No* allocar_no(int num_filhos) {
    return (No*) malloc(sizeof(No)* num_filhos);
}

void liberar_no(No* no) {
    free(no);
}

No* novo_no(char token[50], No** filhos, int num_filhos) {
    No* no = allocar_no(1);    
    snprintf(no->token, 50, "%s", token);
    no->num_filhos= num_filhos;
    no->filhos = filhos;

    return no;
}

void imprimir_arvore(No* raiz) {
    
     if(raiz->filhos != NULL) {
        printf("[%s", raiz->token);
        for(int i = 0; i < raiz->num_filhos; i++) {
            imprimir_arvore(raiz->filhos[i]);
        }
        printf("]");
    }
    else {
        printf("[%s]", raiz->token);
    }
}

void inserir_na_tabela_de_simbolos(RegistroTS registro) {
    if (prox_posicao_livre == TAM_TABELA_DE_SIMBOLOS) {
        printf("Erro! Tabela de Símbolos Cheia!");
        return;
    }
    tabela_de_simbolos[prox_posicao_livre] = registro;
    prox_posicao_livre++;
}

void imprimir_tabela_de_simbolos(RegistroTS *tabela_de_simbolos) {
    printf("----------- Tabela de Símbolos ---------------\n");
    for(int i = 0; i < prox_posicao_livre; i++) {
        printf("{%s} -> {%s} -> {%s} -> {%x}\n", tabela_de_simbolos[i].token, \
                                               tabela_de_simbolos[i].lexema, \
                                               tabela_de_simbolos[i].tipo, \
                                               tabela_de_simbolos[i].endereco);
        printf("---------\n");
    }
    printf("----------------------------------------------\n");
    printf("%d - %d", prox_mem_livre, prox_posicao_livre);
}

int main(int argc, char** argv) {
    yyparse();
}

yyerror(char *s) {
    fprintf(stderr, "error: %s\n", s);
}

