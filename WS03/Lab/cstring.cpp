/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 1 Lab
// -----------------------------------------------------------
// Name            Date            Student ID            Email
//Xinyang Wu    May 30th,2023      153821228         xwu159@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor
  provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "cstring.h"
namespace sdds {
	void strnCpy(char* des, const char* src, int len) {
		int i;
		for (i = 0; i < len && src[i] != '\0'; i++) {
			des[i] = src[i];
		}
		if (i < len) {
			des[i] = '\0';
		}
	}

}