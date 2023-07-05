///***********************************************************************
//// Intro. to Object Oriented Programming
//// Workshop 6 Part 1 Lab
//// -----------------------------------------------------------
//// Name            Date            Student ID            Email
////Xinyang Wu    July 4th,2023      153821228         xwu159@myseneca.ca
//// Revision History
////I have done all the coding by myself and only copied the code that my professor
//  provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////
//***********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   /// Line Class///
   Line::operator const char* () const {
      return (const char*)m_value;
   }

   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }

   Line::~Line() {
       if (m_value != nullptr) {
           delete[] m_value;
           m_value = nullptr;
       }
   }


   /// TextFile Class///
   void TextFile::setEmpty() {
       if (m_textLines != nullptr) {
           delete[] m_textLines;
           m_textLines = nullptr;
       }
       if (m_filename != nullptr) {
           delete[] m_filename;
           m_filename = nullptr;
       }
       m_noOfLines = 0;
   }

   void TextFile::setFilename(const char* fname, bool isCopy) {
       if (isCopy) {
           m_filename = new char[strLen(fname) + 3];
           //3=strLen("C_")+1
           strCpy(m_filename, "C_");
           strCat(m_filename, fname);
       }
       else {
           m_filename = new char[strLen(fname) + 1];
           strCpy(m_filename, fname);
       }
   }

 void TextFile::setNoOfLines() {
    ifstream readfile(m_filename);
    char readChar;
    if (readfile.is_open()) {
        while (readfile.get(readChar)) {
            if (readChar == '\n')
                m_noOfLines++;
        }
        m_noOfLines++; 
    }
    else {
        setEmpty();
    }
}
 void TextFile::loadText() {
     if (m_filename != nullptr) {
         string line;
         unsigned countLine = 0;
         if (m_textLines != nullptr) {
             delete[] m_textLines;
             m_textLines = nullptr;
         }
         m_textLines = new Line[m_noOfLines];
         ifstream readfile(m_filename);
         if (readfile.is_open()) {
             while (getline(readfile, line) && countLine < m_noOfLines) {
                 //if do not add countLine<m_noOflines it will buffer overrun
                 m_textLines[countLine].m_value = new char[strLen(line.c_str()) + 1];
                 strCpy(m_textLines[countLine].m_value, line.c_str());
                 countLine++;
             }
         }
         m_noOfLines = countLine;
     }
 }


   void TextFile::saveAs(const char* fileName)const {
       ofstream outPutfile(fileName);
       unsigned i;
       if (outPutfile.is_open()) {
           // writing the contents of m_textLines to the new file.
           for (i = 0; i < m_noOfLines; i++) {
               outPutfile << m_textLines[i] << endl;
           }
       }
   }

   TextFile::TextFile(unsigned pageSize) {
       setEmpty();
       m_pageSize = pageSize;
   }

   TextFile::TextFile(const char* filename, unsigned pageSize) {
       setEmpty();
       m_pageSize = pageSize;
       if (filename != nullptr && filename[0] != '\0') {
           m_filename = new char[strLen(filename) + 1];
           strCpy(m_filename, filename);
           setNoOfLines();
           loadText();
       }
   }

   TextFile::TextFile(const TextFile& inComingFile) {
       setEmpty();
       this->m_pageSize = inComingFile.m_pageSize;
       if (this != &inComingFile) {
           if (inComingFile.m_textLines && inComingFile.m_noOfLines > 0) {
               setFilename(inComingFile.m_filename, true);
               this->m_noOfLines = inComingFile.m_noOfLines;
               m_textLines = new Line[m_noOfLines];
               unsigned i = 0;
               while (i < m_noOfLines) {
                   m_textLines[i].m_value = new char[strLen(inComingFile.m_textLines[i].m_value) + 1];
                   strCpy(m_textLines[i].m_value, inComingFile.m_textLines[i].m_value);
                   i++;
               }
               saveAs(m_filename);
           }
       }
   }

   TextFile& TextFile::operator=(const TextFile& src) {
       if (this != &src) {
           if (m_textLines != nullptr) {
               delete[] m_textLines;
               m_textLines = nullptr;
           }
           if (src.m_textLines && src.m_noOfLines > 0) {
               this->m_noOfLines = src.m_noOfLines;
               m_textLines = new Line[m_noOfLines];

               unsigned i = 0;
               while (i < m_noOfLines) {
                   m_textLines[i].m_value = new char[strLen(src.m_textLines[i].m_value) + 1];
                   strCpy(m_textLines[i].m_value, src.m_textLines[i].m_value);
                   i++;
               }
               saveAs(m_filename);
           }
       }
       return *this;
   }


   TextFile::~TextFile() {
       if (m_filename != nullptr) {
           delete[] m_filename;
           m_filename = nullptr;
       }
       if (m_textLines != nullptr) {
           delete[] m_textLines;
           m_textLines = nullptr;
       }
   }


   unsigned TextFile::lines()const {
       return m_noOfLines;
   }
   
   std::ostream& TextFile::view(std::ostream& ostr) const
   {
       if (m_filename != nullptr && m_filename[0] != '\0') {
           ostr << m_filename << endl;
           ostr.fill('=');
           ostr.width(strLen(m_filename));
           ostr << '=' << endl;
           unsigned i = 0;
           while (i < m_noOfLines && i < m_pageSize) {
               ostr << m_textLines[i] << endl;
               i++;
           }
           if (i < m_noOfLines) {
               do {
                   ostr << "Hit ENTER to continue...";
                   char x;
                   cin.get(x);
                   for (unsigned j = 0; j < m_pageSize && i < m_noOfLines; j++) {
                       ostr << m_textLines[i] << endl;
                       i++;
                   }
               } while (i < m_noOfLines);
           }
       }
       return ostr;
   }

   std::istream& TextFile::getFile(std::istream& istr) {
       setEmpty();
       string temp;
       getline(istr, temp);
       setFilename(temp.c_str());
       setNoOfLines();
       loadText();
       return istr;
   }

   const char* TextFile::operator[](unsigned index)const {
       if (m_filename!=nullptr) {
           if (index >= m_noOfLines)
               index %= m_noOfLines;
       }
       return m_textLines[index].m_value;
   }

   TextFile::operator bool()const {
       return m_filename != nullptr;
   }

   const char* TextFile::name()const {
       return (const char*)m_filename;
   }

   ostream& operator<<(ostream& ostr, const TextFile& text) {
       return text.view(ostr);
   }

   istream& operator>>(istream& istr, TextFile& text) {
       return text.getFile(istr);
   }
}

