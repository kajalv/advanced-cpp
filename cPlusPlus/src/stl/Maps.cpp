#include "Maps.h"

void runMaps()
{
	map<string, int> ages;

	ages["Mike"] = 40;
	ages["Raj"] = 20;
	ages["Vicky"] = 30;

	ages["Mike"] = 70; // overwrites previous value

	cout << ages["Raj"] << endl;

	// directly trying to access the value corresponding to a key that is not already in the map
	// will add it to the map
	cout << ages["Sue"] << endl; // the age value is stored as zero

	// so, to find a value in a map use 'find' which returns an iterator 
	// if found it points to the element else it points off the end of the map
	if (ages.find("Vicky") != ages.end())
	{
		cout << "Vicky found" << endl;
	}
	if (ages.find("Adam") != ages.end())
	{
		cout << "Adam found" << endl;
	}

	// iterate over map
	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
	{
		// first and second hold the key and value respectively
		cout << it->first << ": " << it->second << endl;
	}

	// what's actually stored in the map is a 'pair'

	// we can use a pair to insert into the map
	pair<string, int> addToMap("Peter", 100);
	ages.insert(addToMap);
	ages.insert(pair<string, int>("Jake", 33));
	// avoid types - return pair of right type
	ages.insert(make_pair("Jake", 33));

	// iterating using pair
	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
	{
		pair<string, int> age = *it;

		cout << age.first << ": " << age.second << endl;
	}

	// Design note: It is very easy to overuse maps.
	// Sometimes instead of a map, it is better to use a
	// vector of objects of our own class types that store information
}