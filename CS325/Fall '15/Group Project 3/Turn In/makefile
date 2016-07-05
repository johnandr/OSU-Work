default: prog

mostMagic.o: mostMagic.c
	gcc -Wall -g -std=c99 -c mostMagic.c

prog: mostMagic.o
	gcc -Wall -g -std=c99 -o prog mostMagic.o

clean:
	rm prog mostMagic.o
