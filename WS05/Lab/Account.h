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
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator ~() const;
      Account& operator=(int number);
      Account& operator=(Account& another);
      Account& operator+=(double amount);
      Account& operator-=(double amount);
      Account& operator<<(Account& another);
      Account& operator>>(Account& another);
   };
   double operator+(const Account& left,const Account&right);
   double operator+=(double&left,const Account&right);
   
}
#endif // SDDS_ACCOUNT_H_