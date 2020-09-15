#include "menu.h"

using namespace std;

void Menu::header(){
    system("clear");
    cout << "|==============|" << endl;
    cout << "|Julio Conchas.|" << endl;
    cout << "|    Agenda    |" << endl;
    cout << "|==============|" << endl;
    cout << "|              |" << endl;
}
void Menu::headerList(){
    cout << "|========================================|" << endl;
    cout << "|  Nombre  | Apellido | Edad |  Telefono |" << endl;
}
void Menu::printMenu(Personlist& p){

    if (p.getSize() != 0) {
        cout << "|[1] Agregar...|" << endl;
        cout << "|[2] Eliminar..|" << endl;
        cout << "|[3] Mostrar...|" << endl;
        cout << "|[7] Salit.....|" << endl;
    }
    else{
        cout << "|[1] Agregar...|" << endl;
        cout << "|[7] Salit.....|" << endl;
    }
}
void Menu::mainMenu(Personlist &p){
    int opt,edad;
    string name,killname,apellido,tel;
    Persona dude;
    int flagName = 0,flagApellido,flagEdad = 0,flagTelefono;
    do{
        header();
        printMenu(p);
        cin  >> opt;
        switch (opt) {
            case 1:
                do{
                    cout << "Ingresa el Nombre: " << endl;
                    cin >> name;
                    if(regex_match(name,regex("[a-zA-Z]+[a-zA-Z]"))){
                        dude.setName(name);
                        flagName = 1;
                     }
                    else{
                        cout << "( " << name << ") Nombre no permitido " << endl;
                    }
                }while(flagName != 1);
                do{
                    cout << "Ingresa el Apellido: " << endl;
                    cin >> apellido;
                    if(regex_match(apellido,regex("[a-zA-Z]+[a-zA-Z]"))){
                        dude.setApellido(apellido);
                        flagApellido = 1;
                     }
                    else{
                        cout << "( " << name << ") Nombre no permitido " << endl;
                    }
                }while(flagApellido != 1);
                do{
                    cout << "Ingresa la edad:  " << endl;
                    cin >> edad;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "( " << edad << ") edad no permitida " << endl;
                    }
                    else if(edad < 100 ){
                        dude.setEdad(edad);
                        flagEdad = 1;
                     }
                    else{
                        cout << "( " << edad << ") edad no permitida " << endl;
                    }
                }while(flagEdad != 1);
                do{
                    cout << "Ingrese el Telefono: " << endl;
                    cin >> tel;
                    dude.setTel(tel);
                    flagTelefono = 1;
                }while(flagTelefono != 1);
                p.insertar(dude);
                flagName = 0,flagApellido = 0, flagEdad = 0, flagTelefono = 0;
                enterToContinue();
            break;
            case 2:
                header();
                cout << "|   Eliminar   |" << endl;
                headerList();
                p.print();
                cout << "| Ingresa el nombre de quien quieres eliminar |" << endl;
                cin >> killname;
                if (!p.eliminar(killname)) {
                    cout << killname << " Error al eliminar " << endl;
                }
                enterToContinue();
            break;
            case 3:
                header();
                cout << "|     Lista    |" << endl << "|   Personas   |" << endl;
                headerList();
                p.print();
                enterToContinue();
            break;
        }

    }while(opt != 7);
    cout << "Bye, bye!" << endl;
}
void Menu::enterToContinue(){
    printf("Presione [ENTER] para continuar....");
    cin.get();
    getchar();
}
