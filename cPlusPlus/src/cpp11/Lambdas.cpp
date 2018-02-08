#include "Lambdas.h"

void lambdaRunner(void(*pFunc)()) // lambda expressions are compatible with function pointers (if same return type and arguments)
{
	pFunc();
}

void runGreet(void(*greet)(string))
{
	greet("Bob");
}

void runDivide(double(*divide)(double, double))
{
	auto rval = divide(9, 3);
	cout << rval << endl;
}

class TestCaptureThis
{
public:
	void run()
	{
		int three{ 3 };
		int four{ 4 };

		auto pL1 = [three, four]() // cannot capture instance variables until you pass 'this'! So here one and two cannot be accessed
		{
			cout << three << endl;
			cout << four << endl;
		};
		pL1();

		auto pL2 = [this, three, four]() // capture this by reference (always, cannot be done by value. So instance variables can be changed.)
		{
			one = 111;
			cout << one << endl;
			cout << two << endl;
			cout << three << endl;
			cout << four << endl;
		};
		pL2(); // no need to pass 'this' explicitly, it's implicit

		auto pL3 = [three, this]() // this can also be passed in any order: need not be the first in the list
		{
			two = 222;
			cout << one << endl;
			cout << two << endl;
			cout << three << endl;
		};
		pL3();

		cout << one << endl; // instance variable changed because 'this' is passed by reference
		cout << two << endl;
	}

private:
	int one{ 1 };
	int two{ 2 };
};

// runners
void runBasic()
{
	[]() {}; // this is a valid lambda function!

	auto func = []() { cout << "Hello lambda!" << endl; };

	func();
	lambdaRunner(func);
	[]() { cout << "Hello again!" << endl; }(); // add () to call it on the spot
	lambdaRunner([]() { cout << "Hello once more!" << endl; });
}

void runParamsAndReturn()
{
	auto pGreet = [](string name) { cout << "Hi " << name << endl; };
	pGreet("Mike");
	runGreet(pGreet);

	auto pDivide1 = [](double a, double b)
	{
		return a / b; // c++ infers return type double here
	};

	auto pDivide2 = [](double a, double b) -> double // trailing return type syntax
	{
		if (b == 0.0)
		{
			return 0; // here returning int, and below returning double. C++ won't be able to infer the return type unless we use the trailing return type syntax above.
		}

		return a / b;
	};

	cout << pDivide1(10.0, 5.0) << endl;
	cout << pDivide2(10.0, 0) << endl;
	runDivide(pDivide1);
}

void runCapture()
{
	int one = 1;
	int two = 2;
	int three = 3;

	// Capture one and two by value
	[one, two]() { cout << one << ", " << two << endl; }();

	// Capture all local variables by value.
	[=]() { cout << one << ", " << two << endl; }();

	// Default capture all local variables by value, but three by reference.
	[=, &three]() { three = 7; cout << one << ", " << two << endl; }();
	cout << three << endl;

	// Default capture all local variables by reference.
	[&]() { three = 7; two = 8; cout << one << ", " << two << endl; }();
	cout << two << endl;

	// Default capture all local variables by reference but two and three by value.
	[&, two, three]() { one = 100;  cout << one << ", " << two << endl; }();
	cout << one << endl;
}

void runCaptureThis()
{
	TestCaptureThis tester;
	tester.run();
}

void runLambdas()
{
	runBasic();
	runParamsAndReturn();
	runCapture();
	runCaptureThis();
}