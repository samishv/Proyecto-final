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
        int prueba2n();
        void asignaByes();
        inline void setByes(){this->numByes=prueba2n();}
        void eliminacionDirecta(Categoria&);

    protected:



};

#endif // ELIMINACIONDIRECTA_H
