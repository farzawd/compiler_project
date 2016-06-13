flex MyLexer.l
bison -d MyParser.y
gcc lex.yy.c MyParser.tab.h MyParser.tab.c
./a.out
