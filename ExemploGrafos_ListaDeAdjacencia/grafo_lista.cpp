/*
    ---------------------------------GRAFO - LISTA DE ADJACÊNCIA------------------------------------
    -MATERIAL UTILIZADO para entender a teoria:
     ->> https://www.slideshare.net/mcastrosouza/grafos-representao

    NÓS: são entidades
    ARESTAS: são relações entre eles
*/
#include <iostream>
#include <list>
#include <algorithm> //função find

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

int main()
{
    //Criando um grafo de 4 vertices
    Grafo grafo(4);

    //adicionado as arestas
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 3);
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(3, 1);
    grafo.adicionarAresta(3, 2);

    //mostrando os graus de saída
    cout << "Grau de saida do vertice 1: " << grafo.obterGrauDeSaida(1);
    cout << "\nGrau de saida do vertice 3: " << grafo.obterGrauDeSaida(3);

    //verifica se existe vizinhos
    if (grafo.existeVizinho(0, 1))
        cout << "\n\n1 eh vizinho de 0\n";
    else
        cout << "\n\n1 NAO eh vizinho de 0\n";

    return 0;
}