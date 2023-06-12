///***********************************************************************
//// Intro. to Object Oriented Programming
//// Workshop 5 Part 2 DIY
//// -----------------------------------------------------------
//// Name            Date            Student ID            Email
////Xinyang Wu    June 11th,2023      153821228         xwu159@myseneca.ca
////I have done all the coding by myself and only copied the code that my professor
//  provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////
//***********************************************************************/
#include <iostream>
#include "Mark.h"
using namespace std;
namespace sdds {
	// Default constructor
	Mark::Mark() {
		m_mark = 0;
		m_isValid = true;
	}

	// Function to check if a mark is valid (0 to 100 inclusive)
	bool Mark::valid(int mark) const{
		return (mark >=0 && mark <= 100);
	}

	// Constructor with one parameter
	Mark::Mark(int mark) {
		m_mark = mark;
		m_isValid = valid(mark);// Check if the mark is valid
	}

	// Conversion function to int
	Mark::operator int() const {
		return m_isValid ?m_mark:0;
	}

	// += operator overloaded to add a mark to the current object
	Mark& Mark::operator+=(int mark){
		if (m_isValid && valid(m_mark + mark)) {
			m_mark += mark;
		}
		else m_mark = 0;
		return *this;
	}

	// = operator overloaded to assign a mark to the current object
	Mark& Mark::operator=(int mark) {
			m_mark = mark;
			m_isValid = valid(mark);
		return *this;
	}

	// Conversion function to double
	Mark::operator double() const {
		if (m_mark >= 0 && m_mark < 50)
			return 0.0;
		else if (m_mark >= 50 && m_mark < 60)
			return 1.0;
		else if (m_mark >= 60 && m_mark < 70)
			return 2.0;
		else if (m_mark >= 70 && m_mark < 80)
			return 3.0;
		else if (m_mark >= 80 && m_mark <= 100)
			return 4.0;
		else return 0.0;
	}

	// Conversion function to char
	Mark::operator char() const {
		if (m_mark > 0 && m_mark < 50)
			return 'F';
		else if (m_mark >= 50 && m_mark < 60)
			return 'D';
		else if (m_mark >= 60 && m_mark < 70)
			return 'C';
		else if (m_mark >= 70 && m_mark < 80)
			return 'B';
		else if (m_mark >= 80 && m_mark <= 100)
			return 'A';
		else {
			return 'X';
		}
	}

	// += operator overloaded to add another Mark object to the current object
	Mark& Mark::operator+=(const Mark& other) {
		if (m_isValid && other.m_isValid&& valid(m_mark + other.m_mark))
			m_mark += other.m_mark;
		return *this;
	}

	// += operator overloaded to add a Mark object to an int
	int operator+=(int& left, const Mark& right) {
		return left += int(right);
	}
}

