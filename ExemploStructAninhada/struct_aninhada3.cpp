//Exemplo de instanciação da estruct aninhada
#include <iostream>
#include <string.h>

using namespace std;

typedef struct Universidade
{
    string nome;
} t_universidade;

typedef struct Aluno
{
    string nome;
    t_universidade universidade;
} t_aluno;


int main( int agrc, const char* argv[])
{
    //Quando adiciona-se uma {} dentro de outra {} eu estou acessando a struct filha
    t_aluno aluno = {"Lucas", {"CEFET"} };

    t_aluno *ptr_aluno = &aluno;

    cout << "Aluno: " << ptr_aluno->nome << endl;
    cout << "Universidade: " << ptr_aluno->universidade.nome << endl;

    return 0;
}
