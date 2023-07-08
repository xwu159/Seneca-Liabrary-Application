/***********************************************************************
// OOP244 Utils Module
// Project MS1
// File	Utils.cpp
// Version 1.0
// Name            Date            Student ID            Email
//Xinyang Wu    July 7th,2023      153821228         xwu159@myseneca.ca

// I have done all the coding by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////
//***********************************************************************/
#include <iostream>
#include "Utils.h"
using namespace std;
namespace sdds {
    int getInt(int min, int max) {
        int value;
        bool done = false;
        while (!done) {
            cin >> value;
            if (cin.fail()|| value < min || value > max) {
                cout << "Invalid Selection, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }else {
                done = true;
            }
        }
        return value;
    }
}
