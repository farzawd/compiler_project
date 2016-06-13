%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include "MyParser.tab.h"




FILE *fout;

char* symbol_table[100];
int counter=0;
int install_id(char* next)
{
	int i;
	for(i = 0 ; i < counter ; i++)
	{
		if(!strcmp(next, symbol_table[i]))
		{
			return i;
		}
	}
	
	char* var_name = (char *) malloc((strlen(next) + 1) * sizeof(char));
	strcpy(var_name, next);
	symbol_table[counter] = var_name;
	
	counter++;
	
	return counter - 1;
}
%}

PROGRAM_KW (program)
MAIN_KW (main)
INTEGER_KW (int)
REAL_KW (real)
CHAR_KW (char)
BOOLEAN_KW (bool)
PROCEDURE_KW (procedure)
IF_KW (if)
THEN_KW (then)
ELSE_KW (else)
DO_KW (do)
WHILE_KW (while)
END_KW (end)
SWITCH_KW (switch)
FOR_KW (for)
IN_KW (in)
REPEAT_KW (repeat)
CASE_KW (case)
DEFAULT_KW (default)
RETURN_KW (return)
EXIT_KW (exit)
WHEN_KW (when)
AND_KW [&&]
OR_KW [||]
NOT_KW [!]

LETTER [a-zA-Z]
ZERO [0]
DIGIT [0-9]
NZ_DIGIT [1-9]

ASSIGN_KW [:][=]
SIGN [+-]
PLUS [+]
MINUS [-]
MULTIPLY [*]
DIVIDE [/]
MOD [%]
LT [<]
EQ (=)
GT [>]
LE [<][=]
GE [>][=]
NE [<][>]
RANGE [\.][\.]

BOOLEAN_CONSTANT "true"|"false"
REAL_CONSTANT {SIGN}?{NZ_DIGIT}{DIGIT}*(\.)?{DIGIT}+([eE]{SIGN}?{DIGIT}+)?
INTEGER_CONSTANT {ZERO}|{SIGN}?{NZ_DIGIT}{DIGIT}*
CHAR_CONSTANT {LETTER}+
IDENTIFIER {LETTER}+|{LETTER}({LETTER}|{DIGIT})*

WHITESPACE ([\t]|[\n]|[ ])*

%%


{MAIN_KW} {printf("\t%s\t", yytext); printf("MAIN_KW\t-\n");return MAIN_KW;}
{PROGRAM_KW} {printf("\t%s\t", yytext); printf("PROGRAM_KW\t-\n");return PROGRAM_KW;}
{INTEGER_KW} {printf("\t%s\t", yytext); printf("INTEGER_KW\t-\n");return INTEGER_KW;}
{REAL_KW} {printf("\t%s\t", yytext); printf("REAL_KW\t-\n");return REAL_KW;}
{CHAR_KW} {printf("\t%s\t", yytext); printf("CHAR_KW\t-\n");return CHAR_KW;}
{BOOLEAN_KW} {printf("\t%s\t", yytext); printf("BOOLEAN_KW\t-\n");return BOOLEAN_KW;}
{PROCEDURE_KW} {printf("\t%s\t", yytext); printf("PROCEDURE_KW\t-\n");return PROCEDURE_KW;}
{OR_KW} {printf("\t%s\t", yytext); printf("OR_KW\t-\n");return OR_KW;}
{AND_KW} {printf("\t%s\t", yytext); printf("AND_KW\t-\n");return AND_KW;}

{NOT_KW} {printf("\t%s\t", yytext); printf("NOT_KW\t-\n");return NOT_KW;}

{WHILE_KW} {printf("\t%s\t", yytext); printf("WHILE_KW\t-\n");return WHILE_KW;}
{END_KW} {printf("\t%s\t", yytext); printf("END_KW\t-\n");return END_KW;}
{SWITCH_KW} {printf("\t%s\t", yytext); printf("SWITCH_KW\t-\n");return SWITCH_KW;}


{ASSIGN_KW} {printf("\t%s\t", yytext); printf("ASSIGN_KW\t-\n");return ASSIGN_KW;}
{IF_KW} {printf("\t%s\t", yytext); printf("IF_KW\t-\n");return IF_KW;}
{THEN_KW} {printf("\t%s\t", yytext); printf("THEN_KW\t-\n");return THEN_KW;}
{ELSE_KW} {printf("\t%s\t", yytext); printf("ELSE_KW\t-\n");return ELSE_KW;}
{FOR_KW} {printf("\t%s\t", yytext); printf("FOR_KW\t-\n");return FOR_KW;}
{REPEAT_KW} {printf("\t%s\t", yytext); printf("REPEAT_KW\t-\n");return REPEAT_KW;}
{CASE_KW} {printf("\t%s\t", yytext); printf("CASE_KW\t-\n");return CASE_KW;}
{DO_KW} {printf("\t%s\t", yytext); printf("DO_KW\t-\n");return DO_KW;}
{DEFAULT_KW} {printf("\t%s\t", yytext); printf("DEFAULT_KW\t-\n");return DEFAULT_KW;}
{RETURN_KW} {printf("\t%s\t", yytext); printf("RETURN_KW\t-\n");return RETURN_KW;}
{EXIT_KW} {printf("\t%s\t", yytext); printf("EXIT_KW\t-\n");return EXIT_KW;}


{MOD} {printf("\t%s\t", yytext); printf("MOD\t-\n");return MOD_KW;}
{MULTIPLY} {printf("\t%s\t", yytext); printf("MULTIPLY\t-\n");return MULTIPLY_KW;}
{DIVIDE} {printf("\t%s\t", yytext); printf("DIVIDE\t-\n");return DIVIDE_KW;}
{PLUS} {printf("\t%s\t", yytext); printf("PLUS\t-\n");return PLUS_KW;}
{MINUS} {printf("\t%s\t", yytext); printf("MINUS\t-\n");return MINUS_KW;}

{RANGE} {printf("\t%s\t", yytext); printf("RANGE\t-\n");return RANGE_KW;}


{LT} {printf("\t%s\t", yytext); printf("LT\t-\n");return LT_KW;}
{LE} {printf("\t%s\t", yytext); printf("LE\t-\n");return LE_KW;}
{GE} {printf("\t%s\t", yytext); printf("GE\t-\n");return GE_KW;}
{GT} {printf("\t%s\t", yytext); printf("GT\t-\n");return GT_KW;}
{EQ} {printf("\t%s\t", yytext); printf("EQ\t-\n");return EQ_KW;}
{NE} {printf("\t%s\t", yytext); printf("NE\t-\n");return NE_KW;}


"(" {printf("\t%s\t", yytext); printf("(\t-\n");return '(';} 
")" {printf("\t%s\t", yytext); printf(")\t-\n");return ')';}
"," {printf("\t%s\t", yytext); printf(",\t-\n");return ',';}
";" {printf("\t%s\t", yytext); printf(";\t-\n");return ';';}
":" {printf("\t%s\t", yytext); printf(":\t-\n");return ':';}
"[" {printf("\t%s\t", yytext); printf("[\t-\n");return '[';}
"]" {printf("\t%s\t", yytext); printf("]\t-\n");return ']';}
"{" {printf("\t%s\t", yytext); printf("{\t-\n");return '{';}
"}" {printf("\t%s\t", yytext); printf("}\t-\n");return '}';}



{BOOLEAN_CONSTANT} {printf("\t%s\t", yytext); printf("BOOLEAN_CONSTANT\t-\n");return BOOLEAN_CONSTANT;}
{REAL_CONSTANT} {printf("\t%s\t", yytext); printf("REAL_CONSTANT\t-\n");return REAL_CONSTANT;}
{INTEGER_CONSTANT} {printf("\t%s\t", yytext); printf("INTEGER_CONSTANT\t-\n");return INTEGER_CONSTANT;}
{IDENTIFIER} {printf("\t%s\t", yytext); printf("IDENTIFIER\t-\n");install_id(yytext); return IDENTIFIER;}

[\n] {++yylineno;}
. {}


%%
/*
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

yyin = fopen("input.txt", "r");	
fout = fopen("output.txt", "w");
printf(fout, "\n LEXER \n");
printf(fout, "\tRegEx\tToken\tAttVal\n\n");
    if(yyin) {  
      yylex();
	  fclose(yyin);           
    }
	fclose(fout);
    return 0;
}
*/
