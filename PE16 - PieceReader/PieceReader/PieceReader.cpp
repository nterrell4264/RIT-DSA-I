// PieceReader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream setfile;
	setfile.open("set0016.txt");
	if (setfile.is_open()) {
		setfile << "\"A suspended ceiling.\" ";
		setfile << "{900, 1400, 0}\n";
		setfile.close();
	}

	ifstream pieceData;
	string piece;
	string pieces;

	pieceData.open("set0016.txt");
	if (pieceData.is_open()) {
		while (getline(pieceData, piece)) {
			pieces += piece;
		}
		pieceData.close();
	}
	cout << pieces << endl;

    return 0;
}

