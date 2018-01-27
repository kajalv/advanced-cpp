#include "ComplexNumber.h"

void runComplexNumbers()
{
	ComplexNumbers::Complex c1(2, 3);
	cout << c1;
}

namespace ComplexNumbers
{
	Complex::Complex() : m_real(0.0), m_imaginary(0.0)
	{
	}

	Complex::Complex(double real, double imaginary) : m_real(real), m_imaginary(imaginary)
	{
	}

	Complex::Complex(const Complex &other)
	{
		m_real = other.m_real;
		m_imaginary = other.m_imaginary;
	}

	const Complex &Complex::operator=(const Complex &other)
	{
		m_real = other.m_real;
		m_imaginary = other.m_imaginary;
		return *this;
	}

	ostream &operator<<(ostream &out, const Complex &complexNum)
	{
		out << complexNum.m_real << " + " << complexNum.m_imaginary << "i" << endl;
		return out;
	}
}