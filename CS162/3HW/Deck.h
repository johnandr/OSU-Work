#ifndef DECK_H
#define DECK_H

#include "Card.h"

using namespace std;

class Deck : public Card
{
	private:
		Card deck[52]; //This is a deck of 52 cards
		int top;
	public:
		Deck();
		void shuffleDeck();
		void displayDeck();
		Card dealCard();
		void swapCards(int,int);
};

#endif
