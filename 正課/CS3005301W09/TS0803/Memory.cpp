/*****************************************************************//**
 * file : Memory.cpp
 * Author : ³¯«Û¾§ 
 * Create date : April 22, 2023
 * Last update : April 22, 2023
 * Description : Memory.cpp
 *********************************************************************/
#include "Memory.h"

/**
 * Intent : a constructor which create the memory a set its memory vector size is availiable
 * pre : 
 * post : 
 * \param size
 */
Memory::Memory(int size) {
	this->memory.resize(size, 0);
}

/**
 * Intent : a function use to get the whole command
 * pre : the input command must not be empty
 * post : do the command from the input command
 * \param inputCommand
 */
void Memory::getCommand(string inputCommand) {
	string command, mode, value; // declare the command, mode and value string
	int position; // declare the position 
	stringstream input(inputCommand); // let input be the string stream from inputCommand

	input >> command >> position >> mode; // input the command, position and mode from input stream
	input.ignore(1); // ignore ' '
	getline(input, value); // get the whole value from the input stream

	if (command == "Set") { // do the "Set" command
		this->set(position, mode, value); // call the set function
	}
	else { // do the "Get" command
		this->get(position, mode); // call the get function
	}
}

/**
 * Intent : a function which is do the get
 * pre : the pos and the mode must not be empty
 * post : get the value by the mode and from the pos
 * \param pos
 * \param mode
 */
void Memory::get(int pos, string mode) {
	try { // try to get the value, if the position is invalid then print the error message
		if (mode == "char") { // do the char mode
			// print out the ascii code of the position of the memory vector
			if (this->memory[pos] != '\0') cout << (unsigned int)this->memory.at(pos);
		}
		else if (mode == "String") { // do the string mode 
			// use one for loop to print the all elements from pos to end, and the '\0' must not print out
			for (int i = pos; i < this->memory.size(); i++) {
				if (this->memory.at(i) == '\0') break; // if the elements is '\0' then don't print it out
				cout << this->memory.at(i); // get the elements
			}
		}
		else if (mode == "short") { // do the short mode 
			unsigned int sum = 0; // declare the sun to 0
			// use a for loop to print out the short from the pos
			for (int i = pos, power = 0; i < pos + 2; i++, power++) {
				sum += this->memory.at(i) * pow(256, power); // the data must turn unsigned char to unsigned int and summation them
			}
			cout << sum; // return the sum
		}
		else { // do the int mode
			unsigned int sum = 0; // declare the sum to 0
			// use for loop to run each times in this case
			for (int i = pos, power = 0; i < pos + 4; i++, power++) {
				sum += this->memory.at(i) * pow(256, power); // turn the hex to decimal and accumulate them
			}
			cout << sum; // return the sum the 4 bytes value 
		}
	}
	catch (const out_of_range& ERROR_MESSAGE) { // if it catch the ERROR_MESSAGE, then print the error mesage 
		cout << "Violation Access."; // print the error message
	}

	cout << '\n';
}

/**
 * Intent : a function to do the set command 
 * pre : the pos, mode and value must be not empty
 * post : do the set command
 * \param pos
 * \param mode
 * \param value
 */
void Memory::set(int pos, string mode, string value) {
	try { // try the set each char, string, short and int mode 
		if (mode == "char") { 
			// if the mode is "char", then do the charMode 
			this->charMode(pos, stoul(value));
		}
		else if (mode == "String") { // if the mode is "String", then do the stringMode 
			this->stringMode(pos, value);
		}
		else if (mode == "short") { // if the mode is "short", then do the shortMode 
			this->shortMode(pos, stoul(value));
		}
		else { // if the mode is "int", then do the intMode
			this->intMode(pos, stoul(value));
		}
	}
	catch (const out_of_range& ERROR_MESSAGE) { // if catch the error message then print the error message
		cout << "Violation Access.\n"; // print error message
	}
}

/**
 * Intent : the function do the char setting
 * pre : the pos and ascii must be not empty
 * post : set the value to the particular pos
 * \param pos
 * \param ascii
 */
void Memory::charMode(int pos, int ascii) {
	// set the ascii is larger than 255, then modify the value 255
	this->memory.at(pos) = (ascii > 255) ? 255 : ascii;
}

/**
 * Intent : a function to execute the string setting
 * pre : the pos and the input must not be empty
 * post : set the value to the particular pos 
 * \param pos
 * \param input
 */
void Memory::stringMode(int pos, string input) {
	for (int i = 0; i < input.size(); i++) {
		this->memory.at(i + pos) = input[i]; // set the value from the input string
	}
}

/**
 * Intent : a function to execute the short setting 
 * pre : the pos and the input must not be empty
 * post : set the value to the particular pos 
 * \param pos
 * \param value
 */
void Memory::shortMode(int pos, unsigned int value) {
	// set the short value to the particular position 
	for (unsigned int i = 0, val = value, count = 0; val != 0 || !(count >= 2); i++, count++) {
		this->memory.at(pos + i) = val % 256;
		val /= 256;
	}
}

/**
 * Intent : a function to execute the int setting 
 * pre : the pos and the input must not be empty
 * post : set the value to the particular pos 
 * \param pos
 * \param value
 */
void Memory::intMode(int pos, unsigned int value) {
	// set the short value to the particular position 
	for (unsigned int i = 0, val = value, count = 0; val != 0 || !(count >= 4); i++, count++) {
		this->memory.at(pos + i) = val % 256;
		val /= 256;
	}
}

