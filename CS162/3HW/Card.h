#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card
{
	public:
		Card();
		int getCard();
		void setCard(int);
		void displayCard(Card);
		int getRank();
		int getSuit();
	private:
		int rank;
		int suit;
		int id;
};

#endif
