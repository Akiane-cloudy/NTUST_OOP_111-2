/*****************************************************************//**
 * file : BankAccount.cpp
 * Author : ³¯«Û¾§ 
 * Create date : March 28, 2023
 * Last update : March 28, 2023
 * Description : Create a BankAccount class
 *********************************************************************/
#include "BankAccount.h";

int BankAccount::total(0); // initial the total to be 0

/**
 * Intent : initial the balance to be 0
 * pre : no any parameter
 * post : modify the balance to be 0
 */
BankAccount::BankAccount()
{
	this->balance = 0; // let balance be 0
}

/**
 * Intent : initial the balance to be input value
 * pre : need the parameter input
 * post : modify the balance to be the input value, and update the total value
 * \param input
 */
BankAccount::BankAccount(int input)
{
	this->balance = input; // let balance to be input value
	total += this->balance; // update the current total value
}

/**
 * Intent : wihtdraw the money from current balance 
 * pre : need a output parameter
 * post : modify the balance to minus the output value, and update the total value
 * \param output
 */
void BankAccount::withdraw(int output)
{
	this->balance -= output; // let balance to minus the output value
	total -= output; // update the current total value
}

/**
 * Intent : save money into the current account
 * pre : need a input parameter
 * post : let current account's balance plus the input value, and update the total value
 * \param input
 */
void BankAccount::save(int input)
{
	this->balance += input; // let balance to plus the input value
	total += input; // update the total value
}

/**
 * Intent : get the current account balance 
 * pre : none
 * post : return the current balance value
 * \return 
 */
int BankAccount::getBalance()
{
	return this->balance; // return the current balance value
}

/**
 * Intent : get the current total value
 * pre : none
 * post : return the value is the total
 * \return 
 */
int BankAccount::getAllMoneyInBank()
{
	return total; // return the current total value
}
