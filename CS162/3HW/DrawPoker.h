#ifndef DRAWPOKER_H
#define DRAWPOKER_H

#include "Poker.h"

using namespace std;

class DrawPoker : public Poker
{
	public:
		DrawPoker();
		void play(int, int);
};
/*
DrawPoker::DrawPoker()
{}

void DrawPoker::play(int a, int b)
{
	char ans;
	cout << "You choose draw poker!" << endl;
	cout << "Have I proved I know how to do Polymorphism???" << endl;
	cout << "[y/n]   " << endl;
	cin >> ans;
	if(ans == 'y')
	{
		cout << "Thanks! :D" << endl;
	}
	else
	{
		cout << "Well at least I can say I tried!" << endl;
	}
}
*/
#endif
