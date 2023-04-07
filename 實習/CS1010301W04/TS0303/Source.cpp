/*****************************************************************//**
 * file : Source.cpp
 * Author : ³¯«Û¾§ 
 * Create date : March 16, 2023
 * Last update : March 16, 2023
 * Description : Input_Output
 *********************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string setDigit(string, int); // Function to set the decimal part
string setResult(string, int, char); // Function to set the symbol of C and complete the result

int main()
{
	string target; // the target we want to modify
	int totalLength, digitLength; // the total length and digit length
	char symbolC; // the symbol need to insert in front of target

	while (cin >> target >> totalLength >> digitLength >> symbolC)
	{
		target = setDigit(target, digitLength);
		target = setResult(target, totalLength, symbolC);

		cout << target << endl;
	}

	return 0;
}

/**
 * Intent : this function is mainly to fix the decimal part
 * pre : digitLength > 0
 * post : The function will return a result string
 * \param targetTemp
 * \param digitLength
 * \return result string
 */
string setDigit(string targetTemp, int digitLength)
{
	// if target didn't have decimal point, then let it get one 
	if (count(targetTemp.begin(), targetTemp.end(), '.') == 0)
	{
		targetTemp = targetTemp + '.';
	}

	// subMain is the part before decimal point
	// and subDigit is the part after decimal point
	string subMain = targetTemp.substr(0, targetTemp.find('.'));
	string subDigit = targetTemp.substr(targetTemp.find('.'));

	//if subDigit's length is smaller than the digit length, then let it get '0' back
	// until the length of subDigit is longer than digit length
	while (subDigit.size() <= digitLength)
	{
		subDigit = subDigit + '0';
	}

	string result;
	if (digitLength == 0)
	{
		// if digit length is equal to 0, then don't return the decimal point 
		result = subMain; 
	}
	else
	{
		// return the result which is combine from main and its decimal part
		result = subMain + '.' + subDigit.substr(1, digitLength);
	}
	 
	return result;
}

/**
 * Intent : Insert the symbol C in front of the target until the whole length is equal to total length
 * pre : totalLength > 0
 * post : The function will return a targetTemp string
 * \param targetTemp
 * \param totalLength
 * \param symbolC
 * \return targetTemp string
 */
string setResult(string targetTemp, int totalLength, char symbolC)
{
	while (targetTemp.size() < totalLength)
	{
		targetTemp = symbolC + targetTemp;
	}

	return targetTemp;
}