//Exemplo simples
#include <iostream>
#include <string.h>

using namespace std;

typedef struct Curso
{
    char nome[100];
    double preco;
} t_curso;

typedef struct Estudante
{
    char nome[50];
    Curso curso;
} t_estudante;

int main(int agrc, const char *agrv[])
{
    t_estudante e;

    strcpy(e.nome, "Lucas");
    strcpy(e.curso.nome, "C++ aprendizado");
    e.curso.preco = 100;

    cout << "Nome da pessoa: " << e.nome << endl;
    cout << "Curso: " << e.curso.nome << endl;
    cout << "Preco: " << e.curso.preco << endl;


    return 0;
}