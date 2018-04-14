//Nathan Terrell
//Section 01

#include "stdafx.h"
#include <string>
#include "Stack.h"

int main()
{
	//Main variables
	Stack* stack = nullptr;
	Stack* copy = nullptr;

	//User input variables
	int choice = 0;
	string input;
	bool choseInt;

	cout << "Pick a data type to demo with:" << endl;
	cout << "1. int" << endl;
	cout << "2. string" << endl;
	cin >> input;
	while (true) { //Loops until user gives valid input if they didn't.
		if (input == "int") {
			stack = new Stack<int>();
			choseInt = true;
		}
		else if (input == "string") {
			stack = new Stack<string>();
			choseInt = false;
		}
		else {
			cout << "Invalid input. Try again.";
			cin.clear();
			cin.ignore(INT_MAX);
			cin >> choice;
		}
	}
	cout << "What operation would you like to perform? Type \"help\" for a list." << endl;
	while (input != "quit") {
		cin >> input;
		if (input == "help") {
			cout << "Stack commands:" << endl;
			cout << "\"quit\" closes the program." << endl;
			cout << "\"push\" adds to the stack." << endl;
			cout << "\"pop\" removes an item from the stack and prints it." << endl;
			cout << "\"clear\" wipes the stack." << endl;
			cout << "\"print\" prints the stack." << endl;
			cout << "\"size\" prints the size of the stack." << endl;
			cout << "\"copy\" copies the current stack to a second memory location." << endl;
			cout << "\"paste\" replaces the stack with a saved copy." << endl;
		}
		if (input == "push") {
			cout << "Push what?" << endl;
			if (choseInt) {
				cin >> choice;
				stack->Push(choice);
			}
			else {
				cin >> input;
				stack->Push(input);
			}
			cout << "Pushed." << endl;
		}
		if (input == "pop") {
			cout << "Popped out " << stack->Pop() << endl;
		}
		if (input == "clear") {
			stack = nullptr;
			if (choseInt) {
				stack = new Stack<int>();
			}
			else {
				stack = new Stack<string>();
			}
		}
		if (input == "print") {
			stack->Print();
		}
		if (input == "size") {
			cout << "The stack size is " << stack->GetSize() << endl;
		}
		if (input == "copy") {
			copy = nullptr;
			copy = stack;
			cout << "Copied with copy constructor." << endl;
		}
		if (input == "paste") {
			if(copy == nullptr) cout << "Error: Nothing to paste." << endl;
			else {
				stack = copy;
				cout << "Pasted with copy assignment.";
			}
		}
	}

	delete stack;
	delete copy;
	return 0;
}

