/*****************************************************************//**
 * File: Creature.cpp
 * Author: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-21
 * Description:  The creature cpp file
 *********************************************************************/
#include "Creature.h"

/**
 * // Intent:  initialize the creature with defult value
 * // Pre:  None
 * // Post:  None
 */
Creature::Creature()
{
	// set the information to defult value
	this->icon = 'C';
	this->power = 10;
	this->type = CREATURE_TYPE::DEFAULT;
}

/**
 * // Intent:  initialize the creature with input value
 * // Pre:  const char& icon, const Position& pos, const int& power, const CREATURE_TYPE type
 * // Post:  None
 */
Creature::Creature(const CREATURE_TYPE &type, const Position& pos)
{
	// set the information to input value
	this->type = type;
	this->pos = pos;
}

/**
 * // Intent:  initialize the creature to input creature
 * // Pre:  const Creature& other
 * // Post:  None
 */
Creature::Creature(const Creature& other)
{
	// set this class as input class
	(*this) = other;
}

/**
 * // Intent:  get the creauture's icon
 * // Pre:  None
 * // Post:  char creatureIcon
 */
char Creature::getIcon() const
{
	// return the creature's icon
	return this->icon;
}

/**
 * // Intent:  set the creauture's icon
 * // Pre:  None
 * // Post:  None
 */
void Creature::setIcon(const char& icon)
{
	// set the icon to input icon
	this->icon = icon;
}

/**
 * // Intent:  get the creauture's position
 * // Pre:  None
 * // Post:  Position creaturePos
 */
Position Creature::getPos() const
{
	// return the creature's position
	return this->pos;
}

/**
 * // Intent:  set the creauture's position
 * // Pre:  None
 * // Post:  None
 */
void Creature::setPos(const Position& pos)
{
	// set the creature's position to input pos
	this->pos = pos;
}

/**
 * // Intent:  get the creauture's power
 * // Pre:  None
 * // Post:  int creaturePower
 */
int Creature::getPower() const
{
	return this->power;
}

/**
 * // Intent:  set the creauture's power
 * // Pre:  None
 * // Post:  None
 */
void Creature::setPower(const int& power)
{
	this->power = power;
}

/**
 * // Intent:  get the creature's type
 * // Pre:  None
 * // Post:  CREATURE_TYPE creatureType
 */
CREATURE_TYPE Creature::getType() const
{
	return this->type;
}

/**
 * // Intent:  set the creature's type
 * // Pre:  None
 * // Post:  None
 */
void Creature::setType(const CREATURE_TYPE& type)
{
	this->type = type;
}