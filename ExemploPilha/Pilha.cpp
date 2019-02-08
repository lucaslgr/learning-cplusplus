#include <iostream>
#include "Pilha.h"

using namespace std;

Pilha::Pilha()
{
    vet = new int[100];
    max_tamPilha = 99;
    topo_Pilha = -1;
}
Pilha::~Pilha()
{
    delete[] vet;
}

void Pilha::push_back(int e) //Empilhar
{
    if (topo_Pilha == max_tamPilha)
        cout << "Pilha cheia!" << endl << endl;
    else
        vet[++topo_Pilha] = e;
}
void Pilha::pop_back() //Desempilhar
{
    if (topo_Pilha == -1)
        cout << "Pilha vazia!" << endl;
    else
        topo_Pilha --;
}
int Pilha::getTopo()
{
    if (topo_Pilha != -1)
        return vet[topo_Pilha];
    else
        return -1;
}
int Pilha::vazia()
{
    return (topo_Pilha == -1);
}