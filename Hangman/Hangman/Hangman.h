#pragma once

#include "stdafx.h"
#include "stdio.h"
#include <iostream>
using namespace std;

#pragma region Functions
void showGallows();
void showSolved();
int main();
#pragma endregion

#pragma region Variables
char word[];
char userGuess[];
char correctGuess[];
char incorrectGuess[];
int guessLimit;
#pragma endregion