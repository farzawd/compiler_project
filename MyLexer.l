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


{MAIN_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "MAIN_KW\t-\n");return MAIN_KW;}
{PROGRAM_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "PROGRAM_KW\t-\n");return PROGRAM_KW;}
{INTEGER_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "INTEGER_KW\t-\n");return INTEGER_KW;}
{REAL_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "REAL_KW\t-\n");return REAL_KW;}
{CHAR_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "CHAR_KW\t-\n");return CHAR_KW;}
{BOOLEAN_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "BOOLEAN_KW\t-\n");return BOOLEAN_KW;}
{PROCEDURE_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "PROCEDURE_KW\t-\n");return PROCEDURE_KW;}
{OR_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "OR_KW\t-\n");return OR_KW;}
{AND_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "AND_KW\t-\n");return AND_KW;}

{NOT_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "NOT_KW\t-\n");return NOT_KW;}

{WHILE_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "WHILE_KW\t-\n");return WHILE_KW;}
{END_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "END_KW\t-\n");return END_KW;}
{SWITCH_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "SWITCH_KW\t-\n");return SWITCH_KW;}


{ASSIGN_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "ASSIGN_KW\t-\n");return ASSIGN_KW;}
{IF_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "IF_KW\t-\n");return IF_KW;}
{THEN_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "THEN_KW\t-\n");return THEN_KW;}
{ELSE_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "ELSE_KW\t-\n");return ELSE_KW;}
{FOR_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "FOR_KW\t-\n");return FOR_KW;}
{REPEAT_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "REPEAT_KW\t-\n");return REPEAT_KW;}
{CASE_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "CASE_KW\t-\n");return CASE_KW;}
{DO_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "DO_KW\t-\n");return DO_KW;}
{DEFAULT_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "DEFAULT_KW\t-\n");return DEFAULT_KW;}
{RETURN_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "RETURN_KW\t-\n");return RETURN_KW;}
{EXIT_KW} {printf(fout, "\t%s\t", yytext); fprintf(fout, "EXIT_KW\t-\n");return EXIT_KW;}


{MOD} {printf(fout, "\t%s\t", yytext); fprintf(fout, "MOD\t-\n");return MOD_KW;}
{MULTIPLY} {printf(fout, "\t%s\t", yytext); fprintf(fout, "MULTIPLY\t-\n");return MULTIPLY_KW;}
{DIVIDE} {printf(fout, "\t%s\t", yytext); fprintf(fout, "DIVIDE\t-\n");return DIVIDE_KW;}
{PLUS} {printf(fout, "\t%s\t", yytext); fprintf(fout, "PLUS\t-\n");return PLUS_KW;}
{MINUS} {printf(fout, "\t%s\t", yytext); fprintf(fout, "MINUS\t-\n");return MINUS_KW;}

{RANGE} {printf(fout, "\t%s\t", yytext); fprintf(fout, "RANGE\t-\n");return RANGE_KW;}


{LT} {printf(fout, "\t%s\t", yytext); fprintf(fout, "LT\t-\n");return LT_KW;}
{LE} {printf(fout, "\t%s\t", yytext); fprintf(fout, "LE\t-\n");return LE_KW;}
{GE} {printf(fout, "\t%s\t", yytext); fprintf(fout, "GE\t-\n");return GE_KW;}
{GT} {printf(fout, "\t%s\t", yytext); fprintf(fout, "GT\t-\n");return GT_KW;}
{EQ} {printf(fout, "\t%s\t", yytext); fprintf(fout, "EQ\t-\n");return EQ_KW;}
{NE} {printf(fout, "\t%s\t", yytext); fprintf(fout, "NE\t-\n");return NE_KW;}


"(" {printf(fout, "\t%s\t", yytext); fprintf(fout, "(\t-\n");return '(';} 
")" {printf(fout, "\t%s\t", yytext); fprintf(fout, ")\t-\n");return ')';}
"," {printf(fout, "\t%s\t", yytext); fprintf(fout, ",\t-\n");return ',';}
";" {printf(fout, "\t%s\t", yytext); fprintf(fout, ";\t-\n");return ';';}
":" {printf(fout, "\t%s\t", yytext); fprintf(fout, ":\t-\n");return ':';}
"[" {printf(fout, "\t%s\t", yytext); fprintf(fout, "[\t-\n");return '[';}
"]" {printf(fout, "\t%s\t", yytext); fprintf(fout, "]\t-\n");return ']';}
"{" {printf(fout, "\t%s\t", yytext); fprintf(fout, "{\t-\n");return '{';}
"}" {printf(fout, "\t%s\t", yytext); fprintf(fout, "}\t-\n");return '}';}



{BOOLEAN_CONSTANT} {printf(fout, "\t%s\t", yytext); fprintf(fout, "BOOLEAN_CONSTANT\t-\n");return BOOLEAN_CONSTANT;}
{REAL_CONSTANT} {printf(fout, "\t%s\t", yytext); fprintf(fout, "REAL_CONSTANT\t-\n");return REAL_CONSTANT;}
{INTEGER_CONSTANT} {printf(fout, "\t%s\t", yytext); fprintf(fout, "INTEGER_CONSTANT\t-\n");return INTEGER_CONSTANT;}
{IDENTIFIER} {printf(fout, "\t%s\t", yytext); fprintf(fout, "IDENTIFIER\t-\n");install_id(yytext); return IDENTIFIER;}

[\n] {++yylineno;}
. {}


%%
/*
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

yyin = fopen("input.txt", "r");	
fout = fopen("output.txt", "w");
fprintf(fout, "\n LEXER \n");
fprintf(fout, "\tRegEx\tToken\tAttVal\n\n");
    if(yyin) {  
      yylex();
	  fclose(yyin);           
    }
	fclose(fout);
    return 0;
}
*/