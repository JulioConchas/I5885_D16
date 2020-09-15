#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "persona.h"

/*
* Author: Julio Conchas
* Email:  conchasjimenez@gmail.com
* Path:   libs/
* File:   node.cpp
*/

class Node {
private:
    Persona person;
    Node* next;
public:
    Node();
    Node(Persona&);
    void setPersona(Persona&);
    void setNext(Node*);

    Persona getPersona();
    Node* getNext();
};

#endif
