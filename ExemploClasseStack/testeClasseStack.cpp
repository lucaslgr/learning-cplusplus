/*
    CLASSE STACK
    - Descrição:
    -> A classe STACK implementa uma pilha, é uma classe da STL, que permite utilizar as funcoes prontas
    para uma estrutura de dados de pilha do tipo LIFO, Last In, First Out.

    Ref: http://www.cplusplus.com/reference/stack/stack/
*/

#include <iostream>
#include <stack>

using namespace std;

int main(int agrc, char *agrv[])
{
    stack<int> pilha; //Declarando um Stack do tipo int

    pilha.push(10);
    pilha.push(20);
    pilha.push(30);
    pilha.push(40);
    pilha.push(50);

    //Pilha: 10, 20, 30, 40

    while(!pilha.empty()) //Enquanto a pilha nao estiver vazia
    {
        int e = pilha.top(); //Pegando o elemento do topo
        cout << e << " "; //Printando o elemento do topo
        pilha.pop(); //Removendo um elemento do topo
    }
    //Imprime: 50 40 30 20 10

    //Tamanho da pilha
    cout << "\nTamanho da minha pilha da classe STACK: " << pilha.size() << endl;

    return 0;
}