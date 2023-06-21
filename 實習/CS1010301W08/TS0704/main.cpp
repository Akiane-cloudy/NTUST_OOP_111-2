/*****************************************************************//**
 * file : main.cpp
 * Author : ³¯«Û¾§ 
 * Create date : April 14, 2023
 * Last update : April 14, 2023
 * Description : Find the Edit distance
 *********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // use the max and min function
using namespace std;

// the function that find the shortest distance between two words
int levenshteinDistance(const string& source, const string& target);

int main()
{
	string source, target; // create two string source and target

	while (getline(cin, source), getline(cin, target)) // get two value of from getline till eof
	{
		cout << levenshteinDistance(source, target) << '\n'; // print out the edit distance
	}
}

/**
 * Intent : A function that find the shortest edit distance 
 * pre : none
 * post : return the shortest edit distance value 
 * \param source
 * \param target
 * \return 
 */
int levenshteinDistance(const string& source, const string& target)
{
	const int targetLength = target.size(); // define targetLength as the size of target string
	const int sourceLength = source.size(); // define sourceLength as the size of source string

	if (!targetLength || !sourceLength) // if one of two lengths is zero, then return the max value of them  
	{
		return max(targetLength, sourceLength); // return the max value of them
	}

	// declare a two dimentional vector to store the edit distance for each substring turn into the another substring 
	// the + 1 means in the place 0 of index is a empty string, and that means a empty string turn into the other substring 
	vector<vector<int>> dp(sourceLength + 1, vector<int>(targetLength + 1, 0));
	
	for (int i = 0; i < targetLength + 1; i++) // use a for loop to initial the value of first row of the dp
	{
		dp[0][i] = i; // initial the value 0 ~ target_length for first row of dp
	}

	for (int j = 0; j < sourceLength + 1; j++) // use a for loop to initial the value of first column of the dp
	{
		dp[j][0] = j; // initial the value 0 ~ source_length for first column of dp
	}
	
	// use two for loops to compute the every edit distance from many substring from source and target
	// and the [0][0] is a empty string so we don't need to compute it, it is zero
	for (int i = 1; i <= sourceLength; i++)
	{
		for (int j = 1; j <= targetLength; j++)
		{
			// if the last character of source and target are equivlent
			// the store it means the last step [i][j] is not need to trans its character, just use the [i - 1][j - 1] edit distance resultS 
			if (source[i - 1] == target[j - 1]) 
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				// else: find the min value of three substring edit distance
				// delete, insert and transform, then plus 1 because the last character is diffrent
				dp[i][j] = min({ dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1 });
			}
		}
	}

	return dp[sourceLength][targetLength]; // return the final result
}
