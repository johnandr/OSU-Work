default: prog

maxSubArray.o: maxSubArray.c
	gcc -Wall -g -std=c99 -c maxSubArray.c

prog: maxSubArray.o
	gcc -Wall -g -std=c99 -o prog maxSubArray.o

clean:
	rm prog maxSubArray.o
