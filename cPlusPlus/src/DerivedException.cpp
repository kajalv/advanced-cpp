#include "DerivedException.h"

/// <summary>
/// Exception message
/// </summary>
/// <returns></returns>
const char* CustomException::what() const throw()
{
	// const throw() specifies the list of exceptions that this function itself can throw. Advisable not to use
	return "Custom Exception: Something bad happened!";
}

/// <summary>
/// Method that throws a custom exception
/// </summary>
void GoesWrong::methodThatGoesWrong()
{
	// again, best not to specify throw() as if any other unspecified exception occurs, it will crash
	throw CustomException();
}

/// <summary>
/// Runner
/// </summary>
void runDerivedException()
{
	GoesWrong obj;

	try
	{
		obj.methodThatGoesWrong();
	}
	catch (CustomException &e) // by reference
	{
		cout << e.what() << endl;
	}
}