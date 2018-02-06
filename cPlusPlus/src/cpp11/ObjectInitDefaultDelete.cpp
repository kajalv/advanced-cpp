#include "ObjectInitDefaultDelete.h"

class TestDefDel
{
	int id{ 3 };
	string name{ "Mike" };

public:
	TestDefDel() = default; // we defined a parameterized constructor, so this statement brings back the default constructor

	TestDefDel(const TestDefDel &other) = delete;
	TestDefDel& operator=(const TestDefDel& other) = delete;

	TestDefDel(int id) : id(id)
	{
	}

	void print()
	{
		cout << id << ": " << name << endl;
	}
};

void runObjectInitDefaultDelete()
{
	TestDefDel test;
	test.print();

	TestDefDel test1(77);
	test1.print();

	// Won't work, we deleted them.
	// Test test2 = test1; // copy initialization - invokes the copy constructor
	// test2 = test; // assignment operator
}