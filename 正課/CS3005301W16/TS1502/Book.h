/*****************************************************************//**
 * file : Book.h
 * Author : 陳彥儒
 * Create date : June 7, 2023
 * Last update : June 7, 2023
 * Description : Book.h
 *********************************************************************/
#pragma once
#include <iostream>
using namespace std;

class Book
{
private:
	string title; // the title property
	string author; // the author property
	int edition; // the edition property

public:
	Book(const string& title, const string& author, const int& edition); // the constructor of the book 
	string getTitle() const; // the function to get the title string 
	string getAuthor() const; // the function to get the author string
	int getEdition() const; // the function to get the edition value
	friend bool operator<(const Book& lhs, const Book& rhs); // the operator < overloding
	friend bool operator==(const Book& lhs, const Book& rhs); // the operator == overloading
};
