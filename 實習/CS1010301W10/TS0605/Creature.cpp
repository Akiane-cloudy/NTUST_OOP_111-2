/*****************************************************************//**
 * file : Creature.cpp
 * Author : ³¯«Û¾§ 
 * Create date : May 3, 2023
 * Last update : May 3, 2023
 * Description : Creature.cpp
 *********************************************************************/
#include "Creature.h"

/**
 * Intent : A constructor to create a creature
 * pre : none
 * post : create a creature
 * \param name
 */
Creature::Creature(const string& name)
{
	// Initial the basic property
	this->name = name;
	this->myLog.name = name;
	this->myLog.birthDay = Diary::date;
	this->myLog.birthDayIndex = Diary::timeLine.size() - 1;
}

/**
 * Intent : A constructor to copy the property from the base to new creature
 * pre : none
 * post : create a creature
 * \param name
 * \param base
 */
Creature::Creature(const string& name, const Creature& base)
{
	// Initial the basic property
	this->name = name;
	this->myLog.name = name;
	this->myLog.birthDay = Diary::date;
	this->myLog.birthDayIndex = Diary::timeLine.size() - 1;
	this->myLog.information = base.myLog.information;
}

/**
 * Intent : Overloading the operator[] to return this creature
 * pre : none
 * post : return this creature and store the input part
 * \param part
 * \return 
 */
Creature& Creature::operator[](const string& part)
{
	// store the input part and return the current creature
	inputPart = part;
	return *this;
}

/**
 * Intent : Overloading the operator= to return this creature
 * pre : None
 * post : Modify the value of the creture property and write the log
 * \param value
 */
void Creature::operator=(const int value)
{
	// set the prev value and the innformation
	int preValue = myLog.information[inputPart];
	myLog.information[inputPart] = (value < 0) ? 0 : value;

	// if there have no change, return
	if (preValue == myLog.information[inputPart]) return;
	
	// write the log
	this->writeLog(inputPart, preValue, myLog.information[inputPart]);
}

/**
 * Intent : Overloading the operator+= 
 * pre : None 
 * post : Modify the value
 * \param value
 */
void Creature::operator+=(const int value)
{
	// Store the origin value and set the information
	int preValue = myLog.information[inputPart];
	myLog.information[inputPart] = (myLog.information[inputPart] + value < 0) ? 0 : myLog.information[inputPart] + value;

	//  if there have no change, return
	if (preValue == myLog.information[inputPart]) return;

	// write the log
	this->writeLog(inputPart, preValue, myLog.information[inputPart]);
}

/**
 * Intent : Overloading the operator-= 
 * pre : None 
 * post : Modify the value
 * \param value
 */
void Creature::operator-=(const int value)
{
	// Store the origin value and set the information
	int preValue = myLog.information[inputPart];
	myLog.information[inputPart] = (myLog.information[inputPart] - value < 0) ? 0 : myLog.information[inputPart] - value;

	//  if there have no change, return
	if (preValue == myLog.information[inputPart]) return;

	// write the log
	this->writeLog(inputPart, preValue, myLog.information[inputPart]);
}

/**
 * Intent : Print the log of creature
 * pre : none
 * post : print the log
 */
void Creature::PrintLog()
{
	// Print the log of creature
	this->myLog.printLog();
	cout << '\n';
}

/**
 * Intent : Print the status of the creature
 * pre : none
 * post : print the status of the creature
 */
void Creature::PrintStatus()
{
	// print the status
	this->myLog.printStatus();
	cout << '\n';
}

/**
 * Intent : Write the log
 * pre : none
 * post : adding information to the diary
 * \param part
 * \param preValue
 * \param nextValue
 */
void Creature::writeLog(const string& part, const int& preValue, const int& nextValue)
{
	// Set the mod to the delta val
	string mode = (preValue == 0 && nextValue > 0) ? "appeared"
		: ((preValue > nextValue) ? "decreased" : "increased");

	// Write the log
	this->myLog.writeLog(part, mode, preValue, nextValue);
}
