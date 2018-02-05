#include "NestedTemplateClass.h"
#include "NestedTemplates.h"

void runNestedTemplate()
{
	/*ring<string>::iterator it; // cannot do this without default constructor, and cannot pass reference of ring to iterator
	it.print();*/

	ring<string> textring(3);

	textring.add("one");
	textring.add("two");
	textring.add("three");
	textring.add("four"); // overwrites 'one'

	for (int i = 0; i < textring.size(); i++)
	{
		cout << textring.get(i) << endl;
	}

	// this C++98 syntax loop must be implemented in order to iterate, either through this method or through range-based loops
	// need begin, end, ++, *, !=
	for (ring<string>::iterator it = textring.begin(); it != textring.end(); it++)
	{
		cout << *it << endl;
	}

	cout << endl;

	// range-based for loop implementation depends on the implementation of the above loop
	// once the iterator way works, range-based for loop will work
	for (string value : textring)
	{
		cout << value << endl;
	}
	
}