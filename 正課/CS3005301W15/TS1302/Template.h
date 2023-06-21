#pragma once

/**
 * Intent : Create a function to compute the absolute value
 * pre : none
 * post : return the abolute value
 * \param num1
 * \param num2
 * \return
 */
template <class T>
auto absoluteValue(const T& num1, const T& num2)
{
	// return the absolute value of two nums
	return ((num1 - num2) < 0) ? num2 - num1 : num1 - num2;
}
