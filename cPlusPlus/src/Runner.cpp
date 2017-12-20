#include "Runner.h"
#include "Exceptions.h"
#include "DerivedException.h"
#include "SubclassExceptions.h"
#include "CreateFile.h"
#include "ReadFile.h"
#include "ParseFile.h"
#include "BinaryFileAndPadding.h"

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
	runCreateFile();
	runReadFile();
	runParseFile();
	checkPadding();
	runBinaryFile();
}
