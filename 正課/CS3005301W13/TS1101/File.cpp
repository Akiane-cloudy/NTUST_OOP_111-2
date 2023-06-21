/*****************************************************************//**
 * file : File.cpp
 * Author : ³¯«Û¾§ 
 * Create date : May 18, 2023
 * Last update : May 18, 2023
 * Description : File.cpp
 *********************************************************************/
#include "File.h"

/**
 * Intent : A file constructor
 * pre : 
 * post : 
 * \param document
 * \param pathName
 */
File::File(std::string document, std::string pathName)
{
	// set the text and the path name
	this->text = document;
	this->pathName = pathName;
}

/**
 * Intent : get the path name 
 * pre : 
 * post : 
 * \return 
 */
std::string File::getPathname() const
{
	// return the path name
	return this->pathName;
}

/**
 * Intent : set the path name
 * pre : 
 * post : 
 * \param path
 */
void File::setPathname(std::string path)
{
	// set the path name
	this->pathName = path;
}
