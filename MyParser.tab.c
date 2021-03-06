/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "MyParser.y" /* yacc.c:339  */


#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <stdlib.h>

FILE *fout;

using namespace std;

vector<char*> quadR[4];
vector<char*> symbolTable[2];
vector<char*> reg;

int lookup(char* a)
{
//look up an identifier in the symbol table
	for(int i = 0 ; i < symbolTable[0].size() ; i++)
	{
		if(strcmp(a, symbolTable[0].at(i)) == 0)
			return i;
	}
	
	return -1;
}

void insertToSymbolTable(char* id,char* type)
{
//insert a new identifier to the symbol table
	symbolTable[0].push_back(id);
	symbolTable[1].push_back(type);
	
	printf("%s was inserted\n", id);
}

int temp_counter = 0;
char* newTemp(char* c)
{
//make a new temporary variable
	char *temp = (char*)calloc(sizeof(char), 20);
	sprintf(temp, "__temp_var_%d", temp_counter++);
	insertToSymbolTable(temp, c);
	return temp;
}

void printQuadToCode()
{
	ofstream myfile;
	myfile.open("intermediatecode.c", ofstream::out);
	myfile << "#include <stdio.h>\n\n";
	
	//print all the variables here
	myfile << "// defined variables:" << endl;
	for(int i = 0 ; i < symbolTable[0].size() ; i++)
	{
		myfile << symbolTable[1].at(i) << " " << symbolTable[0].at(i) << ";" << endl;
	}
	
	myfile << endl << "int main() {\n\n";
	
	for(int i = 0; i < quadR[0].size(); i++)
	{
		myfile<<"Line" << i << ": ";
		if(strcmp(quadR[0][i], "goto") == 0)
		{
			myfile << "goto " << quadR[3][i] << ";" << endl;
		}
		else if(strcmp(quadR[0][i], "cgoto") == 0)
		{
			myfile << "if (" << quadR[1][i] << ") goto " << quadR[3][i] << ";" << endl;
		}
		else if(strcmp(quadR[0][i], ":=") == 0)
		{
			myfile << quadR[3][i] << " = " << quadR[1][i] << ";" << endl;
		}
		else if(strcmp(quadR[0][i], "+") == 0 || strcmp(quadR[0][i], "-") == 0 || strcmp(quadR[0][i], "*") == 0 || strcmp(quadR[0][i], "/") == 0 || strcmp(quadR[0][i], "&&") == 0 || strcmp(quadR[0][i], "||") == 0 || strcmp(quadR[0][i], "<") == 0 || strcmp(quadR[0][i], "<=") == 0 || strcmp(quadR[0][i], ">") == 0 || strcmp(quadR[0][i], ">=") == 0)
		{
			if(strlen(quadR[3][i]) > 0)
				myfile << quadR[3][i] << " = ";
			myfile << quadR[1][i] << " " << quadR[0][i] << " " << quadR[2][i] << ";" << endl;
		}
		else if(strcmp(quadR[0][i], "=") == 0)
		{
			if(strlen(quadR[3][i]) > 0)
				myfile << quadR[3][i] << " = ";
			myfile << quadR[1][i] << " == " << quadR[2][i] << ";" << endl;
		}
		else if(strcmp(quadR[0][i], "U-") == 0)
		{
			if(strlen(quadR[3][i]) > 0)
				myfile << quadR[3][i] << " = ";
			myfile << " -" << quadR[1][i] << ";" << endl;
		}
	}
	
	myfile << "Line" << quadR[0].size() << ": " << "return 0;" << endl;
	myfile << "}" << endl;
	myfile.close();		
}

char* concatnate(int Count,...)
{

}

void pushToQuadTable(char* s0,char* s1,char* s2,char* s3)
{
		quadR[0].push_back(s0);
		quadR[1].push_back(s1);
		quadR[2].push_back(s2);
		quadR[3].push_back(s3);
}

void backpatch(char* a,int b)
{

}

char* merge(char* a,char* b)
{
	return concatnate(2,a,b);
}

char* makelist(int a)
{

}

char* intToCharStar(int a)
{

}

char* addToList(char* a)
{

}


extern FILE *yyin;
extern int yylineno;
extern char* yytext;

extern int yylex();

void yyerror(const char *s);


#line 218 "MyParser.tab.c" /* yacc.c:339  */

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
   by #include "MyParser.tab.h".  */
#ifndef YY_YY_MYPARSER_TAB_H_INCLUDED
# define YY_YY_MYPARSER_TAB_H_INCLUDED
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
    PROGRAM_KW = 258,
    MAIN_KW = 259,
    INTEGER_KW = 260,
    REAL_KW = 261,
    CHAR_KW = 262,
    BOOLEAN_KW = 263,
    PROCEDURE_KW = 264,
    IF_KW = 265,
    THEN_KW = 266,
    ELSE_KW = 267,
    DO_KW = 268,
    FOR_KW = 269,
    IN_KW = 270,
    REPEAT_KW = 271,
    CASE_KW = 272,
    DEFAULT_KW = 273,
    RETURN_KW = 274,
    EXIT_KW = 275,
    WHEN_KW = 276,
    AND_KW = 277,
    OR_KW = 278,
    NOT_KW = 279,
    ASSIGN_KW = 280,
    MOD_KW = 281,
    MULTIPLY_KW = 282,
    DIVIDE_KW = 283,
    PLUS_KW = 284,
    MINUS_KW = 285,
    LT_KW = 286,
    LE_KW = 287,
    GE_KW = 288,
    GT_KW = 289,
    EQ_KW = 290,
    NE_KW = 291,
    WHILE_KW = 292,
    END_KW = 293,
    SWITCH_KW = 294,
    RANGE_KW = 295,
    INTEGER_CONSTANT = 296,
    REAL_CONSTANT = 297,
    BOOLEAN_CONSTANT = 298,
    CHAR_CONSTANT = 299,
    IDENTIFIER = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 152 "MyParser.y" /* yacc.c:355  */

	int ival;
	float rval;
	bool bval;
	char* id;
	char cval;

#line 312 "MyParser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MYPARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 327 "MyParser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   297

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
      52,    53,     2,     2,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    46,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   181,   181,   185,   189,   193,   198,   203,   209,   215,
     219,   223,   227,   232,   236,   241,   245,   250,   254,   258,
     264,   268,   272,   280,   289,   295,   302,   306,   312,   318,
     324,   331,   336,   341,   346,   351,   357,   363,   368,   373,
     378,   383,   388,   393,   401,   408,   413,   419,   425,   430,
     435,   440,   445,   451,   456,   461,   466,   472,   477,   482,
     487,   492,   497,   502,   507,   512,   517,   522,   528,   533,
     538,   543,   548,   553
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM_KW", "MAIN_KW", "INTEGER_KW",
  "REAL_KW", "CHAR_KW", "BOOLEAN_KW", "PROCEDURE_KW", "IF_KW", "THEN_KW",
  "ELSE_KW", "DO_KW", "FOR_KW", "IN_KW", "REPEAT_KW", "CASE_KW",
  "DEFAULT_KW", "RETURN_KW", "EXIT_KW", "WHEN_KW", "AND_KW", "OR_KW",
  "NOT_KW", "ASSIGN_KW", "MOD_KW", "MULTIPLY_KW", "DIVIDE_KW", "PLUS_KW",
  "MINUS_KW", "LT_KW", "LE_KW", "GE_KW", "GT_KW", "EQ_KW", "NE_KW",
  "WHILE_KW", "END_KW", "SWITCH_KW", "RANGE_KW", "INTEGER_CONSTANT",
  "REAL_CONSTANT", "BOOLEAN_CONSTANT", "CHAR_CONSTANT", "IDENTIFIER",
  "';'", "','", "'['", "']'", "'{'", "'}'", "'('", "')'", "':'", "$accept",
  "program", "declarations_list", "declarations", "type",
  "declarator_list", "declarator", "dec", "range", "initializer",
  "initializer_list", "procedure_list", "procedure", "parameters", "block",
  "statement_list", "statement", "arguments", "caseelement", "default",
  "expressions", "constant_expressions", "bool_expressions",
  "arithmetic_expressions", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,    59,    44,    91,    93,
     123,   125,    40,    41,    58
};
# endif

#define YYPACT_NINF -63

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-63)))

#define YYTABLE_NINF -38

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,   -23,    50,    39,   -63,     7,   -63,   -63,   -63,   -63,
      -6,   112,   -63,    25,    21,   -63,    95,   -63,    45,     7,
     -63,    52,    81,    64,   -63,    87,     7,   -63,   165,   155,
      85,   165,   111,   165,   -18,   -63,   -63,    13,    90,    60,
      88,   -63,     7,   188,   -63,    25,    89,   -63,   165,   165,
     -63,   -63,   -63,   -63,   -63,   165,   250,   -63,   122,   -63,
     100,   127,   250,   -63,    92,   235,   165,    25,   -63,   101,
     -63,    -2,    60,   -63,   -11,   106,   107,   118,   -63,   149,
     -63,   -63,    74,   150,    83,   119,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   155,   165,   204,
     165,   126,    42,   250,   123,   113,   -63,   -63,     5,   146,
     -63,   114,   -63,   165,   137,   151,   -63,   165,   261,   165,
     261,   -63,   -63,   -63,    74,    74,    63,   125,   125,    63,
     193,   193,   184,     3,   157,   183,   148,   159,   161,   160,
     166,   -63,   164,   -63,   -63,    -8,   -63,   149,   -63,   -63,
     155,   155,   -63,     7,   162,     7,   -63,   189,   -63,   -63,
     -63,   190,     7,   191,   -63,   -63,   192,   -63,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     9,    10,    12,    11,
       0,     0,     6,     0,     0,    27,     0,     5,     0,     0,
       7,     0,    17,     0,    13,    15,     0,    26,     0,     0,
       0,     0,     0,     0,     0,    33,    43,     0,     0,     0,
       0,     4,     0,     0,     8,     0,     0,     3,     0,     0,
      53,    54,    56,    55,    51,     0,     0,    48,    49,    50,
       0,     0,    41,    49,     0,     0,     0,     0,    30,     0,
      31,     0,     0,     2,    53,    51,     0,    50,    14,     0,
      16,    67,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    44,     0,    32,    29,     0,     0,
      19,     0,    18,     0,     0,    24,    52,     0,    63,     0,
      64,    72,    70,    71,    68,    69,    57,    58,    60,    59,
      61,    62,    35,    49,    53,     0,    49,     0,     0,     0,
       0,    40,     0,    21,    20,    50,    23,     0,    65,    66,
       0,     0,    42,     0,     0,     0,    39,     0,    25,    36,
      38,     0,     0,     0,    28,    45,     0,    47,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -63,    15,    -9,   -63,   144,   194,   -63,   142,   -63,
      96,   231,    10,   -63,    -5,   -63,   -28,   -63,   -63,   -63,
     -13,   -62,   -12,   -15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    11,    12,    13,    23,    24,    25,    76,    80,
     114,    14,    15,    40,    36,    37,    38,   105,   102,   140,
      56,    57,    63,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    60,    20,     6,     7,     8,     9,    66,   -22,    69,
       6,     7,     8,     9,    41,   -37,    58,   115,    62,     1,
      65,    47,     3,    28,    27,    26,    29,    30,    77,   109,
      10,    27,    31,    32,    67,    81,    82,    73,   110,    18,
     -37,   -22,    83,     5,     6,     7,     8,     9,    10,   -37,
       4,   107,    33,   103,    71,    16,    42,    16,    34,   138,
     139,    10,    20,    16,    68,     6,     7,     8,     9,   132,
      22,   118,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    77,   115,   133,   108,   136,    86,
      87,    88,    89,    90,   117,    92,    93,    39,   145,    20,
      86,    87,    88,   142,   148,    28,   149,    48,    29,    30,
      44,    45,    46,    49,    31,    32,    19,     6,     7,     8,
       9,    10,   159,   160,    50,    51,    52,    53,    54,    43,
      61,   119,    64,    97,    33,    55,    70,    98,    72,    79,
      34,    35,    99,    48,   100,    16,   111,   106,   161,    49,
     163,    86,    87,    88,    89,    90,   112,   166,   113,   144,
      50,    51,    52,    53,    54,    28,   141,   137,    29,    30,
      45,    55,    84,    85,    31,    32,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,   143,   146,    48,
      50,    51,    52,    53,    33,    49,   150,   109,   147,   151,
      34,   152,   154,   116,   156,    16,    50,    51,    52,    53,
      54,   104,    48,   153,   155,   157,   162,    55,    49,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    48,    74,
      51,    52,    53,    75,    49,   164,   165,   167,   168,    78,
      55,   135,    21,   158,     0,   134,    51,    52,    53,    75,
       0,     0,   101,     0,     0,     0,    55,    84,    85,     0,
       0,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    84,    85,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96
};

static const yytype_int16 yycheck[] =
{
       5,    29,    11,     5,     6,     7,     8,    25,    16,    37,
       5,     6,     7,     8,    19,    12,    28,    79,    31,     3,
      33,    26,    45,    10,    14,     4,    13,    14,    43,    40,
       9,    21,    19,    20,    52,    48,    49,    42,    49,    45,
      37,    49,    55,     4,     5,     6,     7,     8,     9,    46,
       0,    53,    39,    66,    39,    50,     4,    50,    45,    17,
      18,     9,    71,    50,    51,     5,     6,     7,     8,    97,
      45,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    99,   147,    98,    72,   100,    26,
      27,    28,    29,    30,    11,    32,    33,    52,   113,   108,
      26,    27,    28,   108,   117,    10,   119,    24,    13,    14,
      46,    47,    25,    30,    19,    20,     4,     5,     6,     7,
       8,     9,   150,   151,    41,    42,    43,    44,    45,    48,
      45,    12,    21,    11,    39,    52,    46,    37,    50,    50,
      45,    46,    15,    24,    52,    50,    40,    46,   153,    30,
     155,    26,    27,    28,    29,    30,    49,   162,    40,    45,
      41,    42,    43,    44,    45,    10,    53,    41,    13,    14,
      47,    52,    22,    23,    19,    20,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    41,    51,    24,
      41,    42,    43,    44,    39,    30,    12,    40,    47,    16,
      45,    53,    41,    53,    38,    50,    41,    42,    43,    44,
      45,    67,    24,    54,    54,    51,    54,    52,    30,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    24,    41,
      42,    43,    44,    45,    30,    46,    46,    46,    46,    45,
      52,    99,    11,   147,    -1,    41,    42,    43,    44,    45,
      -1,    -1,    17,    -1,    -1,    -1,    52,    22,    23,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    22,    23,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    56,    45,     0,     4,     5,     6,     7,     8,
       9,    57,    58,    59,    66,    67,    50,    69,    45,     4,
      58,    66,    45,    60,    61,    62,     4,    67,    10,    13,
      14,    19,    20,    39,    45,    46,    69,    70,    71,    52,
      68,    69,     4,    48,    46,    47,    25,    69,    24,    30,
      41,    42,    43,    44,    45,    52,    75,    76,    77,    78,
      71,    45,    75,    77,    21,    75,    25,    52,    51,    71,
      46,    57,    50,    69,    41,    45,    63,    78,    61,    50,
      64,    75,    75,    75,    22,    23,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    11,    37,    15,
      52,    17,    73,    75,    60,    72,    46,    53,    57,    40,
      49,    40,    49,    40,    65,    76,    53,    11,    75,    12,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    71,    77,    41,    63,    77,    41,    17,    18,
      74,    53,    69,    41,    45,    78,    51,    47,    75,    75,
      12,    16,    53,    54,    41,    54,    38,    51,    65,    71,
      71,    69,    54,    69,    46,    46,    69,    46,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    56,    56,    57,    57,    58,    59,
      59,    59,    59,    60,    60,    61,    61,    62,    62,    62,
      63,    63,    63,    64,    65,    65,    66,    66,    67,    68,
      69,    70,    70,    70,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    72,    73,    73,    74,    75,    75,
      75,    75,    75,    76,    76,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    78,    78,
      78,    78,    78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     5,     5,     4,     1,     2,     3,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     4,     4,
       3,     3,     3,     3,     1,     3,     2,     1,     8,     3,
       3,     2,     3,     1,     3,     4,     6,     4,     6,     5,
       4,     2,     5,     1,     1,     5,     6,     4,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     4,     2,     3,     3,
       3,     3,     3,     2
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
#line 182 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 1 \t\t program -> PROGRAM_KW IDENTIFIER declarations_list procedure_list MAIN_KW block \n") ;
	}
#line 1548 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 186 "MyParser.y" /* yacc.c:1646  */
    {
	fprintf(fout, "Rule 2 \t\t program -> PROGRAM_KW IDENTIFIER  procedure_list MAIN_KW block \n") ;
	}
#line 1556 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 190 "MyParser.y" /* yacc.c:1646  */
    {
	fprintf(fout, "Rule 3 \t\t program -> PROGRAM_KW IDENTIFIER declarations_list MAIN_KW block \n") ;
	}
#line 1564 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 194 "MyParser.y" /* yacc.c:1646  */
    {
	fprintf(fout, "Rule 4 \t\t program -> PROGRAM_KW IDENTIFIER MAIN_KW block \n") ;
	}
#line 1572 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 199 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 5 \t\t declarations_list -> declarations ; \n") ;
	}
#line 1580 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 204 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 6 \t\t declarations_list -> declarations_list declarations \n") ;
	}
#line 1588 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 210 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 7 \t\t declarations -> type_specifiers declarator_list ; \n") ;
	}
#line 1596 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 216 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 8 \t\t type -> INTEGER_KW\n") ;
	}
#line 1604 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 220 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 9 \t\t type -> REAL_KW\n") ;
	}
#line 1612 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 224 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 10 \t type -> BOOL_KW\n") ;
	}
#line 1620 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 228 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 11 \t type -> CHAR_KW\n") ;
	}
#line 1628 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 233 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 12 \t declarator_list -> declarator \n") ;
	}
#line 1636 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 237 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 13 \t declarator_list -> declarator_list , declarator \n") ;
	}
#line 1644 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 242 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 14 \t declarator -> dec \n") ;
	}
#line 1652 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 246 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 15 \t declarator -> dec ASSIGN_KW initializer  \n") ;
	}
#line 1660 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 251 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 16 \t dec -> IDENTIFIER \n") ;
	}
#line 1668 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 255 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 17 \t dec -> IDENTIFIER [range] \n") ;
	}
#line 1676 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 259 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 18 \t dec -> IDENTIFIER[INTEGER_CONSTANT] \n") ;
	}
#line 1684 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 265 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 19 \t range -> IDENTIFIER RANGE_KW IDENTIFIER \n") ;
	}
#line 1692 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 269 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 20 \t range -> INTEGER_CONSTANT RANGE_KW INTEGER_CONSTANT \n") ;
	}
#line 1700 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 273 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 21 \t range -> arithmetic_expressions RANGE_KW arithmetic_expressions \n") ;
	}
#line 1708 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 281 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 22 \t initializer -> {initializer_list}  \n") ;
	
	}
#line 1717 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 290 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 23 \t initializer_list -> constant_expressions  \n") ;

	}
#line 1726 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 296 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 24 \t initializer_list -> constant_expressions , initializer_list  \n") ;

	}
#line 1735 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 303 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule  25 \t procedure_list -> procedure_list procedure   \n") ;
	}
#line 1743 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 307 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule  26 \t procedure_list -> procedure  \n") ;
	}
#line 1751 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 313 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 27 \t procedure ->  PROCEDURE_KW IDENTIFIER parameters {declarations_list block } ;	  \n") ;

	}
#line 1760 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 319 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 28 \t parameters -> ( declarations_list )  \n") ;

	}
#line 1769 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 325 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 29 \t block -> {statement_list}  \n") ;

	}
#line 1778 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 332 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 30 \t statement_list -> statement;  \n") ;

	}
#line 1787 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 337 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 31 \t statement_list -> statement_list statement ;  \n") ;

	}
#line 1796 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 342 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 32 \t statement_list -> ;  \n") ;
	}
#line 1804 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 347 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 33 \t statement -> IDENTIFIER ASSIGN_KW expressions  \n") ;

	}
#line 1813 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 352 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 34 \t statement -> IF_KW bool_expressions THEN_KW statement   \n") ;

	}
#line 1822 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 358 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 35 \t statement -> IF_KW bool_expressions THEN_KW statement ELSE_KW statement   \n") ;

	}
#line 1831 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 364 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 36 \t statement -> DO_KW statement WHILE_KW bool_expressions   \n") ;

	}
#line 1840 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 369 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 37 \t statement ->  FOR_KW IDENTIFIER IN_KW range REPEAT_KW statement  \n") ;

	}
#line 1849 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 374 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 38 \t statement -> SWITCH_KW expressions caseelement default END_KW  \n") ;

 	}
#line 1858 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 379 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 39 \t statement -> IDENTIFIER '('arguments')'  \n") ;

 	}
#line 1867 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 384 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 40 \t statement -> RETURN_KW expressions   \n") ;

 	}
#line 1876 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 389 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 41 \t statement -> EXIT_KW WHEN_KW (bool_expressions)   \n") ;

 	}
#line 1885 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 394 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 42 \t statement -> block  \n") ;

 	}
#line 1894 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 402 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 43 \t arguments -> declarator_list  \n") ;

	}
#line 1903 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 409 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 44 \t caseelement ->  CASE_KW INTEGER_CONSTANT:block ;   \n") ;

	}
#line 1912 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 414 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 45 \t caseelement -> caseelement CASE_KW INTEGER_CONSTANT : block ;  \n") ;

	}
#line 1921 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 420 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 46 \t default -> DEFAULT_KW ':' block ';'   \n") ;

	}
#line 1930 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 426 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 47 \t expressions -> constant_expressions  \n") ;

	}
#line 1939 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 431 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 48 \t expressions -> bool_expressions  \n") ;

	}
#line 1948 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 436 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 49 \t expressions -> arithmetic_expressions  \n") ;

	}
#line 1957 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 441 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 50 \t expressions -> IDENTIFIER  \n") ;

	}
#line 1966 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 446 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 51 \t expressions -> (expressions)  \n") ;

	}
#line 1975 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 452 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 52 \t constant_expressions -> INTEGER_CONSTANT  \n") ;

	}
#line 1984 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 457 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 53 \t constant_expressions -> REAL_CONSTANT  \n") ;

	}
#line 1993 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 462 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 54 \t constant_expressions -> CHAR_CONSTANT  \n") ;

	}
#line 2002 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 467 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 55 \t constant_expressions -> BOOLEAN_CONSTANT  \n") ;

	}
#line 2011 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 473 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 56 \t bool_expressions ->  expressions < expressions  \n") ;

	}
#line 2020 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 478 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 57 \t bool_expressions ->  expressions <= expressions  \n") ;

	}
#line 2029 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 483 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 58 \t bool_expressions ->  expressions > expressions  \n") ;

	}
#line 2038 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 488 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 59 \t bool_expressions ->  expressions >= expressions  \n") ;

	}
#line 2047 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 493 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 60 \t bool_expressions ->  expressions = expressions  \n") ;

	}
#line 2056 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 498 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 61 \t bool_expressions ->  expressions != expressions  \n") ;

	}
#line 2065 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 503 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 62 \t bool_expressions ->  expressions AND_KW expressions  \n") ;

	}
#line 2074 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 508 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 63 \t bool_expressions -> expressions OR_KW expressions   \n") ;

	}
#line 2083 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 513 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 64 \t bool_expressions -> expressions AND_KW THEN_KW expressions   \n") ;

	}
#line 2092 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 518 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 65 \t bool_expressions ->  expressions OR_KW ELSE_KW expressions   \n") ;

	}
#line 2101 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 523 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 66 \t bool_expressions ->  NOT_KW expressions  \n") ;

	}
#line 2110 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 529 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 67 \t arithmetic_expressions -> expressions + expressions   \n") ;

	}
#line 2119 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 534 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 68 \t arithmetic_expressions -> expressions - expressions   \n") ;

	}
#line 2128 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 539 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 69 \t arithmetic_expressions -> expressions * expressions   \n") ;

	}
#line 2137 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 544 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 70 \t arithmetic_expressions -> expressions / expressions   \n") ;

	}
#line 2146 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 549 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 71 \t arithmetic_expressions -> expressions [divide] expressions   \n") ;

	}
#line 2155 "MyParser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 554 "MyParser.y" /* yacc.c:1646  */
    {
		fprintf(fout, "Rule 72 \t arithmetic_expressions -> - expressions   \n") ;

	}
#line 2164 "MyParser.tab.c" /* yacc.c:1646  */
    break;


#line 2168 "MyParser.tab.c" /* yacc.c:1646  */
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
#line 559 "MyParser.y" /* yacc.c:1906  */


int main() {
/*
	printf("Parser program started...\nTesting symbol table: inserted variables 'int var1' and 'int var2'");
	insertToSymbolTable("var1", "int");
	insertToSymbolTable("var2", "int");
	printf("lookup result for variables var1 and var2:\t");
	printf("%d, %d\n", lookup("var1"), lookup("var2"));
	
	printf("reserving two temporary variables. reserved names: %s, %s\n", newTemp("int"), newTemp("int"));
	printf("testing complete.");
*/


//--------------------------------------------test case for this code:-----------------------------------------------------------
	/* 
		int a = 4;
		if(a < 2 && b = 3)
		{
			while(a < 1)
			{
				a := a + 1
			}
		}
	*/
	
	insertToSymbolTable("a", "int");
	pushToQuadTable(":=", "4", "", "a");

	// if
	char* lt_place = newTemp("bool");
	char* eq_place = newTemp("bool");
	char* ifex_place = newTemp("bool");
	pushToQuadTable("<", "a", "2", lt_place);
	pushToQuadTable("=", "b", "3", eq_place);
	pushToQuadTable("&&", lt_place, eq_place, ifex_place);
	pushToQuadTable("cgoto", ifex_place, "", "LINE");

		// while
		char* whex_place = newTemp("bool");
		pushToQuadTable("<", "a", "1", whex_place);
		pushToQuadTable("cgoto", whex_place, "", "LINE");
	
			// inside while
			pushToQuadTable("+", "a", "1", "a");
		
		pushToQuadTable("goto", "", "", "LINE");
	
//-------------------------------------------------------------------------------------------------------------------------------
	

	yyin = stdin;
	
	fout = stdout;
	fprintf(fout, "\n \t \t \t PARSER \n");
	fprintf(fout, "Line %d, \t", yylineno);
	fprintf(fout, "Rule No. --> Rule Description \n");
	
	if (fout == NULL)
	{
		printf("Error opening file!\n");
	}
	// make sure it is valid:
	else if (!yyin) {
		printf("Error opening file!\n");
	}
	else
		yyparse();
		
	printQuadToCode();
}

void yyerror(const char *s) {
	//fprintf(fout, "**Error: Line %d near token '%s' --> Message: %s **\n", yylineno,yytext ,s);
	printf("**Error: Line %d near token '%s' --> Message: %s **\n", yylineno,yytext, s);
}
