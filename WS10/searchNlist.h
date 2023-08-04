/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 10
// Version 1.0
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Email
//Xinyang Wu	August 4th,2023	  xwu159@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor
//provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

#include <iostream>
#include "Collection.h"
#include "ReadWrite.h"

namespace sdds {
	/// <summary>
	///  Searches for elements matching the given key in an array and adds them to a collection.
	/// </summary>
	/// <typeparam name="T">Type of elements in the array and the collection.</typeparam>
	/// <typeparam name="K">Type of the key to search for</typeparam>
	/// <param name="col">A reference to a Collection of templated objects</param>
	/// <param name="arr">An array of templated objects</param>
	/// <param name="arraySize">Number of elements in the array of objects</param>
	/// <param name="key">A key templated value to search for, in the array of objects. </param>
	/// <returns>True if at least one match is found and added to the collection, false otherwise.</returns>
	template <typename T, typename K>
	bool search(Collection<T>& col, T arr[], size_t arraySize, const K& key) 
	{
		bool found = false;
		for (size_t i = 0; i < arraySize; i++) {
			if (arr[i] == key) { // Requirement: T must support the equality operator (==)
				col.add(arr[i]); // Requirement: T must be addable to Collection<T>
				found = true;
			}
		}
		return found;
	}

	/// <summary>
	/// Lists all the elements of an array.
	/// </summary>
	/// <typeparam name="T">Type of elements in the array</typeparam>
	/// <param name="title">Title to be printed as the Title of the list</param>
	/// <param name="arr">Array of elements to be listed</param>
	/// <param name="arrSize">Number of elements in the array</param>
	template <typename T>
	void listArrayElements(const char* title, const T arr[], size_t arrSize) {
		std::cout << title << std::endl;
		for (size_t i = 0; i < arrSize; i++) {
			std::cout << i + 1 << ": " << arr[i] << std::endl;
		}
	}
}
#endif