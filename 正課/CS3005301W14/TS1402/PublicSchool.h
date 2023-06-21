/*****************************************************************//**
 * file : PublicSchool.h
 * Author : ³¯«Û¾§ 
 * Create date : May 24, 2023
 * Last update : May 24, 2023
 * Description : PublicSchool.h
 *********************************************************************/
#pragma once
#include "School.h"

class PublicSchool : public School
{
private:
	// Define the growing rate is 0.05
	const float growing_rate = 0.05f;

public:
	// A contructor
	PublicSchool(const string& name, const int& amount);
	// Drop out the student from school
	void dropouts(const float& amount) override;
	// growth the student amount of next year
	void apply_growth();
};

