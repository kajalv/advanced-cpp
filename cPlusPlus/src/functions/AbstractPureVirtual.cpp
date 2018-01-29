#include "AbstractPureVirtual.h"

class Animal
{
	// abstract class
	// must not be able to instantiate it by itself. Can only instantiate its subclasses

public: // don't forget!
	// class containing methods with no implementation. Pure virtual.
	virtual void speak() = 0; // pure virtual. no implementation
	virtual void run() = 0;
};

class Dog : public Animal
{
public:
	virtual void speak()
	{
		cout << "Woof!" << endl;
	}
	// ALL pure virtual functions need to be implemented in order to instantiate a class
	// no run(), so cannot instantiate Dog yet
};

class Labrador : public Dog
{
public:
	virtual void run()
	{
		cout << "Labrador running" << endl;
	}
	// Now, Labrador can be instantiated
};

class Cat : public Animal
{
public:
	virtual void speak()
	{
		cout << "Meow!" << endl;
	}

	virtual void run()
	{
		cout << "Cat running" << endl;
	}
};

void tryAnimal(Animal &a)
{
	a.run();
}

void runAbstractVirtual()
{
	//Animal animal; // not allowed

	Labrador lab;
	lab.speak();
	lab.run();

	Cat cat;
	cat.speak();
	cat.run();

	// Note: cannot create an array of an abstract class, because the constructor needs to run. But can create array of pointers to it.
	Animal *animals[2];
	animals[0] = &lab;
	animals[1] = &cat;

	animals[0]->speak();
	tryAnimal(lab);
}