/************************************************************************
File:   source.cpp

Author:
		���s�Aea5878158@gmail.com
Modifier:
		�௧�N�Acheeryuchi@gmail.com
		���Y���Awindyhuang6@gmail.com
		���T�t�AJYCReports@gmail.com
		���ſ��Atbcey74123@gmail.com
Comment:
		�򥻿�J��V���ʥ\��Aw s a d ���ʸ}��W�U���k�A�ťէ��ܸ}�⯸�ߤ��a�O�r���A��T�W�i�H�W�[�g��
		ESC�O���}�e���C�P�ɧ�s�Ϫ��W����T�C

************************************************************************/

/*  Modifier:
				YAN-RU CHEN ���۾�
				HUAN-KAI XU �\�ٷ_

	Date:	
				May 06, 2023

	Description: 
				Adding the load and save function
				and overloading the operation of Position class
			
*/
#include "main.h"
#include "Hero.h"
#include <vector>
#include <fstream>
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

		if (!(hPos != sPos)) {
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

// �Ψ��x�s�������
char** gBoard;

// �w�q���ؿ�J���O�P�����}�Cindex
enum ValidInput
{
	EW = 0,
	ES = 1,
	EA = 2,
	ED = 3,
	ESPACE = 4,
	EESC = 5,
	ESave = 6,
	ELoad = 7,
	INVALID,
};


Creature gCreature;

// function declare
// ������J���A
void keyUpdate(bool key[]);
// ��l�ƪ���
void setupBoard(int rowN, int colN);
// ��X����
void draw(void);
// ��X������T
void drawInfo(void);

// �{���D�X�ʨ禡
void update(bool key[]);

void saveMap();
void loadMap();

std::vector<Trigger*> gTriggers;

int main(int argc, char** argv)
{
	srand(time(NULL));

	// �ΨӺ޲z��L��J���A���}�C
	bool gKeyState[ValidInput::INVALID];
	for (int i = 0; i < ValidInput::INVALID; i++) {
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

		if (gKeyState[ValidInput::ESave]) {
			saveMap();
			gKeyState[ValidInput::ESave] = false;
		}
		else if (gKeyState[ValidInput::ELoad]) {
			loadMap();
			gKeyState[ValidInput::ELoad] = false;
		}
	}

	system("pause");
	return 0;
}

//******************************************************************
//
// * ������J���A
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
	case '1':
		key[ValidInput::ESave] = true;
		break;
	case '2':
		key[ValidInput::ELoad] = true;
		break;
	default:
		break;
	}
}

//******************************************************************
//
// * �P�_��m�O�_����
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
// * �Q�� call-by-referce �N�p��o�쪺��V�^��
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
		if (cPos + dir * count == hPos) {
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

	gBoard = new char* [rowN];
	for (int i = 0; i < rowN; i++) {
		gBoard[i] = new char[colN];
		for (int j = 0; j < colN; j++) {
			if (i == 0 || i == rowN - 1 || j == 0 || j == colN - 1)
				gBoard[i][j] = GWALL;
			else
				gBoard[i][j] = GNOTHING;
		}
	}

	// Setup for (random) position of all elements and implementation of game board using 2d dynamic array
	// Elements has to be randomly generated within canvas

	std::vector<std::vector<bool>> validFlags(GHEIGHT);
	for (int i = 0; i < GHEIGHT; i++) {
		validFlags[i].resize(GWIDTH);
		for (int j = 0; j < GWIDTH; j++) {
			validFlags[i][j] = gBoard[i][j] == GWALL ? false : true;
		}
	}

	auto getRandomPos = [&rowN, &colN]() {
		return Position((int)(rand() % colN), (int)(rand() % rowN));
	};

	auto getValidRandomPos = [&validFlags, &getRandomPos]() {
		while (true) {
			Position pos = getRandomPos();
			if (validFlags[pos.y][pos.x]) {
				return pos;
			}
		}
	};

	Position hPos = getValidRandomPos();
	validFlags[hPos.y][hPos.x] = false;
	gHero.setPos(hPos);

	Position cPos = getValidRandomPos();
	validFlags[cPos.y][cPos.x] = false;
	gCreature.setPos(cPos);

	for (int i = 0; i < 2; i++) {
		Trigger* trigger = new Trigger();
		Position tPos = getValidRandomPos();
		validFlags[tPos.y][tPos.x] = false;
		trigger->setPos(tPos);
		gTriggers.push_back(trigger);
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
	// Setup and implementation of drawing board using 2d vector

	std::vector<std::vector<char>> drawBoard(GHEIGHT);

	for (int i = 0; i < GHEIGHT; i++) {
		drawBoard[i].resize(GWIDTH);
		for (int j = 0; j < GWIDTH; j++) {
			drawBoard[i][j] = gBoard[i][j];
		}
	}

	// Draw two triggers using for loop on drawBoard

	for (int i = 0; i < gTriggers.size(); i++) {
		Position t = gTriggers[i]->getPos();
		drawBoard[t.y][t.x] = gTriggers[i]->getIcon();
	}

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
	std::cout << "(ESC) Exit (1) Save (2) Load" << std::endl;
}

//******************************************************************
//
// * Update the board state
//==================================================================
void update(bool key[])
//==================================================================
{
	// �M������
	system("CLS");

	Position delta;

	// �O�_��input
	bool hasInput = false;
	if (key[ValidInput::EW]) {
		delta -= Position(0, 1);
		hasInput = true;
	}
	else if (key[ValidInput::ES]) {
		delta += Position(0, 1);
		hasInput = true;
	}
	else if (key[ValidInput::EA]) {
		delta = delta - Position(1, 0);
		hasInput = true;
	}
	else if (key[ValidInput::ED]) {
		delta = delta + Position(1, 0);
		hasInput = true;
	}
	else {
		bool allInvalid = true;
		for (int i = 0; i < ValidInput::INVALID; i++) {
			if (key[i]) {
				allInvalid = false;
				break;
			}
		}
		if (allInvalid)
			std::cout << "invalid input\n";
	}
	if (hasInput) {
		gHero.move(delta);
	}

	// Manipulate update of two triggers using while loop

	for (int i = 0; i < gTriggers.size(); i++) {
		gTriggers[i]->update(gHero);
	}

	gCreature.update(gHero);
	draw();
	drawInfo();
}

//******************************************************************
//
// * Save the map status
//==================================================================
void saveMap() {
	// Save dungen to file
	/*Please implement your code here*/

	// Clear the screen.
	system("CLS"); 

	// Print the title message.
	std::cout << "Input file name for saving or Exit to leave saving.\n";

	// Input the path of the file to save 
	std::string filePath;
	std::cin >> filePath;

	// If the input file is "Exit" then exit the save mode
	if (filePath == "Exit") return;
	
	// Open the file that is the destination to save the board and informations
	std::ofstream saveFile("./saveFile/" + filePath + ".txt");

	// Save ths information of canva
	saveFile << "Canva:\n";
	saveFile << "(row,column): " << GWIDTH << ' ' << GHEIGHT << '\n';
	// Modify the output stream to be the file stream and draw the canva to the file
	auto coutStream = std::cout.rdbuf(); 
	std::cout.rdbuf(saveFile.rdbuf());
	draw();
	saveFile << "\n";
	// Change the output stream to the origin std::cout
	std::cout.rdbuf(coutStream); 

	// Save the information of gHero
	saveFile << "Hero:\n";
	saveFile << "Pos(x,y): " << gHero.getPos() << '\n'; // Save the position
	saveFile << "Hp: " << gHero.getHP() << '\n'; // Save the HP
	saveFile << "Lv: " << gHero.getLevel() << '\n'; // Save the level
	saveFile << "Exp: " << gHero.getExp() << '\n'; // Save the exp
	saveFile << "Exp to next level: " << gHero.getMaxExp() << '\n'; // Save need how much exp to the next level
	saveFile << '\n';

	// Save the information of the creature
	saveFile << "Creature:\n";
	saveFile << "Pos(x,y): " << gCreature.getPos() << '\n'; // Save position
	saveFile << '\n';

	// Save the information of triggers
	saveFile << "Triggers:\n";
	saveFile << "Amounts: " << gTriggers.size() << '\n'; // Save the amounts of triggers
	saveFile << "Pos(x,y):\n"; // Save each triggers's position
	for (int i = 0; i < gTriggers.size(); i++) {
		saveFile << "triggers" << i + 1 << ": " << gTriggers[i]->getPos() << '\n';
	}
	saveFile << '\n';

	// Close read file mode
	saveFile.close();
	/************************************************************************/
}

//******************************************************************
//
// * Load the map status
//==================================================================
void loadMap() {
	// Load from file and reset the dungen
	/*Please implement your code here*/

	// Clear the screen
	system("CLS");

	// Print the title message
	std::cout << "Input file name for loading or Exit to leave loading.\n";

	// Read the file path
	std::string filePath;
	std::cin >> filePath;

	// If the file path is "Exit" then close the loading mode
	if (filePath == "Exit") return;

	// Load the file of the save file
	std::ifstream loadFile("./saveFile/" + filePath + ".txt");

	// Read the information of canva from the save file
	loadFile.ignore(strlen("Canva:\n"));
	loadFile.ignore(strlen("(row,column): "));
	loadFile >> GWIDTH >> GHEIGHT; // Load the width and height of the canva
	setupBoard(GHEIGHT, GWIDTH); // Set the board

	// Ignore the picture of the board
	for (int i = 0; i < GHEIGHT; i++) {
		loadFile.ignore(GWIDTH + 1);
	}
	loadFile.ignore(1);

	// Load the information of the hero
	loadFile.ignore(strlen("Hero:\n"));
	loadFile.ignore(strlen("Pos(x,y): "));
	int hp, level, exp, maxExp;

	// Load the position of the gHero
	Position heroPos;
	loadFile >> heroPos;
	gHero.setPos(heroPos);

	// Load the HP of the gHero
	loadFile.ignore(strlen("HP: "));
	loadFile >> hp;
	gHero.setHP(hp);

	// Load the level of the gHero
	loadFile.ignore(strlen("Lv: "));
	loadFile >> level;
	gHero.setLevel(level);

	// Load the Exp of the gHero
	loadFile.ignore(strlen("Exp: "));
	loadFile >> exp;
	gHero.setExp(exp);

	// Load the maxExp of the gHero
	loadFile.ignore(strlen("Exp to next level: "));
	loadFile >> maxExp;
	gHero.SetMaxExp(maxExp);
	loadFile.ignore(1);

	// Read the information of the creature
	loadFile.ignore(strlen("Creature:\n"));
	loadFile.ignore(strlen("Pos(x,y): "));
	Position creaturePos;
	loadFile >> creaturePos; // Load the position of the creature
	gCreature.setPos(creaturePos); // Set the position of the creature
	loadFile.ignore(1);

	// Read the information of triggers
	loadFile.ignore(strlen("Triggers:\n"));
	loadFile.ignore(strlen("Amounts: "));
	int amounts;
	loadFile >> amounts; // Load the amounts of triggers

	// Load the position of triggers
	loadFile.ignore(strlen("Pos(x,y):\n"));
	gTriggers.clear(); // Clear the gTriggers vector
	for (int i = 0; i < amounts; i++) {
		loadFile.ignore(strlen("triggersx: "));
		Position triggerPos;
		loadFile >> triggerPos; // Load the position
		
		// Record the new trigger's position to the gTriggers vector
		gTriggers.emplace_back(new Trigger(triggerPos.x, triggerPos.y));
	}

	// Close the loading mode
	loadFile.close();
	/************************************************************************/
}
