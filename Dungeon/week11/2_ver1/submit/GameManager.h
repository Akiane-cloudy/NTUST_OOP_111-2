/*****************************************************************//**
 * File: GameManager.h
 * Author: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-21
 * Description:  The GameManager header file
 *********************************************************************/

#include <fstream>
#include <cstdlib>

#include "GAME_STATE.h"
#include "Board.h"

// this class manage the board and the state of the game
class GameManager
{
private:
	// use a board to store the game information
	Board board;
	// store current game state
	GAME_STATE gameState;

public:
	// set a board with defult size or input size
	GameManager(int length = DEFULT_LENGTH, int width = DEFULT_WIDTH);

	// move the hero with input direction
	bool move(const Position& delta);
	// update the information of all elements on the board
	void update();
	// end the game with input game state
	void gameOver(GAME_STATE& gameState);
	// print out the information
	void printInformation();
	// print out the board
	void printBoard();
	// save the board and game information to txt file
	void save(); 
	// load the board and game information from txt file
	void load();
	// end the game
	void exit();
};

