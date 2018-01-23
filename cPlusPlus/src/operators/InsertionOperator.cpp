#include "InsertionOperator.h"

class TestIO
{
public:
	TestIO() : m_id(0), m_name("") {}
	TestIO(int id, string name) : m_id(id), m_name(name) {}

	void print() const
	{
		cout << m_id << ": " << m_name << endl;
	}

	const TestIO &operator=(const TestIO &other)
	{
		cout << "Assignment running" << endl;

		m_id = other.m_id;
		m_name = other.m_name;

		return *this;
	}

	TestIO(const TestIO &other)
	{
		cout << "Copy constructor running" << endl;

		m_id = other.m_id;
		m_name = other.m_name;
	}

	// overload left bit shift for printing
	// to do this, we need to make << a friend function to access private instance variables (or just use getters)
	// ideally this should be defined in separate cpp file, in this project doing everything in same place
	friend ostream &operator<<(ostream &out, const TestIO &test)
	{
		out << test.m_id << ": " << test.m_name;
		return out;
	}

private:
	int m_id;
	string m_name;
};

void runInsertionOpOverload()
{
	TestIO test1(10, "Mike");
	test1.print();

	// overloaded insertion operator
	// cout is an object of type ofstream
	cout << test1 << endl;
	// cout is left-right associative. So first, the operation on the left is done. i.e. In simple words - starts from left.
	// (cout << test1) << endl - the first argument returns a reference to ofstream
	// << cannot be implemented as a member function of Test because it has to return a reference to ofstream and it doesn't take an implicit 'this' Test operator
}