//Nathan Terrell
//Section 01

#include "stdafx.h"
#include "Fighter.h"


int main()
{
	//Makes players
	Fighter* normal = new Fighter();
	Fighter* params = new Fighter("Kim Possible", 11, 10, 9, 13, 18);

	//Prints players
	normal->printFighter();
	params->printFighter();

	delete normal;
	delete params;

    return 0;
}

