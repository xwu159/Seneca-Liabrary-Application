/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 2 DIY
// -----------------------------------------------------------
// Name            Date            Student ID            Email
//Xinyang Wu    June 8th,2023      153821228         xwu159@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor
  provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
#include "cstring.h"
namespace sdds {
	class Label {
		char frame[9];
		char* content;
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		void readLabel();
		std::ostream& printLabel()const;
	};
}
#endif