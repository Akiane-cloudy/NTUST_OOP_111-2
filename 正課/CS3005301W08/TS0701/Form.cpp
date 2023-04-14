/*****************************************************************//**
 * file : Form.cpp
 * Author : ³¯«Û¾§ 
 * Create date : April 11, 2023
 * Last update : April 12, 2023
 * Description : Implement the Form class
 *********************************************************************/
#include "Form.h"

/**
 * Intent : set the input word 
 * pre : none
 * post : catch the input word
 * \param inputWord
 */
void Form::SetInputWord(string inputWord) {
	targetWord = inputWord; // store the input word
}

/**
 * Intent : initial the input word
 * pre : none
 * post : modify the input word to the form
 */
void Form::ProcessInputWord(){
	// use a for loop to run every elements to let it be lower case
	for (auto& i : targetWord) {
		i = tolower(i); // use tolower function to let the every elements to be lower case
	}
}

/**
 * Intent : get the file path from the fileName
 * pre : none
 * post : store the file path
 * \param fileName
 */
void Form::SetFileName(string fileName){
	filePath = fileName; // store the file path from the fileName
}

/**
 * Intent : load the file and compare the word if it is valid
 * pre : none
 * post : store the valid word to the answer vector
 */
void Form::Load_CompareWord() {
	ifstream fileInput(filePath); // open the file and read it

	// use a for loop to get the every line test case to case if it is a valid composed word until eof
	for (string test; fileInput >> test;) {
		bool isValid = true; // check if the word composed is valid
		int alphabet[26]{ 0 }; // use a array to store the amount of every components

		// use a for loop to test every index of the test case 
		for (auto& index : test) {
			alphabet[index - 'a'] = count(test.begin(), test.end(), index); // compute the amounts of every elements of the test string
			// if there has any amounts of the input word is less than the test case, then it is invalid
			if (alphabet[index - 'a'] > count(targetWord.begin(), targetWord.end(), index)) { 
				isValid = false; // modify the state to invalid
			}
		}
		
		// if the word composed is valid then push this test case to the answer vector
		if (isValid == true) {
			answer.push_back(test); // use push_back function to push back to test case to the answer vector
		}
	}

	fileInput.close(); // close the file
}

/**
 * Intent : print every valid composed word from the answer vector
 * pre : none
 * post : print all answer
 */
void Form::PrintFoundWords(){
	// use a for loop to print every answer from the answer vector
	for (const auto& i : answer) {
		cout << i << '\n'; // print every answer
	}
}
