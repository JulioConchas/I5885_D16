#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/*
* Author: Julio Conchas
* Email:  conchasjimenez@gmail.com
* Path:   libs/
* File:   menu.h
*/

#include <iostream>
#include <string>
#include <regex>
#include "personlist.h"
#include "persona.h"

class Menu{
private:
    void header();
    void headerList();
public:
    void printMenu(Personlist&);
    void mainMenu(Personlist&);
    void enterToContinue();
};

#endif
