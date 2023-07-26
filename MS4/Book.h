#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "Publication.h"
namespace sdds {
	class Book :public Publication {
		char* m_authorName{nullptr};
	public:
		Book();
		Book(const Book& book);
		Book& operator=(const Book& book);
		virtual ~Book();

		virtual char type()const;
		virtual std::ostream& write(std::ostream& os) const;
		virtual std::istream& read(std::istream& istr);
		virtual void set(int member_id);
		virtual operator bool() const;
	};
}
#endif // !SDDS_BOOK_H
