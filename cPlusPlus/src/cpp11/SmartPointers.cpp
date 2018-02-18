#include "SmartPointers.h"
// need to #include <memory> to use smart or shared pointers
// smart - aka unique pointers or auto pointers

class TestSmartPtr
{
public:
	TestSmartPtr() {
		cout << "created" << endl;
	}

	void greet() {
		cout << "Hello" << endl;
	}

	~TestSmartPtr() {
		cout << "destroyed" << endl;
	}
};

class TempSmart
{
private:
	unique_ptr<TestSmartPtr[]> pTest;
	// private unique pointer.

	// unique_ptr<TestSmartPtr[]> pTest(new TestSmartPtr[2]);
	// this won't work here because we are trying to call constructor
	// hence we need a public constructor for this class

public:
	TempSmart() : pTest(new TestSmartPtr[2]) // have to use initialization list to do this
	{
	}
};

void runSmartPointers()
{
	// simple int example
	unique_ptr<int> pointerTestInt(new int);
	// no need to say int *, just int.
	// because we want the pointer to manage the memory allocated by new itself, we cannot say = new int. It has to be done within constructor.
	*pointerTestInt = 7;
	cout << *pointerTestInt << endl; // use like a regular pointer, but will be automatically deallocated.

	// example with objects to make it clear with destructors
	unique_ptr<TestSmartPtr> pointerTestObj(new TestSmartPtr);
	pointerTestObj->greet();

	// Prior to C++11, there was auto_ptr which is similar to unique_ptr.But now it is deprecated.
	// Also, we cannot use auto_ptr on arrays but we can use unique_ptr on arrays.
	unique_ptr<TestSmartPtr[]> pTest(new TestSmartPtr[2]);
	pTest[1].greet();

	TempSmart temp;

	cout << "Finished" << endl;
	// after this, memory is automatically cleaned up. When the variables go out of scope.
}