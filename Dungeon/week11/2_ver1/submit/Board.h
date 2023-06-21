/*****************************************************************//**
 * File: Board.h
 * Author: 許桓愷 (B11115008@mail.ntust.edu.tw)
 *		   陳彥儒 (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: 許桓愷 (B11115008@mail.ntust.edu.tw)
 *		   陳彥儒 (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-21
 * Description:  The board header file
 *********************************************************************/
#pragma once

#include <vector>
#include <map>
#include <memory>
#include <iomanip>
#include <cstdlib>

#include "Trigger.h"
#include "ItalianPepperChicken.h"
#include "Hero.h"
#include "TsuaIngWen.h"
#include "XiJinPing.h"

 // defult size of the board
#define DEFULT_LENGTH 11
#define DEFULT_WIDTH 10
// icon of the board
#define WALL '*'
#define NOTHING ' '
#define UNKNOWN '~'
// amounts of creature and trigger
#define CREATURE_SIZE 2
#define TRIGGER_SIZE 2

using namespace std;

// this class control the board
class Board {
private:
	// use a vector vector char to store the board
	vector<vector<char>> board;
	// use a map which take Position as key, bool as the value to check which position is valid
	map<Position, bool> validPos;

	// make a hero
	Hero hero;
	// use a vector to store all creatures
	vector<shared_ptr<Creature>> creatures;
	// use a vector to store all triggers
	vector<shared_ptr<Item>> items;

	// make the dungeon map by DFS
	void dungeonGenerator(int length, int width, Position pos, int dir);

public:
	// make a board with input size or defult size
	Board(int length = DEFULT_LENGTH, int width = DEFULT_WIDTH);
	// make a board with input board
	Board(const Board& other);

	// get the board
	vector<vector<char>>& getBoard();
	// set the board with input vector vector char
	void setBoard(const vector<vector<char>>& newBoard);

	// get the hero
	Hero& getHero();
	// set the hero
	void setHero(const Hero& hero);

	// get the creatures vector
	vector<shared_ptr<Creature>>& getCreatures();
	// set the creatures vector
	void setCreatures(const vector<shared_ptr<Creature>>& creatures);

	// get the triggers vector
	vector<shared_ptr<Item>>& getItems();
	// set the triggers vector
	void setItems(const vector<shared_ptr<Item>>& items);

	// get the length of the board
	int getLength();
	// get the width of the board
	int getWidth();

	// check if the position is empty
	bool isPosEmpty(const Position& pos);
	// check if the position is valid
	bool isPosValid(const Position& pos);
	// draw the board with elements
	void draw();

	bool canCreatureSee();
};
