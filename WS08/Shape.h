#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;
namespace sdds {
	struct Shape {
		virtual void draw(ostream& os) const = 0;
		virtual void getSpecs(istream& is) = 0;
		//Create a virtual empty destructor for the shape interface.
		virtual ~Shape() {}
	};
	ostream& operator<<(ostream& os, const Shape& shape);
	istream& operator>>(istream& is, Shape& shape);
}
#endif // ! SHAPE_H
