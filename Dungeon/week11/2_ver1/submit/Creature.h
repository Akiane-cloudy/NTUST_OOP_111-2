/*****************************************************************//**
 * File: Creature.h
 * Author: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-21
 * Description:  The Creature header file
 *********************************************************************/
#pragma once
#include "Position.h"
#include "CREATURE_TYPE.h"

// this class control the creature
class Creature
{
protected:
	// icon of creature
	char icon;
	// position of creature
	Position pos;
	// damage of the creature
	int power;
	// see which type the creature is
	int seeDistance;

	CREATURE_TYPE type;

public:
	// initialize the creature with defult value
	Creature();
	// initialize the creature with input value
	// Creature(const char& icon = 'C', const Position& pos = {0, 0}, const int& power = 5, const CREATURE_TYPE type = CREATURE_TYPE::DEFAULT);
	// initialize the creature to input creature
	Creature(const CREATURE_TYPE& type, const Position& pos);
	Creature(const Creature& other);

	// get the creauture's icon
	virtual char getIcon() const;
	// set the creature's icon
	virtual void setIcon(const char& icon);

	// get the creature's position
	virtual Position getPos() const;
	// set the creature's position
	virtual void setPos(const Position& pos);
	// get the power of the creature
	virtual int getPower() const;
	// set the power of the creauture
	virtual void setPower(const int& power);

	// get the creature's type
	virtual CREATURE_TYPE getType() const;
	// set the creature's type
	virtual void setType(const CREATURE_TYPE& type);

};

