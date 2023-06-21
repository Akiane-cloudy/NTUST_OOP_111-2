/*****************************************************************//**
 * File: Board.cpp
 * Author: 許桓愷 (B11115008@mail.ntust.edu.tw)
 *		   陳彥儒 (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: 許桓愷 (B11115008@mail.ntust.edu.tw)
 *		   陳彥儒 (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-21
 * Description:  The Board cpp file
 *********************************************************************/
#include "Board.h"  

 /**
  * // Intent:  make a board with input size or defult size
  * // Pre:  None
  * // Post:  None
  */
Board::Board(int length, int width) {
	// set the size of the board
	this->board.resize(length, vector<char>(width));

	// Initial the board
	for (int i = 0; i < length; i++) {
		// fill up the board with WALL in the edge
		if (i == 0 || i == length - 1) fill_n(begin(board[i]), board[i].size(), WALL);
		else {
			// fill other space with UNKNOWN
			board[i][0] = board[i][width - 1] = WALL;
			fill_n(begin(board[i]) + 1, board[i].size() - 2, UNKNOWN);
		}
	}

	// Generate the board
	dungeonGenerator(length, width, { 1, 1 }, 4);

	// change the rest UNKNOWN to WALL
	for (int i = 1; i < length - 1; i++) {
		for (int j = 1; j < width - 1; j++) {
			if (this->board[i][j] == UNKNOWN) {
				this->board[i][j] = WALL;
			}
		}
	}

	// Get the valid position
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			// set the position to true as WALL
			validPos[Position(j, i)] = (board[i][j] == WALL ? true : false);
		}
	}

	// Get the random and valid position
	auto getRandomPos = [this, &length, &width]() {
		while (true) {
			// get a random position 
			Position pos = Position(rand() % width, rand() % length);
			// if the position is empty
			if (this->isPosEmpty(pos)) {
				return pos;
			}
		}
	};

	// get a random position
	Position hPos = getRandomPos();
	// set hero's position to the random position
	hero.setPos(getRandomPos());
	// set the position to true
	validPos[hPos] = true;

	// set random position for creatures
	for (int i = 0; i < CREATURE_SIZE; i++) {
		// get random position
		Position cPos = getRandomPos();
		// push first type of creature to the vector
		if (i == 0) this->creatures.emplace_back(make_shared<XiJinPing>(cPos));
		// push other type of creature to the vector
		else this->creatures.emplace_back(make_shared<TsuaIngWen>(cPos));
		// set the position to true
		validPos[cPos] = true;
	}

	for (int i = 0; i < TRIGGER_SIZE; i++) {
		// get random position
		Position tPos = getRandomPos();
		// push first type of creature to the vector
		if (i == 0) this->items.emplace_back(make_shared<Trigger>(tPos));
		// push other type of creature to the vector
		else this->items.emplace_back(make_shared<ItalianPepperChicken>(tPos));
		// set the position to true
		validPos[tPos] = true;
	}
}

/**
 * // Intent:  make a board with input board
 * // Pre:  const Board& other
 * // Post:  None
 */
Board::Board(const Board& other)
{
	(*this) = other;
}

/**
 * // Intent:  get the hero
 * // Pre:  None
 * // Post:  Hero& hero
 */
Hero& Board::getHero()
{
	return hero;
}

/**
 * // Intent:  set the hero
 * // Pre:  const Hero& hero
 * // Post:  None
 */
void Board::setHero(const Hero& hero)
{
	this->hero = hero;
}

/**
 * // Intent:  get the creatures vector
 * // Pre:  None
 * // Post:  vector<shared_ptr<Creature>>& creatures
 */
vector<shared_ptr<Creature>>& Board::getCreatures()
{
	return this->creatures;
}

/**
 * // Intent:  set the creatures vector
 * // Pre:  const vector<shared_ptr<Creature>>& creatures
 * // Post:  None
 */
void Board::setCreatures(const vector<shared_ptr<Creature>>& creatures)
{
	this->creatures = creatures;
}

/**
 * // Intent:  get the triggers vector
 * // Pre:  None
 * // Post:  vector<shared_ptr<Trigger>>& triggers
 */
vector<shared_ptr<Item>>& Board::getItems()
{
	return this->items;
}

/**
 * // Intent:  set the triggers vector
 * // Pre:  const vector<shared_ptr<Trigger>>& triggers
 * // Post:  None
 */
void Board::setItems(const vector<shared_ptr<Item>>& items)
{
	this->items = items;
}

/**
 * // Intent:  get the length of the board
 * // Pre:  None
 * // Post:  int length
 */
int Board::getLength()
{
	return (int)board.size();
}

/**
 * // Intent:  get the width of the board
 * // Pre:  None
 * // Post:  int width
 */
int Board::getWidth()
{
	return (int)board[0].size();
}

/**
 * // Intent:  set the board with input vector vector char
 * // Pre:  const vector<vector<char>>& newBoard
 * // Post:  None
 */
void Board::setBoard(const vector<vector<char>>& newBoard)
{
	this->board = newBoard;
}

/**
 * // Intent:  get the board
 * // Pre:  None
 * // Post:  vector<vector<char>>& board
 */
vector<vector<char>>& Board::getBoard()
{
	return this->board;
}

/**
 * // Intent:  check if the position is empty
 * // Pre:  const Position& pos
 * // Post:  true if its empty, false if not
 */
bool Board::isPosEmpty(const Position& pos) {
	return (this->validPos[pos] == false);
}

/**
 * // Intent:  check if the position is valid
 * // Pre:  const Position& pos
 * // Post:  true if its valid, false if not
 */
bool Board::isPosValid(const Position& pos)
{
	return (this->board.at(pos.y).at(pos.x) == NOTHING);
}

/**
 * // Intent:  draw the board with elements
 * // Pre:  None
 * // Post: None
 */
void Board::draw() {
	// copy the board
	vector<vector<char>> drawBoard = this->board;

	// put the triggers on the board
	for (int i = 0; i < TRIGGER_SIZE; i++) {
		Position t = this->items[i]->getPos();
		drawBoard[t.y][t.x] = this->items[i]->getIcon();
	}

	// put the creautures on the board
	for (int i = 0; i < CREATURE_SIZE; i++) {
		Position c = this->creatures[i]->getPos();
		drawBoard[c.y][c.x] = this->creatures[i]->getIcon();
	}

	// put the hero on the board
	Position h = hero.getPos();
	drawBoard[h.y][h.x] = hero.getIcon();

	// print out the board
	for (int i = 0; i < drawBoard.size(); i++) {
		for (int j = 0; j < drawBoard[0].size(); j++) {
			if (drawBoard[i][j] == WALL)
				wcout << "牆";
			else if (drawBoard[i][j] == NOTHING)
				wcout << "  ";
			else if (drawBoard[i][j] == 'H')
				wcout << "英";
			else if (drawBoard[i][j] == 'T')
				wcout << "補";
			else if (drawBoard[i][j] == 'C')
				wcout << "義";
			else if (drawBoard[i][j] == 'W')
				wcout << "蔡";
			else if (drawBoard[i][j] == 'X')
				wcout << "習";
		}
		cout << "\n";
	}
	cout << "______________________________\n";
}

/**
 * // Intent:  make the dungeon map by DFS
 * // Pre:  int length, int width, Position pos, int dir
 * // Post:  None
 */
void Board::dungeonGenerator(int length, int width, Position pos, int dir) {
	Position direction[5] = { {1, 0}, {0, -1} ,{-1, 0}, {0, 1}, {0, 0} };

	// If the range of position is out of range or is wall then return
	if (pos.x < 0 || pos.x >= width || pos.y < 0 || pos.y >= length) return;
	if (this->board[pos.y][pos.x] == WALL) return;

	// If the posistion is unknown then set it is empty icon and set the road of previous position be empty icon too
	if (this->board[pos.y][pos.x] == UNKNOWN) {
		this->board[pos.y][pos.x] = NOTHING;
		this->board[Position(pos - direction[dir]).y][Position(pos - direction[dir]).x] = NOTHING;
	}
	else return; // If the position is been check then return

	int nextDir = rand() % 4; // generate a direction randomly
	dungeonGenerator(length, width, pos + direction[(nextDir + 0) % 4] * 2, (nextDir + 0) % 4); // move to right
	dungeonGenerator(length, width, pos + direction[(nextDir + 1) % 4] * 2, (nextDir + 1) % 4); // move to down
	dungeonGenerator(length, width, pos + direction[(nextDir + 2) % 4] * 2, (nextDir + 2) % 4); // move to left
	dungeonGenerator(length, width, pos + direction[(nextDir + 3) % 4] * 2, (nextDir + 3) % 4); // move to up
}