#include "Player.h"

using namespace std;

/*************************
 ** Function: Player Constructor
 ** Description: Set Player values
 ************************/

Player::Player()
{
	sym = 'P';
	xpos = 0;
	ypos = 15;
	keys = 0;
	inv = 0;
}

/*************************
 * Function: reset
 * Description: Set player position to beginning
 ************************/

void Player::reset()
{
    xpos = 1;
    ypos = 15;
}

/*************************
 ** Function: getSym
 ** Description: Send Player symbol character
 ************************/

char Player::getSym()
{
	return sym;
}

/*************************
 ** Function: getX
 ** Description: Send Player X Position
 ************************/

int Player::getX()
{
	return xpos;
}

/*************************
 ** Function: getY
 ** Description: Send Player Y position
 ************************/

int Player::getY()
{
	return ypos;
}

/*************************
 ** Function: getSym
 ** Description: Send Player's number of keys
 ************************/

int Player::getKey()
{
    return keys;
}

/*************************
 ** Function: addKey
 ** Description: increment keys by 1
 ************************/

void Player::addKey()
{
    keys++;
}

/*************************
 ** Function: subKey
 ** Description: decrement keys by 1
 ************************/

void Player::subKey()
{
    keys--;
}

/*************************
 ** Function: getInv
 ** Description: Send Player invicibility counter
 ************************/

int Player::getInv()
{
    return inv;
}

/*************************
 ** Function: setInv
 ** Description: Set invicibility counter to 20
 ************************/

void Player::setInv()
{
    inv = 20;
}

/*************************
 ** Function: move
 ** Description: Update Player position and
 **              possibly decrement invincibility counter
 ** Input: User validated input
 ** Output: Updated X or Y Player position
 ************************/

void Player::move(char input)
{
    if(inv > 0)
    {
        inv--;
    }
	//Error check outside of the Class
	switch(input)
	{
	case 'w' :
		ypos = ypos - 1;
		break;
	case 'a' :
		xpos = xpos - 1;
		break;
	case 's' :
		ypos = ypos + 1;
		break;
	case 'd' :
		xpos = xpos + 1;
		break;
	default :
		break;
	}
}
