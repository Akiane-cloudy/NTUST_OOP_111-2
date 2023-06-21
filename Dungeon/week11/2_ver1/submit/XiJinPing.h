/*****************************************************************//**
 * File: XiJinPing.h
 * Author: 許桓愷 (B11115008@mail.ntust.edu.tw)
 *		   陳彥儒 (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: 許桓愷 (B11115008@mail.ntust.edu.tw)
 *		   陳彥儒 (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-21
 * Description:  The XiJinPing header file
 * Description:  The XiJinPing header file
 *********************************************************************/
#pragma once

#include "Creature.h"
#include <iostream>

 // this is a very special type from Taiwan, which inherit creature class
 // his damage is very emotional 
class XiJinPing : public Creature
{
private:
	// set his voice
	std::string voice = "我們懷念他！";
	const Position directions[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

public:
	// create a XiJinPing with input position
	XiJinPing(const Position& pos);
	// get his next position
	Position getNextPos();
	// get his voice
	std::string loud();
};

