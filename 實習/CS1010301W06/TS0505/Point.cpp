/*****************************************************************//**
 * file : Point.cpp
 * Author : ³¯«Û¾§ 
 * Create date : March 30, 2023
 * Last update : March 30, 2023
 * Description : Point.cpp of the Point.h
 *********************************************************************/
#include "Point.h";
#include <iostream>
using namespace std;

/**
 * Intent : create copy constructor to copy the target to this class object
 * pre : none
 * post : let this object elements is equal to the target
 * \param target
 */
Point::Point(const Point& target)
{
	this->coordinates[0] = target.GetHorizontal(); // copy the target's horizontal value to this object
	this->coordinates[1] = target.GetVertical(); // copy the target's vertical value to this object
}

/**
 * Intent : a Set function to set the coordinates to the parameter
 * pre : none
 * post : let the coorinates x and y modify by the parameter
 * \param x
 * \param y
 */
void Point::Set(float x, float y)
{
	this->coordinates[0] = x; // modify the coordiante of x be the input x
	this->coordinates[1] = y; // modify the coordiante of y be the input y
}

/**
 * Intent : a Move function to modify the coorinates of x and y by the delta value
 * pre : none
 * post : modify the coordinates by the delta value
 * \param deltaX
 * \param deltaY
 */
void Point::Move(float deltaX, float deltaY)
{
	this->coordinates[0] += deltaX; // let x move about delta x
	this->coordinates[1] += deltaY; // let y move about delta y
}

/**
 * Intent : a Rotate function to rotate the point clockwise
 * pre : none
 * post : modify the point clockwise
 */
void Point::Rotate()
{
	// rotate a point clockwise is swap its x and y then let y * -1
	swap(this->coordinates[0], this->coordinates[1]); // swap the x and y
	this->coordinates[1] *= -1; // let the y * -1
}

/**
 * Intent : a Reflect function let the point reflect by origin
 * pre : none
 * post : modify the point to the reflect of origin point 
 */
void Point::Reflect()
{
	this->coordinates[0] *= -1; // let x * -1
	this->coordinates[1] *= -1; // let y * -1
}

/**
 * Intent : out put the horizontal value
 * pre : none
 * post : none
 * \return the x coordiante value
 */
int Point::GetHorizontal() const
{
	return coordinates[0]; // return the coordinate of x value
}

/**
 * Intent : out put the verticle value
 * pre : none
 * post : none
 * \return the y coordiante value
 */
int Point::GetVertical() const
{
	return coordinates[1]; // return the coordinate of y value
}

