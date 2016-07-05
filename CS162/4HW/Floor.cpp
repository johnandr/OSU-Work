#include "Floor.h"

using namespace std;

/*************************
 ** Function: Initial Floor Constructor
 ** Description: Test Floor 
 **              **UPDATE** 
 **              Final floor constructor
 ************************/

Floor::Floor()
{
    //Set test floor
	//setFloor(0);
}

/*************************
 ** Function: setTile
 ** Description: Give tile a new character
 ** Input: X/Y position, new Character
 ** Output: New character in specified tile
 ************************/

void Floor::setTile(int x, int y, char r)
{
    tile[x][y] = r;
}

/*************************
 ** Function: getTile
 ** Description: Send specified tile of floor
 ** Input: X/Y position
 ** Output: Character of specified tile
 ************************/

char Floor::getTile(int x, int y)
{
	return tile[x][y];
}

/*************************
 ** Function: setFloor
 ** Description: Read in specified txt file/input characters of txt file into 2D array of "tiles"
 ** Input: Floor Number (0,1,2)
 ** Output: Sets txt file into Floor class
 ************************/

void Floor::setFloor(int f)
{
    ifstream is;

	if(f == 0)
	{
		is.open("FloorA.txt");
	}
	else if(f == 1)
	{
		is.open("FloorB.txt");
	}
	else if(f == 2)
	{
		is.open("FloorC.txt");
	}else
    {
        //Never happens
        cout << "yeah you messed up..." << endl;
    }
        //Used for original test to move Player
	    //ifstream is("FloorA.txt");
	for(int i=0;i < 20;i++)
	{
		for(int j=0;j <= 30;j++)
		{
			tile[i][j] = is.get();
		}
	}
	is.close();	
}

/*************************
 ** Function: printFloor()
 ** Descrpition: First used to test printing floor
 **              **UPDATE**
 **              Unused fuction call/Used in Game Class
 ************************/

void Floor::printFloor()
{
	cout << endl;
	for(int i=0;i < 20;i++)
	{
		for(int j=0;j <= 30;j++)
		{
			cout << tile[i][j];
		}
	}
	cout << endl;
}
