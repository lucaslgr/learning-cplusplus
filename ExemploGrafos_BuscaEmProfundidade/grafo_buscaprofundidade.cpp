/*
    ---------------------------------GRAFO - DFS (BUSCA EM PROFUNDIDADE)------------------------------------
    -MATERIAL UTILIZADO para entender a teoria:
     ->> https://www.slideshare.net/mcastrosouza/grafos-representao

    NÓS: são entidades
    ARESTAS: são relações entre eles
*/
#include <iostream>
#include <list>
#include <algorithm> //função find
#include <stack> // pilha para usar na DFS 

using namespace std;

class Grafo
{
    private:
        int V; //número de vértices
        list<int> *adj; //ponteiro para um array contendo as listas de adjacências
    public:
        Grafo(int V); //construtor

        void adicionarAresta(int v1, int v2); //Adiciona uma aresta no grafo
        
        // obtém o grau de saída de um dado vértice
        // grau de saída é o número de arcos que saem de "v"
        int obterGrauDeSaida(int v);

        bool existeVizinho(int v1, int v2); //verfica se v2 é vizinho de v1

        void dfs(int v);
};


Grafo::Grafo(int V)
{
    this->V = V; //Atribui o número de vértices
    this->adj = new list<int>[V]; //cria as listas
}

void Grafo::adicionarAresta(int v1, int v2)
{
    //adiciona vértice v2 à lista de vértices adjacentes de v1
    adj[v1].push_back(v2);
}

int Grafo::obterGrauDeSaida(int v)
{
    //basta retornar o tamanho da lista que é a quantidade de vizinhos
    return adj[v].size();
}

bool Grafo::existeVizinho(int v1, int v2)
{
    if ( find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end())
    {
        return true;
    }
    return false;
}

void Grafo::dfs(int v)
{
    stack<int> pilha;
    bool visitados[this->V]; //vetor de visitados

    //marcar todos como não visitados
    for (int i = 0; i < this->V; i++)
        visitados[i] = false;
    
    while (true)
    {
        if (!visitados[v])
        {
            cout << "Visitando vertice " << v << "....\n";
            visitados[v] = true; //marca como visitado
            pilha.push(v); //insere "v" na pilha
        }
        
        bool achou = false;
        list<int>::iterator it;

        for (it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if (!visitados[*it])
            {
                achou = true;
                break;
            }
        }

        if(achou)
        {
            v = *it; //Atualiza o "v"
        }
        else
        {
            //se todos os vizinhos estão visitados ou não existem vizinhos
            //remove da pilha
            pilha.pop();
            //se a pilha ficar vazia, então terminou a busca
            if (pilha.empty())
                break;
            //se chegou aqui, é porque pode pegar o elemento do topo
            v = pilha.top();
        }
    }
    
}

int main()
{
    int V = 8;

    Grafo grafo(V);

    //adicionando as arestas
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 2);
    grafo.adicionarAresta(1, 3);
    grafo.adicionarAresta(1, 4);
    grafo.adicionarAresta(2, 5);
    grafo.adicionarAresta(2, 6);
    grafo.adicionarAresta(6, 7);

    grafo.dfs(0);

    return 0;
}