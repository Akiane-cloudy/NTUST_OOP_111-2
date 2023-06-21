/*****************************************************************//**
 * file : main.cpp
 * Author : ³¯«Û¾§ 
 * Create date : May 18, 2023
 * Last update : May 18, 2023
 * Description : Matrix_Multiplication
 *********************************************************************/
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;
using Matrix = vector<vector<int>>; // Declare the Matrix to be a 2-dimentional vector

// making a matrix with the document
void makeMatrix(Matrix& matrix,const string& elements);
// do the mutiplication
Matrix mutiplicate(const Matrix& matrix1, const Matrix& matrix2);
// print the matrix
void printMatrix(const Matrix& matrix);


int main()
{
	// input the data till eof
	for (int row1, row2, column1, column2; cin >> row1 >> column1 >> row2 >> column2;)
	{
		// Initial the matrix1 and matrix2
		Matrix matrix1(row1, vector<int>(column1)), matrix2(row2, vector<int>(column2));
		// declare the elements of two matrixs
		string firstElements, secondElements;

		// ignore the '\n'
		cin.ignore();
		// get the elements
		getline(cin, firstElements); 
		getline(cin, secondElements);

		// make two matrixs
		makeMatrix(matrix1, firstElements);
		makeMatrix(matrix2, secondElements);

		// if the row of the matrix2 is not equal to the column of the matrix1 then print the error message
		if (row2 != column1) {
			cout << "Matrix multiplication failed.\n";
			continue;
		}

		// do the mutiplication
		Matrix result = mutiplicate(matrix1, matrix2);

		// print the result
		printMatrix(result);
	}
}

/**
 * Intent : Making a matrix
 * pre : 
 * post : 
 * \param matrix
 * \param elements
 */
void makeMatrix(Matrix& matrix, const string& elements)
{
	// declare the string stream of the elemets
	stringstream ss(elements);

	// input the data and intitla the matrix
	for (auto& row : matrix) {
		for (auto& column : row) {
			ss >> column;
		}
	}
}

/**
 * Intent : Do the mutiplication
 * pre : 
 * post : 
 * \param matrix1
 * \param matrix2
 * \return 
 */
Matrix mutiplicate(const Matrix& matrix1, const Matrix& matrix2)
{
	// Declare the result matrix
	Matrix result(matrix1.size(), vector<int>(matrix2[0].size()));

	// Do the mutiplication and the result size is the row of matrix1 and te column of the matrix2
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[0].size(); j++) {
			for (int k = 0; k < matrix2.size(); k++) {
				// mutilpicated
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	// return the result
	return result;
}

/**
 * Intent : print the elements of the matrix
 * pre : 
 * post : 
 * \param matrix
 */
void printMatrix(const Matrix& matrix)
{
	// print the elements of the matrix
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j];
			cout << ((j == matrix[0].size() - 1) ? '\n' : ' '); // if it is not the last line then print the space other wise print the new line
		}
	}
}
