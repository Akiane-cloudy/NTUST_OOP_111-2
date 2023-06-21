/*****************************************************************//**
 * file : VecNf.h
 * Author : ³¯«Û¾§ 
 * Create date : May 2, 2023
 * Last update : May 2, 2023
 * Description : VecNf.h
 *********************************************************************/
#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Declare VecNf class
class VecNf
{
private:
	vector<double> rowVector; // Use a rowVector to store the value of each dimention 

public:
	VecNf(); // A default constructor
	VecNf(float* dest, int cnt); // A constructor to store the value from the input pointer with its size
	VecNf(const VecNf& rhs); // A copy constructor with the input VecNf object

public:
	int Size(); // A Size function to return the vector size
	void operator=(const VecNf&); // A assignment operator overloading to copy the vector from the input VecNf object
	double& operator[](const int&); // Return the value from the input index
	VecNf operator+(const VecNf&); // Overloading the operator+ with the another VecNf object
	VecNf operator-(const VecNf&); // Overloading the operator- with the another VecNf object
	double operator*(const VecNf&); // Overloading the operator* with the another VecNf object
	friend VecNf operator*(const float&, const VecNf&); // Overloading the operator* with the constant and a VecNf object
};
