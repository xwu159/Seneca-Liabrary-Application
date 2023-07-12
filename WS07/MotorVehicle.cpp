/***********************************************************************
//// Intro. to Object Oriented Programming
//// Workshop 7 Part 1 Lab
//// -----------------------------------------------------------
//// Name            Date            Student ID            Email
////Xinyang Wu    July 11th,2023      153821228         xwu159@myseneca.ca
////I have done all the coding by myself and only copied the code that my professor
//  provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//setw in iomanip library
#include <iomanip>
#include "MotorVehicle.h"
#include "cstring.h"
using namespace std;
namespace sdds {

	MotorVehicle::MotorVehicle(const char* plate, int year) {
		strnCpy(this->plate, plate, 9);
		strCpy(address, "Factory");
		this->year = year;
	}

	void MotorVehicle::moveTo(const char* address) {
		if (strCmp(this->address, address)) {
			cout << "|" << right <<setw(8) << plate << "| |" << setw(20) << this->address
				<< " ---> " << left << setw(20) << address << "|" << endl;
			strnCpy(this->address, address, 64);
		}
	}
	ostream& MotorVehicle::write(ostream& os) const {
		os << "| " << year << " | " << plate << " | " << address;
		return os;
	}

	istream& MotorVehicle::read(istream& in) {
		cout << "Built year : ";
		in >> year;
		cout << "License plate : ";
		in >> plate;
		cout << "Current location : ";
		in >> address;
		return in;
	}
	
	ostream& operator<<(ostream& os, const MotorVehicle& mv) {
		return mv.write(os);
	}

	istream& operator>>(istream& in, MotorVehicle& mv) {
		return mv.read(in);
	}
}