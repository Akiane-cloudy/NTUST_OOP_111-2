/*****************************************************************//**
 * File: Item.cpp
 * Author: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-21
 * Description:  The Item cpp file
 *********************************************************************/
#include "Item.h"

/**
 * // Intent:  make a item with input value
 * // Pre:  ITEM_TYPE itemType, const Position& pos
 * // Post:  None
 */
Item::Item(ITEM_TYPE itemType, const Position& pos) {
	this->itemType = itemType;
	this->pos = pos;
}

/**
 * // Intent:  initialize the Item with input Item
 * // Pre:  const Item& other
 * // Post:  None
 */
Item::Item(const Item& other)
{
	(*this) = other;
}

/**
 * // Intent:  get icon of the Item
 * // Pre:  None
 * // Post:  char icon
 */
char Item::getIcon() const
{
	return this->icon;
}

/**
 * // Intent:  set icon of the Item
 * // Pre:  None
 * // Post:  char icon
 */
void Item::setIcon(const char& icon)
{
	this->icon = icon;
}

/**
 * // Intent:  get position of the Item
 * // Pre:  None
 * // Post:  Position ItemPos
 */
Position Item::getPos() const
{
	return this->pos;
}

/**
 * // Intent:  set position of the Item
 * // Pre:  None
 * // Post:  None
 */
void Item::setPos(const Position& pos)
{
	this->pos = pos;
}

/**
 * // Intent:  get the EXP of the Item
 * // Pre:  None
 * // Post:  int exp
 */
int Item::getExp() const
{
	return this->exp;
}

/**
 * // Intent:  set the EXP of the Item
 * // Pre:  None
 * // Post:  None
 */
void Item::setExp(const int& exp)
{
	this->exp = exp;
}

/**
 * // Intent:  see whether the item can let hero defents damage
 * // Pre:  None
 * // Post:  bool canDamage
 */
bool Item::getHaveWeapon() {
	return this->haveWeapon;
}

/**
 * // Intent:  get the HP which item can give to hero
 * // Pre:  None
 * // Post:  int HP
 */
int Item::getHP() const{
	return this->HP;
}

/**
 * // Intent:  set the HP which item can give to hero
 * // Pre:  const int& HP
 * // Post:  None
 */
void Item::setHP(const int& HP) {
	this->HP = HP;
}

/**
 * // Intent:  get the type of the item
 * // Pre:  None
 * // Post:  ITEM_TYPE type
 */
ITEM_TYPE Item::getType() const {
	return this->itemType;
}
