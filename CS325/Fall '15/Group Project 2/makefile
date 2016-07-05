default: prog

gPro2.o: gPro2.c
	gcc -Wall -g -std=c99 -c gPro2.c

prog: gPro2.o
	gcc -Wall -g -std=c99 -o prog gPro2.o

clean:
	rm prog
