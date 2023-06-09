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
#include "LabelMaker.h"
using namespace std;
namespace sdds {
	LabelMaker::LabelMaker(int noOfLabels) {
		this->noOfLabels = noOfLabels;
		this->labels = new Label[noOfLabels];
	}

	void LabelMaker::readLabels() {
		cout << "Enter " << noOfLabels << " labels:" << endl;
		int i = 0;
		for (i = 0; i < noOfLabels; i++) {
			cout << "Enter label number " << i + 1 << endl<<"> ";
			labels[i].readLabel();
		}
	}

	void LabelMaker::printLabels() {
		int i = 0;
		for (i = 0; i < noOfLabels; i++) {
			labels[i].printLabel();
		}
	}

	LabelMaker::~LabelMaker() {
		delete[] labels;
	}

}