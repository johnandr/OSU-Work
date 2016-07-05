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
        bool see[20][31];
	public:
		Floor();
		void setFloor(int);
        void setTile(int,int,char);
		void printFloor();
		char getTile(int,int);
        bool getSee(int,int);
        void setSee(int,int);
};

#endif
