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
#ifndef SDDS_SHOPPINGREC_H
#define SDDS_SHOPPINGREC_H

#include <iostream>

namespace sdds {
	const int MAX_TITLE_LENGTH = 50;
	const int MAX_QUANTITY_VALUE = 50;
	struct ShoppingRec {
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};
	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);
}
#endif
