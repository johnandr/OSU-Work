#include "Player.h"

Player::Player()
{
	money = 50; 
	first.shuffleDeck();
	playing = true;
}

bool Player::getPlaying()
{
	return playing;
}

void Player::showHand(int turn)
{
	for(int i = 0; i < turn; i++)
	{
		Card j = hand[i];
		displayCard(j);
	}
}

void Player::addCard(int i)
{
// 	for(int i = 0; i < 5; i++)
//	{
		hand[i] = first.dealCard();
//	}
}

void Player::sortHand(int r)
{
	bool sort;
	Card temp;
	do
	{
		sort = true;
		for(int i = 0; i < r; i++)
		{
			if(hand[i].getRank() > hand[i + 1].getRank())
			{
				temp = hand[i];
				hand[i] = hand[i + 1];
				hand[i + 1] = temp;
				sort = false;
			}
		}
	}while(!sort);
}

int Player::makeBet()
{
	int bet;

	if(money < 0)
	{
		playing = false;
		bet = 0;
	}
	else
	{
		cout << "How much money do you want to bet?" << endl;
		cout << "You have " << money << " dollars" << endl;
		cin >> bet;
		while(bet < 0)
		{
			cout << "You can't bet a negative number" << endl;
			cin >> bet;
		}
	}

	if(bet == 0)
	{
		playing = false;
	}
	money = money - bet;

	return bet;
}

int Player::checkHand()
{
	bool straight = false;
	bool flush = false;
	int clubs = 0;
	int spades = 0;
	int hearts = 0;
	int diamonds = 0;

	//check for flush
	for(int i = 0; i < 5; i++)
	{
		int x = hand[i].getSuit();
		switch (x)
		{
			case 0:
				diamonds++;
				break;
			case 1:
				hearts++;	
				break;
			case 2:
				spades++;
				break;
			case 3:
				clubs++;
				break;
		}
	}
	
	if(clubs == 5 || spades == 5 || hearts ==5 || diamonds == 5)
	{
		flush = true;
	}

	//check for straight
	if(hand[1].getRank() == hand[0].getRank() + 1 &&
	   hand[2].getRank() == hand[1].getRank() + 1 &&
	   hand[3].getRank() == hand[2].getRank() + 1 &&
	   hand[4].getRank() == hand[3].getRank() + 1)
	{
		straight = true;
	}
	   
	//Check for Straight flush
	if(straight == true && flush == true)
	{
		return 8;
	}

	//Check for 4 of a Kind
	if(hand[0].getRank() == hand[1].getRank() && 
	   hand[1].getRank() == hand[2].getRank() &&
	   hand[2].getRank() == hand[3].getRank())
	{
		return 7;
	}
	if(hand[1].getRank() == hand[2].getRank() && 
	   hand[2].getRank() == hand[3].getRank() &&
	   hand[3].getRank() == hand[4].getRank())
	{
		return 7;
	}

	//Check for Full House
	if((hand[0].getRank() == hand[1].getRank() &&
	    hand[1].getRank() == hand[2].getRank() &&
	    hand[3].getRank() == hand[4].getRank()) ||
	   (hand[2].getRank() == hand[3].getRank() &&
	    hand[3].getRank() == hand[4].getRank() &&
	    hand[0].getRank() == hand[1].getRank()))
	{
		return 6;
	}

	//Check for Flush
	if(flush == true)
	{
		return 5;
	}

	//Check for a Straight
	if(straight == true)
	{
		return 4;
	}

	//Check for 3 of a kind
	if((hand[0].getRank() == hand[1].getRank() &&
	    hand[1].getRank() == hand[2].getRank()) ||
	   (hand[1].getRank() == hand[2].getRank() &&
	    hand[2].getRank() == hand[3].getRank()) ||
	   (hand[2].getRank() == hand[3].getRank() &&
	    hand[3].getRank() == hand[4].getRank()))
	{
		return 3;
	}
	
	//Check for 2 pair
	if((hand[0].getRank() == hand[1].getRank() &&
	    hand[2].getRank() == hand[3].getRank()) ||
	   (hand[0].getRank() == hand[1].getRank() &&
	    hand[3].getRank() == hand[4].getRank()) ||
	   (hand[1].getRank() == hand[2].getRank() &&
	    hand[3].getRank() == hand[4].getRank()))
	{
		return 2;
	}

	//Check for pair
	if(hand[0].getRank() == hand[1].getRank() ||
	   hand[1].getRank() == hand[2].getRank() ||
	   hand[2].getRank() == hand[3].getRank() ||
	   hand[3].getRank() == hand[4].getRank())
	{
		return 1;
	} 

	return 0;
}

void Player::valueHand()
{
	value = checkHand();
	switch(value)
	{
		case 1:
			cout << "You have a pair!" << endl;
			break;
		case 2:
			cout << "You have a two pair!" << endl;
			break;
		case 3:
			cout << "You have a three of a kind!" << endl;
			break;
		case 4:
			cout << "You have a straight!" << endl;
			break;
		case 5:
			cout << "You have a flush!" << endl;
			break;
		case 6:
			cout << "You have a Full House!" << endl;
			break;
		case 7:
			cout << "You have a four of a kind!" << endl;
			break;
		case 8:
			cout << "You have a straight flush!" << endl;
			break;
		default:
			cout << "You have a high card!" << endl;
	}
}
