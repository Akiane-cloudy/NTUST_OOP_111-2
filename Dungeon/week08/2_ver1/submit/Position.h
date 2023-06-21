#pragma once
//************************************************************
// The location in the board
//************************************************************
class Position {
public:
	int x, y; // X, y Coordinate

	Position() : x(0), y(0) {}
	Position(int x, int y) : x(x), y(y) {}
	Position(const Position& ref) { *this = ref; }

	// Operator overloading
	/*Please implement your code here*/
	Position operator+(const Position& lhs); // Overload the operator +
	Position operator-(const Position& lhs); // Overload the operator -
	Position operator*(const int& var); // Overload the operator *
	void operator+=(const Position& lhs); // Overload the operator +=
	void operator-=(const Position& lhs); // Overload the operator -=
	bool operator==(const Position& lhs); // Overload the operator ==
	bool operator!=(const Position& lhs); // Overload the operator !=
	/************************************************************************/
};

/**
 * Intent: Overloading the operator+
 * pre: The lhs must no be empty
 * post: return a Position struct that add by this and the lhs
 * .
 */
Position Position::operator+(const Position& lhs)
{
	// Return the position with position is add by the lhs
	return Position(this->x + lhs.x, this->y + lhs.y);
}

/**
 * Intent: Overloading the operator-
 * pre: The lhs must no be empty
 * post: return a Position struct that add by this diffrence with lhs
 * .
 */
Position Position::operator-(const Position& lhs)
{
	// Return the position with position is minus the lhs
	return Position(this->x - lhs.x, this->y - lhs.y);
}

/**
 * Intent: Overloading the operator+=
 * pre: The lhs must no be empty
 * post: Modify the current Position obeject to add the property of the lhs
 * .
 */
void Position::operator+=(const Position& lhs)
{
	// Let this position x and y add the lhs x and y
	this->x = this->x + lhs.x;
	this->y = this->y + lhs.y;
}

/**
 * Intent: Overloading the operator-=
 * pre: The lhs must no be empty
 * post: Modify the current Position obeject to minus the property of the lhs
 * .
 */
void Position::operator-=(const Position& lhs)
{
	// Let this position x and y minus the lhs x and y
	this->x = this->x - lhs.x;
	this->y = this->y - lhs.y;
}

/**
 * Intent: Overloading the operator*
 * pre: The lhs must no be empty
 * post: Return a Position struct that mutiply by var
 * .
 */
Position Position::operator*(const int& var)
{
	// Return the position combine by the x * var and y * var
	return Position(this->x * var, this->y * var);
}

/**
 * Intent: Overloading the operator==
 * pre: The lhs must no be empty
 * post: Return if this Position is equal to the lhs
 * .
 */
bool Position::operator==(const Position& lhs)
{
	// Return if the current x and y is eqaul to the lhs's property
	return (this->x == lhs.x && this->y == lhs.y);
}

/**
 * Intent: Overloading the operator!=
 * pre: The lhs must no be empty
 * post: Return if this Position is not equal to the lhs
 * .
 */
bool Position::operator!=(const Position& lhs)
{
	// Return if the current x and y is not eqaul to the lhs's property
	return (this->x != lhs.x || this->y != lhs.y);
}
