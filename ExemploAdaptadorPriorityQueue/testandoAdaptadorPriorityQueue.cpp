/*
    PROPRIEDADE -> priority queue da class queue
    - Descrição:
        -> Nada mais é do que uma fila de prioridades

    Ref: http://www.cplusplus.com/reference/queue/priority_queue/
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    //priority_queue<int> p_q; //Declarando uma priority queue
    priority_queue< int, vector<int>, greater<int> > p_q; //Declarando uma fila de prioridade inversa

    //Inserindo elementos
    p_q.push(20);
    p_q.push(15);
    p_q.push(50);

    //Imprimindo os elementos do topo de acordo com a prioridade
    cout <<"Elemento do topo:  "<< p_q.top() << endl;

    //Testando se a fila está vazia
    if(p_q.empty())
        cout << "Fila vazia!\n";
    else
        cout << "Fila NAO vazia!\n";

    cout << "\nTamanho da fila: " << p_q.size() << endl;
    while(!p_q.empty())
    {
        cout << p_q.top() << " "; //Printando o elemento do topo
        p_q.pop(); //Removendo os elementos
    }
    
    return 0;
}