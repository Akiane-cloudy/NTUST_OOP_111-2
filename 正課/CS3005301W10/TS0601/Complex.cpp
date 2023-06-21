/*****************************************************************//**
 * file : Complex.cpp
 * Author : ³¯«Û¾§ 
 * Create date : April 25, 2023
 * Last update : April 25, 2023
 * Description : Complex.cpp
 *********************************************************************/
#pragma once
#include "Complex.h"

/**
 * Intent : A constructor with no parameter to construct the complex number
 * pre : no param input
 * post : construct a complex number
 */
Complex::Complex()
{
	// If the param is empty then construct a complex number which real and imag are 0
	this->realValue = 0; 
	this->imaginaryValue = 0;
}

/**
 * Intent : A constructor with parameter to construct the complex number
 * pre : need one real part parameter
 * post : construct a complex number with the input real number 
 */
Complex::Complex(double r)
{
	// If the param have only one and that is real number part, then set the param to be te real part of complex number and set imaginary is 0
	this->realValue = r;
	this->imaginaryValue = 0;
}

/**
 * Intent : A constructor with parameters to construct the complex number
 * pre : need two parameters real and imaginary 
 * post : construct a complex number with the input parameters 
 * \param r
 * \param i
 */
Complex::Complex(double r, double i)
{
	// Construct the Complex number with the input real part and imag part
	this->realValue = r;
	this->imaginaryValue = i;
}

/**
 * Intent : A member function to get the real part value of the complex number
 * pre : the obeject need to be constructed 
 * post : return the real part of this complex number
 * \return 
 */
double Complex::real()
{	
	// return the real value
	return this->realValue;
}

/**
 * Intent : A member function to get the imaginary part value of the complex number
 * pre : the obeject need to be constructed 
 * post : return the imaginary part of this complex number
 * \return 
 */
double Complex::imag()
{
	// return the imaginary part value
	return this->imaginaryValue;
}

/**
 * Intent : A member function to return the norm value of the complex number
 * pre : The complex number must to be constructed 
 * post : return the norm value of this complex number
 * \return 
 */
double Complex::norm()
{
	// return the norm value which compute step is power the real and imag part then accumulate them the square the value
	return sqrt(pow(this->realValue, 2) + pow(this->imaginaryValue, 2));
}

/**
 * Intent : Overloading the operator+
 * pre : none
 * post : return a complex which is this complex number + the parameter c
 * \param c
 * \return 
 */
Complex Complex::operator+(Complex c)
{	
	// return a complex number which real part is this real part and c, and the imag part is this imag part and the c's imag part
	return Complex(this->realValue + c.realValue, this->imaginaryValue + c.imaginaryValue);
}

/**
 * Intent : Overloading the operator-
 * pre : none
 * post : return a complex which is this complex number - the parameter c
 * \param c
 * \return 
 */
Complex Complex::operator-(Complex c)
{
	// return a complex number which real part is this real part minus the c's real part and so is imaginary part
	return Complex(this->realValue - c.realValue, this->imaginaryValue - c.imaginaryValue);
}

/**
 * Intent : Overloading the operator*
 * pre : none
 * post : return a complex which is this complex number * the parameter c
 * \param c
 * \return 
 */
Complex Complex::operator*(Complex c)
{	
	// declare the real parts is this real value * c's real value - this imag value * c's imag value
	double realParts = this->realValue * c.realValue - this->imaginaryValue * c.imaginaryValue;
	// declare the imag parts is this real val * c' imag val + c's real val * this imag val
	double imagParts = this->realValue * c.imaginaryValue + c.realValue * this->imaginaryValue;
	
	// return a complex number and its real parts is realParts and imag parts is imagParts
	return Complex(realParts, imagParts);
}

/**
 * Intent : Overloading the operator/
 * pre : none
 * post : return a complex which is this complex number / the parameter c 
 * \param c
 * \return 
 */
Complex Complex::operator/(Complex c)
{
	// Declare the nemerator is this * the c ehich imag must * -1
	Complex numerator = (*this) * Complex(c.realValue, ( - 1 ) * c.imaginaryValue);
	// Declate the denominator the norm of c
	double denominator = pow(c.realValue, 2) + pow(c.imaginaryValue, 2);

	// return the this / c
	return Complex(numerator.realValue / denominator, numerator.imaginaryValue / denominator);
}

/**
 * Intent : Return the real value of c
 * pre : the c must be a complex number 
 * post : return the real value
 * \param c
 * \return 
 */
double real(Complex c)
{
	// Return the real value fo the complex number c
	return c.realValue;
}

/**
 * Intent : Return the imaginary value of c
 * pre : the c must be a complex number 
 * post : return the imag value
 * \param c
 * \return 
 */
double imag(Complex c)
{	
	// Return the imaginary value
	return c.imaginaryValue;
}

/**
 * Intent : Return the norm value of c
 * pre : the c must be a complex number 
 * post : return the norm value
 * \param c
 * \return 
 */
double norm(Complex c)
{
	// return the norm value of c
	return c.norm();
}

/**
 * Intent : Overloading the operator+ of a constant and a complex number
 * pre : none
 * post : return the computation result
 * \param d
 * \param c
 * \return 
 */
Complex operator+(double d, Complex c)
{
	// Return the complex number plus the constant
	return Complex(d + c.realValue, c.imaginaryValue);
}

/**
 * Intent : Overloading the operator- of a constant and a complex number
 * pre : none
 * post : return the computation result
 * \param d
 * \param c
 * \return 
 */
Complex operator-(double d, Complex c)
{
	// Return the constant minus the complex number 
	return Complex(d - c.realValue, -1 * c.imaginaryValue);
}

/**
 * Intent : Overloading the operator* of a constant and a complex number
 * pre : none
 * post : return the computation result
 * \param d
 * \param c
 * \return 
 */
Complex operator*(double d, Complex c)
{
	// return the constant mutiply the complex number c
	return Complex(d * c.realValue, d * c.imaginaryValue);
}

/**
 * Intent : Overloading the operator/ of a constant and a complex number
 * pre : none
 * post : return the computation result
 * \param d
 * \param c
 * \return 
 */
Complex operator/(double d, Complex c)
{
	// declare a numerator is the compelx number which real part is the constant * c.realValue and the imag part is constant * c. imagnaryValue * -1
	Complex numerator = Complex(d * c.realValue, d * (-1) * c.imaginaryValue);
	// declare the denominator is the norm value of the c
	double denominator = pow(c.realValue, 2) + pow(c.imaginaryValue, 2);

	// return the complex number is combined with numerator and the denominator
	return Complex(numerator.realValue / denominator, numerator.imaginaryValue / denominator);
}

/**
 * Intent : Overloading the operator== of a constant and a complex number
 * pre : none
 * post : Check if the two complex number c1 and c2 is equal 
 * \param c1
 * \param c2
 * \return 
 */
bool operator==(Complex c1, Complex c2)
{
	// Return true if the real value and imag value are both equivlent 
	return (c1.realValue == c2.realValue && c1.imaginaryValue == c2.imaginaryValue);
}

/**
 * Intent : Overloading the outStream 
 * pre : none
 * post : print out the c.real and c.imag
 * \param strm
 * \param c
 * \return 
 */
ostream& operator<<(ostream& strm, const Complex& c)
{
	// return the ostream to be the real part and the imag part
	return strm << c.realValue << " + " << c.imaginaryValue << "*i";
}

/**
 * Intent : Overloading the istream 
 * pre : none
 * post : get the value of te complex number
 * \param strm
 * \param c
 * \return 
 */
istream& operator>>(istream& strm, Complex& c)
{
	// ignore the "x = "
	strm.ignore(4);
	// input the real part of c
	strm >> c.realValue;

	// ignore the " + "
	strm.ignore(3);
	// input the imag part of c
	strm >> c.imaginaryValue;
	
	// return and ignore the "i*\n"
	return strm.ignore(3);
}

