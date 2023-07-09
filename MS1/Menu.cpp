/***********************************************************************
// OOP244 Utils Module
// Project MS1
// File Menu.cpp
// Version 1.0
// Name            Date            Student ID            Email
//Xinyang Wu    July 7th,2023      153821228         xwu159@myseneca.ca

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds {
    // MenuItem Class
    MenuItem::MenuItem() {
        setEmpty();
    }

    MenuItem::MenuItem(const char* textContent) {
        if (textContent != nullptr) {
            contentOfMenu = new char[strlen(textContent) + 1];
            strcpy(contentOfMenu, textContent);
        }
        else {
            setEmpty();
        }
    }

    MenuItem::~MenuItem() {
        delete[] contentOfMenu;
    }

    void MenuItem::setEmpty() {
        contentOfMenu = nullptr;
    }

    MenuItem::operator bool() const {
        return contentOfMenu != nullptr;
    }

    MenuItem::operator const char* () const {
        return contentOfMenu;
    }

    void MenuItem::display() const {
        if (contentOfMenu != nullptr) {
            cout << contentOfMenu;
        }
    }

    // Menu class defination

    Menu::Menu():m_noOfItems(0) {}

    Menu::Menu(const char* title):menuTitle(title), m_noOfItems(0){
    }

    Menu::~Menu() {
        for (unsigned int i = 0; i < m_noOfItems; i++) {
            delete m_item[i];
        }
    }

    ostream& Menu::displayMenuTitle(ostream& os) {
        if (menuTitle) {
            menuTitle.display();
        }
        return os;
    }

    ostream& Menu::displayMenu(ostream& os) {
        if (menuTitle) {
            displayMenuTitle(os);
            os << ":" << endl;
        }
        for (unsigned int i = 0; i < m_noOfItems; i++) {
            os.setf(ios::right);
            os.width(2);
            os << i + 1 << "- ";
            m_item[i]->display();
            os << endl;
        }
        os << " 0- Exit" << endl;
        os << "> ";
        os.unsetf(ios::right);
        return os;
    }

    unsigned int Menu::run() {
        unsigned int selection = 0;
        displayMenu(cout);
        selection = getInt(0, m_noOfItems);
        return selection;
    }

    unsigned int Menu::operator~() {
        return run();
    }

    Menu::operator int() const {
        return m_noOfItems;
    }

    Menu::operator unsigned int() {
        return m_noOfItems;
    }

    Menu::operator bool() {
        return m_noOfItems > 0;
    }

    Menu& Menu::operator<<(const char* menuContent) {
        if (m_noOfItems < MAX_MENU_ITEMS) {
            MenuItem* newMenuItem = new MenuItem(menuContent);
            m_item[m_noOfItems] = newMenuItem;
            m_noOfItems++;
        }
        return *this;
    }

    char* Menu::operator[](unsigned int index) const {
        return (index>= m_noOfItems? m_item[index %= m_noOfItems]->contentOfMenu : m_item[index]->contentOfMenu);
    }

    ostream& operator<<(ostream& os, Menu& menu) {
        return (menu.displayMenuTitle(os));
    }
}


