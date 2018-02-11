#include "stdafx.h"
#include "Hangman.h"

int main() {
	//Variables
	char word[] = "altruism";
	char correctGuesses[9] = "________";
	char incorrectGuesses[8] = {};
	int wrong = 0;
	bool match = false;
	bool win = false;
	//Program
	cout << "Welcome to Hangman!" << endl;
	while (true) {
		showGallows(wrong);
		showSolved(correctGuesses, incorrectGuesses);
		cout << "Guess a letter: " << endl;
		char userGuess;
		cin >> userGuess;
		for (int i = 0; i < strlen(word); i++) {
			if (word[i] == userGuess) {
				correctGuesses[i] = userGuess;
				match = true;
			}
		}
		if (match) { //Correct guess
			for (int i = 0; i < strlen(word); i++) { //Check for victory
				if (word[i] == correctGuesses[i]) win = true;
				else {
					win = false;
					break;
				}
			}
			if (win) { //Victory
				showSolved(word, incorrectGuesses);
				cout << "You win!" << endl;
				return 0;
			}
			match = false;
		}
		else {
			incorrectGuesses[wrong] = userGuess;
			wrong++;
			if (wrong == 7) { //Defeat
				showGallows(wrong);
				cout << "The person was hanged!" << endl;
				showSolved(word, incorrectGuesses);
				cout << "Try again!" << endl;
				return 0;
			}
		}
	}
}