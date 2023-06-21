/*****************************************************************//**
 * file : PrivateSchool.h
 * Author : ³¯«Û¾§ 
 * Create date : May 24, 2023
 * Last update : May 24, 2023
 * Description : PrivateSchool.h
 *********************************************************************/
#pragma once
#include "School.h"

class PrivateSchool : public School
{
public:
	// A constructor
	PrivateSchool(const string& name, const int& amount);
	// dropout the student from school 
	void dropouts(const float& amount) override;
};

