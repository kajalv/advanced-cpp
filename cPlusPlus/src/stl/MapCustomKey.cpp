#include "MapCustomKey.h"

class PersonKey
{
public:
	// map needs to construct object and then assign values using the object on RHS
	// hence default constructor is needed
	PersonKey() : name(""), age(0)
	{
	}

	PersonKey(string name, int age) : name(name), age(age)
	{
	}

	// copy constructor
	PersonKey(const PersonKey &other)
	{
		name = other.name;
		age = other.age;
	}

	// keys in the map are meant to be accessed as const. The iterator returns them as const values
	void print() const
	{
		cout << name << ": " << age << flush;
	}

	// in order to use a custom object as map keys,
	// we need to know how to compare two objects of this class
	// because they have to be sorted in some order

	// so, operator overloading
	// const ref - ref for efficiency, no copy creation. const because we don't want < to change the objects.
	// const method, as neither object should be modified
	bool operator<(const PersonKey &other) const
	{
		if (name == other.name) // needed so that objects with same name and different age are also considered different
		{
			return age < other.age;
		}
		return name < other.name;
	}

private:
	string name;
	int age;
};

void runMapCustomKey()
{
	map<PersonKey, int> people;

	people[PersonKey("Mike", 40)] = 40;
	people[PersonKey("Sue", 30)] = 30;
	people[PersonKey("Raj", 20)] = 20;
	people[PersonKey("Raj", 20)] = 123; // updates the value in the map

	people[PersonKey("Raj", 444)] = 123;
	// when you try to insert a value into a map same as existing key, the existing key is not modified (key comparison is done by string names)
	// in this case we need to update the comparison operator to take care of the ages as well
	// otherwise two objects with different ages would be considered the same if the names are same

	for (map<PersonKey, int>::iterator it = people.begin(); it != people.end(); it++)
	{
		cout << it->second << ": " << flush;
		it->first.print(); // print must be marked const otherwise this gives an error
		cout << endl;
	}
}