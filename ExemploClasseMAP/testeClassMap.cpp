/*
    ESTUDO DA CLASSE MAP
    - Características:
     -> É uma classe que armazena os elementos de forma que eles possuam uma combinação de chave e valor
     -> As chaves são únicos para identificar os elementos.
     -> Enquanto os valores armazenam o conteúdo associado a uma determinada chave

    - Sintaxe:
    map<tipo do valor , tipo da chave> = mapa{
        {valor, chave},
        {valor, chave}
    };
*/

#include <iostream>
#include <map>

using namespace std;

int main(int agrc, const char *agrv[])
{
    //PRMEIRA MANEIRA DE UTILIZAR
    pair<int, string> pares[] = //Inicializando um vetor de pares
    {
        make_pair(1, "Lucas"),
        make_pair(2, "Maria"),
        make_pair(3, "Joaozin")
    };

    map<int, string> mapa1(pares, pares + 3);

    // CONSULTANDO OS DADOS
    // SINTAXE: mapa[chave] -> retorna o valor correspondente aquela chave
    cout << mapa1[1] << endl;
    cout << mapa1[2] << endl;
    cout << mapa1[3] << endl;
    //FIM DA PRMEIRA MANEIRA DE UTILIZAR


    cout << "\n\n\n";


    //SEGUNDA MANEIRA DE UTILIZAR
    map<int, string> mapa2; //Declaracao
    
    //Inserindo elementos
    mapa2[1] = "Lucas";
    mapa2[2] = "Joao";
    mapa2[3] = "Maria";

    //Acessando e printando as informações
    cout << mapa2[1] << endl;
    cout << mapa2[2] << endl;
    cout << mapa2[3] << endl;
    //FIM DA MANEIRA DE UTILIZAR

    //Utilizando a função at, que retorna uma referência de um 
    //determinado valor, passando como argumento a sua respectiva chave
    mapa2.at(2) = "Noeh";
    cout << "\nPrintando o valor alterado com a funcao at:\n"<<mapa2[2] << endl;
    
    //Limpando o map
    mapa2.clear();

    //Testando se o mapa esta vazio
    if(mapa2.empty())
        cout << "Mapa2 vazio!\n" << endl;
    else
        cout << "Mapa2 NAO vazio!\n" << endl;

    
    //Utilizando a funcao map.cout para identificar se um determinado valor pertence ao map
    //a partir do argumento que é uma key
    if (mapa1.count(1) == true)
        cout << "1 eh elemento do mapa \n";
    else
        cout << "1 NAO eh elemento do mapa\n";


    //Percorrendo um map usando o iterator
    map<int, string>::iterator it;
    for(it = mapa1.begin(); it != mapa1.end(); it++)
        cout << "A chave "<< it->first << " => " << it->second << endl;

    
    //Funcao find, que retorna um iterator para um elemento de acordo com a chave passada como argumento

    it = mapa1.find(2); //Pegando o iterator que aponta para o elemento de chave = 2
    mapa1.erase(it); //Apagando o elemento referente a chave especficada

    cout << "\n\n\n\n" ;

    //Mostrando todos elementos
    for (it = mapa1.begin(); it != mapa1.end(); it++)
        cout << "A chave " << it->first << " => " << it->second << endl;

    return 0;
}