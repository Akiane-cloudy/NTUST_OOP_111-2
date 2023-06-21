/*****************************************************************//**
 * file : user.cpp
 * Author : ³¯«Û¾§ 
 * Create date : May 4, 2023
 * Last update : May 4, 2023
 * Description : user.cpp
 *********************************************************************/
#include "user.h"

 // Declare a namespace Authenticate and it contain the function inputUserName and getUserName
namespace Authenticate
{
	std::string userName; // Declare a userName string variable to store the userName that from the input data

	/**
	 * Intent : A function to input the user's name
	 * pre : The userName must be declared
	 * post : Input the user's name
	 */
	void inputUserName()
	{
		do
		{
			// Print the message
			std::cout << "Enter your username (8 letters only)" << std::endl;
			// Input the user's name
			std::cin >> userName;
		} while (!isValid()); // Check if the input is valid
	}
	
	/**
	 * Intent : A function to get the user's name
	 * pre : The user's name most to be inputted
	 * post : Return the userName
	 * \return 
	 */
	std::string getUserName()
	{
		// Return the userName
		return userName;
	}

}

// A unname namespace contain a isValid function to check if the input is valid
namespace
{
	/**
	 * Intent : A function to check if the input is valid
	 * pre : The userName must be inputted
	 * post : Return if the input data is valid
	 * \return 
	 */
	bool isValid() {
		// If the input userName's size is not equal to 8, return false
		if (Authenticate::userName.size() != 8) return false;

		// If there has any non-letter character, return false
		for (const char& c : Authenticate::userName) {
			if (!isalpha(c)) return false;
		}

		// Else condition, return true
		return true;
	}
}
