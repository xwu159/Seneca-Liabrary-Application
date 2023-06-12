/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 5 Part 1 Lab
// -----------------------------------------------------------
// Name            Date            Student ID            Email
//Xinyang Wu    June 10th,2023      153821228         xwu159@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor
  provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    Account::operator bool() const {
        return m_number >= 10000 && m_number <= 99999 && m_balance >= 0;
    }

    Account::operator int() const {
        return m_number;
    }

    Account::operator double() const {
        return m_balance;
    }

    bool Account::operator ~() const {
        return m_number == 0;
    }

    Account& Account::operator=(int number) {
        if (m_number==0 && number >= 10000 && number <= 99999) {
            m_number = number;
        }
        else if(m_number == 0){
            m_number = -1;
            m_balance = 0.0;
        }
        return *this;
    }

    Account& Account::operator=(Account& another) {
        if (m_number == 0 && another) {
            m_balance = another.m_balance;
            m_number = another.m_number;
            another.m_balance = 0.0;
            another.m_number = 0;
        }
        return *this;
    }

    Account& Account::operator+=(double amount) {
        if (*this&&amount >= 0.0) {
            m_balance += amount;
        }
        return *this;
    }

    Account& Account::operator-=(double amount) {
        if (*this && amount >= 0.0 && (m_balance >= amount)) {
            m_balance -= amount;
        }
        return *this;
    }

    Account& Account::operator<<(Account& another) {
        if (*this&&another && this != &another) {
            m_balance += another.m_balance;
            another.m_balance = 0.0;
        }
        return *this;
    }

    Account& Account::operator>>(Account& another) {
        if (*this && another && this != &another) {
            another.m_balance += m_balance;
            m_balance = 0.0;
        }
        return *this;
    }

   double operator+(const Account& left, const Account& right) {
       double sum = 0.0;
       if (left&&right) { sum = (double)left+ (double)right; }
       return sum;
   };

   double operator+=(double&left, const Account& right) {
       if (right) {
           left += (double)right;
       }
       return left;
   };


}

