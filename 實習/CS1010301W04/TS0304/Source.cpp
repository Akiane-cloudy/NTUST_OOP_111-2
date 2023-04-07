/*****************************************************************//**
 * file : Source.cpp
 * Author : ³¯«Û¾§ 
 * Create date : March 16, 2023
 * Last update : March 16, 2023
 * Description : CPU_Bit_Growth
 *********************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int year;
	// infinite loop until cin meets eof
	while (cin >> year)
	{
		int bits = 4 * pow(2, (year - 1900) / 10); // every 10 years 4 bits will grow by a multiple of 2 
		int counter(0); // use to compute the biggest factorial
		double factorial(0); // the sum of log2(factorial)

		for (int i = 1; factorial < bits; i++,counter++) // if factorial > bits it means the sum of factorial is larger than bits
		{
			factorial += log2(i);
		}

		cout << counter - 1 << endl; // because when it jump out the for loop, counter will +1 one more time
	}

	return 0;
}