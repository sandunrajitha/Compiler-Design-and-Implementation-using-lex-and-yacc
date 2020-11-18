all: calc

calc.tab.c calc.tab.h:	calc.y
	bison -y -d calc.y

lex.yy.c: calc.l calc.tab.h
	flex calc.l

calc: lex.yy.c y.tab.c y.tab.h
	gcc -o calc y.tab.c lex.yy.c calc3b.c

clean:
	rm calc calc.tab.c lex.yy.c calc.tab.h
