/*****************************************************************//**
 * file : NumberGame.cpp
 * Author : ³¯«Û¾§ 
 * Create date : May 2, 2023
 * Last update : May 2, 2023
 * Description : NumberGame.cpp
 *********************************************************************/
#include "NumberGame.h"

/**
 * Intent : Set the value to the input value
 * pre : The vlaue must not be empty
 * post : Set the private value to the input value
 * \param value
 */
void NumberGame::SetInput(int value)
{
	// Set the value to the input value
	this->value = value;
}

/**
 * Intent : Splitting the value to digit
 * pre : The value must not be empty
 * post : Splitting the number and store it to the numList
 */
void NumberGame::ProcessInput()
{
	// Splitting the number and store it to the numList
	for (; value > 0; value /= 10) {
		// Store the digit without zero
		if (value % 10 != 0) {
			this->numList.push_back(value % 10);
			this->maxValue *= value % 10; // use a maxValue to store the max product result
		}
	}

	sort(begin(numList), end(numList), greater<int>()); // Sort the list from the largest one to the smallest one
}

/**
 * Intent : Set the file name to the input path
 * pre : the path must not be empty
 * post : Set the file path to the input string
 * \param path
 */
void NumberGame::SetFileName(string path)
{
	// Set the filePath to the input string
	this->filePath = path;
}

/**
 * Intent : Load the number list from the file and store the valid answer 
 * pre : The file path must not be empty
 * post : Store the valid answer from the file to the validAnswer vector
 */
void NumberGame::LoadNumberList()
{
	// Decalre a unordered_map productList to store each product from the combination for each digits
	unordered_map<int, bool> productList;
	for (const int& digit : this->numList) {
		// Use a temp unodered map to store the previous product result 
		unordered_map<int, bool> temp;
		for (const auto& num : productList) {
			// Store the product result with the previous result and the new digit
			temp[num.first * digit] = true;
		}
		for (const auto& pair : temp) {
			// Store the all result from the temp
			productList[pair.first] = true;
		}
		// Add the new digit to the previous result
		productList[digit] = true;
	}

	// Read the file and check if the number of the list is valid
	for (ifstream file(this->filePath); !file.eof(); ) {
		int inputNum;
		file >> inputNum; // Read the file and get the number

		// If the input number is larget than the maxValue which is the max product result from the numList 
		// then break
		if (inputNum > maxValue) {
			break;
		}

		// Check if the inputNum is valid
		if (productList[inputNum]) {
			this->validAnswer.push_back(inputNum);
		}
	}
}

/**
 * Intent : Print the all valid number from te validAnswer vector
 * pre : The valid answer must be stored to the validAnswer vecror
 * post : Print the all valid answer from the validAnswer vector
 */
void NumberGame::PrintAllValid()
{
	// Print the all valid answe from the validAnswer vector
	for (const int& num : this->validAnswer) {
		cout << num << '\n';
	}
}

/**
 * Intent : Reset the all number and result of the numList and the validAnswer
 * pre : The Reset function be called
 * post : Clear the numList and the validAnswer vector
 */
void NumberGame::Reset()
{
	// Clear the numList and the validAnswer vector
	this->numList.clear();
	this->validAnswer.clear();
}
