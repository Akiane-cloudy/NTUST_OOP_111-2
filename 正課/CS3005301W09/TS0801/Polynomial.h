/*****************************************************************//**
 * file : Polynomial.h
 * Author : ³¯«Û¾§ 
 * Create date : April 21, 2023
 * Last update : April 21, 2023
 * Description : Polynomial.h
 *********************************************************************/
#pragma once

#include <numeric> // accumulate function
#include <iterator> // bakc_inserter
#include <algorithm> // transform
#include <deque>
#include <cmath>

using namespace std;

// defined a Polynomial class
class Polynomial
{ 
private:
	deque<double> coefficients; // defined a private property coefficients

public:
	friend double evaluate(const Polynomial& poly, const double& var); // a function which is use to evaluate the value of the var
	friend Polynomial operator+(const Polynomial& lhs, const double& constant); // the operator+ overloading
	friend Polynomial operator+(const double& constant, const Polynomial& rhs); // the operator+ overloading
	friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs); // the operator+ overloading
	friend Polynomial operator-(const Polynomial& lhs, const double& constant); // the operator- overloading
	friend Polynomial operator-(const double& constant, const Polynomial& rhs); // the operator- overloading
	friend Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs); // the operator- overloading
	friend Polynomial operator*(const Polynomial& lhs, const double& constant); // the operator* overloading
	friend Polynomial operator*(const double& constant, const Polynomial& rhs); // the operator* overloading
	friend Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs); // the operator* overloading
	

public:
	void operator=(const Polynomial&); // the operator= overloading
	double& operator[](int index); // the operator[] overloading
	Polynomial(); // a Polynomial constructor 
	Polynomial(double* param, int size); // a Polynomial constructor that has param
	Polynomial(const Polynomial& poly); // a Polynomial cpoy constructor 
	int mySize(); // return the coeffiecirnts size
};



