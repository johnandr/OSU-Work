#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int main(int argc, char const *argv[])
{
	struct gameState game;

	int i, j, testCase;
	int check = 0;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	int myCard = salvager;
	int choices = -1;
	int pos = -1;
	int * myBonus = 0;
	int myCoins;
	int myBuys;

	for(i = 2; i < MAX_PLAYERS + 1; i++)
	{
		for(j = 1; j < 10; j++)
		{
			initializeGame(i, k, j, &game); // (PLAYERS, CARDS, SEED, GAME)

			// COINS OF GAME BEFORE CALLING FUNCTION
			myCoins = game.coins;
			myBuys = game.numBuys;

			testCase = cardEffect(myCard, 1, choices, choices, &game, pos, myBonus);

			if(testCase == -1)
			{	// FAILED
				printf("ERROR : cardtest2 (SALVAGER) cardEffect returned -1\n");
				check = 1;
			}else
			{
				if(game.numBuys != myBuys + 1)
				{
					printf("ERROR : numBuys don't match, myNum : %d, gameNum : %d\n", myBuys, game.numBuys);
					check = 1;
				}
				myCoins = myCoins + getCost(handCard(choices, &game));
				if(myCoins != game.coins)
				{
					printf("ERROR : myCoins don't match, myCoins : %d, gameCoin : %d\n", myCoins, game.coins);
					check = 1;
				}
			}
		}
	}

	if(check == 0)
	{ 
		printf("Salvager shows no errors! YAY\n");
	}

	return 0;
}
