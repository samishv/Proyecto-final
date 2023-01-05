#include "EliminacionDirecta.h"
#include <iostream>
#include <chrono>
#include <random>
#include <windows.h>

using namespace std;

EliminacionDirecta::EliminacionDirecta()
{
    //ctor
}

EliminacionDirecta::EliminacionDirecta(int totalPrototipos, int totalEquipos)
{
    this->totalPrototipos=totalPrototipos;
    this->totalEquipos=totalEquipos;
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

void EliminacionDirecta::eliminacionDirecta(Categoria& Categ)
{
    int ganadorEnfrentamiento{}, participante{};
    int elegido{},IDElegido{},*PARTICIPANTES, bandera{},numEnfrentamiento{};
    int pos{0};
    string nombreCompetidorRojo{""},nombreCompetidorAzul{""};
    bool unique {false};
    bool nuevoEnfrentamiento {true};



    // Asigna los enfrentamientos

    pos=0;
    Categ.numRondas=Categ.totalPrototipos-1;
    Categ.numParticipantes=Categ.totalPrototipos-Categ.byes;
    PARTICIPANTES= new int[Categ.numParticipantes];

    Categ.numEnfrentamientos=Categ.numParticipantes/2;

    Categ.ENFRENTAMIENTOS = new Enfrentamientos[Categ.numEnfrentamientos];
    numEnfrentamiento=0;


    while(Categ.numParticipantes!=0){

        for(int i=0;i<Categ.numEquipos;i++){

                Categ.numPrototipos=(Categ.EQUIPOS + i)->getnumPrototipos();
                bandera = 0;

                do{

                    unsigned int semilla = chrono::steady_clock::now().time_since_epoch().count();
                    default_random_engine motorG(semilla);
                    uniform_int_distribution<int> participante(0,Categ.numPrototipos-1);

                    elegido=participante(motorG);
                    IDElegido=(Categ.EQUIPOS + i)->getEquipo(elegido);
                    PARTICIPANTES[pos]=IDElegido;
                    unique=true;
                    for(int j=0; j<pos; j++){

                        if(PARTICIPANTES[j]==IDElegido){
                            unique=false;
                        }

                    }

                    for(int j=0; j<Categ.byes; j++){

                        if(Categ.BYES[j]==IDElegido){
                            unique=false;
                        }
                    }

                    bandera ++;

                }while(!unique && bandera<=Categ.numPrototipos);

                if(bandera>Categ.numPrototipos){
                    continue;
                }

                Categ.nombreElegido=(Categ.EQUIPOS + i)->getInfoPrototipo(elegido);
                pos ++;

                if(nuevoEnfrentamiento){
                    (Categ.ENFRENTAMIENTOS+numEnfrentamiento)->setCompetidorRojo(Categ.nombreElegido,IDElegido);
                    nuevoEnfrentamiento=false;
                }else{
                     (Categ.ENFRENTAMIENTOS+numEnfrentamiento)->setCompetidorAzul(Categ.nombreElegido,IDElegido);
                      nuevoEnfrentamiento=true;
                      numEnfrentamiento++;
                     }

                Categ.numParticipantes--;

                if(Categ.numParticipantes==0){
                    break;
                }

        }

}

              for(int i=0; i<Categ.numEnfrentamientos; i++){

                    cout << "\nENFRENTAMIENTO " << i+1 << ": "
                        << (Categ.ENFRENTAMIENTOS+i)->getNombreCompetidorRojo() << " vs " << (Categ.ENFRENTAMIENTOS+i)->getNombreCompetidorAzul() << endl;

              }


             for(int i =2; i<Categ.numRondas+1; i++){

                    Categ.numParticipantes=Categ.byes+Categ.numEnfrentamientos;

                    for(int j=Categ.byes; j<Categ.numParticipantes; j++){

                            nombreCompetidorRojo=(Categ.ENFRENTAMIENTOS+j-Categ.byes)->getNombreCompetidorRojo();
                            nombreCompetidorAzul=(Categ.ENFRENTAMIENTOS+j-Categ.byes)->getNombreCompetidorAzul();


                            do{
                            cout << "\nSeleccione el ganador del enfrentamiento " << j-Categ.byes+1 << ": "
                                   << "\n1. " << nombreCompetidorRojo
                                   << "\n2. " << nombreCompetidorAzul << endl
                                   << "Ganador: ";
                            cin>>ganadorEnfrentamiento;
                            if(cin.fail()){
                                cin.clear();
                                cin.ignore();
                                ganadorEnfrentamiento = 0;
                            }
                            }while(ganadorEnfrentamiento<1);

                            cout << endl << endl;

                            switch(ganadorEnfrentamiento){
                                case 1:
                                    cout << "Ganador: " << nombreCompetidorRojo << endl;
                                    Categ.NOMBREPARTICIPANTES[j]=nombreCompetidorRojo;
                                    Categ.GANADOR = nombreCompetidorRojo;
                                    break;
                                case 2:
                                    cout << "Ganador: " << nombreCompetidorAzul << endl;
                                    Categ.NOMBREPARTICIPANTES[j]=nombreCompetidorAzul;
                                    Categ.GANADOR = nombreCompetidorAzul;
                                    break;
                                default:
                                    cout << "Opcion invalida, prueba otra vez: " << endl;
                    }
            }

            Categ.byes=0;

            delete[] Categ.ENFRENTAMIENTOS;
            Categ.numEnfrentamientos=Categ.numParticipantes/2;
            Categ.ENFRENTAMIENTOS=new Enfrentamientos[Categ.numEnfrentamientos];
            participante=0;
            for(int j=0; j<Categ.numEnfrentamientos; j++){

                (Categ.ENFRENTAMIENTOS+j)->setCompetidorRojo(Categ.NOMBREPARTICIPANTES[participante]);
                participante ++;
                (Categ.ENFRENTAMIENTOS+j)->setCompetidorAzul(Categ.NOMBREPARTICIPANTES[participante]);
                participante ++;
            }

            for(int j=0; j<Categ.numEnfrentamientos; j++){

                    cout << "\nENFRENTAMIENTO " << j+1 << ": "
                        << (Categ.ENFRENTAMIENTOS+j)->getNombreCompetidorRojo() << " vs " << (Categ.ENFRENTAMIENTOS+j)->getNombreCompetidorAzul() << endl;

              }

    }

    cout << "\nGANADOR 1° lugar: " << Categ.GANADOR << endl << endl;
}


void EliminacionDirecta::asignaByes()
{
    cout << "total equipos:" << totalEquipos
         << "\nnumero de byes: " << numByes << endl;
}
