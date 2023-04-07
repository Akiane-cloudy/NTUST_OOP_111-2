/*****************************************************************//**
 * file : Source.cpp
 * Author : ³¯«Û¾§ 
 * Create date : March 16, 2023
 * Last update : March 20, 2023
 * Description : Simple_Drawing_Program
 *********************************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> map; //declare a map which size is m*n

void initialMap(int m, int n); // The function to initial the map m*n
void printMap(); // The function to print the map
bool isShapeValid(int, int, int); // check if the square is valid
bool isShapeValid(int, int, int, string); // check if the triangle is valid
bool isShapeValid(int, int, int, int); // check if the line is valid
void draw(int, int, int); // draw the square
void draw(int, int, int, string); // draw the triangle
void draw(int, int, int, int); // draw the line

int main()
{
	int m, n; // this length and width of the map
	cin >> m >> n; // input the m and n
	initialMap(m, n); // initial the map to a m*n map

	while (1)
	{
		string shape; // check what shape that user want to draw
		cin >> shape;

		if (shape == "EXIT") // if user enters EXIT then end the program
		{
			break;
		}
		else if (shape == "S") // if shape is S that mean user want to draw a square
		{
			int width, x, y;
			cin >> width >> x >> y; // input the width and the position x and y

			if (isShapeValid(width, x, y) == true) // check if the picture is valid
			{
				draw(width, x, y); // draw the picture
				printMap(); // print out the map
			}
			else
			{
				cout << "Out of range." << endl << endl; // if that is invalid then print "out of range."
			}
		}
		else if (shape == "L") // if shape is L that mean user want to draw a line
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2; // input the position x1,x2,x3,x4

			if (isShapeValid(x1, y1, x2, y2) == true) // check if the picture is valid
			{
				draw(x1, y1, x2, y2); // draw the picture
				printMap(); // print out the map
			}
			else
			{
				cout << "Out of range." << endl << endl; // if that is invalid then print "out of range."
			}
		}
		else if (shape == "T") // if shape is L that mean user want to draw a triangle
		{
			int width, x, y;
			string face;
			cin >> width >> x >> y >> face; // input the width and position x and y and what it face to

			if (isShapeValid(width, x, y, face) == true) // check if the picture is valid
			{
				draw(width, x, y, face); // draw the picture
				printMap(); // print out the map
			}
			else
			{
				cout << "Out of range." << endl << endl; // if that is invalid then print "out of range."
			}
		}
	}
}

/**
 * Intent : The function to initial the map m*n
 * pre : m > 0, n > 0
 * post : the map will be initial
 * \param m
 * \param n
 */
void initialMap(int m, int n)
{
	for (int i(0); i < n; i++)
	{
		vector<char> temp; // create a temp vector to store every value for one dimension
		for (int j(0); j < m; j++)
		{
			temp.push_back('*');
		}
		map.push_back(temp); //create 2 dimension vector
	}
}

/**
 * Intent : print the map
 * pre : none
 * post : print the map
 */
void printMap()
{
	for (auto& column : map)
	{
		for (auto& row : column)
		{
			cout << row; // print out the row of map 
		}
		cout << endl; // change the column and make new line
	}
	cout << endl;
}

/**
 * Intent : check if the square is valid
 * pre : width >= 0, x and y must have value
 * post : return the square is valid to draw or not 
 * \param width
 * \param x
 * \param y
 * \return 
 */
bool isShapeValid(int width, int x, int y)
{
	bool isXValid = (x + width) <= map[0].size(); // if the x + width is over than map each row size then that is over range
	bool isYValid = (y + width) <= map.size(); // if the y + width is over than map each column size then that is over range

	return isXValid && isYValid; // return the square is valid to draw or not 
}

/**
 * Intent : check if the triangle is valid
 * pre : width >= 0, x and y must have value, and the "face" must be LU¡BD || RU¡BD
 * post : return the triangle is valid to draw or not 
 * \param width
 * \param x
 * \param y
 * \param face
 * \return 
 */
bool isShapeValid(int width, int x, int y, string face)
{
	bool isXValid, isYValid;

	if (face == "LU")
	{
		isXValid = (x - (width - 1) >= 0); // the x can not be negative number
		isYValid = (y - (width - 1) >= 0); // the y can not be negative number

		return isXValid && isYValid; // if x and y are all valid then return true
	}
	else if (face == "LD")
	{
		isXValid = (x - (width - 1) >= 0); // the x can not be negative number
		isYValid = (y + (width - 1) < map.size()); // the y can not larger than map's width

		return isXValid && isYValid; // if x and y are all valid then return true
	}
	else if (face == "RU")
	{
		isXValid = (x + (width - 1) < map[0].size()); // the x can not larger than map's length
		isYValid = (y - (width - 1) >= 0); // the y can not be negative number

		return isXValid && isYValid;// if x and y are all valid then return true
	}
	else if (face == "RD")
	{
		isXValid = (x + (width - 1) < map[0].size()); // the x can not larger than map's length
		isYValid = (y + (width - 1) < map.size()); // the y can not larger than map's width

		return isXValid && isYValid; // if x and y are all valid then return true
	}
}

/**
 * Intent : check if the line is valid 
 * pre : x1, y1, x2, y2 must have value
 * post : return if x and y are all valid
 * \param x1
 * \param y1
 * \param x2
 * \param y2
 * \return 
 */
bool isShapeValid(int x1, int y1, int x2, int y2)
{
	bool isXValid = (x1 >= 0 && x1 < map[0].size() && x2 >= 0 && x2 < map[0].size()); // if x1 and x1 are all in the map then x is valid
	bool isYValid = (y1 >= 0 && x1 < map.size() && y2 >= 0 && y2 < map.size()); // if y1 and y2 are all in the map then y is valid

	return isXValid && isYValid; // if x and y are all valid then return true
}

/**
 * Intent : draw the square
 * pre : width can not be the negative number, and x¡By must exist
 * post : modify the map to draw a square
 * \param width
 * \param x
 * \param y
 */
void draw(int width, int x, int y)
{
	for (int i = y; i < y + width; i++) // draw the y to column of y + width
	{
		for (int j = x; j < x + width; j++) // draw the x to row of x + width
		{
			map[i][j] = 'X';
		}
	}
}

/**
 * Intent : draw the line
 * pre : x1, y1, x2, y2 must exist 
 * post : modify the map to draw a line
 * \param x1
 * \param y1
 * \param x2
 * \param y2
 */
void draw(int x1, int y1, int x2, int y2)
{
	while ((x1 != x2) || (y1 != y2)) // draw the line until the x1 == x2 and y1 == y2
	{
		map[y1][x1] = 'X';

		if (x1 != x2)
		{
			x1 += (x2 - x1) / (int)abs(x2 - x1); // x + an unit vector of the destination
		}

		if (y1 != y2)
		{
			y1 += (y2 - y1) / (int)abs(y2 - y1); // y + an unit vector of the destination
		}
	}

	map[y1][x1] = 'X'; // because the loop didn't run the final turn
}

/**
 * Intent : draw the triangle
 * pre : isShapeValid of triangle must be true
 * post : modify the map to draw a triangle
 * \param width
 * \param x
 * \param y
 * \param face
 */
void draw(int width, int x, int y, string face)
{
	if (face == "LU")
	{
		for (int i = y, k = 0; i > y - width; i--, k++) // run every column of y and set k to count what turn should x plus to
		{
			for (int j = x; j > x - width + k; j--) // run every row of x 
			{
				map[i][j] = 'X'; // modifying the map 
			}
		}
	}
	else if (face == "LD")
	{
		for (int i = y, k = 0; i < y + width; i++, k++) // run every column of y and set k to count what turn should x plus to
		{
			for (int j = x; j > x - width + k; j--) // run every row of x 
			{
				map[i][j] = 'X' ;// modifying the map 
			}
		}
	}
	else if (face == "RU")
	{
		for (int i = y, k = 0; i > y - width ; i--, k++) // run every column of y and set k to count what turn should x minus to
		{
			for (int j = x; j < x + width - k; j++) // run every row of x 
			{
				map[i][j] = 'X'; // modifying the map 
			}
		}
	}
	else if (face == "RD")
	{
		for (int i = y, k = 0; i < y + width; i++, k++) // run every column of y and set k to count what turn should x minus to
		{
			for (int j = x; j < x + width - k; j++) // run every row of x 
			{
				map[i][j] = 'X'; // modifying the map 
			}
		}
	}
}

