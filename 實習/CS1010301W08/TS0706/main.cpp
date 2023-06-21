/*****************************************************************//**
 * file : main.cpp
 * Author : ³¯«Û¾§ 
 * Create date : April 19, 2023
 * Last update : April 19, 2023
 * Description : Shisensho
 *********************************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> boards(8, vector<int>(8, 0)); // create a 8*8 boards vector to store the input board 6*6
int x2, y2; // x2 y2 is the end coordinate of each compare case
bool isFind; // declare a bool variable store if the target is found
const int delta[4][2]{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // declare a const delta value the represented each direction delta value

void setBoards(); //a function to initial the boards
bool isPosValid(int, int); // a function that check if the position is valid to read
bool isPosValid(int, int, bool); // a function that check if the position is valid to read
bool removable(int, int); // a function that check if the position is removable
void findEnd(int, int, int, int); // use dfs to find the target

int main()
{
	setBoards(); // initial the board

	int x1, y1; // set x1, y1 that represent the begin position
	while (cin >> x1 >> y1 >> x2 >> y2) // input the begin position
	{
		x2 += 1, y2 += 1; // because the board is 8*8, so every position in 6*6 need to plus 1
		isFind = false; // initial the isFind is false
		bool isRemoveable = (removable(x1 + 1, y1 + 1)); // check if the pair is removable
		
		if (isRemoveable == false) // if it is not removable that print out "bad pair"
		{
			cout << "bad pair\n"; // print bad pair
		}
		else // else represented that is removable 
		{
			cout << "pair matched\n"; // print out "pair matched"
			boards[y1 + 1][x1 + 1] = boards[y2][x2] = 0; // set the begin and end position elements to be 0
		}
	}
}

/**
 * Intent : a function to initial the boards from input
 * pre : none
 * post : initial the boards
 */
void setBoards()
{
	// use for loop to run 8 times for each case
	for (int i = 1; i < 7; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			cin >> boards[i][j]; // input the boads elements
		}
	}
}

/**
 * Intent : a function that check if the target and the begin is match
 * pre : the boards need had initialed
 * post : return the mathc is success or failed
 * \param x1
 * \param y1
 * \return 
 */
bool removable(int x1, int y1)
{
	// check if the position is valid
	// if the postion is out of range or any elements is 0 between target and begin
	// or just the target != to begin, then return false
	if (!(isPosValid(x1, y1)) ||
		(x1 == x2 && y1 == y2) ||
		boards[y1][x1] == 0 || boards[y2][x2] == 0 ||
		boards[y1][x1] != boards[y2][x2])
	{
		return false;
	}

	int turn = 0; // declare how many times that it turns
	int temp = boards[y1][x1]; // use temp to record the elements that from the begin position 
	boards[y1][x1] = 0; // then set the begin position to be 0
	
	findEnd(x1, y1, turn, -1); // find the target, and the function will modify the isFind or not

	if (isFind == false) // if isFind is false, then the target is not found, so put temp back to origin position
	{
		boards[y1][x1] = temp; // store temp back to boards
	}

	return (isFind == true); //return the isFind is true or false 
}

/**
 * Intent : a function to find the target, if success then modify the isFind to be true
 * pre : none
 * post : modify the isFind to be true or false
 * \param x1
 * \param y1
 * \param turn
 * \param direction
 */
void findEnd(int x1, int y1, int turn, int direction)
{
	if (!isPosValid(x1, y1, 0) || isFind || turn > 3) // if the position is invalid or turn > 3 or is find the target, then return
	{
		return;
	}
	else if (x1 == x2 && y1 == y2 && turn <= 3) // if find the target and the turn is less than 4, then modify the isFind to be true and return
	{
		isFind = true; // modify the isFind to be true
		return;
	}
	else if (boards[y1][x1] != 0) // if the current position is not eqaul to 0 then return
	{
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++) // use for loop to run 4 direction to check if it is the target
		{
			// find the begin + delta, if the direction is the same between direction and current direction
			// the do not plus the turn value
			findEnd(x1 + delta[i][1], y1 + delta[i][0], (i == direction) ? turn : turn + 1, i);
		}
	}
}

/**
 * Intent : a function that check if the position is valid
 * pre : none
 * post : true or false
 * \param x1
 * \param y1
 * \return 
 */
bool isPosValid(int x1, int y1)
{
	// if the x1y1 or x2y2 is out of range, then return false
	if (x1 < 1 || y1 < 1 || x2 < 1 || y2 < 1 ||
		x1 > 6 || y1 > 6 || x2 > 6 || y2 > 6)
	{
		return false;
	}

	return true; // return true
}

/**
 * Intent : check if the position is valid, this is use to check the path of th whole 8*8 baords
 * pre : none
 * post : true or false
 * \param x1
 * \param y1
 * \param opera
 * \return 
 */
bool isPosValid(int x1, int y1, bool opera)
{
	// check if the x1y1 and x2y2 is a valid position
	if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 ||
		x1 > 7 || y1 > 7 || x2 > 7 || y2 > 7)
	{
		return false; // if out of range, then return false
	}

	return true; // return true
}
