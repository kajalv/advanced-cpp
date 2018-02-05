#pragma once

#include "cppincl.h"

// nested template class
// (demonstrating following the STL convention of lower-case letters for class names)
// class that enables us to use range-based loop
// circular data structure
// iterator is nested within ring

template <typename T>
class ring
{
public:
	class iterator; // implementing it here itself is generally not good practice, as it can get quite complicated and messy while nesting. So we can take it outside the class.
};

// iterator has to be aware of the type while dereferencing, so has to use the same typename as the ring
template <typename T>
class ring<T>::iterator // Here is the implementation
{
public:
	void print() // prefer to keep implementation inline inside a template class
	{
		cout << "Hello from iterator" << endl;
	}
};