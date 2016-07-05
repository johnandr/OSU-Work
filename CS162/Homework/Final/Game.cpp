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
    chase = false;
}

/*************************
 ** Function: play
 ** Description: Uses functions and variables of game to play game
 ************************/

void Game::play()
{
	instruct();
    check();
	//print();
        //loop used to test  
        //for(int k = 0; k < 100; k++)
    while(end == false)
    {
        //check();
        checkGhost();
	    print();
	    input = select();
        random = moveGhost();
    	g[bob].move(random);
    	p.move(input);
        check();
	}
    print();
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
 ** Function: moveGhost
 ** Description: Uses a random number to generate Ghost's next move
 ** Input: Random number seeded from time
 ** Output: Ghost's next move.
 ************************/

char Game::moveGhost()
{
    int ham;
    ham = rand() % 4;
        //Sorry for it being so long but it just has a lot of checks
    if(chase == true)
    {
        if((abs(g[bob].getX() - p.getX())) <= (abs(g[bob].getY() - p.getY())))
        {
            if((g[bob].getX() - p.getX()) == 0)
            {
                if((g[bob].getY() - p.getY()) < 0)
                {
	        	    if((floors[bob].getTile(g[bob].getY() + 1,g[bob].getX()) == '#') ||
	        	       (floors[bob].getTile(g[bob].getY() + 1,g[bob].getX()) == 'D'))
                    {
                        chase = false;
                        return moveGhost();
                    }else
                    {
                        return 'S';
                    }
                }else
                {
	        	    if((floors[bob].getTile(g[bob].getY() - 1,g[bob].getX()) == '#') ||
	        	       (floors[bob].getTile(g[bob].getY() - 1,g[bob].getX()) == 'D'))
                    {
                        chase = false;
                        return moveGhost();
                    }else
                    {
                        return 'W';
                    }
                }
            }else if((g[bob].getX() - p.getX()) < 0)
            {
	        	if((floors[bob].getTile(g[bob].getY(),g[bob].getX() + 1) == '#') ||
	        	   (floors[bob].getTile(g[bob].getY(),g[bob].getX() + 1) == 'D'))
                {
                    if((g[bob].getY() - p.getY()) < 0)
                    {
	        	        if((floors[bob].getTile(g[bob].getY() + 1,g[bob].getX()) == '#') ||
	        	           (floors[bob].getTile(g[bob].getY() + 1,g[bob].getX()) == 'D'))
                        {
                            chase = false;
                            return moveGhost();
                        }else
                        {
                            return 'S';
                        }
                    }else
                    {
	        	        if((floors[bob].getTile(g[bob].getY() - 1,g[bob].getX()) == '#') ||
	        	           (floors[bob].getTile(g[bob].getY() - 1,g[bob].getX()) == 'D'))
                        {
                            chase = false;
                            return moveGhost();
                        }else
                        {
                            return 'W';
                        }
                    }
                }else
                {
	        	        if((floors[bob].getTile(g[bob].getY(),g[bob].getX() + 1) == '#') ||
	        	           (floors[bob].getTile(g[bob].getY(),g[bob].getX() + 1) == 'D'))
                        {
                            chase = false;
                            return moveGhost();
                        }else
                        {
                            return 'D';
                        }
                }
            }else
            {
	        	if((floors[bob].getTile(g[bob].getY(),g[bob].getX() - 1) == '#') ||
	        	   (floors[bob].getTile(g[bob].getY(),g[bob].getX() - 1) == 'D'))
                {
                    if((g[bob].getY() - p.getY()) < 0)
                    {
	        	        if((floors[bob].getTile(g[bob].getY() + 1,g[bob].getX()) == '#') ||
	        	           (floors[bob].getTile(g[bob].getY() + 1,g[bob].getX()) == 'D'))
                        {
                            chase = false;
                            return moveGhost();
                        }else
                        {
                            return 'S';
                        }
                    }else
                    {
	        	        if((floors[bob].getTile(g[bob].getY() - 1,g[bob].getX()) == '#') ||
	        	           (floors[bob].getTile(g[bob].getY() - 1,g[bob].getX()) == 'D'))
                        {
                            chase = false;
                            return moveGhost();
                        }else
                        {
                            return 'W';
                        }
                    }
                }else
                {
        	        if((floors[bob].getTile(g[bob].getY(),g[bob].getX() - 1) == '#') ||
        	           (floors[bob].getTile(g[bob].getY(),g[bob].getX() - 1) == 'D'))
                    {
                        chase = false;
                        return moveGhost();
                    }else
                    {
                        return 'A';
                    }
                }
            }

        }else
        {
            if((g[bob].getY() - p.getY()) == 0)
            {
                if((g[bob].getX() - p.getX()) < 0)
                {
        	        if((floors[bob].getTile(g[bob].getY(),g[bob].getX() + 1) == '#') ||
        	           (floors[bob].getTile(g[bob].getY(),g[bob].getX() + 1) == 'D'))
                    {
                        chase = false;
                        return moveGhost();
                    }else
                    {
                        return 'D';
                    }
                }else
                {
        	        if((floors[bob].getTile(g[bob].getY(),g[bob].getX() - 1) == '#') ||
        	           (floors[bob].getTile(g[bob].getY(),g[bob].getX() - 1) == 'D'))
                    {
                        chase = false;
                        return moveGhost();
                    }else
                    {
                        return 'A';
                    }
                }
            }else if((g[bob].getY() - p.getY()) < 0)
            {
	        	if((floors[bob].getTile(g[bob].getY() + 1,g[bob].getX()) == '#') ||
	        	   (floors[bob].getTile(g[bob].getY() + 1,g[bob].getX()) == 'D'))
                {
                    if((g[bob].getX() - p.getX()) < 0)
                    {
            	        if((floors[bob].getTile(g[bob].getY(),g[bob].getX() - 1) == '#') ||
            	           (floors[bob].getTile(g[bob].getY(),g[bob].getX() - 1) == 'D'))
                        {
                            chase = false;
                            return moveGhost();
                        }else
                        {
                            return 'D';
                        }
                    }else
                    {
                        if((floors[bob].getTile(g[bob].getY(),g[bob].getX() - 1) == '#') ||
          	               (floors[bob].getTile(g[bob].getY(),g[bob].getX() - 1) == 'D'))
                        {
                            chase = false;
                            return moveGhost();
                        }else
                        {      
                            return 'A';
                        }
                    }
                }else
                {
                    if((floors[bob].getTile(g[bob].getY() + 1,g[bob].getX()) == '#') ||
          	           (floors[bob].getTile(g[bob].getY() + 1,g[bob].getX()) == 'D'))
                    {
                        chase = false;
                        return moveGhost();
                    }else
                    {      
                        return 'S';
                    }
                }
            }else
            {
	        	if((floors[bob].getTile(g[bob].getY() - 1,g[bob].getX()) == '#') ||
	        	   (floors[bob].getTile(g[bob].getY() - 1,g[bob].getX()) == 'D'))
                {
                    if((g[bob].getX() - p.getX()) < 0)
                    {
                        if((floors[bob].getTile(g[bob].getY(),g[bob].getX() + 1) == '#') ||
          	               (floors[bob].getTile(g[bob].getY(),g[bob].getX() + 1) == 'D'))
                        {
                            chase = false;
                            return moveGhost();
                        }else
                        {      
                            return 'D';
                        }
                    }else
                    {
                        if((floors[bob].getTile(g[bob].getY(),g[bob].getX() - 1) == '#') ||
          	               (floors[bob].getTile(g[bob].getY(),g[bob].getX() - 1) == 'D'))
                        {
                            chase = false;
                            return moveGhost();
                        }else
                        {      
                            return 'A';
                        }
                    }
                }else
                {
                    if((floors[bob].getTile(g[bob].getY() - 1,g[bob].getX()) == '#') ||
          	           (floors[bob].getTile(g[bob].getY() - 1,g[bob].getX()) == 'D'))
                    {
                       chase = false;
                       return moveGhost();
                    }else
                    {      
                        return 'W';
                    }
                }
            }
        }    
    }else
    {
    switch(ham)
    {
    case 0 : 
		if((floors[bob].getTile(g[bob].getY() - 1,g[bob].getX()) == '#') ||
		   (floors[bob].getTile(g[bob].getY() - 1,g[bob].getX()) == 'X') ||
		   (floors[bob].getTile(g[bob].getY() - 1,g[bob].getX()) == 'D'))
        {
			moveGhost();
			break;
		}
			return 'W';
	case 1 :
		if((floors[bob].getTile(g[bob].getY(), g[bob].getX() - 1) == '#') ||
		   (floors[bob].getTile(g[bob].getY(), g[bob].getX() - 1) == 'D'))
        {
			moveGhost();
			break;
		}		
			return 'A';
	case 2 :
		if((floors[bob].getTile(g[bob].getY() + 1,g[bob].getX()) == '#') ||
		   (floors[bob].getTile(g[bob].getY() + 1,g[bob].getX()) == 'D'))
        {
			moveGhost();
			break;
		}		
			return 'S';
	case 3 :
		if((floors[bob].getTile(g[bob].getY(),g[bob].getX() + 1) == '#') ||
		   (floors[bob].getTile(g[bob].getY(),g[bob].getX() + 1) == 'D'))

        {
		    moveGhost();
			break;
		}		
			return 'D';
    default :
        moveGhost();
        break;
    }
    }
}

/*************************
 ** Function: checkGhost
 ** Description: Check player's position for special tiles
 ** Input: Player's position in relation to Ghost's position and tile on Floor
 ** Output: Clear tile if specified and add items to Player/reset if Player "dies"
 ************************/

void Game::checkGhost()
{
    if(abs(g[bob].getX() - p.getX()) + abs(g[bob].getY() - p.getY()) < 6)
    {
        chase = true;
        cout << "Chasing!!" << endl;
    }else
    {
        chase = false;
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

        //Fog of War, Player Visibilty
    for(int i = 0; i < 6;i++)
    {
        int j;
        j = 5 - i;
        for(j; j >= 0;j--)
        {
            if(p.getY() - i < 0 || p.getX() - j < 0)
            {
                if(p.getX() - j > 0)
                {
                    floors[bob].setSee(p.getY() + i,p.getX() + j); 
                    floors[bob].setSee(p.getY() + i,p.getX() - j);
                }else if(p.getY() - i > 0)
                {
                    if(p.getY() + i < 20)
                    {
                    floors[bob].setSee(p.getY() + i,p.getX() + j);
                    }
                    floors[bob].setSee(p.getY() - i,p.getX() + j);
                }else
                {   
                    floors[bob].setSee(p.getY() + i,p.getX() + j); 
                }
            }else if(p.getY() + i > 19 || p.getX() + j > 30)
            {
                if(p.getY() + i < 19)
                {
                    floors[bob].setSee(p.getY() - i,p.getX() - j);
                    floors[bob].setSee(p.getY() + i,p.getX() - j);
                }else if(p.getX() + j < 30)
                {
                    floors[bob].setSee(p.getY() - i,p.getX() + j);
                    floors[bob].setSee(p.getY() - i,p.getX() - j);
                }else
                {
                    floors[bob].setSee(p.getY() - i,p.getX() - j);
                }
            }else
            {
                floors[bob].setSee(p.getY() + i,p.getX() + j); 
                floors[bob].setSee(p.getY() + i,p.getX() - j);
                floors[bob].setSee(p.getY() - i,p.getX() + j);
                floors[bob].setSee(p.getY() - i,p.getX() - j);
            }
        }
    }
}

/*************************
 ** Function: print
 ** Description: Print Floor/Player/Ghost to screen
 ** Input: "Visible" Floor tiles/Player Position/Ghost Position
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
            }else
            {
                if(floors[bob].getSee(i,j) == false)
                {
                    if(j == 30)
                    {
                        //cout << floors[bob].getTile(i,j);
                        cout << endl;
                    }else
                    {
                        cout << " ";
                    }
    		    }else if(j == g[bob].getX() && i == g[bob].getY())
    		    {
    			    cout << g[bob].getSym();
    		    }else
    		    {
    			    cout << floors[bob].getTile(i,j);
    		    }
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
/*    cout << "  ______  ______  __   __  _______  ______  ______  ______  ______" << endl;
    cout << " /\\  ___\\/\\  __ \\/\\ '-.\\ \\/\\  ____\\/\\  == \\/\\  __ \\/\\__  _\\/\\  ___\\" << endl;
    cout << " \\ \\ \\___\\ \\ \\/\\ \\ \\ \\-.  \\ \\ \\___ \\ \\  __<\\ \\  __ \\/_/\\ \\/\\ \\___  \\" << endl;
    cout << "  \\ \\_____\\ \\_____\\ \\_\\'\\_\\ \\______\\ \\_\\ \\_\\ \\_\\ \\_\\ \\ \\_\\ \\/\\_____\\" << endl;
    cout << "   \\/______\\/_____/\\/_/ \\/_/\\/______/\\/_/ /_/\\/_/\\/_/  \\/_/  \\/_____/  " << endl;
*/
    cout << "Congratulations! You completed the" << endl;
    cout << "MAZE OF FRUSTRATION" << endl;
}
