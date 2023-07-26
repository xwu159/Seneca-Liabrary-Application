/***********************************************************************
// Project MS4
// Version 1.0
// Name            Date            Student ID            Email
//Xinyang Wu    July 25th,2023      153821228         xwu159@myseneca.ca

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Book.h"
using namespace std;
namespace sdds {
	Book::Book():Publication()
	{
		m_authorName = nullptr;
	}
	Book::Book(const Book& book):Publication(book)
	{
		*this = book;
	}

	Book& Book::operator=(const Book& book)
	{
		if (this != &book) {
			Publication::operator=(book);
			delete[] m_authorName;
			if (book.m_authorName) {
				m_authorName = new char [strlen(book.m_authorName) + 1];
				strcpy(m_authorName, book.m_authorName);
			}
			else {
				m_authorName = nullptr;
			}
		}
		return *this;
	}

	Book::~Book()
	{
		delete[] m_authorName;
	}

	char Book::type() const
	{
		return 'B';
	}

	ostream& Book::write(ostream& os) const
	{
		Publication::write(os);
		if (conIO(os)) {
			char authorName[SDDS_AUTHOR_WIDTH + 1] = { 0 };
			strncpy(authorName, m_authorName, SDDS_AUTHOR_WIDTH);
			authorName[SDDS_AUTHOR_WIDTH] = '\0';
			os << " "<<setw(SDDS_AUTHOR_WIDTH)<< left<< setfill(' ') << authorName << " |";
		}
		else {
			os << '\t'<< m_authorName;
		}
		return os;
	}

	istream& Book::read(istream& istr)
	{
		Publication::read(istr);
		if (m_authorName) {
			delete[] m_authorName;
			m_authorName = nullptr;
		}
		if (conIO(istr)) {
			istr.ignore();
			cout << "Author: ";
		}
		else {
			istr.ignore(1000, '\t');
		}
		char tempAuthorName[257] = {0};
		istr.get(tempAuthorName, 256);
		if (istr) {
			m_authorName = new char[strlen(tempAuthorName) + 1];
			strcpy(m_authorName, tempAuthorName);
		}
		return istr;
	}

	void Book::set(int member_id)
	{
		Publication::set(member_id);
		Publication::resetDate();
	}

	Book::operator bool() const
	{
		return (m_authorName!=nullptr&&m_authorName[0]!='\0' && Publication::operator bool());
	}



}
