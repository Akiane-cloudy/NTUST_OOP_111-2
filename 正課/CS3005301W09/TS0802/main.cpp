/*****************************************************************//**
 * file : main.cpp
 * Author : ³¯«Û¾§ 
 * Create date : April 22, 2023
 * Last update : April 22, 2023
 * Description : Matrix_multiplication
 *********************************************************************/
#include <iostream>
#include <vector>
using namespace std;

// declare a function mutiplication to do the mutiplication with two matrix 
vector<vector<int>> multiplication(const vector<vector<int>>&, const vector<vector<int>>);
// a function to initial the matrix
void setMatrix(vector<vector<int>>& matrix, int length, int width);
// print the result 
void printResult(const vector<vector<int>>&);

int main() {
	int length1, width1, length2, width2; // declare two length and two width 
	// input the data till eof
	while (cin >> length1 >> width1 >> length2 >> width2) {
		// declare the matrix1
		vector<vector<int>> matrix1(length1, vector<int>(width1, 0));
		// declare the matrix2
		vector<vector<int>> matrix2(length2, vector<int>(width2, 0));
		setMatrix(matrix1, length1, width1); // initial the matrix1
		setMatrix(matrix2, length2, width2); // initial the matrix2

		if (width1 != length2) {
			cout << "Matrix multiplication failed.\n"; // if two matrix can't do the mutiplication then print the error message
			continue;
		}

		vector<vector<int>> result = multiplication(matrix1, matrix2); // let result store the result of the multiplication
		printResult(result); // print the result
	}
}

/**
 * Intent : a function that use to initial the matrix from the input data
 * pre : the matrix, length and width must not be empty 
 * post : initial the input matrix and let it store the input data
 * \param matrix
 * \param length
 * \param width
 */
void setMatrix(vector<vector<int>>& matrix, int length, int width) {
	// use two for loops to initial the matrix
	for (int row = 0; row < length; row++) {
		for (int column = 0; column < width; column++) {
			cin >> matrix[row][column]; // input the matrix data
		}
	}
}

/**
 * Intent : a function that do the mutiplication of two matrixs
 * pre : the matrix1 and the matrix2 must initial
 * post : return a matrix that is the result of two matrix mutiplication
 * \param matrix1
 * \param matrix2
 * \return 
 */
vector<vector<int>> multiplication(const vector<vector<int>>& matrix1, const vector<vector<int>> matrix2) {
	// declare a two dimetional vector result and set its size two be the legnth provided by matrix1 and the width provided by matrix2
	vector<vector<int>> result(matrix1.size(), vector<int>(matrix2[0].size(), 0));

	// use three for loop to do the mutiplication
	for (int i = 0; i < matrix1.size(); i++) {
		for (int j = 0; j < matrix2[0].size(); j++) {
			int sum = 0; // declare the sum to 0
			for (int k = 0; k < matrix2.size(); k++) {
				sum += matrix1[i][k] * matrix2[k][j]; // do the mutiplication
			}
			result[i][j] = sum; // store the value to the result vector
		}
	}

	return result; // return the result
}

/**
 * Intent : a function that print the all elements of the result vector
 * pre : the result vector must exist and store the value of two matrix mutiplication
 * post : print the result's elements
 * \param result
 */
void printResult(const vector<vector<int>>& result) {
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[0].size(); j++) {
			cout << result[i][j]; // print the elements of the result
			if (j != result[0].size() - 1) cout << ' '; // just don't print the space if it is the last elements of the result vector
		}
		cout << endl; // print line
	}
}
