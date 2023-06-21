/*****************************************************************//**
 * file : main.cpp
 * Author : 陳彥儒
 * Create date : June 7, 2023
 * Last update : June 7, 2023
 * Description : Library Database
 *********************************************************************/
#include "CommandController.h"

int main() {
	// read the input command and do the command 
	for (string command; getline(cin, command); ) {
		if (!command.size()) continue; // if the command is empty then do not do anything
		try {
			// try to execute the input command
			CommandController::commandInput(command);
		}
		catch (const char* errorMessage) {
			// if any error message are catched the print the error message
			cout << errorMessage;
		}
	}
}
