#include "stdafx.h"
#include "GamePlay.h"


GamePlay::GamePlay(const char* field)
{
	name = field;
}


GamePlay::~GamePlay()
{
}

void GamePlay::Update(mutex mtx) {
	for (int i = 1; i <= 10; i++) {
		mtx.lock();
		cout << "Loading " << name << "... " << i << "0%" << endl;
		mtx.unlock();
	}
}
