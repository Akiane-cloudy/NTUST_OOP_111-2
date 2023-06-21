/*****************************************************************//**
 * File: Position.h
 * Author: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Create Date: 2023-05-21
 * Editor: ³\®Ù·_ (B11115008@mail.ntust.edu.tw)
 *		   ³¯«Û¾§ (B11115004@mail.ntust.edu.tw)
 * Update Date: 2023-05-21
 * Description:  The Position header file
 *********************************************************************/
#pragma once
#include <iostream>

// this struct control the 
struct Position
{
	// use x and y to store the position
	int x, y;

	// initialize the position which both x and y are 0
	Position() :x(0), y(0) {}
	// initialize the position with input value
	Position(int x, int y) : x(x), y(y) {}
	// initialize the position with input position
	Position(const Position& pos) : x(pos.x), y(pos.y) {}

	// get the sum of two position
	Position operator+(const Position& other) const
	{
		return Position(this->x + other.x, this->y + other.y);
	}

	// get the difference of two position
	Position operator-(const Position& other) const
	{
		return Position(this->x - other.x, this->y - other.y);
	}

	// get the multiply of two position
	Position operator*(const int& var) const
	{
		return Position(this->x * var, this->y * var);
	}

	// check if two position are the same
	bool operator==(const Position& other) const
	{
		return (this->x == other.x && this->y == other.y);
	}

	// check if two position are not the same
	bool operator!=(const Position& other) const
	{
		return (this->x != other.x || this->y != other.y);
	}

	// set the position by other position
	void operator=(const Position& other)
	{
		this->x = other.x;
		this->y = other.y;
	}

	// check if current position is less than input position
	bool operator<(const Position& rhs) const {
		if (this->y == rhs.y) return this->x < rhs.x;
		return this->y < rhs.y;
	}

	// output the position 
	friend std::ostream& operator<<(std::ostream& oStream, const Position& pos) {
		return oStream << pos.x << " " << pos.y;
	}

	// input the position
	friend std::istream& operator>>(std::istream& iStream, Position& pos) {
		return iStream >> pos.x >> pos.y;
	}
};
