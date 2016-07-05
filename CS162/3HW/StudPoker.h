#ifndef STUDPOKER_H
#define STUDPOKER_H

#include "Poker.h"

using namespace std;

class StudPoker : public Poker
{
	private:
		Player *aPlayer;
		Deck aDeck;
		int rounds;
		int games;
		int players;
		int pot;
	public:
		StudPoker();
		StudPoker(int,int);
		void makePlayers(int);
		void dealHand(int,int);
		void placeBets(int);
		void play(int,int);
		void checkWinner(int);
		void finalCheck(int);
};

#endif
