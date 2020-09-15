#include <iostream>
#include "persona.h"

Persona::Persona(){}
string Persona::getName(){ return name; }
int Persona::getEdad(){ return edad; }
float Persona::getPeso(){ return peso; }
float Persona::getAltura(){ return altura; }

string Persona::toString(){
    string str_peso = to_string(peso);
    string str_altura = to_string(altura);
    str_peso = str_peso.substr(0,str_peso.find(".")+3);
    str_altura = str_altura.substr(0,str_altura.find(".")+3);
    return name+","+to_string(edad)+","+str_peso+","+str_altura+"#";
}
string Persona::toString01(){
    string str_peso = to_string(peso);
    string str_altura = to_string(altura);
    str_peso = str_peso.substr(0,str_peso.find(".")+3);
    str_altura = str_altura.substr(0,str_altura.find(".")+3);
    if (name.size() < 8) {
        unsigned aux = name.size();
        unsigned plus = 8 - aux;
        name.resize(aux+plus,' ');
    }
    return "|  "+name+"   "+to_string(edad)+"   "+str_peso+"   "+str_altura+"   |";
}

void Persona::setName(string n){
    name = n;
}
void Persona::setEdad(int e){ edad = e; }
void Persona::setPeso(float p){ peso = p; }
void Persona::setAltura(float a){ altura = a; }
