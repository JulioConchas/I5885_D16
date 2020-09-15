#include "personlist.h"

/*
* Author: Julio Conchas
* Email:  conchasjimenez@gmail.com
* Path:   libs/
* File:   personlist.cpp
*/


using namespace std;

/***** Private ****/
void Personlist::inicializar(){
    struct stat buffer;
    if (stat("../main/data.txt",&buffer) == 0) {
        if (!load()) cout << "Error al cargar las personas" << endl;
    }
    else{
        cout << "data file not exists" << '\n';
        size = 0;
    }
}
bool Personlist::load(){
    bool flag = true;
    fstream myFile;
    char c;
    string myOutput = "";
    Persona p;

    myFile.open("data.txt", fstream::in);
    if (myFile.good()) {
        if (myFile.is_open()) {
            do{
                c = myFile.get();
                if (c != '#') {
                    myOutput = myOutput + c;
                }
                else{
                    p = split_data(myOutput);
                    insertar(p);
                    myOutput="";
                }
            }while(!myFile.eof());
        }
        else{
            cout << "ERROR,read(): file is not open\n";
            flag = false;
        }
    }
    else{
        cout << "ERROR,read(): file is not good\n";
        flag = false;
    }
    myFile.close();
    return flag;
}
Persona Personlist::split_data(string s){
    Persona p;
    string data = "";
    int valueFlag = 0;
    int int_data;
    float float_data;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ',' && s[i] != '\n') {
            data = data + s[i];
        }
        else{
            if (valueFlag == 0) {
                //cout << "name: " << data << endl;
                p.setName(data);
                data = "";
                valueFlag++;
            }
            else if (valueFlag == 1) {
                istringstream(data) >> int_data;
                //cout << "Edad: " << int_data << endl;
                p.setEdad(int_data);
                data = "";
                valueFlag++;
            }
            else if (valueFlag == 2) {
                float_data = stof(data);
                //cout << "Peso: " << float_data << endl;
                p.setPeso(float_data);
                data = "";
                valueFlag++;
            }

        }
    }
    if (valueFlag == 3) {
        float_data = stof(data);
        //cout << "Altura: " << float_data << endl;
        p.setAltura(float_data);
    }
    return p;

}

/***** Public ****/

Personlist::Personlist(){
    head = nullptr;
    size = 0;
    inicializar();
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
            if (save()) { cout << "PERSONLIST: guardado exitosamente!" << endl; }
            else { cout << "PERSONLIST: problemas al guardar! " << endl; }
            flag = true;
        }
        auxOne = aux;
        aux = aux->getNext();
    }
    return flag;
}
bool Personlist::buscar(string s){
    Node *aux = head;
    bool flag = false;
    while (aux != nullptr) {
        if (aux->getPersona().getName() == s) {
            cout << aux->getPersona().getName() << " Encontrado" << endl;
            cout << aux->getPersona().getEdad() << " edad" << endl;
            cout << aux->getPersona().getPeso() << " peso" << endl;
            cout << aux->getPersona().getAltura() << " edad" << endl;

            flag = true;
        }
        aux = aux->getNext();
    }
    return flag;
}
bool Personlist::modificar(string s){
    Node *aux = head;
    bool flag = false;
    int flagName = 0,flagEdad = 0,flagPeso = 0, flagAltura = 0;
    int opt,edad;
    float peso,altura;
    string name;

    while (aux != nullptr) {
        if (aux->getPersona().getName() == s) {
            cout << aux->getPersona().getName() << " Encontrado" << endl;
            cout << "Que deceas modificar" << endl;
            cout << "[1] Nombre" << endl;
            cout << "[2] Edad" << endl;
            cout << "[3] Peso" << endl;
            cout << "[4] altura" << endl;
            cin >> opt;
            switch (opt) {
                case 1:
                    do{
                        cout << "Ingresa el nuevo nombre: " << endl;
                        cin >> name;
                        if(regex_match(name,regex("[a-zA-Z]+[a-zA-Z]"))){
                            aux->getPersona().setName(name);
                            cout << aux->getPersona().getName() << endl;
                            flagName = 1;
                         }
                        else{
                            cout << "( " << name << ") Nombre no permitido " << endl;
                        }
                    }while(flagName != 1);
                break;
                case 2:
                    do{
                        cout << "Ingresa la nueva edad:  " << endl;
                        cin >> edad;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout << "( " << edad << ") edad no permitida " << endl;
                        }
                        else if(edad < 100 ){
                            aux->getPersona().setEdad(edad);
                            flagEdad = 1;
                         }
                        else{
                            cout << "( " << edad << ") edad no permitida " << endl;
                        }
                    }while(flagEdad != 1);
                break;
                case 3:
                    do{
                        cout << "Ingrese el nuevo peso: " << endl;
                        cin >> peso;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout << "( " << peso << ") peso no permitida " << endl;
                        }
                        if(peso < 100 ){
                            aux->getPersona().setPeso(peso);
                            flagPeso = 1;
                         }
                        else{
                            cout << "( " << peso << ") peso no permitida " << endl;
                        }
                    }while(flagPeso != 1);
                break;
                case 4:
                    do{
                        cout << "Ingrese la nueva altura: " << endl;
                        cin >> altura;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout << "( " << altura << ") altura no permitida " << endl;
                        }
                        else if(altura < 2 ){
                            aux->getPersona().setAltura(altura);
                            flagAltura= 1;
                         }
                        else{
                            cout << "( " << altura << ") altura no permitida " << endl;
                        }
                    }while(flagAltura != 1);
                break;
            }
            flag = true;
        }
        aux = aux->getNext();
    }
    return flag;
}
bool Personlist::save(){
    Node *aux = head;
    bool flag;
    fstream myFile;
    struct stat buffer;
    if (stat("../main/data.txt",&buffer) == 0) {
        system("rm -Rf ../main/data.txt");
    }
    myFile.open("data.txt",fstream::out | fstream::app);
    if (myFile.good() && myFile.is_open()) {
        while (aux != nullptr) {
            myFile << aux->getPersona().toString();
            aux = aux->getNext();
        }
        flag = true;
    }
    else{
        flag = false;
    }
    myFile.close();
    return flag;
}
void Personlist::print(){
    Node *aux = head;
    cout << "|=================================|" << endl;
    while (aux != nullptr) {
        cout << aux->getPersona().toString01() << endl;
        aux = aux->getNext();
    }
    cout << "|=================================|" << endl;
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
