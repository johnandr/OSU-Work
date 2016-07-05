#include "Ghost.h"

using namespace std;

/*************************
 ** Function: Test Ghost Constructor
 ** Description: Sets testing values for Ghost
 **              **UPDATE**
 **              Final Ghost Constructor
 ************************/

Ghost::Ghost()
{
	sym = 'G';
	xpos = 14;  //UNNECESSARY   **Gets Overwritten
	ypos = 8;   //UNNECESSARY   **Gets Overwritten
	count = 5;
    shift = 1;
}

/*************************
 ** Function: Designted Ghost Consructor
 ** Description: Sets values of Ghost character
 **              **UNUSED**
 ************************/

Ghost::Ghost(int x,int y)
{
	sym = 'G';
	xpos = x;
	ypos = y;
	count = 5;
    shift = 1;
}

/*************************
 ** Function: setPos
 ** Description: Sets position of Ghost
 ** Input: X/Y position
 ** Output: X/Y position of Ghost
 ************************/

void Ghost::setPos(int x, int y)
{
    xpos = x;
    ypos = y;
}

/*************************
 ** Function: getX
 ** Description: Send X position of Ghost
 ** Input: N/A
 ** Output: X position of Ghost
 ************************/

int Ghost::getX()
{
	return xpos;
}

/*************************
 ** Function: getY
 ** Description: Send Y position of Ghost
 ** Input: N/A
 ** Output: Y position of Ghost
 ************************/

int Ghost::getY()
{
	return ypos;
}

/*************************
 ** Function: getSym
 ** Description: Send symbol character of Ghost
 ** Input: N/A
 ** Output: Symbol character of Ghost
 ************************/

char Ghost::getSym()
{
	return sym;
}

/*************************
 ** Function: move
 ** Description: Shift Ghost position
 ** Input: N/A
 ** Output: Updated Ghost position
 ************************/

void Ghost::move(char N)
{
    switch(N)
    {
    case 'W' :
        ypos = ypos - 1;
        break;
    case 'S' :
        ypos = ypos + 1;
        break;
    case 'A' :
        xpos = xpos - 1;
        break;
    case 'D' :
        xpos = xpos + 1;
        break;
    default :
        break;
    }
/*	xpos = xpos + shift;

	count++;
	if(count == 10)
	{
		shift = shift * -1;
		count = 0;
	}*/
}
