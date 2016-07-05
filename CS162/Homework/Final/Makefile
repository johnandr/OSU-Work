CXX = g++
CXXFLAGS = -g -std=c++0x
OBJS = Player.o Main.o
SRCS = Player.cpp Main.cpp Floor.cpp Game.cpp Ghost.cpp
HEADERS = Floor.h Character.h Ghost.h Player.h Game.h

game: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o game

clean:
	rm -f *.o game
