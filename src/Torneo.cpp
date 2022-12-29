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
    //Se elige la categoría a registrar


    /*CATEGORIAS = new Categoria[2]

    (CATEGORIAS + i)->setHuesped();*/

    cout << "\nElige la categoria a registrar:\n"
             << "1.-Minisumo RC\n"
             << "2.-Minisumo autonomo" << endl;
        cin >> numCategoria;

        switch(numCategoria){
        case 1:
            MiniRC.setCategoria();
            break;
        case 2:
            MiniAutonomo.setCategoria();
            break;
        default:
            cout << "Opcion invalida, prueba otra vez: " << endl;
        }
}

void Torneo::mostrarCategoria(int numCategoria){


        switch(numCategoria){
        case 1:
            cout << MiniRC.getCategoria() << endl;
            break;
        case 2:
            cout << MiniAutonomo.getCategoria() << endl;
            break;
        default:
            cout << "Opcion invalida, prueba otra vez: " << endl;
        }

}
void Torneo::setEncuentros()
{
    bool correcto{false};

    do{
            //system("cls");
            cout << "\nElige el sistema de organizacion de encuentros que deseas implementar: \n"
                 << "1.-Eliminacion directa\n"
                 << "2.-Por grupos (Round Robin)\n" ;
                cin >> opcionEncuentro;
                cout << endl << endl;

                switch(opcionEncuentro){
                    case 1:
                        {
                        EliminacionDirecta eleccion(MiniRC.getTotalPrototipos());
                        eleccion.prueba2n();
                        correcto = true;
                        break;
                        }
                    case 2:
                        cout << "caso 2" << endl;
                        correcto=true;
                        break;
                    default:
                        cout << "Opcion invalida, prueba otra vez: " << endl;
                }

    }while(!correcto);

}


