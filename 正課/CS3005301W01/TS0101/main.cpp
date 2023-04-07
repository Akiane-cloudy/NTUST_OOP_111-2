// Name: ³¯«Û¾§, B11115004
// Date: February 22, 2023
// Last Update: February 22, 2023
// Problem statement: ComputeSQRT

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double n,guess,preGuess (0);

	while (cin >> n)
	{
		guess = n / 2;

		do
		{
			preGuess = guess; //init the every time's preGuess
			double r = n / guess;
			guess = (guess + r) / 2;
		} while (preGuess - guess >= 0.01);

		cout << fixed << setprecision(2) << guess <<endl; 
	}

	return 0;
}
