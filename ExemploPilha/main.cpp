#include <iostream>
#include "Pilha.h"

using namespace std;

main (int agrc, char *argv[])
{
    Pilha p;

    p.push_back(10);
    cout << "Pilha  vaza:" << p.vazia() << endl;
    cout<< "Topo da pilha" << p.getTopo() << endl;;
    return 0;
}