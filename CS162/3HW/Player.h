#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Deck.h"

class Player: public Deck
{
	private:
		Card hand[5];
		int money;
		int size;
		Deck first;
		int value; 
		bool playing;

	public:
		Player();
		Card getHand(int r){return hand[r];}
		void showHand(int);
		void addCard(int);
		void sortHand(int);
		int checkHand();
		void valueHand();
		int makeBet();
		bool getPlaying();
};

#endif
