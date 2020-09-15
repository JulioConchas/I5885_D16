#include "menu.h"

using namespace std;

void Menu::header(){
    system("clear");
    cout << "|==============|" << endl;
    cout << "|Julio Conchas.|" << endl;
    cout << "|Pracitca 1:   |" << endl;
    cout << "|-Delimitadores|" << endl;
    cout << "|==============|" << endl;
    cout << "|              |" << endl;
}
void Menu::headerList(){
    cout << "|=================================|" << endl;
    cout << "|  Nombre  | Edad | Peso | Altura |" << endl;
}
void Menu::printMenu(Personlist& p){

    if (p.getSize() != 0) {
        cout << "|[1] Insertar..|" << endl;
        cout << "|[2] Eliminar..|" << endl;
        cout << "|[3] Mostrar...|" << endl;
        cout << "|[4] Guardar...|" << endl;
        cout << "|[5] Buscar....|" << endl;
        cout << "|[6] Modificar.|" << endl;
        cout << "|[7] Salit.....|" << endl;
    }
    else{
        cout << "|[1] Insertar..|" << endl;
        cout << "|[7] Salit.....|" << endl;
    }
}
void Menu::mainMenu(Personlist &p){
    int opt,edad;
    float peso,altura;
    string name,killname;
    Persona dude;
    int flagName = 0,flagEdad = 0,flagPeso = 0, flagAltura = 0;

    do{
        header();
        printMenu(p);
        cin  >> opt;
        switch (opt) {
            case 1:
                do{
                    cout << "Ingresa el nombre: " << endl;
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
                    cout << "Ingrese el peso: " << endl;
                    cin >> peso;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "( " << peso << ") peso no permitida " << endl;
                    }
                    if(peso < 100 ){
                        dude.setPeso(peso);
                        flagPeso = 1;
                     }
                    else{
                        cout << "( " << peso << ") peso no permitida " << endl;
                    }
                }while(flagPeso != 1);
                do{
                    cout << "Ingrese la altura: " << endl;
                    cin >> altura;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "( " << altura << ") altura no permitida " << endl;
                    }
                    else if(altura < 2 ){
                        dude.setAltura(altura);
                        flagAltura= 1;
                     }
                    else{
                        cout << "( " << altura << ") altura no permitida " << endl;
                    }
                }while(flagAltura != 1);
                p.insertar(dude);
                flagName = 0,flagEdad = 0,flagPeso = 0, flagAltura = 0;
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
            case 4:
                if (p.save()) {
                    cout << "Guardado exitosamente" << endl;
                }
                else{
                    cout << "Error hay algun problema al guardad" << endl;
                }
                enterToContinue();
            break;
            case 5:
                header();
                cout << "|    Buscar    |" << endl;
                cout << "| Ingresa el nombre de quien quieres buscar |" << endl;
                cin >> killname;
                if (!p.buscar(killname)) {
                    cout << killname << " No encontrado" << endl;
                }
                enterToContinue();
            break;
            case 6:
                header();
                cout << "|  Modificar   |" << endl;
                headerList();
                p.print();
                cout << "| Ingresa el nombre de quien quieres modificar |" << endl;
                cin >> killname;
                if (!p.modificar(killname)) {
                    cout << killname << " Error al modificar " << endl;
                }
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
