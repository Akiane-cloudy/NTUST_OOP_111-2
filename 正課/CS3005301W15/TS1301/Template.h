/*****************************************************************//**
 * file : Template.h
 * Author : 陳彥儒
 * Create date : May 31, 2023
 * Last update : May 31, 2023
 * Description : Template_Binary_Search
 *********************************************************************/
#pragma once

 /**
  * Intent : The Binary search function implement by Iterate method
  * pre : none
  * post : find the location of the key or not found
  * \param a
  * \param first
  * \param last
  * \param key
  * \param found
  * \param location
  */
template <class T>
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location)
{
	// Initial the found  and location to be false and -1
	found = false;
	location = -1;

	// Iterate the array with to position, if the start position is larger than last, then break the loop
	while (first <= last) {
		int search = (first + last) / 2; // the mid point of the search position

		// Check if the search point is eqaul to to key, if not then do the another search
		if (a[search] == key) {
			// if find the key, modify the found to be true and the location be the search position
			found = true;
			location = search;
			break;
		}
		else if (a[search] < key) {
			// if the key is larger than the search key, then let first to be search + 1
			first = search + 1;
		}
		else {
			// if the key is smaller than the search key, then let the last to be search -1
			last = search - 1;
		}
	}
}

/**
 * Intent : The Binary search function implement by Recursive method
 * pre : none
 * post : find the location of the key or not found
 * \param a
 * \param first
 * \param last
 * \param key
 * \param found
 * \param location
 */
template <class T>
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location)
{
	// If the first is larger than last then stop the recursion
	if (first <= last) {
		// Initial the foudn and location
		found = false;
		location = -1;

		// Initial the search key to be the mid point
		int search = (first + last) / 2;

		// if the key is searched then modify the found and location
		if (a[search] == key) {
			found = true;
			location = search;
		}
		else if (a[search] < key) {
			// Else condition check the search key and the key value and do the recursive
			RecBinarySearch(a, search + 1, last, key, found, location);
		}
		else {
			// Else condition check the search key and the key value and do the recursive
			RecBinarySearch(a, first, search - 1, key, found, location);
		}
	}
}
