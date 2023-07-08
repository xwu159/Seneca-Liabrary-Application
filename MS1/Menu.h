/***********************************************************************
// OOP244 Utils Module
// Project MS1
// File Menu.h
// Version 1.0
// Name            Date            Student ID            Email
//Xinyang Wu    July 7th,2023      153821228         xwu159@myseneca.ca

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////
//***********************************************************************/
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>

namespace sdds {
    const unsigned int MAX_MENU_ITEMS = 20;
    class Menu;
    class MenuItem {
        char* contentOfMenu{};
        friend class Menu;
        MenuItem();
        MenuItem(const char* textContent);
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        ~MenuItem();
        void setEmpty();
        operator bool()const;
        operator const char* () const;
        void display() const;
    };
    class Menu {
        MenuItem menuTitle{};
        MenuItem* m_item[MAX_MENU_ITEMS]{};
        unsigned int m_noOfItems;
    public:
        Menu();
        Menu(const char* title);
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;
        ~Menu();
        std::ostream& displayMenuTitle(std::ostream& os);
        std::ostream& displayMenu(std::ostream& os);
        unsigned int run();
        unsigned int operator~();
        operator int() const;
        operator unsigned int();
        operator bool();
        Menu& operator<<(const char* menuTitle);
        //overload the indexing operator to run the const char* cast of the corresponding MenuItem in the array of MenuItem pointer
        char* operator[](unsigned int index) const;
    };
    // Overloading the insertion operator
    std::ostream& operator<<(std::ostream& os, Menu& menu);
}
#endif