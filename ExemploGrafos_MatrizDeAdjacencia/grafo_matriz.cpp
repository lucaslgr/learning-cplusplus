/*
    ---------------------------------GRAFO - MATRIZ DE ADJACÊNCIA------------------------------------
    -MATERIAL UTILIZADO para entender a teoria:
     ->> https://www.slideshare.net/mcastrosouza/grafos-representao
*/
#include <iostream>

using namespace std;

int grafo[5][5] =
{
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 0, 1, 1},
    {0, 0, 1, 0, 1},
    {0, 0, 1, 1, 0}
};

bool tem_ligacao(int v1, int v2)
{
    //Se o resultado for == 1, entra no if
    if (grafo[v1][v2])
    {
        return true;
    }
    return false;
}

int main(int agrc, const char *agrv[])
{
    //Testando quais vértices tem ligação com o outro, passando V1 e V2 como parâmetros
    cout << tem_ligacao(2,0);
    return 0;
}