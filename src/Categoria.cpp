#include "Categoria.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Categoria::Categoria()
{
    //ctor
}

Categoria::~Categoria()
{
    //dtor
}


void Categoria::setCategoria()
{
    cout << "Ingrese la cantidad de equipos que participaran: ";
    cin >> numEquipos;
    EQUIPOS = new Equipo[numEquipos];

    for(int i{0}; i < numEquipos; i++){
        cout << "\n\nIngrese nombre del equipo " << i+1 << " y registre sus prototipos";
        (EQUIPOS + i)->setEquipo();
    }

}

string Categoria::getCategoria()
{
    ostringstream salida;

    for(int i{0}; i < numEquipos; i++){
        cout << (EQUIPOS + i)->getEquipo();

    }
    return salida.str();
}

