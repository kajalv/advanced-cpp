#include "StacksAndQueues.h"

class Test
{
public:
	Test(string name) : m_name(name)
	{
	}

	~Test()
	{
		//cout << "Object " << m_name << " destroyed" << endl;
	}

	void print() const
	{
		cout << m_name << endl;
	}

private:
	string m_name;
};

void runStack()
{
	// LIFO
	stack<Test> testStack;

	testStack.push(Test("Mike")); // original object gets destroyed, copy gets created inside the stack
	testStack.push(Test("Vicky"));
	testStack.push(Test("Sue"));

	Test test1 = testStack.top(); // access the top element, but doesn't pop it. Returns a reference to the object, then copies to test1
	test1.print();

	testStack.pop();

	Test &test2 = testStack.top(); // access reference for efficiency. IMPORTANT: Be careful, if it is popped, it should not be used again - undefined behaviour
	test2.print();

	// should not iterate through a stack. not how it's designed to work.

	while (testStack.size() > 0)
	{
		Test &test = testStack.top();
		test.print();

		// if you don't pop, infinite loop
		// IMPORTANT: Be careful, if it is popped, it should not be used again - undefined behaviour, reference to destroyed object
		testStack.pop();
	}
}

void runQueue()
{
	// FIFO
	queue<Test> testQueue;

	testQueue.push(Test("Mike")); // original object gets destroyed, copy gets created inside the stack
	testQueue.push(Test("Vicky"));
	testQueue.push(Test("Sue"));

	// can also access back
	testQueue.back().print();

	while (testQueue.size() > 0)
	{
		Test &test = testQueue.front(); // stack - top, queue - front
		test.print();

		// if you don't pop, infinite loop
		// IMPORTANT: Be careful, if it is popped, it should not be used again - undefined behaviour, reference to destroyed object
		testQueue.pop(); // remove item from front of queue
	}
}

void runStackQueue()
{
	runStack();
	runQueue();
}