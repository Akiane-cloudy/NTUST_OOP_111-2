// Name: ³¯«Û¾§ B11115004
// Date: March 9, 2023
// Last Update: March 9, 2023
// Problem statement: Compute_The_Tax

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	for (double income; cin >> income;)
	{
		double tax(0);

		if (income <= 750.0) // the income is lower than 750
		{
			tax = income * 0.01;
		}

		else if (income <= 2250.0) // the income between 750 ~ 2250
		{
			tax = (income - 750.0) * 0.02 + 7.50;
		}

		else if (income <= 3750.0) // the income between 2250 ~ 3750
		{
			tax = (income - 2250.0) * 0.03 + 37.50;
		}

		else if (income <= 5250.0) // the income between 3750 ~ 5250
		{
			tax = (income - 3750.0) * 0.04 + 82.50;
		}

		else if (income <= 7000.0) // the income between 5250 ~ 7000
		{
			tax = (income - 5250.0) * 0.05 + 142.50;
		}

		else // the income larger than 7000
		{
			tax = (income - 7000.0) * 0.06 + 230.00;
		}

		cout << fixed << setprecision(2) << tax << endl;
	}
}