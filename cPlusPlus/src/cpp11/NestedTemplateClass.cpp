#include "NestedTemplateClass.h"
#include "NestedTemplates.h"

void runNestedTemplate()
{
	ring<string>::iterator it;
	it.print();

	ring<string> textring(3);

	textring.add("one");
	textring.add("two");
	textring.add("three");
	textring.add("four"); // overwrites 'one'

	for (int i = 0; i < textring.size(); i++)
	{
		cout << textring.get(i) << endl;
	}
}