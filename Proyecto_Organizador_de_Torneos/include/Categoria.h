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
        void setCategoria();        //Solicita la informaci�n con la cual se rellenar�n los datos de los equipos
        void mostrarCategoria();        //Muestra la informaci�n de los equipos de la categoria
        string getInfoPrototipo(int,int);       //Devuelve el nombre de un prototipo en concreto.
        void elimDirecta(Categoria&);       //Llama al m�todo eliminacionDirecta de la clase Eliminacion.
        void setByes();     //Determina el numero de Byes que habr� y asigna quienes ser�n los byes.
        inline void setTotalPrototipos(int total){totalPrototipos = total;}         //Asigna cuantos prototipos hay en total.
        inline int getTotalPrototipos(){return totalPrototipos;}        //Regresa la cantidad total de prototipos.


    protected:


};

#endif // CATEGORIA_H
