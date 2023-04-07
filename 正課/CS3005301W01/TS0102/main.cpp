// Name: ³¯«Û¾§ B11115004
// Date: February 22, 2023
// Last Update: February 22, 2023
// Problem statement: ComputeHMS

#include <iostream>
using namespace std;

int main()
{
	unsigned long long sec;

	while (cin >> sec)
	{
		unsigned long long mins = sec / 60; //init mins
		sec = sec % 60;						//count sec
		unsigned long long hrs = mins / 60; //init hrs
		mins = mins % 60;					//count mins

		cout << hrs << " hours " << mins << " minutes and " << sec << " seconds" << endl;
	}

	return 0;
}