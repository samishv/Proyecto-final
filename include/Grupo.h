#ifndef GRUPO_H
#define GRUPO_H
#include "Categoria.h"
#include <string>

using namespace std;

class Grupo
{
    private:
        string *NOMBRES;

    public:
        Grupo();
        virtual ~Grupo();
        void setGrupo(int, int, Categoria);
        void mostrarGrupo(int);

    protected:

};

#endif // GRUPO_H
