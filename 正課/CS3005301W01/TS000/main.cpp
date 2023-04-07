// Name: ³¯«Û¾§, B11115004
// Date: February 22, 2023
// Last Update: February 22, 2023
// Problem statement: Writing Hello World!

#include <iostream>
using namespace std;

int main()
{
	int times;

	while (cin >> times) //init how many times we need to print.
	{
		while (times--)
		{
			cout << "Hello World!" << endl;
		}
	}

	return 0;
}