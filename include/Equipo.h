#ifndef EQUIPO_H
#define EQUIPO_H
#include "Prototipo.h"
#include <string>

class Equipo
{
    friend class Categoria;
    private:
        string nombreEquipo;
        int numPrototipos;
        Prototipo *PROTOTIPOS;

    public:
        Equipo();
        virtual ~Equipo();
        void setEquipo();
        string getEquipo();

    protected:


};

#endif // EQUIPO_H
