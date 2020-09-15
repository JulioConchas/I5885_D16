#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <string>

using namespace std;

class Persona{
private:
    string name;
    int edad;
    float peso;
    float altura;
public:
    Persona();

    string getName();
    int getEdad();
    float getPeso();
    float getAltura();

    string toString();
    string toString01();

    void setName(string);
    void setEdad(int);
    void setPeso(float);
    void setAltura(float);
};
#endif
