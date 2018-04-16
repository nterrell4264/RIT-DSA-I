#pragma once
#include <iostream> //Used in .cpp and in the main file
using namespace std;

template<class T>
class Stack
{
public:
	Stack();
	Stack(int stackSize);
	~Stack();
	Stack(const Stack& other);
	Stack<T> operator=(const Stack & other);
	T* operator[](int index);
	void Push(T* item);
	T* Pop();
	int GetSize();
	bool IsEmpty();
	void Print();
private:
	//Variables
	T** data;
	int dataSize = 4;
	int size = 0;
};

#pragma region Construct/Destruct/Copy/Index
template<class T>
Stack<T>::Stack()
{
	data = new T*[dataSize];
}
template<class T>
Stack<T>::Stack(int stackSize)
{
	if (stackSize > 0) data = new T*[stackSize];
	else data = new T*[1];
}
template<class T>
Stack<T>::~Stack()
{
	delete[] data;
}

//Copy constructor
template<class T>
Stack<T>::Stack(const Stack& other)
{
	data = other.data;
}
//Copy assignment
template<class T>
Stack<T> Stack<T>::operator=(const Stack & other)
{
	if (this != &other) data = other.data;
	return *this;
}

//Indexer
template<class T>
T* Stack<T>::operator[](int index) {
	return (*data)[index];
}
#pragma endregion
#pragma region Methods
template<class T>
void Stack<T>::Push(T* item)
{
	data[size] = item;
	size++;
	if (size == dataSize) { //Resizes array if it's full now
		//Creates larger array with double the size
		T** bigArray = new T*[dataSize * 2];
		for (int i = 0; i < dataSize; i++) {
			bigArray[i] = data[i];
		}
		dataSize *= 2;
		//Makes data the only pointer to the new array
		delete data;
		data = bigArray;
		delete bigArray;
	}
}
template<class T>
T* Stack<T>::Pop()
{
	if (size > 0) {
		size--;
		T* popped = data[size];
		if (!IsEmpty()) {
			if (size == dataSize / 2) { //Resizes array if it's small enough for it
				//Creates smaller array with half the size
				dataSize /= 2;
				T** smallArray = new T*[dataSize];
				for (int i = 0; i < dataSize; i++) {
					smallArray[i] = data[i];
				}
				//Makes data the only pointer to the new array
				delete[] data;
				data = smallArray;
			}
		}
		return popped;
	}
}

template<class T>
int Stack<T>::GetSize()
{
	return size;
}
template<class T>
bool Stack<T>::IsEmpty()
{
	return size == 0;
}

template<class T>
void Stack<T>::Print()
{
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ": " << *(data[i]) << endl;
	}
}
#pragma endregion