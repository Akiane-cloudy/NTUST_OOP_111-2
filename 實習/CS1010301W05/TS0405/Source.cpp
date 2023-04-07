/*****************************************************************//**
 * file : Source.cpp
 * Author : ³¯«Û¾§ 
 * Create date : March 23, 2023
 * Last update : March 23, 2023
 * Description : Collatz_Conjecture
 *********************************************************************/
#include <iostream> 
#include <algorithm> // use the max and min function
#include <vector> // to store the every case of size of collatz conjecture 
using namespace std;

int main()
{
	int num1, num2; // two numbers represents the begin and end

	while (cin >> num1 >> num2) // input two numbers until the input data is eof
	{
		int maxLength = 0; // declare the max length is 0, if any case if large than it than update the value

		for (int i = min(num1, num2); i <= max(num1, num2); i++) // the case begin from the smaller number of two numbers
		{
			vector<int> collatzConjecture; // use vector to store the collatz conjecture number 
			collatzConjecture.push_back(i); // push the first number of this conjecture

			while (collatzConjecture.back() != 1) // the loop will continue until the final number equal to 1
			{
				// declare a push back number, if the last number of this vector is even number
				// then push back the last number / 2
				// else if the last number is odd number, then push back the last number * 3 + 1
				int pushBackNum = (collatzConjecture.back() % 2 == 0) ? collatzConjecture.back() / 2 : collatzConjecture.back() * 3 + 1;
				collatzConjecture.push_back(pushBackNum);
			}

			maxLength = max(maxLength, (int)collatzConjecture.size()); // use max function to find the max length of all the cases
		}

		cout << num1 << " " << num2 << " " << maxLength << endl; // out put the result.
	}
}
