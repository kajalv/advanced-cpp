#include "ComplexNumber.h"

void runComplexNumbers()
{
	ComplexNumbers::Complex c1(2, 3);
	cout << c1;

	ComplexNumbers::Complex c2(4, 5);
	cout << c1 + c2;

	ComplexNumbers::Complex c3(4, 2);
	cout << c3 + 8;
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

	Complex operator+(const Complex &c1, const Complex &c2)
	{
		return Complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
	}

	Complex operator+(const Complex &c1, double d)
	{
		return Complex(c1.getReal() + d, c1.getImaginary());
	}

	Complex operator+(double d, const Complex &c1)
	{
		//return Complex(c1.getReal() + d, c1.getImaginary());
		// OR 
		return operator+(c1, d);
	}
}