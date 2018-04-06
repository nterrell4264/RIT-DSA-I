#include "stdafx.h"
#include "Level.h"


Level::Level()
{
	character = "MissingNo.";
	upgrade = "None";
	order = -1;
	printf("Level created\n");
}

Level::Level(string playedAs, string upgradeName, int levelNum)
{
	character = playedAs;
	upgrade = upgradeName;
	order = levelNum;
	printf("Level created\n");
}


Level::~Level()
{
	printf("Level destroyed\n");
}
