/*****************************************************************//**
 * file : Diary.cpp
 * Author : ³¯«Û¾§ 
 * Create date : May 3, 2023
 * Last update : May 3, 2023
 * Description : Diary.cpp
 *********************************************************************/
#include "Diary.h"

// Initial the date and timeLine
string Diary::date;
vector<string> Diary::timeLine;

/**
 * Intent : A function to set the new day
 * pre : none
 * post : add the new time to the timeLine
 * \param day
 */
void Diary::NewDay(const string& day)
{
	// Modify the date to the current day and push the date to the timeLine
	Diary::date = day;
	Diary::timeLine.push_back(date);
}

/**
 * Intent : A constructor the record the creature grow diary
 * pre : none
 * post : create a diary class object
 * \param creatureName
 */
Diary::Diary(string creatureName)
{
	// Initial the basic property
	this->name = creatureName;
	this->birthDay = Diary::date;
	// Initial the evenet to the size which is 100
	this->events.resize(100, vector<string>(1, ""));
}

/**
 * Intent : Write the log
 * pre : none
 * post : Write the information to the log diary
 * \param parts
 * \param delta
 * \param preVal
 * \param nextVal
 */
void Diary::writeLog(const string& parts, const string& delta, const int& preVal, const int& nextVal)
{
	// Initial the string stream ss to store the change information
	stringstream ss;
	ss << this->name << "'s " << parts << ' ' << delta;
	ss << " (" << preVal << " -> " << nextVal << ").\n";

	// If the events is empty then clear that
	if (this->events[timeLine.size() - 1][0] == "") {
		this->events[timeLine.size() - 1].clear();
	}

	// Push the events information to the diary
	this->events[timeLine.size() - 1].push_back(ss.str());
}

/**
 * Intent : Print the log
 * pre : none
 * post : Print the whole log
 */
void Diary::printLog()
{
	// Print the title of the diary
	cout << this->name + "'s log:\n";
	// Run from the bithday to the time line's end 
	for (int i = this->birthDayIndex; i < timeLine.size(); i++)
	{
		cout << "Day " << timeLine[i] << '\n'; // Print the Date from the timeLine
		// If the events is not empty then print the events
		if (events[i][0] != "") {
			for (const auto& str : events[i]) {
				cout << str; // print the each of events
			}
		}	
	}
}

/**
 * Intent : Print the status of the diary
 * pre : none
 * post : print the status
 */
void Diary::printStatus()
{
	// Print the title of the status
	cout << this->name << "'s status:\n";
	// Print the status of the diary
	for (const auto& pair : this->information)
	{
		if (pair.second != 0) // If the value is 0 then do not print the information
			cout << pair.first << " * " << pair.second << '\n'; // print the status if the each parts
	}
}
