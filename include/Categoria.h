#ifndef CATEGORIA_H
#define CATEGORIA_H
#include "Equipo.h"
#include <string>

class Categoria
{
    private:
        int numEquipos;
        Equipo *EQUIPOS;

    public:
        Categoria();
        virtual ~Categoria();
        void setCategoria();
        string getCategoria();

    protected:


};

#endif // CATEGORIA_H
