/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 1 Part1
// Version 1.0
// -----------------------------------------------------------
// Name            Date            Email                  Student ID
//Xinyang Wu     May 16th,2023   xwu159@myseneca.ca       153821228
//I have done all the coding by myself and only copied the code that my
  professor provided to complete my workshops and assignments.//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H

namespace sdds {
	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}
#endif