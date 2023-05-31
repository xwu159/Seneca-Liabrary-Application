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
#include "Bill.h"
using namespace std;
namespace sdds {
    double Bill::totalTax()const {
        int i;
        double totalTax=0.0;
        for (i = 0; isValid() && i < m_noOfItems; i++) {
            totalTax += m_items[i].tax();
        }
        return totalTax;
    };

    double Bill::totalPrice()const {
        int i;
        double totalPrice = 0.0;
        for (i = 0; isValid() && i < m_noOfItems; i++) {
            totalPrice += m_items[i].price();
        }
        return totalPrice;
    };

    void Bill::Title()const {
        cout << "+--------------------------------------+" << endl;
        if (isValid()) {
            cout << "| ";
            cout.setf(ios::fixed);
            cout.width(36);
            cout.precision(2);
            cout << left << m_title;
            cout << " |" << endl;
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    };

    void Bill::footer()const {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid()) {
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << "|                Total Tax: ";
            cout.width(10); 
            cout << right << totalTax() << " |" << endl;
            cout << "|              Total Price: ";
            cout.width(10); 
            cout<< right << totalPrice() << " |" << endl;
            cout << "|          Total After Tax: ";
            cout.width(10);
            cout<< right << (totalTax() + totalPrice()) << " |" << endl;
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+--------------------------------------+" << endl;
    };

    void Bill::setEmpty() {
        m_title[0] = '\0';
        m_items = nullptr;
    };

    bool Bill::isValid()const {
        bool valid = m_title[0] != '\0' && m_items != nullptr;
        int i;
        for (i = 0; valid && i < m_noOfItems; i++) {
            valid = m_items[i].isValid();
        }
        return valid;
    };

    void Bill::init(const char* title, int noOfItems) {
        if(m_title[0] = '\0' || noOfItems <= 0){
            setEmpty();
        }
        else {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strnCpy(m_title, title, 36);
            m_items = new Item[m_noOfItems];
            int i = 0;
            for (i = 0; i < m_noOfItems; i++) {
                m_items[i].setEmpty();
            }
        }
    };

    bool Bill::add(const char* item_name, double price, bool taxed) {
        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            return true;
        }
        else {
            return false;
        }
    };

    void Bill::display()const {
        Title();
        int i;
        for (i = 0; i < m_noOfItems; i++) {
            m_items[i].display();
        }
        footer();
    };

    void Bill::deallocate() {
        delete [] m_items;
        m_items = nullptr;
    };
}