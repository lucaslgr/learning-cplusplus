/*
    ESTUDO DA CLASSE DEQUE EM C++
    - Descrição:
        -> O deque segue os conceitos de uma fila FIFO, porém, com a peculiaridade de que pode
        se inserir elementos no início, no final, remover elementos no início e no final também.

    - Reference;
        -> http://www.cplusplus.com/reference/deque/deque/
*/

#include <iostream> // o termo io representa, i-> in, o-> out.
#include <deque>

using namespace std;

int main()
{
    deque<int> fila;

    cout << "Antes de inserir os elementos: ";

    if (fila.empty())
        cout << "Fila vazia!\n";
    else
        cout << "Fila NAO vazia!\n";

    // inserir elementos ao final da fila
    fila.push_back(10);
    fila.push_back(20);

    // inserir elemento no início da fila
    fila.push_front(30);
    //fila: 30 10 20

    cout << "\nDepois de inserir os elementos: ";

    if (fila.empty())
        cout << "Fila vazia!\n";
    else
        cout << "Fila NAO vazia!\n";
    


    //Mostrando os elementos dessa fila
    deque<int>::iterator it = fila.begin(); // Declarando um iterator que aponta para o início do nosso deque
    while(it != fila.end())
        cout << *it++ << " "; // Incrementando o iterador para apontar para o próximo elemento da fila
    //FIM

    //Limpando toda a fila
    fila.clear();
    //Fim da limpeza

    if (fila.empty())
        cout << "\nFila vazia!\n";
    else
        cout << "\nFila NAO vazia!\n";

    // Inserir elementos
    fila.push_back(10);
    fila.push_front(20);
    fila.push_back(30);
    // fila: 20 10 30  

    //Removendo o segundo elemento
    fila.erase(fila.begin() + 1);

    //Mostrando os elementos dessa fila
    it = fila.begin(); // Atribuindo ao iterator o endereço que aponta para o início do nosso deque
    while (it != fila.end())
        cout << *it++ << " "; // Incrementando o iterador para apontar para o próximo elemento da fila
    //FIM

    //Retornando o elemento da frente
    cout << "\n\nElemento da frente: " << fila.front() ;
    cout << "\n\nUltimo elemento: " << fila.back();
    cout << endl;

    //Usando o insert para inserir um elemento em uma determinada posicao
    fila.insert((fila.begin() + 1), 10); //Inserindo o valor 10 na segunda posicao

    //Mostrando os elementos dessa fila
    it = fila.begin(); // Atribuindo ao iterator o endereço que aponta para o início do nosso deque
    while (it != fila.end())
        cout << *it++ << " "; // Incrementando o iterador para apontar para o próximo elemento da fila
    //FIM

    //Removendo um elemento do início
    fila.pop_front();
    //Removendo um elemento do final
    fila.pop_back();

    //Tamanho da fila
    cout << "\nTamanho da fila: " << fila.size() << endl; 

    return 0;
}