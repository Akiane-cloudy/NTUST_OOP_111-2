/*****************************************************************//**
 * file : Complex.h
 * Author : ³¯«Û¾§ 
 * Create date : April 28, 2023
 * Last update : April 28, 2023
 * Description : Complex.h
 *********************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
public:
	double realValue, imaginaryValue;

	Complex();
	//~Complex();
	Complex(double r);
	//~Complex(double r);
	Complex(double r, double i);
	//~Complex(double r, double i);
	double real(); // return the real value
	double imag(); // return the imaginary value
	double norm(); // return the norm value of this complex number
	friend double real(Complex c); // return the real value of the input complex number
	friend double imag(Complex c); // return the imaginary value of the input complex number
	friend double norm(Complex c); // return the norm value of the input complex number
	Complex operator+(Complex c); // overloading the operator+ of this complex number + the input complex number
	Complex operator-(Complex c); // overloading the operator- of this complex number - the input complex number
	Complex operator*(Complex c); // overloading the operator* of this complex number * the input complex number
	Complex operator/(Complex c); // overloading the operator/ of this complex number / the input complex number
	friend Complex operator+(double d, Complex c); // overloading the operator+ with two parameters
	friend Complex operator-(double d, Complex c); // overloading the operator- with two parameters
	friend Complex operator*(double d, Complex c); // overloading the operator* with two parameters
	friend Complex operator/(double d, Complex c); // overloading the operator/ with two parameters
	friend bool operator==(Complex c1, Complex c2);	// overloading the operator== with two parameters
	friend ostream& operator<<(ostream &strm, const Complex &c); // overloading the outstream operator with two a complex number
	friend istream& operator>>(istream &strm,Complex &c); // overloading the instream operator with two a complex number
};
