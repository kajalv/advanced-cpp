#include "DelegatingConstructor.h"

class ParentDC
{
public:
	ParentDC() : ParentDC("hello") // calling one constructor from another couldn't be done in C++98 but has been made available in C++11
	{
		cout << "No parameter parent constructor" << endl;
	}

	ParentDC(string text)
	{
		cout << "string parent constructor" << endl;
	}

private:
	int dogs{ 5 };
	string text{ "hello" };
};

class ChildDC : public ParentDC
{
public:
	ChildDC() = default;
};

void runDelegatingConstructor()
{
	ParentDC parent("Hello");
	ChildDC child;
}