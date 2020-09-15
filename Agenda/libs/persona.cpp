#include <iostream>
#include "persona.h"

Persona::Persona(){}
string Persona::getName(){ return name; }
string Persona::getApellido(){ return apellido; }
int Persona::getEdad(){ return edad; }
string Persona::getTel(){ return tel; }


string Persona::toString(){
    return name+","+apellido+" "+to_string(edad)+","+tel+"#";
}
string Persona::toString01(){
    if (name.size() < 8) {
        unsigned aux = name.size();
        unsigned plus = 8 - aux;
        name.resize(aux+plus,' ');
    }
    if (apellido.size() < 8) {
        unsigned aux = apellido.size();
        unsigned plus = 8 - aux;
        apellido.resize(aux+plus,' ');
    }
    return "|  "+name+"   "+apellido+"    "+to_string(edad)+"   "+tel+" |";
}

void Persona::setName(string n){ name = n; }
void Persona::setApellido(string n){ apellido = n; }
void Persona::setEdad(int e){ edad = e; }
void Persona::setTel(string t){ tel = t; }
