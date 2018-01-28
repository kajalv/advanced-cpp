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

	// there can be a situation where specifying the type or not can make a difference.
	// this comes into play in overloaded functions.
	showMe(5); // this one displays the non-template version - it is a closer match!
	showMe<>(5); // even this is sufficient to go to the template version. Type inference will happen
	showMe<int>(5);
	showMe("Five");
	showMe<string>("Five");

	// how to forcibly require the <> else the code will not compile
	iNeedAType<int>();
}