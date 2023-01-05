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
        string GANADOR;
        friend class EliminacionDirecta;


    public:
        Categoria();
        virtual ~Categoria();
        void setCategoria();        //Solicita la información con la cual se rellenarán los datos de los equipos
        void mostrarCategoria();        //Muestra la información de los equipos de la categoria
        string getInfoPrototipo(int,int);       //Devuelve el nombre de un prototipo en concreto.
        void elimDirecta(Categoria&);       //Llama al método eliminacionDirecta de la clase Eliminacion.
        void setByes();     //Determina el numero de Byes que habrá y asigna quienes serán los byes.
        inline void setTotalPrototipos(int total){totalPrototipos = total;}         //Asigna cuantos prototipos hay en total.
        inline int getTotalPrototipos(){return totalPrototipos;}        //Regresa la cantidad total de prototipos.


    protected:


};

#endif // CATEGORIA_H
