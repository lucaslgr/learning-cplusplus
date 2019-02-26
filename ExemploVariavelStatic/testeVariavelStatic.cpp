/*
    VARIAVEL STATIC:
    - Características:
        -> O tempo de vida das variáveis estáticas é o tempo de vida do programa.
        -> Uma variável estática rêtem informação entre chamadas a uma função. 

    OBS: Note que no exemplo abaixo a variável ID NÃO é ZERADA quando é chamada novamente no loop
    do while, e continua com o seu valor anterior e incrementando +1 a cada chamada.
*/

#include <iostream>

using namespace std;

int gerarID()
{
    static int ID = 0;
    return ID++;
}

int main(int agrc, const char *agrv[])
{
    string nome;

    while(true || 1)
    {
        cout << "Digite o nome da pessoa: ";
        cin >> nome;
        cout << "ID gerado para o usuario " << nome << ": " << gerarID() << endl << endl; 
    }
    

    return 0;
}