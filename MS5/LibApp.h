#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include <iostream>
#include "Menu.h"
#include "Book.h"
#include "Publication.h"
namespace sdds {
   class LibApp {
       char m_fileName[257];
       Publication* m_PPA[SDDS_LIBRARY_CAPACITY + 1];
       int m_NOLP;
       int m_LLRN;
       Menu m_publicationType;

       bool m_changed;
       Menu m_mainMenu;
       Menu m_exitMenu;

       bool confirm(const char* message);
       void load();
       void save();
       int search(int searchType);
       void returnPub();
       void newPublication();
       void removePublication();
       void checkOutPub();
   public:
       LibApp(const char* fileName);
       ~LibApp();
       void run();
       Publication* getPub(int libRef);
   };

}
#endif



