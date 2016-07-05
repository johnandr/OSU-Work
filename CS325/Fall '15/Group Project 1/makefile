default: prog

gPro1.o: gPro1.c
	gcc -Wall -g -std=c99 -c gPro1.c

prog: gPro1.o
	gcc -Wall -g -std=c99 -o prog gPro1.o

clean:
	rm prog
