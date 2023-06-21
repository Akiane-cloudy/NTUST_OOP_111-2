/*****************************************************************//**
 * file : Email.h
 * Author : ³¯«Û¾§ 
 * Create date : May 18, 2023
 * Last update : May 18, 2023
 * Description : Email.h
 *********************************************************************/
#pragma once

#include "Document.h"
// Declare a Email class and inheritance the class Document
class Email : public Document
{
private:
	// declare sender, recipient, title properties
	std::string sender;
	std::string recipient;
	std::string title;

public:
	// The constructor with document, sender, recipient and title string
	Email(std::string documents, std::string sender, std:: string recipient, std::string title);

	// Get the string sender
	std::string getSender();
	// set the sender with parameter
	void setSender(std::string sender);
	// Get the recipient
	std::string getRecipient();
	// set the recipient
	void setRecipient(std::string recipient);
	// Get the title
	std::string getTitle();
	// Set the title
	void setTitle(std::string title);
};

