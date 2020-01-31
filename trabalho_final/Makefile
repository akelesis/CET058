compile: parser.y flex.l
	bison -d parser.y
	flex flex.l
	gcc -o parser.x parser.tab.c lex.yy.c -ll 