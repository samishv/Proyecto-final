#include "Prototipo.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Prototipo::Prototipo()
{
    //ctor
}

Prototipo::~Prototipo()
{
    //dtor
}

void Prototipo::setPrototipo(int ID_prototipo)
{
    this->ID_prototipo=ID_prototipo;
    fflush(stdin);
    cout << "\nNombre: ";

    getline(cin,nombrePrototipo);
    do{
        cout << "\nCantidad de integrantes: ";
        cin >>  numeroIntegrantes;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            numeroIntegrantes = 0;
        }
    }while(numeroIntegrantes<1);

    INTEGRANTES = new Integrantes[numeroIntegrantes];
    cin.ignore();
    cin.clear();
    for(int i{0}; i < numeroIntegrantes; i++){
        cout << "\n\nIngrese informacion del integrante '" << i + 1 << "'";
        (INTEGRANTES + i)->setIntegrante();
    }


}

void Prototipo::mostrarPrototipo()
{
    cout << "\nPrototipo: " << nombrePrototipo;

    for(int i{0}; i < numeroIntegrantes; i++){
        cout << (INTEGRANTES + i)->getIntegrantes();
    }
}
