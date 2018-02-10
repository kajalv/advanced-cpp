#include "Elision.h"

class TestEl
{

public:
	TestEl() { cout << "constructor" << endl; }
	TestEl(int i) { cout << "parameterized constructor" << endl; }
	TestEl(const TestEl &other) { cout << "copy constructor" << endl; }
	TestEl &operator=(const TestEl &other) { cout << "assignment" << endl; return *this; }
	~TestEl() { cout << "destructor" << endl; }

	friend ostream &operator<<(ostream &out, const TestEl &test);
};

ostream &operator<<(ostream &out, const TestEl &test)
{
	out << "Hello from test";
	return out;
}

TestEl getTest()
{
	return TestEl();
}

void runElision()
{
	// optimization can be disabled with -fno-elide-constructors
	// without return value optimization, or eliding extra copies of objects, this statement gives a series of copies and destructions
	TestEl test1 = getTest();

	cout << test1 << endl;

	vector<TestEl> vec;
	vec.push_back(TestEl());
}