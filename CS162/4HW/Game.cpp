#include "Game.h"

using namespace std;
 
/*************************
 ** Function: Game Constructor
 ** Description: Set all values for Game
 ************************/

Game::Game()
{
    g[0].setPos(14,8);
    g[1].setPos(14,8);
    g[2].setPos(14,1);
    floors[0].setFloor(0);
    floors[1].setFloor(1);
    floors[2].setFloor(2);
    bob = 0;
	end = false;
}

/*************************
 ** Function: play
 ** Description: Uses functions and variables of game to play game
 ************************/

void Game::play()
{
	instruct();
	print();
        //loop used to test  
        //for(int k = 0; k < 100; k++)
    while(end == false)
    {
	    input = select();	
    	p.move(input);
    	g[bob].move('N');
        check();
	    print();
	}
    congrats();
}

/*************************
 ** Function: select
 ** Description: Set input from user, error check invalid input
 ** Input: Player motion (WASD or UZ)
 ** Output: Proper character user inputted
 ************************/

char Game::select()
{
	char i;
	cin >> i;
	switch(i)
	{
	case 'w' :
		if(floors[bob].getTile(p.getY() - 1,p.getX()) == '#')
		{
			//cout << floors[bob].getTile(p.getY() - 1,p.getX());
			cout << "There's a wall there, Try Again" << endl;
			select();
			break;
		}
        if(floors[bob].getTile(p.getY() - 1,p.getX()) == 'D' && p.getKey() == 0)
        {
            cout << "You need a key (K)" << endl;
            select();
            break;
        }    
			return i;
	case 'a' :
		if(floors[bob].getTile(p.getY(), p.getX() - 1) == '#' || p.getX() - 1 < 0)
		{
			//cout << floors[bob].getTile(p.getY(),p.getX() - 1);
			cout << "There's a wall there, Try Again" << endl;
			select();
			break;
		}		
        if(floors[bob].getTile(p.getY(),p.getX() - 1) == 'D' && p.getKey() == 0)
        {
            cout << "You need a key (K)" << endl;
            select();
            break;
        }    
			return i;
	case 's' :
		if(floors[bob].getTile(p.getY() + 1,p.getX()) == '#')
		{
			//cout << floors[bob].getTile(p.getY() + 1,p.getX());
			cout << "There's a wall there, Try Again" << endl;
			select();
			break;
		}		
        if(floors[bob].getTile(p.getY() + 1,p.getX()) == 'D' && p.getKey() == 0)
        {
            cout << "You need a key (K)" << endl;
            select();
            break;
        }    
			return i;
	case 'd' :
		if(floors[bob].getTile(p.getY(),p.getX() + 1) == '#')
		{
			//cout << floors[bob].getTile(p.getY(),p.getX() + 1);
			cout << "There's a wall there, Try Again" << endl;
			select();
			break;
		}		
        if(floors[bob].getTile(p.getY(),p.getX() + 1) == 'D' && p.getKey() == 0)
        {
            cout << "You need a key (K)" << endl;
            select();
            break;
        }    
			return i;
    case 'u' :
        if(floors[bob].getTile(p.getY(),p.getX()) == 'U') 
        /*(floors[bob].getTile(p.getY(),p.getX()) == 'A' && bob == 0) || 
          (floors[bob].getTile(p.getY(),p.getX()) == 'B' && bob == 1)*/
        {
            cout << "You went UP" << endl;
            bob++;
            break;
        }
            cout << floors[bob].getTile(p.getY(),p.getX()) << endl;
            cout << "You need to be on a ladder (U) to go up" << endl;
            select();
            break;
    case 'z' :
        if(floors[bob].getTile(p.getY(),p.getX()) == 'Z') 
        /*(floors[bob].getTile(p.getY(),p.getX()) == 'A' && bob == 1) || 
          (floors[bob].getTile(p.getY(),p.getX()) == 'B' && bob == 2)*/
        {
            cout << "You went DOWN" << endl;
            bob--;
            break;
        }
            cout << "You need to be on a ladder (Z) to go down" << endl;
            select();
            break;
    default :
		cout << "Not a valid input" << endl;
		select();
        break;
	}
}

/*************************
 ** Function: check
 ** Description: Check player's position for special tiles
 ** Input: Player's position in relation to Ghost's position and tile on Floor
 ** Output: Clear tile if specified and add items to Player/reset if Player "dies"
 ************************/

void Game::check()
{
        //Checking for Ghost
    if((p.getX() == g[bob].getX() && p.getY() == g[bob].getY() && p.getInv() == 0) ||
       (p.getX() + 1 == g[bob].getX() && p.getY() == g[bob].getY() && p.getInv() == 0) ||
       (p.getX() - 1 == g[bob].getX() && p.getY() == g[bob].getY() && p.getInv() == 0) ||
       (p.getX() == g[bob].getX() && p.getY() + 1 == g[bob].getY() && p.getInv() == 0) ||
       (p.getX() == g[bob].getX() && p.getY() - 1 == g[bob].getY() && p.getInv() == 0))
    {
        p.reset();
        bob = 0;
    }
        //Checks for a Key
    if(floors[bob].getTile(p.getY(),p.getX()) == 'K' && p.getKey() != 3)
    {
        floors[bob].setTile(p.getY(),p.getX(),' ');
        p.addKey();
    }
        //Checks for a Cherry
    if(floors[bob].getTile(p.getY(),p.getX()) == 'C')
    {
        floors[bob].setTile(p.getY(),p.getX(),' ');
        p.setInv(); 
    }
        //Checks for a Door
    if(floors[bob].getTile(p.getY(),p.getX()) == 'D')
    {
        floors[bob].setTile(p.getY(),p.getX(),' ');
        p.subKey();
    }
        //Checks for the Exit
    if(floors[bob].getTile(p.getY(),p.getX()) == 'X')
    {
        end = true;
        cout << floors[bob].getTile(p.getY(),p.getX()) << endl;
    }
}

/*************************
 ** Function: print
 ** Description: Print Floor/Player/Ghost to screen
 ** Input: Floor tiles/Player Position/Ghost Position
 ** Output: Input onto screen
 ************************/

void Game::print()
{
	cout << "You have " << p.getKey() << " keys" << endl;
    if(p.getInv() != 0)
    {
        cout << "You are invicible for " << p.getInv() << " turns" << endl;
    }
	for(int i=0;i < 20;i++)
	{
		for(int j=0;j <= 30;j++)
		{
			if(j == p.getX() && i == p.getY())
			{
				cout << p.getSym();
			}else if(j == g[bob].getX() && i == g[bob].getY())
			{
				cout << g[bob].getSym();
			}else
			{
				cout << floors[bob].getTile(i,j);
			}
		}
	}
	cout << endl;
}

/*************************
 ** Function: instruct
 ** Description: Give inscructions to user on how to play game
 ************************/

void Game::instruct()
{
	cout << "Welcome to the MAZE GAME!" << endl;
	cout << "You are P and you are trying to escape" << endl;
	cout << "THE MAZE OF FRUSTRATION" << endl;
	cout << "W - Move Up" << endl 
         << "A - Move Left" << endl 
         << "S - Move Down" << endl 
         << "D - Move Right" << endl;
	cout << "ENJOY!" << endl << endl;
}

/*************************
 ** Function: congrats
 ** Description: Prompt user they finished the maze
 ************************/

void Game::congrats()
{
/*  cout << "  ______  ______  __   __  _______  ______  ______  ______  ______" << endl;
    cout << " /\  ___\/\  __ \/\ '-.\ \/\  ____\/\  == \/\  __ \/\__  _\/\  ___\\" << endl;
    cout << " \ \ \___\ \ \/\ \ \ \-.  \ \ \___ \ \  __<\ \  __ \/_/\ \/\ \___  \\" << endl;
    cout << "  \ \_____\ \_____\ \_\\'\_\ \______\ \_\ \_\ \_\ \_\ \ \_\ \/\_____\\" << endl;
    cout << "   \/______\/_____/\/_/ \/_/\/______/\/_/ /_/\/_/\/_/  \/_/  \/_____/  " << endl;
*/
    cout << "Congratulations! You completed the" << endl;
    cout << "MAZE OF FRUSTRATION" << endl;
}
