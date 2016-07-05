/**********************
 ** This was made by Andrew Johnson
 ** CS162 Final Maze Project
 ** ENJOY!
 *********************/

#include "Player.h"
#include "Character.h"
#include "Floor.h"
#include "Game.h"

using namespace std;

int main()
{
    srand(time(NULL)); // SEED THOSE RANDOM NUMBERS :D
	Game g;
	g.play();

    return 0;
}
