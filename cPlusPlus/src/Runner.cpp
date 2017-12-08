#include "Runner.h"
#include "Exceptions.h"

int main()
{
	runAll();

	cout << endl;
	return 0;
}

/// <summary>
/// Run everything
/// </summary>
void runAll()
{
	runExceptions();
}

/// <summary>
/// Exceptions
/// </summary>
void runExceptions()
{
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
	catch (string &e) // by reference
	{
		cout << "String error message: " << e << endl;
	}
}