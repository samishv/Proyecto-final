#include "Categoria.h"
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


string Categoria::getInfoPrototipo(int posicion,int posicionPrototipo)
{
    ostringstream salida;
        cout << (EQUIPOS + posicion)->getEquipo(posicionPrototipo);


    return salida.str();
}



void Categoria::eliminacionDirecta()
{
    int ganadorEnfrentamiento, participante;
    int elegido,IDElegido,*PARTICIPANTES, bandera,numEnfrentamiento;
    int pos{0};
    string nombreCompetidorRojo,nombreCompetidorAzul;
    bool unique {false};
    bool nuevoEnfrentamiento {true};



    // Asigna los enfrentamientos

    pos=0;
    numRondas=totalPrototipos-1;
    numParticipantes=totalPrototipos-byes;
    PARTICIPANTES= new int[numParticipantes];

    numEnfrentamientos=numParticipantes/2;

    ENFRENTAMIENTOS = new Enfrentamientos[numEnfrentamientos];
    numEnfrentamiento=0;


    while(numParticipantes!=0){

        for(int i=0;i<numEquipos;i++){

                numPrototipos=(EQUIPOS + i)->getnumPrototipos();
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

                }while(!unique && bandera<=numPrototipos);

                if(bandera>numPrototipos){
                    continue;
                }

                nombreElegido=(EQUIPOS + i)->getInfoPrototipo(elegido);
                pos ++;

                if(nuevoEnfrentamiento){
                    (ENFRENTAMIENTOS+numEnfrentamiento)->setCompetidorRojo(nombreElegido,IDElegido);
                    nuevoEnfrentamiento=false;
                }else{
                     (ENFRENTAMIENTOS+numEnfrentamiento)->setCompetidorAzul(nombreElegido,IDElegido);
                      nuevoEnfrentamiento=true;
                      numEnfrentamiento++;
                     }

                numParticipantes--;

                if(numParticipantes==0){
                    break;
                }

        }

}

              for(int i=0; i<numEnfrentamientos; i++){

                    cout << "\nENFRENTAMIENTO " << i+1 << ": "
                        << (ENFRENTAMIENTOS+i)->getNombreCompetidorRojo() << " vs " << (ENFRENTAMIENTOS+i)->getNombreCompetidorAzul() << endl;

              }


             for(int i =2; i<numRondas; i++){

                    numParticipantes=byes+numEnfrentamientos;

                    for(int j=byes; j<numParticipantes; j++){

                            nombreCompetidorRojo=(ENFRENTAMIENTOS+j-byes)->getNombreCompetidorRojo();
                            nombreCompetidorAzul=(ENFRENTAMIENTOS+j-byes)->getNombreCompetidorAzul();


                            cout << "\nSeleccione el ganador del enfrentamiento " << j-byes+1 << ": "
                                 << "\n1. " << nombreCompetidorRojo
                                 << "\n2. " << nombreCompetidorAzul << endl;

                            cin>>ganadorEnfrentamiento;
                            cout << endl << endl;

                            switch(ganadorEnfrentamiento){
                                case 1:
                                    cout << "Ganador: " << nombreCompetidorRojo << endl;
                                    NOMBREPARTICIPANTES[j]=nombreCompetidorRojo;
                                    break;

                                case 2:
                                    cout << "Ganador: " << nombreCompetidorAzul << endl;
                                    NOMBREPARTICIPANTES[j]=nombreCompetidorAzul;
                                    break;
                                default:
                                    cout << "Opcion invalida, prueba otra vez: " << endl;
                    }
            }

            byes=0;

            delete[] ENFRENTAMIENTOS;
            numEnfrentamientos=numParticipantes/2;
            ENFRENTAMIENTOS=new Enfrentamientos[numEnfrentamientos];
            participante=0;
            for(int j=0; j<numEnfrentamientos; j++){

                (ENFRENTAMIENTOS+j)->setCompetidorRojo(NOMBREPARTICIPANTES[participante]);
                participante ++;
                (ENFRENTAMIENTOS+j)->setCompetidorAzul(NOMBREPARTICIPANTES[participante]);
                participante ++;
            }

            for(int j=0; j<numEnfrentamientos; j++){

                    cout << "\nENFRENTAMIENTO " << j+1 << ": "
                        << (ENFRENTAMIENTOS+j)->getNombreCompetidorRojo() << " vs " << (ENFRENTAMIENTOS+j)->getNombreCompetidorAzul() << endl;

              }

    }

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





