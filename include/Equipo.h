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

    public:
        Equipo();
        virtual ~Equipo();
        void setEquipo();
        string getEquipos();
        string getEquipo(int);
        inline int getnumPrototipos(){return numPrototipos;}

    protected:


};

#endif // EQUIPO_H
