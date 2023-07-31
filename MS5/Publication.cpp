/***********************************************************************
// Project MS5
// File	Publication.cpp
// Version 1.0
// Name            Date            Student ID            Email
//Xinyang Wu    July 29th,2023      153821228         xwu159@myseneca.ca

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Publication.h"
using namespace std;
namespace sdds {
	Publication::Publication() {
		setEmpty();
	}
	void Publication::setEmpty() {
		if (m_title != nullptr) {
			delete[] m_title;
			m_title = nullptr;
		}
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		resetDate();
	}

	Publication::Publication(const Publication& src) {
		*this = src;
	}

	Publication& Publication::operator=(const Publication& src) {
		if (this != &src) {
			delete[] m_title;
			m_title = nullptr;
			if (src.m_title) {
				m_title = new char[strlen(src.m_title) + 1];
				strcpy(m_title, src.m_title);
			}
			strcpy(m_shelfId, src.m_shelfId);
			set(src.m_membership);
			setRef(src.m_libRef);
			m_date = src.m_date;
		}
		return *this;
	}

	Publication::~Publication() {
		delete[] m_title;
	}
	void Publication::set(int member_id) {
		m_membership = member_id;
	}
	void Publication::setRef(int value) {
		m_libRef = value;
	}
	void Publication::resetDate() {
		m_date = Date();
	}
	char Publication::type()const {
		return 'P';
	}
	bool Publication::onLoan()const {
		return (m_membership != 0);
	}
	Date Publication::checkoutDate()const {
		return m_date;
	}
	bool Publication::operator==(const char* title)const {
		return (strstr(m_title, title) != nullptr);
	}
	Publication::operator const char* ()const {
		return m_title;
	}
	int Publication::getRef()const {
		return m_libRef;
	}
	bool Publication::conIO(ios& io)const {
		return (&io == &cin || &io == &cout);
	}

	ostream& Publication::write(ostream& os) const{
		char title[SDDS_TITLE_WIDTH + 1] = { 0 };
		strncpy(title, m_title, SDDS_TITLE_WIDTH);
		if (conIO(os)) {
			os << "| " << m_shelfId << " | " << setw(30) << left << setfill('.') << title << " | ";
			if (m_membership != 0)
				os << m_membership;
			else
				os << " N/A ";
			os << " | " << m_date << " |";
		}
		else {
			os << type() ;
			os << '\t' << m_libRef << '\t' << m_shelfId << '\t' << setw(30) << m_title << '\t';
			os << m_membership;
			os << '\t' << m_date;
		}

		return os;
	}

	istream& Publication::read(istream& istr) {
		setEmpty();
		char tempTitle[256]{};
		char tempShelfId[SDDS_SHELF_ID_LEN + 1]{};
		int tempMembership = 0;
		int tempLibRef = -1;
		Date tempDate;
		if (conIO(istr)) {
			cout << "Shelf No: ";
			istr.getline(tempShelfId, SDDS_SHELF_ID_LEN + 1);
			if (strlen(tempShelfId) != SDDS_SHELF_ID_LEN) {
				istr.setstate(ios::failbit);
			}
			cout << "Title: ";
			istr.getline(tempTitle, 256);
			cout << "Date: ";
			istr >> tempDate;
		}
		else {
			istr >> tempLibRef;
			// ignores the next character in the input stream
			istr.ignore();
			istr.getline(tempShelfId, SDDS_SHELF_ID_LEN + 1, '\t');
			istr.getline(tempTitle, 256, '\t');
			istr >> tempMembership;
			istr.ignore();
			istr >> tempDate;
		}
		if (!tempDate) {
			istr.setstate(ios::failbit);
		}
		if (istr) {
			m_title = new char[strlen(tempTitle) + 1];
			strcpy(m_title, tempTitle);
			strcpy(m_shelfId, tempShelfId);
			set(tempMembership);
			m_date = tempDate;
			setRef(tempLibRef);
		}
		return istr;
	}

	Publication::operator bool() const {
		return (m_title != nullptr && m_shelfId[0] != '\0');
	}
}