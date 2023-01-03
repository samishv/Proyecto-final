#include "Grupo.h"

Grupo::Grupo()
{
    //ctor
}

Grupo::~Grupo()
{
    //dtor
}

void Grupo::setGrupo(int tamanio, int inicio)
{
    PROTOTIPOS = new Prototipo[tamanio];

    for(int i=0; i<tamanio; i++){
        //(PROTOTIPOS + i) = (EQUIPOS + i)->getInfoPrototipo(inicio+i);
    }

    /*(EQUIPOS + i)->getInfoPrototipo(elegido);
    (PROTOTIPOS + i)->setPrototipo(this->contPrototipos);*/
}
