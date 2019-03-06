/*
    ESTUDO DA CLASSE QUEUE
    - Características: 
        -> É uma classe que implenta filas do tipo FIFO, First In, First Out
        -> Sempre se insere no final e se retira do início


    OBS: NÃO CONFUNDA COM A CLASS -> DEQUE, na class Deque, você pode remover e inserir tanto no início
    quanto no início da fila

    Ref: http://www.cplusplus.com/reference/queue/queue/
*/

#include <iostream>
#include <queue>

using namespace std;

int main(int agrc, char *agrv[])
{
    queue<int> fila;

    //Inserindo na fila
    fila.push(10);
    fila.push(20);
    fila.push(30);
    fila.push(40);
    // fila: 10 20 30 40

    //Mostrando o último elemento
    cout << "\nUltimo elemento: " << fila.back() << endl;

    if (fila.empty())
        cout << "\nFila vazia!!\n";
    else
        cout << "\nFila NAO vazia!!\n";

    //Imprimindo o primeiro elemento
    cout << "\nPrimeiro elemento: " << fila.front() << endl;

    while(!fila.empty())
    {
        int e = fila.front(); //pega o primeiro elemento
        cout << e << " ";
        fila.pop(); //remove elemento do início
    }

    //Inserindo na fila NOVAMENTE
    fila.push(10);
    fila.push(20);
    fila.push(30);
    fila.push(40);
    // fila: 10 20 30 40

    cout << "Tamanho da fila: " << fila.size() << endl;
    cout << endl;

    return 0;
}