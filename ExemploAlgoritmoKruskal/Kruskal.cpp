/*
                                        ALGORITMO DE KRUSKAL
    -> O objetivo deste algoritmo é formar uma arvore geradora mínima, ou seja, uma árvore que inclui todos os os vértices
    onde o peso total é mínimo.
    -> É um algoritmo guloso, que é um algoritmo que não se arrepende das suas decisões.
    -> Como forma uma árvore, não pode haver cíclos.


    Implementação do algoritmo de Kruskal:
    -> Para detectar ciclos iremos utilizar o algoitmo Unio-Find que detecta ciclos em grafos NÃO direcionados.

*/

#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <string.h> //memset

using namespace std;

class Aresta
{
    int vertice1, vertice2, peso;

    public:
        Aresta(int v1, int v2, int peso)
        {
            vertice1 = v1;
            vertice2 = v2;
            this->peso = peso;
        }

        int obterVertice1()
        {
            return this->vertice1;
        }

        int obterVertice2()
        {
            return this->vertice2;
        }

        int obterPeso()
        {
            return this->peso;
        }

        //Sobreescrita do operador "<"
        bool operator<(const Aresta &aresta2) const
        {
            return (peso < aresta2.peso);
        }
};

class Grafo
{
    int V; //número de vértices
    vector<Aresta> arestas; //vetor de arestas

    public:
        Grafo(int v)
        {
            this->V = v;
        }

        //função que adiciona uma aresta
        void adicionaAresta(int v1, int v2, int peso)
        {
            Aresta aresta(v1, v2, peso);
            arestas.push_back(aresta);
        }

        //função que busca o subconjunto de um elemento "i"
        int buscar(int subset[], int i)
        {
            if(subset[i] == -1)
                return i;
            return buscar(subset, subset[i]);
        }

        //função para unir dois subconjuntos em um único subconjunto
        void unir(int subset[], int v1, int v2)
        {
            int v1_set = buscar(subset, v1);
            int v2_set = buscar(subset, v2);
            subset[v1_set] = v2_set;
        }

        //função que roda o algoritmo de Kruskal
        void kruskal()
        {
            vector<Aresta> arvore;
            int size_arestas = arestas.size();

            //ordena as arestas pelo menor peso
            sort(arestas.begin(), arestas.end());

            //aloca memória para criar "V" subconjuntos
            int *subset = new int[V];

            //inicializa todos os subconjuntos como conjuntos de um único elemento
            memset(subset, -1, sizeof(int) *V);

            for (int i = 0; i < size_arestas; i++)
            {
                int v1 = buscar(subset, arestas[i].obterVertice1());
                int v2 = buscar(subset, arestas[i].obterVertice2());

                if (v1 != v2)
                {
                    //se forem diferentes é porque NÃO forma ciclo, insere o vetor
                    arvore.push_back(arestas[i]);
                    unir(subset, v1, v2); //faz a união
                }
            }

            int size_arvore = arvore.size();

            //mostrar as arestas selecionadas com seus respectivos pesos
            for (int i = 0; i < size_arvore; i++)
            {
                char v1 = 'A' + arvore[i].obterVertice1(); //TABELA ASCII
                char v2 = 'A' + arvore[i].obterVertice2();
                cout << "(" << v1 << ", " << v2 << ") = " << arvore[i].obterPeso() << endl;
            }
            
        }
};

int main(int agrc, char *argv[])
{
    Grafo g(7); //grafo
    
    //Adiciona as arestas
    g.adicionaAresta(0, 1, 7);
    g.adicionaAresta(0, 3, 5);
    g.adicionaAresta(1, 2, 8);
    g.adicionaAresta(1, 3, 9);
    g.adicionaAresta(1, 4, 7);
    g.adicionaAresta(2, 4, 5);
    g.adicionaAresta(3, 5, 15);
    g.adicionaAresta(3, 5, 6);
    g.adicionaAresta(4, 5, 8);
    g.adicionaAresta(4, 6, 9);
    g.adicionaAresta(5, 6, 11);


    g.kruskal();


    return 0;
}