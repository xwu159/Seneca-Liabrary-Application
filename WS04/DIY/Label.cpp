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
using namespace std;
namespace sdds {
	Label::Label() {
		strCpy(frame, "+-+|+-+|");
		content = nullptr;
	};

	Label::Label(const char* frameArg) {
		strCpy(frame, frameArg);
		content = nullptr;
	};

	Label::Label(const char* frameArg, const char* content) {
		strCpy(frame, frameArg);
		this->content = new char[strLen(content) + 1];
		strCpy(this->content, content);
	};

	Label::~Label() {
		delete[] content;
	};

	void Label::readLabel() {
		char temp[71];
		cin.getline(temp, 71);
		if (content != nullptr) { 
			delete[] content; 
		}
		content = new char[strLen(temp) + 1];
		strCpy(content, temp);
	};

	std::ostream& Label::printLabel()const {
		if (content != nullptr) {
			cout << frame[0];
			int i = 0;
			for (i = 0; i < strLen(content) + 2; i++) {
				cout << frame[1];
			}
			cout << frame[2] << endl;

			cout << frame[7];
			for (i = 0; i < strLen(content) + 2; i++) {
				cout << " ";
			}
			cout << frame[3] << endl;

			cout << frame[7];
			cout << " " << content << " ";
			cout << frame[3] << endl;

			cout << frame[7];
			for (i = 0; i < strLen(content) + 2; i++) {
				cout << " ";
			}
			cout << frame[3] << endl;

			cout << frame[6];
			for (i = 0; i < strLen(content) + 2; i++) {
				cout << frame[5];
			}
			cout << frame[4];
		}
		return cout;
	};
}