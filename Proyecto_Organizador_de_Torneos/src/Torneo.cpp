#include "Torneo.h"
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

    do{
        do{
            cout << "\nElige la categoria a registrar:\n"
                    << "1.-Minisumo RC\n"
                    << "2.-Minisumo autonomo" << endl;
            cin >> numCategoria;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                numCategoria = 0;
            }
        }while(numCategoria<1);

        switch(numCategoria){
        case 1:
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

        do{
            cout << "\nElige el sistema de organizacion de encuentros que deseas implementar: \n"
                    << "1.-Eliminacion directa\n";
            cin >> opcionEncuentro;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                opcionEncuentro = 0;
            }
        }while(opcionEncuentro<1);

        cout << endl << endl;

                switch(opcionEncuentro){
                    case 1:
                        categoriaActiva.setByes();
                        categoriaActiva.elimDirecta(categoriaActiva);
                        correcto = true;
                        break;
                    default:
                        cout << "Opcion invalida, prueba otra vez: " << endl;
                }

    }while(!correcto);

}


