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
#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include <iostream>
#include "ShoppingRec.h"

namespace sdds {
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}
#endif