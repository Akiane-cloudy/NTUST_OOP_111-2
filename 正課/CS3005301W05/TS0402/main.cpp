/*****************************************************************//**
 * file : main.cpp
 * Author : ³¯«Û¾§ 
 * Create date : March 24, 2023
 * Last update : March 24, 2023
 * Description : the main.cpp of Fraction use to test some simple input
 *********************************************************************/
#include <iostream>
#include "Fraction.h" // import the Fraction.h
using namespace std;

int main()
{
	Fraction f1, f2; // create two Fraction class f1 and f2
	f1.setNumerator(4); // set the f1's numerator to 4
	f1.setDenominator(2); // and set f1's denominator to 2
	f1.getDouble(); // output the double form or the integer form of the fraction f1
	f1.outputReducedFraction(); // out put the reduced fraction form of the fraction f1

	f2.setNumerator(20); // set the f2's numerator to 20
	f2.setDenominator(60); // and set f2's denominator to 60
	f2.getDouble(); // output the double form or the integer form of the fraction f2
	f2.outputReducedFraction(); // out put the reduced fraction form of the fraction f2
	return 0; // end the program
}