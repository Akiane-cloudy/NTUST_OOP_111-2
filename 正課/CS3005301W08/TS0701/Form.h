/*****************************************************************//**
 * file : Form.h
 * Author : ³¯«Û¾§ 
 * Create date : April 12, 2023
 * Last update : April 12, 2023
 * Description : Form.h
 *********************************************************************/
#include <string>
#include <iostream>
#include <fstream> // to get the input file 
#include <vector> // store the answer

using namespace std;
class Form
{
private:
	vector<string> answer; // delcare a vector to store the answer
	string targetWord; // declare a varial to store the input word
	string filePath; // declare a varialbe to store the input file path

public:
	void SetInputWord(string inputWord); // set input
	void ProcessInputWord(); // process input
	void SetFileName(string fileName); // set file name
	void Load_CompareWord(); // read-in data and compare
	void PrintFoundWords(); // print answers
};
