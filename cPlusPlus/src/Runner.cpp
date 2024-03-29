#include "Runner.h"
#include "Exceptions.h"
#include "DerivedException.h"
#include "SubclassExceptions.h"
#include "CreateFile.h"
#include "ReadFile.h"
#include "ParseFile.h"
#include "BinaryFileAndPadding.h"
#include "Vectors.h"
#include "VectorsMemory.h"
#include "TwoDimVectors.h"
#include "List.h"
#include "Maps.h"
#include "MapCustomValue.h"
#include "MapCustomKey.h"
#include "MultiMap.h"
#include "Set.h"
#include "StacksAndQueues.h"
#include "SortVectors.h"
#include "AssignmentOperator.h"
#include "InsertionOperator.h"
#include "ComplexNumber.h"
#include "UsingTemplates.h"
#include "FunctionPointers.h"
#include "SlicingPoly.h"
#include "AbstractPureVirtual.h"
#include "Functors.h"
#include "TypesMangling.h"
#include "AutoKeyword.h"
#include "NestedTemplateClass.h"
#include "Initializations.h"
#include "InitializerList.h"
#include "ObjectInitDefaultDelete.h"
#include "Lambdas.h"
#include "StandardFunction.h"
#include "DelegatingConstructor.h"
#include "Elision.h"
#include "MemoryMgmt.h"
#include "MoveConstructors.h"
#include "Casts.h"
#include "PerfectForwarding.h"
#include "Bind.h"
#include "SmartPointers.h"
#include "SharedPointers.h"
#include "MultipleInheritance.h"

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
	runVectors();
	runVectorsAndMemory();
	run2DVectors();
	runList();
	runMaps();
	runMapCustomValue();
	runMapCustomKey();
	runMultiMap();
	runSets();
	runStackQueue();
	runSortVectors();
	runAssignmentOpOverload();
	runInsertionOpOverload();
	runComplexNumbers();
	runUsingTemplates();
	runFunctionPointers();
	runDetailedExampleFunctionPointers();
	runSlicingPoly();
	runAbstractVirtual();
	runFunctors();
	runTypesMangling();
	runAuto();
	runNestedTemplate();
	runInit();
	runObjectInitDefaultDelete();
	runLambdas();
	runStdFunc();
	runDelegatingConstructor();
	runElision();
	runMemMgmt();
	runMoveConstructors();
	runCasts();
	runPerfectForwarding();
	runBind();
	runSmartPointers();
	runSharedPointers();
	runMultipleInheritance();

	getchar();
}
