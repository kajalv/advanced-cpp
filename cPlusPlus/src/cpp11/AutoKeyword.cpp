#include "AutoKeyword.h"

// can use auto for return type of functions
// c++ 11 introduces trailing return types
// useful in template functions
auto testauto() -> int
{
	return 500;
}

template <class T, class S>
auto testAutoTemplate(T value1, S value2) -> decltype(value1 + value2)
{
	return value1 + value2;
}

// can also use functions in decltype
int getterval()
{
	return 999;
}

auto testDeclFuncAuto() -> decltype(getterval())
{
	return getterval();
}

void runAuto()
{
	auto value = 7; // useful when there's a really long type declaration, such as iterator of vector of vector of.. etc
	auto text = "Hello"; // "primitive string, not c++ string?"
	cout << text << " " << value << endl;
	cout << testauto() << endl;
	cout << testAutoTemplate(5, 6) << endl;
	cout << testDeclFuncAuto() << endl;
}