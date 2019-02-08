#include <iostream>
#include <vector>

using namespace std;

int main(int agrc, const char *agrv[])
{
    vector<int> v(3);
    v[0] = 10;
    v[1] = 20;
    v[2] = 30;
    vector<int>::iterator it;

    for(it = v.begin(); it!=v.end(); it++)
    {
        cout << *it << endl;
    }
    
    //É necessário o uso do asterisco->* pois a função begin() retorna um iterador que
    //aponta para a memória da primeira posição do vector
    cout << "primeiro elemento: " << *v.begin() << endl;

    //O iterador vai de uma faixa [begin, end), ou seja, intervalo fechado de begin até um
    //intervalo ABERTO no end
    cout << "primeiro elemento: " << *(--v.end()) << endl;


    // TESTE E COMPARAÇÃO DE ITERADOR REVERSO & NORMAL
    //Utilzando um iterador reverso

    cout << endl << "Iterador Reverso: " << endl;
    
    vector<int>::reverse_iterator r_it;
    int i = 0;
    for (r_it = v.rbegin(); r_it != v.rend(); r_it++)
    {
        *r_it = ++i;
        cout << *r_it << endl;
    }

    cout << endl << "Iterador Normal: " << endl;

    //Utilizando iterador normal
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    // FIM TESTE


    return 0;
}