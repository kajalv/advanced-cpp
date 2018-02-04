#include "Functors.h"

struct Test1
{
	// base class
	// we can implement lots of types of tests deriving from this

	virtual bool operator()(string &text) = 0;
	virtual ~Test1() {};
};

// functor is a class/struct that overloads ()
struct MatchTest : public Test1
{
	// this contains some code to test a particular object, say string

	// overload () - only this operator can take variable number of arguments. Also it can return whatever we want, here bool.
	bool operator()(string &text) // doesn't have to be reference - up to you
	{
		return text == "lion";
	}

	// this can have some state. Cannot do that with function pointers!
};

void checker(string text, Test1 &test) // reference must be used for polymorphism to be applied correctly
{
	if (test(text))
	{
		cout << "Match" << endl;
	}
	else
	{
		cout << "No match" << endl;
	}
}

void runFunctors()
{
	MatchTest pred;

	string value = "lion";
	cout << pred(value) << endl; // looks like a function call but it's not. It's just operator () applied to a struct.

	checker("lion", pred);
}