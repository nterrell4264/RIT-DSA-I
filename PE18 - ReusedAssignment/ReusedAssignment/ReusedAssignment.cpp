//Nathan Terrell
//Section 01
//The name comes from there being an almost identical GDAPS II assignment

#include "stdafx.h"
#include <thread>
#include "NumberPrinter.h"

NumberPrinter* printers[10];
std::thread* threads[10];

int main()
{
	for (int i = 0; i < 10; i++) {
		NumberPrinter* printer = new NumberPrinter(rand());
		//printer->Print();
		std::thread* thread =  new std::thread(&NumberPrinter::Print, printer);
		printers[i] = printer;
		threads[i] = thread;
	}
	for (std::thread* thread : threads) {
		thread->join();
		delete thread;
	}
	for (NumberPrinter* printer : printers) {
		delete printer;
	}

    return 0;
}

