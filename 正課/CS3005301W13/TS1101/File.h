/*****************************************************************//**
 * file : File.h
 * Author : ³¯«Û¾§ 
 * Create date : May 18, 2023
 * Last update : May 18, 2023
 * Description : File.h
 *********************************************************************/
#pragma once
#include "Document.h"

// Declare a File class and inheritance the class document
class File : public Document
{
private:
	std::string pathName; // a varialbe of string to store the path name

public:
	// A constructor with document and pathname
	File(std::string document, std::string pathName);
	// get the path name string 
	std::string getPathname() const;
	// set the path name
	void setPathname(std::string path);
};

