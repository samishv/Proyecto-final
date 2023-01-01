#ifndef CATEGORIA_H
#define CATEGORIA_H
#include "Equipo.h"
#include "Enfrentamientos.h"
#include <string>

class Categoria

{

    private:
        int numEquipos;
        int totalPrototipos{0};
        int byes;
        int byesRestantes;
        int numPrototipos;
        int contPrototipos{0};
        int *BYES;
        int numRondas;
        int numEnfrentamientos;
        int numParticipantes;
        Equipo *EQUIPOS;
        Enfrentamientos *ENFRENTAMIENTOS;
        string nombreElegido;
        string *NOMBREPARTICIPANTES;


    public:
        Categoria();
        virtual ~Categoria();
        void setCategoria();
        string getCategoria();
        string getInfoPrototipo(int,int);
        void eliminacionDirecta();
        void setByes();


    protected:


};

#endif // CATEGORIA_H
