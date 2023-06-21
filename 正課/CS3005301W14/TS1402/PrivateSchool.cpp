#include "PrivateSchool.h"

/**
 * Intent : The Private school constructor 
 * pre : The base class school must be init
 * post : 
 * \param name
 * \param amount
 */
PrivateSchool::PrivateSchool(const string& name, const int& amount) : School(name, amount)
{
}

/**
 * Intent : Drop outs the student with the parameter amount
 * pre : none
 * post : none
 * \param amount
 */
void PrivateSchool::dropouts(const float& amount)
{
	// If the amont is larger than 0 and the amount is less than the current student amount
	if (amount > 0 && amount <= this->studentAmount) {
		// let student amount minus the amount parameter
		this->studentAmount -= (int)amount;
		// if the amount is larger than 100 then the student amount next year will minus 100
		if ((int)amount > 100) this->studentAmountNextYear -= 100;
	}
}
