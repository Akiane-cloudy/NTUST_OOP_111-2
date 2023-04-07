/*****************************************************************//**
 * file : Month.cpp
 * Author : ³¯«Û¾§ 
 * Create date : March 28, 2023
 * Last update : March 28, 2023
 * Description : Month.cpp
 *********************************************************************/
#include "Month.h"
#include <map> 
#include <iostream>
#include <string>
using namespace std;

// use a map to store month abbreviation and its month value
map <string, int> monthMap{ {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6},{"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}};
// declare a string array to store Jan ~ Dec abbreviation
string abbreviation[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

/**
 * Intent : define a constuctor to initial the month to be 1
 * pre : none
 * post : let month's value be 1
 */
Month::Month()
{
	this->month = 1; // month become 1
}

/**
 * Intent : define a constuctor to initial the month to be the abbreviation parameter
 * pre : none
 * post : modify the month
 * \param first
 * \param second
 * \param third
 */
Month::Month(char first, char second, char third)
{
	string monthStr = ""; // declare a monthStr to store the parameter
	monthStr += first; // push back the char 
	monthStr = monthStr + second + third; // push back all char

	// if the monthStr can't find in the monthMap, then the .find() function will return an iterator and is equal to the iterator of the end()
	// and if it can't find in the monthMap then modify month value to 1
	this->month = (monthMap.find(monthStr) != monthMap.end()) ? monthMap[monthStr] : 1;
}

/**
 * Intent : defined a constructor to modify the month value to be the monthInt parameter
 * pre : the monthInt value must >= 1 or <= 12 
 * post : modify the month value
 * \param monthInt
 */
Month::Month(int monthInt)
{
	// if the monthInt is >= 1 and <= 12 then modify the month to to be monthInt value
	// or modify it to be 1
	this->month = (monthInt >= 1 && monthInt <= 12) ? monthInt : 1;
}

/**
 * Intent : a destructor
 * pre : none
 * post : none
 */
Month::~Month()
{
}

/**
 * Intent : input a number then modify the month to be the input number
 * pre : the input value must valid ( >=1 and <= 12)
 * post : modify the month value to be the input number or 1
 */
void Month::inputInt()
{
	int inputMonth; // declare a inputMonth varialbe
	cin >> inputMonth; // get the inputMonth value
	
	// if the inputMonth isn't valid then modify it to 1
	// or modify it to the inputMonth value
	this->month = (inputMonth >= 1 && inputMonth <= 12) ? inputMonth : 1;
}

/**
 * Intent : get 3 characters and modify the current month
 * pre : need three letters
 * post : modify the current month
 */
void Month::inputStr()
{
	char letter1, letter2, letter3; // declare three letters to store the input character
	cin >> letter1 >> letter2 >> letter3; // input three letters
	Month temp(letter1, letter2, letter3); // create a temp Month class and its value is the input 

	this->month = temp.month; // copy the temp month to the current month
}

/**
 * Intent : output the month value
 * pre : none
 * post : output the month value
 */
void Month::outputInt()
{
	cout << this->month; // print out the month value
}

/**
 * Intent : output the abbrevition of current month
 * pre : none
 * post : print out the abbreviation of the current month
 */
void Month::outputStr()
{
	cout << abbreviation[(this->month) - 1]; // output the abbreviation of the current month
}

/**
 * Intent : return the next month of the current month
 * pre : none
 * post : return a Month class which property month value is the next month of current month 
 * \return 
 */
Month Month::nextMonth()
{
	Month temp((this->month) % 12 + 1); // create a temp Month class and its month value is next month of current month
	return temp; // return the temp Month class
}
