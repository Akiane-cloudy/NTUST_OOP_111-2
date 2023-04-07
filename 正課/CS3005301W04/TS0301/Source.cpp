// Name: ³¯«Û¾§ B11115004
// Date: March 14, 2023
// Last Update: March 14, 2023
// Problem statement: Occurenc_Counting

#include <iostream>
#include <sstream> // let the input string become a input stream
#include <map> // to store the amount of each number that appear
using namespace std;

int main()
{
	string inputString; // declare a string to store the input string 

	// because of the input data has many space
	// so I choose getline to get the whole line string
	while (getline(cin, inputString)) 
	{
		stringstream outStream(inputString);
		// use map to store the amount of each number that appear
		// and greater mean descending sort the map
		map<int, int, greater<int>> input;

		// use an integer "temp" varialbe to store every number read from the string stream
		// if the number is appearing more times, and its value will + 1 : {key, value} 
		for (int temp; outStream >> temp; input[temp]++);

		cout << "N\tcount\n";
		// use a iterator to print out all of value of the map
		// first mean the key and second mean the value
		for (auto& inputIte : input) 
		{
			cout << inputIte.first << '\t' << inputIte.second << endl;
		}
	}
	return 0;
}