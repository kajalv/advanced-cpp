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

void runMemMgmt()
{
	TestMem test1 = getTest();

	cout << test1 << endl;

	vector<TestMem> vec;
	vec.push_back(TestMem());

	// lvalues and rvalues
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