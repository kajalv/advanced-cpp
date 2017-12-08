#include "Exceptions.h"

/// <summary>
/// Function that may go wrong and throw an exception
/// </summary>
void mightGoWrong()
{
	bool error1 = false;
	bool error2 = false;
	bool error3 = true;

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