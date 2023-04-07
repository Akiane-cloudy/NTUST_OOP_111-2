// Name: ³¯«Û¾§ B11115004
// Date: March 9, 2023
// Last Update: March 9, 2023
// Problem statement: Adding_Large_Numbers

#include <iostream>
#include <string>
using namespace std;

struct BigInt // defined a struct "BigInt" to encapsulation the big integer number
{
	string val;

	BigInt() :val{ "" } // a constructor use to initial a empty string
	{

	};

	int size()
	{
		return val.size(); // a member function return the string val's length size 
	}
};

BigInt add(BigInt &lhs, BigInt &rhs);
void init(BigInt &lhs, BigInt &rhs);
bool isValid(BigInt& lhs, BigInt& rhs);

int main() 
{
	for (int n; cin >> n;)
	{
		for (int i(0); i < n; i++)
		{
			BigInt a, b, result;
			cin >> a.val >> b.val;

			if (isValid(a, b) == false) // if a or b is an invalid number, then print out the message
			{
				cout << "Not a valid number, please try again." << endl;
				continue;
			}

			result = add(a, b);

			cout << result.val << endl;
		}
	}
	
	return 0;
}

BigInt add(BigInt &lhs, BigInt &rhs)
{
	BigInt result;
	init(lhs, rhs);

	bool carry = false; // if carry is true that mean the next sum need to plus 1
	for (int i(lhs.size() - 1); i >= 0; i--)
	{
		int sum = (lhs.val[i] - '0') + (rhs.val[i] - '0'); // plus two number of lhs and rhs
		if (carry == true) // if carry is true, then carry and set carry is false
		{
			sum += 1;
			carry = false;
		}
		if (sum > 9)
		{
			carry = true; // this is mean the next sum need to carry
		}
		sum %= 10; // ex: 11 % 10 = 1, 5 % 10 = 5
		result.val = to_string(sum) + result.val; // plus the number into the result string, bum sum is an integer, so do the function "to_string"
	}
	if (carry == true)
	{
		result.val = '1' + result.val;
	}
	return result;
}

// if one of two big int number's val size is shorter than the another one
// then initial them to be same val size
void init(BigInt &lhs, BigInt &rhs)
{
	while (lhs.size() < rhs.size())
	{
		lhs.val = '0' + lhs.val; // if lhs is shorter than rhs, then put "0" in front of the val
	}

	while (rhs.size() < lhs.size())// if rhs is shorter than lhs, then put "0" in front of the val
	{
		rhs.val = '0' + rhs.val;
	}
}

// if the val has some weird character that mean it has something isn't number
// then return false
bool isValid(BigInt& lhs, BigInt& rhs)
{
	for (char& i : lhs.val)
	{
		if (!(i >= '0' && i <= '9'))
		{
			return false;
		}
	}
	for (char& i : rhs.val)
	{
		if (!(i >= '0' && i <= '9'))
		{
			return false;
		}
	}
	return true;
}