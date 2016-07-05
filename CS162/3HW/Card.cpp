#include "Card.h"

//Constructor for Class Card
Card::Card() : rank(0), suit(0), id(0)
{}

//Gives value of Card
int Card::getCard()
{
	return id;
}

//Creates value of Card
void Card::setCard(int num)
{
	if(num >= 0 && num < 52)
	{
		id = num;
		rank = id % 13;
		suit = id / 13;
	}
	else
	{
		id = 0;
		rank = 0;
		suit = 0;
	}
}


void Card::displayCard(Card ID)
{
	string Ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
	string Suits[] = { "D", "H", "S", "C"};

	cout << Ranks[ID.rank] << Suits[ID.suit] << endl;
}

int Card::getRank()
{
	return rank;
}

int Card::getSuit()
{
	return suit;
}
