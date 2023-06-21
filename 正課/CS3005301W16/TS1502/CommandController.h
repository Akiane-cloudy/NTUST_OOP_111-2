/*****************************************************************//**
 * file : CommandController.h
 * Author : 陳彥儒
 * Create date : June 7, 2023
 * Last update : June 7, 2023
 * Description : CommandController.h
 *********************************************************************/
#pragma once
#include "DataBase.h"

#include <sstream>

class CommandController
{
public:
	static void commandInput(const string& command); // input the command
	static void insert(const string& args); // insert function
	static void deleted(const string& args); // delete edition
	static void find(const string& args); // find author
	static void sort(const string& args); // sort by author/title
};

