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
    int elegido{},IDElegido{},*PARTICIPANTES{}, bandera{},numEnfrentamiento{};
    int pos{0};
    string nombreCompetidorRojo{""},nombreCompetidorAzul{""};
    bool unique {false};
    bool nuevoEnfrentamiento {true};



    // Asigna los enfrentamientos

    pos=0;

    Categ.numRondas = Categ.totalPrototipos-1;
    Categ.numParticipantes = Categ.totalPrototipos - Categ.byes;
    PARTICIPANTES= new int[Categ.numParticipantes];

    Categ.numEnfrentamientos = Categ.numParticipantes/2;

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

                    if(PARTICIPANTES[j] == IDElegido){
                        unique=false;
                    }

                }

                for(int j=0; j<Categ.byes; j++){

                    if(Categ.BYES[j] == IDElegido){
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


    // Rondas a partir de la segunda
    for(int i =2; i<=(Categ.numRondas+1); i++){

        if(i==(Categ.numRondas+1)){
            Categ.numParticipantes=1;
        }else{
            Categ.numParticipantes=Categ.byes+Categ.numEnfrentamientos;
        }

        for(int j=Categ.byes; j<Categ.numParticipantes; j++){

            nombreCompetidorRojo=(Categ.ENFRENTAMIENTOS+j-Categ.byes)->getNombreCompetidorRojo();
            nombreCompetidorAzul=(Categ.ENFRENTAMIENTOS+j-Categ.byes)->getNombreCompetidorAzul();

            if(i==(Categ.numRondas+1)){
                cout << "\nSeleccione el ganador del tercer lugar : " << endl;
            }else{
                cout << "\nSeleccione el ganador del enfrentamiento " << j-Categ.byes+1 << ": " << endl;
            }

            cout << "\n1. " << nombreCompetidorRojo
                 << "\n2. " << nombreCompetidorAzul << endl;

            cin>>ganadorEnfrentamiento;
            cout << endl << endl;

            switch(ganadorEnfrentamiento){
            case 1:
                cout << "Ganador: " << nombreCompetidorRojo << endl;
                //Dependiendo de la ronda, guarda a los ganadores
                if(i==(Categ.numRondas-1)){
                    Categ.TERCEROS[j]=nombreCompetidorAzul;
                    Categ.NOMBREPARTICIPANTES[j]=nombreCompetidorRojo;
                }else if(i==(Categ.numRondas)){
                    Categ.GANADORES[0]=nombreCompetidorRojo;
                    Categ.GANADORES[1]=nombreCompetidorAzul;
                    Categ.NOMBREPARTICIPANTES[0]=Categ.TERCEROS[0];
                    Categ.NOMBREPARTICIPANTES[1]=Categ.TERCEROS[1];
                }else{
                    Categ.NOMBREPARTICIPANTES[j]=nombreCompetidorRojo;
                }
                if(i==(Categ.numRondas+1)){
                    Categ.GANADORES[2]=nombreCompetidorRojo;
                }

                break;

            case 2:
                cout << "Ganador: " << nombreCompetidorAzul << endl;
                if(i==(Categ.numRondas-1)){
                    Categ.TERCEROS[j]=nombreCompetidorRojo;
                    Categ.NOMBREPARTICIPANTES[j]=nombreCompetidorAzul;
                    for(int j=0; j<2; j++){

                        cout << Categ.TERCEROS[j] << endl;

                    }
                }else if(i==(Categ.numRondas)){
                    Categ.GANADORES[0]=nombreCompetidorAzul;
                    Categ.GANADORES[1]=nombreCompetidorRojo;
                    Categ.NOMBREPARTICIPANTES[0]=Categ.TERCEROS[0];
                    Categ.NOMBREPARTICIPANTES[1]=Categ.TERCEROS[1];
                    for(int j=0; j<2; j++){

                        cout << Categ.NOMBREPARTICIPANTES[j] << endl;

                    }
                }else{
                    Categ.NOMBREPARTICIPANTES[j]=nombreCompetidorAzul;
                }

                if(i==(Categ.numRondas+1)){
                    Categ.GANADORES[2]=nombreCompetidorAzul;
                }

                break;
            default:
                cout << "Opcion invalida, prueba otra vez: " << endl;
            }
        }

        Categ.byes=0;

        delete[] Categ.ENFRENTAMIENTOS;

        if(i==(Categ.numRondas)){
            Categ.numEnfrentamientos=1;
        }else if(i==(Categ.numRondas+1)){
            Categ.numEnfrentamientos=1;
        }else{
            Categ.numEnfrentamientos=Categ.numParticipantes/2;
        }

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

        for(int j=0; j<3; j++){

            cout << "\nGANADOR " << j+1 << "° lugar: "
                 << Categ.GANADORES[j] << endl;
        }


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
