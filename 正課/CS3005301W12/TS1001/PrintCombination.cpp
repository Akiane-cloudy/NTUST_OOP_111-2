/*****************************************************************//**
 * file : PrintCombination.cpp
 * Author : ³¯«Û¾§ 
 * Create date : May 10, 2023
 * Last update : May 10, 2023
 * Description : PrintCombination
 *********************************************************************/
#include "PrintCombination.h"
 
vector<int> list; // A list to store the whole number list
vector<int> res; // A vector to store the result

/**
 * Intent : The main function to store the number list 
 * pre : none
 * post : do the recursion
 * \param array
 * \param range
 * \param choice
 */
void PrintCombination(int* array, int range, int choice)
{
	// store the number list
	for (int i = 0; i < range; i++) {
		list.push_back(array[i]);
	}
	findCombination(0, choice); // do the recursion to find the all combination
}

/**
 * Intent : Print the combination
 * pre : none
 * post : print the result
 */
void printResult()
{
	// Print the whole answer
	for (int i = 0; i < res.size() - 1; i++) {
		cout << res[i] << ' ';
	}
	cout << res[res.size() - 1] << '\n'; // Only make a new line a the last elements
}

/**
 * Intent : Find the all combiantion
 * pre : none
 * post : find the all combination
 * \param from
 * \param choice
 */
void findCombination(int from, int choice)
{
	// If the choice is 0 then print the answer
	if (choice == 0) {
		printResult();
		return;
	}
	
	// ex: C[5;4] = 1 + C[4;3](recursive)
	for (int i = from; i <= list.size() - choice; i++) {
		res.push_back(list[i]); // store the elements
		findCombination(i + 1, choice - 1); // find the sub array of the combination
		res.pop_back(); // pop the last elements
	}
}
