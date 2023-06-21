/*****************************************************************//**
 * file : Account.h
 * Author : 陳彥儒
 * Create date : May 31, 2023
 * Last update : May 31, 2023
 * Description : ATM
 *********************************************************************/
#pragma once
#include "InsufficientFunds.h"
#include "NegativeDeposit.h"

 // Declare the account class to store the balance
class Account
{
private:
	double balance; // the balance property

public:
	// The constructor with no deposit
	Account();
	// The constructor with initialDeposit
	Account(double initialDeposit);

	double getBalance(); // The function to get the balance from the account
	double deposit(double amount); // The function to deposit the money to the account
	double withdraw(double amount); // The function to withdraw the money to the account
};

