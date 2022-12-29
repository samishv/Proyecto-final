#include "EliminacionDirecta.h"
#include <iostream>

using namespace std;

EliminacionDirecta::EliminacionDirecta(int totalPrototipos)
{
    this->totalPrototipos=totalPrototipos;
    //ctor
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
    cout << "TOTAL : " << totalPrototipos << endl;
    cout << "byes : " << byes << endl;
    return byes;
}
