#include "stdafx.h"
#include "NumberPrinter.h"


NumberPrinter::NumberPrinter()
{

}

NumberPrinter::NumberPrinter(int printNum) {
	num = printNum;
}

NumberPrinter::~NumberPrinter()
{
}

void NumberPrinter::Print() {
	for (int i = 0; i < 50; i++) {
		cout << num << " ";
	}
}
