/*****************************************************************//**
 * File: ItalianPepperChicken.h
 * Author: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-27
 * Description:  the ItalianPepperChicken header file
 *********************************************************************/
#pragma once
#include "Item.h"

// this class control ItalianPepperChicken item
// it could let hero immune to the next attack and gain HP for 20 points
class ItalianPepperChicken : public Item{
private:

public:
	ItalianPepperChicken() = default;
	// make a class with input position
	ItalianPepperChicken(const Position& pos);
};
