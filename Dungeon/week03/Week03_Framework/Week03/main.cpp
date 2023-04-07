/************************************************************************
File:   Source.cpp

Author:
		Áé½å¼s¡Aea5878158@gmail.com
Modifier:
		¿à¯§¦N¡Acheeryuchi@gmail.com
		ÅU°ßÄ£¡Aguweiyao867@gmail.com
		³¯«T¦t¡AJYCReports@gmail.com
		ªô¹Å¿³¡Atbcey74123@gmail.com
Comment:
		Draw and print out the canvas.

************************************************************************/

/********************************************************************

Name: ³¯«Û¾§ B11115004, ³\®Ù·¢B11115008

Date: March 14, 2023

Last Update: March 14, 2023

Problem statement: Draw and print out the canvas.

*********************************************************************/

#include <iostream>
#include <stdio.h>
#include <cstdlib> // use to pause the window before user click anything from keyboard
using namespace std;

void drawBoard(); //Function to draw board
void makeBoard(); //Function to make board
void modifyBoard();	//Function to modify board

const int DUNGEN_ROW = 10, DUNGEN_COL = 20;
char dungenMap[DUNGEN_ROW][DUNGEN_COL];

int main(int argc, char** argv)
{
	makeBoard();
	drawBoard();
	modifyBoard();
	drawBoard();

	system("pause"); // pause the window before user click anything from keyboard
}

void drawBoard()
//==================================================================
{
	// Draw out the whole board
	/************************************************************************/
	/*Please implement your code here*/

	// use two for loop to print out the dungen map
	// if one column finish to print, then make a new line
	for (int row(0); row < DUNGEN_ROW; row++)
	{
		for (int column(0); column < DUNGEN_COL; column++)
		{
			cout << dungenMap[row][column];
		}
		cout << endl;
	}
	cout << endl;
	/************************************************************************/
}

void makeBoard()
//==================================================================
{
	// Enter symbol for wall and blank then create array
	/************************************************************************/
	/*Please implement your code here*/

	// declare two varialbes to store symbol of wall and symbol of blank
	char symbolWall, symbolBlank; 

	cout << "Enter symbol for wall: ";
	cin.get(symbolWall); // get the symbol of wall, we use cin.get() because it can get the space character

	cin.ignore(1, '\n'); // clear the input buffer because cin.get() will getch the '\n'

	cout << "Enter symbol for blank: ";
	cin.get(symbolBlank); // get the symbol of blank

	cin.ignore(1, '\n');

	// the range of blank is 
	// row: 1 ~ DUNGEN_ROW - 1 
	// column : 1 ~ DUNGEN_COL - 1
	// so out of this range are all wall.
	for (int row(0); row < DUNGEN_ROW; row++)
	{
		for (int column(0); column < DUNGEN_COL; column++)
		{
			if (row > 0 && row < DUNGEN_ROW - 1 && column > 0 && column < DUNGEN_COL - 1)
			{
				dungenMap[row][column] = symbolBlank;
			}
			else
			{
				dungenMap[row][column] = symbolWall;
			}
		}
	}
	/************************************************************************/
}

void modifyBoard()
//==================================================================
{
	// Function for modifying board given position and char to change
	/************************************************************************/
	/*Please implement your code here*/
	char symbolPosition; // the symbol of new character 
	int modifyX, modifyY; // which position it want to modifying

	cout << "Enter symbol for modifying position: ";
	cin.get(symbolPosition); // get the symbol of new character

	cout << "Enter X of modifying position: ";
	cin >> modifyX; // get the position of X which need to modifying 

	cout << "Enter Y of modifying position: ";
	cin >> modifyY; // get the position of Y which need to modifying 
	
	// the range of x is 1 ~ DUNGEN_COL - 1
	// the range of y is 1 ~ DUnGEN_ROW - 1
	bool xIsValid = (modifyX > 0 && modifyX < DUNGEN_COL - 1);
	bool yIsValid = (modifyY > 0 && modifyY < DUNGEN_ROW - 1);
	if (xIsValid && yIsValid) // if the position is valid then modifying the character
	{
		dungenMap[modifyY][modifyX] = symbolPosition; 
	}
	else
	{
		cout << "Invalid input" << endl;
	}
	/************************************************************************/
}