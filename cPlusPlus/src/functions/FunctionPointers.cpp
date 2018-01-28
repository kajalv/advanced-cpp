#include "FunctionPointers.h"

void testFunc()
{
	cout << "Hello" << endl;
}

void sum(int value1, int value2)
{
	cout << "Sum: " << (value1 + value2) << endl;
}

int getSmaller(int value1, int value2)
{
	return value1 < value2 ? value1 : value2;
}

void runFunctionPointers()
{
	testFunc();

	// Declaring a function pointer
	// void *pTest(); // ambiguous. Could be a function prototype with a return type of (void *). So need brackets around *pTest.
	void (*pTest)(); // function pointer

	// Assigning a function to a function pointer
	pTest = &testFunc;
	pTest = testFunc; // Still works! All we need is the name of the function which is a pointer to the function.
	// void (*pTest)() = testFunc; to declare and assign together

	// Calling a function through a function pointer
	//*pTest(); // ambiguous. Again could be call to a pTest returning a pointer. So, again we need brackets.
	(*pTest)(); 
	pTest(); // Still works! Name of the function is a pointer to the function

	// Function pointer with parameters
	void(*pSum)(int, int) = sum;
	pSum(4, 6);

	// Function pointer with return value
	int(*pSmaller)(int, int) = getSmaller;
	int showVal = pSmaller(6, 8);
	cout << showVal << endl;
}

bool matchCriteria(string stringToCheck)
{
	return stringToCheck.size() == 3; // criteria is that the string has 3 characters
}

int countStrings(vector<string> &texts, bool(*matcherFunc)(string stringToTest)) // function pointer is the argument
{
	int count = 0;

	for (string current : texts)
	{
		if (matcherFunc(current))
		{
			count++;
		}
	}

	return count;
}

void runDetailedExampleFunctionPointers()
{
	vector<string> listOfStrings;
	listOfStrings.push_back("one");
	listOfStrings.push_back("two");
	listOfStrings.push_back("three");
	listOfStrings.push_back("four");
	listOfStrings.push_back("five");
	listOfStrings.push_back("six");

	// if you include algorithm, you can use count_if
	// which checks how many elements of a vector (within the given range) satisfy some criteria as given by the function
	// this is the usage of the function pointer
	cout << count_if(listOfStrings.begin(), listOfStrings.end(), matchCriteria) << endl;

	// own implementation
	cout << countStrings(listOfStrings, matchCriteria) << endl;
}