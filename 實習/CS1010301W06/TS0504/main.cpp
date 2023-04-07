/*****************************************************************//**
 * file : main.cpp
 * Author : ³¯«Û¾§ 
 * Create date : March 30, 2023
 * Last update : March 30, 2023
 * Description : Sudoku Checker
 *********************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> sudoku; // declare a vector to store all input sudoku's elements

void initial(string); // function to initial the sudoku
bool isHorizontalValid(); // check if the all the rows of sudoku is valid
bool isVerticalValid(); // check if the all the columns of sudokju is valid
bool isSquareValid(); // check if the 9 * 9 square is valid

int main()
{
	char space; // declare a space variable to filte the '\n' of several input case
	string input; // every line of the input 

	while (getline(cin, input)) // get the input string from cin until eof
	{
		initial(input); // initial the input to the sudoku

		for (int i = 0; i < 8; i++) // run 9 times to get the every lines to intial to the sudoku
		{
			getline(cin, input); // get the input string
			initial(input); // intial it to sudoku
		}

		// check if the rows, columns, and all square of sudoku is valid
		// if any of these function return false then the sudoku is inconsistent
		if (isHorizontalValid() && isVerticalValid() && isSquareValid())
		{
			cout << "True" << endl; // if all the function return true then the sudoku is consistent then print out true
		}
		else
		{
			cout << "False" << endl; // if any of these function return false then the sudoku is inconsistent
		}

		sudoku.clear(); // clear the sudoku to prepare to store the next input case
		space = getchar(); // get the '\n' from input
	}
}

/**
 * Intent : initial the dusoku from the input data
 * pre : none
 * post : store the elements to the sudoku
 * \param temp
 */
void initial(string temp)
{
	string result = ""; // declare a string result 
	for (int i = 0; i <= 16; i += 2) // use for loop to filte the ','
	{
		result += temp[i]; // store the elements to the result string
	}

	sudoku.push_back(result); // push back the string to the sudoku
}

/**
 * Intent : check the all of rows is valid
 * pre : none
 * post : none
 * \return true or false
 */
bool isHorizontalValid()
{
	for (auto& row : sudoku) // use range for loop to run all of the rows elements
	{
		int sum = 0; // initial a sum to do summary of all columns's elements

		for (int i(0); i < 9; i++)
		{
			sum += row[i] - '0';// + every elements of every row of sudoku
		}

		if (sum != 45) // check if the sum is equal to 45
		{
			return false; // if the sum is not equal to 45 then return false
		}
	}

	return true; // otherwise return true
}

/**
 * Intent : check if all of columns is valid
 * pre : none
 * post : none
 * \return true or false
 */
bool isVerticalValid()
{
	for (int row = 0; row < 9; row++) // use range for loop to run the columns
	{
		int sum = 0; // initial a sum to do summary of all columns's elements

		for (int column = 0; column < 9; column++)
		{
			sum += sudoku[row][column] - '0'; // + every elements of sudoku 
		}

		if (sum != 45) // check if the sum is 45 or not
		{
			return false; // if the sum is not equal to 45 then return false
		}
	}

	return true; // otherwise return true
}

/**
 * Intent : check if the box of every 9 * 9 square box's elements is valid
 * pre : none
 * post : none
 * \return true or false
 */
bool isSquareValid()
{
	for (int i = 0; i < 3; i++) // the column of 3 * 3 system and its subsystem is also a 3 * 3 system
	{
		for (int j = 0; j < 3; j++) // the row of 3 * 3 system and its subsystem is also a 3 * 3 system
		{
			int sum = 0; // initial the sum 0 and it is use to summary the every 3 * 3 subsystem elements
			
			// the for loop represent the 3 * 3 subsystem 
			// k is the column of subsystem and l represent the row of this subsystem
			for (int k = 0 + i * 3; k < 3 + i * 3; k++) // the range of k is from i * 3 + 0 and until k is equal to 3 + i * 3 
			{
				for (int l = 0 + j * 3; l < 3 + j * 3; l++) // the range of l is from 0 + j * 3 until l is equal to 3 + j * 3
				{
					sum += sudoku[k][l] - '0'; // summary the every elements of sudoku of this subsystem
				}
			}

			if (sum != 45) // if any summary of any subsystem is not equal to 45 then return false
			{
				return false; // return false
			}
		}
	}

	return true; // otherwise, return true 
}
