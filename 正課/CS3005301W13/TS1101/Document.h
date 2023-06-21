/*****************************************************************//**
 * file : Document.h
 * Author : ³¯«Û¾§ 
 * Create date : May 18, 2023
 * Last update : May 18, 2023
 * Description : Document.h
 *********************************************************************/
#pragma once
#include <iostream>

// Declare a class Document to store a text
class Document
{
protected:
	std::string text; // a text property

public:
	// a default constructor
	Document() = default;
	// a construtor with other document
	Document(const Document& other);
	// a constructor with string
	Document(const std::string& inputText);

	// get the text
	std::string getText() const;
	// set the text
	void setText(const std::string& inputText);
	// overloading the operator = to assinged the document text
	void operator=(Document& rhs);
};
