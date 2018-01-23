#include "AssignmentOperator.h"

class TestEO
{
public:
	TestEO() : m_id(0), m_name("") {}
	TestEO(int id, string name) : m_id(id), m_name(name) {}

	void print() const // implicit first argument 'this' - reference to the object that called it 
	{
		cout << m_id << ": " << m_name << endl;
	}

	// override default implementation of =
	const TestEO &operator=(const TestEO &other) // = should not change the value on the RHS
	{
		cout << "Assignment running" << endl;

		m_id = other.m_id;
		m_name = other.m_name;

		return *this;
	}

	// copy constructor
	TestEO(const TestEO &other)
	{
		cout << "Copy constructor running" << endl;

		m_id = other.m_id;
		m_name = other.m_name;
	}

	// if you define any one of a copy constructor or = or destructor, you should implement all three

private:
	int m_id;
	string m_name;
};

void runAssignmentOpOverload()
{
	TestEO test1(10, "Mike");
	test1.print();
	TestEO test2(20, "Bob");
	test2 = test1; // default implementation will do a shallow copy
	test2.print();

	// You might want to copy in a specific way, eg. pointers and unique identifiers
	// need to override default behaviour
	TestEO test3;
	//test3 = test2 = test1; // valid, each operator returns a reference
	test3.operator=(test2); // interesting syntax

	TestEO test4 = test1; // this is copy initialization, this does not invoke the =
	// invokes copy constructor
}