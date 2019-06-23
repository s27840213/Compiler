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
#line 2 "compiler_hw3.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex


FILE *file; // To generate .j file for Jasmin

/* Symbol table function - you can add new function if needed. */
void set_type(int);
void set_parameter();
int lookup_symbol(char*);
void create_symbol();
void insert_symbol(char*,int,int);
void dump_symbol();
int get_stack_num(char*);
int get_symbol_index(char*);
int get_symbol_type(char*);
float get_symbol_value(char*);
int getParam();
int getParamNum();
int check_global(char*);
void set_value(char*,float);
char* type2str(int);
/* code generation functions, just an example! */
void gencode_function();
void gencode_load();
void gencode_ADD(float left[7],float right[7]);
void gencode_SUB(float left[7],float right[7]);
void gencode_MUL(float left[7],float right[7]);
void gencode_DIV(float left[7],float right[7]);
void gencode_MOD(float left[7],float right[7]);
void gencode_INC(float var[7]);
void gencode_DEC(float var[7]);
void gencode_function_call(char*,int);
void gencode_print();
void gencode_assign();
void gencode_compare();
void gencode_store();





typedef struct symbol_table{
    //from 0~
    int index;
    char* name;
    // 1:variable 2:function 3:parameter
    char *kind;
    // 1:int 2:float 3:bool 4:string 5:void
    char *type;
    // from 0~
    int scope;
    // 1:int 2:float 3:bool 4:string 5:void
    char *attribute;
    float value;
    char *string_value;
    int param_n;
    int param_a[128];
    struct symbol_table* next;
    struct symbol_table* prev;
}symbol_table;

typedef struct id_list{
    char* id;
    struct id_list* next;
    struct id_list* prev;
}id_list;
int scope_num = 0;
int index_num = 0;
int decl_count = 0;
int dump_flag = -1;
int param_num = 0;
char error_buf[128];
char param_array[512];
char curr_func[128];
int curr_func_type=0;
int isMain = 0;
char string_buf[128];
int semantic_error_flag=0;
int syntax_error_flag=0;
int error_flag=0;
int cmp_num=0;
int while_count=0;
int ret_type=5;
int func_undecl_flag = 0;
int func_call_param_num = 0;
int if_end_num = 0;
int while_num = 0;
int while_end_num = 0;
int while_flag = 0;
int param_buffer[64];
symbol_table *head;
symbol_table *tail;
symbol_table *record;
symbol_table *curr;
id_list *id_head;
id_list *id_tail;
void yyerror(char*);
void print_error(char*,char*);
void print_test();
void clear_symbol(int);
void need_dump(int);
char* search_id();


#line 178 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ADD = 258,
    SUB = 259,
    MUL = 260,
    DIV = 261,
    MOD = 262,
    INC = 263,
    DEC = 264,
    MT = 265,
    LT = 266,
    MTE = 267,
    LTE = 268,
    EQ = 269,
    NE = 270,
    ASGN = 271,
    ADDASGN = 272,
    SUBASGN = 273,
    MULASGN = 274,
    DIVASGN = 275,
    MODASGN = 276,
    AND = 277,
    OR = 278,
    NOT = 279,
    LB = 280,
    RB = 281,
    LCB = 282,
    RCB = 283,
    LSB = 284,
    RSB = 285,
    COMMA = 286,
    SEMICOLON = 287,
    PRINT = 288,
    IF = 289,
    ELSE = 290,
    FOR = 291,
    WHILE = 292,
    VOID = 293,
    INT = 294,
    FLOAT = 295,
    STRING = 296,
    BOOL = 297,
    TRUE = 298,
    FALSE = 299,
    RETURN = 300,
    ENDFILE = 301,
    I_CONST = 302,
    F_CONST = 303,
    STRING_TEXT = 304,
    ID = 305
  };
#endif
/* Tokens.  */
#define ADD 258
#define SUB 259
#define MUL 260
#define DIV 261
#define MOD 262
#define INC 263
#define DEC 264
#define MT 265
#define LT 266
#define MTE 267
#define LTE 268
#define EQ 269
#define NE 270
#define ASGN 271
#define ADDASGN 272
#define SUBASGN 273
#define MULASGN 274
#define DIVASGN 275
#define MODASGN 276
#define AND 277
#define OR 278
#define NOT 279
#define LB 280
#define RB 281
#define LCB 282
#define RCB 283
#define LSB 284
#define RSB 285
#define COMMA 286
#define SEMICOLON 287
#define PRINT 288
#define IF 289
#define ELSE 290
#define FOR 291
#define WHILE 292
#define VOID 293
#define INT 294
#define FLOAT 295
#define STRING 296
#define BOOL 297
#define TRUE 298
#define FALSE 299
#define RETURN 300
#define ENDFILE 301
#define I_CONST 302
#define F_CONST 303
#define STRING_TEXT 304
#define ID 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 117 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    double f_val;
    char* string;
    //0: value  1:type  2: stack num(global->index) 3:global or not
    float var_info[7]; 

#line 326 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 343 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   677

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   187,   187,   188,   192,   193,   198,   199,   202,   203,
     204,   205,   210,   280,   353,   360,   366,   374,   381,   391,
     397,   411,   419,   425,   434,   439,   444,   449,   454,   460,
     468,   474,   480,   485,   491,   499,   513,   526,   539,   552,
     564,   570,   579,   588,   589,   590,   591,   592,   595,   596,
     599,   611,   622,   635,   636,   642,   647,   654,   662,   672,
     678,   686,   687,   696,   697,   700,   707,   716,   717,   726,
     727,   729,   736,   739,   740,   741,   744,   745,   746,   769,
     775,   782,   783,   787,   790,   793,   796,   799,   802,   807,
     824,   828,   832,   837,   840,   848,   860,   875,   905,   963,
     964,   967,   974,   985,  1000,  1022,  1027,  1081,  1087,  1088,
    1089,  1090,  1091,  1092,  1095,  1096
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "DIV", "MOD", "INC",
  "DEC", "MT", "LT", "MTE", "LTE", "EQ", "NE", "ASGN", "ADDASGN",
  "SUBASGN", "MULASGN", "DIVASGN", "MODASGN", "AND", "OR", "NOT", "LB",
  "RB", "LCB", "RCB", "LSB", "RSB", "COMMA", "SEMICOLON", "PRINT", "IF",
  "ELSE", "FOR", "WHILE", "VOID", "INT", "FLOAT", "STRING", "BOOL", "TRUE",
  "FALSE", "RETURN", "ENDFILE", "I_CONST", "F_CONST", "STRING_TEXT", "ID",
  "$accept", "program", "stats", "stats_in_func", "stat",
  "declaration_stat", "initializer", "p3_arithmetic_stat",
  "p2_arithmetic_stat", "p1_arithmetic_stat", "value_stat", "value",
  "string_text", "type", "compound_stat", "while_stat", "while_begin",
  "while_stat_part1", "while_stat_part2", "if_else_stat", "if_stat",
  "if_part1", "if_part2", "else_if_stat", "else_if_part1", "else_if_part2",
  "else_stat", "else_part1", "else_part2", "expression_stat",
  "assign_stat", "assign_op", "func_call", "func_call_param", "print_func",
  "func_declaration", "func_part1", "func_part2", "func_part3", "param",
  "logic_stats", "logic_stat", "compare_op", "logic_op", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -82

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-82)))

#define YYTABLE_NINF -108

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     524,    59,    59,   577,   577,   588,   -23,   -20,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   551,   -82,   -82,   -82,
     624,   152,   -82,   -82,   -82,    36,    76,    44,   -82,   -82,
     -82,   -33,   -82,   -82,    -5,   200,   -82,    22,   227,   -82,
      38,    10,   -82,   -82,   125,    59,    42,   -82,   -82,   -82,
     588,    44,    44,     7,    53,     4,   622,    59,   -82,    55,
      36,   -82,   -82,   -82,   -82,   -82,   -82,   588,   588,   -82,
     -82,   603,   603,   577,   577,   577,   -82,   -82,    18,    59,
     524,   -82,   -82,   -82,    51,    56,   254,   -82,   281,   308,
     -82,   -82,    43,   -82,   614,   -82,   -82,   -82,    45,     5,
      23,     4,    21,   117,   -82,   -82,    70,    71,   207,    49,
     -82,   -82,    15,   201,    75,    54,    36,   588,    76,    76,
      44,    44,    44,   588,   -82,   -82,    90,   335,   -82,    79,
     -82,   -82,   362,   -82,   -82,   -82,   524,   -82,   -82,   -82,
     -82,   389,    -1,    74,   -82,   416,   -82,   -82,   -82,   635,
     -82,    82,    86,   -82,   -82,   -82,   -82,   -82,   -82,    59,
     -82,   -82,   -82,    59,   588,   -82,    88,   -82,   -82,   -82,
      59,   -82,   443,   470,   -82,   -82,   497,    61,   -82,   -82,
     -82,    54,   -82,   -82,   108,   -82,   -82,   -82,   -82,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      42,    42,    42,    42,    42,    42,     0,     0,    51,    47,
      43,    44,    46,    45,    37,    38,    42,    35,    36,    41,
      39,    42,     3,     4,     8,    81,    17,    22,    28,    33,
      32,     0,     9,    49,     0,    42,    48,    58,    42,    10,
       0,    40,    11,     5,     0,    42,    39,    30,    40,    31,
      42,    24,    25,     0,    17,    28,    42,    42,    79,     0,
      14,    83,    84,    85,    86,    87,    88,    42,    42,     1,
       2,    42,    42,    42,    42,    42,    26,    27,     0,    42,
      42,    55,    53,    50,    72,     0,    42,    57,    42,    42,
      64,    61,     0,    59,    42,    76,    77,    97,     0,     0,
       0,     0,     0,    18,    23,    34,     0,     0,   107,     0,
     105,    78,    91,    28,     0,    92,    80,    42,    15,    16,
      19,    20,    21,    42,    96,    13,     0,    42,     7,     0,
      72,    56,    42,    70,    67,    65,    42,    75,    73,    71,
      63,    42,     0,    82,   102,    42,    99,    95,    98,     0,
      29,     0,     0,   108,   109,   110,   111,   112,   113,    42,
     114,   115,    60,    42,    42,    89,     0,    52,    54,     6,
      42,    69,    42,    42,    62,   101,    42,     0,    93,    94,
     106,   104,    90,    12,     0,    68,    74,   100,   103,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -82,   -82,   -12,   -81,     6,   -82,    12,    -2,     2,    25,
      11,    73,    81,     1,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,    57,   -82,   -82,   -82,
      46,   -82,     0,   -26,   -82,   -82,   -82,   -82,   -82,   -82,
     -53,   -82,   -82,   -82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,    22,   127,   128,    24,    59,    25,    26,    27,
      28,    29,    30,    92,    32,    33,    34,    35,    83,    36,
      37,    38,    93,    85,    86,   135,    87,    88,   139,    39,
      40,    68,    48,   114,    42,    43,    44,    99,   147,   100,
     115,   110,   159,   163
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    31,    56,    53,   109,    57,    23,    54,   141,    70,
      71,    72,    47,    49,    60,   123,    55,    78,    71,    72,
      79,    41,    31,    82,    71,    72,   126,    23,    51,    52,
     105,   125,   145,   103,   123,    41,    31,   146,    41,    71,
      72,    23,    96,   124,    91,    98,   164,   150,   102,   148,
     125,   172,    76,    77,   149,   173,   101,    84,    73,    74,
      75,    55,     1,     2,   176,   112,   116,    67,   108,    94,
      95,   160,   161,   118,   119,   162,   160,   161,   113,   104,
      41,    73,    74,    75,    45,   129,    41,   111,    41,    41,
     108,   130,   134,   142,   138,   144,   151,   152,   120,   121,
     122,   165,    14,    15,   170,    94,    17,    18,    19,    46,
     181,   188,   160,   161,   178,   102,   167,   184,   179,    54,
     183,    60,   -29,   -29,   -29,   -29,   -29,    41,    55,   106,
     160,   161,    41,   169,   189,   166,    41,   107,   182,     0,
     143,    41,   131,     0,     0,    41,     0,   169,     0,     0,
     177,    97,    69,     0,     0,     1,     2,     0,     0,     0,
       3,     4,   112,     9,    10,    11,    12,    13,     0,     0,
     180,     0,    41,    41,   108,   113,    41,     5,   169,   169,
       0,   108,   169,     0,     0,     6,     7,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     0,    17,
      18,    19,    20,     1,     2,     0,     0,     0,     3,     4,
       0,   153,   154,   155,   156,   157,   158,   153,   154,   155,
     156,   157,   158,  -107,  -107,     5,     0,    80,     0,     0,
       1,     2,    81,     6,     7,     3,     4,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     0,    17,    18,    19,
      20,     0,     5,     0,    89,     0,     0,     1,     2,    90,
       6,     7,     3,     4,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,    17,    18,    19,    20,     0,     5,
       0,   132,     0,     0,     1,     2,   133,     6,     7,     3,
       4,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       0,    17,    18,    19,    20,     0,     5,     0,   136,     0,
       0,     1,     2,   137,     6,     7,     3,     4,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     0,    17,    18,
      19,    20,     0,     5,     0,     0,   140,     0,     1,     2,
       0,     6,     7,     3,     4,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     0,    17,    18,    19,    20,     0,
       5,     0,     0,   168,     0,     1,     2,     0,     6,     7,
       3,     4,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    17,    18,    19,    20,     0,     5,     0,     0,
     171,     0,     1,     2,     0,     6,     7,     3,     4,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     0,    17,
      18,    19,    20,     0,     5,     0,     0,   174,     0,     1,
       2,     0,     6,     7,     3,     4,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     0,    17,    18,    19,    20,
       0,     5,     0,     0,   175,     0,     1,     2,     0,     6,
       7,     3,     4,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     0,    17,    18,    19,    20,     0,     5,     0,
       0,   185,     0,     1,     2,     0,     6,     7,     3,     4,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
      17,    18,    19,    20,     0,     5,     0,     0,   186,     0,
       1,     2,     0,     6,     7,     3,     4,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     0,    17,    18,    19,
      20,     0,     5,     0,     0,   187,     0,     1,     2,     0,
       6,     7,     3,     4,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,    17,    18,    19,    20,     0,     5,
       0,     0,     0,     0,     1,     2,     0,     6,     7,     3,
       4,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       0,    17,    18,    19,    20,     0,     5,     0,     0,     0,
       1,     2,     0,    58,     0,     3,     4,     0,     0,     0,
       0,     1,     2,     0,    14,    15,     3,     4,    17,    18,
      19,    46,    50,     0,     0,     0,     1,     2,     0,     0,
       0,     3,     4,     5,     0,     0,     0,     1,     2,     0,
      14,    15,     3,     4,    17,    18,    19,    46,   117,     0,
       0,    14,    15,     0,     0,    17,    18,    19,    46,     5,
      61,    62,    63,    64,    65,    66,    14,    15,     0,    67,
      17,    18,    19,    46,     0,     0,     0,    14,    15,     0,
       0,    17,    18,    19,    20,    14,    15,     0,     0,    17,
      18,    19,    46,     9,    10,    11,    12,    13
};

static const yytype_int16 yycheck[] =
{
       0,     0,    25,     5,    57,    25,     0,     5,    89,    21,
       3,     4,     1,     2,    16,    16,     5,    50,     3,     4,
      25,    21,    21,    35,     3,     4,    79,    21,     3,     4,
      26,    32,    27,    26,    16,    35,    35,    32,    38,     3,
       4,    35,    32,    25,    38,    44,    31,    26,    50,    26,
      32,   132,     8,     9,    31,   136,    45,    35,     5,     6,
       7,    50,     3,     4,   145,    67,    68,    25,    57,    31,
      32,    22,    23,    71,    72,    26,    22,    23,    67,    26,
      80,     5,     6,     7,    25,    34,    86,    32,    88,    89,
      79,    35,    86,    50,    88,    50,    26,    26,    73,    74,
      75,    26,    43,    44,    25,    31,    47,    48,    49,    50,
     163,    50,    22,    23,    32,   117,    26,   170,    32,   117,
      32,   123,     5,     6,     7,     8,     9,   127,   117,    56,
      22,    23,   132,   127,    26,   123,   136,    56,   164,    -1,
      94,   141,    85,    -1,    -1,   145,    -1,   141,    -1,    -1,
     149,    26,     0,    -1,    -1,     3,     4,    -1,    -1,    -1,
       8,     9,   164,    38,    39,    40,    41,    42,    -1,    -1,
     159,    -1,   172,   173,   163,   164,   176,    25,   172,   173,
      -1,   170,   176,    -1,    -1,    33,    34,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    47,
      48,    49,    50,     3,     4,    -1,    -1,    -1,     8,     9,
      -1,    10,    11,    12,    13,    14,    15,    10,    11,    12,
      13,    14,    15,    22,    23,    25,    -1,    27,    -1,    -1,
       3,     4,    32,    33,    34,     8,     9,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    47,    48,    49,
      50,    -1,    25,    -1,    27,    -1,    -1,     3,     4,    32,
      33,    34,     8,     9,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    47,    48,    49,    50,    -1,    25,
      -1,    27,    -1,    -1,     3,     4,    32,    33,    34,     8,
       9,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    47,    48,    49,    50,    -1,    25,    -1,    27,    -1,
      -1,     3,     4,    32,    33,    34,     8,     9,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    47,    48,
      49,    50,    -1,    25,    -1,    -1,    28,    -1,     3,     4,
      -1,    33,    34,     8,     9,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    50,    -1,
      25,    -1,    -1,    28,    -1,     3,     4,    -1,    33,    34,
       8,     9,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    47,    48,    49,    50,    -1,    25,    -1,    -1,
      28,    -1,     3,     4,    -1,    33,    34,     8,     9,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    47,
      48,    49,    50,    -1,    25,    -1,    -1,    28,    -1,     3,
       4,    -1,    33,    34,     8,     9,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    47,    48,    49,    50,
      -1,    25,    -1,    -1,    28,    -1,     3,     4,    -1,    33,
      34,     8,     9,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,    48,    49,    50,    -1,    25,    -1,
      -1,    28,    -1,     3,     4,    -1,    33,    34,     8,     9,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      47,    48,    49,    50,    -1,    25,    -1,    -1,    28,    -1,
       3,     4,    -1,    33,    34,     8,     9,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    47,    48,    49,
      50,    -1,    25,    -1,    -1,    28,    -1,     3,     4,    -1,
      33,    34,     8,     9,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    47,    48,    49,    50,    -1,    25,
      -1,    -1,    -1,    -1,     3,     4,    -1,    33,    34,     8,
       9,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    47,    48,    49,    50,    -1,    25,    -1,    -1,    -1,
       3,     4,    -1,    32,    -1,     8,     9,    -1,    -1,    -1,
      -1,     3,     4,    -1,    43,    44,     8,     9,    47,    48,
      49,    50,    25,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,     8,     9,    25,    -1,    -1,    -1,     3,     4,    -1,
      43,    44,     8,     9,    47,    48,    49,    50,    25,    -1,
      -1,    43,    44,    -1,    -1,    47,    48,    49,    50,    25,
      16,    17,    18,    19,    20,    21,    43,    44,    -1,    25,
      47,    48,    49,    50,    -1,    -1,    -1,    43,    44,    -1,
      -1,    47,    48,    49,    50,    43,    44,    -1,    -1,    47,
      48,    49,    50,    38,    39,    40,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     8,     9,    25,    33,    34,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    47,    48,    49,
      50,    52,    53,    55,    56,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    70,    71,    72,    80,
      81,    83,    85,    86,    87,    25,    50,    61,    83,    61,
      25,    60,    60,    58,    59,    61,    25,    25,    32,    57,
      58,    16,    17,    18,    19,    20,    21,    25,    82,     0,
      53,     3,     4,     5,     6,     7,     8,     9,    50,    25,
      27,    32,    53,    69,    35,    74,    75,    77,    78,    27,
      32,    55,    64,    73,    31,    32,    32,    26,    64,    88,
      90,    61,    58,    26,    26,    26,    62,    63,    61,    91,
      92,    32,    58,    61,    84,    91,    58,    25,    59,    59,
      60,    60,    60,    16,    25,    32,    91,    54,    55,    34,
      35,    77,    27,    32,    55,    76,    27,    32,    55,    79,
      28,    54,    50,    81,    50,    27,    32,    89,    26,    31,
      26,    26,    26,    10,    11,    12,    13,    14,    15,    93,
      22,    23,    26,    94,    31,    26,    57,    26,    28,    55,
      25,    28,    54,    54,    28,    28,    54,    64,    32,    32,
      61,    91,    84,    32,    91,    28,    28,    28,    50,    26
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    54,    54,    55,    55,
      55,    55,    56,    56,    57,    58,    58,    58,    58,    59,
      59,    59,    59,    59,    60,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    62,    62,    62,    62,    62,
      62,    63,    63,    64,    64,    64,    64,    64,    65,    65,
      66,    67,    68,    69,    69,    69,    70,    70,    70,    71,
      72,    73,    73,    73,    73,    74,    75,    76,    76,    76,
      76,    77,    78,    79,    79,    79,    80,    80,    80,    80,
      81,    81,    81,    82,    82,    82,    82,    82,    82,    83,
      84,    84,    84,    85,    85,    86,    87,    88,    88,    89,
      89,    89,    90,    90,    91,    91,    92,    92,    93,    93,
      93,    93,    93,    93,    94,    94
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     5,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     2,     2,     2,     2,     1,     3,
       2,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     4,     1,     3,     1,     3,     2,     1,     2,
       4,     1,     3,     2,     1,     2,     5,     1,     3,     2,
       1,     2,     1,     1,     3,     1,     2,     2,     3,     2,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     4,
       3,     1,     1,     5,     5,     3,     3,     1,     2,     1,
       3,     2,     2,     4,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
        case 12:
#line 210 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(lookup_symbol((yyvsp[-3].string))!=0){
            insert_symbol((yyvsp[-3].string),1,-1);
            decl_count++;
            set_type((yyvsp[-4].i_val));
            set_value((yyvsp[-3].string),(yyvsp[-1].var_info)[0]);

            // global scope
            if(scope_num == 0){
                gencode_function(".field public static ");
                gencode_function((yyvsp[-3].string));
                gencode_function(" ");
                char tempbuf[64];
                switch((yyvsp[-4].i_val)){
                    case 1:
                        gencode_function("I = ");
                        sprintf(tempbuf, "%d", (int)(yyvsp[-1].var_info)[0]);
                        gencode_function(tempbuf);
                        gencode_function("\n");
                        break;
                    case 2:
                        gencode_function("F = ");
                        sprintf(tempbuf, "%f", (float)(yyvsp[-1].var_info)[0]);
                        gencode_function(tempbuf);
                        gencode_function("\n");
                        break;
                    case 3:
                        gencode_function("Z = ");
                        gencode_function("\n");
                        break;
                    case 4:
                        gencode_function("Ljava/lang/String; = \"");
                        gencode_function(yylval.string);
                        gencode_function("\"\n");
                        break;
                    case 5:                        
                        gencode_function("V = ");
                        sprintf(tempbuf, "%f", (float)(yyvsp[-1].var_info)[0]);
                        gencode_function(tempbuf);
                        gencode_function("\n");
                        break;
                }
            }
            else if(scope_num>0){
                char tempbuf[64];
                switch((yyvsp[-4].i_val)){
                    case 1:
                            gencode_assign((yyvsp[-3].string),1,(yyvsp[-1].var_info));

                        break;
                    case 2:
                        gencode_assign((yyvsp[-3].string),1,(yyvsp[-1].var_info));

                        break;
                    case 3:
                        gencode_assign((yyvsp[-3].string),1,(yyvsp[-1].var_info));
                        break;
                    case 4:
                        gencode_assign((yyvsp[-3].string),1,(yyvsp[-1].var_info));
                        break;
                    case 5:
                        gencode_assign((yyvsp[-3].string),1,(yyvsp[-1].var_info));
                        break;

                }
            }
        }
        else
            print_error("Redeclared variable ",(yyvsp[-3].string));
    }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 280 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(lookup_symbol((yyvsp[-1].string))!=0){
            insert_symbol((yyvsp[-1].string),1,-1);
            decl_count++;
            set_type((yyvsp[-2].i_val));
            set_value((yyvsp[-1].string),0);
            if(scope_num == 0){
                gencode_function(".field public static ");
                gencode_function((yyvsp[-1].string));
                gencode_function(" ");
                char tempbuf[64];
                switch((yyvsp[-2].i_val)){
                    case 1:
                        gencode_function("I\n");
                        break;
                    case 2:
                        gencode_function("F\n");
                        break;
                    case 3:
                        gencode_function("Z\n");
                        break;
                    case 4:
                        gencode_function("Ljava/lang/String;\n");
                        break;
                    case 5:
                        gencode_function("V\n");
                        break;
                }
            }
            if(scope_num > 0){

                char tempbuf[64];
                switch((yyvsp[-2].i_val)){
                    case 1:
                        
                        gencode_function("\tldc 0\n");
                        gencode_function("\tistore ");
                        sprintf(tempbuf,"%d\n",get_stack_num((yyvsp[-1].string)));
                        gencode_function(tempbuf);
                        break;
                    case 2:
                        gencode_function("\tldc 0\n");
                        gencode_function("i2f\n");
                        gencode_function("\tfstore ");
                        sprintf(tempbuf,"%d\n",get_stack_num((yyvsp[-1].string)));
                        gencode_function(tempbuf);
                        break;
                    case 3:
                        gencode_function("\tldc 0\n");
                        gencode_function("\tistore ");
                        sprintf(tempbuf, "%d\n", get_stack_num((yyvsp[-1].string)));
                        gencode_function("\n");
                        break;
                    case 4:
                        gencode_function("\tldc ""\n");
                        gencode_function("\tastore ");
                        sprintf(tempbuf, "%d\n", get_stack_num((yyvsp[-1].string)));
                        gencode_function(tempbuf);
                        break;
                    case 5:
                        gencode_function("\tldc 0\n");
                        gencode_function("\tistore ");
                        sprintf(tempbuf, "%d\n", get_stack_num((yyvsp[-1].string)));
                        break;
                }
            }
        }
        else
            print_error("Redeclared variable ",(yyvsp[-1].string));
    }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 353 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.var_info)[0] = (yyvsp[0].var_info)[0];  (yyval.var_info)[1] = (yyvsp[0].var_info)[1];
        (yyval.var_info)[2] = (yyvsp[0].var_info)[2];  (yyval.var_info)[3] = (yyvsp[0].var_info)[3];
    }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 360 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.var_info)[0] = (yyvsp[-2].var_info)[0] + (yyvsp[0].var_info)[0]; (yyval.var_info)[1] = ((yyvsp[-2].var_info)[1]==2 || (yyvsp[0].var_info)[1]==2)? 2:1; 
        (yyval.var_info)[2] = -1; (yyval.var_info)[3] = -1;
        gencode_ADD((yyvsp[-2].var_info),(yyvsp[0].var_info));
        gencode_store((yyvsp[-2].var_info),(yyvsp[0].var_info));
    }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 366 "compiler_hw3.y" /* yacc.c:1646  */
    {


        (yyval.var_info)[0] = (yyvsp[-2].var_info)[0] - (yyvsp[0].var_info)[0]; (yyval.var_info)[1] = ((yyvsp[-2].var_info)[1]==2 || (yyvsp[0].var_info)[1]==2)? 2:1; 
        (yyval.var_info)[2] = -1; (yyval.var_info)[3] = -1;
        gencode_SUB((yyvsp[-2].var_info),(yyvsp[0].var_info));
        gencode_store((yyvsp[-2].var_info),(yyvsp[0].var_info));
    }
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 374 "compiler_hw3.y" /* yacc.c:1646  */
    {
        
        (yyval.var_info)[0] = (yyvsp[0].var_info)[0];
        (yyval.var_info)[1] = (yyvsp[0].var_info)[1];
        (yyval.var_info)[2] = (yyvsp[0].var_info)[2];
        (yyval.var_info)[3] = (yyvsp[0].var_info)[3];
    }
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 381 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.var_info)[0] = (yyvsp[-1].var_info)[0];
        (yyval.var_info)[1] = (yyvsp[-1].var_info)[1];
        (yyval.var_info)[2] = (yyvsp[-1].var_info)[2];
        (yyval.var_info)[3] = (yyvsp[-1].var_info)[3];
    }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 391 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_MUL((yyvsp[-2].var_info),(yyvsp[0].var_info));
        gencode_store((yyvsp[-2].var_info),(yyvsp[0].var_info));
        (yyval.var_info)[0] = (yyvsp[-2].var_info)[0] * (yyvsp[0].var_info)[0]; (yyval.var_info)[1] = ((yyvsp[-2].var_info)[1]==2 || (yyvsp[0].var_info)[1]==2)? 2:1; 
        (yyval.var_info)[2] = -1; (yyval.var_info)[3] = -1;
    }
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 397 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if((yyvsp[0].var_info)[0] == 0) {
            yyerror("Divided by Zero");
            (yyval.var_info)[0] = 0;
        }
        else{
            (yyval.var_info)[0] = (yyvsp[-2].var_info)[0] / (yyvsp[0].var_info)[0]; 
        }
        (yyval.var_info)[1] = ((yyvsp[-2].var_info)[1]==2 || (yyvsp[0].var_info)[1]==2)? 2:1;
        (yyval.var_info)[2] = -1; (yyval.var_info)[3] = -1;
        gencode_DIV((yyvsp[-2].var_info),(yyvsp[0].var_info));


    }
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 411 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_MOD((yyvsp[-2].var_info),(yyvsp[0].var_info));

        (yyval.var_info)[0] = (yyvsp[-2].var_info)[0];
        (yyval.var_info)[1] = (yyvsp[-2].var_info)[1];
        (yyval.var_info)[2] = (yyvsp[-2].var_info)[2];
        (yyval.var_info)[3] = (yyvsp[-2].var_info)[3];
    }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 419 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.var_info)[0] = (yyvsp[0].var_info)[0];
        (yyval.var_info)[1] = (yyvsp[0].var_info)[1];
        (yyval.var_info)[2] = (yyvsp[0].var_info)[2];
        (yyval.var_info)[3] = (yyvsp[0].var_info)[3];
    }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 425 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.var_info)[0] = (yyvsp[-1].var_info)[0];
        (yyval.var_info)[1] = (yyvsp[-1].var_info)[1];
        (yyval.var_info)[2] = (yyvsp[-1].var_info)[2];
        (yyval.var_info)[3] = (yyvsp[-1].var_info)[3];
    }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 434 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.var_info)[0] = (yyvsp[0].var_info)[0] + 1;  (yyval.var_info)[1] = (yyvsp[0].var_info)[1];
        (yyval.var_info)[2] = (yyvsp[0].var_info)[2];      (yyval.var_info)[3] = (yyvsp[0].var_info)[3];
        gencode_INC((yyvsp[0].var_info));
    }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 439 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.var_info)[0] = (yyvsp[0].var_info)[0] - 1;  (yyval.var_info)[1] = (yyvsp[0].var_info)[1];
        (yyval.var_info)[2] = (yyvsp[0].var_info)[2];      (yyval.var_info)[3] = (yyvsp[0].var_info)[3];
        gencode_DEC((yyvsp[0].var_info));
    }
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 444 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.var_info)[0] = (yyvsp[-1].var_info)[0] + 1;  (yyval.var_info)[1] = (yyvsp[-1].var_info)[1];
        (yyval.var_info)[2] = (yyvsp[-1].var_info)[2];      (yyval.var_info)[3] = (yyvsp[-1].var_info)[3];
        gencode_INC((yyvsp[-1].var_info));
    }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 449 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.var_info)[0] = (yyvsp[-1].var_info)[0] - 1;  (yyval.var_info)[1] = (yyvsp[-1].var_info)[1];
        (yyval.var_info)[2] = (yyvsp[-1].var_info)[2];      (yyval.var_info)[3] = (yyvsp[-1].var_info)[3];
        gencode_DEC((yyvsp[-1].var_info));
    }
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 454 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.var_info)[0] = (yyvsp[0].var_info)[0];
        (yyval.var_info)[1] = (yyvsp[0].var_info)[1];
        (yyval.var_info)[2] = (yyvsp[0].var_info)[2];
        (yyval.var_info)[3] = (yyvsp[0].var_info)[3];
    }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 460 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.var_info)[0] = (yyvsp[-1].var_info)[0] - 1;  (yyval.var_info)[1] = (yyvsp[-1].var_info)[1];
        (yyval.var_info)[2] = (yyvsp[-1].var_info)[2];      (yyval.var_info)[3] = (yyvsp[-1].var_info)[3];
    }
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 468 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.var_info)[0] = (yyvsp[0].var_info)[0];
        (yyval.var_info)[1] = (yyvsp[0].var_info)[1];
        (yyval.var_info)[2] = (yyvsp[0].var_info)[2];
        (yyval.var_info)[3] = (yyvsp[0].var_info)[3];
    }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 474 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.var_info)[0] = (yyvsp[0].var_info)[0];
        (yyval.var_info)[1] = (yyvsp[0].var_info)[1];
        (yyval.var_info)[2] = (yyvsp[0].var_info)[2];
        (yyval.var_info)[3] = (yyvsp[0].var_info)[3];
    }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 480 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.var_info)[0] = -1;
        (yyval.var_info)[1] = 4;

    }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 485 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.var_info)[0] = (yyvsp[0].var_info)[0];
        (yyval.var_info)[1] = (yyvsp[0].var_info)[1];
        (yyval.var_info)[2] = (yyvsp[0].var_info)[2];
        (yyval.var_info)[3] = (yyvsp[0].var_info)[3];
    }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 491 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.var_info)[0] = (yyvsp[-1].var_info)[0];
        (yyval.var_info)[1] = (yyvsp[-1].var_info)[1];
        (yyval.var_info)[2] = (yyvsp[-1].var_info)[2];
        (yyval.var_info)[3] = (yyvsp[-1].var_info)[3];
    }
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 499 "compiler_hw3.y" /* yacc.c:1646  */
    {
        /* 
            1 : value = $1
            2 : type = int
        */ 
        (yyval.var_info)[0] = (yyvsp[0].i_val); (yyval.var_info)[1] = 1;
        (yyval.var_info)[2] = -1; (yyval.var_info)[3] = 0;
        char tempbuf[64];
        if(scope_num>0){
            sprintf(tempbuf, "\tldc %d\n", yylval.i_val);
            gencode_function(tempbuf);
        }

    }
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 513 "compiler_hw3.y" /* yacc.c:1646  */
    {
        /* 
            1 : value = $1
            2 : type = float
        */ 
        (yyval.var_info)[0] = (yyvsp[0].f_val); (yyval.var_info)[1] = 2;
        (yyval.var_info)[2] = -1; (yyval.var_info)[3] = 0;
        char tempbuf[64];
        if(scope_num>0){
            sprintf(tempbuf, "\tldc %f\n", yylval.f_val);
            gencode_function(tempbuf);
        }
    }
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 526 "compiler_hw3.y" /* yacc.c:1646  */
    {
        /* 
            1 : value = 1
            2 : type = bool
        */ 
        (yyval.var_info)[0] = 1;  (yyval.var_info)[1] = 3;
        (yyval.var_info)[2] = -1; (yyval.var_info)[3] = 0;
        char tempbuf[64];
        if(scope_num>0){
            sprintf(tempbuf, "\tldc %d\n", yylval.i_val);
            gencode_function(tempbuf);
        }
    }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 539 "compiler_hw3.y" /* yacc.c:1646  */
    {
        /* 
            1 : value = 0
            2 : type = bool
        */ 
        (yyval.var_info)[0] = 0;  (yyval.var_info)[1] = 3; 
        (yyval.var_info)[2] = -1; (yyval.var_info)[3] = 0;
        char tempbuf[64];
        if(scope_num>0){
            sprintf(tempbuf, "\tldc %d\n", yylval.i_val);
            gencode_function(tempbuf);
        }
    }
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 552 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(lookup_symbol((yyvsp[0].string))==-1){
            print_error("Undeclared Variable ",(yyvsp[0].string));
        }
        else{
                (yyval.var_info)[0] = get_symbol_value((yyvsp[0].string));
                (yyval.var_info)[1] = get_symbol_type((yyvsp[0].string));
                (yyval.var_info)[2] = get_stack_num((yyvsp[0].string));
                (yyval.var_info)[3] = check_global((yyvsp[0].string));
                gencode_load((yyval.var_info),(yyvsp[0].string));
        }
    }
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 564 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.var_info)[1] = get_symbol_type((yyvsp[0].string));
    }
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 570 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(scope_num>0){
            char tempbuf[64];
            sprintf(tempbuf, "\tldc \"%s\"\n", yylval.string);
            gencode_function(tempbuf);
        }

    }
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 579 "compiler_hw3.y" /* yacc.c:1646  */
    {
                
            if(scope_num>0){
                gencode_function("\tldc \"\"\n");
            }
        }
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 588 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val) = 1;}
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 589 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val) = 2;}
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 590 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val) = 3;}
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 591 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val) = 4;}
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 592 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val) = 5;}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 599 "compiler_hw3.y" /* yacc.c:1646  */
    {
        need_dump(scope_num);
        scope_num--;
        while_end_num--;
        char tempbuf[64];
        sprintf(tempbuf,"WHILE_EXIT_%d_%d",while_end_num,scope_num+1);
        gencode_function(tempbuf);
        gencode_function(":\n");
    }
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 611 "compiler_hw3.y" /* yacc.c:1646  */
    {
        while_num++;
        char tempbuf[64];
        sprintf(tempbuf,"L_WHILE_%d_%d",while_num,scope_num);
        gencode_function(tempbuf);
        gencode_function(":\n");

    }
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 622 "compiler_hw3.y" /* yacc.c:1646  */
    {
        ++scope_num;
        char tempbuf[64];
        sprintf(tempbuf,"\tifeq WHILE_EXIT_%d_%d",while_end_num,scope_num);
        gencode_function(tempbuf);
        gencode_function("\n");
        while_end_num++;

        }
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 636 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char tempbuf[64];
        sprintf(tempbuf,"\tgoto L_WHILE_%d_%d",while_num--,(scope_num-1));
        gencode_function(tempbuf);
        gencode_function("\n");
    }
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 647 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char tempbuf[64];
        sprintf(tempbuf,"IF_EXIT_%d",if_end_num);
        gencode_function(tempbuf);
        gencode_function(":\n");
        if_end_num++;
    }
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 654 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char tempbuf[64];
        sprintf(tempbuf,"IF_EXIT_%d",if_end_num);
        gencode_function(tempbuf);
        gencode_function(":\n");
        if_end_num++;

    }
#line 2269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 662 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char tempbuf[64];
        sprintf(tempbuf,"IF_EXIT_%d",if_end_num);
        gencode_function(tempbuf);
        gencode_function(":\n");
        if_end_num++;

    }
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 672 "compiler_hw3.y" /* yacc.c:1646  */
    {
        need_dump(scope_num);
        scope_num--;
    }
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 678 "compiler_hw3.y" /* yacc.c:1646  */
    {
        ++scope_num;
        char tempbuf[64];
        sprintf(tempbuf, "\tifeq LABLE_F_ACTION_%d\n", scope_num);
        gencode_function(tempbuf);
        }
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 687 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char tempbuf[64];
        sprintf(tempbuf, "\tgoto IF_EXIT_%d\n", if_end_num);
        gencode_function(tempbuf);
        sprintf(tempbuf,"LABLE_F_ACTION_%d",scope_num);
        gencode_function(tempbuf);
        sprintf(tempbuf,"%s",":\n");
        gencode_function(tempbuf);
    }
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 700 "compiler_hw3.y" /* yacc.c:1646  */
    {
        need_dump(scope_num);
        scope_num--;

    }
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 707 "compiler_hw3.y" /* yacc.c:1646  */
    {
        ++scope_num;
        char tempbuf[64];
        sprintf(tempbuf, "\tifeq LABLE_F_ACTION_%d\n", scope_num);
        gencode_function(tempbuf);
    }
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 717 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char tempbuf[64];
        sprintf(tempbuf, "\tgoto IF_EXIT_%d\n", if_end_num);
        gencode_function(tempbuf);
        sprintf(tempbuf,"LABLE_F_ACTION_%d",scope_num);
        gencode_function(tempbuf);
        sprintf(tempbuf,"%s",":\n");
        gencode_function(tempbuf);
    }
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 729 "compiler_hw3.y" /* yacc.c:1646  */
    {
        need_dump(scope_num);        
        scope_num--;
    }
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 736 "compiler_hw3.y" /* yacc.c:1646  */
    {++scope_num;}
#line 2366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 746 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(ret_type == 1 && (yyvsp[-1].var_info)[1] == 1){
			gencode_function("\tireturn\n");
		}
		else if(ret_type == 1 && (yyvsp[-1].var_info)[1] == 2){

            yyerror("Return type mismatch");

		}
		else if(ret_type == 2 && (yyvsp[-1].var_info)[1] == 1){
            yyerror("Return type mismatch");
		}
		else if(ret_type == 2 && (yyvsp[-1].var_info)[1] == 2){
			gencode_function("\tfreturn\n");
		}
		else if(ret_type == 3 && (yyvsp[-1].var_info)[1] == 3){
			gencode_function("\tireturn\n");
		}
		else {
			yyerror("Return Type mismatch");
		}
	
    }
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 769 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_function("\treturn\n");
    }
#line 2402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 775 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(lookup_symbol((yyvsp[-2].string))==(-1)){
            print_error("Undeclared variable ",(yyvsp[-2].string));
        }

        gencode_assign((yyvsp[-2].string),(yyvsp[-1].i_val),(yyvsp[0].var_info));
    }
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 787 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.i_val) = 1;
    }
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 790 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.i_val) = 2;
    }
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 793 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.i_val) = 3;
    }
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 796 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.i_val) = 4;
    }
#line 2446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 799 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.i_val) = 5;
    }
#line 2454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 802 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.i_val) = 6;
    }
#line 2462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 807 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(lookup_symbol((yyvsp[-3].string))==-1){
            print_error("Undeclared function ",(yyvsp[-3].string));
            func_undecl_flag = 1;
        }

        gencode_function_call((yyvsp[-3].string),func_call_param_num);
        for(int i =0;i<func_call_param_num;i++){
            if(param_buffer[i] != getParam((yyvsp[-3].string),i)){
                yyerror("Parameter type mismatch!");
            }
        }
        func_call_param_num =0;

    }
#line 2482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 824 "compiler_hw3.y" /* yacc.c:1646  */
    {
        param_buffer[func_call_param_num] = (yyvsp[-2].var_info)[1];
        func_call_param_num++;
    }
#line 2491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 828 "compiler_hw3.y" /* yacc.c:1646  */
    {
        param_buffer[func_call_param_num] = (yyvsp[0].var_info)[1];
        func_call_param_num++;
    }
#line 2500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 832 "compiler_hw3.y" /* yacc.c:1646  */
    {
        func_call_param_num++;
    }
#line 2508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 837 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_print((yyvsp[-2].var_info));
    }
#line 2516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 840 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_function("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
        gencode_function("\tswap\n");
        gencode_function("\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
    }
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 848 "compiler_hw3.y" /* yacc.c:1646  */
    {
        need_dump(scope_num);

        if(param_num>0){
            set_parameter();
        }

        scope_num--;
    }
#line 2540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 860 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(lookup_symbol((yyvsp[-1].string)) == -1){
            insert_symbol((yyvsp[-1].string), 2, (yyvsp[-2].i_val));
            fprintf(file,".method public static %s(",(yyvsp[-1].string));
            strcpy(curr_func,(yyvsp[-1].string));
            curr_func_type = (yyvsp[-2].i_val);
        }
        else print_error("Redeclared function ", (yyvsp[-1].string));
        ++scope_num;
        (yyval.i_val) = (yyvsp[-2].i_val);
        ret_type = (yyvsp[-2].i_val);
    }
#line 2557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 875 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(strcmp(curr_func,"main")==0){
            isMain=1;
            gencode_function("[Ljava/lang/String;");
            ret_type = 5;
        }
        gencode_function(")");
        isMain = 0;

        switch(curr_func_type){
            case 1:
                gencode_function("I\n");
                break;
            case 2:
                gencode_function("F\n");
                break;
            case 3:
                gencode_function("Z\n");
                break;
            case 4:
                gencode_function("Ljava/lang/String;\n");
                break;
            case 5:
                gencode_function("V\n");
                break;                
            }
        curr_func_type = 0;
        gencode_function(".limit stack 50\n");
        gencode_function(".limit locals 50\n");
    }
#line 2592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 905 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(strcmp(curr_func,"main")==0){
            isMain=1;
            gencode_function("[Ljava/lang/String;");
        }
        
        for(int i = 0;i<param_num;i++){
            switch(param_array[i]){
                case 1:
                    if(isMain == 0)
                        gencode_function("I");
                    break;
                case 2:
                    if(isMain == 0)
                        gencode_function("F");
                    break;
                case 3:
                    if(isMain == 0)
                        gencode_function("Z");
                    break;
                case 4:
                    if(isMain == 0)
                        gencode_function("Ljava/lang/String;");
                    break;
                case 5:
                    if(isMain == 0)
                        gencode_function("V");
                    break;
            }
        }
        
        gencode_function(")");
        isMain = 0;

        switch(curr_func_type){
            case 1:
                gencode_function("I\n");
                break;
            case 2:
                gencode_function("F\n");
                break;
            case 3:
                gencode_function("Z\n");
                break;
            case 4:
                gencode_function("Ljava/lang/String;\n");
                break;
            case 5:
                gencode_function("V\n");
                break;                
            }
        curr_func_type = 0;
        gencode_function(".limit stack 50\n");
        gencode_function(".limit locals 50\n");
    }
#line 2652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 964 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_function(".end method\n");
    }
#line 2660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 967 "compiler_hw3.y" /* yacc.c:1646  */
    {
            gencode_function(".end method\n");
            // yyerror("Error return type!");
    }
#line 2669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 974 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(lookup_symbol((yyvsp[0].string)) != 0){
            insert_symbol((yyvsp[0].string), 3, (yyvsp[-1].i_val));
            param_array[param_num] = (yyvsp[-1].i_val);
            ++param_num;
            decl_count++;
            set_type((yyvsp[-1].i_val));
        }
        else    print_error("Redeclared variable ", (yyvsp[0].string));

    }
#line 2685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 985 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(lookup_symbol((yyvsp[0].string)) != 0){
            insert_symbol((yyvsp[0].string), 3, (yyvsp[-1].i_val));
            param_array[param_num] = (yyvsp[-1].i_val);
            ++param_num;
            decl_count++;
            set_type((yyvsp[-1].i_val));

        }
        else    print_error("Redeclared variable ", (yyvsp[0].string));
    }
#line 2701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1000 "compiler_hw3.y" /* yacc.c:1646  */
    {
        switch((yyvsp[-1].i_val)){
            case 1:
                if((yyvsp[-2].i_val)==1 && (yyvsp[0].i_val)==1){
                    (yyval.i_val) = 1;
                }
                else{
                    (yyval.i_val) = 0;
                }
                gencode_function("\tiand\n");
                break;
            case 2:
                if((yyvsp[-2].i_val)==1 || (yyvsp[0].i_val)==1){
                    (yyval.i_val) = 1;
                }
                else{
                    (yyval.i_val) = 0;
                }
                gencode_function("\tior\n");
                break;
        }
    }
#line 2728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1022 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.i_val) = (yyvsp[0].i_val);
    }
#line 2736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1027 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_compare((yyvsp[-2].var_info),(yyvsp[0].var_info),(yyvsp[-1].i_val));
        switch((yyvsp[-1].i_val)){
            case 1:
                if((yyvsp[-2].var_info)[0]>(yyvsp[0].var_info)[0]){
                    (yyval.i_val) = 1;
                }
                else{
                    (yyval.i_val)= 0;
                }
                break;
            case 2:
                if((yyvsp[-2].var_info)[0]<(yyvsp[0].var_info)[0]){
                    (yyval.i_val) = 1;
                }
                else{
                    (yyval.i_val)= 0;
                }
                break;
            case 3:
                if((yyvsp[-2].var_info)[0]>=(yyvsp[0].var_info)[0]){
                    (yyval.i_val) = 1;
                }
                else{
                    (yyval.i_val)= 0;
                }
                break;
            case 4:
                if((yyvsp[-2].var_info)[0]<=(yyvsp[0].var_info)[0]){
                    (yyval.i_val) = 1;
                }
                else{
                    (yyval.i_val)= 0;
                }
                break;
            case 5:
                if((yyvsp[-2].var_info)[0]=(yyvsp[0].var_info)[0]){
                    (yyval.i_val) = 1;
                }
                else{
                    (yyval.i_val)= 0;
                }
                break;
            case 6:
                if((yyvsp[-2].var_info)[0]!=(yyvsp[0].var_info)[0]){
                    (yyval.i_val) = 1;
                }
                else{
                    (yyval.i_val)= 0;
                }
                break;
              
        }
    }
#line 2795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1081 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.i_val) = (int)(yyvsp[0].var_info)[0];
    }
#line 2803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1087 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val)=1;}
#line 2809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1088 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val)=2;}
#line 2815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1089 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val)=3;}
#line 2821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1090 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val)=4;}
#line 2827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1091 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val)=5;}
#line 2833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1092 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val)=6;}
#line 2839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1095 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val)=1;}
#line 2845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1096 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val)=2;}
#line 2851 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2855 "y.tab.c" /* yacc.c:1646  */
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
#line 1099 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;
    create_symbol();
    file = fopen("compiler_hw3.j","w");
    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n");
    yyparse();
    dump_symbol(scope_num);




    printf("\nTotal lines: %d \n",yylineno);
    
    fclose(file);
    if(error_flag){
        remove("compiler_hw3.j");
    }
    return 0;
}

void yyerror(char *s)
{

    error_flag=1;
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno+1, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");

    if(strcmp("syntax error",s)==0){
        remove("compiler_hw3.j");        
        exit(0);
    }
}

void create_symbol() {
    head = (symbol_table*)malloc(sizeof(symbol_table));
    head->index = -1;
    head->name = NULL;
    head->kind = NULL;
    head->type = NULL;
    head->scope = -1;
    head->attribute = NULL;
    head->next = NULL;
    head->prev = head;
    head->string_value = NULL;
    tail = head;
}
void insert_symbol(char *name,int kind,int type) {
    symbol_table *temp = tail;
    if(temp == head){
        temp->next = (symbol_table*)malloc(sizeof(symbol_table));
        temp->next->prev = temp;
        temp = temp->next;
        temp->next = NULL;
        head-> next = temp;
        tail = temp;
    }
    else{
        temp->next = (symbol_table*)malloc(sizeof(symbol_table));
        temp->next->prev = temp;
        temp = temp->next;
        temp->next = NULL;
        tail = temp;
    }

    
    temp->index = index_num;
    temp->name = (char*)malloc(sizeof(char)*strlen(name)+1);
    strncpy(temp->name, name, strlen(name));

    temp->scope = scope_num;
    switch(kind){
        case 1:
            temp->kind = (char*)malloc(sizeof(char)*strlen("variable"));
            strcpy(temp->kind,"variable");
            break;
        case 2:
            temp->kind = (char*)malloc(sizeof(char)*strlen("function"));
            strcpy(temp->kind,"function");
            break;
        case 3:
            temp->kind = (char*)malloc(sizeof(char)*strlen("parameter"));
            strcpy(temp->kind,"parameter");
            break;
        case -1:
            temp->type = (char*)malloc(sizeof(char)*strlen("default"));
            strcpy(temp->type,"default");
            break;
    }

    switch(type){
        case 1:
            temp->type = (char*)malloc(sizeof(char)*strlen("int"));
            strcpy(temp->type,"int");
            break;
        case 2:
            temp->type = (char*)malloc(sizeof(char)*strlen("float"));
            strcpy(temp->type,"float");
            break;
        case 3:
            temp->type = (char*)malloc(sizeof(char)*strlen("bool"));
            strcpy(temp->type,"bool");
            break;
        case 4:
            temp->type = (char*)malloc(sizeof(char)*strlen("string"));
            strcpy(temp->type,"string");
            break;
        case 5:
            temp->type = (char*)malloc(sizeof(char)*strlen("void"));
            strcpy(temp->type,"void");
            break;
        case -1:
            temp->type = (char*)malloc(sizeof(char)*strlen("default"));
            strcpy(temp->type,"default");
            break;
    }
    index_num ++;
}
int lookup_symbol(char *name) {
    symbol_table *temp = head;
    while(temp->next!=NULL){
        temp = temp-> next;
        if(strcmp(temp->name,name)==0 && temp->scope == scope_num) 
            return 0;
        if(strcmp(temp->name, name) == 0 && temp->scope < scope_num)
            return 1;
    }
    return -1;
}
void dump_symbol(int dump_scope_num) {

    int table_has_element_flag = 0;
    symbol_table* element = head;
    while(element->next != NULL){
        element = element->next;
        if(element->scope == dump_scope_num)
            table_has_element_flag = 1;
    }
    if(table_has_element_flag == 0) return;

    int index_count = 0;

    symbol_table* temp = head;
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
    "Index", "Name", "Kind", "Type", "Scope", "Attribute ");
    while(temp->next != NULL)
    {

        temp = temp->next;
        if(temp->scope == dump_scope_num){

		        printf("%-10d%-10s%-12s%-10s%-10d",
			    index_count, temp->name, temp->kind, temp->type, temp->scope);
                if(temp->attribute!=NULL){
                    printf("%-10s",temp-> attribute);
                }     
                    index_count++;
                    printf("\n");

        }

    }
        printf("\n");

    clear_symbol(dump_scope_num);
}
void print_test() {
	symbol_table* test = head->next;
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
       "Index", "Name", "Kind", "Type", "Scope", "Attribute");
	while(test != NULL) {
		printf("%-10d%-10s%-12s%-10s%-10d\n",
			test->index, test->name, test->kind, test->type, test->scope);
        if(test->attribute!=NULL){
            printf("%-10s",test-> attribute);
        }    
		test = test->next;
	}
}

void set_type(int type){
    symbol_table *temp = tail;


    for(int i = 0; i < decl_count;i++){
    switch(type){
        case 1:
            temp->type = (char*)malloc(sizeof(char)*strlen("int"));
            strcpy(temp->type,"int");
            break;
        case 2:
            temp->type = (char*)malloc(sizeof(char)*strlen("float"));
            strcpy(temp->type,"float");
            break;
        case 3:
            temp->type = (char*)malloc(sizeof(char)*strlen("bool"));
            strcpy(temp->type,"bool");
            break;
        case 4:
            temp->type = (char*)malloc(sizeof(char)*strlen("string"));
            strcpy(temp->type,"string");
            break;
        case 5:
            temp->type = (char*)malloc(sizeof(char)*strlen("void"));
            strcpy(temp->type,"void");
            break;
        case -1:
            temp->type = (char*)malloc(sizeof(char)*strlen("default"));
            strcpy(temp->type,"default");
            break;
    }
        temp = temp->prev;
    }
    decl_count = 0;
}

void set_value(char* name,float input){
    symbol_table *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope == scope_num){
            temp->value = input;
            return;
        }

    }   
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope < scope_num){
            temp->value = input; 
            return;
        }
    }   
}


void set_string_value(char* name,char* input){
    symbol_table *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope == scope_num){
            temp->string_value = input;
            return;
        }

    }   
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope < scope_num){
            return;
        }
    }   
}
void clear_symbol(int scope_num){
    if(scope_num != 0){
        symbol_table* temp = head;

        while(temp->next != NULL){
            temp = temp -> next;
            if(temp->scope == scope_num){
                if(temp->next != NULL){
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                else temp->prev->next = NULL;
                symbol_table* deletenode = temp;
                temp = temp -> prev;
                tail = temp;
                free(deletenode);
            }
        }

    }
}

void need_dump(int scope_num){
    dump_flag = scope_num;
}

void set_parameter(){
    symbol_table *temp = tail;
    while(strcmp(temp->kind,"function")!=0){
        temp = temp->prev;
    }

        for(int i = 0;i<param_num;i++){
            switch(param_array[i]){
                case 1:

                    if(temp->attribute==NULL)
                    {
                        temp->attribute = (char*)malloc(sizeof(char)*512);
                        strcpy(temp->attribute,"int");
                        temp->param_a[0] = 1;
                        temp->param_n++;
                    }

                    else{
                        strcat(temp->attribute,", int");
                        temp-> param_a[temp->param_n] = 1;
                        temp->param_n++;
                    }

                        
                 break;
                case 2:


                    if(temp->attribute==NULL)
                    {
                        temp->attribute = (char*)malloc(sizeof(char)*512);
                        strcpy(temp->attribute,"float");
                        temp->param_a[0] = 2;
                        temp->param_n++;
                    }

                    else{
                        strcat(temp->attribute,", float");
                        temp->param_a[temp->param_n] = 2;
                        temp->param_n++;   
                    }
              
                    break;
                case 3:


                    if(temp->attribute==NULL)
                    {
                        temp->attribute = (char*)malloc(sizeof(char)*512);
                        strcpy(temp->attribute,"bool");
                        temp->param_a[0] = 3;
                        temp->param_n++; 
                    }

                    else
                        strcat(temp->attribute,", bool");
                        temp->param_a[temp->param_n] = 3;
                        temp->param_n++; 
                    break;
                case 4:


                    if(temp->attribute==NULL){

                        temp->attribute = (char*)malloc(sizeof(char)*512);
                        strcpy(temp->attribute,"string");
                        temp->param_a[0] = 4;
                        temp->param_n++; 
                    }

                    else
                        strcat(temp->attribute,", string");
                        temp->param_a[temp->param_n] = 4;
                        temp->param_n++; 
                    break;
                case 5:

                    if(temp->attribute==NULL){
                        temp->attribute = (char*)malloc(sizeof(char)*512);
                        strcpy(temp->attribute,"void");
                        temp->param_a[0] = 5;
                        temp->param_n++; 
                    }
                    else
                        strcat(temp->attribute,", void");
                        temp->param_a[temp->param_n] = 5;
                        temp->param_n++; 
                    break;
                case -1:
                    break;
            }
    }

    param_num = 0;
    param_array[0]='\0';

}
void print_error(char* msg, char* Name){
    sprintf(error_buf, "%s%s", msg, Name);
    yyerror(error_buf);
}

void gencode_function(char* output_text){
    fprintf(file,"%s", output_text);
}

int get_symbol_index(char *name){
    symbol_table* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope == scope_num){
            return temp->index;
        }
    }   
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope < scope_num){
             return temp->index;
        }
    }  
}

int get_stack_num(char *name){
    symbol_table *temp = head;
    int return_num = 0;
    while(temp->next!=NULL){
        temp = temp->next;
        if(strcmp(temp->name,name)==0 && temp->scope <= scope_num && temp->scope>0){
            return return_num;
        }
        else if(temp->scope<=scope_num && temp->scope>0){
            return_num++;
        }
    }
    return -1;
}

void gencode_ADD(float left[7],float right[7]){
    if(left[1] == 1 && left[1] == 1){
        // int & int 
        gencode_function("\tiadd\n");
    }
    // int float
    else if(left[1]==1 &&right[1]==2){
        gencode_function("\tswap\n");
        gencode_function("\ti2f\n");
        gencode_function("\tswap\n");
        gencode_function("\tfadd\n");

    }
    // float float
    else if(left[1]==2 && right[1]==2){
        gencode_function("\tfadd\n");
    }
    else if(left[1]==2 &&right[1]==1){
        gencode_function("\ti2f\n");
        gencode_function("\tfadd\n");        
    }


}

void gencode_SUB(float left[7],float right[7]){
    if(left[1] == 1 && left[1] == 1){
        // int & int 
        gencode_function("\tisub\n");
    }
    // int float
    else if(left[1]==1 &&right[1]==2){
        gencode_function("\tswap\n");
        gencode_function("\ti2f\n");
        gencode_function("\tswap\n");
        gencode_function("\tfsub\n");

    }
    // float float
    else if(left[1]==2 && right[1]==2){
        gencode_function("\tfadd\n");
    }
    else if(left[1]==2 &&right[1]==1){
        gencode_function("\ti2f\n");
        gencode_function("\tfsub\n");        
    }

}

void gencode_MUL(float left[7],float right[7]){
    if(left[1] == 1 && left[1] == 1){
        // int & int 
        gencode_function("\timul\n");
    }
    // int float
    else if(left[1]==1 &&right[1]==2){
        gencode_function("\tswap\n");
        gencode_function("\ti2f\n");
        gencode_function("\tswap\n");
        gencode_function("\tfmul\n");

    }
    // float float
    else if(left[1]==2 && right[1]==2){
        gencode_function("\tfmul\n");
    }
    else if(left[1]==2 &&right[1]==1){
        gencode_function("\ti2f\n");
        gencode_function("\tfmul\n");        
    }

}

void gencode_DIV(float left[7],float right[7]){
    if(left[1] == 1 && left[1] == 1){
        // int & int 
        gencode_function("\tidiv\n");
    }
    // int float
    else if(left[1]==1 &&right[1]==2){
        gencode_function("\tswap\n");
        gencode_function("\ti2f\n");
        gencode_function("\tswap\n");
        gencode_function("\tfdiv\n");

    }
    // float float
    else if(left[1]==2 && right[1]==2){
        gencode_function("\tfdiv\n");
    }
    else if(left[1]==2 &&right[1]==1){
        gencode_function("\ti2f\n");
        gencode_function("\tfdiv\n");        
    }

}
void gencode_MOD(float left[7],float right[7]){
    if(left[1] == 1 && left[1] == 1){
        // int & int 
        gencode_function("\tirem\n");
    }
    else{
		yyerror("Only int can do mod");
	}
    }



void gencode_load(float data[7],char* id){
    char tempbuf[64];
    int global_flag = check_global(id);
    switch((int)data[1]){
        case 1:
            //global
            if(global_flag){
                sprintf(tempbuf, "\tgetstatic compiler_hw3/%s %s\n", id, "I");
                gencode_function(tempbuf);
            }
            else{
            	sprintf(tempbuf, "\tiload %d\n", get_stack_num(id));
                gencode_function(tempbuf);

            }
            break;
        case 2:
            if(global_flag){
                sprintf(tempbuf, "\tgetstatic compiler_hw3/%s %s\n", id, "F");
                gencode_function(tempbuf);
            }
            else{
            	sprintf(tempbuf, "\tfload %d\n", get_stack_num(id));
                gencode_function(tempbuf);

            }
            break;
        case 3:
            if(global_flag){
                sprintf(tempbuf, "\tgetstatic compiler_hw3/%s %s\n", id, "Z");
                gencode_function(tempbuf);
            }
            else{
            	sprintf(tempbuf, "\tiload %d\n", get_stack_num(id));
                gencode_function(tempbuf);

            }
            break;
        case 4:
            if(global_flag){
                sprintf(tempbuf, "\tgetstatic compiler_hw3/%s %s\n",id, "Ljava/lang/String;");
                gencode_function(tempbuf);
            }
            else{
            	sprintf(tempbuf, "\taload %d\n", get_stack_num(id));
                gencode_function(tempbuf);

            }
            break;

    }

}

void gencode_store(int type,char* name){
    char tempbuf[64];
    int isGlobal = check_global(name);
    switch(type){
        case 1:
            //global
            if(isGlobal){
                sprintf(tempbuf, "\tputstatic compiler_hw3/%s %s\n", name, "I");
                gencode_function(tempbuf);
            }
            else{
            	sprintf(tempbuf, "\tistore %d\n", get_stack_num(name));
                gencode_function(tempbuf);

            }
            break;
        case 2:
            if(isGlobal){
                sprintf(tempbuf, "\tputstatic compiler_hw3/%s %s\n", name, "F");
                gencode_function(tempbuf);
            }
            else{
                int a = get_stack_num(name);
            	sprintf(tempbuf, "\tfstore %d\n", a);
                gencode_function(tempbuf);

            }
            break;
        case 3:
            if(isGlobal){
                sprintf(tempbuf, "\tputstatic compiler_hw3/%s %s\n", name, "Z");
                gencode_function(tempbuf);
            }
            else{
            	sprintf(tempbuf, "\tistore %d\n", get_stack_num(name));
                gencode_function(tempbuf);

            }
            break;
        case 4:
            if(isGlobal){
                sprintf(tempbuf, "\tputstatic compiler_hw3/%s %s\n", name, "Ljava/lang/String");
                gencode_function(tempbuf);
            }
            else{
            	sprintf(tempbuf, "\tastore %d\n", get_stack_num(name));
                gencode_function(tempbuf);

            }
            break;
    }
}

int check_global(char* name){
    symbol_table *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
        if(strcmp(temp->name,name)==0 && temp->scope==0){
            return 1;
        }
    }
    return 0;
}

int get_symbol_type(char* name){
    symbol_table *temp = head;

    // search for temp in curr scope
    while(temp->next!=NULL){
        temp = temp->next;
        if(strcmp(temp->name,name)==0 && temp->scope==scope_num){
            int type = 0;
            if(strcmp("int",temp->type)==0)
                type = 1;
            if(strcmp("float",temp->type)==0)            
                type = 2;
            if(strcmp("bool",temp->type)==0)            
                type = 3;
            if(strcmp("string",temp->type)==0)            
                type = 4;
            if(strcmp("void",temp->type)==0)            
                type = 5;
            return type;
        }
    }
    temp = head;

    // search for temp in lower scope
    while(temp->next!=NULL){
        temp = temp->next;
        if(strcmp(temp->name,name)==0 && temp->scope<scope_num){
            int type = 0;
            if(strcmp("int",temp->type)==0)
                type = 1;
            if(strcmp("float",temp->type)==0)            
                type = 2;
            if(strcmp("bool",temp->type)==0)            
                type = 3;
            if(strcmp("string",temp->type)==0)            
                type = 4;
            if(strcmp("void",temp->type)==0)            
                type = 5;
            return type;
        }
    }
}

char* type2str(int type){
    switch(type){
        case 1:
            return "I";
        case 2:
            return "F";
        case 3:
            return "Z";
        case 4:
            return "Ljava/lang/String;";
        case 5:
            return "V";
    }
}

float get_symbol_value(char* name){
    symbol_table *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope == scope_num){
            return temp->value;
        }
    }   
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope < scope_num){
             return temp->value;
        }
    } 
}



void gencode_print(float* var){
    gencode_function("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
    gencode_function("\tswap\n");
    gencode_function("\tinvokevirtual java/io/PrintStream/println(");
    if(var[1] == 1)
        gencode_function("I)V\n");
    else if(var[1] == 2)
        gencode_function("F)V\n");
    else if(var[1] == 3)
        gencode_function("I)V\n");
    else if(var[1] == 4)
        gencode_function("Ljava/lang/String;)V\n");
    else if(var[1] == 5)
        gencode_function("I)V\n");
}

void gencode_DEC(float var[7]){
    switch((int)var[1]){
        case 1:
            gencode_function("\tldc 1\n");
			gencode_function("\tisub\n");
        break;

        case 2:
            gencode_function("\tldc 1.0\n");
		    gencode_function("\tfsub\n");
        break;
        default:
		yyerror("Only int and float can do post expression");
        break;

    }
}
void gencode_INC(float var[7]){
    char tempbuf[64];
    sprintf(tempbuf,"%d\n",(int)var[2]);
    switch((int)var[1]){
        case 1:
            gencode_function("\tldc 1\n");
			gencode_function("\tiadd\n");
            gencode_function("\tistore ");
            gencode_function(tempbuf);
        break;

        case 2:
            gencode_function("\tldc 1.0\n");
		    gencode_function("\tfadd\n");
            gencode_function("\tfsotre ");
            gencode_function(tempbuf);

        break;
        default:
		yyerror("Only int and float can do post expression");
        break;

    }




}

void gencode_function_call(char* name,int p_num){
    gencode_function("\tinvokestatic compiler_hw3/");
    gencode_function(name);
    gencode_function("(");
    int num = getParamNum(name);
    if(num !=p_num){
        yyerror("Wrong number of parameter");
    }
    int par[64];
    for(int i =0;i<num;i++){
        par[i] = getParam(name,i);
        gencode_function(type2str(par[i]));
    }
    gencode_function(")");
    gencode_function(type2str(get_symbol_type(name)));
    gencode_function("\n");

}
void gencode_assign(char*name,int assign_type,float right[7]){
    int type = get_symbol_type(name);
    float info[7];
    info[0] = get_symbol_value(name);
    info[1] = get_symbol_type(name);
    info[3] = check_global(name);
    switch(assign_type){
        case 1:
		if(right[1] == 1 && type ==1){
			gencode_store(type,name);
		}
		else if(right[1] == 1 && type == 2){
			gencode_function("\ti2f\n");
			gencode_store(type,name);

		}
		else if(right[1] == 2 && type == 2){
			gencode_store(type,name);

		}
		else if(right[1] == 2 && type == 1){
			gencode_function("\tf2i\n");
			gencode_store(type,name);
		}
		else if(right[1] == 3 && type == 3){
			gencode_store(type,name);

		}
		else if(right[1] == 4 && type == 4){
			gencode_store(type,name);

		}
		else{
            if(func_undecl_flag=0){
			    yyerror("Wrong type at assign!");
                func_undecl_flag = 0;
            }
		}
		break;
        case 2:
            gencode_load(info,name);
		    gencode_function("\tswap\n");
	    	gencode_ADD(info, right);
		    gencode_store(type,name);
            
            break;
        case 3:
            gencode_load(info,name);
		    gencode_function("\tswap\n");
	    	gencode_SUB(info, right);
		    gencode_store(type,name);
            break;
        case 4:
            gencode_load(info,name);
		    gencode_function("\tswap\n");
	    	gencode_MUL(info, right);
		    gencode_store(type,name);
            break;
        case 5:
            gencode_load(info,name);
		    gencode_function("\tswap\n");
	    	gencode_DIV(info, right);
		    gencode_store(type,name);
            break;
        case 6:
            gencode_load(info,name);
		    gencode_function("\tswap\n");
	    	gencode_MOD(info, right);
		    gencode_store(type,name);
            break;
    }
}
void gencode_compare(float left[7],float right[7],int op){
    char tempbuf[64];
	if(left[1] == 1 && right[1] == 1){
		gencode_function("\ti2f\n");
		gencode_function("\tswap\n");
		gencode_function("\ti2f\n");
		gencode_function("\tswap\n");
	}
	else if(left[1] == 1 && right[1] == 2){
		gencode_function("\tswap\n");
		gencode_function("\ti2f\n");
		gencode_function("\tswap\n");
	}
	else if(left[1] == 2 && right[1] == 2){
	}
	else if(left[1] == 2 && right[1] == 1){
		gencode_function("\ti2f\n");
	}
	else{
		yyerror("Unsupported data type!");
	}

	gencode_function("\tfcmpl\n");

	char op_name[10];
	char op_code[10];

	switch(op){
        	
	case 1:
		sprintf(op_code, "ifgt");
		sprintf(op_name, "MT");
		break;

	case 2:
		sprintf(op_code, "iflt");
		sprintf(op_name, "LT");
		break;

	case 3:
		sprintf(op_code, "ifge");
		sprintf(op_name, "MTE");
		break;
	case 4:
		sprintf(op_code, "ifle");
		sprintf(op_name, "LTE");
		break;
	case 5:
		sprintf(op_code, "ifeq");
		sprintf(op_name, "EQ");
		break;

	case 6:
		sprintf(op_code, "ifne");
		sprintf(op_name, "NE");
		break;
	}

	sprintf(tempbuf, "\t%s LABLE_%s_T_%d\n", op_code, op_name, cmp_num);
	gencode_function(tempbuf);
	gencode_function("\ticonst_0\n");
	sprintf(tempbuf, "\tgoto LABLE_%s_F_%d\n", op_name, cmp_num);
	gencode_function(tempbuf);
	sprintf(tempbuf, "LABLE_%s_T_%d:\n", op_name, cmp_num);
	gencode_function(tempbuf);
	gencode_function("\ticonst_1\n");
	sprintf(tempbuf,"LABLE_%s_F_%d:\n", op_name, cmp_num);
	gencode_function(tempbuf);

	cmp_num++;
}

int getParam(char* name,int i){
    symbol_table* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope == scope_num){
            return temp->param_a[i];
        }
    }   
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope < scope_num){
             return temp->param_a[i];
        }
    }      
}

int getParamNum(char* name,int i){
    symbol_table* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope == scope_num){
            return temp->param_n;
        }
    }   
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope < scope_num){
             return temp->param_n;
        }
    }      
}
