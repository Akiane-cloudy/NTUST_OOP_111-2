/*****************************************************************//**
 * file : Account.cpp
 * Author : 陳彥儒
 * Create date : May 31, 2023
 * Last update : May 31, 2023
 * Description : ATM
 *********************************************************************/
#include "Account.h"

 /**
  * Intent :A constructor with no parameter
  * pre : none
  * post : initial the balance value
  */
Account::Account() : balance(0) {}

/**
  * Intent :A constructor with initialDeposit
  * pre : none
  * post : initial the balance value
  */
Account::Account(double initialDeposit) : balance(initialDeposit) {}

/**
 * Intent : Get the balance from the account
 * pre : none
 * post : get the balance of the account
 * \return
 */
double Account::getBalance()
{
	// return the balance value
	return balance;
}

/**
 * Intent :	Deposit the money with the amount parameter
 * pre : none
 * post : Deposit the amount
 * \param amount
 * \return
 */
double Account::deposit(double amount)
{
	// if the amount is a non-possitive number then throw the error exception class
	if (amount > 0) balance += amount;
	else throw NegativeDeposit();

	return balance;
}

/**
 * Intent :	Withdraw the money of the amount of the parameter
 * pre : none
 * post : Withdraw the amount of money
 * \param amount
 * \return
 */
double Account::withdraw(double amount)
{
	// if the amount is a non-possitive numberor or larger then the balance value 
	// then throw the error exception class
	if ((amount > balance) || (amount < 0)) throw InsufficientFunds();
	else balance -= amount;

	return balance;
}
