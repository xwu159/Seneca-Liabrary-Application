/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 5 Part 2 DIY
// -----------------------------------------------------------
// Name            Date            Student ID            Email
//Xinyang Wu    June 11th,2023      153821228         xwu159@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor
  provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Mark.h"
using namespace std;
using namespace sdds;
int main() {
   Mark m, n(25), k(200), p(-10);
   cout << "int ............" << endl;
   cout << int(m) << endl;
   cout << int(n) << endl;
   cout << int(k) << endl;
   cout << int(p) << endl;
   cout << "+= ............." << endl;
   cout << int(m += 20) << endl;
   cout << int(n += 20) << endl;
   cout << int(k += 20) << endl;
   cout << int(n += 60) << endl;
   cout << "= .............." << endl;
   cout << int(m = 80) << endl;
   cout << int(n = 120) << endl;
   cout << int(k = 70) << endl;
   cout << "double ........." << endl;
   m = 50; n = 80; k = 120;
   cout << double(m) << endl;
   cout << double(n) << endl;
   cout << double(k) << endl;
   cout << "char ..........." << endl;
   cout << char(m) << endl;
   cout << char(n) << endl;
   cout << char(k) << endl;
   cout << "int += Mark ..." << endl;
   int val = 60;
   cout << (val += n) << endl;
   cout << (val += k) << endl;
   return 0;
}