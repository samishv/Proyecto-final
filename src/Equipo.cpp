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
void Equipo::setEquipo(int contProtipos)
{
    this->contPrototipos=contProtipos;
    cin.ignore();
    cout << "\nNombre del equipo: ";
    getline(cin,nombreEquipo);


    cout << "\nCantidad de prototipos: ";
    cin >> numPrototipos;
    PROTOTIPOS = new Prototipo[numPrototipos];

    for(int i{0}; i < numPrototipos; i++){
        cout << "\n\nIngrese informacion del prototipo '" << i + 1 << "'";
        cout << "\ncontPrototpipos: " << this->contPrototipos<<endl;
        (PROTOTIPOS + i)->setPrototipo(this->contPrototipos);
        this->contPrototipos ++;
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

int Equipo::getEquipo(int posicionPrototipo)
{
    return(PROTOTIPOS + posicionPrototipo)->getIDPrototipo();


}

string Equipo::getInfoPrototipo(int posicionPrototipo)
{
    return(PROTOTIPOS + posicionPrototipo)->getNombrePrototipo();


}
