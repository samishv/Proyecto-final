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
    fflush(stdin);
    cout << "\nNombre del equipo: ";
    getline(cin,nombreEquipo);


    do{
        cout << "\nCantidad de prototipos: ";
        cin >> numPrototipos;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            numPrototipos = 0;
        }
    }while(numPrototipos<1);

    PROTOTIPOS = new Prototipo[numPrototipos];

    for(int i{0}; i < numPrototipos; i++){
        cout << "\n\nIngrese informacion del prototipo '" << i + 1 << "'";
        (PROTOTIPOS + i)->setPrototipo(this->contPrototipos);
        this->contPrototipos ++;
    }
}

void Equipo::mostrarEquipos()
{
    cout << "\nEquipo: " << nombreEquipo;

    for(int i{0}; i < numPrototipos; i++){
        (PROTOTIPOS + i)->mostrarPrototipo();
    }
}

int Equipo::getEquipo(int posicionPrototipo)
{
    return(PROTOTIPOS + posicionPrototipo)->getIDPrototipo();
}

string Equipo::getInfoPrototipo(int posicionPrototipo)
{
    return(PROTOTIPOS + posicionPrototipo)->getNombrePrototipo();
}
