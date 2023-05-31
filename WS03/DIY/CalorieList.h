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
#ifndef CALORIELIST_H_
#define CALORIELIST_H_
#include "Food.h"
namespace sdds{
	class CalorieList {
		Food* m_foods;
		int m_noOfItems;
		int m_itemsAdded;
		int totalCalories()const;
		void Title()const;
		void footer()const;
		void setEmpty();
		bool isValid()const;
	public:
		void init(int size);
		bool add(const char* item_name, int calories, int when);
		void display()const;
		void deallocate();
	};
}
#endif