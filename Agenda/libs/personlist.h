#ifndef PERSONLIST_H_INCLUDED
#define PERSONLIST_H_INCLUDED

/*
* Author: Julio Conchas
* Email:  conchasjimenez@gmail.com
* Path:   libs/
* File:   personlist.h
*/

#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <vector>
#include "node.h"
#include "persona.h"

class Personlist {
private:
    Node *head;
    int size;
    void inicializar();
    bool load();
    Persona split_data(string);
public:
    Personlist();
    ~Personlist();
    void insertar(Persona);
    bool eliminar(string);
    bool buscar(string);
    bool modificar(string);
    bool save();
    void print();
    int getSize();
};

#endif
