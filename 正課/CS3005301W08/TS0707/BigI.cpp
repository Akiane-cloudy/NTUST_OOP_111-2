/*****************************************************************//**
 * file : BigI.cpp
 * Author : ³¯«Û¾§ 
 * Create date : April 13, 2023
 * Last update : April 13, 2023
 * Description : BigI class implement
 *********************************************************************/
#include "BigI.h"

#include <vector>

void del(string& result); // delete the 0 that is don't need
void initial(string& lhs, string& rhs); // initial the string length from two string

/**
 * Intent : a default constructor for class BigI 
 * pre : create a BigI class
 * post : create a BighI class and initial its value to be "0"
 */
BigI::BigI()
{
	this->value = "0"; // set the value to be "0"
}

/**
 * Intent : a constructor which will initial the value to be input string
 * pre : create a BigI class and need a parameter to pass
 * post : create a BigI class and initial its value to be input value
 * \param value
 */
BigI::BigI(string value)
{
	this->value = value; // set the value to be the input value
}

/**
 * Intent : a function to set the value
 * pre : none
 * post : modify the value to be the input value
 * \param value
 */
void BigI::setValue(string value)
{
	this->value = value; // set the value to be the input values
}

/**
 * Intent : get the value
 * pre : none
 * post : return the value
 * \return 
 */
string BigI::getValue()
{
	return this->value; // return the current value
}

/**
 * Intent : a operator overloading function overload the +
 * pre : none
 * post :will get the current object + rhs value 
 * \param rhs
 * \return 
 */
string BigI::operator+(BigI& rhs)
{
	string big1 = this->getValue(); // declare big1 to be the current object's value
	string big2 = rhs.getValue(); // declare big2 to be the rhs's value
	string result = ""; // set the result 

	initial(big1, big2); // initial the length for both string
	const int SIZE = big1.size(); // defined a SIZE const int varialbe of two strings 
	bool carry = false; // check if the carry is true

	// use a for loop to plus every elements of two value
	for (int i = SIZE - 1; i >= 0; i--)
	{
		int sum = 0; // use sum to store the summary of two numbers

		sum += (big1[i] - '0' + big2[i] - '0'); // summary the two number of two string and store in the sum variable

		if (carry == true) // if the carry == true, then the sum need to plus 1
		{
			sum += 1; // let sum + 1 
			carry = false; // and set carry to be false
		}

		carry = sum / 10; // if sum is > 10, then carry will be true
		sum %= 10; // sum %= 10 means get the remain if the sum is larger than 10
		result = char(sum + '0') + result; // push the sum into the result string
	}

	if (carry == true) // if the carry is still keep true that mean need to carry one more times
	{
		result = '1' + result; // carry one more times
	}

	del(result); // delete the 0 that we don't need
	 
	return result; // return the result string
}

/**
 * Intent : a operator overloading function overload the -
 * pre : none
 * post : will get the current object - rhs value 
 * \param rhs
 * \return 
 */
string BigI::operator-(BigI& rhs)
{
	string big1 = this->getValue(); // declare big1 to be the current object's value
	string big2 = rhs.getValue(); // declare big2 to be the rhs's value
	string result = ""; // set the result 

	if (big1 == big2) // if the big1 = big2 that mean the result will be 0
	{
		return "0";
	}

	initial(big1, big2); // initial the length of two string 
	const int SIZE = big1.size(); // defined a SIZE const int varialbe of two strings 
	int borrow = 0; // check if it needs to borrow
	bool isNegative = false; // check if the result will be negative 
	
	if (big1 < big2) // check if the big2 > big1
	{ 
		swap(big1, big2); // if the big2 > big1 then swap them
		isNegative = true; // then set the isNegative to be true
	}

	// use for loop to compute the every diffrence value
	for (int i = SIZE - 1; i >= 0; i--)
	{
		int sum = 0; // declare a sum to store the diffrence from two number

		sum += ((big1[i] - '0') - (big2[i] - '0')) - borrow; // compute the diffrence of to numbers 

		if (sum < 0) // check if the sum is less than 0
		{
			sum += 10; // if sum is less than 0, then plus 10
			borrow = 1; // and set the borrow be 1
		}
		else
		{
			borrow = 0; // if sum is bigger than 0, set the borrow be 0
		}

		result = char(sum + '0') + result; // push the sum into the result string
	}
	
	if (isNegative == true) // check if the result is negative number
	{
		result = "-" + result; // if the result is a negative number than add a '-' in front of the result string
	}

	del(result); // delete the 0 that we don't need
	
	return result; // return the result string
}

/**
 * Intent : a operator overloading function overload the *
 * pre : none
 * post : will get the current object * rhs value 
 * \param rhs
 * \return 
 */
string BigI::operator*(BigI& rhs)
{
	string big1 = this->getValue(); // declare big1 to be the current object's value
	string big2 = rhs.getValue(); // declare big2 to be the rhs's value
	string resultStr = ""; // declare resultStr to store the final answer
	vector<int> result((big1.size() + big2.size()), 0); // declare a vector to store the result of two bigInt product

	if (big1.size() < 2 && big2.size() < 2) // check if two string both length are less than 2
	{
		// if the length are < 2, then return the answer quickly
		return to_string((big1[0] - '0') * (big2[0] - '0'));
	}

	// reverse two strings because I want to compute from index of 0
	// but in c++ the 0 of index is the final last number for a number
	reverse(big1.begin(), big1.end());
	reverse(big2.begin(), big2.end());

	// use two for loop to compute the product result
	for (int i = 0; i < big1.size(); i++)
	{
		for (int j = 0; j < big2.size(); j++)
		{
			int num1 = big1[i] - '0'; // let the num1 be the number of i of index of big1
			int num2 = big2[j] - '0'; // let the num2 be the number of j of index of big2

			result[i + j] += num1 * num2; // every index of i + j is the big1[i] * big2[i] 
			result[i + j + 1] = result[i + j + 1] + result[i + j] / 10; // if the result is bigger than 10 then carry it to next number
			result[i + j] %= 10; // do the remain if the result is bigger than 10
		}
	}

	// use a for loop to push the answer back to resultStr 
	for (int i = 0; i < result.size(); i++)
	{
		resultStr = to_string(result[i]) + resultStr; // insert the result in front of the resultPtr 
	}

	del(resultStr); // delete the 0 that we don't need

	return resultStr; // return the result 
}

/**
 * Intent : a function to set the length of two string
 * pre : none
 * post : modify the string
 * \param lhs
 * \param rhs
 */
void initial(string& lhs, string& rhs)
{
	while (lhs.size() < rhs.size()) // while the lhs's length is less than rhs, insert a 0 infont of the string
	{
		lhs = '0' + lhs; // insert a '0' in front of the the lhs
	}

	while (lhs.size() > rhs.size()) // while the rhs's length is less than lhs, insert a 0 infont of the string
	{
		rhs = '0' + rhs; // insert a '0' in front of the the rhs
	}
}
 
/**
 * Intent : a function to delete the 0 that we don't need
 * pre : none
 * post : modify the string
 * \param result
 */
void del(string& result)
{
	auto i = result.begin(); // declare a iterator i and set it be the begin of result

	if (result[0] == '-') // check if the result is a negative number
	{
		i++; // if the resualt is a negative number, then the iterater will move to the next position 
	}

	// use a for loop tot run every elements
	// if it is 0 then remove that till the elements meets none-zero or the length is 1
	for (; i != result.end() && result.size() > 1;)
	{
		if ((*i) == '0') // check if the elements is 0
		{
			result.erase(i); // if the elements is '0' then erase that
		}
		else
		{
			break; // if meets the none-zero number than break
		}
	}
}
