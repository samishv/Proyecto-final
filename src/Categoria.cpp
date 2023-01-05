#include "Categoria.h"
#include "EliminacionDirecta.h"
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <random>
#include <windows.h>
#include <vector>

using namespace std;

Categoria::Categoria()
{
    //ctor
}

Categoria::~Categoria()
{
    //dtor
}


void Categoria::setCategoria()
{
    int pos{0};
    do{
        cout << "Ingrese la cantidad de equipos que participaran: ";
        cin >> numEquipos;

        if(numEquipos<1){
            cout << "Cantidad Incorrecta. Ingrese nuevamente.\n" << endl;
        }
    }while(numEquipos<1);

    EQUIPOS = new Equipo[numEquipos];

    for(int i{0}; i < numEquipos; i++){
        system("cls");
        cout << "\n\nIngrese nombre del equipo " << i+1 << " y registre sus prototipos\n";
        (EQUIPOS + i)->setEquipo(totalPrototipos);
        totalPrototipos+=(EQUIPOS + i)->getnumPrototipos();
    }

    ORGANIZADOS = new string[totalPrototipos];

    for(int i{0}; i < numEquipos; i++){
        for(int j{0}; j < (EQUIPOS + i)->getnumPrototipos(); j++){
            ORGANIZADOS[pos] = (EQUIPOS + i)->getInfoPrototipo(j);
            pos++;
        }
    }

    pos = 0;

    REVUELTOS = new string[totalPrototipos];
    REVUELTOS[totalPrototipos-1] = "libre";

    unsigned int semilla = chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine motorG(semilla);
    uniform_int_distribution<int> elegido(0,totalPrototipos-1);

    while(REVUELTOS[totalPrototipos-1] == "libre"){
        int lugar;
        lugar = elegido(motorG);

        if(ORGANIZADOS[lugar] == "usado"){
            continue;
        }

        REVUELTOS[pos] = ORGANIZADOS[lugar];
        ORGANIZADOS[lugar] = "usado";

        pos++;
    }

}

void Categoria::mostrarCategoria()
{
    for(int i{0}; i < numEquipos; i++){
        (EQUIPOS + i)->mostrarEquipos();
    }
}


string Categoria::getInfoPrototipo(int posicion,int posicionPrototipo)
{
    ostringstream salida;
        salida << (EQUIPOS + posicion)->getEquipo(posicionPrototipo);


    return salida.str();
}

void Categoria::elimDirecta(Categoria& Categ)
{
    EliminacionDirecta Eliminar{};
    Eliminar.eliminacionDirecta(Categ);
}

void Categoria::elimRobin(Categoria& Categ)
{
    EliminacionDirecta Eliminar{};
    Eliminar.roundRobin(Categ);
}

void Categoria::setByes()
{

    int n{2};
    int pos{0};
    int bandera, elegido, IDElegido;
    bool unique;


    // Determina el numero de byes

    while (pow(2,n)<=totalPrototipos){
        byes=pow(2,n+1)-totalPrototipos;

        if(pow(2,n)==totalPrototipos){
            byes = 0;
            break;
        }
        n++;
    }

         cout << "\nnumero de byes: " << byes << endl << endl;
         byesRestantes=byes;
         BYES = new int[byes];
         numParticipantes=totalPrototipos-byes;
         NOMBREPARTICIPANTES= new string[byes+(numParticipantes)/2];

    // asigna quienes seran los byes

    while(byesRestantes!=0){


        for(int i=0;i<numEquipos;i++){


                numPrototipos=(EQUIPOS + i)->getnumPrototipos();
                bandera = 0;

                do{

                    unsigned int semilla = chrono::steady_clock::now().time_since_epoch().count();
                    default_random_engine motorG(semilla);
                    uniform_int_distribution<int> pasan(0,numPrototipos-1);

                    elegido=pasan(motorG);
                    IDElegido=(EQUIPOS + i)->getEquipo(elegido);
                    BYES[pos]=IDElegido;
                    unique=true;
                    for(int j=0; j<pos; j++){

                        if(BYES[j]==IDElegido){
                            unique=false;
                        }

                    }

                    bandera ++;

                }while(!unique && bandera<=numPrototipos);

                if(bandera>numPrototipos){
                        continue;
                    }

                nombreElegido=(EQUIPOS + i)->getInfoPrototipo(elegido);
                NOMBREPARTICIPANTES[pos]=nombreElegido;
                pos ++;
                cout << "Del equipo " << i+1 << " pasa : " << nombreElegido << endl;
                byesRestantes--;

                if(byesRestantes==0){
                    break;
                }

        }

    }
}
