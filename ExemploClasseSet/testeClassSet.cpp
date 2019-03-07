/*
    CLASSE SET
    - Descrição:
    -> É uma classe que define outro tipo de conteiner, que provê funções que implementa a estrutura
    conjunto que é uma estrutura onde não temos elementos repetidos.
    -> É uma classe que vem da STL do C++.

    Ref: http://www.cplusplus.com/reference/set/set/
*/

#include <iostream>
#include <set>

using namespace std;

int main(int agrc, const char *agrv[])
{
    int vet[] = {10,  20, 10, 30 , 40, 50}; //Declarando e atribuindo um vetor de inteiros
    
    set<int> myset(vet, vet + 6); //Declarando um set e atribuindo o vetor de inteiros a ele

    set<int>::iterator it = myset.begin(); //Declarando um iterator para um set e atribuindo o endereço da primeira posição do meu set para o iterator

    //Mostrando os elementos
    while(it != myset.end())
    {
        cout << *it << " ";
        it++; //Incrementando para onde o iterator aponta
    }
    cout << endl;
    /*
        - Note que:
        -> O set não armazenou nenhum valor repetido
        -> Ele ordenou automaticamente todos os valores
    */

    // Apgando apenas um elemento
    it = myset.begin(); //Pegando um iterator que aponta para o início do meu conjunto
    myset.erase(it);

    //Mostrando os elementos
    it = myset.begin();
    while (it != myset.end())
    {
        cout << *it << " ";
        it++; //Incrementando para onde o iterator aponta
    }
    cout << endl;

    //Limpando todos elementos
    // myset.clear();

    //Testando se o conjunto está vazio
    if (myset.empty())
        cout << "\nConjunto vazio!\n";
    else
        cout << "\nConjunto NAO vazio!!\n";


    //Encontrando o elemento do conjunto que o valor é igual a 50
    it = myset.find(50);
    if (it == myset.end()) //Percorre até o final e não encontra nada
        cout << "\n\nO elemento 50 NAO existe\n";
    else
        cout << "\n\nO elemento 50 existe\n";
    

    //Mostrando o tamanho do meu conjunto set
    cout << "Tamanho do meu conjunto myset: " << myset.size() << endl;

    return 0;
}