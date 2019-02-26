/*
    KEYWORD EXTERN
    - O objetivo a keyword extern é ampliar a visibilidade de variáveis e funções
    - Por padrão, as funções já são compiladas como extern

    - Acesse abaixo para entender os exemplos:
    -> https://docs.microsoft.com/pt-br/cpp/cpp/extern-cpp?view=vs-2017
*/

#include <iostream>
#include "varExtern.h"

// extern int var;

int main(int agrc, char *argv[])
{
    int var = 10;

    std::cout << var << std::endl;

    return 0;
}