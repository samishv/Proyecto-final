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
void Prototipo::setPrototipo()
{
    cin.ignore();
    cout << "\nNombre: ";

    getline(cin,nombrePrototipo);
    cout << "\nCantidad de integrantes: " << endl;
    cin >>  numeroIntegrantes;
    INTEGRANTES = new Integrantes[numeroIntegrantes];
    cin.ignore();
    cin.clear();
    for(int i{0}; i < numeroIntegrantes; i++){
        cout << "\n\nIngrese informacion del integrante '" << i + 1 << "'";
        (INTEGRANTES + i)->setIntegrante();
    }

}

string Prototipo::getPrototipo()
{
    ostringstream salidaPrototipo;



    salidaPrototipo << "\nPrototipo: " << nombrePrototipo;

    for(int i{0}; i < numeroIntegrantes; i++){
                cout << (INTEGRANTES + i)->getIntegrantes();
        }

    return salidaPrototipo.str();
}

