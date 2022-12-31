#ifndef CATEGORIA_H
#define CATEGORIA_H
#include "Equipo.h"
#include "Enfrentamientos.h"
#include <string>

class Categoria: public Enfrentamientos

{

    private:
        int numEquipos;
        Equipo *EQUIPOS;
        int totalPrototipos{0};
        int numPrototipos;
        int contPrototipos{0};
        string nombreElegido;
        int numRondas;
        int numEnfrentamientos;
        Enfrentamientos *ENFRENTAMIENTOS;

    public:
        Categoria();
        virtual ~Categoria();
        void setCategoria();
        string getCategoria();
        //inline int getTotalPrototipos(){return totalPrototipos;}
        //inline int getTotalEquipos(){return numEquipos;}
        int getInfoEquipo(int);
        string getInfoPrototipo(int,int);
        void eliminacionDirecta();

    protected:


};

#endif // CATEGORIA_H
