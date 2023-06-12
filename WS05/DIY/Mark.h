/***********************************************************************
 Intro. to Object Oriented Programming
 Workshop 5 Part 2 DIY
 -----------------------------------------------------------
 Name            Date            Student ID            Email
Xinyang Wu    June 11th,2023      153821228         xwu159@myseneca.ca
I have done all the coding by myself and only copied the code that my professor
  provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef MARH_H
#define MARK_H
namespace sdds {
	class Mark {
		int m_mark;
		bool m_isValid;
	public:
		Mark();
		bool valid(int mark) const;
		Mark(int);
		operator int() const;
		Mark& operator+=(int mark);
		Mark& operator=(int);
		operator double() const;
		operator char() const;
		Mark& operator+=(const Mark& other);
	};
	int operator+=(int& left, const Mark& right);
}
#endif







