#include "Equipo.h"
#include <iostream>
#include <string>
#include <sstream>

Equipo::Equipo()
{
    //ctor
}

Equipo::~Equipo()
{
    //dtor
}
void Equipo::setEquipo()
{
    cin.ignore();
    cout << "\nNombre del equipo: " << endl;
    getline(cin,nombreEquipo);


    cout << "\nCantidad de prototipos: ";
    cin >> numPrototipos;
    PROTOTIPOS = new Prototipo[numPrototipos];

    for(int i{0}; i < numPrototipos; i++){
        cout << "\n\nIngrese informacion del prototipo '" << i + 1 << "'";
        (PROTOTIPOS + i)->setPrototipo();
    }
}
string Equipo::getEquipo()
{
    ostringstream salidaEquipo;



    salidaEquipo << "\nEquipo: " << nombreEquipo;

    for(int i{0}; i < numPrototipos; i++){
                cout << (PROTOTIPOS + i)->getPrototipo();
        }


    return salidaEquipo.str();
}
