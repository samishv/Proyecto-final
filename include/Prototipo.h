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
        void setPrototipo(int);
        string getPrototipo();
        inline string getNombrePrototipo(){return nombrePrototipo;}
        inline int getIDPrototipo(){return ID_prototipo;}


    protected:

};

#endif // PROTOTIPO_H
