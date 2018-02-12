#include "MoveConstructors.h"

class TestMove
{
private:
	static const int SIZE = 100;

	int *_pBuffer{ nullptr };

public:
	TestMove()
	{
		_pBuffer = new int[SIZE] {};
	}

	TestMove(int param)
	{
		_pBuffer = new int[SIZE] {};

		for (int i = 0; i < SIZE; i++)
		{
			_pBuffer[i] = param * i;
		}
	}

	TestMove(const TestMove &other)
	{
		_pBuffer = new int[SIZE] {};

		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
	}

	// Move constructor
	// has to take mutable rvalue reference
	TestMove(TestMove &&other)
	{
		// Might want to check that 'other' is not equal to 'this'
		cout << "Move constructor" << endl;
		_pBuffer = other._pBuffer; // steal the buffer
		// destructor of other will deallocate the buffer and we don't want that to happen
		// So for this we set the buffer of other to nullptr
		other._pBuffer = nullptr; // set stolen resources to null so they can't be deallocated
	}

	TestMove &operator=(const TestMove &other)
	{
		_pBuffer = new int[SIZE] {};

		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int)); // in copy constructor we need to allocate memory, but not in move
		return *this;
	}

	TestMove &operator=(TestMove &&other)
	{
		cout << "Move assignment" << endl;

		delete[] _pBuffer; // in move assignment operator, need to delete memory that's already been allocated
		// this is the difference from move constructor

		_pBuffer = other._pBuffer;
		other._pBuffer = nullptr;

		return *this;
	}

	~TestMove()
	{
		delete[] _pBuffer;
	}

	friend ostream &operator<<(ostream &out, const TestMove &test);
};

ostream &operator<<(ostream &out, const TestMove &test)
{
	out << "Hello from test";
	return out;
}

TestMove getTestMove()
{
	return TestMove();
}

void runMoveConstructors()
{
	vector<TestMove> vec;
	vec.push_back(TestMove()); // move constructor

	TestMove test;
	test = TestMove(); // move assignment operator
}