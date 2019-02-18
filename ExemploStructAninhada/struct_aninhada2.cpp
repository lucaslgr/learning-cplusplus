//Exemplificando a possibilidade de se criar uma struct dentro da outra literalmente
#include <iostream>
#include <string.h>

using namespace std;

typedef struct Pessoa
{
    struct Carro
    {
        double preco;
    };

    struct Casa
    {
        double preco;
    };

    struct Carro carro;
    struct Casa casa;

} t_pessoa;

int main(int agrc, const char *agrv[])
{
    t_pessoa p1;

    p1.carro.preco = 2000;
    p1.casa.preco = 300;

    cout << "Preco do carro: " << p1.carro.preco << endl;
    cout << "Preco da casa: " << p1.casa.preco << endl;

    return 0;
}