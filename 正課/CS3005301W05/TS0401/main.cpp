/*****************************************************************//**
 * file : main.cpp
 * Author : ³¯«Û¾§ 
 * Create date : March 24, 2023
 * Last update : March 24, 2023
 * Description : the main of Class_Point_In_Plane
 *********************************************************************/
#include <iostream>
#include "Point.h" // import the Point.h
using namespace std;

int main(void) {
	Point point; // create a class Point "point"

	point.Set(0, 5); // set the point's vetical value and horizontal value
	cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl; // out put the vertical value and the horizontal value

	point.Move(1, 2); // let the vertical and horizontal value modyfying by the parameter
	cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl; // out put the vertical value and the horizontal value

	// use for loop to rotate the point 4 times and print out the result
	for (int i = 0; i < 4; i++) {
		point.Rotate(); // turn the point by 90 degrees 
		cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl; // print out the result
	}

	return 0; // end the program
}