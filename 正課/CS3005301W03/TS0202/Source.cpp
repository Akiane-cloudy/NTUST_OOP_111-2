// Name: ³¯«Û¾§ B11115004
// Date: March 7, 2023
// Last Update: March 7, 2023
// Problem statement:  Leaderboard

#include <iostream>
#include <fstream>
#include <vector>
const int MAX = 3;
using namespace std;


void getHighScores(vector<string> &nameVec, vector<int> &scoreVec);

int main()
{
	vector<string> nameVec; // declare the vector to store the input name data
	vector<int> scoreVec; // declare the vector to store the input socre data
	getHighScores(nameVec, scoreVec); 

	for (int i(0); i < MAX; i++)
	{
		cout << nameVec[i] << endl;
		cout << scoreVec[i] << endl;
	}

	return 0;
}

void getHighScores(vector<string> &nameVec, vector<int> &scoreVec)
{
	ifstream fileInput("scores.txt"); // open file to read the input data

	string name;
	int score;
	while (fileInput >> name) // get the data from input file
	{
		fileInput >> score;
		nameVec.push_back(name);
		scoreVec.push_back(score);
	}

	for (int i(0); i < nameVec.size() - 1; i++)
	{
		for (int j(0); j < nameVec.size() - i - 1; j++)
		{
			if (scoreVec[j+1] > scoreVec[j]) // if the next person's score is bigger than the previous one, then swap their socre and name place
			{
				swap(scoreVec[j], scoreVec[j + 1]);
				swap(nameVec[j], nameVec[j + 1]);
			}
		}
	}
	return;
}