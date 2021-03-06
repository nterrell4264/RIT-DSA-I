//Nathan Terrell
//Section 01

#include "stdafx.h"
#include "Hangman.h"

void showGallows(int guessLimit) {
	cout << "  X" << endl;
	cout << "______" << endl;
	cout << "|";
	if (guessLimit > 0) cout << "  |";
	cout << endl;
	cout << "|";
	if (guessLimit > 1) cout << "  0";
	cout << endl;
	cout << "|";
	if (guessLimit == 3) cout << "  |";
	if (guessLimit == 4) cout << " /|";
	if (guessLimit >= 5) cout << " /|\\";
	cout << endl;
	cout << "|";
	if (guessLimit > 5) cout << "  |";
	cout << endl;
	cout << "|";
	if (guessLimit > 5) cout << " /";
	if (guessLimit > 6) cout << " \\";
	cout << endl;
	cout << "|" << endl;
}

void showSolved(char word[], char guesses[]) {
	cout << "Incorrect guesses: " << guesses << endl;
	cout << "Word: " << word << endl;
}

