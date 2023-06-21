/*****************************************************************//**
 * File: Item.h
 * Author: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-21
 * Description:  The Item header file
 *********************************************************************/
#pragma once

#include "Position.h"
#include "ITEM_TYPE.h"

class Item
{
protected:
	// icon of the trigger
	char icon;
	// postion of trigger
	Position pos;
	// the EXP other could get from trigger
	int exp;
	int HP;
	bool haveWeapon;
	ITEM_TYPE itemType;
	 
public:
	// initialize the trigger with input value
	// Item(ITEM_TYPE itemType, const char& icon = 'T', const Position& pos = { 0, 0 }, const int& exp = 10, const int& HP = 0, const bool& canDamage = false);
	Item(ITEM_TYPE itemType, const Position& pos = { 0, 0 });
	// initialize the trigger with input trigger
	Item(const Item& other);

	// get icon of the trigger
	virtual char getIcon() const;
	// set icon of the tirgger
	virtual void setIcon(const char& icon);

	// get position of trigger
	virtual Position getPos() const;
	// set position of trigger
	virtual void setPos(const Position& pos);

	// get the EXP of the trigger
	virtual int getExp() const;
	// set the EXP of the trigger
	virtual void setExp(const int& exp);
	// see whether the item can let hero defents damage
	virtual bool getHaveWeapon();

	// get the HP which item can give to hero
	virtual int getHP() const;
	// set the HP which item can give to hero
	virtual void setHP(const int& HP);

	// get the type of the item
	virtual ITEM_TYPE getType() const;
};