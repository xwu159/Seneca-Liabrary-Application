/***********************************************************************
// Project MS5
// File	Streamable.cpp
// Version 1.0
// Name            Date            Student ID            Email
//Xinyang Wu    July 29th,2023      153821228         xwu159@myseneca.ca

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Streamable.h"
using namespace std;
namespace sdds {
    Streamable::~Streamable() {};

    std::ostream& operator<<(std::ostream& os, const Streamable& s) {
        if (s) {
            s.write(os);
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, Streamable& s) {
        return s.read(is);
    }
}
