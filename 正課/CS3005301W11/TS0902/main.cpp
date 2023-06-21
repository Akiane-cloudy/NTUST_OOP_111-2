/*****************************************************************//**
 * file : main.cpp
 * Author : ³¯«Û¾§ 
 * Create date : May 4, 2023
 * Last update : May 4, 2023
 * Description : Namespace
 *********************************************************************/
#include "user.h"
#include "password.h"
using namespace Authenticate; 

int main()
{
	// Input the user name and the password
	inputUserName();
	inputPassword();

	// Print the message of the username and the password
	std::cout << "Your username is " << getUserName()
			  <<" and your password is: " << getPassword() << std::endl;

	return 0;
}
