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
        void setCompetidorRojo(string,int);     //Asigna al competidorRojo el nombre que recibe.
        void setCompetidorAzul(string,int);     //Asigna al competidorAzul el nombre que recibe.
        inline void setCompetidorRojo(string competidorRojo){this->competidorRojo=competidorRojo;}      //Asigna al competidorRojo el nombre que recibe.
        inline void setCompetidorAzul(string competidorAzul){this->competidorAzul=competidorAzul;}      //Asigna al competidorAzul el nombre que recibe.
        inline string getNombreCompetidorRojo(){return this->competidorRojo;}       //Devuelve el nombre del competidorRojo.
        inline string getNombreCompetidorAzul(){return this->competidorAzul;}       //Devuelve el nombre del competidorAzul.
        inline int getIDCompetidorRojo(){return this->IDcompetidorRojo;}        //Devuelve el numero de identificación del competidorRojo.
        inline int getIDCompetidorAzul(){return this->IDcompetidorAzul;}        //Devuelve el numero de identificación del competidorAzul.




    protected:


};

#endif // ENFRENTAMIENTOS_H
