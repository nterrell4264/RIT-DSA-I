#include "stdafx.h"
#include "Fighter.h"
#include <iostream>
using namespace std;


Fighter::Fighter()
{
	skill = 10;
}

Fighter::Fighter(const char* student, int eng, int soc, int mth, int sci, int skl) : Player(student, eng, soc, mth, sci)
{
	skill = skl;
}


Fighter::~Fighter()
{
}

void Fighter::printFighter() {
	Player::printPlayer();
	cout << "Fighting level: " << skill << endl;
}