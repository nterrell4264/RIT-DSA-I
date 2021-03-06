//Nathan Terrell
//Section 01

#include "stdafx.h"
#include "Debugging.h"


int main()
{
	srand(NULL);

	cout << "How many random numbers do you want?" << endl;
	int userNum = 0;
	cin >> userNum;

	for (int i = 0; i < userNum; i++) {
		cout << "Number " << i + 1 << ": " << rand() << endl;
	}

	cout << "Give me a string to reverse." << endl;
	char* userStr = new char;
	cin >> userStr;
	char* reverse = reverseString(userStr);
	cout << "The reverse is:" << endl;
	cout << reverse << endl;

    return 0;
}

char* reverseString(char* inputString) {
	char newString[256] = "";
	int len = strlen(inputString);
	for (int i = 0; i < len; i++) {
		char c = inputString[i];
		newString[len - 1 - i] = c;
	}
	strcpy_s(inputString, 128, (const char*)&newString);
	return inputString;
}

