#pragma once
#include <iostream> //Used in .cpp and in the main file
using namespace std;

//Wrapper class to allow non-immediately defined pointer
#pragma region Wrapper
template<class T>
class StackBase {
public:
	StackBase();
	virtual ~StackBase() = 0;

	//Methods
	virtual void Push(T* item) = 0;
	virtual T* Pop() = 0;
	virtual int GetSize() = 0;
	virtual bool IsEmpty() = 0;
	virtual void Print() = 0;
};
#pragma endregion

template<class T>
class Stack : public StackBase
{
public:
	#pragma region Construct/Destruct/Copy/Index
	Stack<T>::Stack()
	{
		data = new T[dataSize];
	}
	Stack<T>::~Stack()
	{
		delete[] data;
	}

	//Copy constructor
	Stack<T>::Stack(const Stack& other)
	{
		data = other.data;
	}
	//Copy assignment
	Stack<T> Stack<T>::operator=(const Stack & other)
	{
		if (this != &other) data = other.data;
		return *this;
	}

	//Indexer
	T* Stack<T>::operator[](int index) {
		if (index < size + 1) return data[index];
		else throw "OutOfBoundsException.";
	}
	#pragma endregion
	#pragma region Methods
	void Stack<T>::Push(T* item)
	{
		data[size] = item;
		size++;
		if (size == dataSize) { //Resizes array if it's full now
								//Creates larger array with double the size
			T* bigArray = new T[dataSize * 2];
			for (int i = 0; i < dataSize; i++) {
				bigArray[i] = dataSize[i];
			}
			dataSize *= 2;
			//Makes data the only pointer to the new array
			data = bigArray;
			delete bigArray;
		}
	}
	T* Stack<T>::Pop()
	{
		if (size > 0) {
			size--;
			T* popped = data[size];
			if (!IsEmpty()) {
				if (size == dataSize / 2) { //Resizes array if it's small enough for it
											//Creates larger array with double the size
					dataSize /= 2;
					T* smallArray = new T[dataSize];
					for (int i = 0; i < dataSize; i++) {
						smallArray[i] = dataSize[i];
					}
					//Makes data the only pointer to the new array
					data = smallArray;
					delete smallArray;
				}
			}
			return popped;
		}
	}

	int Stack<T>::GetSize()
	{
		return size;
	}
	bool Stack<T>::IsEmpty()
	{
		return size == 0;
	}

	void Stack<T>::Print()
	{
		cout << "The stack contains the following items:" << endl;
		for (int i = 0; i < size; i++) {
			cout << i + 1 << ": " << *(data[i]) << endl;
		}
	}
	#pragma endregion
private:
	//Variables
	T* data[];
	int dataSize = 4;
	int size = 0;
};

