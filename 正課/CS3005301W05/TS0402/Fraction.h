/*****************************************************************//**
 * file : Fraction.h
 * Author : ³¯«Û¾§ 
 * Create date : March 24, 2023
 * Last update : March 24, 2023
 * Description : the Fraction.h use to define the calss fraction
 *********************************************************************/
#ifndef _Fraction_H_ // if not define the Fraction.h 
#define _Fraction_H_ // then define the Fraction.h
#include <iostream>
#include <iomanip> // use to set precision of the output
using namespace std;

// create a Fraction class
class Fraction
{
private:
	int numerator; // define the numerator
	int denominator; // define the denomonator
	// declare a private function GCD to get the greater common divisor of numerator and denomenator
	int greatestCommonDivisor(); 
public:
	void setNumerator(int nu); // set the numerator to the parameter
	void setDenominator(int de); // set the denominator to the parameter
	void getDouble(); // output the fraction by a double form, if the numerator divide by denomiantor, then output by a integer form
	void outputReducedFraction(); // output the fraction by a reduced fractio form
};

#endif //Fraction_H