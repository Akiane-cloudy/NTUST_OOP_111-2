/************************************************************************
File:   Source.cpp

Author:
		鍾賢廣，ea5878158@gmail.com
Modifier:
		賴祐吉，cheeryuchi@gmail.com
		陳俊宇，JYCReports@gmail.com
Comment:
		Output W,A,S,D after input, ESC to stop process.

************************************************************************/

// Name: 陳彥儒 許桓愷
// Date: Feb 22, 2023
// Last Update: Feb 24, 2023
// Problem statement: Output W,A,S,D after input, ESC to stop process.

#include <conio.h>  // For getch() function
#include <iostream> // For print out information
using namespace std;

// Define inputs and its index
enum ValidInput
{
	EW = 0,
	ES = 1,
	EA = 2,
	ED = 3,
	ESPACE = 4,
	EESC = 5,
	INVALID,
};

// Detect state of input
void keyUpdate(bool key[]);

int main()
{
	// Initialize state of key
	bool gKeyState[ValidInput::INVALID];

	// Obtain and update the input using a loop
	/************************************************************************/
	/*Please implement your code here*/

	// create a string array to store W S A D SPACE ESC
	string keyWords[ValidInput::INVALID]{ "W", "S", "A", "D", "SPACE", "ESC" };

	while (1)
	{
		keyUpdate(gKeyState);

		for (int index = 0; index < ValidInput::INVALID; index++)
		{
			if (gKeyState[index] == true)
			{
				cout << "Key " << keyWords[index] << " is pressed.";
				if (index == ValidInput::EESC) // if index is equal to EESC then end the program
				{
					cout << " End program." << endl;
				}
				else
				{
					cout << endl;
				}
				break;
			}
		}
		if (gKeyState[ValidInput::EESC] == true)
		{
			break; // ESC is pressed, end the program.
		}
	}

	return 0;
	/************************************************************************/
}

//******************************************************************
//
// * 偵測輸入狀態
//==================================================================
void keyUpdate(bool key[])
//==================================================================
{
	for (int i = 0; i < ValidInput::INVALID; i++)
	{
		key[i] = false;
	}
	char input = _getch();

	// Implement a switch for output calls
	/************************************************************************/
	/*Please implement your code here*/

	switch (input)
	{
		case 'W':
		case 'w':
			key[ValidInput::EW] = true;
			break;
		case 'A':
		case 'a':
			key[ValidInput::EA] = true;
			break;
		case 'S':
		case 's':
			key[ValidInput::ES] = true;
			break;
		case 'D':
		case 'd':
			key[ValidInput::ED] = true;
			break;
		case 27:
			key[ValidInput::EESC] = true;
			break;
	}

	/************************************************************************/
}
