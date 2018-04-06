//Nathan Terrell
//Section 01

#include "stdafx.h"
#include "Level.h"
#include <iostream>
#include <memory>
#include <crtdbg.h>
using namespace std;

void createSmart(){
	shared_ptr<Level> level(new Level());
}

void createDumb() {
	Level* level = new Level();
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//createSmart();
	createDumb();
    return 0;
}

