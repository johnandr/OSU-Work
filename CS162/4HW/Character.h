#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

using namespace std;

class Character
{
    protected:
        int xpos;
        int ypos;
        char sym;
	public:
		virtual void move(char) = 0;
        virtual int getX() = 0;
        virtual int getY() = 0;
        virtual char getSym() = 0;
};

#endif
