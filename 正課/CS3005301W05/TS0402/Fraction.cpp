/*****************************************************************//**
 * file : Fraction.cpp
 * Author : ³¯«Û¾§ 
 * Create date : March 21, 2023
 * Last update : March 21, 2023
 * Description : Fraction
 *********************************************************************/
#include "Fraction.h" // import the Fraction.h

/**
 * Intent : set the numerator to the parameter nu
 * pre : the parameter must be an integer
 * post : modify the numerator to nu
 * \param nu
 */
void Fraction::setNumerator(int nu)
{
	this->numerator = nu; // set the numerator to parameter nu
}

/**
 * Intent : set the denominator to the parameter de
 * pre : the parameter must be an integer
 * post : modify the denominator to the parameter de
 * \param de
 */
void Fraction::setDenominator(int de)
{
	this->denominator = de; // set the denominator to parameter de
}

/**
 * Intent : output the double value of the fraction, if the fraction is an integer then out put an integer
 * pre : none
 * post : out put the fraction value use a double number form or an integer
 */
void Fraction::getDouble()
{
	// if the numerator % denominator is not equal to 0, then output the double value form
	// else, output the integer form
	if (this->numerator % this->denominator != 0) {
		cout << fixed << setprecision(6) << (double)this->numerator / this->denominator << endl; // print the double form and set precision to 6
	}
	else {
		cout << numerator / denominator << endl; // output an integer form
	}
}

/**
 * Intent : output the reduced fraction 
 * pre : none
 * post : output the reduced fraction 
 */
void Fraction::outputReducedFraction()
{
	// if the numerator % denominator is not equal to 0 
	// then print out the numerator / denominator form and this is the reduced fraction form
	// else print out the numerator / denominator
	if (this->numerator % this->denominator != 0) {
		cout << this->numerator / greatestCommonDivisor() << '/' << this->denominator / greatestCommonDivisor() << endl; // print out the reduced fraction form 
	}
	else {
		cout << numerator / denominator << endl; // print out an integer form
	}
}



/**
 * Intent : output the greatest common divisor number of numerator and denominator
 * pre : the numerator and denominator must have value
 * post : return the gcd number of numerator and denominator
 * \return the gcd number of numerator and denominator
 */
int Fraction::greatestCommonDivisor()
{
	int num1 = this->numerator; // declare num1 to the numerator 
	int num2 = this->denominator; // delcare num2 to the denominator

	// if num2 is not equal to 0, then use the Euclidean algorithm to compute the gcd number
	// if one of them is become 0, then return the sum of two numbers
	if (num2 != 0) { 
		while ((num1 %= num2) && (num2 %= num1)); // if one of them become 0 then break the loop
	}

	return num1 + num2; // return the sum of two numbers
}



