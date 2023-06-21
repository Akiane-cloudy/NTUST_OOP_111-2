/*****************************************************************//**
 * file : Creature.h
 * Author : ³¯«Û¾§ 
 * Create date : May 3, 2023
 * Last update : May 3, 2023
 * Description : Creature.h
 *********************************************************************/
#pragma once

#include "Diary.h"

// A Creature class
class Creature
{
private:
	// The basic property of a creature
	string name;
	Diary myLog;
	string inputPart;

public:
	Creature(const string& name); // A constuctor with its name
	Creature(const string& name, const Creature&); // A constuctor with its name and the information base
	Creature& operator[](const string&); // Overloading the operator to return the creature 
	void operator=(const int value); // Overloading the operator= to assign the value to the parts of the creature
	void operator+=(const int value); // Overloading the operator+= to adding the value to the parts of the creature
	void operator-=(const int value); // overloading the operator-= to minus the value of the parts of the creature
	void PrintLog(); // A function to print the log
	void PrintStatus(); // A function to print the status 
	void writeLog(const string&, const int&, const int&); // A function to write the log
};
