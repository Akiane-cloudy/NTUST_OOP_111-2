/*****************************************************************//**
 * file : password.cpp
 * Author : ³¯«Û¾§ 
 * Create date : May 4, 2023
 * Last update : May 4, 2023
 * Description : password.cpp
 *********************************************************************/
#include "password.h"

// Implement the namespace Authenticate
namespace Authenticate
{
	std::string password; // Declare a string variable

	/**
	 * Intent : A function to let user input their password
	 * pre : Need a string variable password 
	 * post : input the password
	 */
	void Authenticate::inputPassword()
	{
		do
		{
			// Print the message
			std::cout << "Enter your password (at least 8 characters "
					  << "and at least one non-letter)" << std::endl;
			// Input the password
			std::cin >> password; 
		} while (!isValid()); // Check if the password is valid
	}
	
	/**
	 * Intent : Get the password
	 * pre : The password must be inputted
	 * post : Return the password
	 * \return 
	 */
	std::string getPassword()
	{
		return password; // Return the password
	}
}

// A unname namespace is used in this source code and contain a isValid function
namespace
{
	/**
	 * Intent : Check if the input is valid
	 * pre : None
	 * post : Return if the input is valid
	 * \return 
	 */
	bool isValid()
	{
		// If the size if the password is less than 8, return false
		if (Authenticate::password.size() < 8) return false;

		// If there has least one non-letter character, return true
		for (const char& c : Authenticate::password) {
			if (!isalpha(c)) return true;
		}

		return false; // Else condition return false
	}
}



