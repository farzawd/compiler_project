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
RANGE [\.\.]

BOOLEAN_CONSTANT "true"|"false"
REAL_CONSTANT {SIGN}?{NZ_DIGIT}{DIGIT}*(\.)?{DIGIT}+([eE]{SIGN}?{DIGIT}+)?
INTEGER_CONSTANT {ZERO}|{SIGN}?{NZ_DIGIT}{DIGIT}*
CHAR_CONSTANT {LETTER}+
IDENTIFIER {LETTER}+|{LETTER}({LETTER}|{DIGIT})*

WHITESPACE ([\t]|[\n]|[ ])*

%%


{MAIN_KW} {return MAIN_KW;}
{PROGRAM_KW} {return PROGRAM_KW;}
{INTEGER_KW} {return INTEGER_KW;}
{REAL_KW} {return REAL_KW;}
{BOOLEAN_KW} {return BOOLEAN_KW;}
{PROCEDURE_KW} {return PROCEDURE_KW;}
{OR_KW} {return OR_KW;}
{AND_KW} {return AND_KW;}

{NOT_KW} {return NOT_KW;}

{WHILE_KW} {return WHILE_KW;}
{END_KW} {return END_KW;}
{SWITCH_KW} {return SWITCH_KW;}


{ASSIGN_KW} {return ASSIGN_KW;}
{IF_KW} {return IF_KW;}
{THEN_KW} {return THEN_KW;}
{ELSE_KW} {return ELSE_KW;}
{FOR_KW} {return FOR_KW;}
{REPEAT_KW} {return REPEAT_KW;}
{CASE_KW} {return CASE_KW;}
{DO_KW} {return DO_KW;}
{DEFAULT_KW} {return DEFAULT_KW;}
{RETURN_KW} {return RETURN_KW;}
{EXIT_KW} {return EXIT_KW;}


{MOD} {return MOD_KW;}
{MULTIPLY} {return MULTIPLY_KW;}
{DIVIDE} {return DIVIDE_KW;}
{PLUS} {return PLUS_KW;}
{MINUS} {return MINUS_KW;}

{RANGE} {return RANGE_KW;}

{LT} {return LT_KW;}
{LE} {return LE_KW;}
{GE} {return GE_KW;}
{GT} {return GT_KW;}
{EQ} {return EQ_KW;}
{NE} {return NE_KW;}


"(" {return '(';} 
")" {return ')';}
"," {return ',';}
";" {return ';';}
":" {return ':';}
"[" {return '[';}
"]" {return ']';}
"{" {return '{';}
"}" {return '}';}



{BOOLEAN_CONSTANT} {return BOOLEAN_CONSTANT;}
{REAL_CONSTANT} {return REAL_CONSTANT;}
{INTEGER_CONSTANT} {return INTEGER_CONSTANT;}
{IDENTIFIER} {install_id(yytext); return IDENTIFIER;}

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