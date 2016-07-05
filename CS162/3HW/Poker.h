#ifndef POKER_H
#define POKER_H

#include "Player.h"

class Poker : public Player
{
	public:
		Poker();
		//Poker(int,int);
		virtual void play(int, int) = 0;
};
/*
Poker::Poker(){}

//Poker::Poker(int a,int b){}

void Poker::play(int a, int b)
{
	cout << a << "many games" << endl;
	cout << b << "many players" << endl;
	cout << "still in POKER" << endl;
}
*/
#endif
