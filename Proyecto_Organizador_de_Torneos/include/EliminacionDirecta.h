#ifndef ELIMINACIONDIRECTA_H
#define ELIMINACIONDIRECTA_H
#include "Prototipo.h"
#include "Categoria.h"
#include "Torneo.h"


class EliminacionDirecta
{

    private:
        int totalPrototipos;
        int totalEquipos;
        Prototipo *BYES;
        int numByes;
        int numPrototipos;

    public:
        EliminacionDirecta();
        EliminacionDirecta(int,int);
        virtual ~EliminacionDirecta();
        int prueba2n();     //Calcula la cantidad de byes que va a haber.
        void eliminacionDirecta(Categoria&);        //Da a conocer los ganadores mediante el modo de enfretamiento de eliminacion directa.
        void asignaByes();      //Muestra cuantos equipo y byes hay.
        inline void setByes(){this->numByes=prueba2n();}        //Almacena la cantidad de byes.

    protected:



};

#endif // ELIMINACIONDIRECTA_H
