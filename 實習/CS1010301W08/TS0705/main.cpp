/*****************************************************************//**
 * file : main.cpp
 * Author : ³¯«Û¾§ 
 * Create date : April 14, 2023
 * Last update : April 14, 2023
 * Description : Cow Calculation
 *********************************************************************/
#include <iostream>
#include <deque> // trans the string to a four digit system
using namespace std;

deque<int> initial(const string&); // return a deque that transed from the target string
void add(deque<int>&, deque<int>&); // add two deque 
void rightShift(deque<int>&); // shift right the deque
void leftShift(deque<int>&); // shift left the deque
void normalize(deque<int>&); // set the deque be a 8 decimal number

int main()
{
	int amounts; // declare amounts that represents the case amounts
	while (cin >> amounts) // read the amounts till eof
	{
		cout << "COWCULATIONS OUTPUT\n"; // print the title

		for (int i = 0; i < amounts; i++) // test the serveral cases
		{
			char opera; // declare a character opera 
			string num1, num2, input; // declare three strings num1 num2 and input

			cin >> num1 >> num2; // input num1 and num2

			deque<int> deqNum1 = initial(num1); // declare a deqNum1 to store the 4 digit system number of num1
			deque<int> deqNum2 = initial(num2); // declare a deqNum2 to store the 4 digit system number of num2
			normalize(deqNum1); // set the deque be a 8 decimal number
			normalize(deqNum2); // set the deque be a 8 decimal number

			for (int i = 0; i < 3; i++) // excute 3 operator 
			{
				cin >> opera; // input the operator

				switch (opera) // select mode
				{
				case 'A':
					add(deqNum1, deqNum2); // add two numbers
					break;
				case 'R':
					rightShift(deqNum2); // shift right the num2
					break;
				case 'L':
					leftShift(deqNum2); // shift left the num2
					break;
				case 'N':
					break;
				}
			}

			cin >> input; // get the input string
			deque<int> deqInput = initial(input); // turn the input string to a deque

			// check if the input deque is equal to the deqNum2, if they are equivalent then print out YES, otherwise is NO
			cout << ((deqInput == deqNum2) ? "YES\n" : "NO\n");
		}

		cout << "END OF OUTPUT\n"; // print the END message
	}
}

/**
 * Intent : Add two numbers
 * pre : initial the deqNum1 and deqNum2
 * post : modify the deqNum2 to the sum of num1 and num2
 * \param deqNum1
 * \param deqNum2
 */
void add(deque<int>& deqNum1, deque<int>& deqNum2)
{
	int carry = 0; // check if the it need to carry
	const int SIZE = deqNum1.size(); // decalre a const int variable SIZE to store the size of deqNum1 

	// use a for loop to compute the sum of two number
	for (int i = SIZE - 1; i >= 0; i--)
	{
		int sum = 0; // declare a sum to store sum of two elements of two deque
		
		sum = deqNum1[i] + deqNum2[i] + carry; // summary the number
		carry = sum / 4; // check if the next summation need to carry 
		sum %= 4; // let sum be the remain number of 4 becuase it is a 4 digits system
		deqNum2[i] = sum; // store the sum into deqNum2
	}
	
	if (carry)
	{
		deqNum2.push_front(carry); // if carry is 1 then need to insert one more 1 carry number front the deque
	}
}

/**
 * Intent : a function to initial the string to be a deque
 * pre : none
 * post : return a deque the transed from the string
 * \param target
 * \return 
 */
deque<int> initial(const string& target)
{
	deque<int> result; // declare a res deque
	string table = "VUCD"; // create a table V = 0, U = 1, C = 2, D = 3

	for (const auto& i : target) // use a for loop to run every elements
	{
		result.push_back(int(table.find(i))); // push the index to the result deque
	}

	return result; // return the result deque
}

/**
 * Intent : a function to shift right the deque
 * pre : none
 * post : modify the input deque
 * \param target
 */
void rightShift(deque<int>& target)
{
	target.pop_back(); // pop the last value
	target.push_front(0); // insert a 0 in font of the deque
}

/**
 * Intent : a function to shift left the deque
 * pre : none
 * post : modify the input deque
 * \param target
 */
void leftShift(deque<int>& target)
{
	target.pop_front(); // pop the first value
	target.push_back(0); // insert a 0 behinde the deque
}

/**
 * Intent : a function to normalize the deque to be a 8 decimal system
 * pre : none
 * post : normalize the deque
 * \param target
 */
void normalize(deque<int>& target)
{
	// if the amounts of the elements of the input target is less than 8
	// then insert 0 in front if the deque
	while (target.size() < 8)
	{
		target.push_front(0);
	}
}
