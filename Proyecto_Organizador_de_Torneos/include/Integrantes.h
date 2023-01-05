#ifndef INTEGRANTES_H
#define INTEGRANTES_H
#include <string>

using namespace std;

class Integrantes
{
    private:
        string nombreIntegrante;


    public:
        Integrantes();
        virtual ~Integrantes();
        void setIntegrante();       //Asigna el nombre del integrante.
        string getIntegrantes();        //Devuelve el nombre del integrante.

    protected:


};

#endif // INTEGRANTES_H
