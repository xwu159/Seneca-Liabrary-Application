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

#include <iostream>
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds {
	int numRecords;
	PCPopulation* pcPopulation;
	void sort() {
		int i, j;
		PCPopulation temp;
		for (i = numRecords - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (pcPopulation[j].population > pcPopulation[j + 1].population) {
					temp = pcPopulation[j];
					pcPopulation[j] = pcPopulation[j + 1];
					pcPopulation[j + 1] = temp;
				}
			}
		}
	}

	bool load(const char* filename) {
		bool ok = false;
		int i;
		if (openFile(filename)) {
			numRecords = noOfRecords();
			pcPopulation = new PCPopulation[numRecords];
			for (i = 0; i < numRecords; i++) {
				if (read(pcPopulation[i].postalCode) && read(pcPopulation[i].population)) {
					ok = true;
				}
				else {
					cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
				}
			}
			closeFile();
		}
		else {
			cout << "Could not open data file: "<<filename << endl;
		}
		return ok;
	}
	void display() {
		int i, total=0;
		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;
		sort();
		for (i = 0; i < numRecords; i++) {
			cout << i+1<<"- " << pcPopulation[i].postalCode << ":  " << pcPopulation[i].population << endl;
			total += pcPopulation[i].population;
		}
		cout << "-------------------------" << endl;
		cout << "Population of Canada: "<<total << endl;
	}
	void deallocateMemory() {
		delete[] pcPopulation;
	}

}