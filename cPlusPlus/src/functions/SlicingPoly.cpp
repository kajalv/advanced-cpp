#include "SlicingPoly.h"

class ParentO
{
public:
	virtual void print() // if not virtual, cannot overload
	{
		cout << "Parent" << endl;
	}

	ParentO(const ParentO &other) : one(0)
	{
		one = other.one;
		cout << "Copy parent" << endl;
	}

	ParentO() : one(0) {}

	// will need virtual destructor if there is a virtual method
	virtual ~ParentO() {}
private:
	int one;
};

class ChildO : public ParentO // subclasses have to run constructor of parent class
{
public:
	ChildO() : two(2) {}

	void print()
	{
		cout << "Child" << endl;
	}

private:
	int two;
};

void runSlicingPoly()
{
	ChildO c1;
	ParentO &p1 = c1; // reference to subclass
	p1.print(); // outputs child. But without making the function virtual, there is no lookup mechanism, so this will output parent.

	ParentO p2 = ChildO(); // copy initialization. Implicit copy constructor to Parent
	p2.print(); // outputs parent

	ParentO p3 = ChildO();
	// copy constructor copies one, but it can't copy two!
	// this is object slicing. "up-casting"
}