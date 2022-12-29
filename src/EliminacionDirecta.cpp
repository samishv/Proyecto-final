#include "EliminacionDirecta.h"
#include <iostream>
#include <chrono>
#include <random>
#include <windows.h>

using namespace std;

EliminacionDirecta::EliminacionDirecta(int totalPrototipos, int totalEquipos)
{
    this->totalPrototipos=totalPrototipos;
    this->totalEquipos=totalEquipos;
    //ctor
}

EliminacionDirecta::~EliminacionDirecta()
{
    //dtor
}

int EliminacionDirecta::prueba2n()
{
    int n{2};
    int byes{87};
    while ((2^n)<=totalPrototipos){
        byes=(2^(n+1))-totalPrototipos;
        if((2^n)==totalPrototipos){
            byes = 0;
            break;
        }
        n+=1;
    }

    return byes;
}


void EliminacionDirecta::asignaByes()
{
    cout << "total equipos:" << totalEquipos
         << "\nnumero de byes: " << numByes << endl;


    /*BYES = new Prototipo[numByes];

    while(numByes!=0){
        for(int i=0;i<totalEquipos;i++){
                this->numPrototipos=Categoria::MiniRC.getInfoEquipo(i);
                cout << "Prototipos del equipo '" << i+1 <<"' " << numPrototipos<<endl;
                for(int j=0;j<numPrototipos;j++){
                    unsigned int semilla = chrono::steady_clock::now().time_since_epoch().count();
                    default_random_engine motorG(semilla);
                    uniform_int_distribution<int> pasan(0,numPrototipos);
                    cout << getInfoPrototipo(i,pasan(motorG)) << endl;
                    numByes-=1;
                }

        }
    }*/
}
