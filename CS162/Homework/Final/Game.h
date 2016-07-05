#ifndef GAME_H
#define GAME_H

#include "Floor.h"
#include "Ghost.h"
#include "Player.h"
#include <time.h>
#include <cmath>

using namespace std;

class Game
{
	private:
		Floor curr;     //Used as test floor
        Floor floors[3];
        int bob;        //Floor Number(Had a friend name variable)
		char input;
		Player p;
		Ghost g[3];
        int random;
        bool chase;
		bool end;
	public:
		Game();
		void play();
		void instruct();
		void print();
        void check();
        void checkGhost();
        char moveGhost();
		char select();
        void congrats();
};

#endif
