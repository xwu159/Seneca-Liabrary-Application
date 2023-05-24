/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 2 Part 1 Lab
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Student ID            Email
//Xinyang Wu    May 23rd,2023      153821228         xwu159@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor 
  provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Employee.h"

using namespace sdds;
int main() {
   if (load()) {
      display();
   }
   deallocateMemory();
   return 0;
}