#pragma once
#include <iostream> //Used in .cpp and in the main file
using namespace std;

template<class T>
class Stack
{
public:
	Stack();
	~Stack();
	//Copy stuff
	Stack(const Stack& other);
	Stack operator= (const Stack& other);

	//Methods
	void Push(T* item);
	T* Pop();
	int GetSize();
	bool IsEmpty();
	void Print();
private:
	//Variables
	T* data[];
	int dataSize = 4;
	int size = 0;
};

