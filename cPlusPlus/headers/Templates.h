#pragma once

#include "cppincl.h"

// template class
template <class T, class K>
class TemplateTest
{
public:
	TemplateTest(T obj, K val) : m_obj(obj), m_val(val)
	{
	}

	void print() const
	{
		cout << m_val << ": " << m_obj << endl;
	}

private:
	T m_obj;
	K m_val;
};

// template function
template <typename T> // class or typename - both are valid, both can be used
void display(T n)
{
	cout << n << endl;
}

// template function to demonstrate type inference with overloaded functions and what can happen if you do not specify the type
template <typename T> // class or typename - both are valid, both can be used
void showMe(T n)
{
	cout << "Template version: " << n << endl;
}

void showMe(int n)
{
	cout << "Non-template version: " << n << endl;
}

// template function that will not compile unless <> is specified
template <typename T>
void iNeedAType() // no argument. So can't infer the type - it has to be specified.
{
	cout << T() << endl;

	// if no type: no matching overloaded found, and could not deduce template argument for 'T'
}