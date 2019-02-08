
/*
    Operador ternário ?:
    <condicao que retorne um booleano> ? <operacao 1> : <operacao 2>;
*/

#include <iostream>
#include <string>

using namespace std;

//Calcula se o primeiro valor é maior ou igual ao segundo e retorna true or false
bool calculaSeValorEMaior (int primeiroValor, int valorParaComparacao)
{
    if (primeiroValor < valorParaComparacao)
        return true;
    else
        return false;
}

main (int agrc, const char* argv[])
{
    
    int num1 = 10;
    int num2 = 20;
    /*
    if (num < 10)
        cout << "O número num é menor ou igual a 10" << endl;
    else
        cout << "O número é maior que 10" << endl;
    */

    (num1 <= 10) ? cout << "O número é menor ou igual a 10" : cout << "O número é maior ou igual a 10" << endl << endl;
    calculaSeValorEMaior(10, 20)? cout << "O número é menor ou igual a 10" : cout << "O número é maior ou igual a 10" << endl << endl;
    return 0;
}