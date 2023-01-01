#ifndef ENFRENTAMIENTOS_H
#define ENFRENTAMIENTOS_H
#include <string>

using namespace std;

class Enfrentamientos
{
    private:
        string competidorRojo;
        string competidorAzul;
        int IDcompetidorRojo;
        int IDcompetidorAzul;


    public:
        Enfrentamientos();
        virtual ~Enfrentamientos();
        void setCompetidorRojo(string,int);
        void setCompetidorAzul(string,int);
        inline void setCompetidorRojo(string competidorRojo){this->competidorRojo=competidorRojo;}
        inline void setCompetidorAzul(string competidorAzul){this->competidorAzul=competidorAzul;}
        inline string getNombreCompetidorRojo(){return this->competidorRojo;}
        inline string getNombreCompetidorAzul(){return this->competidorAzul;}
        inline int getIDCompetidorRojo(){return this->IDcompetidorRojo;}
        inline int getIDCompetidorAzul(){return this->IDcompetidorAzul;}




    protected:


};

#endif // ENFRENTAMIENTOS_H
