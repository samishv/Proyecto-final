#include "Integrantes.h"
#include <iostream>
#include <sstream>

using namespace std;

Integrantes::Integrantes()
{
    //ctor
}

Integrantes::~Integrantes()
{
    //dtor
}
void Integrantes::setIntegrante()
{
    cout << "\nNombre: ";

    getline(cin,nombreIntegrante);



}

string Integrantes::getIntegrantes()
{
    ostringstream salidaIntegrantes;
    salidaIntegrantes << "\nIntegrante: " << nombreIntegrante;
    return salidaIntegrantes.str();
}

