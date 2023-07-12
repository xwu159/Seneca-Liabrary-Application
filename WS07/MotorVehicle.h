#ifndef SDDS_MOTORVEHICLE_H_
#define SDDS_MOTORVEHICLE_H_
using namespace std;
namespace sdds {
	class MotorVehicle {
		char plate[9];
		char address[64];
		int year;
	public:
		MotorVehicle(const char* plate, int year);
		void moveTo(const char* address);
		ostream& write(ostream& os) const;
		istream& read(istream& in);
	};
	ostream& operator<<(ostream&os, const MotorVehicle& mv);
	istream& operator>>(istream&in, MotorVehicle& mv);
}
#endif