/*****************************************************************//**
 * file : Polynomial.cpp
 * Author : ³¯«Û¾§ 
 * Create date : April 21, 2023
 * Last update : April 21, 2023
 * Description : Polynomial.cpp
 *********************************************************************/
#include "Polynomial.h"

/**
 * Intent : a constructor to initial the coefficients vector to store a 0
 * pre : create a Polynomial class
 * post : set the coefficients store a 0
 */
Polynomial::Polynomial()
{
	this->coefficients.push_back(0); // push_back a 0 to the coefficients 
}

/**
 * Intent : a constructor to initial the coefficients vector to store the param pointer
 * pre : the param must not be empty, and the size must be empty
 * post : set the coefficients vector store the input param 
 * \param param
 * \param size
 */
Polynomial::Polynomial(double* param, int size)
{
	// use transform to set the param into the coefficients deque
	transform(param, param + size, back_inserter(this->coefficients), [](const double& val)
		{
			return val;
		});
}

/**
 * Intent : a copy constructor to set this to the param
 * pre : need another polynomial
 * post : copy the another polunomial object to the current object
 * \param poly
 */
Polynomial::Polynomial(const Polynomial& poly)
{
	this->coefficients = poly.coefficients; // copy the another coefficients to the current's one
}

/**
 * Intent : return the size of this polynomial 
 * pre : none
 * post : return a the size of this polynomial
 * \return 
 */
int Polynomial::mySize()
{
	int count = 0; // declare the count to 0
	for (int i = this->coefficients.size() - 1; i >= 0; i--) // use for loop to count the none-zero coefficients from high degree
	{
		if (this->coefficients[i] == 0) count++; // count the amount of the zero coefficient of this deque
		else break;
	}

	return this->coefficients.size() - count; // return the size
}

/**
 * Intent : evaluate the value of the var into the polynomial
 * pre : the var must not be the empty 
 * post : return the result of evaluation
 * \param poly
 * \param var
 * \return 
 */
double evaluate(const Polynomial& poly, const double& var)
{
	int power = 0; // declare a power variable to count the result
	//use accumulate function to count the evaluation result 
	return accumulate(begin(poly.coefficients), end(poly.coefficients), 0.0, [&power,&var](const double& sum, const double& num)
		{
			return sum + pow(var, power++) * num; // accumulate the result 
		});
}

/**
 * Intent : overloading the operator =
 * pre : the rhs must not be empty
 * post : modify the current object equal the rhs 
 * \param rhs
 */
void Polynomial::operator=(const Polynomial& rhs)
{
	this->coefficients = rhs.coefficients; // let this coefficients to the param
}

/**
 * Intent : overloading the operator []
 * pre : the index must not be empty
 * post : return the value of the index or modify the value of the index
 * \param index
 * \return 
 */
double& Polynomial::operator[](int index)
{
	while (index >= this->coefficients.size()) // if the index is larger than the length of coefficient
	{
		this->coefficients.push_back(0); // push 0 to the back of coffcients
	}

	return this->coefficients[index]; // return the refference of the index 
}

/**
 * Intent : overloading the operator +
 * pre : the Polynaomial lhs and the constant must not be the empty
 * post : return the result 
 * \param lhs
 * \param constant
 * \return 
 */
Polynomial operator+(const Polynomial& lhs, const double& constant)
{
	Polynomial temp(lhs); // copy the lhs to the temp
	temp.coefficients[0] += constant; // let the polynomial's constant plus the constant param

	return temp; //return the result
}

/**
 * Intent : overloading the operator +
 * pre : the Polynaomial lhs and the constant must not be the empty
 * post : return the result 
 * \param constant
 * \param rhs
 * \return 
 */
Polynomial operator+(const double& constant, const Polynomial& rhs)
{
	Polynomial temp(rhs); // copy the rhs to the temp
	temp.coefficients[0] += constant; // let the polynomial's constant plus the constant param

	return temp; //return the result
}

/**
 * Intent : overloading the operator +
 * pre :  the Polynaomial lhs and the Polynaomial rhs must not be the empty
 * post : return the result 
 * \param lhs
 * \param rhs
 * \return 
 */
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs)
{
	Polynomial temp; // declare a polynomial temp to store the result of two polynomial summation
	// if the lhs is larger than the rhs, then copy the lhs to temp, otherwise copy the rhs to the temp
	temp.coefficients = (lhs.coefficients.size() > rhs.coefficients.size()) ? lhs.coefficients : rhs.coefficients;

	// use for loop to accumulating the result
	for (int i = 0; i < min(lhs.coefficients.size(), rhs.coefficients.size()); i++)
	{
		// let the two polynomial accumulate
		temp.coefficients[i] += (lhs.coefficients.size() <= rhs.coefficients.size()) ? lhs.coefficients[i] : rhs.coefficients[i];
	}

	return temp; // return the temp
}

/**
 * Intent : the operator - overloading 
 * pre : the polynomial lhs and the constant must not be the empty
 * post : return the result
 * \param lhs
 * \param constant
 * \return 
 */
Polynomial operator-(const Polynomial& lhs, const double& constant)
{
	Polynomial temp(lhs); // copy the lhs to temp
	temp.coefficients[0] -= constant; // let coefficients's constant minus constant 

	return temp; // return the result
}

/**
 * Intent : the operator - overloading  
 * pre : the polynomial lhs and the constant must not be the empty
 * post : return the result
 * \param constant
 * \param rhs
 * \return 
 */
Polynomial operator-(const double& constant, const Polynomial& rhs)
{
	Polynomial temp; // declare a temp to store the result
	temp.coefficients.clear(); // clear the coefficents first
	// use transform to let the every elements of coefficients * -1
	transform(begin(rhs.coefficients), end(rhs.coefficients), back_inserter(temp.coefficients), [](const double& val)
		{
			return val * -1;
		});

	temp.coefficients[0] += constant; // let the constant + each other

	return temp; // return the result
}

/**
 * Intent : the operator - overloading  
 * pre : the polynomial lhs and the constant must not be the empty
 * post :  return the result
 * \param lhs
 * \param rhs
 * \return 
 */
Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs)
{
	Polynomial temp(lhs); // copy the lhs to temp
	while (temp.coefficients.size() < rhs.coefficients.size())
	{
		temp.coefficients.push_back(0); // if the rhs.size() is larger than the temp, then push a 0 back to the coefficient
	}

	// use a for loop to run the coefficient
	for (int i = 0; i < rhs.coefficients.size(); i++)
	{
		temp.coefficients[i] -= rhs.coefficients[i]; // let the two plynomial minus each other
	}

	return temp; // return the result
}

/**
 * Intent :the operator * overloading 
 * pre : the polynomial lhs and the constant must not be the empty
 * post : return the result
 * \param lhs
 * \param constant
 * \return 
 */
Polynomial operator*(const Polynomial& lhs, const double& constant)
{
	Polynomial temp(lhs); // copy the lhs to the temp
	// use transform the every elements of the coeffiecient mutiply the constant
	transform(begin(temp.coefficients), end(temp.coefficients), begin(temp.coefficients), [&constant](const double& val)
		{
			return val * constant;
		});
	
	return temp; // return the result
}

/**
 * Intent : the operator * overloading
 * pre : the constant and the polynomial rhs must not be the empty
 * post : return the result
 * \param constant
 * \param rhs
 * \return 
 */
Polynomial operator*(const double& constant, const Polynomial& rhs)
{
	return rhs * constant; // return the value
}

/**
 * Intent : the operator * overloading
 * pre : the polynomial lhs and the polynomial rhs must not be the empty
 * post : return the result
 * \param lhs
 * \param rhs
 * \return 
 */
Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs)
{
	Polynomial temp; // declare the temp to store the result of two polynomial mutiplication
	const int MAX_SIZE = max(lhs.coefficients.size(), rhs.coefficients.size()); // defined a MAX_SIZE of two coefficients
	const int MIN_SIZE = min(lhs.coefficients.size(), rhs.coefficients.size()); // defined a MIN_SIZE of two coefficients

	temp.coefficients.resize(MAX_SIZE + MIN_SIZE, 0); // resize the coeffients to the sum of two coefficients size

	// use two for loop two do the mutiplication
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MIN_SIZE; j++)
		{
			// the coefficients which the position i + j is the the two coefficient mutiplication
			temp.coefficients[i + j] += (lhs.coefficients.size() > rhs.coefficients.size()) 
										? lhs.coefficients[i] * rhs.coefficients[j]
										: lhs.coefficients[j] * rhs.coefficients[i];
		}
	}
	
	return temp; // return the result
}
