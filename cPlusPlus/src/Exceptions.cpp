#include "Exceptions.h"

class CanGoWrong
{
public:
	CanGoWrong()
	{
		// if something goes wrong in a constructor, throwing an exception is a good way to handle it
		// because there is no mechanism to have a return code from a constructor

		char *pMemory = new char[999];
		delete[] pMemory;
	}
};

/// <summary>
/// Function that may go wrong and throw an exception
/// </summary>
void mightGoWrong()
{
	bool error1 = false;
	bool error2 = false;
	bool error3 = false;

	// int
	if (error1)
	{
		throw 666;
	}

	// char const *
	if (error2)
	{
		throw "Something went wrong.";
	}

	// string (object type)
	if (error3)
	{
		throw string("Something else went wrong"); // no new
	}

	cout << "All went well." << endl;
}

/// <summary>
/// Function that uses a function which can go wrong
/// </summary>
void usesMightGoWrong()
{
	mightGoWrong();
}

/// <summary>
/// Function that uses a class which throws exception in its constructor
/// </summary>
void usesClassThatCanGoWrong()
{
	CanGoWrong wrong;
}

/// <summary>
/// Run Exceptions
/// </summary>
void runExceptions()
{
	// simple exceptions
	try
	{
		usesMightGoWrong();
	}
	catch (int e)
	{
		cout << "Error code: " << e << endl;
	}
	catch (char const *e)
	{
		cout << "Error message: " << e << endl;
	}
	catch (string &e) // by reference, because exception type is an object
	{
		cout << "String error message: " << e << endl;
	}

	// exceptions inside a class constructor
	try
	{
		usesClassThatCanGoWrong();

		cout << "All went well in the class." << endl;
	}
	catch (bad_alloc &e) // by reference
	{
		cout << "Memory exception in class: " << e.what() << endl; // what() gives the description
	}
}