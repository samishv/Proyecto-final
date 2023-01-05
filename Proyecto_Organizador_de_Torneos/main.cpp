#include <iostream>
#include "Torneo.h"

using namespace std;

int main()
{
    int opcion{};
    char verCategoria{};
    char accion{'n'};


    cout << "Bienvenido, creemos un nuevo torneo\n" << endl;

    do{
        //Llenamos el objeto
        Torneo Robotica{};
        Robotica.setTorneo();
        //Robotica.setEncuentros();
        bool activo{true};

        do{
            //Pausa para poder visualizar las selecciones
            system("pause");
            system("cls");
            cout << "\n\nVisualizar los datos de alguna categoria? (S/N): ";
            cin >> verCategoria;
            verCategoria = tolower(verCategoria);

            if(verCategoria == 's'){
                do{
                    cout << "\nElige la categoria a mostrar:\n"
                            << "1.-Minisumo RC\n"
                            << "2.-Minisumo autonomo\n" ;
                    cin >> opcion;
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore();
                        opcion = 0;
                    }
                }while(opcion<1);

                cout << endl << endl;

                Robotica.mostrarCategoria(opcion);
            }else{
                activo = false;
            }
        }while(activo);

        cout << "\nSalir (S)"
             << "\nIngresar nuevo grupo (N)" << endl;
        cin >> accion;
        accion = tolower(accion);
        if(accion == 'n'){
            system("cls");
        }
    }while(accion == 'n');
    return 0;
}
