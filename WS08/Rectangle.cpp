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
#include <iomanip>
#include "Rectangle.h"
namespace sdds {
	Rectangle::Rectangle() :m_width(0), m_height(0) {}

	Rectangle::Rectangle(const char* label, int width, int height) :LblShape(label), m_width(width), m_height(height) {
		if (m_height < 3 || m_width < (strlen(label) + 2)) {
			m_height = 0;
			m_width = 0;
		}
	}

	void Rectangle::getSpecs(istream& is) {
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore();
		is >> m_height;
		is.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	void Rectangle::draw(ostream& os) const {
		if (m_width > 0 && m_height > 0 && label() != nullptr) {
			os << "+";
			for (int i = 0; i < m_width - 2; i++) {
				os << "-";
			}
			os << "+" << endl;
			os << "|";
			os << left << setw(m_width - 2) << label();
			os << "|" << endl;

			for (int i = 0; i < m_height - 3; i++) {
				os << "|";
				for (int j = 0; j < m_width - 2; j++) {
					os << " ";
				}
				os << "|" << endl;
			}

			os << "+";
			for (int i = 0; i < m_width - 2; i++) {
				os << "-";
			}
			os << "+" << endl;
		}
	}
}