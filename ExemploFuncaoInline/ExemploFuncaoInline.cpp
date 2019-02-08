#include <iostream>

using namespace std;

//A função inline acelera o desempenho, pois o compilador troca a sua chamada pelo código da função na hora da compilação
//Porém ela consome mais memória, usar apenas em funções pequenas que são chamadas muitas vezes.
inline void foo()
{
    cout << "Aprendendo C++\n";
}

int main(int agrc, char *argv[])
{
    foo();
    return 0;
}