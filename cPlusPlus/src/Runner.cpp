#include "Runner.h"
#include "Exceptions.h"
#include "DerivedException.h"
#include "SubclassExceptions.h"

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
	runDerivedException();
	runSubclassExceptions();
}
