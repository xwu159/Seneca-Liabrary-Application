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
#include "CalorieList.h"
using namespace std;
namespace sdds{
	int CalorieList::totalCalories()const {
		int i,totalCalories = 0;
		for (i = 0; isValid() && i < m_noOfItems; i++) {
			totalCalories += m_foods[i].calories();
		}
		return totalCalories;
	}

	void CalorieList::Title()const {
		cout << "+----------------------------------------------------+" << endl;
		if (isValid()) {
			cout << "|  ";
			cout.width(49);
			cout << left << "Daily Calorie Consumption";
			cout << " |" << endl;
		}
		else {
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}

	void CalorieList::footer()const {
		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid()) {
			cout << "|    Total Calories for today:";
			cout.width(9);
			cout << right << totalCalories() << " |            |" << endl;
		}
		else {
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}

	void CalorieList::setEmpty() {
		m_foods = nullptr;
	}

	bool CalorieList::isValid()const {
		bool valid = m_foods != nullptr;
		int i;
		for (i = 0; valid && i < m_noOfItems; i++) {
			valid = m_foods[i].isValid();
		}
		return valid;
	}

	void CalorieList::init(int size) {
		if (size <= 0) {
			setEmpty();
		}
		else {
			m_noOfItems = size;
			m_itemsAdded = 0;
			m_foods = new Food[m_noOfItems];
			int i = 0;
			for (i = 0; i < m_noOfItems; i++) {
				m_foods[i].setEmpty();
			}
		}
	}

	bool CalorieList::add(const char* item_name, int calories, int when) {
		if (m_itemsAdded < m_noOfItems) {
			m_foods[m_itemsAdded].set(item_name, calories, when);
			m_itemsAdded++;
			return true;
		}
		else {
			return false;
		}
	}

	void CalorieList::display()const {
		Title();
		int i;
		for (i = 0; i < m_noOfItems; i++) {
			m_foods[i].display();
		}
		footer();
	}

	void CalorieList::deallocate() {
		delete[] m_foods;
		m_foods = nullptr;
	}

}
