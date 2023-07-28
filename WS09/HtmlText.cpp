/***********************************************************************
//// Intro. to Object Oriented Programming
//// Workshop 9 Part 1 Lab
//// -----------------------------------------------------------
//// Name            Date            Student ID            Email
////Xinyang Wu    July 26th,2023     153821228         xwu159@myseneca.ca
////I have done all the coding by myself and only copied the code that my professor
//  provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////
***********************************************************************/
#include "HtmlText.h"
#include "Text.h"
#include "cstring.h"
using namespace std;
namespace sdds {
	HtmlText::HtmlText(const char* filename, const char* title) :Text(filename), m_title(nullptr)
	{
		if (title && title[0] != '\0') {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
	}
	HtmlText::HtmlText(const HtmlText& htmltext) :Text(htmltext), m_title(nullptr)
	{
		if (htmltext.m_title)
			m_title = new char[strlen(htmltext.m_title) + 1];
		strcpy(m_title, htmltext.m_title);
	}
	HtmlText& HtmlText::operator=(const HtmlText& htmltext)
	{
		if (this != &htmltext) {
			Text::operator=(htmltext);
			delete[] m_title;
			m_title = nullptr;
			if (htmltext.m_title) {
				m_title = new char[strlen(htmltext.m_title) + 1];
				strcpy(m_title, htmltext.m_title);
			}
		}
		return *this;
	}
	HtmlText::~HtmlText()
	{
		delete[] m_title;
	}
	void HtmlText::write(std::ostream& os) const
	{
			os << "<html><head><title>";
			os << (m_title ? m_title : "No Title");
			os << "</title></head>\n<body>\n";

			if (m_title)
				os << "<h1>" << m_title << "</h1>\n";

			bool multipleSpaces = false;
			for (int i = 0; (*this)[i] != '\0'; i++) {
				char ch = (*this)[i];
				if (ch == '<') {
					os << "&lt;";
					multipleSpaces = false;
				}
				else if (ch == '>') {
					os << "&gt;";
					multipleSpaces = false;
				}
				else if (ch == '\n') {
					os << "<br />\n";
					multipleSpaces = false;
				}
				else if (ch == ' ') {
					if (!multipleSpaces) {
						multipleSpaces = true;
						os << " ";
					}else{
						os << "&nbsp;";
					}
				}
				else {
					os << ch;
					multipleSpaces = false;
				}
			}

			os << "</body>\n</html>";
	
	}
}