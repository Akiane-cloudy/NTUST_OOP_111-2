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
	Position operator+(const Position& rhs) const {
		return Position(x + rhs.x, y + rhs.y);
	}
	Position& operator+=(const Position& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	Position operator-(const Position& rhs) const {
		return Position(x - rhs.x, y - rhs.y);
	}
	Position& operator-=(const Position& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}
	Position operator*(int scale) const {
		return Position(x * scale, y * scale);
	}
	bool operator==(const Position& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	bool operator!=(const Position& rhs) const {
		return !(*this == rhs);
	}

	/*Please implement your code here*/
	// Intent: Overloading the operator<< of the ostream and Position class
	// pre: none
	// post: Output the position of a position class
	friend std::ostream& operator<<(std::ostream& out, const Position& target) {
		return out << target.x << ' ' << target.y; // Output the position
	}

	// Intent: Overloading the operator>> of the istream and Position class
	// pre: none
	// post: Read the position of a position class
	friend std::istream& operator>>(std::istream& in, Position& target) {
		return in >> target.x >> target.y; // Read the x and y of a position class
	}
	/************************************************************************/
};
