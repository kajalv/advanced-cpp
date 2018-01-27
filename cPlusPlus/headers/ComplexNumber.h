#pragma once

#include "cppincl.h"

#ifndef COMPLEX_H_
#define COMPLEX_H_

// Nothing new in this - only practicing whatever has been done so far

void runComplexNumbers();

namespace ComplexNumbers
{
	class Complex
	{
	public:
		Complex();
		Complex(double real, double imaginary);
		Complex(const Complex &other);
		const Complex &operator=(const Complex &other);
		friend ostream &operator<<(ostream &out, const Complex &complexNum);

		double getReal() const { return m_real; }
		double getImaginary() const { return m_imaginary; }
		// overloading the plus operator - it can either be a member function, or to make it more encapsulated,
		// it can be a free-standing function like <<.

		bool operator==(const Complex &other) const;
		bool operator!=(const Complex &other) const;
		Complex operator*() const;

	private:
		double m_real;
		double m_imaginary;
	};

	// not const ref. (return). Creating a new number.
	Complex operator+(const Complex &c1, const Complex &c2);
	Complex operator+(const Complex &c1, double d);
	Complex operator+(double d, const Complex &c1); // need to do it both ways for associativity!! Else error if you try, say, 3.2 + c!
}

#endif /* COMPLEX_H_ */
