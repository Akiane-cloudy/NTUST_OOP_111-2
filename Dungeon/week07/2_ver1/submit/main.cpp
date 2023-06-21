/************************************************************************
File:   source.cpp

Author:
		鍾賢廣，ea5878158@gmail.com
Modifier:
		賴祐吉，cheeryuchi@gmail.com
		黃欣云，windyhuang6@gmail.com
		陳俊宇，JYCReports@gmail.com
		邱嘉興，tbcey74123@gmail.com
Comment:
		基本輸入方向移動功能，w s a d 移動腳色上下左右，空白改變腳色站立之地板字元，到T上可以增加經驗
		ESC是離開畫面。同時更新圖版上的資訊。

************************************************************************/

// Modifier: 許桓愷B11115008, 陳彥儒B11115004
// Last_Update: April 22, 2023
// Comment: 基本輸入方向移動功能，w s a d 移動腳色上下左右，空白改變腳色站立之地板字元，到T上可以增加經驗
//			ESC是離開畫面。同時更新圖版上的資訊。

#include "main.h"
#include "Hero.h"
#include <vector>
Hero	 gHero(2, 2);

using namespace std;

class Creature {//creature class 
private:
	Position	sPos;			// Creature position
	char sIcon = 'C';			// Creature icon
	int power;
public:
	// Default constructor
	Creature(void) {
		this->sPos.x = 1;
		this->sPos.y = 1;
		this->sIcon = 'C';
		this->power = 5;
	};

	// Set position
	void setPos(Position pos) { this->sPos = pos; }
	void setPos(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
	}

	// Set icon
	void setIcon(char& icon) { this->sIcon = icon; }

	// Get position
	Position getPos(void) { return this->sPos; }

	// Get Icon
	char getIcon(void) { return this->sIcon; }

public:
	void update(Hero& hero) {
		Position hPos = hero.getPos();

		Position dir;
		if (canSee(this->sPos, hPos, dir)) {
			std::cout << "Creature has find the Hero in the ( " << dir.x << ", " << dir.y << " ) direction\n";
			this->sIcon = '!';
		}
		else {
			std::cout << "Creature didn't find the Hero\n";
			this->sIcon = 'C';
		}

		if (hPos.x == sPos.x && hPos.y == sPos.y) {
			hero.damage(power);
		}
	}
};

// Constent value
const char GWALL = 'O';
const char GNOTHING = ' ';

int GWIDTH = -1;
int GHEIGHT = -1;
const int MIN_SIZE = 4;
const double gTimeLog = 0.033;

// Distance
const int gDistance = 4;

// 用來儲存版面資料
char** gBoard;

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


Creature gCreature;

// function declare
// 偵測輸入狀態
void keyUpdate(bool key[]);
// 初始化版面
void setupBoard(int rowN, int colN);
// 輸出版面
void draw(void);
// 輸出說明資訊
void drawInfo(void);

// 程式主驅動函式
void update(bool key[]);

// Create vector of trigger pointer for further managenent and manipulation
/*Please implement your code here*/

// use gTrigger Trigger pointer vector to store all the trigger
vector<Trigger*> gTrigger (2);
/************************************************************************/

int main(int argc, char** argv)
{
	srand(time(NULL));

	// 用來管理鍵盤輸入狀態的陣列
	bool gKeyState[6];
	for (int i = 0; i < 6; i++) {
		gKeyState[i] = false;
	}

	while (true) {
		std::cout << "Enter Width: ";
		std::cin >> GWIDTH;
		std::cout << "Enter Height: ";
		std::cin >> GHEIGHT;
		system("CLS");
		if (GHEIGHT < MIN_SIZE || GWIDTH < MIN_SIZE) {
			std::cout << "Illegal, both has to be larger than " << MIN_SIZE << std::endl;
		}
		else {
			break;
		}
	}

	// Setup a clear dungeon
	setupBoard(GHEIGHT, GWIDTH);

	// Draw the bord and information
	draw();
	drawInfo();

	// Variable for game loop
	clock_t startT, endT;
	startT = clock();
	endT = clock();

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
// * 利用 call-by-referce 將計算得到的方向回傳
//==================================================================
bool canSee(Position cPos, Position hPos, Position& dir)
//==================================================================
{
	// the dir_x and dir_y value are call-by-refernce
	dir.x = (int)clip((float)(hPos.x - cPos.x), -1.f, 1.f); // clip the value between -1 ~ 1
	dir.y = (int)clip((float)(hPos.y - cPos.y), -1.f, 1.f);
	int count = 0;
	do {
		// spot the target position
		if (cPos.x + dir.x * count == hPos.x &&
			cPos.y + dir.y * count == hPos.y) {
			return true;
		}
		count++;
	} while (count < gDistance); // check the range in 4 units
	return false;
}

//******************************************************************
//
// * Setup the board
//==================================================================
void setupBoard(int rowN, int colN)
//==================================================================
{
	// Allocate & init game board using 2d dynamic array
	/*Please implement your code here*/

	// make an array with pointers which length is rowN
	gBoard = new char* [rowN];

	// for each pointer in gBoard
	for (int i = 0; i < rowN; i++) {
		// point at a new char array which length is colN
		gBoard[i] = new char[colN];
	}

	// initialize the board with GWALL and GNOTHING
	// for each elements in gBoard
	for (int i = 0; i < rowN; i++) {
		for (int j = 0; j < colN; j++) {
			// if the position right now is the edge of the board
			if (i == 0 || j == 0 || i == rowN - 1 || j == colN - 1) {
				// set the icon to GWALL
				gBoard[i][j] = GWALL;
			}
			else {
				// if it's not the edge of the board, set the icon to GNOTHING
				gBoard[i][j] = GNOTHING;
			}
		}
	}
	/************************************************************************/

	// Setup for (random) position of all elements and implementation of game board using 2d dynamic array
	// Elements has to be randomly generated within canvas
	// Two triggers should also be initialized and pushed to the container here.
	/*Please implement your code here*/

	// use a Position variable to store the random position
	Position randomPos;

	// get random pos for creature
	// keep random until the position is valid (equel to GNOTHING)
	do {
		randomPos = { rand() % rowN , rand() % colN };
	} while (!isPositionValid(randomPos));

	// set the position of creature to random position
	gCreature.setPos(randomPos);
	// change the icon in gBoard in creature's position
	gBoard[randomPos.y][randomPos.x] = gCreature.getIcon();

	// for each trigger
	for (int i = 0; i < (int)gTrigger.size(); i++) {
		// make a trigger pointer which point at a Trigger object
		Trigger* triggerPtr = new Trigger;

		// put it into the gTrigger vector
		gTrigger[i] = triggerPtr;

		// get the random position of trigger
		// until the position is valid (equel to GNOTHING)
		do {
			randomPos = { rand() % rowN, rand() % colN };
		} while (!isPositionValid(randomPos));

		// set the position of trigger
		gTrigger[i]->setPos(randomPos);

		// change the icon in gBoard in trigger's position
		gBoard[randomPos.y][randomPos.x] = gTrigger[i]->getIcon();
	}

	// clean the icon of creature and trigger
	// because the hero is able to cover the creature and trigger
	// get the position of creature 
	Position creaturePos = gCreature.getPos();
	// set the icon of the position to GNOTHING
	gBoard[creaturePos.y][creaturePos.x] = GNOTHING;

	// clean trigger icon in gBoard
	// for each trigger
	for (int i = 0; i < (int)gTrigger.size(); i++) {
		// get the position of trigger
		Position triggerPos = gTrigger[i]->getPos();

		// set the icon of the position to GNOTHING
		gBoard[triggerPos.y][triggerPos.x] = GNOTHING;
	}
	/************************************************************************/
}

//******************************************************************
//
// * Draw the board
//==================================================================
void draw()
//==================================================================
{
	// Add the hero into the board
	// Setup and implementation of drawing board using 2d vector
	/*Please implement your code here*/

	// use a 2D char vector to store the board
	vector<vector<char> > drawBoard (GHEIGHT, vector<char>(GWIDTH));

	// get the imformation from gBoard and store into draw board
	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			drawBoard[i][j] = gBoard[i][j];
		}
	}
	/************************************************************************/

	// Draw two triggers using for loop on drawBoard
	/*Please implement your code here*/

	// add the trigger icon into drawBoard
	for (int i = 0; i < (int)gTrigger.size(); i++) {
		Position triggerPos = gTrigger[i]->getPos();

		drawBoard[triggerPos.y][triggerPos.x] = gTrigger[i]->getIcon();
	}
	/************************************************************************/

	// add the creature icon into drawBoard
	Position c = gCreature.getPos();
	drawBoard[c.y][c.x] = gCreature.getIcon();

	// Update the hero information
	Position h = gHero.getPos();
	drawBoard[h.y][h.x] = gHero.getIcon();

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
	std::cout << "The hero is level " << gHero.getLevel() << "(" << gHero.getExp() << "/" << gHero.getMaxExp() << " to level up)" << std::endl;
	std::cout << "The hero has " << gHero.getHP() << " hp" << std::endl;
	std::cout << "Use wsad key to move Hero " << gHero.getIcon() << std::endl;
	std::cout << "Every time you step on a trigger T, the hero gets 10 exp." << std::endl;
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

	// Manipulate update of two triggers using while loop
	/*Please implement your code here*/

	// using while loop to update
	int i = 0;
	while (i < (int)gTrigger.size()) {
		gTrigger[i++]->update(gHero);
	}
	/************************************************************************/

	gCreature.update(gHero);
	draw();
	drawInfo();
}
