#ifndef ENFRENTAMIENTOS_H
#define ENFRENTAMIENTOS_H
#include <string>

using namespace std;

class Enfrentamientos
{
    private:
        string competidorRojo;
        string competidorAzul;
        string ganador;


    public:
        Enfrentamientos();
        virtual ~Enfrentamientos();
        inline void setCompetidorRojo(string competidorRojo){this->competidorRojo=competidorRojo;}
        inline void setCompetidorAzul(string competidorAzul){this->competidorAzul=competidorAzul;}
        inline string getCompetidorRojo(){return this->competidorRojo;}
        inline string getCompetidorAzul(){return this->competidorAzul;}


    protected:


};

#endif // ENFRENTAMIENTOS_H
