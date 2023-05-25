/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 2 Part 2 DIY
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Student ID            Email
//Xinyang Wu    May 24th,2023      153821228         xwu159@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor
  provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {
	struct PCPopulation {
		char postalCode[4];
		int population;
	};
	void sort();
	bool load(const char* filename);
	void display();
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_