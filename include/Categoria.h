#ifndef CATEGORIA_H
#define CATEGORIA_H
#include "Equipo.h"
#include <string>

class Categoria
{
    private:
        int numEquipos;
        Equipo *EQUIPOS;
        int totalPrototipos{0};
    public:
        Categoria();
        virtual ~Categoria();
        void setCategoria();
        string getCategoria();
        inline int getTotalPrototipos(){return totalPrototipos;}

    protected:


};

#endif // CATEGORIA_H
