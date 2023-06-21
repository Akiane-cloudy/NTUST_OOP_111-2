/*****************************************************************//**
 * File: TsuaIngWen.h
 * Author: 許桓愷 (B11115008@mail.ntust.edu.tw)
 *		   陳彥儒 (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: 許桓愷 (B11115008@mail.ntust.edu.tw)
 *		   陳彥儒 (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-21
 * Description:  The TsuaIngWen header file
 *********************************************************************/
#pragma once

#include "Creature.h"
#include <iostream>

 // this is a very special type from Taiwan, which inherit creature class
 // TsuaIngWen's feature is let hero gain 10 HP every time when hero touch her
class TsuaIngWen : public Creature
{
private:
	// set the TsuaIngWen's voice
	std::string voice = "臺灣一定有希望！";
	const Position directions[2] = { {1, 0}, {-1, 0} };

public:
	// initailize the TsuaIngWen with input position
	TsuaIngWen(const Position& pos);
	// get the next position 
	Position getNextPos();
	// return TsuaIngWen's voice 
	std::string loud();
};

