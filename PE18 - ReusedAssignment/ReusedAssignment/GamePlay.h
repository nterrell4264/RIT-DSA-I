#pragma once

#include <string>
#include <iostream>
#include <mutex>
using namespace std;

class GamePlay
{
public:
	GamePlay(const char* field);
	~GamePlay();

	string name;

	void Update();
	//void Update(mutex mtx);
};

