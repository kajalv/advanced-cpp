#include "TypesMangling.h"

// The flag -std=gnu++11 is required to enable C++ 11 in a GNU compiler. Depends on the compiler.
// Without this, there may be warnings/errors.

void runTypesMangling()
{
	// decltype - new c++ 11 keyword
	// typeid - existing c++ 98
	// needed in 'auto'

	// typeid - existing c++ 98
	// Note: although typeid is a keyword, need to include typeinfo header to make the program well-formed, even if compiled successfully
	// otherwise results are 'not guaranteed'!
	int value;
	cout << typeid(value).name() << endl; // type information about this variable
	string stuff;
	cout << typeid(stuff).name() << endl;
	// C++ does 'name mangling' - take the names of things and adds a lot of characters to get more info about what they are
	// especially if overloading

	// decltype - new c++ 11 keyword
	// declare variables of an existing type
	decltype(stuff) name = "Bob";
	cout << typeid(name).name() << endl;
	cout << name << endl;

	decltype(value) age = 25;
	cout << typeid(age).name() << endl;
	cout << age << endl;

	// remove unreferenced variable warning
	value = 2;
	cout << value << endl;
}