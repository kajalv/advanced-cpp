#include "Vectors.h"

void runVectors()
{
	// Resizable array, template class

	// Can be pre-set to some size, after which anything added will increase the size
	vector<int> presized(5);
	presized.push_back(666);
	presized.push_back(777);
	presized.push_back(888);
	cout << presized.size() << endl; // 8

	// can preset as well as initialize all elements to some value
	vector<int> presetVector(10, 0); // 10 elements, all initialized to zero
	cout << presetVector[6] << endl;

	vector<string> strings;
	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");

	// old way of iterating
	for (unsigned int i = 0; i < strings.size(); i++)
	{
		cout << strings[i] << endl;
	}
	// Note - accessing beyond the end of the vector will not really throw an error, but it will have undefined behaviour

	// recommended way of iterating
	vector<string>::iterator it;
	for (it = strings.begin(); it != strings.end(); it++)
	{
		// it overloads *, ++, -- much like using a pointer
		cout << *it << endl;
	}

	/*
	Note on iterating:
	Using the index-based way of iterating is not necessarily less efficient than using an iterator (for the purpose of iteration).
	Just for iterating, we can use a const iterator to ensure they cannot be changed. (one advantage.)
	C++11 uses a better way to iterate.
	*/

	it = strings.begin();
	it += 2;
	cout << *it << endl;
}