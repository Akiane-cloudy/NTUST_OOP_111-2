#include "PublicSchool.h"

/**
 * Intent : A constructor of the Public school class
 * pre : The base class School must be include
 * post : 
 * \param name
 * \param amount
 */
PublicSchool::PublicSchool(const string& name, const int& amount) : School(name, amount)
{
}

/**
 * Intent : The function that drop out student of the current school
 * pre : 
 * post : 
 * \param amount
 */
void PublicSchool::dropouts(const float& amount)
{
	// if the amount is larger than 0 and is less than the student amounts, drop out the students
	if (amount > 0 && amount <= this->studentAmount) {
		this->studentAmount -= (int)amount;

		// if the amount is larger than 100 then let the student of the next years decreased
		if ((int)amount > 100) {
			this->studentAmountNextYear -= ((int)studentAmountNextYear * 0.05);
		}
	}
}

/**
 * Intent : Growth the next year student amount 
 * pre : 
 * post : 
 */
void PublicSchool::apply_growth()
{
	// apply the next student amount be the growing rate times the student amounts next year
	this->studentAmountNextYear += growing_rate * studentAmountNextYear;
}
