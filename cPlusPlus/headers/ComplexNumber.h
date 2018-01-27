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

	private:
		double m_real;
		double m_imaginary;
	};
}

#endif /* COMPLEX_H_ */
