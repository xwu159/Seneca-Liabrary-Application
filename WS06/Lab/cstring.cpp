/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 6 Part 1 Lab
// -----------------------------------------------------------
// Name            Date            Student ID            Email
//Xinyang Wu    July 4th,2023      153821228         xwu159@myseneca.ca
// Revision History
//I have done all the coding by myself and only copied the code that my professor
  provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "cstring.h"
namespace sdds {
	void strCpy(char* des, const char* src) {
		while (*src != '\0') {
			*des = *src;
			src++;
			des++;
		}
		*des = '\0';
	}

	int strLen(const char* s) {
		int length = 0;
		while (*s != '\0') {
			length++;
			s++;
		}
		return length;
	}

	void strCat(char* des, const char* src) {
		int i, j;
		for (i = 0; des[i] != '\0'; i++) {
		}
		for (j = 0; src[j] != '\0'; j++) {
			des[i] = src[j];
			i++;
		}
		des[i] = '\0';
	}
}