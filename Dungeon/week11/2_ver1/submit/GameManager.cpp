/*****************************************************************//**
 * File: GameManager.cpp
 * Author: 許桓愷 (B11115008@mail.ntust.edu.tw)
 *		   陳彥儒 (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: 許桓愷 (B11115008@mail.ntust.edu.tw)
 *		   陳彥儒 (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-21
 * Description:  The GameManager cpp file
 *********************************************************************/
#include "GameManager.h"

 /**
  * // Intent:  set a board with input size
  * // Pre:  int length, int width
  * // Post:  None
  */
GameManager::GameManager(int length, int width)
{
	// set the board to input size
	this->board = Board(length, width);
	// initialize the game state to playing
	this->gameState = GAME_STATE::PLAYING;
}

/**
 * // Intent:  move the hero with input direction
 * // Pre:  const Position& delta
 * // Post:  true if move success, false if not
 */
bool GameManager::move(const Position& delta)
{
	// get the hero in the board
	Hero& hero = board.getHero();
	// get the position which hero going to move to
	Position nextPos = hero.getPos() + delta;

	// if the new position is valid
	if (this->board.isPosValid(nextPos)) {
		// set hero's position to the new position
		hero.setPos(nextPos);
		return true;
	}

	// if the position is not valid
	return false;
}

/**
 * // Intent:  update the information of all elements on the board
 * // Pre:  None
 * // Post:  None
 */
void GameManager::update()
{
	// use a pointer vector to store all the creatures' data
	vector<shared_ptr<Creature>> creatures = this->board.getCreatures();
	// use a pointer vector to store all the triggers' data
	vector<shared_ptr<Item>> triggers = this->board.getItems();
	// get the hero's information
	Hero& hero = this->board.getHero();
	// use a string to store the message
	string message;
	// use a string vector to store all message from the creature
	vector<string> creatureMessage;

	// for all creatures
	for (const auto& creature : creatures) {
		// get the distance from creature to hero
		Position distance = (creature->getPos() - hero.getPos());

		// if they are on the same position
		if (distance == Position(0, 0)) {
			// if the hero meet the boss
			if (creature->getType() == CREATURE_TYPE::XIJINPING) {
				// if the hero have weapon
				if (hero.getHaveWeapon())
					// hero beats boss
					gameState = GAME_STATE::WIN;
				else
					// boss beats the hero
					gameState = GAME_STATE::LOSE;

				// game over with the state 
				gameOver(gameState);
			}
			else {
				// hero get damagee by the creature
				hero.damage(creature->getPower());
			}
		}

		// if their distance is equel or less than 2
		if (abs(distance.x) + abs(distance.y) <= 2) {
			// see which type the creature has
			switch (creature->getType())
			{
				// if the type is TSUAINGWEN
			case CREATURE_TYPE::TSUAINGWEN:
				// set the creature's message
				message = "Tsua Ing Wen has found the hero and says : ";
				// push back to the vector
				creatureMessage.push_back(message + ((shared_ptr<TsuaIngWen>&)creature)->loud());
				break;

				// if the type is TSUAINGWEN
			case CREATURE_TYPE::XIJINPING:
				// set the creature's message
				message = "Xi jin Ping has found the hero and says : ";
				// push back to the vector
				creatureMessage.push_back(message + ((shared_ptr<XiJinPing>&)creature)->loud());
				break;
			}
		}
	}

	// for all trigger in triggers
	for (const auto& trigger : triggers) {
		// if the hero is on the trigger
		if (trigger->getPos() == hero.getPos()) {
			// if the trigger can provide hero weapon
			if (trigger->getHaveWeapon())
				// give hero his lightsaber
				hero.setHaveWeapon(true);

			// hero gain EXP from trigger
			hero.gainExp(trigger->getExp());
			// hero update HP from trigger
			hero.setHp(hero.getHp() + trigger->getHP());
		}
	}

	// print out the creatures' message
	for (const auto& str : creatureMessage) {
		cout << str << "\n\n";
	}
}

/**
 * // Intent:  end the game with input game state
 * // Pre:  GAME_STATE &gameState
 * // Post:  None
 */
void GameManager::gameOver(GAME_STATE& gameState) {
	// clean the screen
	system("CLS");

	// if the player wins the game
	if (gameState == GAME_STATE::WIN)
		// print out the messange
		cout << "\n你已擊敗吸金瓶!\n\n";
	else
		// print out the messange
		cout << "\n您已被流放到新疆!\n\n";

	// end the game
	exit();
}

/**
 * // Intent:  print out the information
 * // Pre:  None
 * // Post:  None
 */
void GameManager::printInformation()
{
	// get the hero
	Hero& hero = this->board.getHero();
	// get the trigger
	shared_ptr<Item>item = this->board.getItems()[0];

	cout << "\nmove Hero to Italian Pepper Chicken to get the lightsaber\n";

	if (hero.getHaveWeapon())
		cout << "\nHero's weaopn: lightsaber *1\n\n";
	else
		cout << "\nHero's weaopn:\n\n";

	cout << "Level: " << hero.getLevel() << "(" << hero.getCurrentExp() << "/" << hero.getMaxExp() << " to level up)    ";
	cout << "HP: " << hero.getHp() << endl << endl;

	cout << "touch W will gain 20 HP\n";
	cout << "touch T will gain EXP\n";

	cout << "\n\n(ESC) Exit (1) Save (2) Load" << endl;


	/*
	// print out all information
	cout << "The hero is level " << hero.getLevel() << "(" << hero.getCurrentExp() << "/" << hero.getMaxExp() << " to level up)" << endl;
	cout << "The hero has " << hero.getHp() << " hp" << endl;
	if (hero.getHaveWeapon())
		cout << "\nThe hero have lightsaber to kill Xi Jin Ping\n" << endl;
	cout << "Every time you step on a item T, the hero gets " << item->getExp() << " exp." << endl;
	cout << "Every time you step on a item C, the hero gets 20 HP and have a lightsaber to kill Xi Jin Ping" << endl;
	cout << "If Creature has found the hero, it will loud.\n";
	cout << "Touch Tsua Ing Wen will get healing for 10 hp.\n";
	cout << "Touch Xi Jin Ping will lose the game if you don't have a lightsaber\n";
	cout << "You win if you have lightsaber and touch Xi Jin Ping\n";
	cout << "(ESC) Exit (1) Save (2) Load" << endl;
	*/
}

/**
 * // Intent:  print out the board
 * // Pre:  None
 * // Post:  None
 */
void GameManager::printBoard()
{
	// use draw function in board
	this->board.draw();
}

/**
 * // Intent:  save the board and game information to txt file
 * // Pre:  None
 * // Post:  None
 */
void GameManager::save()
{
	// Clear the screen.
	system("CLS");

	// Print the title message.
	cout << "Input file name for saving or Exit to leave saving.\n";

	// Input the path of the file to save 
	string filePath;
	cin >> filePath;

	// If the input file is "Exit" then exit the save mode
	if (filePath == "Exit") return;

	// Open the file that is the destination to save the board and informations
	ofstream saveFile("./saveFile/" + filePath + ".txt");
	if (!saveFile.is_open()) return;

	// Save ths information of canva
	saveFile << "Canva:\n";
	saveFile << "(row,column): " << this->board.getLength() << ' ' << this->board.getWidth() << '\n';

	// Store the information of the board
	for (const auto& vec : this->board.getBoard()) {
		for (const auto& element : vec) {
			saveFile << element;
		}
		saveFile << '\n';
	}
	saveFile << "\n";

	// Save the information of hero
	Hero hero = board.getHero();
	saveFile << "Hero:\n";
	saveFile << "Pos(x,y): " << hero.getPos() << '\n'; // Save the position
	saveFile << "Hp: " << hero.getHp() << '\n'; // Save the HP
	saveFile << "Lv: " << hero.getLevel() << '\n'; // Save the level
	saveFile << "Exp: " << hero.getCurrentExp() << '\n'; // Save the exp
	saveFile << "Exp to next level: " << hero.getMaxExp() << '\n'; // Save need how much exp to the next level
	saveFile << "Is hero have a lightsaber: " << hero.getHaveWeapon() << '\n';
	saveFile << '\n';

	// Save the information of the creature
	vector<shared_ptr<Creature>> creatures = board.getCreatures();
	saveFile << "Creature:\n";
	saveFile << "Amounts: " << creatures.size() << '\n';
	saveFile << "Pos(x,y):\n";
	for (int i = 0; i < creatures.size(); i++) {
		string cType;
		Position cPos = creatures[i]->getPos();

		if (creatures[i]->getType() == CREATURE_TYPE::TSUAINGWEN) cType = "TSUAINGWEN";
		else cType = "XIJINPING";

		saveFile << cType << ": " << cPos << '\n';
	}
	saveFile << '\n';

	// save the information of items
	vector<shared_ptr<Item>> items = board.getItems();
	saveFile << "Items:\n";
	saveFile << "Amounts: " << items.size() << '\n';
	saveFile << "Pos(x,y):\n";
	for (int i = 0; i < items.size(); i++) {
		string iType;
		Position iPos = items[i]->getPos();

		if (items[i]->getType() == ITEM_TYPE::TRIGGER) iType = "TRIGGER";
		else iType = "ITALIAN_PEPPER_CHICKEN";

		saveFile << iType << ": " << iPos << '\n';
	}
	saveFile << '\n';

	// Close read file mode
	saveFile.close();

}

/**
 * // Intent:  load the board and game information from txt file
 * // Pre:  None
 * // Post:  None
 */
void GameManager::load()
{
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
	int length, width;
	loadFile.ignore(strlen("Canva:\n"));
	loadFile.ignore(strlen("(row,column): "));
	loadFile >> length >> width; // Load the width and height of the canva
	vector<vector<char>> tempBoard(length, vector<char>(width));

	loadFile.ignore(1);
	for (auto& row : tempBoard) {
		for (auto& column : row) {
			loadFile.get(column);
		}
		loadFile.ignore(1);
	}
	this->board.getBoard() = tempBoard;
	loadFile.ignore(1);

	// Load the information of the hero
	loadFile.ignore(strlen("Hero:\n"));
	loadFile.ignore(strlen("Pos(x,y): "));
	Hero& hero = board.getHero();
	int hp, level, exp, maxExp;
	bool weapon;

	// Load the position of the hero
	Position heroPos;
	loadFile >> heroPos;
	hero.setPos(heroPos);

	// Load the HP of the hero
	loadFile.ignore(strlen("HP: "));
	loadFile >> hp;
	hero.setHp(hp);

	// Load the level of the hero
	loadFile.ignore(strlen("Lv: "));
	loadFile >> level;
	hero.setLevel(level);

	// Load the Exp of the hero
	loadFile.ignore(strlen("Exp: "));
	loadFile >> exp;
	hero.setCurrentExp(exp);

	// Load the maxExp of the hero
	loadFile.ignore(strlen("Exp to next level: "));
	loadFile >> maxExp;
	hero.setMaxExp(maxExp);

	loadFile.ignore(strlen("Is hero have a lightsaber: "));
	loadFile >> weapon;
	hero.setHaveWeapon(weapon);

	loadFile.ignore(1);

	// Read the information of the creature
	vector<shared_ptr<Creature>> creatures;
	int creatureAmounts;
	loadFile.ignore(strlen("Creature:\n"));
	loadFile.ignore(strlen("Amounts: "));
	loadFile >> creatureAmounts;

	loadFile.ignore(strlen("Pos(x,y):\n"));
	for (int i = 0; i < creatureAmounts; i++) {
		string infor;
		Position creaturePos;
		loadFile >> infor >> creaturePos;

		if (infor == "XIJINPING:") creatures.emplace_back(make_shared<XiJinPing>(creaturePos));
		if (infor == "TSUAINGWEN:") creatures.emplace_back(make_shared<TsuaIngWen>(creaturePos));
	}
	this->board.getCreatures() = creatures;
	loadFile.ignore(1);

	// read the information of items
	vector<shared_ptr<Item>> items;
	int itemAmounts;
	loadFile.ignore(strlen("Items:\n"));
	loadFile.ignore(strlen("Amounts: "));
	loadFile >> itemAmounts;

	loadFile.ignore(strlen("Pos(x,y):\n"));
	for (int i = 0; i < itemAmounts; i++) {
		string infor;
		Position itemPos;
		loadFile >> infor >> itemPos;

		if (infor == "TRIGGER:") items.emplace_back(make_shared<Trigger>(itemPos));
		if (infor == "ITALIAN_PEPPER_CHICKEN:") items.emplace_back(make_shared<ItalianPepperChicken>(itemPos));
	}
	this->board.getItems() = items;

	// Close the loading mode
	loadFile.close();

}

/**
 * // Intent:  end the game
 * // Pre:  None
 * // Post:  None
 */
void GameManager::exit()
{
	// end the program
	system("pause");
	std::exit(0);
}

