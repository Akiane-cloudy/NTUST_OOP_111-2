/*****************************************************************//**
 * File: Controller.cpp
 * Author: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-21
 * Description:  The Controller cpp file
 *********************************************************************/
#include "Controller.h"

/**
 * // Intent:  initialize the board with input size
 * // Pre:  const int& length, const int& width
 * // Post:  None
 */
Controller::Controller(const int& length, const int& width)
{
	// set dungeon to the game manager with input size board
	this->dungeon = GameManager(length, width);
}

/**
 * // Intent:  move the hero with input direction
 * // Pre:  const Position& delta
 * // Post:  true if hero move success, false if not
 */
bool Controller::move(const Position& delta)
{
	// move the hero by using move function in dungeon
	return this->dungeon.move(delta);
}

/**
 * // Intent:  check if the input is invalid and print out the error message
 * // Pre:  bool& invalid, bool& moveInvalid
 * // Post:  None
 */
void Controller::update(bool& invalid, bool& moveInvalid)
{
	// clean the output
	system("CLS");

	try {
		// if the user press an invalid key
		if (invalid) {
			// throw an error 
			throw "input error";
		}
	} catch (...) {
		// print out the error message
		cout << "Invalid input" << endl;
		invalid = false;
	}

	try {
		// if the position hero going to move is a WALL
		if (moveInvalid) {
			// thow an error
			throw "move error";
		}
	} catch (...) {
		// print out the error message
		cout << "Invalid location" << endl;
		moveInvalid = false;
	}

	// update the information of elements on the board
	this->dungeon.update();
	
	// print out the board
	this->printBoard();
	// print out information
	this->printInformation();
}

/**
 * // Intent:  print out the information
 * // Pre:  None
 * // Post:  None
 */
void Controller::printInformation()
{
	// use printInformation function in dungeon
	return this->dungeon.printInformation();
}

/**
 * // Intent:  print out the board
 * // Pre:  None
 * // Post:  None
 */
void Controller::printBoard()
{
	// use printBoard function in dungeon
	return this->dungeon.printBoard();
}

/**
 * // Intent:  save current board and game information to the txt file
 * // Pre:  None
 * // Post:  None
 */
void Controller::save()
{
	// use save function in dungeon
	return this->dungeon.save();
}

/**
 * // Intent:  load the board and game information from the txt file
 * // Pre:  None
 * // Post:  None
 */
void Controller::load()
{
	// use load function in dungeon
	return this->dungeon.load();
}

/**
 * // Intent:  end the game
 * // Pre:  None
 * // Post:  None
 */
void Controller::exit()
{
	// use exit function in dungeon
	return this->dungeon.exit();
}

