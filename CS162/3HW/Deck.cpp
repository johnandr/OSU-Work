#include "Deck.h"

Deck::Deck()
{
	top = 0;
	for(int i = top; i < 52; i++)
	{
		deck[i].setCard(i);
	}
}

void Deck::swapCards(int a, int b)
{
	Card temp = deck[a];
	deck[a] = deck[b];
	deck[b] = temp;
}

void Deck::shuffleDeck()
{
	for(int i = 0; i < 100; i++)
	{
		int a = rand() % 52;
		int b = rand() % 52;
		swapCards(a,b);
	}
	top = 0;
	//displayDeck();
}

void Deck::displayDeck()
{
	for(int i = 0; i < 52; i++)
	{
		Card j = deck[i];
		displayCard(j);
	}
	cout << endl;
}

Card Deck::dealCard()
{
	top++;
	return deck[top - 1];
}
