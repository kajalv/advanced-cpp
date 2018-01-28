#include "UsingTemplates.h"
#include "Templates.h"

void runUsingTemplates()
{
	TemplateTest<string, int> test1("Hello", 1);
	test1.print();

	display<int>(5);
	display<string>("World");
	display("Trying!"); // type inference
	display(6.6);
}