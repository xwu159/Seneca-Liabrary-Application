#ifndef LBLSHAPE_H
#define LBLSHAPE_H
#include "Shape.h"
using namespace std;
namespace sdds {
	class LblShape :public Shape {
		char* m_label{};
	protected:
		const char* label() const;
	public:
		LblShape();
		LblShape(const char* label);
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;
		virtual ~LblShape();
		void getSpecs(istream& is);
	};
}
#endif // ! LBLSHAPE_H
