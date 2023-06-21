/*****************************************************************//**
 * File: main.cpp
 * Author: 許桓愷 (B11115008@mail.ntust.edu.tw)
 *		   陳彥儒 (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: 許桓愷 (B11115008@mail.ntust.edu.tw)
 *		   陳彥儒 (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-20
 * Description:  The main cpp file
 *********************************************************************/
#include <iostream>
#include <conio.h>

#include "VALID_KEY.h"
#include <Windows.h>
#include "Controller.h"

 // set the minimum size of the width and height
#define MIN_SIZE 4
// set all 4 different direction to Position array
const Position dir[4] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

/**
 * // Intent: get users input and play the game
 * // Pre:  None
 * // Post:  None
 */
int main()
{
	// use srand with time to get random number
	srand(time(NULL));
	// use these two intergers to store the size of the board
	int width, length;
	int valid = 0;

	// keep read size of the board until the input data is bigger than minimum size
	while (valid != 1) {
		string difficulty;

		if (valid == -1)
			cout << "Please enter valid difficulty!!!\n\n";

		cout << "--------------------------------\n";
		cout << "|Team 02                       |\n";
		cout << "|                              |\n";
		cout << "|Member:                       |\n";
		cout << "|       B11115004 YAN_RU CHEN  |\n";
		cout << "|       B11115008 HUAN_KAI HSU |\n";
		cout << "|                              |\n";
		cout << "--------------------------------\n";
		cout << '\n';
		cout << "□□□□□□□□□□□□□□□□□\n";
		cout << "□ Game mode selection menu :)  □\n";
		cout << "□ B: for Black (HARD)          □\n";
		cout << "□ Y: for Yellow (MEDIUM)       □\n";
		cout << "□ W: for White (EASY)          □\n";
		cout << "□□□□□□□□□□□□□□□□□\n";
		cout << "Enter game difficulty: ";

		cin >> difficulty;

		if (difficulty == "B" || difficulty == "b") {
			width = 7;
			length = 7;
			valid = 1;
		}
		else if (difficulty == "Y" || difficulty == "y") {
			width = 13;
			length = 13;
			valid = 1;
		}
		else if (difficulty == "W" || difficulty == "w") {
			width = 17;
			length = 17;
			valid = 1;
		}
		else {
			valid = -1;
		}

		// clean the output
		system("CLS");
	}

	// use a controller to control main functions of game 
	Controller dungeonControll(length, width);
	// invalid to check whether the user input is invalid
	// moveInvalid to check whether the move is invalid
	bool invalid = false, moveInvalid = false;

	// keep get user's input and do corresponding move
	while (true)
	{
		// update the user input
		dungeonControll.update(invalid, moveInvalid);

		// see which key the user press
		switch (_getch())
		{
			// if the user press w
		case 'W':
		case 'w':
			// move the hero up
			// if the move is fail, set moveInvalid to true
			if (!dungeonControll.move(dir[0])) moveInvalid = true;
			break;

			// if the user press s
		case 'S':
		case 's':
			// move the hero down
			// if the move is fail, set moveInvalid to true
			if (!dungeonControll.move(dir[1])) moveInvalid = true;
			break;

			// if the user press a
		case 'A':
		case 'a':
			// move the hero left
			// if the move is fail, set moveInvalid to true
			if (!dungeonControll.move(dir[2])) moveInvalid = true;
			break;

			// if the user press d
		case 'D':
		case 'd':
			// move the hero right
		   // if the move is fail, set moveInvalid to true
			if (!dungeonControll.move(dir[3])) moveInvalid = true;
			break;

			// if the user press ESC
		case 27:
			// end the program
			dungeonControll.exit();
			break;

			// if the user press 1
		case '1':
			// save the file to txt file
			dungeonControll.save();
			break;

			// if the user press 2
		case '2':
			// load the board and game information from txt file
			dungeonControll.load();
			break;

			// if the user press an invalid key
		default:
			// set invalid to true
			invalid = true;
			break;
		}
	}
}
