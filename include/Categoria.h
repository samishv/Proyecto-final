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
        int numRondas;
        int *BYES;
        int numEnfrentamientos;
        int numParticipantes;
        Equipo *EQUIPOS;
        Enfrentamientos *ENFRENTAMIENTOS;
        string *ORGANIZADOS;
        string *REVUELTOS;
        string nombreElegido;
        string *NOMBREPARTICIPANTES;
        string TERCEROS[2];
        string GANADORES[3];
        friend class EliminacionDirecta;
        friend class Grupo;


    public:
        Categoria();
        virtual ~Categoria();
        void setCategoria();
        void mostrarCategoria();
        string getInfoPrototipo(int,int);
        void elimDirecta(Categoria&);
        void elimRobin(Categoria&);
        void setByes();
        inline void setTotalPrototipos(int total){totalPrototipos = total;}
        inline int getTotalPrototipos(){return totalPrototipos;}


    protected:



};

#endif // CATEGORIA_H
