/*****************************************************************//**
 * file : CommandController.cpp
 * Author : 陳彥儒
 * Create date : June 7, 2023
 * Last update : June 7, 2023
 * Description : CommandController.cpp
 *********************************************************************/
#include "CommandController.h"

 /**
  * Intent : Execute the input command
  * pre : the command must be not empty
  * post : none
  * \param inputCommand
  */
void CommandController::commandInput(const string& inputCommand)
{
	// use string stream to modify the input stream to the inputCommand
	stringstream ss(inputCommand);
	string command, args; // declare the command and args string variable

	ss >> command; // input the command string 
	getline(ss, args); // get the args 

	// Execute the command if it is valid
	if (command == "Insert") CommandController::insert(args);
	else if (command == "Delete") CommandController::deleted(args);
	else if (command == "Find") CommandController::find(args);
	else if (command == "Sort") CommandController::sort(args);
	else throw "Unknown Command.\n"; // if the command is invalid then throw the unknow command error message
}

/**
 * Intent :	The insert function
 * pre : none
 * post : none
 * \param args
 */
void CommandController::insert(const string& args)
{
	// Open the string stream with the input args
	stringstream ss(args);
	string title = "", author = ""; // declare the title and author string 
	int edition = 0; // declare the edition variable

	// use for loop to split the title with the character '"'
	for (string temp; (!ss.eof() && title.empty()) || (!title.empty() && title.back() != '"' && title[1] == '"');) {
		ss >> temp;
		title += ' ' + temp; // add the space of the title string
	}
	if (title.size()) title = title.substr(2, title.size() - 3); // split the string

	// use for loop to split the author string with the character '"'
	for (string temp; (!ss.eof() && author.empty()) || (!author.empty() && author.back() != '"' && author[1] == '"');) {
		ss >> temp;
		author += ' ' + temp; // add the space of the author string
	}
	if (author.size()) author = author.substr(2, author.size() - 3); // split the string 

	ss >> edition; // input the edition 

	// check the args size of the titlte, author and edition if it is incomplete
	if (!(title.size() && author.size() && edition)) throw "Incomplete Command.\n";
	else DataBase::insert(title, author, edition); // Do the insert function 
}

/**
 * Intent :	The deleted command
 * pre : none
 * post : none
 * \param args
 */
void CommandController::deleted(const string& args)
{
	// Open the string stream with the input args
	stringstream ss(args);
	string type, title = "", author = ""; // declare the title and author string 
	int edition = 0; // declare the edition variable

	ss >> type; // input the type
	if ((type != "Edition" && type != "Book")) throw "Incomplete Command.\n"; // if the type is neither edition nor book then throw the incomplete command

	// split the title string
	for (string temp; (!ss.eof() && title.empty()) || (!title.empty() && title.back() != '"' && title[1] == '"');) {
		ss >> temp;
		title += ' ' + temp; // add the space between string 
	}
	if (title.size()) title = title.substr(2, title.size() - 3); // split the string of the character '"'

	// use for loop to split author string 
	for (string temp; (!ss.eof() && author.empty()) || (!author.empty() && author.back() != '"' && author[1] == '"');) {
		ss >> temp;
		author += ' ' + temp; // add the space bewteen string
	}
	if (author.size()) author = author.substr(2, author.size() - 3); // split the string of the character '"'

	ss >> edition; // input the edition value

	// if the args size of title and author is invalid then throw the incomplete command error message
	if (!(title.size() && author.size())) throw "Incomplete Command.\n";
	else {
		// according to the type and do the deleted function
		if (type == "Edition") DataBase::deleted(title, author, edition);
		else DataBase::deleted(title, author);
	}
}

/**
 * Intent : The find function
 * pre : none
 * post : none
 * \param args
 */
void CommandController::find(const string& args)
{
	// open the string stream with the input args string
	stringstream ss(args);
	string type, title = "", author = ""; // declare the type, title and author string 

	ss >> type; // input the type 
	if (type != "Book" && type != "Author") throw "Incomplete Command.\n"; // if the type is invalid then throw the incomplete command error message

	// use for loop to split the title string
	for (string temp; (!ss.eof() && title.empty()) || (!title.empty() && title.back() != '"' && title[1] == '"');) {
		ss >> temp;
		title += ' ' + temp; // add the space between temp and the title string
	}
	if (title.size()) title = title.substr(2, title.size() - 3); // split the title string

	// use for loop to plit the author string
	for (string temp; (!ss.eof() && author.empty()) || (!author.empty() && author.back() != '"' && author[1] == '"');) {
		ss >> temp;
		author += ' ' + temp; // add the space between temp string and author string
	}
	if (author.size()) author = author.substr(2, author.size() - 3); // split the author string with character '"'

	if (!(title.size())) throw "Incomplete Command.\n"; // if the title size is 0 the throw the incomplete command error message
	else {
		if (type == "Book") DataBase::find(title, author); // do the find function
		else DataBase::find(title); // title == author
	}
}

/**
 * Intent : the sort function
 * pre : none
 * post : none
 * \param args
 */
void CommandController::sort(const string& args)
{
	// according to the args and do the right sort function
	if (args == " by Title") DataBase::sortByTitle();
	else if (args == " by Author") DataBase::sortByAuthor();
	else throw "Incomplete Command.\n"; // if the args is invalid then throw the incomplete command
}

