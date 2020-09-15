#include "node.h"

/*
* Author: Julio Conchas
* Email:  conchasjimenez@gmail.com
* Path:   libs/
* File:   node.cpp
*/

Node::Node(){}
Node::Node(Persona& p) : person(p),next(nullptr){ }
void Node::setPersona(Persona& p){
    person = p;
}
void Node::setNext(Node * n){
    next = n;
}
Persona Node::getPersona(){
    return person;
}
Node* Node::getNext(){
    return next;
}
