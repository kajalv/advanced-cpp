#include "Lambdas.h"

void lambdaRunner(void(*pFunc)()) // lambda expressions are compatible with function pointers (if same return type and arguments)
{
	pFunc();
}

void runBasic()
{
	[]() {}; // this is a valid lambda function!

	auto func = []() { cout << "Hello lambda!" << endl; };

	func();
	lambdaRunner(func);
	[]() { cout << "Hello again!" << endl; }(); // add () to call it on the spot
	lambdaRunner([]() { cout << "Hello once more!" << endl; });
}

void runLambdas()
{
	runBasic();
}