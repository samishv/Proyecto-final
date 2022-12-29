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
        system("cls");
        cout << "\n\nIngrese nombre del equipo " << i+1 << " y registre sus prototipos\n";
        (EQUIPOS + i)->setEquipo();
        totalPrototipos+=(EQUIPOS + i)->numPrototipos;


    }
    cout << totalPrototipos << endl;
}

string Categoria::getCategoria()
{
    ostringstream salida;

    for(int i{0}; i < numEquipos; i++){
        cout << (EQUIPOS + i)->getEquipo();

    }
    return salida.str();
}

