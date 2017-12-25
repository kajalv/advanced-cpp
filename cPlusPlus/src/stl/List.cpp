#include "List.h"

void runList()
{
	// lists differ from vectors in the following ways - 
	// They are stored as doubly linked lists in memory.
	// They cannot be accessed with an index. Have to use iterator.
	// Elements can be added in the beginning/middle/end whereas in vector we are restricted to adding at the end.
	// Iterator can only be incremented/decremented with ++ or --. Using += is not possible.

	list<int> numbers;

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_front(0);

	for (list<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	// inserting an element into the list will add a new element just before the iterator,
	// but not change what the iterator is pointing to

	list<int>::iterator curr = numbers.begin();
	curr++;
	cout << "Element: " << *curr << endl; // 1
	numbers.insert(curr, 1234);
	cout << "Element: " << *curr << endl; // still 1, but the list now has 1234 before 1
	for (list<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	// erasing an element from the list will remove the element pointed to by the iterator passed to it
	// but it will also invalidate the iterator.
	// however, it returns a valid iterator pointing to the immediate next element.
	// the net effect is to increment the iterator
	// (because it will now point to the element that was immediately after the deleted element)

	// so if attempting to delete elements within a loop, be careful of the increment -
	// in a for loop, after erasing the current iterator, again a ++ is done so an element gets skipped
	// so increment the iterator conditionally in that case.

	curr = numbers.erase(curr);
	cout << "Element: " << *curr << endl; // 2
	for (list<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

}