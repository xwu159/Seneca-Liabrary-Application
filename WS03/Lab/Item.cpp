/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 1 Lab
// -----------------------------------------------------------
// Name            Date            Student ID            Email
//Xinyang Wu    May 30th,2023      153821228         xwu159@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor
  provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {
    void Item::setName(const char* name) {
        strnCpy(m_itemName,name,20);
        m_itemName[20] = '\0';
    };

    void Item::setEmpty() {
        m_price = 0.0;
        m_itemName[0]= '\0';
    };

    void Item::set(const char* name, double price, bool taxed) {
        if (price < 0 || name == nullptr) {
            setEmpty();
        }
        else {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    };

    void Item::display()const {
        if (isValid())
        {
            cout << "| ";
            cout.fill('.');
            cout.width(20);
            cout << left << m_itemName << " | ";
            cout.fill(' ');
            cout.setf(ios::fixed);
            cout.width(7);
            cout.precision(2);
            cout << right << m_price << " | ";
            if (m_taxed) {
                cout << "Yes";
            } else{
                cout << "No ";
            }
            cout<< " |" << endl;
        }
        else {
            cout<<"| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    };

    bool Item::isValid()const {
        return (m_price > 0 && m_itemName[0] != '\0');
    };

    double Item::price()const {
        return m_price;
    };

    double Item::tax()const {
        return m_taxed ? (m_price * 0.13) : 0.0;
    };
}