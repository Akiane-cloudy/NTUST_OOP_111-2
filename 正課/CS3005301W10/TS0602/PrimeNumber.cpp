/*****************************************************************//**
 * file : PrimeNumber.cpp
 * Author : ³¯«Û¾§ 
 * Create date : April 28, 2023
 * Last update : April 28, 2023
 * Description : PrimeNumber.cpp
 *********************************************************************/
#include "PrimeNumber.h"

/**
 * Intent : A functio to check if a number is a prime number
 * pre : the num must not ne empty
 * post : return tur or false
 * \param num
 * \return 
 */
bool isPrime(int num)
{
	for (int i = 2; i <= sqrt(num); i++)
	{
		// If there has any number is the num's factor then return false
		if (num % i == 0)
			return false;
	}
	
	// If there has no any factor of the num then return ture
	return true;
}

/**
 * Intent : A constructor to initial the value to be 1
 * pre : none
 * post : Construct a PrimeNumber object
 */
PrimeNumber::PrimeNumber()
{
	this->value = 1;
}

/**
 * Intent : A constructor to initial the value to the input value 
 * pre : none
 * post : Construct a PrimeNumber object
 * \param _value
 */
PrimeNumber::PrimeNumber(int _value)
{
	// Initial the value to be the input value
	this->value = _value;
}

/**
 * Intent : Get the value of this object
 * pre : none
 * post : return the value of this object
 * \return 
 */
int PrimeNumber::get()
{
	// return the value
	return this->value;
}

/**
 * Intent : Overloading the operator++ and this is a prefix operator
 * pre : none
 * post : return a primenumber
 * \return 
 */
PrimeNumber& PrimeNumber::operator++()
{
	// Find the next prime number of this value 
	for (this->value += 1; isPrime(this->value) != true; (this->value)++);

	// return this
	return *this;
}

/**
 * Intent : Overloading the operator++ and this is a postfix operator
 * pre : none	
 * post : return the next primenumber
 * \param 
 * \return 
 */
PrimeNumber PrimeNumber::operator++(int)
{
	// Store the origin value of this object
	int origin = this->value;
	// find the next prime number
	++(*this);

	return PrimeNumber(origin); // return the origin prime number
}

/**
 * Intent : Overloading the operator++ and this is a prefix operator
 * pre : none
 * post : return a last primenumber
 * \return 
 */
PrimeNumber& PrimeNumber::operator--()
{
	// find the last primenumber of this primenumber
	for (this->value -= 1; isPrime(this->value) != true; (this->value)--);

	// return this
	return *this;
}

/**
 * Intent : Overloading the operator++ and this is a postfix operator
 * pre : none
 * post :  return a last primenumber
 * \param 
 * \return 
 */
PrimeNumber PrimeNumber::operator--(int)
{
	// Store the origin value of this object
	int origin = this->value;
	// find the last prime number
	--(*this);

	// return the last primenumber
	return PrimeNumber(origin);
}
