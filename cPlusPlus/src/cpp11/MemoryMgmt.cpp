#include "MemoryMgmt.h"

class TestMem
{
private:
	static const int SIZE = 100;

	int *_pBuffer;

public:
	TestMem()
	{
		cout << "constructor" << endl;
		_pBuffer = new int[SIZE] {};

		// three ways to initialize all the values to 0
		// memset(_pBuffer, 0, sizeof(int)*SIZE); // this sets individual bytes to 0, so 4 0 bytes make a 0 int value. Can be prone to bugs if not careful.
		// _pBuffer = new int[SIZE](); // this may work, need to check, instructor not sure
		// third way is the one being used above
	}

	TestMem(int param)
	{
		cout << "parameterized constructor" << endl;
		_pBuffer = new int[SIZE] {};

		for (int i = 0; i < SIZE; i++)
		{
			_pBuffer[i] = param * i;
		}
	}

	TestMem(const TestMem &other)
	{
		cout << "copy constructor" << endl;

		_pBuffer = new int[SIZE] {};

		// alternate way to copy buffer. 
		//std::copy(other._pBuffer, other._pBuffer + SIZE, _pBuffer);
		// may need to include <memory.h>, but usually part of some other header file 
		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
	}

	TestMem &operator=(const TestMem &other)
	{
		cout << "assignment" << endl;
		_pBuffer = new int[SIZE] {};

		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
		return *this;
	}

	~TestMem()
	{
		cout << "destructor" << endl;

		// array form of delete
		delete[] _pBuffer;
	}

	friend ostream &operator<<(ostream &out, const TestMem &test);
};

ostream &operator<<(ostream &out, const TestMem &test)
{
	out << "Hello from test";
	return out;
}

TestMem getTest()
{
	return TestMem();
}

void runLvaluesAndRvalues()
{
	TestMem test1 = getTest();

	cout << test1 << endl;

	vector<TestMem> vec;
	vec.push_back(TestMem());

	// 1 - lvalues and rvalues
	// lvalue - anything we can take the address of
	int value1 = 7;

	int *pValue1 = &value1;
	//int *pValue2 = &7;

	TestMem *pTest1 = &test1;
	//Test *pTest2 = &getTest(); // getTest() returns a temporary object, so it is an rvalue, not an lvalue

	int *pValue3 = &++value1;
	cout << *pValue3 << endl;

	//int *pValue4 = &value1++; // postfix ++ operator creates a temporary value, so it is an rvalue, unlike prefix ++ operator

	// int *s = &(7 + value1);
}

void runLvalueReferences()
{
	TestMem test1 = getTest();

	cout << test1 << endl;

	vector<TestMem> vec;
	vec.push_back(TestMem());

	// 2 - Lvalue references
	TestMem &rTest1 = test1; // lvalue reference - the usual c++98 way of creating a 'reference'

	//Test &rTest2 = getTest(); // lvalue reference cannot bind to rvalue

	const TestMem &rTest2 = getTest(); // const lvalue references can bind to rvalues!
	// does so by extending the lifetime of the temporary object, to a point where the const lvalue reference goes out of scope

	TestMem test2(TestMem(1)); // const lvalue reference in copy constructor - can bind to an rvalue
}

void checkWhich(const TestMem &value)
{
	cout << "lValue function!" << endl;
}

void checkWhich(TestMem &&value)
{
	cout << "rValue function!" << endl;
}

void intTest(const int &value)
{
	cout << "lValue int func!" << endl;
}

void intTest(int &&value)
{
	cout << "rValue int func!" << endl;
}

void runRvalueReferences()
{
	TestMem test1 = getTest();

	cout << test1 << endl;

	vector<TestMem> vec;
	vec.push_back(TestMem());

	TestMem &ltest1 = test1;

	TestMem &&rtest1 = getTest();
	// rvalue references give us a way to differentiate between temp values and non-temp values
	// i.e. between lvalues and rvalues
	// example using checkWhich below

	checkWhich(test1); // l
	checkWhich(getTest()); // r
	checkWhich(TestMem()); // r

	int num = 4;
	intTest(++num); // l
	intTest(num++); // r
}

void runMemMgmt()
{
	runLvaluesAndRvalues();
	runLvalueReferences();
	runRvalueReferences();
}