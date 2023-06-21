/*****************************************************************//**
 * File: Hero.cpp
 * Author: 許桓愷 (B11115008@mail.ntust.edu.tw)
 *		   陳彥儒 (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: 許桓愷 (B11115008@mail.ntust.edu.tw)
 *		   陳彥儒 (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-21
 * Description:  The Hero cpp file
 *********************************************************************/
#include "Hero.h"

 /**
  * // Intent:  make a hero with input hero class
  * // Pre:  const Hero& other
  * // Post:  None
  */
Hero::Hero(const Hero& other)
{
	// set itself as input hero class
	(*this) = other;
}

/**
 * // Intent:  make a hero with input value
 * // Pre:  const char& icon
 *			const Position& pos
 *			const int& hp
 *			const int& level
 *			const int& maxExp
 *			const int& currentExp
 * // Post:  None
 */
Hero::Hero(const char& icon, const Position& pos, const int& hp, const int& level, const int& maxExp, const int& currentExp)
{
	// set the information to input value
	this->icon = icon;
	this->pos = pos;
	this->hp = hp;
	this->level = level;
	this->maxExp = maxExp;
	this->currentExp = currentExp;
	this->haveWeapon = false;
}

/**
 * // Intent:  get the icon of the hero
 * // Pre:  None
 * // Post:  char icon
 */
char Hero::getIcon() const
{
	return this->icon;
}

/**
 * // Intent:  set the icon of the hero
 * // Pre:  const char& icon
 * // Post:  None
 */
void Hero::setIcon(const char& icon)
{
	this->icon = icon;
}

/**
 * // Intent:  get the position of the hero
 * // Pre:  None
 * // Post:  Position heroPos
 */
Position Hero::getPos() const
{
	return this->pos;
}

/**
 * // Intent:  get the HP of the hero
 * // Pre:  None
 * // Post:  int heroHp
 */
int Hero::getHp() const
{
	return this->hp;
}

/**
 * // Intent:  set the HP of the hero
 * // Pre:  const int& hp
 * // Post:  None
 */
void Hero::setHp(const int& hp)
{
	this->hp = hp;
}

/**
 * // Intent:  get the level of the hero
 * // Pre:  None
 * // Post:  int level
 */
int Hero::getLevel() const
{
	return this->level;
}

/**
 * // Intent:  set the level of the hero
 * // Pre:  const int& level
 * // Post:  None
 */
void Hero::setLevel(const int& level)
{
	this->level = level;
}

/**
 * // Intent:  set the position of the hero
 * // Pre:  const Position& pos
 * // Post:  None
 */
void Hero::setPos(const Position& pos)
{
	this->pos = pos;
}

/**
 * // Intent:  get the max exp of the hero
 * // Pre:  None
 * // Post:  int maxExp
 */
int Hero::getMaxExp() const
{
	return this->maxExp;
}

/**
 * // Intent:  set the max exp of the hero
 * // Pre:  const int& maxExp
 * // Post:  None
 */
void Hero::setMaxExp(const int& maxExp)
{
	this->maxExp = maxExp;
}

/**
 * // Intent:  set the current exp of the hero
 * // Pre:  const int& currentExp
 * // Post:  None
 */
void Hero::setCurrentExp(const int& currentExp)
{
	this->currentExp = currentExp;
}

/**
 * // Intent:  increase the exp of the hero
 * // Pre:  const int& points
 * // Post:  None
 */
void Hero::gainExp(const int& points)
{
	// increase the exp
	currentExp += points;

	// if current exp is bigger or equel to max exp
	if (currentExp >= maxExp) {
		// increase level
		level += currentExp / maxExp;
		// adjust the exp
		currentExp %= maxExp;
		// adjust the max exp
		maxExp = (int)(maxExp * 1.2);
	}
}

/**
 * // Intent:  decrease the HP of hero
 * // Pre:  const int& points
 * // Post:  None
 */
void Hero::damage(const int& points)
{
	if (points < 0) {
		this->hp -= points;
		return;
	}

	this->hp -= points;
}

/**
 * // Intent:  get the current exp of the hero
 * // Pre:  NOne
 * // Post:  int currentExp
 */
int Hero::getCurrentExp() const
{
	return this->currentExp;
}

/**
 * // Intent: set the weapon of the hero
 * // Pre:  const bool&
 * // Post:  None
 */
void Hero::setHaveWeapon(const bool& haveWeapon) {
	this->haveWeapon = haveWeapon;
}

/**
 * // Intent:  get the state of hero's weapon
 * // Pre:  None
 * // Post:  bool haveWeapon
 */
bool Hero::getHaveWeapon() const {
	return this->haveWeapon;
}
