/*****************************************************************//**
 * file : VecNf.cpp
 * Author : ³¯«Û¾§ 
 * Create date : May 2, 2023
 * Last update : May 2, 2023
 * Description : Dim_Vector
 *********************************************************************/
#include "VecNf.h"

/**
 * Intent : A default constuctor to initial the vector to be a one dimention vector with a zero element
 * pre : There is no params inputed 
 * post : Initial the rowVector to be a one dimention vector
 */
VecNf::VecNf()
{
	this->rowVector.push_back(0); // Push a zero element to the vector
}

/**
 * Intent : A constructor to initial the vector to store the value from the pointer with its dimention
 * pre : The dest point must not be empty
 * post : Intitial the vector value
 * \param dest
 * \param cnt
 */
VecNf::VecNf(float* dest, int cnt)
{
	// Use transform to store the elements from the input pointer
	transform(dest, dest + cnt, back_inserter(this->rowVector), [](const double& num)
		{
			return num;
		});
}

/**
 * Intent : A copy constructor to copy the other VecNf 
 * pre : The rhs VecNf object msut exist
 * post : Let this object become to the rhs vector
 * \param rhs
 */
VecNf::VecNf(const VecNf& rhs)
{
	// Use transform to copy the value from the rhs vector
	transform(begin(rhs.rowVector), end(rhs.rowVector), back_inserter(this->rowVector), [](const double& num)
		{
			return num;
		});
}

/**
 * Intent : A Size member function to return the size of the vector
 * pre : none
 * post : Return the size of the vector
 * \return 
 */
int VecNf::Size()
{
	// Return the size of the vector
	return this->rowVector.size();
}

/**
 * Intent : Overloading the operator= to assign the rhs to this object
 * pre : The rhs object must exist
 * post : Copy the rhs to this
 * \param rhs
 */
void VecNf::operator=(const VecNf& rhs)
{
	// Print a "ASSIGNMENT!!!" message
	cout << "ASSIGNMENT!!!" << '\n';

	// Declare a temp to copy the rhs 
	VecNf temp(rhs);
	this->rowVector = temp.rowVector; // Modify this's vector to be the temp's
}

/**
 * Intent : Return the elements of the index of the rowVector
 * pre : None
 * post : Return the element(reference) of the vector 
 * \param index
 * \return 
 */
double& VecNf::operator[](const int& index)
{
	// Return the element of the rowVector 
	return this->rowVector[index];
}

/**
 * Intent : Overloading the operator+ to add this and the rhs object
 * pre : The rhs VecNf object must exist
 * post : Return the resualt of adding two object
 * \param rhs
 * \return 
 */
VecNf VecNf::operator+(const VecNf& rhs)
{
	// Check that if the dimention of two vectors are different, then print a error message and return zero vector
	if (this->Size() != rhs.rowVector.size()) {
		cout << "dimensions inconsistent" << '\n';
		return VecNf({ 0 }, 1);
	}
	
	// Declare a const integer size of two vector size
	const int size = max(this->rowVector.size(), rhs.rowVector.size());
	// Use a point and assign it serveral size to store the result of two vectors adding
	float* list = new float[size];
	
	for (int i = 0; i < size; i++){
		list[i] = this->rowVector[i] + rhs.rowVector[i]; // Add with two vectors
	}

	return VecNf(list, size); // Return the VecNf object with the result and its size
}

/**
 * Intent : Overloading the operator- to store the defference of two vector
 * pre : The rhs VecNf object must exist
 * post : Return a VecNf object with the result of the deffrence of two vectors
 * \param rhs
 * \return 
 */
VecNf VecNf::operator-(const VecNf& rhs)
{
	VecNf temp(rhs); // Declare a temp object to copy the rhs
	for (double& num : temp.rowVector) {
		num *= -1; // Let the elements of the temp * -1
	}

	return (*this) + temp; // Return (*this) + (-1)rhs 
}

/**
 * Intent : Overloading the operator* 
 * pre : The rhs object must exist
 * post : Return the result of the inner product of two vector 
 * \param rhs
 * \return 
 */
double VecNf::operator*(const VecNf& rhs)
{
	// If the size of two vector are difference then print an error message and return 0
	if (this->Size() != rhs.rowVector.size()) {
		cout << "dimensions inconsistent" << '\n';
		return 0.0;
	}

	// Declare a const integer size to store the size of two rowVector
	const int size = min(this->rowVector.size(), rhs.rowVector.size());
	double sum = 0; // Use sum to accumulate the result

	for (int i = 0; i < size; i++)
	{
		sum += this->rowVector[i] * rhs.rowVector[i]; // Compute the inner product
	}

	return sum; // Return the result of the inner product of two vector
}

/**
 * Intent : Compute a new vector with a constant
 * pre : None
 * post : Return a VecNf object to store the result of the product
 * \param target
 * \param rhs
 * \return 
 */
VecNf operator*(const float& target, const VecNf& rhs)
{
	VecNf temp(rhs); // Copy the rhs to temp
	for (auto& num : temp.rowVector) {
		num *= target; // Mutiply the constant with vector
	}

	return temp; // Return the temp
}


