flex MyLexer.l
bison -d MyParser.y
g++ lex.yy.c MyParser.tab.h MyParser.tab.c
./a.out
