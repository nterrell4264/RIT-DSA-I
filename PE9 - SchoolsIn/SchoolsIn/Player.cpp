#include "stdafx.h"
#include "Player.h"
#include <iostream>
using namespace std;


Player::Player()
{
	name = "Unknown";
	english = 10;
	socialStudies = 10;
	math = 10;
	science = 10;
}

Player::Player(const char * student, int eng, int soc, int mth, int sci)
{
	name = student;
	english = eng;
	socialStudies = soc;
	math = mth;
	science = sci;
}


Player::~Player()
{
}

void Player::printPlayer()
{
	cout << name << endl;
	cout << "English level: " << english << endl;
	cout << "Social Studies level: " << socialStudies << endl;
	cout << "Math level: " << math << endl;
	cout << "Science level: " << science << endl;
}
