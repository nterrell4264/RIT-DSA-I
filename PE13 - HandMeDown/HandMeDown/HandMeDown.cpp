//Nathan Terrell
//Section 01

#include "stdafx.h"
#include "Counter.h"
#include <iostream>
using namespace std;

int IterativeHands(int seats) {
	int result = 0;
	for (int i = 0; i < seats; i++) {
		if (i % 2 == 0) result += 4;
		else result += 3;
	}
	return result;
}

int RecursiveHands(int seats) {
	if (seats == 1) return 3;
	if (seats % 2 == 0) return 4 + RecursiveHands(seats - 1);
	else return 3 + RecursiveHands(seats - 1);
}

int MathHands(int seats) {
	return (seats / 2) * 7 + (seats % 2 == 1 ? 3 : 0);
}

int main()
{
	//10 seats
	cout << "Times for 10-seat row:" << endl;
	StartCounter();
	IterativeHands(10);
	cout << "Iterative: " << GetCounter() << " ms" << endl;
	StartCounter();
	RecursiveHands(10);
	cout << "Recursive: " << GetCounter() << " ms" << endl;
	StartCounter();
	MathHands(10);
	cout << "Formulaic: " << GetCounter() << " ms" << endl;
	cout << endl;

	//100 seats
	cout << "Times for 100-seat row:" << endl;
	StartCounter();
	IterativeHands(100);
	cout << "Iterative: " << GetCounter() << " ms" << endl;
	StartCounter();
	RecursiveHands(100);
	cout << "Recursive: " << GetCounter() << " ms" << endl;
	StartCounter();
	MathHands(100);
	cout << "Formulaic: " << GetCounter() << " ms" << endl;
	cout << endl;

	//1000 seats
	cout << "Times for 1000-seat row:" << endl;
	StartCounter();
	IterativeHands(1000);
	cout << "Iterative:" << GetCounter() << " ms" << endl;
	StartCounter();
	RecursiveHands(1000);
	cout << "Recursive:" << GetCounter() << " ms" << endl;
	StartCounter();
	MathHands(1000);
	cout << "Formulaic:" << GetCounter() << " ms" << endl;
    return 0;
}

