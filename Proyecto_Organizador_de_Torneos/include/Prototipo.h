#ifndef PROTOTIPO_H
#define PROTOTIPO_H
#include "Integrantes.h"
#include <string>

class Prototipo
{
    private:
        string nombrePrototipo;
        int numeroIntegrantes;
        Integrantes *INTEGRANTES;
        int ID_prototipo;

    public:
        Prototipo();
        virtual ~Prototipo();
        void setPrototipo(int);     //Asigna el nombre del prototipo.
        void mostrarPrototipo();        //Muestra el nombre del prototipo y los integrantes.
        inline string getNombrePrototipo(){return nombrePrototipo;}     //Devuelve el nombre del prototipo.
        inline int getIDPrototipo(){return ID_prototipo;}       //Devuelve el valor numérico asignado al prototipo.


    protected:

};

#endif // PROTOTIPO_H
