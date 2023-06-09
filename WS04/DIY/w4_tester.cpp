/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 2 DIY
// -----------------------------------------------------------
// Name            Date            Student ID            Email
//Xinyang Wu    June 8th,2023      153821228         xwu159@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor
  provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Label.h"
#include "LabelMaker.h"
using namespace sdds;
using namespace std;
int main() {
   int noOfLabels;
   // Create a lable for the program title:
   Label 
      theProgram("/-\\|/-\\|", "The Label Maker Program"),
      EmptyOne1,
      EmptyOne2("ABCDEFGH");
   cout << "EmptyOne1" << endl;
   EmptyOne1.printLabel() << endl;
   cout << "EmptyOne2" << endl;
   EmptyOne2.printLabel() << endl;
   theProgram.printLabel() << endl << endl;
   // ask for number of labels to get created
   cout << "Number of labels to create: ";
   cin >> noOfLabels;
   cin.ignore(10000, '\n');
   // Create a LabelMaker for the number of 
   // the labels requested
   LabelMaker lblMkr(noOfLabels);
   // Ask for the label texts
   lblMkr.readLabels();
   // Print the labels
   lblMkr.printLabels();
   return 0;
}