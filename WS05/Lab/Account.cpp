/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 5 Part 1 Lab
// -----------------------------------------------------------
// Name            Date            Student ID            Email
//Xinyang Wu    June 10th,2023      153821228         xwu159@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Xinyang Wu    June 12th,2023     Add comments
//I have done all the coding by myself and only copied the code that my professor
  provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    // Sets the account to an 'empty' state
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }

    // Default constructor, initializes a new account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }

    // Constructor with parameters, validates and initializes an account
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }

    // Displays account information
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

    // Conversion function to bool, checks if account is valid
    Account::operator bool() const {
        return m_number >= 10000 && m_number <= 99999 && m_balance >= 0;
    }

    // Conversion function to int, returns account number
    Account::operator int() const {
        return m_number;
    }

    // Conversion function to double, returns account balance
    Account::operator double() const {
        return m_balance;
    }

    // Operator ~, checks if account is new
    bool Account::operator ~() const {
        return m_number == 0;
    }

    // Operator =, assigns a number to the account
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

    // Operator =, transfers an account's balance to another
    Account& Account::operator=(Account& another) {
        if (m_number == 0 && another) {
            m_balance = another.m_balance;
            m_number = another.m_number;
            another.m_balance = 0.0;
            another.m_number = 0;
        }
        return *this;
    }

    // Operator +=, deposits an amount to the account
    Account& Account::operator+=(double amount) {
        if (*this&&amount >= 0.0) {
            m_balance += amount;
        }
        return *this;
    }

    // Operator -=, withdraws an amount from the account
    Account& Account::operator-=(double amount) {
        if (*this && amount >= 0.0 && (m_balance >= amount)) {
            m_balance -= amount;
        }
        return *this;
    }

    // Operator <<, transfers the balance from another account to this account
    Account& Account::operator<<(Account& another) {
        if (*this&&another && this != &another) {
            m_balance += another.m_balance;
            another.m_balance = 0.0;
        }
        return *this;
    }

    // Operator >>, transfers the balance from this account to another account
    Account& Account::operator>>(Account& another) {
        if (*this && another && this != &another) {
            another.m_balance += m_balance;
            m_balance = 0.0;
        }
        return *this;
    }

    // Operator +, adds the balances of two accounts
   double operator+(const Account& left, const Account& right) {
       double sum = 0.0;
       if (left&&right) { sum = (double)left+ (double)right; }
       return sum;
   };

   // Operator +=, adds the balance of an account to a double
   double operator+=(double&left, const Account& right) {
       if (right) {
           // Checks if account is valid and then adds its balance to left
           left += (double)right;
       }
       return left;
   };


}

