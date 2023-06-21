/*****************************************************************//**
 * file : Book.cpp
 * Author : 陳彥儒
 * Create date : June 7, 2023
 * Last update : June 7, 2023
 * Description : Book.cpp
 *********************************************************************/
#include "Book.h"

 /**
  * Intent : The constructor of the Book class
  * pre : none
  * post : none
  * \param title
  * \param author
  * \param edition
  */
Book::Book(const string& title, const string& author, const int& edition)
{
	// initial the properties
	this->title = title;
	this->author = author;
	this->edition = edition;
}

/**
 * Intent :	Get the title property
 * pre : none
 * post : none
 * \return
 */
string Book::getTitle() const
{
	// get the title string
	return this->title;
}

/**
 * Intent : The funtcion to get the author string
 * pre : none
 * post : none
 * \return
 */
string Book::getAuthor() const
{
	// get the author string 
	return this->author;
}

/**
 * Intent :	Get the edition value
 * pre : none
 * post : none
 * \return
 */
int Book::getEdition() const
{
	// get the edition value
	return this->edition;
}

/**
 * Intent : Overloading the operator < of two Book class
 * pre : none
 * post : none
 * \param lhs
 * \param rhs
 * \return
 */
bool operator<(const Book& lhs, const Book& rhs)
{
	// compare order: author title and edition
	if (rhs.author.size() > lhs.author.size()) return true;
	if (rhs.title.size() > lhs.title.size()) return true;
	if (rhs.edition > lhs.edition) return true;

	// else condition is return false
	return false;
}

/**
 * Intent : Overloading the operator == of two Book class
 * pre : none
 * post : none
 * \param lhs
 * \param rhs
 * \return
 */
bool operator==(const Book& lhs, const Book& rhs)
{
	// return the lhs is equal to the rhs class if the all properties is equivlent
	return (lhs.author == rhs.author && lhs.title == rhs.title && lhs.edition == rhs.edition);
}
