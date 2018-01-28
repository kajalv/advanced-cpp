#include "UsingTemplates.h"
#include "Templates.h"

void runUsingTemplates()
{
	TemplateTest<string, int> test1("Hello", 1);
	test1.print();
}