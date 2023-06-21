/*****************************************************************//**
 * File: TsuaIngWen.cpp
 * Author: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-21
 * Description:  The TsuaIngWen cpp file
 *********************************************************************/
#include "TsuaIngWen.h"

/**
 * // Intent:  initailize the TsuaIngWen with input position
 * // Pre:  const Position& pos
 * // Post:  None
 */
TsuaIngWen::TsuaIngWen(const Position& pos) : Creature(CREATURE_TYPE::TSUAINGWEN, pos)
{
	this->icon = 'W';
	this->power = -10;
	this->seeDistance = 2;
}

/**
 * // Intent:  get nexr position
 * // Pre:  None
 * // Post:  Position nextPos
 */
Position TsuaIngWen::getNextPos()
{
	return this->pos + directions[rand() % 2];
}

/**
 * // Intent:  return TsuaIngWen's voice 
 * // Pre:  None
 * // Post:  string voice
 */
std::string TsuaIngWen::loud()
{
	return this->voice;
}
