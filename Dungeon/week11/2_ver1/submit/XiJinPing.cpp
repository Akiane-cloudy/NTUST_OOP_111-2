/*****************************************************************//**
 * File: XiJinPing.cpp
 * Author: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-21
 * Description:  The XiJinPing cpp file
 *********************************************************************/
#include "XiJinPing.h"

 /**
  * // Intent:  initailize the XiJinPing with input position
  * // Pre:  const Position& pos
  * // Post:  None
  */
XiJinPing::XiJinPing(const Position& pos) : Creature(CREATURE_TYPE::XIJINPING, pos)
{
	this->icon = 'X';
	this->power = 9999;
	this->seeDistance = 2;
}

/**
 * // Intent:  get next position
 * // Pre:  None
 * // Post:  Position nextPos
 */
Position XiJinPing::getNextPos()
{
	return this->pos + directions[rand() % 4];
}

/**
 * // Intent:  return XiJinPing's voice
 * // Pre:  None
 * // Post:  string voice
 */
std::string XiJinPing::loud()
{
	return this->voice;
}
