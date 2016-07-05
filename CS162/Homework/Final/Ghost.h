#ifndef GHOST_H
#define GHOST_H

#include "Character.h"

using namespace std;

class Ghost : public Character
{
	private:
		//int xpos;
		//int ypos;
		//char sym;
        int shift;
		int count;
	public:
		Ghost();
		Ghost(int, int);
		void move(char);
        void setPos(int, int);
		int getX();
		int getY();
		char getSym();
};

#endif
