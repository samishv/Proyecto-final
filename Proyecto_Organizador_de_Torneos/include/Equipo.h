#ifndef EQUIPO_H
#define EQUIPO_H
#include "Prototipo.h"
#include <string>

class Equipo
{
    private:
        string nombreEquipo;
        int numPrototipos;
        Prototipo *PROTOTIPOS;
        int contPrototipos;

    public:
        Equipo();
        virtual ~Equipo();
        void setEquipo(int);        //Solicita la informaci�n del equipo y la almacena.
        void mostrarEquipos();      //Muestra la informaci�n del equipo.
        int getEquipo(int);     //Devuelve el nombre de un prototipo del equipo elegido.
        inline int getnumPrototipos(){return numPrototipos;}        //Devuelve la cantidad de prototipos en el equipo.
        string getInfoPrototipo(int);       //Devuelve la informaci�n de los prototipos registrados.

    protected:


};

#endif // EQUIPO_H
