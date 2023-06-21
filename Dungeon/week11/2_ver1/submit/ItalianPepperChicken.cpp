/*****************************************************************//**
 * File: ItalianPepperChicken.cpp
 * Author: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-27
 * Description:  the ItalianPepperChicken cpp file
 *********************************************************************/
#include "ItalianPepperChicken.h"

/**
 * // Intent:  make a class with input position
 * // Pre:  const Position& pos
 * // Post:  None
 */
ItalianPepperChicken::ItalianPepperChicken(const Position& pos) : Item(ITEM_TYPE::ITALIAN_PEPPER_CHICKEN, pos) {
	// set the information
	this->icon = 'C';
	this->exp = 0;
	this->HP = 20;
	this->haveWeapon = true;
}
