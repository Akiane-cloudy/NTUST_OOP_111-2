/*****************************************************************//**
 * file : Point.h
 * Author : ³¯«Û¾§ 
 * Create date : March 31, 2023
 * Last update : March 31, 2023
 * Description : Point.h
 *********************************************************************/
#pragma once

// create a Point class
class Point
{
private:
	float coordinates[2]; // use a float array to store coordinates
public:
	Point() = default; // the constructor is default
	Point(const Point&); // a copy constructor to copy the target to this object
	~Point() = default; // a distructor is default
	void Set(float, float); // a Set function use to set the coordiante by input value
	void Move(float, float); // a Move function to let the x and y move by the input value 
	void Rotate(); // rotate the point clockwise
	void Reflect(); // reflect the point by the origin
	int GetHorizontal() const; // get the horizontal value of the coordinates
	int GetVertical() const; // get the vertical value of the coordinates
};
