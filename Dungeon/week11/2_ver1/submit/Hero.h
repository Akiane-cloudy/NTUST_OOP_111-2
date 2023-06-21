/*****************************************************************//**
 * File: Hero.h
 * Author: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-21
 * Description:  The hero header file
 *********************************************************************/
#pragma once
#include "Position.h"
#include "GAME_STATE.h"

// this class control the hero
class Hero
{
protected:
	// icon of hero
	char icon;	
	// position of hero
	Position pos;		
	// hp of the hero
	int	hp;
	// level of the hero
	int	level;     
	// max exp of hero
	int	maxExp;		
	// hero's current exp
	int	currentExp;
	bool haveWeapon;

public:
	// make a hero with input value
	Hero(const char& icon = 'H', const Position& pos = {0, 0}, const int& hp = 100, const int& level = 1, const int& maxExp = 15, const int& currentExp = 0);
	// make a hero with input hero
	Hero(const Hero& other);

	// get the icon of the hero
	virtual char getIcon() const final;
	// set the icon of the hero
	virtual void setIcon(const char& icon) final;

	// get the position of the hero
	virtual Position getPos() const final;
	// set the position of the hero
	virtual void setPos(const Position& pos) final;

	// get the HP of the hero
	virtual int getHp() const final;
	// set the HP of the hero
	virtual void setHp(const int& hp)final;

	// get the level of the hero
	virtual int getLevel() const final;
	// set the level of the hero
	virtual void setLevel(const int& level)final;

	// get the max exp of the hero
	virtual int getMaxExp() const final;
	// set the max exp of the hero
	virtual void setMaxExp(const int& maxExp) final;

	// get the current exp of the hero
	virtual int getCurrentExp() const final;
	// set the current exp of the hero
	virtual void setCurrentExp(const int& currentExp) final;

	// increase the exp of the hero
	virtual void gainExp(const int& points);
	// decrease the HP of the hero
	virtual void damage(const int& points);
	
	// set the weapon 
	void setHaveWeapon(const bool&);
	// get the weapon
	bool getHaveWeapon() const;

};

