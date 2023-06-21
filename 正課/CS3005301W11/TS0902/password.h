/*****************************************************************//**
 * file : password.h
 * Author : ³¯«Û¾§ 
 * Create date : May 4, 2023
 * Last update : May 4, 2023
 * Description : password.h
 *********************************************************************/
#pragma once
#include <iostream>

// Declare a namespace Authenticate and it contain the function inputPassword and getPassword
namespace Authenticate
{
	void inputPassword(); // A function to input the password
	std::string getPassword(); // A function to get the password
}

// A unname namespace contain a isValid function to check if the input is valid
namespace
{
	bool isValid(); // Check if the input is valid
}