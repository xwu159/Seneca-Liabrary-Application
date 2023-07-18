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
#include <limits>
#include "Line.h"
namespace sdds {
	Line::Line() :m_length(0), LblShape() {};

	Line::Line(const char* label, int length) :LblShape(label), m_length(length) {};

	void Line::getSpecs(istream& is) {
		LblShape::getSpecs(is);
		is >> m_length;
		//ignore the remaining characters in the input stream is up to and including the newline character ('\n')
		is.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	void Line::draw(ostream& os) const {
		if (m_length > 0 && label() != nullptr) {
			os << label() << endl;
			for (int i = 0; i < m_length; i++) {
				os << '=';
			}
		}
	}
}