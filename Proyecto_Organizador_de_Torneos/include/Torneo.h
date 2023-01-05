#ifndef TORNEO_H
#define TORNEO_H
#include "EliminacionDirecta.h"
#include "Categoria.h"

class Torneo
{

    private:
        int numCategoria;
        int opcionEncuentro;
        Categoria MiniRC{};
        Categoria MiniAutonomo{};



    public:
        Torneo();
        virtual ~Torneo();
        void setTorneo();       //Dentro del objeto torneo se registrará la categoría y dará paso a que se empiecen a rellenar los datos.
        void setEncuentros(Categoria&);     //En el objeto torneo se solicitará el sistema de enfrentamientos que se usará para determinar los ganadores.
        void mostrarCategoria(int);     //Permite ver los datos guardados en la categoria elegida.

    protected:


};

#endif // TORNEO_H
