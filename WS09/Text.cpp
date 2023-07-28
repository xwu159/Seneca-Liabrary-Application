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
#include <fstream>
#include "Text.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   const char& Text::operator[](int index) const
   {
       return m_content[index];
   }

   Text::Text(const char* filename) :m_filename(nullptr), m_content(nullptr) 
   {
       if (filename && filename[0] != '\0') {
           m_filename = new char[strlen(filename) + 1];
           strcpy(m_filename, filename);
           read();
       }
   }

   Text::Text(const Text& text):m_filename(nullptr),m_content(nullptr)
   {
       if (text.m_content) {
           m_content = new char[strlen(text.m_content) + 1];
           strcpy(m_content, text.m_content);
       }
   }

   Text& Text::operator=(const Text& text)
   {
       if (this != &text) {
           delete[] m_filename;
           delete[] m_content;
           m_filename = nullptr;
           m_content = nullptr;
           if (text.m_content) {
               m_content = new char[strlen(text.m_content) + 1];
               strcpy(m_content, text.m_content);
           }
       }
       return *this;
   }

   Text::~Text()
   {
       delete[] m_filename;
       delete[] m_content;
   }

   void Text::read()
   {
       if (m_filename) {
           ifstream file(m_filename);
           int length = getFileLength();
           if (length > 0 && file.is_open()) {
               m_content = new char[length + 1];
               char ch;
               int i = 0;
               while (file.get(ch)) {
                   m_content[i] = ch;
                   i++;
               }
               m_content[i] = '\0';
           }
           file.close();
       }
   }

   void Text::write(std::ostream& os) const
   {
       if (m_content) {
           os << m_content;
       }
   }

   ostream& operator<<(ostream& os, const Text& text)
   {
       text.write(os);
       return os;
   }

}