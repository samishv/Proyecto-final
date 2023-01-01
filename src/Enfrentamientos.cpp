#include "Enfrentamientos.h"

Enfrentamientos::Enfrentamientos()
{
    //ctor
}

Enfrentamientos::~Enfrentamientos()
{
    //dtor
}
void Enfrentamientos::setCompetidorRojo(string competidorRojo, int IDcompetidorRojo)
{
    this->competidorRojo=competidorRojo;
    this->IDcompetidorRojo=IDcompetidorRojo;
}

void Enfrentamientos::setCompetidorAzul(string competidorAzul, int IDcompetidorAzul)
{
    this->competidorAzul=competidorAzul;
    this->IDcompetidorAzul=IDcompetidorAzul;
}


