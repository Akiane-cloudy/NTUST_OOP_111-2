/*****************************************************************//**
 * file : main.cpp
 * Author : ³¯«Û¾§ 
 * Create date : April 13, 2023
 * Last update : April 13, 2023
 * Description : Large Integer operation
 *********************************************************************/
#include "BigI.h" // import the BigI class

#include <iostream>
using namespace std;

int main()
{
	string input1, input2; // declare two input string
		
	while (cin >> input1 >> input2) //read the input string
	{	
		BigI num1(input1), num2(input2); // create two BigI object and initial its value tp be input
		 
		// print out the result of + - and *
		cout << num1 + num2 << '\n'
			 << num1 - num2 << '\n'
			 << num1 * num2 << '\n';
	}

	return 0;
}
