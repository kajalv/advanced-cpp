#pragma once

#include "cppincl.h"

// nested template class
// (demonstrating following the STL convention of lower-case letters for class names)
// class that enables us to use range-based loop
// circular data structure
// iterator is nested within ring

template <typename T>
class ring
{
public:
	class iterator; // implementing it here itself is generally not good practice, as it can get quite complicated and messy while nesting. So we can take it outside the class.
	// iterator cannot access the private members. We need to be able to pass it info

	// iterating impl
	iterator begin()
	{
		return iterator(0, *this); // pass the ring object and the start position
	}

	iterator end()
	{
		return iterator(m_size, *this);
	}

	// ring buffer impl
	ring(int size) : m_size(size), m_values(NULL), m_pos(0) // initialize in the order they are declared to prevent warnings
	{
		m_values = new T[size];
	}

	~ring()
	{
		delete[] m_values;
		m_values = NULL;
	}

	int size()
	{
		return m_size;
	}

	void add(T value)
	{
		m_values[m_pos++] = value;
		if (m_pos == m_size)
		{
			m_pos = 0;
		}
	}

	T& get(int pos) // usually STL containers return references
	{
		return m_values[pos];
	}

private:
	T *m_values;
	int m_size;
	int m_pos;
};

// iterator has to be aware of the type while dereferencing, so has to use the same typename as the ring
template <typename T>
class ring<T>::iterator // Here is the implementation
{
public:

	iterator(int pos, ring &aRing) : m_pos(pos), m_ring(aRing)
	{
		;
	}

	iterator &operator++(int) // postfix type takes a parameter, prefix does not
	{
		m_pos++;
		return *this;
	}

	iterator &operator++() // postfix type takes a parameter, prefix does not
	{
		m_pos++;
		return *this;
	}

	T &operator*()
	{
		return m_ring.get(m_pos);
	}

	bool operator!=(const iterator &other) const
	{
		return m_pos != other.m_pos;
	}

	void print() // prefer to keep implementation inline inside a template class
	{
		cout << "Hello from iterator" << endl;
	}

private:
	int m_pos;
	ring &m_ring; // why copy. Use reference
};