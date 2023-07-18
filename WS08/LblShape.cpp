/***********************************************************************
//// Intro. to Object Oriented Programming
//// Workshop 8 Part 1 Lab
//// -----------------------------------------------------------
//// Name            Date            Student ID            Email
////Xinyang Wu    July 18th,2023     153821228         xwu159@myseneca.ca
////I have done all the coding by myself and only copied the code that my professor
//  provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "LblShape.h"
namespace sdds {
	const char* LblShape::label() const {
		return m_label;
	}

	LblShape::LblShape() : m_label(nullptr) {}


	LblShape::LblShape(const char* label) : m_label(nullptr) {
		if (label != nullptr) {
			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}
	}

	LblShape:: ~LblShape() {
		delete[] m_label;
	}

	void LblShape::getSpecs(istream& is) {
		char buffer[100];
		if (is.getline(buffer, 100, ',')) {
			delete[] m_label;
			m_label = new char[strlen(buffer) + 1];
			strcpy(m_label, buffer);
		}
	}

}

