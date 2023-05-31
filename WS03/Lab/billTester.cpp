/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 1 Lab
// -----------------------------------------------------------
// Name            Date            Student ID            Email
//Xinyang Wu    May 30th,2023      153821228         xwu159@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor
  provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/


#include "Bill.h"
using namespace sdds;
int main() {
   Bill B;
   B.init("Quick Shopping", 5);
   B.add("Milk 2%", 4.99, false);
   B.display();
   B.add(nullptr, 15.50, true);
   B.add("Frying Pan", 24.99, true);
   B.add("Eggs", -2.99, false);
   B.display();
   B.deallocate();
   B.init("Quick Shopping", 5);
   B.add("Milk 2%", 4.99, false);
   B.add("Spatula", 15.50, true);
   B.add("Frying Pan", 24.99, true);
   B.add("Eggs", 5.99, false);
   B.add("Bug Spray", 9.99, true);
   B.display();
   B.deallocate();
   return 0;
}