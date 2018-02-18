#include "PerfectForwarding.h"

class TestPF
{
};

template<typename T>
void callPF(T &&arg)
{
	checkPF(forward<T>(arg)); // without the forward, arg looks like an lvalue, so lvalue version will be called always even if call(TestPF());
	// static_cast works fine and calls the right function. checkPF(static_cast<T>(arg));
	// but the 'forward' function does the same thing as is intended for use in this way
}

void checkPF(TestPF &test)
{
	cout << "lvalue" << endl;
}

void checkPF(TestPF &&test)
{
	cout << "rvalue" << endl;
}

void runPerfectForwarding()
{
	auto &&t = TestPF(); // rvalue reference
	TestPF test1;
	auto &&t1 = test1; // lvalue
	// t1 can't be an rvalue reference otherwise it wouldn't bind to the lvalue
	// as a rule in C++11, if auto boiled down to lvalue, then the reference as a whole would collapse
	// reference collapsing rules

	// idea behind perfect forwarding
	// might want to call right version of a function depending on whether lvalue or value was passed to the template function
	// pass the argument in such a way that the lvalue or rvalue-ness is preserved
	TestPF test;
	callPF(test);
	callPF(TestPF());
}