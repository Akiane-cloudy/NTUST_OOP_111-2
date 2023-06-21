/*****************************************************************//**
 * File: Controller.h
 * Author: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-21
 * Description:  The Controllor header file
 *********************************************************************/
#pragma once
#include "GameManager.h"

// this class control all main functions of the game
class Controller
{
private:
	// use a game manager to control the board
	GameManager dungeon;

public:
	Controller() = default;
	// initailize the board with input size
	Controller(const int& length, const int& width);

	// move the hero with input direction
	bool move(const Position& delta);
	// check if the input is invalid and print out the error message
	void update(bool& invalid, bool& moveInvalid);
	// print out the information
	void printInformation();
	// print out the board
	void printBoard();
	// save current board and game information to the txt file
	void save();
	// load the board and game information from the txt file
	void load();
	// end the game
	void exit();
};

