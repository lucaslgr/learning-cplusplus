#include <iostream>
#include <vector>

using namespace std;

int main(int agrc, const char *agrv[])
{
    vector<int> v;
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    //Teste loop
    while(v.empty())
        v.pop_back();  //retirando elemento do vector

    if (v.empty()) {
        cout << "Vector vazio!\n";
    }
    else
    {
        cout << "Vector NAO vazio!\n";
    }
    //FIM


    //Imprimento o ultimo valor do vector
    cout << v.back() << endl;
    cout << v.front() << endl;
    //FIM


    //Acessando e imprimindo o valor de DETERMINADA posição
    cout << "\n\n Usando v.at(position): \n";
    cout << v.at(0) << endl;
    cout << v.at(2) << endl;
    //FIM


    //Inserindo elementos EM QUALQUER POSIÇÃO COM .insert(posicao, valor);
    cout << "\n\nEstudando a funcao .insert(): \n";
    vector<int>::iterator it = v.begin(); //Atribuindo a primeiro posição ao iterator
    
    v.insert(it, 30); //Inserindo valor 30 na posição do iterator-> it
    v.insert( (it + 2), 30);
    for(it = v.begin(); it!=v.end() ; it++)
    {
        cout << "Valor:" << *it << endl;
    }
    //FIM

    
    //Usando erase para apagar posicoes ESPECIFICAS em um vector
    cout << "\n\nEstudando a funcao .erase(posicao): \n";
    v.erase(v.begin() + 3); //Apagando o 4º elemento do meu vector
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << "Valor:" << *it << endl;
    }
    //FIM


    //Usando a funcao .swap(vector) para trocar os valores de um vector com outro
    cout << "\n\nEstudando a funcao .swap(posicao): \n";
    vector<int> vecA(3, 20);
    vector<int> vecB(4,10);
    
    vecA.swap(vecB);

    for (int ss = 0; ss < vecA.size(); ss++)
        cout << "Valor vecA:" << vecA[ss] << endl;

    cout << "\n\n";

    for (int ss = 0; ss < vecB.size(); ss++)
        cout << "Valor vecB:" << vecB[ss] << endl;
    //FIM
    return 0;
}