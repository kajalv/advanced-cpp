#include "MultiMap.h"

void runMultiMap()
{
	multimap<int, string> lookup;

	// there is no overloaded [] in multimap, so have to use insert

	// just like in map, the keys will be sorted so the order of insertion does not matter
	lookup.insert(make_pair(30, "Mike"));
	lookup.insert(make_pair(10, "Vicky"));
	lookup.insert(make_pair(30, "Raj")); // in a normal map the previous value is overriden, here another one is added
	lookup.insert(make_pair(20, "Bob"));

	for (multimap<int, string>::iterator it = lookup.begin(); it != lookup.end(); it++)
	{
		cout << it->first << ": " << it->second << endl;
	}
	cout << endl;

	// since there can be duplicate values for the same key, searching works differently

	// IMPORTANT: Starting with find and iterating will go from the 'found' element till the end of the map
	// so find is not useful at all!
	for (multimap<int, string>::iterator it = lookup.find(20); it != lookup.end(); it++)
	{
		cout << it->first << ": " << it->second << endl;
	}
	cout << endl;

	// so to search:
	// get range of elements: get two iterators to start and end of the range
	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);
	// C++11
	auto its2 = lookup.equal_range(30);

	// stop at its.second because that iterator points off the end
	for (multimap<int, string>::iterator it = its.first; it != its.second; it++)
	{
		cout << it->first << ": " << it->second << endl;
	}
	cout << endl;
}