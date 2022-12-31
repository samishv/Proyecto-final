#include "Categoria.h"
#include <iostream>
#include <sstream>
#include <string.h>
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
    cout << "Ingrese la cantidad de equipos que participaran: ";
    cin >> numEquipos;
    EQUIPOS = new Equipo[numEquipos];

    for(int i{0}; i < numEquipos; i++){
        system("cls");
        cout << "\n\nIngrese nombre del equipo " << i+1 << " y registre sus prototipos\n";
        (EQUIPOS + i)->setEquipo(totalPrototipos);
        totalPrototipos+=(EQUIPOS + i)->getnumPrototipos();


    }
    cout << totalPrototipos << endl;
}

string Categoria::getCategoria()
{
    ostringstream salida;

    for(int i{0}; i < numEquipos; i++){
        cout << (EQUIPOS + i)->getEquipos();

    }
    return salida.str();
}

int Categoria::getInfoEquipo(int posicion){

    return (EQUIPOS+posicion)->getnumPrototipos();
}


string Categoria::getInfoPrototipo(int posicion,int posicionPrototipo)
{
    ostringstream salida;
        cout << (EQUIPOS + posicion)->getEquipo(posicionPrototipo);


    return salida.str();
}

void Categoria::eliminacionDirecta()
{
    int n{2};
    int byes{87};
    int elegido,IDElegido,*BYES, *PARTICIPANTES, bandera,numParticipantes,byesRestantes,numEnfrentamiento;
    int pos{0};
    string nombreElegido;
    bool unique {false};
    bool nuevoEnfrentamiento {true};




    // Determina el numero de byes

    while (pow(2,n)<=totalPrototipos){
        byes=pow(2,n+1)-totalPrototipos;

        if(pow(2,n)==totalPrototipos){
            byes = 0;
            break;
        }
        n++;
    }

         cout << "\nnumero de byes: " << byes << endl;
         byesRestantes=byes;
         BYES = new int[byes];

    // asigna quienes seran los byes

    while(byesRestantes!=0){

         cout << "\nnumero de equipos: " << numEquipos << endl;

        for(int i=0;i<numEquipos;i++){


                numPrototipos=(EQUIPOS + i)->getnumPrototipos();
                cout << "Prototipos del equipo '" << i+1 <<"' " << numPrototipos<<endl;
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
                    cout << "Prototipos " << numPrototipos << " Bandera " << bandera <<endl;

                }while(!unique && bandera<=numPrototipos);

                if(bandera>numPrototipos){
                        continue;
                    }

                nombreElegido=(EQUIPOS + i)->getInfoPrototipo(elegido);
                pos ++;
                cout << "Del equipo " << i+1 << " pasa el prototipo " << elegido+1 <<" : " << IDElegido  << " " <<nombreElegido << "\nnumero de byes: " << byesRestantes << endl;
                byesRestantes--;

                if(byesRestantes==0){
                    break;
                }

        }

    }

    for(int j=0; j<pos; j++){
            cout << BYES[j] << endl;
    }

// Asigna los enfrentamientos

        pos=0;
        //numRondas=totalPrototipos-1;
        numRondas=0;
        numParticipantes=totalPrototipos-byes;
        //participantesRestantes=numParticipantes;

        for(int i =0; i<=numRondas; i++){

            PARTICIPANTES= new int[numParticipantes];
            ENFRENTAMIENTOS = new Enfrentamientos[numParticipantes/2];
            numEnfrentamiento=0;


            while(numParticipantes!=0){

                cout << "\nnumero de equipos: " << numEquipos << endl;

                for(int i=0;i<numEquipos;i++){


                        numPrototipos=(EQUIPOS + i)->getnumPrototipos();
                        cout << "Prototipos del equipo '" << i+1 <<"' " << numPrototipos<<endl;
                        bandera = 0;

                do{

                    unsigned int semilla = chrono::steady_clock::now().time_since_epoch().count();
                    default_random_engine motorG(semilla);
                    uniform_int_distribution<int> participante(0,numPrototipos-1);

                    elegido=participante(motorG);
                    IDElegido=(EQUIPOS + i)->getEquipo(elegido);
                    PARTICIPANTES[pos]=IDElegido;
                    unique=true;
                    for(int j=0; j<pos; j++){

                        if(PARTICIPANTES[j]==IDElegido){
                            unique=false;
                        }

                    }

                    for(int j=0; j<byes; j++){

                        if(BYES[j]==IDElegido){
                            unique=false;
                        }

                    }


                    bandera ++;
                    cout << "Prototipos " << numPrototipos << " Bandera " << bandera <<endl;

                }while(!unique && bandera<=numPrototipos);

                if(bandera>numPrototipos){
                        continue;
                    }

                nombreElegido=(EQUIPOS + i)->getInfoPrototipo(elegido);
                pos ++;

                if(nuevoEnfrentamiento){
                    (ENFRENTAMIENTOS+numEnfrentamiento)->setCompetidorRojo(nombreElegido);
                    nuevoEnfrentamiento=false;
                }else{
                    (ENFRENTAMIENTOS+numEnfrentamiento)->setCompetidorAzul(nombreElegido);
                    nuevoEnfrentamiento=true;
                    numEnfrentamiento++;
                }

                cout << "Del equipo " << i+1 << " el prototipo " << elegido+1 <<" : " << IDElegido  << " " <<nombreElegido << "\nnumero de byes: " << byesRestantes << endl;
                numParticipantes--;

                if(numParticipantes==0){
                    break;
                }

                }

            }


              for(int i=0; i<numEnfrentamientos; i++){

                    cout << "\nENFRENTAMIENTO " << i+1 << ": "
                        << (ENFRENTAMIENTOS+i)->getCompetidorRojo() << " vs " << (ENFRENTAMIENTOS+i)->getCompetidorAzul() << endl;


            }



        }

    }



