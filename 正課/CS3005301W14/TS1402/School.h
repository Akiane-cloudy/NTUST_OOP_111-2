/*****************************************************************//**
 * file : School.h
 * Author : ³¯«Û¾§ 
 * Create date : May 24, 2023
 * Last update : May 24, 2023
 * Description : School.h
 *********************************************************************/
#pragma once
#include <iostream>
using namespace std;

// A school class
class School
{
protected:
	// the properties
	string name;
	int studentAmount, studentAmountNextYear;

public:
	// A constructor
	School(const string& name, const int& amount);
	// Admission student
	void admissions(const float& amount);
	// dropouts the student
	virtual void dropouts(const float& amount);
	// transfer the student to other school
	void transfer(const float& amount, School& toSchool);
	// overloading operator<< to print the properties
	friend ostream& operator<<(ostream& out, const School& school);
};

// Include the private school and public school class
#include "PrivateSchool.h"
#include "PublicSchool.h"
