#include "personlist.h"

/*
* Author: Julio Conchas
* Email:  conchasjimenez@gmail.com
* Path:   libs/
* File:   personlist.cpp
*/


using namespace std;

/***** Public ****/

Personlist::Personlist(){
    head = nullptr;
    size = 0;
}
void Personlist::insertar(Persona p){
    Node* nuevo = new Node(p);
    if (head == nullptr) {
        head = nuevo;
        nuevo->setNext(nullptr);
    }
    else{
        nuevo->setNext(head);
        head = nuevo;
    }
    size++;
}
bool Personlist::eliminar(string s){
    Node *aux = head;
    Node *auxOne;
    bool flag = false;
    while (aux != nullptr) {
        if (aux->getPersona().getName() == s) {
            cout << aux->getPersona().getName() << " Encontrado" << endl;
            if (aux == head) {
                 head = aux->getNext();
              }
            else {
                auxOne->setNext(aux->getNext());
            }
            delete aux;
            flag = true;
        }
        auxOne = aux;
        aux = aux->getNext();
    }
    return flag;
}
void Personlist::print(){
    Node *aux = head;
    cout << "|========================================|" << endl;
    while (aux != nullptr) {
        cout << aux->getPersona().toString01() << endl;
        aux = aux->getNext();
    }
    cout << "|========================================|" << endl;
}
int Personlist::getSize(){
    return size;
}
Personlist::~Personlist(){
    Node *aux = head;
    Node *del;
    while (aux != nullptr) {
        del = aux;
        aux = aux->getNext();
        delete del;
    }
}
