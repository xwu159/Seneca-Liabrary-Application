#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "IceCream.h"

using namespace std;
IceCream::IceCream() {
	numOfScoops=0;
	flavour[0] = '\0';
}
IceCream::IceCream(int scoops, const char*flavor) {
	set(scoops, flavor);
}
void IceCream::set(int scoops, const char* flavor) {
	if (scoops <= max_scoops && scoops >= min_scoops && flavor != nullptr) {
		numOfScoops = scoops;
		if (strlen(flavor) < 19) {
			strcpy(flavour, flavor);
		}
		else {
			cout << "Flavor name is too long!" << endl;
			flavour[0] = '\0';
		}
	}
	else {
		numOfScoops = 0;
		flavour[0] = '\0';
	}
}

bool IceCream::isEmpty() const {
	return (numOfScoops == 0 && flavour[0] == '\0');
}

void IceCream::display(ostream&) const {
	if (isEmpty()) {
		cout << "Argh!" << endl;
	}
	if (numOfScoops <= max_scoops && numOfScoops >= min_scoops && flavour != nullptr) {
		cout.setf(ios::right);
		cout.width(3);
		cout.fill('0');
		cout << numOfScoops << ' ' << flavour<<endl;
		cout.unsetf(ios::right);
	}
}

IceCream& IceCream::operator++(int) {
	if (numOfScoops < max_scoops) {
		numOfScoops++;
	}
	return *this;
}

IceCream IceCream::operator-(int scoops){
	numOfScoops -= scoops;
	if (scoops < 0||numOfScoops<1||numOfScoops>5) { numOfScoops = 1; }
	return *this;
}