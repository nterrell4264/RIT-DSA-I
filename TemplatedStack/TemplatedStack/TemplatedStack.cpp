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

	cout << "Performing tests on int stack." << endl;
	if(intStack->IsEmpty()) cout << "Stack is currently empty." << endl; //IsEmpty

	cout << "Pushing variables on the back." << endl; //Push
	intStack->Push_Back(2);
	intStack->Push_Back(5);
	intStack->Push_Back(8);
	intStack->Print(); //Print

	cout << "Popped " << intStack->Pop_Back() << " from the back." << endl; //Pop
	intStack->Print();

	cout << "Pushing variables to the front." << endl; //Deque push
	intStack->Push_Front(6);
	intStack->Push_Front(3);
	intStack->Print();

	cout << "Popped " << intStack->Pop_Front() << " from the front." << endl; //Deque pop
	intStack->Print();

	cout << "Size of the stack is " << intStack->GetSize() << "." << endl; //GetSize
	cout << "Element at index 1 is " << (*intStack)[1] << "." << endl; //Indexer

	cout << "Creating copy of stack." << endl; //Copy constructor
	intCopy = new Stack<int>(*intStack);
	intStack->Print();
	intCopy->Print();

	cout << "Pushing variable to copy." << endl; //Independence of copy
	intCopy->Push_Back(9);
	intStack->Print();
	intCopy->Print();

	cout << "Using copy assignment to override copy." << endl; //Copy assignment
	*intCopy = *intStack;
	intStack->Print();
	intCopy->Print();

	delete intStack; //Destructor
	delete intCopy;

	cout << endl << "Performing tests on string stack." << endl; //Does all the same things on an object data type
	if (stringStack->IsEmpty()) cout << "Stack is currently empty." << endl;

	cout << "Pushing variables on the back." << endl;
	stringStack->Push_Back("red");
	stringStack->Push_Back("yellow");
	stringStack->Push_Back("blue");
	stringStack->Print();

	cout << "Popped " << stringStack->Pop_Back() << " from the back." << endl;
	stringStack->Print();

	cout << "Pushing variables to the front." << endl;
	stringStack->Push_Front("purple");
	stringStack->Push_Front("white");
	stringStack->Print();

	cout << "Popped " << stringStack->Pop_Front() << " from the front." << endl;
	stringStack->Print();

	cout << "Size of the stack is " << stringStack->GetSize() << "." << endl;
	cout << "Element at index 1 is " << (*stringStack)[1] << "." << endl;

	cout << "Creating copy of stack." << endl;
	stringCopy = new Stack<string>(*stringStack);
	stringStack->Print();
	stringCopy->Print();

	cout << "Pushing variable to copy." << endl;
	stringCopy->Push_Back("rock");
	stringStack->Print();
	stringCopy->Print();

	cout << "Using copy assignment to override copy." << endl;
	*stringCopy = *stringStack;
	stringStack->Print();
	stringCopy->Print();

	delete stringStack;
	delete stringCopy;

	return 0;
}

