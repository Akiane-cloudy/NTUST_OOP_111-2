/*****************************************************************//**
 * file : TheTranslationMachine.cpp
 * Author : ³¯«Û¾§ 
 * Create date : May 5, 2023
 * Last update : May 5, 2023
 * Description : TheTranslationMachine.cpp
 *********************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<char, vector<char>> translateTable; // A table witch is used to store the diectionary
map<char, bool> check; // A map to store the character which is been checked

void translation(string&, const string&); // A function to translate the each words
void trans(char&, const char&, char&); // A function to translate the each character from the word
bool isTransable(string, const string); // Check if the word is transable


int main()
{
	// Input m and n; m represented the amounts of dictionary and the n represented the amounts of each words pair 
	for (int m, n; cin >> m >> n;)
	{
		if (m == 0 && n == 0) break; // If the m and n are 0 then break the program

		translateTable.clear(); // Clear the table

		// input the dictionary ch1 -> ch2
		while (m--) {
			char ch1, ch2;
			cin >> ch1 >> ch2; // input the each pair charactre

			translateTable[ch1].push_back(ch2); // store the pair of dictionary into the table
		}

		// Check if the origin words can tranlate to target words
		while (n--) {
			string origin, target;
			cin >> origin >> target; // Input the words

			// If the words is transable then print yes, otherwise is no
			if (isTransable(origin, target)) {
				cout << "yes\n";
			}
			else {
				cout << "no\n";
			}
		}
	}
}

/**
 * Intent : A function to check if the words is transable
 * pre : the words must to be inputted
 * post : return true or false
 * \param origin
 * \param target
 * \return 
 */
bool isTransable(string origin, const string target)
{
	// If two words have difference size then return false
	if (origin.size() != target.size()) return false;

	// Try to translate the origin to target
	translation(origin, target);

	// Return if the origin words is transable to be the target word
	return (origin == target);
}

/**
 * Intent : A function to translate the each words
 * pre : The two words has the same size
 * post : translate the origin word
 * \param origin
 * \param target
 */
void translation(string& origin, const string& target)
{
	// Run the each character of the origin and check if it can translate it to be target
	for (int i = 0; i < origin.size(); i++) {
		for (int j = 0; j < translateTable[origin[i]].size(); j++) {
			// Run the each character and try to translate that
			trans(origin[i], target[i], translateTable[origin[i]][j]);
			// Clear the check table
			check.clear();
		}
	}
}

/**
 * Intent : A function to try to translate the character
 * pre : None
 * post : trans the origin character to be target if it can
 * \param origin
 * \param target
 * \param current
 */
void trans(char& origin, const char& target, char& current)
{
	// If the origin is equal to target or this character is been checked then return
	if (origin == target || check[current] != false) {
		return;
	}

	// Set the current character to be checked 
	check[current] = true;

	// If the current is equal to target then translate the origin to be the target
	if (current == target) {
		origin = current;
		return;
	}

	// If the current character is not in the dictionary then return
	if (translateTable.find(current) == end(translateTable)) {
		return;
	}
		
	// Translate the current character to the another character if it is in the dictionary
	for (int i = 0; i < translateTable[current].size(); i++) {
		trans(origin, target, translateTable[current][i]);
	}
}
