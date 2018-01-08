#include "MapCustomValue.h"

class PersonValue
{
public:
	// map needs to construct object and then assign values using the object on RHS
	// hence default constructor is needed
	PersonValue() : name(""), age(0)
	{
	}

	PersonValue(string name, int age) : name(name), age(age) 
	{
	}

	// copy constructor
	PersonValue(const PersonValue &other)
	{
		cout << "Copy constructor running!" << endl;
		name = other.name;
		age = other.age;
	}

	void print()
	{
		cout << name << ": " << age << endl;
	}

private:
	string name;
	int age;
};

void runMapCustomValue()
{
	map<int, PersonValue> people;

	// map needs to construct object and then assign values using the object on RHS
	// hence default constructor is needed
	people[50] = PersonValue("Mike", 40);
	// shallow copy (becomes a problem when there are pointers) - for this need to overload assignment operator
	// this does not call copy constructor
	people[31] = PersonValue("Vicky", 30);
	people[2] = PersonValue("Raj", 20);
	// map sorts objects in order of keys

	people.insert(make_pair(55, PersonValue("Bob", 45)));
	people.insert(make_pair(45, PersonValue("Sue", 45)));

	for (map<int, PersonValue>::iterator it = people.begin(); it != people.end(); it++)
	{
		cout << it->first << ": " << flush;
		it->second.print();
	}
}