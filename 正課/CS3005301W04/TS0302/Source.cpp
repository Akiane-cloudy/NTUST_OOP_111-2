// Name: ³¯«Û¾§ B11115004
// Date: March 14, 2023
// Last Update: March 14, 2023
// Problem statement: TextBased_Histogram

#include <iostream>
#include <fstream> // use to read the grade.txt
#include <sstream> // let the input string be the another input stream
#include <map> // to store the amount of each nuber that apear
using namespace std;

int main(void)
{
	ifstream fileInput("grade.txt"); // open file and let it be an input stream 
	ofstream outPut("grades.Output"); // open file and let it be an output stream

	// set a string to store the input data from file until eof
	for (string inputString; getline(fileInput, inputString);)
	{
		//initial a map which has six keys 0 to 5, and every value is 0
		//let the input string be a new input stream, and store every number that appear in the map grade
		map<int, int> grade{ {0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0} };
		stringstream stringStream(inputString);
		
		for (int temp; stringStream >> temp; grade[temp]++); // if the number is apear, than its value will + 1

		// declare an iterator to print out every value and its key on the grades.Output file
		for (auto& mapIte : grade) 
		{
			outPut << mapIte.second << " grade(s) of " << mapIte.first << endl;
		}
	}

	fileInput.close(); // close the input file stream
	outPut.close(); //close the output file stream

	return 0;
}