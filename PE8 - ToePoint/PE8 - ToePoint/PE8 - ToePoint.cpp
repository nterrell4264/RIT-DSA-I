//Nathan Terrell
//Section 01

/* Comment questions:
- changeVariable changes a copy of the variable passed into the function, just like C# and Java. chagnePointer changes the actual memory address
- The stack array has its values changed. The data on the stack is overridden after it's executed, but the pointer still points to that spot.
*/

#include "stdafx.h"
#include "Header.h"

int main()
{
	//Part 1
	double u = 1.41421;
	printf("Value: %f\n", u);
	changeVariable(u);
	printf("Value: %f\n", u);
	changePointer(&u);
	printf("Value: %f\n", u);

	//Part 2
	int counting[] = { 1, 2, 3, 5, 4, 17, 1000000000, -1 };
	printf("Array length: %i\n", getLengthArray(counting));
	printf("Array length: %i\n", getLengthPointer(counting));

	//Part 3
	int* stack = createStackArray();
	int* heap = createHeapArray(6);
	printf("Stack array: ");
	for (int i = 0; i < 5; i++) {
		printf("%i ", *(stack + i));
	}
	printf("\nHeap array: ");
	for (int i = 0; i < 6; i++) {
		printf("%i ", *(heap + i));
	}
	printf("\n");
	delete[] heap;

    return 0;
}

void changeVariable(double doub) {
	doub = 3.14159;
	printf("Variable changed to %f.\n",doub);
}

void changePointer(double* doub) {
	*doub = 2.71828;
	printf("Pointer value changed to %f.\n", *doub);
}

int getLengthArray(int data[]) {
	int result = 0;
	int i = 0;
	while (data[i] != -1) {
		result++;
		i++;
	}
	return result;
}

int getLengthPointer(int* pointer) {
	int result = 0;
	int* address = pointer;
	while (*address != -1) {
		result++;
		address++;
	}
	return result;
}

int* createStackArray() {
	int ints[5] = { };
	for (int i = 0; i < sizeof(ints) / sizeof(int); i++) {
		ints[i] = i;
	}
	return ints;
}

int* createHeapArray(int size) {
	int* ints = new int[size];
	for (int i = 0; i < size; i++) {
		ints[i] = i;
	}
	return ints;
}

