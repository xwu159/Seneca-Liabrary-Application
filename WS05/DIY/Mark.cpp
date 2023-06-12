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
	Mark::Mark() {
		m_mark = 0;
		m_isValid = true;
	}
	bool Mark::valid(int mark) const{
		return (mark >=0 && mark <= 100);
	}

	Mark::Mark(int mark) {
		m_mark = mark;
		m_isValid = valid(mark);
	}

	Mark::operator int() const {
		return m_isValid ?m_mark:0;
	}

	Mark& Mark::operator+=(int mark){
		if (m_isValid && valid(m_mark + mark)) {
			m_mark += mark;
		}
		else m_mark = 0;
		return *this;
	}

	Mark& Mark::operator=(int mark) {
			m_mark = mark;
			m_isValid = valid(mark);
		return *this;
	}

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

	Mark::operator char() const {
		if (m_mark >= 0 && m_mark < 50)
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

	Mark& Mark::operator+=(const Mark& other) {
		if (m_isValid && other.m_isValid&& valid(m_mark + other.m_mark))
			m_mark += other.m_mark;
		return *this;
	}

	int operator+=(int& left, const Mark& right) {
		return left += int(right);
	}
}

