/*****************************************************************//**
 * file : BigI.h
 * Author : ³¯«Û¾§ 
 * Create date : April 13, 2023
 * Last update : April 13, 2023
 * Description : BigI class defined 
 *********************************************************************/
#pragma once

#include <string> 
#include <cstring> // use the cstring tool
using namespace std;

// create a class BigI 
class BigI
{
private:
	string value; // the value of the class

public:
	BigI(); // a default constructor 
	BigI(string); // a constructor to initial the value to be input string
	void setValue(string); // set the value to be the input string
	string getValue(); // get the value

public:
	string operator+(BigI& rhs); // overload the operator+
	string operator-(BigI& rhs); // overload the operator-
	string operator*(BigI& rhs); // overload the operator*
};
