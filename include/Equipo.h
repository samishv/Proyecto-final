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
        void setEquipo(int);
        void mostrarEquipos();
        int getEquipo(int);
        inline int getnumPrototipos(){return numPrototipos;}
        string getInfoPrototipo(int);

    protected:


};

#endif // EQUIPO_H
