#include "StandardFunction.h"

// function to use for function pointer
bool checkWithFunction(string &test)
{
	return test.size() == 3;
}

// functor
struct CheckWithFunctor
{
	bool operator()(string &test)
	{
		return test.size() == 5;
	}
} checkFunctor;

// standard function is anything that is 'callable'
void runWithStdFuncType(function<bool(string&)> checker)
{
	string test = "stars";
	cout << checker(test) << endl;
}

void runStdFunc()
{
	int size = 5;
	vector<string> vec{ "one", "two", "three" };

	auto lambda = [size](string test) {return test.size() == size; };

	auto count = count_if(vec.begin(), vec.end(), lambda);

	cout << count << endl;

	count = count_if(vec.begin(), vec.end(), checkWithFunction);
	cout << count << endl;

	count = count_if(vec.begin(), vec.end(), checkFunctor);
	cout << count << endl;

	// use std func type
	runWithStdFuncType(lambda);
	runWithStdFuncType(checkWithFunction);
	runWithStdFuncType(checkFunctor);

	function<int(int, int)> add = [](int one, int two) { return one + two; };
	cout << add(7, 3) << endl;
}
