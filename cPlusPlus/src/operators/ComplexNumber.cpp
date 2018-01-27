#include "ComplexNumber.h"

using namespace ComplexNumbers;

void runComplexNumbers()
{
	Complex c1(2, 3);
	cout << c1;

	Complex c2(4, 5);
	cout << c1 + c2;

	Complex c3(4, 2);
	cout << c3 + 8;
	Complex c4(c3);

	cout << (c1 == c2) << " " << !(c3 == c4) << endl;
	cout << c1 << *c1;

	// just be careful with operator precedence when applying many operators at once.
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
		out << "(" << complexNum.m_real << ", " << complexNum.m_imaginary << ")" << endl;
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

	bool Complex::operator==(const Complex &other) const
	{
		return m_real == other.m_real && m_imaginary == other.m_imaginary;
	}

	bool Complex::operator!=(const Complex &other) const
	{
		return !(*this == other);
	}

	// overload the dereference operator to give the complex conjugate
	Complex Complex::operator*() const
	{
		return Complex(m_real, -m_imaginary);
	}
}