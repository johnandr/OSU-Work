CXX = g++
CXXFLAGS = -std=c++0x
OBJS = Card.o Main.o Deck.o Player.o Poker.o 
SRCS = Card.cpp Main.cpp Deck.cpp Player.cpp StudPoker.cpp Poker.cpp DrawPoker.cpp
HEADERS = Card.h Deck.h Player.h Poker.h StudPoker.h DrawPoker.h

play: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o play

clean:
	rm -f *.o play
