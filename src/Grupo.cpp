#include "Grupo.h"
#include <iostream>

using namespace std;

Grupo::Grupo()
{
    //ctor
}

Grupo::~Grupo()
{
    //dtor
}

void Grupo::setGrupo(int tamanio, int inicio, Categoria Categ)
{
    NOMBRES = new string[tamanio];

    for(int i=0; i<tamanio; i++){
        NOMBRES[i] = Categ.REVUELTOS[inicio+i];
    }
}

void Grupo::mostrarGrupo(int tamanio)
{
    for(int i=0; i<tamanio; i++){
        cout << NOMBRES[i] << endl;
    }
}
