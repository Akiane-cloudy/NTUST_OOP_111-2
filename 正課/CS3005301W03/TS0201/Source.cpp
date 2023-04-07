// Name: ³¯«Û¾§ B11115004
// Date: March 7, 2023
// Last Update: March 7, 2023
// Problem statement:  Compute_Standard_Deviation

#include <iostream> // use to print result and input data 
#include <cmath> // to calculate the square root and power 
using namespace std;

int main()
{
	for (int n; cin >> n;) // input the number of i
	{
		double *nums = new double[n]; // declare the nums array to store the input data
		double average(0.0); // init average

		for (int i(0); i < n; i++)
		{
			cin >> nums[i];
			average += (double)nums[i] / n; // compute the summary of every numbers, then compute the average
		}

		double sd(0.0); // sd represent the "Standard deviation"
		for (int i(0); i < n; i++)
		{
			sd += pow((nums[i] - average), 2); // sd = sqrt((nums[i] - average)^2 * 1/n) 
		}
		sd /= n;
		sd = sqrt(sd); // compute the standard deviation

		cout << "Average:" << average << "\tStandard deviation:" << sd << endl; // print the result
		
		delete []nums; // free the memory
	}

}