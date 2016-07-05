#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Poker.h"
#include "DrawPoker.h"
#include "StudPoker.h"

using namespace std;

char choose_game()
{
	char choice;
	cout << "What game do you want to play?" << endl;
	cout << "[s] Stud Poker" << endl;
	cout << "[d] Draw Poker" << endl;
	cin >> choice;

	while( choice != 's' && choice != 'd')
	{
		cout << "Pick a valid option" << endl;
		cin >> choice;
	}

	return choice;
}

int players()
{
	int num;
	cout << "How many players are there?" << endl;
	cout << "2-6" << endl;
	cin >> num;

	while(num < 2 || num > 6)
	{
		cout << "Invalid number of players" << endl;
		cin >> num;
	}
	
	return num;
}

int games()
{
	int num;
	cout << "How many games do you want to play?" << endl;
	cin >> num;
	
	return num;
}

int main() 
{
	srand(time(NULL)); //SEED IT!

	Poker *game;
	char game_choice;
	int num_of_players;
	int num_of_games;
//	game_choice = choose_game();
//	num_of_players = players();	
//	num_of_games = games();
	//Deck aDeck;

	if(game_choice == 's')
	{
		cout << "You choose Stud" << endl;
		game = new StudPoker(num_of_games, num_of_players);
	}
	else if(game_choice == 'd')
	{
		cout << "You choose Draw" << endl;
		game = new DrawPoker;
	}
//	game->play(num_of_games, num_of_players);
	
	Player one;
	for(int i = 0; i < 5; i++)
	{
		one.addCard(i);
	}
	one.sortHand(5);
	one.showHand(5);
	one.valueHand();
	cout << one.checkHand() << endl;
	return 0;
} 
