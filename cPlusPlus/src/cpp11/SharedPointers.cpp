#include "SharedPointers.h"
// need to #include <memory> to use smart or shared pointers

class TestSharedPtr
{
public:
	TestSharedPtr() {
		cout << "created" << endl;
	}

	void greet() {
		cout << "Hello" << endl;
	}

	~TestSharedPtr() {
		cout << "destroyed" << endl;
	}
};

void runSharedPointers()
{
	// Shared pointers don't delete the memory associated with the objects
	// until all pointers that point at that object have gone out of scope.

	shared_ptr<TestSharedPtr> pTestA(new TestSharedPtr());
	shared_ptr<TestSharedPtr> pTestB = make_shared<TestSharedPtr>();
	// best way to create a shared pointer is to use make_shared macro
	// more efficient than using new, according to documentation

	shared_ptr<TestSharedPtr> pTest1 = make_shared<TestSharedPtr>();
	shared_ptr<TestSharedPtr> pTest2 = pTest1;
	// memory won't be destroyed unless both these go out of scope

	// to see it in effect:
	shared_ptr<TestSharedPtr> pTestScope2(nullptr);

	{ // restricted scope
		shared_ptr<TestSharedPtr> pTestScope1 = make_shared<TestSharedPtr>();

		pTestScope2 = pTestScope1; // pTestScope2 scope ends later

		auto pTestScope3 = pTestScope1;
	}

	cout << "Finished" << endl;
}