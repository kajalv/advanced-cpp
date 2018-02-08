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

void runLambdas()
{
	runBasic();
	runParamsAndReturn();
}