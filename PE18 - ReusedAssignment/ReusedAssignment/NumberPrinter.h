#pragma once

#include <iostream>
using namespace std;

class NumberPrinter
{
public:
	NumberPrinter();
	NumberPrinter(int printNum);
	~NumberPrinter();

	int num = 0;

	void Print();
};

