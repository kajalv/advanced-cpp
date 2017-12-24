#include "VectorsMemory.h"

void runVectorsAndMemory()
{
	vector<double> numbers;

	cout << "Size: " << numbers.size() << endl;

	// capacity is the size of the allocated internal array that the vector uses to store data

	int cap = numbers.capacity();
	cout << "Capacity: " << cap << endl;

	for (int i = 0; i < 10000; i++)
	{
		if (numbers.capacity() != cap)
		{
			// if we keep adding numbers, the vector resizes its internal capacity by re-initializing to a new array
			// and copying all the old elements.
			// Capacity increases exponentially.
			cap = numbers.capacity();
			cout << "New capacity: " << cap << endl;
		}

		numbers.push_back(i);
	}

	// Resize - changes the size of the array, while keeping existing elements, but does not change the capacity
	numbers.resize(100);
	cout << numbers[2] << endl;
	cout << "Resized.\nSize: " << numbers.size() << endl;
	cout << "Capacity: " << numbers.capacity() << endl;

	// Reserve - changes the capacity of the array, while keeping existing elements, but does not change the size
	numbers.reserve(100000);
	cout << numbers[2] << endl;
	cout << "Reserved.\nSize: " << numbers.size() << endl;
	cout << "Capacity: " << numbers.capacity() << endl;

	// Clear - resets the size to zero, but does not change the existing capacity of the vector
	// To lower the capacity, we have to re-initialize the vector to another temp vector, which is usually not required
	numbers.clear();
	cout << "Cleared.\nSize: " << numbers.size() << endl;
	cout << "Capacity: " << numbers.capacity() << endl;
}