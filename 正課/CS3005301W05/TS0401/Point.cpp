/*****************************************************************//**
 * file : Point.cpp
 * Author : ³¯«Û¾§ 
 * Create date : March 21, 2023
 * Last update : March 21, 2023
 * Description : Class_Point_In_Place
 *********************************************************************/
#include "Point.h"

/**
 * Intent : set this object's vetical and horizontal
 * pre : none 
 * post : modify the vertical and horizontal value
 * \param vertical
 * \param horizontal
 */
void Point::Set(int vertical, int horizontal)
{
	this->vertical = vertical; // origin vetical value -> the vertical value which is called
	this->horizontal = horizontal; // origin horizontal value -> the horizontal value which is called
}

/**
 * Intent : move the point for serveral pixels
 * pre : none
 * post : modidy the point for serveral pixels of x and y
 * \param x
 * \param y
 */
void Point::Move(int x, int y)
{
	this->vertical += x; // let vertical value move about x pixels
	this->horizontal += y; // let horizontal value move about y pixels
}

/**
 * Intent : let the point turn 90 degrees clockwise from origin
 * pre : none
 * post : let the point turn 90 degrees clockwise from origin
 */
void Point::Rotate()
{
	// if a point is turnning 90 degrees, then the x coordinate and the y coordinate will switch
	// and the new horizontal one will times -1
	swap(this->vertical, this->horizontal);  // let the vertical and horizontal switch
	this->horizontal *= -1; // let the new horizontal one times -1
}
