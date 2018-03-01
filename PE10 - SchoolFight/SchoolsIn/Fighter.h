#pragma once
#include "Player.h"
class Fighter :
	public Player
{
public:
	Fighter();
	Fighter(const char* student, int eng, int soc, int mth, int sci, int skl);
	~Fighter();

	int skill;
	void printFighter();
};

