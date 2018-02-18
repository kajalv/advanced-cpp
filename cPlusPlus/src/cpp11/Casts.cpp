#include "Casts.h"

class ParentClass
{
public:
	virtual void speak() // virtual makes ParentClass polymorphic
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

void runDynamicCast()
{
	ParentClass parent;
	BrotherClass brother;

	ParentClass *ppb = &brother;
	BrotherClass *pbb = dynamic_cast<BrotherClass *>(ppb); // cast back to subclass type
	// RTTI must be turned on for the above statement to work
	// dynamic cast checks types at runtime
	// error: ParentClass not a polymorphic type - make the functions virtual

	if (pbb == nullptr) // nullptr for invalid cast
	{
		cout << "Invalid cast" << endl;
	}
	else
	{
		cout << pbb << endl;
	}
}

void runReinterpretCast()
{
	ParentClass parent;
	BrotherClass brother;
	SisterClass sister;

	ParentClass *ppb = &brother;
	SisterClass *pbb = reinterpret_cast<SisterClass *>(ppb); // reinterpret the brother object as a sister
	// reinterpret cast has even less checking than static cast
	// can usually cast anything to anything
	// best to avoid, unless dealing with a really badly written API

	if (pbb == nullptr)
	{
		cout << "Invalid cast" << endl;
	}
	else
	{
		cout << pbb << endl;
	}
}

void runCasts()
{
	runStaticCast();
	runDynamicCast();
	runReinterpretCast();
}