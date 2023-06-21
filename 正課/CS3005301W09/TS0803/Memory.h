/*****************************************************************//**
 * file : Memory.h
 * Author : ³¯«Û¾§ 
 * Create date : April 22, 2023
 * Last update : April 22, 2023
 * Description : Memory.h
 *********************************************************************/
#pragma once

#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

// declare a memory class
class Memory {

public:
	Memory(int size = 0); // a constructor that set the memory size

private:
	vector<unsigned char> memory; // a private property 

public:
	void getCommand(string); // get the whole command
	void get(int, string); // do the "Get" command
	void set(int, string, string); // do the "Set" command
	void charMode(int, int); // do the char setting mode
	void shortMode(int, unsigned int); // do the short setting mode
	void stringMode(int, string); // do the string setting mode
	void intMode(int, unsigned int); // do the int setting mode
};
