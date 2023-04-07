/************************************************************************
File:   Source.cpp

Author:
		鍾賢廣，ea5878158@gmail.com
Modifier:
		賴祐吉，cheeryuchi@gmail.com
		陳俊宇，JYCReports@gmail.com
		邱嘉興，tbcey74123@gmail.com
Comment:
		基本輸入方向移動功能，w s a d 移動腳色上下左右，空白改變腳色站立之地板字元，
		ESC是離開畫面。同時更新圖版上的資訊。

************************************************************************/

/************************************************************************
Name: 陳彥儒 B11115004, 許桓愷 B11115008

Date: March 21, 2023

Last Update: March 24, 2023

Comment:
		基本輸入方向移動功能，w s a d 移動腳色上下左右，空白改變腳色站立之地板字元，
		ESC是離開畫面。同時更新圖版上的資訊。

************************************************************************/

#include <iostream>
#include <math.h>		// pow() and sqrt()
#include <ctime>		// for time loop function
#include <conio.h>		// _getch() <= to read input without enter "ENTER" key
#include <algorithm>	// for max and min function

//************************************************************
// The location in the board
//************************************************************
struct Position {
	int x; // X, y Coordinate
	int y;
};

// Check whether the location is a valid one i.e. not a wall
bool isPositionValid(Position& loc);

//************************************************************
// Hero Class, only has requirement part for example
//************************************************************
class Hero {
private:
	Position	sPos;			// Hero location
	char sIcon = 'H';	// Hero icon

public:
	// Default constructor
	// set this hero position to (0,0)
	// and set hero's icon to 'H'
	Hero() {
		this->sPos.x = 0; 
		this->sPos.y = 0;
		this->sIcon = 'H';
	};

	// Set position
	void setPos(Position pos) { this->sPos = pos; } // set the hero's position to the parameter pos
	void setPos(int x, int y) {
		this->sPos.x = x; // set the x coordinate to the parameter x
		this->sPos.y = y; // set the y coordinate to the parameter y
	}

	// Set icon
	void setIcon(char& icon) { this->sIcon = icon; } // set the hero's icon to the parameter icon

	// Get position
	Position getPos(void) { return this->sPos; }

	// Get Icon
	char getIcon(void) { return this->sIcon; }

	// Incrementally move the elements 
	// Intent: move the hero's position if then move is valid 
	// pre: the deltaX and deltaY must have value
	// post: modify the hero's position if the position is valid
	void move(int deltaX, int deltaY) {
		// Implement Hero controls
		/*Please implement your code here*/
		Position temp = this->sPos; // create a Position class temp and set it same to this hero position
		temp.x += deltaX; // let the x plus the deltaX
		temp.y += deltaY; // let the y plus the deltaY

		// if the temp is valid to move, then change the hero's position to temp
		// else don't do anything
		if (isPositionValid(temp) == true)
		{
			this->sPos = temp; // modify the hero's position
		}
		/************************************************************************/
	}
};

// clip algroithm
float clip(float n, float minimun, float maximum);
// 判斷 hero 是否在 creature 的視線範圍內
bool isCreatureSeeTheHero(const Position& heroPos, const Position& creaturePos);

// the creature class
class Creature {

	// Implement Creature Class
	/*Please implement your code here*/
private:
	Position creaturePos; // the creature present position
	char creatureIcon; // the creature icon

public :
	// the defalt constuctor of Creature class 
	// set the creature's x y coordinate of position to (0,0)
	// and set it's icon to be '@'
	Creature()
	{
		this->creaturePos.x = 0;
		this->creaturePos.y = 0;
		this->creatureIcon = '@';
	}

	// Intent: set the creature position to the specified location
	// pre: the pos must exist
	// post: modify the creature' position to the parameter pos
	void setPos(const Position &pos)
	{
		this->creaturePos = pos;
	}

	// Intent: set the creature position to the specified location
	// pre: the x and y must exist
	// post: modify the creature' position to the parameter x and y
	void setPos(const int &x, const int &y)
	{
		this->creaturePos.x = x;
		this->creaturePos.y = y;
	}

	// Intent: set the creature's icon to the specified symbol
	// pre: the symbol must exist
	// post: modify the creature' icon to the parameter icon
	void setIcon(const char& icon)
	{
		this->creatureIcon = icon;
	}

	// Intent: get the creature current position
	// return: the current position of the creature
	Position getPos()
	{
		return this->creaturePos;
	}

	// Intent: get the creature current icon
	// return: the current icon of the creature
	char getIcon()
	{
		return this->creatureIcon;
	}

	// Intent: update the creature's position, it will modify its position
	//         depending on the hero's position, if the creature can see the hero
	//         then creature will move toward him, else random move
	// pre: need the hero's position
	// post: update the creature's position
	void update(const Position& heroPos) {
		if (isCreatureSeeTheHero(heroPos, this->creaturePos) == true) {
			// declare the distanceX to the absolute value of hero and creature of their x coordinate
			int distanceX = abs(heroPos.x - this->creaturePos.x);
			// declare the distanceY to the absolute value of hero and creature of their y coordinate
			int distanceY = abs(heroPos.y - this->creaturePos.y);
			// declare the deltaX to an unit vector of x 
			int deltaX = (distanceX == 0) ? 0 : (heroPos.x - this->creaturePos.x) / distanceX;
			// declare the deltaY to an unit vector of y
			int deltaY = (distanceY == 0) ? 0 : (heroPos.y - this->creaturePos.y) / distanceY;
			// declare a temp position to copy the current creature's position
			Position temp = this->creaturePos;

			// if distanceX is larger than distanceY, then temp's x plus the deltaX
			if (distanceX > distanceY)
			{
				temp.x += deltaX;
			}
			else if (distanceX < distanceY) // if distanceY is larger than distanceX, then temp's y plus the deltaY
			{
				temp.y += deltaY;
			}
			else // if distanceX is equal to distanceY then plus deltaX or deltaY randomly
			{
				if (rand() % 2) // random pick one direction to move
				{
					temp.x += deltaX; // move x coordinate
				}
				else
				{
					temp.y += deltaY; // move y coordinate
				}
			}

			if (isPositionValid(temp) == true) // if the temp's position is valid then modify the original creature's position to temp
			{
				this->creaturePos = temp; // modify the position of creature
			}
		}
		else
		{
			// if this case is the creature didn't see the hero, so it will move randomly
			// here we declare 4 direction to move: right, down, left and up
			int deltaXY[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
			// declare a temp position to try if the position is valid 
			Position temp;
			
			do {
				temp = this->creaturePos; // initial the temp to be the current creature's position
				int randomDirection = rand() % 4; // pick one direction randomly

				temp.x += deltaXY[randomDirection][0]; // move the x coordinate about the deltaXY
				temp.y += deltaXY[randomDirection][1]; // move the y coordinate about the deltaXY
			} while (isPositionValid(temp) == false); // the loop will continue until the position is valid to move

			this->creaturePos = temp; // modify the current position to the temp
 		}
	}
	/************************************************************************/
};

// Constent value
const char GWALL = 'O';
const char GNOTHING = ' ';

const int GWIDTH = 10;
const int GHEIGHT = 10;
const double gTimeLog = 0.033;

// Distance
const int gDistance = 4;

// 用來儲存版面資料
char gBoard[GHEIGHT][GWIDTH];

// 定義六種輸入指令與對應陣列index
enum ValidInput
{
	EW = 0,
	ES = 1,
	EA = 2,
	ED = 3,
	ESPACE = 4,
	EESC = 5,
	INVALID,
};

Hero gHero;
Creature gCreature;

// function declare
// 偵測輸入狀態
void keyUpdate(bool key[]);
// 判斷位置是否為空
bool isPositionValid(Position& loc);
// 初始化版面
void setupBoard();
// 輸出版面
void draw(void);
// 輸出說明資訊
void drawInfo(void);
// 判斷 hero 是否在 creature 的視線範圍內
bool isCreatureSeeTheHero(const Position& heroPos, const Position& creaturePos);

// 程式主驅動函式
void update(bool key[]);

int main(int argc, char** argv)
{
	srand(time(NULL));

	// 用來管理鍵盤輸入狀態的陣列
	bool gKeyState[6];

	// Setup a clear dungeon
	setupBoard();

	// Set the position of Hero
	gHero.setPos(2, 2);

	gCreature.setPos(5, 6);

	// Draw the bord and information
	draw();
	drawInfo();

	// Variable for game loop
	clock_t startT, endT;
	startT = clock();
	endT = clock();

	// Get the press key
	keyUpdate(gKeyState);

	// Run the game loop
	while (!gKeyState[ValidInput::EESC]) {
		// Compute the time lap
		double timeFrame = (double)(endT - startT) / CLOCKS_PER_SEC;

		// Execute the game loop
		if (timeFrame >= gTimeLog) {
			update(gKeyState);
			startT = clock();
		}

		// Update the key
		keyUpdate(gKeyState);
		endT = clock();
	}

	system("pause");
	return 0;
}

//******************************************************************
//
// * 偵測輸入狀態
//==================================================================
void keyUpdate(bool key[])
//==================================================================
{
	for (int i = 0; i < ValidInput::INVALID; i++) {
		key[i] = false;
	}
	char input = _getch();
	switch (input) {
	case 'w':
		key[ValidInput::EW] = true;
		break;
	case 's':
		key[ValidInput::ES] = true;
		break;
	case 'a':
		key[ValidInput::EA] = true;
		break;
	case 'd':
		key[ValidInput::ED] = true;
		break;
	case ' ':
		key[ValidInput::ESPACE] = true;
		break;
	case 27:
		key[ValidInput::EESC] = true;
		break;
	default:
		break;
	}
}

//******************************************************************
//
// * 判斷位置是否為空
//==================================================================
bool isPositionValid(Position& pos)
//==================================================================
{
	// Check whether it is an empty space
	if (gBoard[pos.y][pos.x] != GNOTHING)
		return false;

	if (pos.x == gHero.getPos().x && pos.y == gHero.getPos().y)
		return false;

	if (pos.x == gCreature.getPos().x && pos.y == gCreature.getPos().y)
		return false;

	return true;
}

//******************************************************************
//
// * clip algroithm
//==================================================================
float clip(float n, float minimun, float maximum)
//==================================================================
{
	return std::max(minimun, std::min(n, maximum));
}

//******************************************************************
//
// * Setup the board
//==================================================================
void setupBoard()
//==================================================================
{
	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			if (i == 0 || i == GHEIGHT - 1) {
				gBoard[i][j] = GWALL;
			}
			else if (j == 0 || j == GWIDTH - 1) {
				gBoard[i][j] = GWALL;
			}
			else {
				gBoard[i][j] = GNOTHING;
			}
		}
	}
}

//******************************************************************
//
// * Draw the board
//==================================================================
void draw()
//==================================================================
{
	// Add the hero into the board
	char drawBoard[GHEIGHT][GWIDTH];

	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			drawBoard[i][j] = gBoard[i][j];
		}
	}

	// Update the hero information
	Position h = gHero.getPos();
	drawBoard[h.y][h.x] = gHero.getIcon();

	Position c = gCreature.getPos();
	drawBoard[c.y][c.x] = gCreature.getIcon();

	// Draw the board
	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			std::cout << drawBoard[i][j]; //  output
		}
		std::cout << "\n";
	}
}

//******************************************************************
//
// * Output information
//==================================================================
void drawInfo(void)
//==================================================================
{
	// Print Outputs
	/*Please implement your code here*/
	// if the creature can see the hero then print out "Creature found Hero!"
	if (isCreatureSeeTheHero(gHero.getPos(), gCreature.getPos()) == true)
	{
		std::cout << "Creature found Hero!" << std::endl;
	}
	/************************************************************************/

	std::cout << "Use wsad key to move Hero " << gHero.getIcon() << std::endl;
	std::cout << "Press ESC key to exit" << std::endl;
}

//******************************************************************
//
// * Update the board state
//==================================================================
void update(bool key[])
//==================================================================
{
	// 清除版面
	system("CLS");

	// 是否有input
	bool hasInput = false;
	if (key[ValidInput::EW]) {
		gHero.move(0, -1);
		hasInput = true;
	}
	else if (key[ValidInput::ES]) {
		gHero.move(0, 1);
		hasInput = true;
	}
	else if (key[ValidInput::EA]) {
		gHero.move(-1, 0);
		hasInput = true;
	}
	else if (key[ValidInput::ED]) {
		gHero.move(1, 0);
		hasInput = true;
	}
	else {
		std::cout << "invalid input\n";
	}
	//Calculate and Initiate Move
	gCreature.update(gHero.getPos());
	draw();
	drawInfo();
}

/**
 * Intent : 判斷 hero 是否在 creature 的視線範圍內
 * pre : none
 * post : return whether the creature can see the hero
 * parameter : heroPos
 * return : return whether the creature can see the hero
 */
bool isCreatureSeeTheHero(const Position& heroPos, const Position& creaturePos) {
	int distanceX = abs(heroPos.x - creaturePos.x); // declare the distanceX to the absolute distance of hero and creature
	int distanceY = abs(heroPos.y - creaturePos.y); // declare the distanceY to the absolute distance of hero and creature

	// if the distanceX and distanceY is smaller than 3, then return true
	// that mean the creature finds the hero
	if (distanceX <= 2 && distanceY <= 2)
	{
		return true;
	}
	
	return false; // else isn't see the hero, return false
}
