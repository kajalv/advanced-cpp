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