#include "SubclassExceptions.h"

void goesWrong()
{
	bool error1 = false;
	bool error2 = false;

	if (error1)
	{
		// bad_alloc is a subclass of exception
		throw bad_alloc();
	}

	if (error2)
	{
		throw exception();
	}
}

void runSubclassExceptions()
{
	// Polymorphism guarantees that we can use a subclass wherever a parent class is expected.
	// what() is a virtual method and we will get the correct exception description, but the error handling will not be as expected
	// important to catch subclasses before any of their parent classes

	try
	{
		goesWrong();
	}
	catch (bad_alloc &e)
	{
		cout << "Catching bad alloc: " << e.what() << endl;
	}
	catch (exception &e)
	{
		cout << "Catching exception: " << e.what() << endl;
	}

	cout << "All went well in subclass exceptions." << endl;
}