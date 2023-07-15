/***********************************************************************
// Final Project Milestone 2 
// LibApp Module
// File	LibApp.cpp
// Version 1.0
// Name            Date            Student ID            Email
//Xinyang Wu    July 14th,2023      153821228         xwu159@myseneca.ca
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "LibApp.h"
using namespace std;
namespace sdds {
    bool LibApp::confirm(const char* message) {
        bool result = false;
        Menu menu(message);
        menu << "yes";
        if (menu.run() == 1) {
            result = true;
        }
        return result;
    }

    void LibApp::load() {
        cout << "Loading Data" << endl;
    }

    void LibApp::save() {
        cout << "Saving Data" << endl;
    }

    void LibApp::search() {
        cout << "Searching for publication" << endl;
    }

    void LibApp::returnPub() {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl;
        cout << endl;
        m_changed = true;
    }

    void LibApp::newPublication() {
        cout << "Adding new publication to library" << endl;
        if (confirm("Add this publication to library?")) {
            m_changed = true;
            cout << "Publication added" << endl;
        }
        cout << endl;
    }

    void LibApp::removePublication() {
        cout << "Removing publication from library" << endl;
        search();
        if (confirm("Remove this publication from the library?")) {
            m_changed = true;
            cout << "Publication removed" << endl;
        }
        cout << endl;
    }

    void LibApp::checkOutPub() {
        search();
        if (confirm("Check out publication?")) {
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
        cout << endl;
    }

    LibApp::LibApp():m_changed(false),m_mainMenu("Seneca Library Application"),m_exitMenu("Changes have been made to the data, what would you like to do?") {
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        load();
    }

    void LibApp::run() {
        int menuSelection, exitSelection;
        bool exitFlag = false;
        while (!exitFlag) {
            menuSelection=m_mainMenu.run();
            switch (menuSelection) {
            case 0:
                if (m_changed) {
                    exitSelection = m_exitMenu.run();
                    switch (exitSelection) {
                    case 0:
                        if (confirm("This will discard all the changes are you sure?")) {
                            exitFlag = true;
                        }
                        break;
                    case 1:
                        save();
                        exitFlag = true;
                        break;
                    case 2:
                        break;
                    }
                }
                else {
                    exitFlag = true;
                }
                cout << endl;
                break;
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            }
        }
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Thanks for using Seneca Library Application" << std::endl;
    }
}
