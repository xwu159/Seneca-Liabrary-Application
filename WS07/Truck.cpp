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
#include <iostream>
#include "Truck.h"
namespace sdds {
	Truck::Truck(const char* plate, int year, double capacity, const char* address):MotorVehicle(plate, year) {
		this->capacity = capacity;
		currentLoad = 0;
		moveTo(address);
	}

	bool Truck::addCargo(double cargo) {
		bool rt = false;
		if (this->currentLoad + cargo <= capacity) {
			this->currentLoad += cargo;
			rt = true;
		}
		else if (this->currentLoad < capacity) {
			this->currentLoad = capacity;
			rt = true;
		}
		return rt;
	}

	bool Truck::unloadCargo() {
		bool rt = false;
		if (currentLoad > 0) {
			currentLoad = 0;
			rt = true;
		}
		return rt;
	}

	ostream& Truck::write(ostream& os) const {
		MotorVehicle::write(os);
		os << " | " << currentLoad << "/" << capacity;
		return os;
	}

	istream& Truck::read(istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> capacity;
		cout << "Cargo: ";
		in >> currentLoad;
		return in;
	}

	ostream& operator<<(ostream& os, const Truck& trk) {
		return trk.write(os);
	}

	istream& operator>>(istream& in, Truck& trk) {
		return trk.read(in);
	}


}