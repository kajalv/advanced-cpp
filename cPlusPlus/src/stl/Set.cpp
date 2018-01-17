#include "Set.h"

void runSets()
{
	// only stores unique elements, in order
	set<int> numbers;

	numbers.insert(50);
	numbers.insert(10);
	numbers.insert(30);
	numbers.insert(30); // duplicate won't be inserted again
	numbers.insert(20);

	for (set<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		cout << *it << endl;
	}

	// find if an object is in the set
	set<int>::iterator itFind = numbers.find(30);
	if (itFind != numbers.end())
	{
		cout << "Found " << *itFind << endl;
	}

	// simpler way to check if it is in the set
	if (numbers.count(30)) // either returns 0 or 1 because only unique elements are stored
	{
		cout << "Found." << endl;
	}

	// skipped in video - doing the same thing with custom objects as set members.
	// 1- need to overload comparison operator if types can't be directly compared
	// 2 - any function call to print() contents will need to be const
	// 3 - need default constructor
	// see: using custom objects as keys in maps
}