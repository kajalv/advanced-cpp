#include "InitializerList.h"

class TestInitL
{
public:
	// need to #include<initializer_list> in order to use this syntax!
	TestInitL(initializer_list<string> texts)
	{
		// we can iterate through initializer_list
		for (auto value : texts)
		{
			cout << value << endl;
		}
	}

	void print(initializer_list<string> strings)
	{
		for (auto value : strings)
		{
			cout << value << endl;
		}
	}
};

void runInitializerList()
{
	vector<int> numbers{ 1, 3, 4, 6 };
	cout << numbers[2] << endl;

	// need to #include<initializer_list> in order to use this syntax!
	TestInitL test{ "apple", "orange", "banana" };
	test.print({ "one", "two", "three", "four" });
}