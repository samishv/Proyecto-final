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
    cout << "\nNombre del equipo: ";
    getline(cin,nombreEquipo);


    cout << "\nCantidad de prototipos: ";
    cin >> numPrototipos;
    PROTOTIPOS = new Prototipo[numPrototipos];

    for(int i{0}; i < numPrototipos; i++){
        cout << "\n\nIngrese informacion del prototipo '" << i + 1 << "'";
        (PROTOTIPOS + i)->setPrototipo();
    }
}
string Equipo::getEquipos()
{
    ostringstream salidaEquipos;

    salidaEquipos << "\nEquipo: " << nombreEquipo;

    for(int i{0}; i < numPrototipos; i++){
                cout << (PROTOTIPOS + i)->getPrototipo();
        }


    return salidaEquipos.str();
}

string Equipo::getEquipo(int posicionPrototipo)
{
    ostringstream salidaEquipo;

    salidaEquipo <<  (PROTOTIPOS + posicionPrototipo)->getNombrePrototipo();

    return salidaEquipo.str();
}
