/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 2 DIY
// -----------------------------------------------------------
// Name            Date            Student ID            Email
//Xinyang Wu    May 31st,2023      153821228         xwu159@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor
  provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;
namespace sdds {
	void Food::setName(const char* name) {
		strnCpy(m_foodName,name,30);
		m_foodName[30] = '\0';
	}

	void Food::setEmpty() {
		m_foodName[0] = '\0';
		m_timeOfConsumption = 0;
	}

	void Food::set(const char* name, int calorieNumber, int timeOfConsumption) {
		if (calorieNumber < 0 || name == nullptr||timeOfConsumption<0||timeOfConsumption>4) {
			setEmpty();
		}
		else {
			setName(name);
			m_calorieNumber = calorieNumber;
			m_timeOfConsumption = timeOfConsumption;
		}
	}

	bool Food::isValid()const {
		return (m_foodName[0] != '\0' && m_calorieNumber >= 0 && m_calorieNumber <= 3000 && m_timeOfConsumption > 0 && m_timeOfConsumption < 5);
	}

	void Food::display()const {
		if (isValid())
		{
			cout << "| ";
			cout.fill('.');
			cout.width(30);
			cout << left << m_foodName << " | ";
			cout.fill(' ');
			cout.width(4);
			cout << right << m_calorieNumber << " | ";
			switch (m_timeOfConsumption)
			{
			case 1:
				cout << "Breakfast ";
				break;
			case 2:
				cout << "Lunch     ";
				break;
			case 3:
				cout << "Dinner    ";
				break;
			default:
				cout << "Snack     ";
				break;
			}
			cout << " |" << endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}

	int Food::calories()const {
		return m_calorieNumber;
	}
}