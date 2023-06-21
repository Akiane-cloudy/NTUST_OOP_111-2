/*****************************************************************//**
 * file : user.h
 * Author : ³¯«Û¾§ 
 * Create date : May 4, 2023
 * Last update : May 4, 2023
 * Description : user.h
 *********************************************************************/
#pragma once
#include <iostream>

 // Declare a namespace Authenticate and it contain the function inputUserName and getUserName
namespace Authenticate
{
	void inputUserName(); // A function to input the user's name
	std::string getUserName(); // A function to get the user's name
}

// A unname namespace contain a isValid function to check if the input is valid
namespace
{
	bool isValid(); // A function to check if the input is valid
}