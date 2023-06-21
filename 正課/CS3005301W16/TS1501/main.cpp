/*****************************************************************//**
 * file : main.cpp
 * Author : 陳彥儒
 * Create date : June 6, 2023
 * Last update : June 6, 2023
 * Description : Set Exercise
 *********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int main()
{
	// Declare a set to store the name without duplicate
	set<string> nameSet;
	ifstream in("name.txt"); // open the file to read

	// use for loop to store the input data
	for (string input; getline(in, input); ) {
		nameSet.insert(input); // insert to the name set
	}

	// use for loop to print the name in the name set
	for (const auto& name : nameSet) {
		cout << name << '\n';
	}
}
