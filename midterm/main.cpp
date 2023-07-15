#include <iostream>
#include "IceCream.h"

int main() {
	IceCream* flavour = new IceCream[3];
	flavour[0].set(4, "Vanilla");
	flavour[1].set(2, "Almond");
	flavour[2].set(1, "Caramel");
	IceCream* flavourTemp = new IceCream[4];
	int i = 0;
	for (i = 0; i < 3; i++) {
		flavourTemp[i] = flavour[i];
	}
	flavourTemp[3].set(3,"Chocolate Mint");
	delete[] flavour;
	flavour = flavourTemp;
	for (int i = 0; i < 4; i++){
		flavour[i].display(std::cout);
	}
	delete[] flavour;
	return 0;
}