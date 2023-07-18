#ifndef LINE_H
#define LINE_H
#include "LblShape.h"
using namespace std;
namespace sdds {
	class Line :public LblShape {
		int m_length{};
	public:
		Line();
		Line(const char* label, int length);
		void getSpecs(istream& is);
		void draw(ostream& os) const;
	};
}
#endif // ! LINE_H