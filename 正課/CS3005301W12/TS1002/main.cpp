/*****************************************************************//**
 * file : main.cpp
 * Author : ³¯«Û¾§ 
 * Create date : May 11, 2023
 * Last update : May 11, 2023
 * Description : Word_Game
 *********************************************************************/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
using Point = pair<int, int>; // Use a point to store a pair of to int that mean (y,x)

vector<string> board; // Store the board from input
vector<string> temp; // Becuase of the board will be changed, so copy it 
// A direction step table
const int dir[8][2]{ {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

bool isValid(const string& target); // Check if the string is valid
void find(string res, Point currentPos, const string& target, int targetIndex, string& result); // Find the path that check if the string is valid

int main()
{
	while (1)
	{
		board.resize(4); // resize the board
		for (auto& str : board) {
			cin >> str; // input the board
			if (cin.eof()) return 0; // if the input is eof then close the program
		}

		temp = board; // Copy the board

		ifstream file("words.txt"); // open file
		for (string input; file >> input;) {
			if (isValid(input)) { 
				cout << input << '\n'; // Check if the string is valid and print the answer
			}
		}
		cout << '\n'; // new line
	}
}

/**
 * Intent : Check if the input string is valid 
 * pre : The board must not be empty
 * post : return if the string is valid 
 * \param target
 * \return 
 */
bool isValid(const string& target)
{
	vector<Point> start; // use a vector to store the start position
	board = temp; // copy the board

	if (target.size() < 3 ) return false; // If the target length is less than 3 then it is invalid

	// Use two for loop to check the start position and store them
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == target[0]) {
				start.push_back({ i, j }); // store the start position
			}	
		}
	}
	
	// Run the start position and DFS them to find the path of the input target string
	for (const auto& pos : start) {
		string res; // Use res to store the path
		find(res, pos, target, 0, res); // Find the path

		if (res == target) return true; // If the res is equal to the input target string them return true
	}

	return false; // else condition is false
}

/**
 * Intent : Use DFS to find the path is valid and store it
 * pre : The target length must more than 3
 * post : If the path is valid then modify the result become to the target
 * \param res
 * \param currentPos
 * \param target
 * \param targetIndex
 * \param result
 */
void find(string res, Point currentPos, const string& target, int targetIndex, string& result)
{
	// If the path is valid then let result to be target 
	if (res == target) {
		result = res; // store result
		return; // return it
	}

	// If the size of res is larger than target or res is queal target or the index is larger then the size of target then return
	if (res.size() > target.size() || res == target || targetIndex >= target.size()) return;

	// If find the target char that it wants then store the path and set it to be 0 that mean it is been checked 
	if (target[targetIndex] == board[currentPos.first][currentPos.second]) {
		res.push_back(target[targetIndex]);
		board[currentPos.first][currentPos.second] = 0;
		targetIndex++; // Find the next char
	}
	else return; // else mean it is not found, and return it

	// Run the eight direction to the next step
	for (const auto step : dir) {
		int nextY = currentPos.first + step[0]; // the next position y
		int nextX = currentPos.second + step[1]; // the next position x

		if (nextY < 0 || nextX < 0 || nextY >= 4 || nextX >= 4) continue; // If the (nextY, nextX) is invalid then dont run it
		if (board[nextY][nextX] == 0) continue; // If the next step is been checked then don run it


		find(res, { nextY, nextX }, target, targetIndex, result); // If the next position is valid then run it
	}
}
