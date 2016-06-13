%{

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

%}
%union {
	int ival;
	float rval;
	bool bval;
	char* id;
	char cval;
}

%token PROGRAM_KW MAIN_KW INTEGER_KW REAL_KW CHAR_KW BOOLEAN_KW PROCEDURE_KW IF_KW THEN_KW ELSE_KW DO_KW FOR_KW IN_KW REPEAT_KW CASE_KW DEFAULT_KW RETURN_KW EXIT_KW WHEN_KW AND_KW OR_KW NOT_KW ASSIGN_KW MOD_KW MULTIPLY_KW DIVIDE_KW PLUS_KW MINUS_KW LT_KW LE_KW GE_KW GT_KW EQ_KW NE_KW WHILE_KW END_KW SWITCH_KW RANGE_KW
%token <ival> INTEGER_CONSTANT
%token <rval> REAL_CONSTANT
%token <bval> BOOLEAN_CONSTANT
%token <cval> CHAR_CONSTANT
%token <id> IDENTIFIER

%left AND_KW OR_KW
%right ASSIGN_KW
%left EQ_KW NE_KW
%left LT_KW GT_KW
%left LE_KW GE_KW
%left PLUS_KW MINUS_KW
%left MULTIPLY_KW DIVIDE_KW MOD_KW
%right NOT_KW
%left THEN_KW
%left ELSE_KW



%%
program : PROGRAM_KW IDENTIFIER declarations_list procedure_list MAIN_KW block
	{
		fprintf(fout, "Rule 1 \t\t program -> PROGRAM_KW IDENTIFIER declarations_list procedure_list MAIN_KW block \n") ;
	};
	| PROGRAM_KW IDENTIFIER procedure_list MAIN_KW block
	{
	fprintf(fout, "Rule 2 \t\t program -> PROGRAM_KW IDENTIFIER  procedure_list MAIN_KW block \n") ;
	};
	| PROGRAM_KW IDENTIFIER declarations_list MAIN_KW block
	{
	fprintf(fout, "Rule 3 \t\t program -> PROGRAM_KW IDENTIFIER declarations_list MAIN_KW block \n") ;
	};
	|  PROGRAM_KW IDENTIFIER MAIN_KW block
	{
	fprintf(fout, "Rule 4 \t\t program -> PROGRAM_KW IDENTIFIER MAIN_KW block \n") ;
	};
		
declarations_list : declarations 
	{
		fprintf(fout, "Rule 5 \t\t declarations_list -> declarations ; \n") ;
	};
	
	|  declarations_list declarations
	{
		fprintf(fout, "Rule 6 \t\t declarations_list -> declarations_list declarations \n") ;
	};
	
	
declarations : type declarator_list ';' 
	{
		fprintf(fout, "Rule 7 \t\t declarations -> type_specifiers declarator_list ; \n") ;
	};
			
	
type : INTEGER_KW
	{
		fprintf(fout, "Rule 8 \t\t type -> INTEGER_KW\n") ;
	};
	| REAL_KW
	{
		fprintf(fout, "Rule 9 \t\t type -> REAL_KW\n") ;
	};
	| BOOLEAN_KW
	{
		fprintf(fout, "Rule 10 \t type -> BOOL_KW\n") ;
	};
	| CHAR_KW
	{
		fprintf(fout, "Rule 11 \t type -> CHAR_KW\n") ;
	};
	
declarator_list : declarator 
	{
		fprintf(fout, "Rule 12 \t declarator_list -> declarator \n") ;
	};
	| declarator_list ',' declarator
	{
		fprintf(fout, "Rule 13 \t declarator_list -> declarator_list , declarator \n") ;
	};
	
declarator : dec
	{
		fprintf(fout, "Rule 14 \t declarator -> dec \n") ;
	};
	| dec ASSIGN_KW initializer
	{
		fprintf(fout, "Rule 15 \t declarator -> dec ASSIGN_KW initializer  \n") ;
	};
	
dec : IDENTIFIER 
	{
		fprintf(fout, "Rule 16 \t dec -> IDENTIFIER \n") ;
	};
	| IDENTIFIER '['range']'
	{
		fprintf(fout, "Rule 17 \t dec -> IDENTIFIER [range] \n") ;
	};
	| IDENTIFIER'['INTEGER_CONSTANT']'
	{
		fprintf(fout, "Rule 18 \t dec -> IDENTIFIER[INTEGER_CONSTANT] \n") ;
	};
	
	
range : IDENTIFIER RANGE_KW IDENTIFIER
	{
		fprintf(fout, "Rule 19 \t range -> IDENTIFIER RANGE_KW IDENTIFIER \n") ;
	};
	| INTEGER_CONSTANT RANGE_KW INTEGER_CONSTANT
	{
		fprintf(fout, "Rule 20 \t range -> INTEGER_CONSTANT RANGE_KW INTEGER_CONSTANT \n") ;
	};
	| arithmetic_expressions RANGE_KW arithmetic_expressions
	{
		fprintf(fout, "Rule 21 \t range -> arithmetic_expressions RANGE_KW arithmetic_expressions \n") ;
	};




initializer : '{'initializer_list'}' 
	{
		fprintf(fout, "Rule 22 \t initializer -> {initializer_list}  \n") ;
	
	};




initializer_list : constant_expressions 
	{
		fprintf(fout, "Rule 23 \t initializer_list -> constant_expressions  \n") ;

	};
	
	| constant_expressions ',' initializer_list 
	{
		fprintf(fout, "Rule 24 \t initializer_list -> constant_expressions , initializer_list  \n") ;

	};	
	
	
procedure_list: procedure_list procedure 
	{
		fprintf(fout, "Rule  25 \t procedure_list -> procedure_list procedure   \n") ;
	};
	| procedure
	{
		fprintf(fout, "Rule  26 \t procedure_list -> procedure  \n") ;
	};
	
	
procedure : PROCEDURE_KW IDENTIFIER parameters '{' declarations_list block '}' ';'	
	{
		fprintf(fout, "Rule 27 \t procedure ->  PROCEDURE_KW IDENTIFIER parameters {declarations_list block } ;	  \n") ;

	};
	
parameters : '(' declarations_list ')'
	{
		fprintf(fout, "Rule 28 \t parameters -> ( declarations_list )  \n") ;

	};
	
block : '{' statement_list '}'
	{
		fprintf(fout, "Rule 29 \t block -> {statement_list}  \n") ;

	};
	
	
statement_list : statement ';' 
	{
		fprintf(fout, "Rule 30 \t statement_list -> statement;  \n") ;

	};
	| statement_list statement ';'		
	{
		fprintf(fout, "Rule 31 \t statement_list -> statement_list statement ;  \n") ;

	};
	| ';'
	{
		fprintf(fout, "Rule 32 \t statement_list -> ;  \n") ;
	};
	
statement : IDENTIFIER ASSIGN_KW expressions 
	{
		fprintf(fout, "Rule 33 \t statement -> IDENTIFIER ASSIGN_KW expressions  \n") ;

	};
	| IF_KW bool_expressions THEN_KW statement 
	{
		fprintf(fout, "Rule 34 \t statement -> IF_KW bool_expressions THEN_KW statement   \n") ;

	};
	
	| IF_KW bool_expressions THEN_KW statement ELSE_KW statement 
	{
		fprintf(fout, "Rule 35 \t statement -> IF_KW bool_expressions THEN_KW statement ELSE_KW statement   \n") ;

	};
	
	| DO_KW statement WHILE_KW bool_expressions 
	{
		fprintf(fout, "Rule 36 \t statement -> DO_KW statement WHILE_KW bool_expressions   \n") ;

	};
	| FOR_KW IDENTIFIER IN_KW range REPEAT_KW statement
	{
		fprintf(fout, "Rule 37 \t statement ->  FOR_KW IDENTIFIER IN_KW range REPEAT_KW statement  \n") ;

	};
 	| SWITCH_KW expressions caseelement default END_KW 
 	{
		fprintf(fout, "Rule 38 \t statement -> SWITCH_KW expressions caseelement default END_KW  \n") ;

 	};
 	| IDENTIFIER '('arguments')' 
 	{
		fprintf(fout, "Rule 39 \t statement -> IDENTIFIER '('arguments')'  \n") ;

 	};
 	| RETURN_KW expressions 
 	{
		fprintf(fout, "Rule 40 \t statement -> RETURN_KW expressions   \n") ;

 	};
 	| EXIT_KW WHEN_KW '('bool_expressions')' 
 	{
		fprintf(fout, "Rule 41 \t statement -> EXIT_KW WHEN_KW (bool_expressions)   \n") ;

 	};
 	| block 
 	{
		fprintf(fout, "Rule 42 \t statement -> block  \n") ;

 	};
 
	
	
arguments : declarator_list 
	{
		fprintf(fout, "Rule 43 \t arguments -> declarator_list  \n") ;

	};

	
caseelement: CASE_KW INTEGER_CONSTANT ':' block ';' 
	{
		fprintf(fout, "Rule 44 \t caseelement ->  CASE_KW INTEGER_CONSTANT:block ;   \n") ;

	};
	| caseelement CASE_KW INTEGER_CONSTANT ':' block ';'
	{
		fprintf(fout, "Rule 45 \t caseelement -> caseelement CASE_KW INTEGER_CONSTANT : block ;  \n") ;

	};

default : DEFAULT_KW ':' block ';' 
	{
		fprintf(fout, "Rule 46 \t default -> DEFAULT_KW ':' block ';'   \n") ;

	};

expressions : constant_expressions 
	{
		fprintf(fout, "Rule 47 \t expressions -> constant_expressions  \n") ;

	};
	| bool_expressions 
	{
		fprintf(fout, "Rule 48 \t expressions -> bool_expressions  \n") ;

	};
	| arithmetic_expressions 
	{
		fprintf(fout, "Rule 49 \t expressions -> arithmetic_expressions  \n") ;

	};
	|IDENTIFIER 
	{
		fprintf(fout, "Rule 50 \t expressions -> IDENTIFIER  \n") ;

	};
	| '('expressions')'
	{
		fprintf(fout, "Rule 51 \t expressions -> (expressions)  \n") ;

	};
	
constant_expressions : INTEGER_CONSTANT 
	{
		fprintf(fout, "Rule 52 \t constant_expressions -> INTEGER_CONSTANT  \n") ;

	};
	| REAL_CONSTANT
	{
		fprintf(fout, "Rule 53 \t constant_expressions -> REAL_CONSTANT  \n") ;

	};
	| CHAR_CONSTANT 
	{
		fprintf(fout, "Rule 54 \t constant_expressions -> CHAR_CONSTANT  \n") ;

	};
	| BOOLEAN_CONSTANT
	{
		fprintf(fout, "Rule 55 \t constant_expressions -> BOOLEAN_CONSTANT  \n") ;

	};
	
bool_expressions : expressions LT_KW expressions 
	{
		fprintf(fout, "Rule 56 \t bool_expressions ->  expressions < expressions  \n") ;

	};
	| expressions LE_KW expressions 
	{
		fprintf(fout, "Rule 57 \t bool_expressions ->  expressions <= expressions  \n") ;

	};
	| expressions GT_KW expressions 
	{
		fprintf(fout, "Rule 58 \t bool_expressions ->  expressions > expressions  \n") ;

	};
	| expressions GE_KW expressions 
	{
		fprintf(fout, "Rule 59 \t bool_expressions ->  expressions >= expressions  \n") ;

	};
	|expressions EQ_KW expressions 
	{
		fprintf(fout, "Rule 60 \t bool_expressions ->  expressions = expressions  \n") ;

	};
	| expressions NE_KW expressions 
	{
		fprintf(fout, "Rule 61 \t bool_expressions ->  expressions != expressions  \n") ;

	};
	| expressions AND_KW expressions 
	{
		fprintf(fout, "Rule 62 \t bool_expressions ->  expressions AND_KW expressions  \n") ;

	};
	| expressions OR_KW expressions 
	{
		fprintf(fout, "Rule 63 \t bool_expressions -> expressions OR_KW expressions   \n") ;

	};
	| expressions AND_KW THEN_KW expressions 
	{
		fprintf(fout, "Rule 64 \t bool_expressions -> expressions AND_KW THEN_KW expressions   \n") ;

	};
	| expressions OR_KW ELSE_KW expressions 
	{
		fprintf(fout, "Rule 65 \t bool_expressions ->  expressions OR_KW ELSE_KW expressions   \n") ;

	};
	| NOT_KW expressions
	{
		fprintf(fout, "Rule 66 \t bool_expressions ->  NOT_KW expressions  \n") ;

	};

arithmetic_expressions : expressions PLUS_KW expressions 
	{
		fprintf(fout, "Rule 67 \t arithmetic_expressions -> expressions + expressions   \n") ;

	};
	| expressions MINUS_KW expressions 
	{
		fprintf(fout, "Rule 68 \t arithmetic_expressions -> expressions - expressions   \n") ;

	};
	| expressions MULTIPLY_KW expressions 
	{
		fprintf(fout, "Rule 69 \t arithmetic_expressions -> expressions * expressions   \n") ;

	};
	| expressions DIVIDE_KW expressions 
	{
		fprintf(fout, "Rule 70 \t arithmetic_expressions -> expressions / expressions   \n") ;

	};
	| expressions MOD_KW expressions 
	{
		fprintf(fout, "Rule 71 \t arithmetic_expressions -> expressions [divide] expressions   \n") ;

	};
	| MINUS_KW expressions
	{
		fprintf(fout, "Rule 72 \t arithmetic_expressions -> - expressions   \n") ;

	};

%%

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
