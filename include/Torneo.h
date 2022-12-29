#ifndef TORNEO_H
#define TORNEO_H
#include "EliminacionDirecta.h"
#include "Categoria.h"

class Torneo
{
    friend class EliminacionDirecta;
    private:
        int numCategoria;
        int opcionEncuentro;
        Categoria MiniRC{};
        Categoria MiniAutonomo{};



    public:
        Torneo();
        virtual ~Torneo();
        void setTorneo();
        void setEncuentros();
        void mostrarCategoria(int);

    protected:


};

#endif // TORNEO_H
