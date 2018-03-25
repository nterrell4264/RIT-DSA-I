#pragma once
#include <string>
using namespace std;
class Level
{
public:
	Level();
	Level(string playedAs, string upgradeName, int levelNum);
	~Level();

	string character;
	string upgrade;
	int order;
};

