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

// Modifier: 陳彥儒:B11115004, 許桓愷:B11115008
// Last Update: April 11, 2023
// Comment: use the input command to move the hero

#include "main.h"
#include "Hero.h"
Hero	 gHero(2, 2);



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
	EJUMP,
	INVALID,
};


Creature gCreature;

// function declare
// 偵測輸入狀態
void keyUpdate(bool key[]);
// 初始化版面
void setupBoard();
// 輸出版面
void draw(void);
// 輸出說明資訊
void drawInfo(void);

// 程式主驅動函式
void update(bool key[]);

Trigger gTrigger(5, 5, 10);
int globalJumpX, globalJumpY;

int main(int argc, char** argv)
{
	srand(time(NULL));

	// 用來管理鍵盤輸入狀態的陣列, 大小為7
	bool gKeyState[7]; 
	for (int i = 0; i < 7; i++) {
		gKeyState[i] = false;
	}

	// Setup a clear dungeon
	setupBoard();

	gCreature.setPos(5, 6);

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

	ValidInput inputType = ValidInput::INVALID;
	int jumpX = 0, jumpY = 0;

	// Read from input and parse to operation
	/*Please implement your code here*/
	std::string input; // declare a string to get the input command and its infor
	std::getline(std::cin, input); // get a line of string

	std::stringstream inputStream(input); // let the input be a stream
	std::string command, information; // declare two string variables to get the command and its information
	inputStream >> command >> information; // get the command and information from the input stream
	
	// if the input is only have '\0' it mean the input is enter
	// so if the input is not just a enter, then continue to do the compare
	if (command[0] != '\0')
	{

		std::stringstream inforStream(information); // let the information be a stream
		char c; // use to get the '(' ','  ')' char
		int destinationX, destinationY; // the x and y of the destination
		inforStream >> c >> destinationX >> c >> destinationY >> c; // get the input destination

		// check if the destination is valid
		bool isXValid = (destinationX >= 0 && destinationX < GWIDTH); 
		bool isYValid = (destinationY >= 0 && destinationY < GHEIGHT); 

		if (command == "Move") // check if the command is move
		{
			if (isXValid && isYValid) // check if the destination is valid
			{
				int heroX = gHero.getPos().x; // get the hero's x of position
				int heroY = gHero.getPos().y; // get the hero's y of position

				// get the distance of hero and destination
				int distanceX = (heroX - destinationX);  
				int distanceY = (heroY - destinationY);

				// if the desination is near the hero (absolute distance is 1), then do moving
				if (distanceX + distanceY == 1 || distanceX + distanceY == -1)
				{
					if (distanceX != 0) // if distanceX != 0 that means the delta is x
					{
						// if distanceX is 1 then move left otherwise is move right
						inputType = (distanceX == 1) ? ValidInput::EA : ValidInput::ED;
					}
					else // if distanceY != 0 that means the delta is y
					{
						// if distanceY is 1 then moving to up otherwise is moving to down
						inputType = (distanceY == 1) ? ValidInput::EW : ValidInput::ES;
					}
				}
			}
		}
		else if (command == "Jump") // the Jump command
		{
			if (isXValid && isYValid) // check if the destination is valid
			{
				// set the jump value
				jumpX = destinationX;
				jumpY = destinationY;
				inputType = ValidInput::EJUMP; // set the inputType to jump
			}
		}
		else if (command == "Exit") // the Exit command
		{
			inputType = ValidInput::EESC; // set the inputType to ESC
		}
		else // the input is not follow the form, them get the last char to move
		{
			char dir = input[input.size() - 1]; // get the last char from the input
			switch (dir)
			{
				// if last char is 'w' or 'W' then set the inputType to w
			case 'w':
			case 'W':
				inputType = ValidInput::EW;
				break;
				// if last char is 'a' or 'A' then set the inputType to a
			case 'a':
			case 'A':
				inputType = ValidInput::EA;
				break;
				// if last char is 's' or 'S' then set the inputType to s
			case 's':
			case 'S':
				inputType = ValidInput::ES;
				break;
				// if last char is 'd' or 'D' then set the inputType to d
			case 'd':
			case 'D':
				inputType = ValidInput::ED;
				break;
			}
		}
	}
	/************************************************************************/

	if (inputType == ValidInput::EW) {
		key[ValidInput::EW] = true;
	}
	else if (inputType == ValidInput::EA) {
		key[ValidInput::EA] = true;
	}
	else if (inputType == ValidInput::ES) {
		key[ValidInput::ES] = true;
	}
	else if (inputType == ValidInput::ED) {
		key[ValidInput::ED] = true;
	}
	else if (inputType == ValidInput::EESC) {
		key[ValidInput::EESC] = true;
	}
	else if (inputType == ValidInput::EJUMP) {
		key[ValidInput::EJUMP] = true;
		globalJumpX = jumpX;
		globalJumpY = jumpY;
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

	Position t = gTrigger.getPos();
	drawBoard[t.y][t.x] = gTrigger.getIcon();

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
	std::cout << "Every time you step on a trigger T, the hero gets " << gTrigger.getExpAmount() << " EXP points" << std::endl;
	std::cout << "Type Exit to exit" << std::endl;
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
	else if (key[ValidInput::EJUMP]) {
		gHero.jump(globalJumpX, globalJumpY);
		hasInput = true;
	}
	else {
		std::cout << "invalid input\n";
	}
	gTrigger.update(gHero);
	gCreature.update(gHero);
	draw();
	drawInfo();
}
