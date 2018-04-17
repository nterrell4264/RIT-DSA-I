#pragma once
#include <iostream> //Used in .cpp and in the main file
using namespace std;

template<class T>
class Stack
{
private:
	//Variables
	T* data;
	int dataSize = 4;
	int size = 0;
public:
	Stack();
	Stack(int stackSize);
	~Stack();
	Stack(Stack& other);
	Stack<T>& operator=(Stack& other);
	T& operator[](int index);
	void Push_Back(T item);
	void Push_Front(T item);
	T Pop_Back();
	T Pop_Front();
	int GetSize();
	int GetDataSize();
	bool IsEmpty();
	void Print();
};

#pragma region Construct/Destruct/Copy/Index
template<class T>
Stack<T>::Stack()
{
	data = new T[4];
}
template<class T>
Stack<T>::Stack(int stackSize)
{
	if (stackSize > 0) {
		data = new T[stackSize];
		dataSize = stackSize;
	}
	else {
		data = new T[4];
	}
}
template<class T>
Stack<T>::~Stack()
{
	delete[] data;
	data = nullptr;
}

//Copy constructor
template<class T>
Stack<T>::Stack(Stack& other)
{
	size = other.GetSize();
	dataSize = other.GetDataSize();
	data = new T[dataSize];
	for (int i = 0; i < size; i++) 
		data[i] = other[i];
}
//Copy assignment
template<class T>
Stack<T>& Stack<T>::operator=(Stack& other)
{
	if (this != &other) { //Won't copy to itself to save time/it will fail
		delete[] data;
		size = other.GetSize();
		dataSize = other.GetDataSize();
		data = new T[dataSize];
		for (int i = 0; i < size; i++)
			data[i] = other[i];
	}
	return *this;
}

//Indexer
template<class T>
T& Stack<T>::operator[](int index) {
	return data[index];
}
#pragma endregion
#pragma region Methods
template<class T>
void Stack<T>::Push_Back(T item)
{
	data[size] = item;
	size++;
	if (size == dataSize) { //Resizes array if it's full now
		//Creates larger array with double the size
		T* bigArray = new T[(dataSize * 2)];
		for (int i = 0; i < dataSize; i++) {
			bigArray[i] = data[i];
		}
		dataSize *= 2;
		//Makes data the only pointer to the new array (bigArray goes out of scope)
		delete[] data;
		data = bigArray;
	}
}
template<class T>
void Stack<T>::Push_Front(T item)
{
	size++;
	if (size == dataSize) { //Resizes array if it's full now
		//Creates larger array with double the size
		T* bigArray = new T[(dataSize * 2)];
		for (int i = 0; i < dataSize; i++) {
			bigArray[i] = data[i];
		}
		dataSize *= 2;
		//Makes data the only pointer to the new array (bigArray goes out of scope)
		delete[] data;
		data = bigArray;
	}
	for (int i = size; i > 0; i--) data[i] = data[i - 1]; //Pushes data back
	data[0] = item;
}

template<class T>
T Stack<T>::Pop_Back()
{
	if (!IsEmpty()) {
		size--;
		T popped = data[size];
		data[size] = T();
		if (!IsEmpty()) {
			if (size < dataSize / 2) { //Resizes array if it's small enough for it
				//Creates smaller array with half the size
				dataSize /= 2;
				T* smallArray = new T[dataSize];
				for (int i = 0; i < dataSize; i++) {
					smallArray[i] = data[i];
				}
				//Makes data the only pointer to the new array (smallArray goes out of scope)
				delete[] data;
				data = smallArray;
			}
		}
		return popped;
	}
}
template<class T>
T Stack<T>::Pop_Front()
{
	if (!IsEmpty()) {
		T popped = data[0];
		size--;
		for (int i = 0; i < size; i++) data[i] = data[i + 1]; //Moves data forward
		data[size] = T(); //Calls default constructor to nullify data
		if (!IsEmpty()) {
			if (size < dataSize / 2) { //Resizes array if it's small enough for it
				//Creates smaller array with half the size
				dataSize /= 2;
				T* smallArray = new T[dataSize];
				for (int i = 0; i < dataSize; i++) {
					smallArray[i] = data[i];
				}
				//Makes data the only pointer to the new array (smallArray goes out of scope)
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
int Stack<T>::GetDataSize()
{
	return dataSize;
}
template<class T>
bool Stack<T>::IsEmpty()
{
	return size == 0;
}

template<class T>
void Stack<T>::Print()
{
	cout << "Stack contains:" << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ": ";
		cout << data[i] << endl;
	}
}
#pragma endregion