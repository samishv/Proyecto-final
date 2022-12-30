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
    int elegido;
    int IDElegido;
    //int j{0};
    //int k;
    //int pos{0};
    string nombreElegido;
    //bool unique {false};

    while (pow(2,n)<=totalPrototipos){
        byes=pow(2,n+1)-totalPrototipos;

        if(pow(2,n)==totalPrototipos){
            byes = 0;
            break;
        }
        n++;
    }

         cout << "\nnumero de byes: " << byes << endl;
         //k=byes;

    // asigna quienes seran los byes

    while(byes!=0){
        //BYES = new Prototipo[byes];
         cout << "\nnumero de equipos: " << numEquipos << endl;
        for(int i=0;i<numEquipos;i++){


                numPrototipos=(EQUIPOS + i)->getnumPrototipos();
                cout << "Prototipos del equipo '" << i+1 <<"' " << numPrototipos<<endl;


                unsigned int semilla = chrono::steady_clock::now().time_since_epoch().count();
                default_random_engine motorG(semilla);
                uniform_int_distribution<int> pasan(0,numPrototipos-1);
                byes--;
                elegido=pasan(motorG);
                IDElegido=(EQUIPOS + i)->getEquipo(elegido);
                cout << "Del equipo " << i+1 << " pasa el prototipo " << elegido+1 <<" : " << IDElegido  <<"\nnumero de byes: " << byes << endl;

                if(byes==0){
                    break;
                }

        }

    }

    /*for(int j=0; j<pos; j++){
            cout << BYES[j] << endl;
        }
    int n{2};
    int byes{87};
    int elegido;
    //int k;
    //int pos{0};
    string nombreElegido;

    // Determina el numero de byes

    while (pow(2,n)<=totalPrototipos){
        byes=pow(2,n+1)-totalPrototipos;

        if(pow(2,n)==totalPrototipos){
            byes = 0;
            break;
        }
        n++;
    }
        //k=byes;
         cout << "\nNumero de byes: " << byes << endl;


    // asigna quienes seran los byes
    while(byes!=0){
        string BYES[byes];
        bool unique {false};

        string nombreGuardado;
        cout << "\nNumero de equipos: " << numEquipos << endl;


        for(int i=0;i<numEquipos;i++){
                cout << "i" << i << "\nunique " << unique << endl;

                numPrototipos=(EQUIPOS + i)->getnumPrototipos();
                //cout << "Prototipos del equipo '" << i+1 <<"' " << numPrototipos<<endl;

                unsigned int semilla = chrono::steady_clock::now().time_since_epoch().count();
                default_random_engine motorG(semilla);
                uniform_int_distribution<int> pasan(0,numPrototipos);
                byes--;
                elegido=pasan(motorG);
                nombreElegido=(EQUIPOS + i)->getEquipo(elegido);

                cout<< "Nombre elegido: " << nombreElegido<< endl;

                //unique = true;
                //cout<<k<<endl;
                //if(k!=0){
                for (int j=0; j<k ; j++){
                        nombreGuardado=BYES[j];
                    cout<< "Nombre guardado "<<j<<" : " << nombreGuardado<< endl;
                    if(nombreGuardado.compare(nombreElegido)==0){
                        unique=false;
                        cout << "se repite" << endl;
                    }
                }
                //}


                //BYES[pos]=nombreElegido;

                //pos++;
                //unique = false;
                cout << "Del equipo " << i+1 << " pasa el prototipo " << elegido+1 <<" : " << nombreElegido  <<"\ni " << i << endl;

                if(byes==0)break;


        }
    }*/

}

