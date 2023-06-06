/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 1 Lab
// -----------------------------------------------------------
// Name            Date            Student ID            Email
//Xinyang Wu    June 6th,2023       153821228         xwu159@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor
  provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "cstring.h"
namespace sdds {
	int strCmp(const char* s1, const char* s2) {
		int i;
		for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
		return s1[i] - s2[i];
	}
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
}