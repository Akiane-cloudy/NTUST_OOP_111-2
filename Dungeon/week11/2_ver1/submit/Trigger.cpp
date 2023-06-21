/*****************************************************************//**
 * File: Trigger.cpp
 * Author: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-27
 * Description:  the Trigger cpp file
 *********************************************************************/
#include "Trigger.h"

/**
 * // Intent:  make a class with input position
 * // Pre:  const Position& pos
 * // Post:  None
 */
Trigger::Trigger(const Position& pos) : Item(ITEM_TYPE::TRIGGER, pos) {
	// set the information
	this->icon = 'T';
	this->exp = 10;
	this->HP = 0;
	this->haveWeapon = false;
}
