/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 1 Part 2
// Version 1.0
// -----------------------------------------------------------
// Name            Date            Email                  Student ID
//Xinyang Wu     May 17th,2023   xwu159@myseneca.ca       153821228
//I have done all the coding by myself and only copied the code that my
  professor provided to complete my workshops and assignments.//
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

	void strnCpy(char* des, const char* src, int len) {
		int i;
		for (i = 0; i < len && src[i] != '\0'; i++) {
			des[i] = src[i];
		}
		if (i < len) {
			des[i] = '\0';
		}
	}

	int strCmp(const char* s1, const char* s2) {
		int i;
		for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
		return s1[i] - s2[i];
	}

	int strnCmp(const char* s1, const char* s2, int len) {
		int i = 0;
		int result = 0;
		while (i < len && s1[i] && s2[i] && result == 0) {
			if (s1[i] != s2[i]) {
				result = s1[i] - s2[i];
			}
			i++;
		}
		return result;
	}

	int strLen(const char* s) {
		int length = 0;
		while (*s != '\0') {
			length++;
			s++;
		}
		return length;
	}

	const char* strStr(const char* str1, const char* str2) {
		int i, j;
		if (!*str2) {
			return str1;
		}
		for (i = 0; str1[i] != '\0'; i++) {
			for (j = 0; str2[j] != '\0' && str1[i + j] != '\0' && str1[i + j] == str2[j]; j++) {
			}
				if (str2[j] == '\0') {
					return &str1[i];
				}
		}
		return nullptr;
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