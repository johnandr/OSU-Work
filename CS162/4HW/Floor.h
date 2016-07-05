#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include <fstream>
#include "Player.h"

using namespace std;

class Floor
{
	private:
		char tile[20][31];
	public:
		Floor();
		void setFloor(int);
        void setTile(int,int,char);
		void printFloor();
		char getTile(int,int);
};

#endif
