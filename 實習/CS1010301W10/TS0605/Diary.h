/*****************************************************************//**
 * file : Diary.h
 * Author : ³¯«Û¾§ 
 * Create date : May 3, 2023
 * Last update : May 3, 2023
 * Description : Diary.h
 *********************************************************************/
#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

// Declare the Diary class
class Diary 
{
private:
	// Declare the basic property 
	string name;
	string birthDay;
	int birthDayIndex; 
	map<string, int> information; // A map to store the information of the amounts of the parts 
	vector<vector<string>> events; // A vector to store the events of each time of timeLine

public:
	static string date; // A static value about the current date
	static vector<string> timeLine; // A vector to store each times
	static void NewDay(const string& day); // A function to change the current date

public:
	Diary(string = ""); // A constructor to create the Diary
	void writeLog(const string&, const string&, const int& preVal, const int& nextVal); // A function to write the log
	void printLog(); // A function to print the log
	void printStatus(); // A function to print the status
	friend class Creature; // Claim the Creature class is my friend :)
};
