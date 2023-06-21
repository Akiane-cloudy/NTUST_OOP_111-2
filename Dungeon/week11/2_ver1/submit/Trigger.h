/*****************************************************************//**
 * File: Trigger.h
 * Author: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-21
 * Description:  The trigger header file
 *********************************************************************/
#pragma once
#include "Position.h"
#include "Item.h"

// this class control the trigger
class Trigger : public Item
{
public:
	Trigger() = default;
	// make a class with input position
	Trigger(const Position& pos);
};

 