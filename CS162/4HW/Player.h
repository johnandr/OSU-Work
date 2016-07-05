#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

using namespace std;

class Player : public Character
{
	private:
		//int xloc;
		//int yloc;
		//int sym;
		int keys;
		int inv;
	public:
		Player();
		void move(char);
		int getX();
		int getY();
		char getSym();
        int getKey();
        int getInv();
        void subKey();
        void setInv();
        void addKey();
        void reset();
};

#endif
