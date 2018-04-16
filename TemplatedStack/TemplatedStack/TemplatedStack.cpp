//Nathan Terrell
//Section 01

#include "stdafx.h"
#include <string>
#include "Stack.h"

int main()
{
	//Main variables
	Stack<int>* intStack = new Stack<int>();
	Stack<string>* stringStack = new Stack<string>();
	Stack<int>* intCopy = nullptr;
	Stack<string>* stringCopy = nullptr;

	//User input variables
	string input;
	bool isInt = true;

	cout << "Stack editor loaded. Can use integer and string stacks. Currently using int stack." << endl;
	cout << "What operation would you like to perform? Type \"help\" for a list." << endl;
	while (input != "quit") {
		cin >> input;
		if (input == "help") {
			cout << "Stack commands:" << endl;
			cout << "\"quit\" closes the program." << endl;
			cout << "\"switch\" switches between using the int and string stacks." << endl;
			cout << "\"push\" adds to the stack." << endl;
			cout << "\"pop\" removes an item from the stack and prints it." << endl;
			cout << "\"clear\" wipes the current stack." << endl;
			cout << "\"print\" prints both stacks." << endl;
			cout << "\"size\" prints the size of both stacks." << endl;
			cout << "\"copy\" copies the current stack to a second memory location." << endl;
			cout << "\"paste\" replaces the stack with a saved copy." << endl;
		}
		if (input == "switch") {
			isInt = !isInt;
			cout << "Matrix swapped to " << (isInt ? "int" : "string") << endl;
		}
		if (input == "push") {
			cout << "Push what?" << endl;
			if (isInt) {
				int* intInput = 0;
				cin >> *intInput;
				intStack->Push(intInput);
			}
			else {
				string* stringInput = new string();
				cin >> *stringInput;
				stringStack->Push(stringInput);
			}
			cout << "Pushed." << endl;
		}
		if (input == "pop") {
			cout << "Popped out " << intStack->Pop() << endl;
		}
		if (input == "clear") {
			intStack = nullptr;
			if (isInt) {
				delete intStack;
				intStack = new Stack<int>();
			}
			else {
				delete stringStack;
				stringStack = new Stack<string>();
			}
		}
		if (input == "print") {
			cout << "Int stack:" << endl;
			intStack->Print();
			cout << "String stack:" << endl;
			stringStack->Print();
		}
		if (input == "size") {
			cout << "The integer stack size is " << intStack->GetSize() << endl;
			cout << "The string stack size is " << stringStack->GetSize() << endl;
		}
		if (input == "copy") {
			if (isInt) {
				intCopy = nullptr;
				intCopy = intStack;
			}
			else {
				stringCopy = nullptr;
				stringCopy = stringStack;
			}
			cout << "Copied with copy constructor." << endl;
		}
		if (input == "paste") {
			if (isInt) {
				if (intCopy == nullptr) cout << "Error: Nothing to paste." << endl;
				else {
					intStack = intCopy;
				}
			}
			else {
				if (stringCopy == nullptr) cout << "Error: Nothing to paste." << endl;
				else {
					stringStack = stringCopy;
				}
			}
			cout << "Pasted with copy assignment.";
		}
	}

	delete intStack;
	delete stringStack;
	delete intCopy;
	delete stringCopy;
	return 0;
}

