#ifndef GRUPO_H
#define GRUPO_H
#include "Prototipo.h"
#include <string>

using namespace std;

class Grupo
{
    private:
        Prototipo *PROTOTIPOS;

    public:
        Grupo();
        virtual ~Grupo();
        void setGrupo(int, int);

    protected:

};

#endif // GRUPO_H
