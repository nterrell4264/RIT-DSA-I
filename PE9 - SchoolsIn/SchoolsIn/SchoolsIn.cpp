//Nathan Terrell
//Section 01

#include "stdafx.h"
#include "Player.h"


int main()
{
	//Makes players
	Player defStack = Player();
	Player parStack = Player("Robert'); DROP TABLE students;--", 8, 2, 17, 13);
	Player* defHeap = new Player();
	Player* parHeap = new Player("Help I'm trapped in a driver's license factory", 10, 14, 8, 13);

	//Prints players
	defStack.printPlayer();
	parStack.printPlayer();
	defHeap->printPlayer();
	parHeap->printPlayer();

	delete defHeap;
	delete parHeap;

    return 0;
}

