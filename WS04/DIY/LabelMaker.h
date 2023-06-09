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
#ifndef SDDS_LABELMAKER_H_
#define SDDS_LABELMAKER_H_
#include <iostream>
#include "Label.h"
#include "cstring.h"
namespace sdds {
	class LabelMaker {
		Label* labels;
		int noOfLabels;
	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}
#endif 
