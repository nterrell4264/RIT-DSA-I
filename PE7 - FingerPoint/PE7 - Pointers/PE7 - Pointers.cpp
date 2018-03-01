//Nathan Terrell
//Section 01

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

class MovableObject
{
public:
	int xPos = 0;
	int yPos = 0;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
		name = nullptr;
	}
};

class Monster : public MovableObject
{
public:
	int damage = 0;
};

int main()
{
	Monster *boss = new Monster();
	Player *pOne = new Player();
	//MovableObject *boss = new Monster();
	//MovableObject *pOne = new Player();
	/* The player's destructor isn't called when it is made as a Movable Object, which makes sense because it gets converted after construction. */

	Monster *fakeMonster = (Monster*)pOne;

	cout << "Boss: " << boss << endl;
	cout << "Player: " << pOne << endl;
	cout << "Fake monster: " << fakeMonster << endl;

	pOne->xPos = 1;
	pOne->yPos = 2;

	cout << "Boss: ";
	boss->PrintPos();

	cout << "Player: ";
	pOne->PrintPos();

	cout << "Fake monster: ";
	fakeMonster->PrintPos();

	delete boss;
	delete pOne;
	//delete fakeMonster; //fakeMonster points to pOne, which is already deleted.

	_getch();
    return 0;
}

