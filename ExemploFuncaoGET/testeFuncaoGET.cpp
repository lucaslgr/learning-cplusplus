/*
    FUNÇÂO GET:
    - Descrição:
        -> É uma função do objeto de entrada "cin" da biblioteca iostream
        -> seus parâmetros são: cin.get( string VARIAVEL, int TAMANHO);

    - Características:
        -> A função get recebe uma string do C;
*/

#include <iostream>
#include <string>

#define MAX 100

using namespace std;

int main(int agrc, const char *agrv[])
{
    char nome[MAX];

    cout << "Digite o seu nome: ";
    //cin >> nome; //Note que: dessa forma ele pega apenas a primeira palavra até encontrar um \n (espaço)

    cin.get(nome, MAX);

    cout << "Oi " << nome << endl;

    return 0;
}