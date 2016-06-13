/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 12 "MyParser.y" /* yacc.c:1909  */

	int ival;
	float rval;
	_Bool bval;
	char* id;
	char cval;

#line 108 "MyParser.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MYPARSER_TAB_H_INCLUDED  */
