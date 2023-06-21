/*****************************************************************//**
 * file : School.cpp
 * Author : ³¯«Û¾§ 
 * Create date : May 24, 2023
 * Last update : May 24, 2023
 * Description : School.cpp
 *********************************************************************/
#include "School.h"

/**
 * Intent : A constructor to initial the properties
 * pre : 
 * post : 
 * \param name
 * \param amount
 */
School::School(const string& name, const int& amount)
{
	// set the school name and the amount of school and next year amount
	this->name = name;
	this->studentAmount = this->studentAmountNextYear = amount;
}

/**
 * Intent : admission the student from school
 * pre : 
 * post : 
 * \param amount
 */
void School::admissions(const float& amount)
{
	// if the amount is valid then admission it
	if (amount > 0) this->studentAmount += (int)amount;
}

/**
 * Intent : drop out the student from the school
 * pre : 
 * post : 
 * \param amount
 */
void School::dropouts(const float& amount)
{
	// if the amount is valid then drop the student
	if (amount > 0 && amount <= studentAmount) this->studentAmount -= (int)amount;
}

/**
 * Intent : transfer the student to other school 
 * pre : 
 * post : 
 * \param amount
 * \param toSchool
 */
void School::transfer(const float& amount, School& toSchool)
{
	// if the amount is valid then trans the stdents
	if (amount > 0 && amount < this->studentAmount) {
		// origin school is drop
		this->dropouts(amount);
		// other school is admission
		toSchool.admissions(amount);
	}
}

/**
 * Intent : overloading the operator<< to print the information of a school
 * pre : 
 * post : 
 * \param out
 * \param school
 * \return 
 */
ostream& operator<<(ostream& out, const School& school)
{
	// print the name, student amounts, next year amount of student
	out << school.name << '\t' << school.studentAmount << '\t' << school.studentAmountNextYear;
	return out; // return the output stream
}
