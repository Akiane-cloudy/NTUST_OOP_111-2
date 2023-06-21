/*****************************************************************//**
 * file : Reversal.cpp
 * Author : ³¯«Û¾§ 
 * Create date : May 4, 2023
 * Last update : May 4, 2023
 * Description : Reversal
 *********************************************************************/
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<string> wordList; // Declare a string vector to store the word from input
	size_t maxSize = 0; // Initial the maxSize of each word is 0
	int maxIndex = -1; // Initial the maxIndex of the word which has longest size from the dictionary
	
	for (string input; cin >> input; ) {
		wordList.push_back(input); // Read the wordList from the input
	}
	
	// Run each word from the wordList and check if reverse it can find the another word
	for (const auto& str : wordList) {
		string temp = str; // Use temp to store the current check data
		reverse(begin(temp), end(temp)); // Reverse it

		// Use for loop to find the revese word from the dictionary
		for (const auto& strTemp : wordList) {
			// If the word is exeisted in the dictionary, then check its size 
			if (temp == strTemp) { 
				// If the size of the word is larger than the maxSize, then change the maxSize to the current word's
				if (maxSize < temp.size()) {
					maxSize = temp.size();
					maxIndex = find(begin(wordList), end(wordList), temp) - begin(wordList); // Record the index of the curren word
				}
			}
		}
	}

	// Reverse the answer
	reverse(begin(wordList[maxIndex]), end(wordList[maxIndex]));
	cout << wordList[maxIndex] << '\n'; // Print the answer from the wordList
}
