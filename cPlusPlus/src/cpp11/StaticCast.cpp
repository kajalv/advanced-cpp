#include "StaticCast.h"

class ParentClass
{
public:
	void speak()
	{
		cout << "Parent speaking" << endl;
	}
};

class BrotherClass : public ParentClass
{

};

class SisterClass : public ParentClass
{
	;
};

void runStaticCast()
{
	// casting in C
	double value = 3.21;
	cout << (int)value << " " << int(value) << endl;

	// static cast in C++
	cout << static_cast<int>(value) << endl;

	ParentClass parent;
	BrotherClass brother;

	ParentClass *ppb = &brother;
	BrotherClass *pbb = static_cast<BrotherClass *>(ppb); // very very unsafe! try to use methods that don't exist, and crash.
	// static cast is only compile time. There is no runtime checking.
	cout << pbb << endl;

	ParentClass &&p1 = ParentClass();
	ParentClass &&p = static_cast<ParentClass &&>(parent); // set rvalue reference to refer to an lvalue
	p.speak();
}