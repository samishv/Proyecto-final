#include "Torneo.h"
#include "Categoria.h"
#include <string>
#include <iostream>

using namespace std;

Torneo::Torneo()
{
    //ctor
}

Torneo::~Torneo()
{
    //dtor
}

void Torneo::setTorneo(){
    bool correcto{false};
    //Se elige la categoría a registrar


    /*CATEGORIAS = new Categoria[2]

    (CATEGORIAS + i)->setHuesped();*/

    do{
        cout << "\nElige la categoria a registrar:\n"
             << "1.-Minisumo RC\n"
             << "2.-Minisumo autonomo" << endl;
        cin >> numCategoria;

        switch(numCategoria){
        case 1:
            cout << "\nCategoria disponible para:\n"
                 << "\n4 o mas prototipos en eliminacion directa\n"
                 << "\n6 o mas prototipos en Round Robin\n" << endl;
            MiniRC.setCategoria();
            if(!(MiniRC.getTotalPrototipos()>3)){
                cout << "\nMinimo de prototipos totales 4 no alcanzado" << endl;
                system("pause");
                system("cls");
                MiniRC.setTotalPrototipos(0);
                break;
            }
            correcto = true;
            setEncuentros(MiniRC);
            break;
        case 2:
            cout << "\nCategoria disponible para:\n"
                 << "\n4 o mas prototipos en eliminacion directa\n"
                 << "\n6 o mas prototipos en Round Robin\n" << endl;
            MiniAutonomo.setCategoria();
            if(!(MiniAutonomo.getTotalPrototipos()>3)){
                cout << "\nMinimo de prototipos totales 4 no alcanzado" << endl;
                system("pause");
                system("cls");
                MiniAutonomo.setTotalPrototipos(0);
                break;
            }
            correcto = true;
            setEncuentros(MiniAutonomo);
            break;
        default:
            cout << "Opcion invalida, prueba otra vez: " << endl;
        }
    }while(!correcto);
}

void Torneo::mostrarCategoria(int numCategoria)
{
        switch(numCategoria){
        case 1:
            MiniRC.mostrarCategoria();
            cout << endl;
            break;
        case 2:
            MiniAutonomo.mostrarCategoria();
            cout << endl;
            break;
        default:
            cout << "Opcion invalida, prueba otra vez: " << endl;
        }

}

void Torneo::setEncuentros(Categoria& categoriaActiva)
{
    bool correcto{false};

    do{
        system("cls");
        cout << "\nElige el sistema de organizacion de encuentros que deseas implementar: \n"
             << "1.-Eliminacion directa\n"
             << "2.-Por grupos (Round Robin)\n" ;
        cin >> opcionEncuentro;
        cout << endl << endl;

        switch(opcionEncuentro){
        case 1:
            categoriaActiva.setByes();
            categoriaActiva.elimDirecta(categoriaActiva);
            correcto = true;
            break;
        case 2:
            categoriaActiva.elimRobin(categoriaActiva);
            correcto=true;
            break;
        default:
            cout << "Opcion invalida, prueba otra vez: " << endl;
        }

    }while(!correcto);

}


