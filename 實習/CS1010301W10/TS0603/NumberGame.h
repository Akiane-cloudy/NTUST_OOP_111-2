/*****************************************************************//**
 * file : NumberGame.h
 * Author : ³¯«Û¾§ 
 * Create date : May 2, 2023
 * Last update : May 2, 2023
 * Description : NumberGame.h
 *********************************************************************/
#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Declare the NumberGame class
class NumberGame
{
private:
	int value, maxValue = 1; // Declare the input number value and the max product number 
	string filePath; // Store the filePath
	vector<int> numList; // Splitting the number to digit and store it
	vector<int> validAnswer; // Store the valid answer of the file 

public:
	NumberGame() = default; // A default constructor
	void SetInput(int); // Set the input values
	void ProcessInput(); // Splitting the number to digit
	void SetFileName(string); // Set the file path
	void LoadNumberList(); // Load the number of the file 
	void PrintAllValid(); // Print the all valid answer of the file
	void Reset(); // Reset the answer and numlist 
};
