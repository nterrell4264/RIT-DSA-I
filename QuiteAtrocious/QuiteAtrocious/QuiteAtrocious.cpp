//Nathan Terrell
//Section 01

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	char string[36] = "supercalifragilistic";
	cout << "String length: " << strlen(string) << endl;
	strcat_s(string, "expialidocious");
	int iCount = 0;
	for (char letter : string) {
		if (letter == 'i') iCount++;
	}
	cout << "Number of i\'s: " << iCount << endl;

    return 0;
}

