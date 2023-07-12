#ifndef SDDS_TRUCK_H_
#define SDDS_TRUCK_H_
#include "MotorVehicle.h"
using namespace std;
namespace sdds {
	class Truck: public MotorVehicle {
		double capacity;
		double currentLoad;
		public:
			Truck(const char* plate, int year, double capacity,const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		ostream& write(ostream& os) const;
		istream& read(istream& in);
	};
	ostream& operator<<(ostream& os, const Truck & trk);
	istream& operator>>(istream& in, Truck& trk);
}
#endif
