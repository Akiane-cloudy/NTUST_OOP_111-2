/*****************************************************************//**
 * file : Source.cpp
 * Author : ³¯«Û¾§ 
 * Create date : March 23, 2023
 * Last update : March 23, 2023
 * Description : Greatest_Common_Divisor
 *********************************************************************/
#include <iostream>
using namespace std;

/**
 * Intent : the function will return the GCD number fo two number
 * pre : num2 must not euqal to 0
 * post : the function will return the GCD number fo two number
 * \param num1
 * \param num2
 * \return the GCD of them
 */
int greatestCommonDivisor(int num1, int num2)
{
	// if one of them become zero, then return the sum of them and that is the GCD number of two input number
	if (num2 == 0)
	{
		return num1 + num2; // return the sum of two input number
	}

	// use "Euclidean algorithm" to compute the GCD number
	// first use the first number divide by the second number, and the second divide by the mod from step 1
	// until one of them become zero, them stop the recursion
	return greatestCommonDivisor(num2, num1 % num2);
}

int main()
{
	int num1, num2; // declare two input numbers

	while (cin >> num1 >> num2) // enter the numbers until eof
	{
		cout << greatestCommonDivisor(num1, num2) << endl; // call the GCD function, and return GCD of them
	}

	return 0; // end the program
}
