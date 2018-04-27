#include "stdafx.h"
#include "GamePlay.h"


GamePlay::GamePlay(const char* field)
{
	name = field;
}


GamePlay::~GamePlay()
{
}

void GamePlay::Update() {
	for (int i = 1; i <= 10; i++) {
		cout << "Loading " << name << "... " << i << "0%" << endl;
	}
}
