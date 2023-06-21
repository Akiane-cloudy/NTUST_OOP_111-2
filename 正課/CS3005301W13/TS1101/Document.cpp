/*****************************************************************//**
 * file : Document.cpp
 * Author : ³¯«Û¾§ 
 * Create date : May 18, 2023
 * Last update : May 18, 2023
 * Description : Document.cpp
 *********************************************************************/
#include "Document.h"

/**
 * Intent : a constructor with the other Document object
 * pre : 
 * post : 
 * \param other
 */
Document::Document(const Document& other)
{
	// set the text to this text
	this->text = other.text;
}

/**
 * Intent : a constructor with the input text parameter
 * pre : 
 * post : 
 * \param inputText
 */
Document::Document(const std::string& inputText)
{
	// set the text to the input text
	this->text = inputText;
}

/**
 * Intent : Get the text
 * pre : 
 * post : 
 * \return 
 */
std::string Document::getText() const
{
	// get the text
	return this->text;
}

/**
 * Intent : set the text
 * pre : 
 * post : 
 * \param inputText
 */
void Document::setText(const std::string& inputText)
{
	// set the text
	this->text = inputText;
}

/**
 * Intent : overloading the operator=
 * pre : 
 * post : 
 * \param rhs
 */
void Document::operator=(Document& rhs)
{
	// set this text to the other text
	this->text = rhs.getText();
}
