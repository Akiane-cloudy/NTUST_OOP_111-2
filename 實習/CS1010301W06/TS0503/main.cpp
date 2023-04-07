/*****************************************************************//**
 * file : main.cpp
 * Author : ³¯«Û¾§ 
 * Create date : March 30, 2023
 * Last update : March 30, 2023
 * Description : Student_Record struct implement
 *********************************************************************/
#include <iostream>
#include <vector> // store the every StRec struct
#include <string> 
using namespace std;

// define aa struct StRec and has three property firstname, lastname and phone number
typedef struct
{
	char firstName[25]; // define a first name as a first name to store the first name
	char lastName[30]; // define a last name as a last name to store the last name
	char phone[15]; // define phone as phone number to store the phone number
} StRec;

vector<StRec> information; // use a vector to store the student information

// Function list
bool operator==(StRec, StRec); // overload the operator == between two StRec struct
bool isCommandValid(string); // return is the command valid
bool isInputValid(string, string, string); // return is the input valid
bool isStudentExist(StRec); // check is the student exist
bool isInsertValid(StRec); // check is insert command works
StRec getInformation(string, string, string); // get the information of student
void deleteInformation(StRec); // delete the student information from the list
int findInformation(StRec); // find the indexc of the student
void printInformation(); // print all student of the list

int main()
{
	string command; // declare the command
	while (cin >> command) // input a command
	{
		// check if the input command is valid, if it is invalid then output "Input Error"
		if (isCommandValid(command) == false)
		{
			cout << "Input Error" << endl; // if the input is invalid then output "Input Error"
			continue; // continue the loop
		}
		else
		{
			// the option insert
			if (command == "insert")
			{
				string firstName, lastName, phone; // declare a first name, last name and phone string
				cin >> firstName >> lastName >> phone; // get the all string value

				// check is the input string is valid
				if (isInputValid(firstName, lastName, phone) == true)
				{
					//create a student and its first, last name and phone is the input
					StRec student = getInformation(firstName, lastName, phone);
					//if the insert is valid then insert the student to the list
					if (isInsertValid(student) == true)
					{
						information.push_back(student); // insert the student to the list of information
					}
					else
					{
						cout << "Insert Error" << endl; // the insert is invalid so print out a message "Insert Error"

					}
				}
				else
				{
					cout << "Input Error" << endl; // the input string is invalid so print out "Input Error"
				}
			}
			// the option delete
			else if (command == "delete")
			{
				string firstName, lastName, phone; // declare a first name, last name and phone string
				cin >> firstName >> lastName >> phone; // get the all string value

				// check if the input is valid 
				if (isInputValid(firstName, lastName, phone) == true)
				{
					StRec student = getInformation(firstName, lastName, phone); // get the student information
					// check if the student is exist and the list is empty
					// if the student is exist then delete the student information
					if (isStudentExist(student) == true && information.empty() == false)
					{
						deleteInformation(student); // delete the student's information
					}
					else
					{
						cout << "Delete Error" << endl; // if the student is not exist and or the list is empty then print out "Delete Error"
					}
				}
				else
				{
					cout << "Input Error" << endl; // if the input is invalid then print out the "Input Error" message
				}
			}
			//the option search
			else if (command == "search")
			{
				string firstName, lastName, phone; // declare the first, last name and phone string
				cin >> firstName >> lastName >> phone; // input the string data

				// check if the input is valid
				if (isInputValid(firstName, lastName, phone) == true)
				{
					StRec student = getInformation(firstName, lastName, phone); // create a student and set its information to the input data
					// check if the student is exist
					if (isStudentExist(student) == false)
					{
						cout << "Search Error" << endl; // if the student is not exist, then print out the "Search Error" message
					}
					else
					{
						cout << findInformation(student) << endl; // if the student is exist then print its position of the information list
					}
				}
				else
				{
					cout << "Input Error" << endl; // the input is invalid, print out the "Input Error" message
				}
			}
			// the option print
			else
			{
				// check if the information list is empty
				if (information.empty() == true)
				{
					cout << "Print Error" << endl; // if the list is empty then print out the "Print Error" message
				}
				else
				{
					printInformation(); // print all the student information of the list
				}
			}
		}
	}
}

/**
 * Intent : overload the operator == to check if the lhs is equal to rhs
 * pre : need two parameter lhs and rhs
 * post : check if the struct lhs is equal to rhs
 * \param lhs
 * \param rhs
 * \return true or false
 */
bool operator==(StRec lhs, StRec rhs)
{
	bool isFirstNameValid = (strcmp(lhs.firstName, rhs.firstName) == 0); // check if lhs's first name is equal to rhs's first name
	bool isLastNameValid = (strcmp(lhs.lastName, rhs.lastName) == 0); // check if lhs's last name is equal to rhs's last name
	bool isPhoneValid = (strcmp(lhs.phone, rhs.phone) == 0); // check if lhs's phone number is equal to rhs's phone number

	return (isFirstNameValid && isLastNameValid && isPhoneValid); // return if lhs's all the information is equal to rhs
}

/**
 * Intent : check if the input command is valid 
 * pre : need a input command
 * post : check if the input command is valid
 * \param command
 * \return true or false
 */
bool isCommandValid(string command)
{
	// if the input command is not eqaul to "inser", "delete", "search" or "print"
	// then return false, otherwise is true
	return (command == "insert" || command == "delete" || command == "search" || command == "print");
}

/**
 * Intent : check if the input string is valid
 * pre : need three input data
 * post : check if the input data is valid
 * \param firstN
 * \param lastN
 * \param phoneN
 * \return true or false
 */
bool isInputValid(string firstN, string lastN, string phoneN)
{
	bool isFirstNameValid = (firstN.size() <= 25); // declare a variable to check if the first name string's length is valid
	bool isLastNameValid = (lastN.size() <= 30); // declare a variable to check if the last name string's length is valid
	bool isPhoneValid1 = (phoneN.size() <= 15); // declare a variable to check if the phone string's length is valid
	// intent : check if the phone's element is '0' ~ '9'
	// pre : none
	// post : modify isPhoneValid2's value to be true or false
	// parameter : input phoneN string
	bool isPhoneValid2 = [&](string) -> bool 
	{
		for (auto& i : phoneN) // use range for loop to run every element of phoneN
		{
			if (!(i >= '0' && i <= '9')) 
			{
				return false; // if any of the phoneN is over or less than 0 or 9 then modify the variable to be false
			}
			return true; // if the input is valid then modify the variable to be true
		}
	}(phoneN); // call the phoneN parameter

	return (isFirstNameValid && isLastNameValid && isPhoneValid1 && isPhoneValid2); // return all the check is valid
}

/**
 * Intent : check if the target student is exist 
 * pre : none
 * post : none
 * \param target
 * \return if the target student is exist
 */
bool isStudentExist(StRec target)
{
	for (auto& stu : information) // use range for loop to run every element of information list
	{
		if (stu == target) // if the the student is exist, return true
		{
			return true; // return true
		}
	}

	return false; // if the student is not exist then return false
}

/**
 * Intent : check if the insert is valid
 * pre : none	
 * post : none
 * \param target
 * \return true or false
 */
bool isInsertValid(StRec target)
{
	// check if the target student is already insert to the list
	// and if the information list is already has 10 students in it
	if (isStudentExist(target) == true || information.size() >= 10)
	{
		return false; // if the list is full or the student is already insert to the list, then return false
	}

	return true; // if the student haven't been inserted to the this then return true
}

/**
 * Intent : get the information of the input data
 * pre : the first, last and phone input string must be valid
 * post : make a struct temp to store the input data and return it
 * \param first
 * \param last
 * \param phone
 * \return a struct StRec temp
 */
StRec getInformation(string first, string last, string phone)
{
	StRec temp{"", "", ""}; // initial a temp and its information is null
	strcpy_s(temp.firstName, first.c_str()); // copy the first name from the parameter to the temp
	strcpy_s(temp.lastName, last.c_str()); // copy the last name from the parameter to the temp
	strcpy_s(temp.phone, phone.c_str()); // copy the phone form the parameter to the temp

	return temp; // return a temp struct
}

/**
 * Intent : delete the target's information
 * pre : the target must exist and the information list must be not empty
 * post : delete the target from the information list
 * \param target
 */
void deleteInformation(StRec target)
{
	// use a iterator from begin to end of information, find the target and delete it
	for (auto current = information.begin(); current != information.end(); current++)
	{
		if (*current == target) // if find the target than delete it
		{
			information.erase(current); // use member function erase to delete the target from the list
			return; // end the function
		}
	}
}

/**
 * Intent : find the index of the target in the list
 * pre : the target must exist
 * post : none
 * \param target
 * \return the index of the target from the list
 */
int findInformation(StRec target)
{
	int index(0); // initial the index is from 0
	for (; index < information.size(); index++) // run all the index untill find the target
	{
		if (information[index] == target) // if find the target then return the current index
		{
			return index; // return the index
		}
	}
}

/**
 * Intent : print the all information from the list
 * pre : the information list must be not empty
 * post : none
 */
void printInformation()
{
	// use range for loop to run all of the information's elements and prints them out
	for (auto& i : information)
	{
		// print out their first name, last name and their phone number
		cout << i.firstName << " " << i.lastName << " " << i.phone << endl;
	}
}
