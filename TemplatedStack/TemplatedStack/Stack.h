#pragma once
#include <iostream> //Used in .cpp and in the main file
using namespace std;

template<class T>
class Stack
{
public:
	#pragma region Construct/Destruct/Copy/Index
	Stack();
	Stack(int stackSize);
	~Stack();

	//Copy constructor
	Stack(const Stack& other);
	//Copy assignment
	Stack<T> operator=(const Stack & other);

	//Indexer
	T* operator[](int index);
	#pragma endregion
	#pragma region Methods
	void Push(T* item);
	T* Pop();

	int GetSize();
	bool IsEmpty();

	void Print();
	#pragma endregion
private:
	//Variables
	T** data[1];
	int dataSize = 4;
	int size = 0;
};

