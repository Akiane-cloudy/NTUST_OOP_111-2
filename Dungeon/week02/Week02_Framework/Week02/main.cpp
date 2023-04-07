/************************************************************************
File:   Source.cpp

Author:
		ªô¹Å¿³¡Atbcey74123@gmail.com
Comment:
		Output character position after W,A,S,D input.
		Output invalid if destination out of boundary.
		ESC to stop process.

************************************************************************/
/***********************************************************************
Name: ³¯«Û¾§:B11115004, ³\®Ù·_:B11115008
Date: March 7, 2023 
Last Update: March 7, 2023 
Problem statement: 
	Output character position after W,A,S,D input.
	Output invalid if destination out of boundary.
	ESC to stop process.
***********************************************************************/

#include <iostream>	// For print out information
#include <conio.h>	// For getch() function

bool tryMove(int deltaX, int deltaY);
bool checkValidDst(int x, int y);

int posX = 0, posY = 0; // global param to keep the character position
const int DUNGEN_SIZE = 5; // For each dimension, -DUNGEN_SIZE < pos < DUNGEN_SIZE

// initial every single delta value about posX and posY
// and 0 of row represent deltaX, the other is deltaY
// delta[direction][x or y]:move to right, to down, to left and up.
const int delta[4][2]{ {1,0}, {0,-1}, {-1,0}, {0,1} };

int main()
{
	// Obtain and update the input using a loop
	while (true)
	{
		char input = _getch();
		if (input == 27)
		{
			break; // end the program
		}
		/************************************************************************/
		/*Please implement your code here*/
		switch (input) 
		{
			// move to up
			case 'W':
			case 'w':
				if (tryMove(delta[3][0], delta[3][1]) == false)
				{
					std::cout << "Failed to move" << std::endl;
				}
				std::cout << "Character position: (" << posX << ',' << posY << ")" << std::endl;
				break;
			// move to left
			case 'A':
			case 'a':
				if (tryMove(delta[2][0], delta[2][1]) == false)
				{
					std::cout << "Failed to move" << std::endl;
				}
				std::cout << "Character position: (" << posX << ',' << posY << ")" << std::endl;
				break;
			// move to down
			case 'S':
			case 's':
				if (tryMove(delta[1][0], delta[1][1]) == false)
				{
					std::cout << "Failed to move" << std::endl;
				}
				std::cout << "Character position: (" << posX << ',' << posY << ")" << std::endl;
				break;
			// move to right
			case 'D':
			case 'd':
				if (tryMove(delta[0][0], delta[0][1]) == false)
				{
					std::cout << "Failed to move" << std::endl;
				}
				std::cout << "Character position: (" << posX << ',' << posY << ")" << std::endl;
				break;
		}

		/************************************************************************/
	}
}

//******************************************************************
//
// * Move character with input delta, return true if successful otherwise false
//==================================================================
bool tryMove(int deltaX, int deltaY)
{
	/************************************************************************/
	/*Please implement your code here*/
	if (checkValidDst(posX + deltaX, posY + deltaY) == true)
	{
		posX += deltaX;
		posY += deltaY;
		return true;
	}
	return false;
	/************************************************************************/
}
//******************************************************************
//
// * Check if given position is a valid destination, return true if valid otherwise false
//==================================================================
bool checkValidDst(int x, int y)
{
	/************************************************************************/
	/*Please implement your code here*/
	bool xValid = (x < DUNGEN_SIZE && x > -DUNGEN_SIZE);
	bool yValid = (y < DUNGEN_SIZE && y > -DUNGEN_SIZE);
	return xValid && yValid;
	/************************************************************************/
}
