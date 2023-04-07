/*****************************************************************//**
 * file : Point.h
 * Author : ³¯«Û¾§ 
 * Create date : March 24, 2023
 * Last update : March 24, 2023
 * Description : Point.h
 *********************************************************************/
#ifndef _Point_H_ // if not define the Point.h
#define _Point_H_ // then define Point.h
#include <iostream>
using namespace std;

// create a Point class
class Point
{
// two private property : vertical, horizontal
private:
	int vertical;
	int horizontal;

public:
	Point() // the constructor to innitial the vertical and horizontal value
	{
		vertical = 0; // set the value of vertical to 0
		horizontal = 0; // set the value of horizontal to 0
	}

	void Set(int vertical, int horizontal); // the function to modify the vertical and horizontal value
	void Move(int x, int y); // move the vertical value and the horizontal value by the parameter
	void Rotate(); // rotate the point about 90 degrees clockwise
	int RetrieveVertical() const { return vertical; }  // return the vertical value
	int RetrieveHorizontal() const { return horizontal; } // return the horizontal value
};

#endif //Point_H