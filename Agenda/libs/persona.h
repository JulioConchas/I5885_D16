#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <string>

using namespace std;

class Persona{
private:
    string name;
    string apellido;
    int edad;
    string tel;
public:
    Persona();

    string getName();
    string getApellido();
    int getEdad();
    string getTel();

    string toString();
    string toString01();

    void setName(string);
    void setApellido(string);
    void setEdad(int);
    void setTel(string);
};
#endif
