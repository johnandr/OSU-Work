CC = g++
prog_file = lab1
$(prog_file): mult_div.o prog.o
	$(CC) mult_div.o prog.o -o $(prog_file) 
mult_div.o: mult_div.cpp
	$(CC) -c mult_div.cpp 
prog.o: prog.cpp 
	$(CC) -c prog.cpp


prog_file = lab2
$(prog_file): encript.o
	$(CC) encript.o -o$(prog_file)
encript.o: encript.cpp
	$(CC) -c encript.cpp

clean: 
	rm -f *.out *.o $(prog_file)
