/*****************************************************************//**
 * file : Atoi.cpp
 * Author : ³¯«Û¾§ 
 * Create date : April 12, 2023
 * Last update : April 12, 2023
 * Description : Implement the Atoi class
 *********************************************************************/
#include "Atoi.h"
#include <cmath> // use the power function

/**
 * Intent : a constructor to initial a empty string
 * pre : create a Atoi class
 * post : initial a Atoi class object and set its propety "beTrans" to a empty string
 */
Atoi::Atoi() : beTrans("") // initial the beTrans value be a empty string
{

}

/**
 * Intent : a constructor to initial a string a particular string
 * pre : create a Atoi class
 * post : initial a Atoi class object and set its propety "beTrans" to be s
 * \param s
 */
Atoi::Atoi(string s) : beTrans(s) // initial the beTrans value be s string
{
	
}

/**
 * Intent : set beTrans to the string s
 * pre : the string must be digital 
 * post : set beTrans to the string s
 * \param s
 */
void Atoi::SetString(string s)
{
	this->beTrans = s; // set beTrans to the string s
}

/**
 * Intent : get the beTrans string value
 * pre : the string must be digital 
 * post : get the beTrans string value
 * \return 
 */
const string Atoi::GetString()
{
	return this->beTrans; // return the beTrans string value
}

/**
 * Intent : get the length of the input string
 * pre : the string must be digital 
 * post : 
 * \return 
 */
int Atoi::Length()
{
	// return the beTrans.size() if it is a positive number, if it is a negative number then return beTrans.size() - 1
	return (this->beTrans[0] == '-') ? this->beTrans.size() - 1 : this->beTrans.size();
}

/**
 * Intent : check if the input string is valid, in another words is check if all the elements is digital
 * pre : none
 * post : check if the input string is valid
 * \return 
 */
bool Atoi::IsDigital()
{
	// use a for loop to run every elements from the beTrans
	for (const char& i : this->beTrans)
	{
		// if the character from the input string is over 0 ~ 9
		// and it isn't the '-', then return false
		if ((i < '0' || i > '9') && i != '-') 
		{
			return false;
		}
	}
	
	return true; // if every thing is alright then return true
}

/**
 * Intent : convert a string to a integer
 * pre : it must be digital 
 * post : return a integer that is convert from the string
 * \return 
 */
int Atoi::StringToInteger()
{
	int result = 0, index = 0; // declare the result and index

	if (this->beTrans[0] == '-')
	{
		// check if the string has '-', then it is a negative number 
		// so don't use the first place from the string
		index = 1; 
	}

	// use a for loop to compute the amounts
	for (; index < this->beTrans.size(); index++)
	{
		// let result + the value which is the every digital elements * its correct power of 10
		// and the power is the string size - index - 1
		result += (this->beTrans[index] - '0') * pow(10, this->beTrans.size() - index - 1);
	}

	// if beTrans[0] is '-' it means the number is negative so the result * (-1)
	return (this->beTrans[0] == '-') ? result * (-1) : result;
}
