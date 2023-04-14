/*****************************************************************//**
 * file : Source.cpp
 * Author : ³¯«Û¾§ 
 * Create date : April 11, 2023
 * Last update : April 12, 2023
 * Description : Seven_segment_display implement
 *********************************************************************/
#include <iostream>
#include <string>
#include <vector> // create a table to store 0 ~ 9
using namespace std;

// declare three const string vector as a table to store the 0~9 
const vector<string> row1{ " _ ", "   ", " _ ", " _ ", "   ", " _ ", " _ ", " _ ", " _ ", " _ " };
const vector<string> row2{ "| |", "  |", " _|", " _|", "|_|", "|_ ", "|_ ", "  |", "|_|", "|_|" };
const vector<string> row3{ "|_|", "  |", "|_ ", " _|", "  |", " _|", "|_|", "  |", "|_|", " _|" };

int main()
{
	string input; // declare a input string 
	while (getline(cin, input)) // get the whole string until eof
	{
		// initial three strings represents three row of number
		string outputRow1 = "";
		string outputRow2 = "";
		string outputRow3 = "";

		for (auto& i : input) // use for loop to run every elements of input
		{
			if (i >= '0' && i <= '9') // check if the character is valid or not
			{
				// if the character is valid then push it to the every output row string 
				outputRow1 += row1[i - '0']; 
				outputRow2 += row2[i - '0'];
				outputRow3 += row3[i - '0'];
			}
		}

		// print out all of the output row to the screen 
		cout << outputRow1 << '\n' << outputRow2 << '\n' << outputRow3 << endl;
	}
}
