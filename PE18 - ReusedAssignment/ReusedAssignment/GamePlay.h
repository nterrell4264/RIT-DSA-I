#pragma once

#include <string>
#include <iostream>
using namespace std;

class GamePlay
{
public:
	GamePlay(const char* field);
	~GamePlay();

	string name;

	void Update();
};

