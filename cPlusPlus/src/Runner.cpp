#include "Runner.h"
#include "Exceptions.h"
#include "DerivedException.h"

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
}
