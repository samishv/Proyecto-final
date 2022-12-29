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

    public:
        Prototipo();
        virtual ~Prototipo();
        void setPrototipo();
        string getPrototipo();
        inline string getNombrePrototipo(){return nombrePrototipo;}


    protected:

};

#endif // PROTOTIPO_H
