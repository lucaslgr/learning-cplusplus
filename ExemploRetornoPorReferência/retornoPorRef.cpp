/*
 ESTUDO DO RETORNO POR REFERÊNCIA EM UMA FUNÇÃO
 - O C++ permite que uma função faça esse tipo de retorno, que é o retorno por referência.
 - Implicitamente ela retorna um apontador implícito para o valor de retorno
 - Uma função que retorna uma referência, ela funciona como um apelido -> 'alias' para a variável
 que esta sendo referenciada.

 - Qual é o objetivo e quando fazer um retorno por referência?
 -> Geralmente, quando você tem uma quantidade de informação muito grande a ser retornada, que é
    muito mais eficiente do que retornar uma cópia.
*/

#include <iostream>

using namespace std;

typedef struct Pessoa
{
    string nome;
    int idade;
    double peso, altura;

}t_pessoa, fulano, p;


double& calcular_imc(t_pessoa &pessoa)
{
    double result = (pessoa.peso / (pessoa.altura) * (pessoa.altura));

    double &imc = result; // Nesta linha é declarado e atribuido que o endereço de imc recebe o endereço de result

    cout << "O valor da variavel imc eh: " << imc << endl;
    cout << "O valor da variavel &imc eh: " << &imc << endl;
    cout << "O valor da variavel &result eh: " << &result << endl;

    /*
    Note que com as linhas 31, 32 e 33, podemos comprovar que:
        - o retorno da função, é o retorno do endereço de IMC que é o mesmo endereço de result 
    */

    return imc;
}

int main(int agrc, char *agrv[])
{
    //Preenchendo a minha struct
    fulano pessoa = {"joao", 20, 92.45, 1.75};

    cout << "IMC: "<< calcular_imc(pessoa) << endl;

    return 0;
}