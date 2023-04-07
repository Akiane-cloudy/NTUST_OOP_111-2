/************************************************************************
File:   Source.cpp

Author:
		���s�Aea5878158@gmail.com
Modifier:
		�௧�N�Acheeryuchi@gmail.com
		���T�t�AJYCReports@gmail.com
Comment:
		Use clock to count time (And output) for following input tasks

************************************************************************/

// Name: ���۾� �\�ٷ_
// Date: Feb 22, 2023 
// Last Update: Feb 24, 2023 
// Problem statement: Use clock to count time (And output) for following input tasks.

#include <ctime>
#include <iostream> //use to print out the message
#include <iomanip> // use to count three digits after the decimal point
using namespace std;

int main(int argc, char** argv)
{
	clock_t startT, endT; // Variable to store the start of the gameloop
	startT = clock();
	endT = clock();
	clock_t globalStartT = startT;

	// Start the game loop
	/************************************************************************/
	/*Please implement your code here*/

	for (int times = 0; times < 15; times++)
	{
		// the clock() function catch the time which unit is milliseconds
		// so 1000 milliseconds is 1 second. 
		while (endT - startT != 1000) 
		{
			endT = clock(); // if the endT minus startT didn't reach 1 second, then re-get the endT.
		}

		cout << "Total time " << times << " at " << fixed << setprecision(3)  << ((double)(endT - globalStartT) / 1000) << endl;
		
		startT = endT; // re-defined the startT be the last endT
	}

	return 0;
	/************************************************************************/

}
