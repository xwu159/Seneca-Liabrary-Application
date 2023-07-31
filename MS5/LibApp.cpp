/***********************************************************************
// Final Project Milestone 5 
// LibApp Module
// File	LibApp.cpp
// Version 1.0
// Name            Date            Student ID            Email
//Xinyang Wu    July 29th,2023      153821228         xwu159@myseneca.ca
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "LibApp.h"
#include "Utils.h"
#include "PublicationSelector.h"

using namespace std;
namespace sdds {

    bool LibApp::confirm(const char* message) {
        bool result = false;
        Menu menu(message);
        menu << "Yes";
        if (menu.run() == 1) {
            result = true;
        }
        return result;
    }

    void LibApp::load() {
        std::cout << "Loading Data" << std::endl;
        ifstream infile(m_fileName);
        char type{};
        int i;
        for (i = 0; infile&&i<SDDS_LIBRARY_CAPACITY; i++) {
            infile >> type;
            infile.ignore();
            if (infile) {
                if (type == 'P')
                    m_PPA[i] = new Publication;
                else if (type == 'B')
                    m_PPA[i] = new Book;
                if (m_PPA[i]) {
                    infile >> *m_PPA[i];
                    m_NOLP++;
                    m_LLRN = m_PPA[i]->getRef();
                }
            }
        }
    }

    void LibApp::save() {
        std::cout << "Saving Data" << std::endl;
        ofstream outfile(m_fileName);
        for (int i = 0; i < m_NOLP; i++) {
            if (m_PPA[i]->getRef() != 0)
                outfile << *m_PPA[i] << std::endl;
        }
        outfile.close();
    }


    int LibApp::search(int searchType) {
        char title[256]{};
        int selectedType = 0, i = 0, libRef = 0;
        char typeChar;
        PublicationSelector pubSelect("Select one of the following found matches:", 15);

        selectedType = m_publicationType.run();
        if (selectedType == 1) {
            typeChar = 'B';
        }
        else if (selectedType == 2) {
            typeChar = 'P';
        }

        cin.ignore(1000, '\n');
        std::cout << "Publication Title: ";
        cin.getline(title, 256);

        if (searchType == 1) {
            for (i = 0; i < m_NOLP; i++) {
                if (m_PPA[i]->operator==(title) && typeChar == m_PPA[i]->type() && m_PPA[i]->getRef() != 0) {
                    pubSelect << m_PPA[i];
                }
            }
        }

        else if (searchType == 2) {
            for (i = 0; i < m_NOLP; i++) {
                if (m_PPA[i]->operator==(title) && m_PPA[i]->onLoan() && typeChar == m_PPA[i]->type() && m_PPA[i]->getRef() != 0) {
                    pubSelect << m_PPA[i];
                }
            }
        }

        else if (searchType == 3) {
            for (i = 0; i < m_NOLP; i++) {
                if (m_PPA[i]->operator==(title) && !m_PPA[i]->onLoan() && typeChar == m_PPA[i]->type() && m_PPA[i]->getRef() != 0) {
                    pubSelect << m_PPA[i];
                }
            }
        }

        if (pubSelect) {
            pubSelect.sort();
            libRef = pubSelect.run();
            if (libRef > 0){
                std::cout << *getPub(libRef) << std::endl;
            }
            else {
                std::cout << "Aborted!" << std::endl;
            }
        }
        else {
            std::cout << "No matches found!" << std::endl;
        }

        return libRef;
    }

    void LibApp::returnPub() {
        bool aborted = false;
        std::cout << "Return publication to the library" << std::endl;
        int libRef = search(2); 
        if (!(libRef > 0)) {
            aborted = true;
        }

        if (!aborted) {
            bool confirmed = confirm("Return Publication?");

            if (confirmed) {
                int daysLoaned = Date() - getPub(libRef)->checkoutDate();

                if (daysLoaned > SDDS_MAX_LOAN_DAYS) {
                    double penalty = (daysLoaned - SDDS_MAX_LOAN_DAYS) * 0.5;
                    std::cout << fixed << setprecision(2);
                    std::cout << "Please pay $" << penalty;
                    std::cout << " penalty for being " << (daysLoaned - SDDS_MAX_LOAN_DAYS);
                    std::cout<< " days late!" << std::endl;
                }

                getPub(libRef)->set(0);
                m_changed = true;
            }

            std::cout << "Publication returned" << std::endl;
        }

        std::cout << std::endl;
    }

    void LibApp::newPublication() {
        bool ret = false;
        if (m_NOLP == SDDS_LIBRARY_CAPACITY) {
            std::cout << "Library is at its maximum capacity!";
            ret = true;
        }
        if(!ret) {
            std::cout << "Adding new publication to the library" << std::endl;
            m_changed = true;
            int pubType = m_publicationType.run();
            cin.ignore(1000, '\n');
            Publication* p = nullptr;
            if (pubType == 0) {
                std::cout << "Aborted!" << std::endl;
                ret = true;
                }
            else if (pubType == 1) {
                p = new Book;
                cin >> *p;
                }
            else if (pubType == 2) {
                p = new Publication;
                cin >> *p;
                }

            if (cin.fail()){
                cin.ignore(1000, '\n');
                cin.clear();
                std::cout << "Aborted!" << std::endl;
                exit(0);
                }
            else {
                if (!ret && confirm("Add this publication to the library?")) {
                    if (!*p) {
                        std::cout << "Failed to add publication!" << std::endl;
                        delete p;
                        }

                    else {
                        m_LLRN++;
                        p->setRef(m_LLRN);

                        m_PPA[m_NOLP] = p;

                        m_NOLP++;
                        m_changed = true;
                        std::cout << "Publication added" << std::endl;
                    }
                }
            }
        }
        std::cout << std::endl;
    }

 void LibApp::removePublication() {
        std::cout << "Removing publication from library" << std::endl;
        int libRef = search(1);
        if (libRef) {
            if (confirm("Remove this publication from the library?")) {
                getPub(libRef)->setRef(0);
                m_changed = true;
                std::cout << "Publication removed" << std::endl;
            }
        }
        std::cout << std::endl;
    }

    void LibApp::checkOutPub() {
        std::cout << "Checkout publication from the library" << std::endl;
        int libRef = search(3);
        if (libRef > 0) {
            if (confirm("Check out publication?")) {
                std::cout << "Enter Membership number: ";
                int input = getIntError(10000, 99999, "Invalid membership number, try again: ");
                getPub(libRef)->set(input);
                m_changed = true;
                std::cout << "Publication checked out" << std::endl;
            }
        }
        std::cout << std::endl;
    }

    LibApp::LibApp(const char* fileName):m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_publicationType("Choose the type of publication:") {
        if (fileName) {
            strcpy(m_fileName, fileName);
        }
        m_changed = false;
        m_NOLP = 0;
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        m_publicationType << "Book" << "Publication";
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
                std::cout << std::endl;
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

    Publication* LibApp::getPub(int libRef)
    {
        int i;
        for (i = 0; i < m_NOLP; i++) {
            if (m_PPA[i]->getRef() == libRef)
                return m_PPA[i];
        }
        return nullptr;
    }

    LibApp::~LibApp() {
        for (int i = 0; i < m_NOLP; i++) {
            delete m_PPA[i];
        }
    }
    
}
