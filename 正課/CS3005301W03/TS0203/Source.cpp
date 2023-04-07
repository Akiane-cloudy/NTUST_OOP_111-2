// Name: ³¯«Û¾§ B11115004
// Date: March 7, 2023
// Last Update: March 7, 2023
// Problem statement: Square_Code

#include <iostream>
#include <string>
using namespace std;

int getN(int length);

int main()
{
	string input; 
	while (cin >> input) // get the input data
	{
		const int n = getN(input.size()); // get the side lenght of square (n*n)
		for (int column(0); column < n; column++)
		{
			for (int row(0); row < n; row++)
			{
				// exchange the position of row and column
				// if the position is not found in origin input data
				// then just don't print anything
				if (row * n + column < input.size()) 
				{
					cout << input[row * n + column];
				}
			}
			cout << endl;
		}
	}
}

int getN(int length)
{
	int n(1);
	while (n * n < length) // if message length <= n^2, then return n
	{
		n++;
	}
	return n;
}