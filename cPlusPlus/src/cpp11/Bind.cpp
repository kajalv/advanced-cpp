#include "Bind.h"
// need to include <functional> to use bind // bind function is in std namespace
using namespace placeholders;

int addThreeNums(int a, int b, int c)
{
	cout << a << ", " << b << ", " << c << endl;
	return a + b + c;
}

void runWithStd(function<int(int, int)> func)
{
	cout << func(7, 3) << endl;
}

class TestBind
{
public:
	int adder(int a, int b, int c)
	{
		cout << a << ", " << b << ", " << c << endl;
		return a + b + c;
	}
};

void runBind()
{
	// bind allows you to create aliases to functions
	auto calculate = bind(addThreeNums, 3, 4, 5);
	cout << calculate() << endl;

	// with placeholders
	auto calculateWithNums = bind(addThreeNums, _1, _2, _3); // as many placeholders as needed
	cout << calculateWithNums(10, 20, 30) << endl; // now arguments can be supplied on-the-go

	// placeholders are numbered in order so we can change the order
	auto calculateWithDiffOrder = bind(addThreeNums, _2, _3, _1);
	cout << calculateWithDiffOrder(10, 20, 30) << endl;
	// 10, 20, 30 is reshuffled according to the specified order _2, _3, _1. _1 means first argument, which internally goes in the last place
	// so this means that internally, to the add function, the first argument int a is actually the second one passed, i.e. 20
	// so the order in which parameters are passed to the function is 20, 30, 10

	// combine placeholders and arguments
	auto calculateMixed = bind(addThreeNums, _2, 100, _1);
	cout << calculateMixed(10, 20) << endl;

	// use standard function with bind
	runWithStd(calculateMixed);

	// bind to a method
	TestBind obj;
	auto calculateMethod = bind(&TestBind::adder, obj, _2, 100, _1);
	// & is needed for the pointer to the method
	// also, need an object to bind to.
	runWithStd(calculateMethod);
}