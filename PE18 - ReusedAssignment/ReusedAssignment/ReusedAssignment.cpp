//Nathan Terrell
//Section 01
//The name comes from there being an almost identical GDAPS II assignment

#include "stdafx.h"
#include <thread>
#include "NumberPrinter.h"
#include "GamePlay.h"
using namespace std;

NumberPrinter* printers[50];
thread* threads[50];
thread* loading[5];

int main()
{
	//Part 1
	for (int i = 0; i < 50; i++) {
		NumberPrinter* printer = new NumberPrinter(rand());
		//printer->Print();
		thread* threader = new thread(&NumberPrinter::Print, printer);
		printers[i] = printer;
		threads[i] = threader;
	}
	for (thread* thread : threads) {
		thread->join();
		delete thread;
	}
	for (NumberPrinter* printer : printers) {
		delete printer;
	}

	cout << endl;

	//Part 2
	GamePlay* physics = new GamePlay("physics");
	GamePlay* splines = new GamePlay("spline articulator");
	GamePlay* clouds = new GamePlay("dynamic cloudform generator");
	GamePlay* network = new GamePlay("geothermal network");
	GamePlay* disaster = new GamePlay("natural disaster namer");

	loading[0] = new thread(&GamePlay::Update, physics);
	loading[1] = new thread(&GamePlay::Update, splines);
	loading[2] = new thread(&GamePlay::Update, clouds);
	loading[3] = new thread(&GamePlay::Update, network);
	loading[4] = new thread(&GamePlay::Update, disaster);

	/* Mutex version, which is broken
	mutex console;
	loading[0] = new thread(&GamePlay::Update, physics, console);
	loading[1] = new thread(&GamePlay::Update, splines, console);
	loading[2] = new thread(&GamePlay::Update, clouds, console);
	loading[3] = new thread(&GamePlay::Update, network, console);
	loading[4] = new thread(&GamePlay::Update, disaster, console);
	*/

	for (thread* thread : loading) {
		thread->join();
		delete thread;
	}
	cout << "Load complete." << endl;

	delete physics;
	delete splines;
	delete clouds;
	delete network;
	delete disaster;
    return 0;
}

