/*****************************************************************//**
 * file : DataBase.h
 * Author : 陳彥儒
 * Create date : June 7, 2023
 * Last update : June 7, 2023
 * Description : DataBase.h
 *********************************************************************/
#pragma once
#include "Book.h"

#include <set>
#include <vector>
#include <algorithm>

 // Declare a DataBase class to store the data with Book
class DataBase
{
public:
	static vector<Book> dataBase; // A vector to store the data with Book
	static void insert(const string& title, const string& author, const int& edition); // Insert
	static void deleted(const string& title, const string& author); // delete book
	static void deleted(const string& title, const string& author, const int& edition); // delete edition
	static void find(const string& title, const string& author); // find book
	static void find(const string& author); // find author
	static void sortByTitle(); // sort by title
	static void sortByAuthor(); // sort by author
};

