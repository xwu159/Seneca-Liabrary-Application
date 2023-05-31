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
#ifndef FOOD_H_
#define FOOD_H_
namespace sdds {
	class Food {
		char m_foodName[31];
		int m_calorieNumber;
		int m_timeOfConsumption;
		void setName(const char* name);
	public:
		void set(const char* name, int calorieNumber, int timeOfConsumption);
		void setEmpty();
		bool isValid()const;
		int calories()const;
		void display()const;
	};
}
#endif // !FOOD_H
