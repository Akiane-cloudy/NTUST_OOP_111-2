/*****************************************************************//**
 * file : main.cpp
 * Author : ³¯«Û¾§ 
 * Create date : April 22, 2023
 * Last update : April 22, 2023
 * Description : Meomory_Simulator
 *********************************************************************/
#include "Memory.h"

int main() {
	int memorySize, cases; // declare the memorySize and how much cases is

	while (cin >> memorySize) { // get the input data till the data is eof
		Memory memory(memorySize); // declare the memory object
		
		cin >> cases; // input the case amounts
		cin.ignore(1); // ignore the '\n'

		while (cases--) { // run the case
			string input; // declare a input string which is the input command
			getline(cin, input); // get the whole line from the input

			memory.getCommand(input); // run the command
		}
	}
}
