#include "StudPoker.h"

StudPoker::StudPoker()
{
	games = 1;
	players = 2;
}

StudPoker::StudPoker(int g, int p)
{
	pot = 0;
	aPlayer = new Player[p];
	games = g;
	players = p;
}

void StudPoker::makePlayers(int num)
{
	Player *aPlayer = new Player[num];
}

void StudPoker::dealHand(int p, int r)
{
	for(int j = 0; j < p; j++)
	{
		aPlayer[j].addCard(r);
	}
}

void StudPoker::placeBets(int p)
{
	int b;

	for(int k = 0; k < p; k++)
	{
		b = aPlayer[k].makeBet();
		pot = pot + b;
	}
}
	
void StudPoker::play(int game, int play)
{
	//Deck deck;
	//Player *aPlayer = new Player[play];
	for(int g = 0; g < game; g++)
	{
		aDeck.shuffleDeck();
		for(int r = 1; r < 6; r++)
		{
			for(int p = 0; p < play; p++)
			{
/*				if(aPlayer[p].getPlaying() == false)
				{}
				else
				{*/	
					//dealHand(p, r);
				aPlayer->getHand(r) = aDeck.dealCard();	
				//	aPlayer[p].addCard(r);
					cout << "Player " << p + 1 <<"'s hand" << endl;
					aPlayer[p].showHand(r);
					placeBets(p);
/*				}*/
				aPlayer[p].sortHand(r);
				aPlayer[p].valueHand();
				cout << endl;
			}
		}
		//checkWinner(play);
	}
	finalCheck(play);
}

void StudPoker::checkWinner(int p)
{
	for(int l = 0; l < p; l++)
	{
		cout << "Player " << l + 1 << endl;
		//aPlayer[l].sortHand();
		//aPlayer[l].valueHand();
		//aPlayer[l].showHand(5);
		//cout << aPlayer[l].valueHand() << endl;
		cout << endl;
	}
	//Player with biggest value
/*	{
		"Player".money = "Player".money + pot;
		pot = 0;
	}*/
}

void StudPoker::finalCheck(int p)
{
	//Determine which player 'x' has greatest money
	//cout << "Player " << x << " wins!" << endl;
}


