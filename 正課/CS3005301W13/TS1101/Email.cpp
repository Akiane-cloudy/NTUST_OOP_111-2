/*****************************************************************//**
 * file : Email.cpp
 * Author : ³¯«Û¾§ 
 * Create date : May 18, 2023
 * Last update : May 18, 2023
 * Description : Email.cpp
 *********************************************************************/
#include "Email.h"

/**
 * Intent : a constructor with document, sender, recipient and title
 * pre : 
 * post : 
 * \param documents
 * \param sender
 * \param recipient
 * \param title
 */
Email::Email(std::string documents, std::string sender, std::string recipient, std::string title)
{
	// set the properties
	this->text = documents;
	this->sender = sender;
	this->recipient = recipient;
	this->title = title;
}

/**
 * Intent : Get the sender 
 * pre : 
 * post : 
 * \return 
 */
std::string Email::getSender()
{
	// retur the sender
	return this->sender;
}

/**
 * Intent : set the sender
 * pre : 
 * post : 
 * \param sender
 */
void Email::setSender(std::string sender)
{
	// set the sender with the parameter
	this->sender = sender;
}

/**
 * Intent : get the recipient
 * pre : 
 * post : 
 * \return 
 */
std::string Email::getRecipient()
{
	// return the recipient
	return this->recipient;
}

/**
 * Intent : set the recipient
 * pre : 
 * post : 
 * \param recipient
 */
void Email::setRecipient(std::string recipient)
{
	// set the recipient to the parameter
	this->recipient = recipient;
}

/**
 * Intent : get the title
 * pre : 
 * post : 
 * \return 
 */
std::string Email::getTitle()
{
	// get the title
	return this->title;
}

/**
 * Intent : set the title
 * pre : 
 * post : 
 * \param title
 */
void Email::setTitle(std::string title)
{
	// set the title
	this->title = title;
}
