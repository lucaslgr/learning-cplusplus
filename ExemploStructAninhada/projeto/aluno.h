#ifndef _ALUNO_H_
#define _ALUNO_H_

#include <string.h>
#include <iostream>

using namespace std;

typedef struct Universidade
{
    private:
        string nome;

    public:
        void setNome(string nome)
        {
            this->nome = nome;
        }

        string obterNome()
        {
            return this->nome;
        }
} t_universidade;

typedef struct Aluno
{
    private:
        string nome;
        t_universidade universidade;

    public:
        Aluno(string nome, string universidade)
        {
          this->nome = nome;
          this->universidade.setNome(universidade);
        }

        string obterNome()
        {
            return this->nome;
        }

        string obterUniversidade()
        {
            return universidade.obterNome();
        }

        void setNome(string nome)
        {
            this->nome = nome;
        }

        void setUniversidade(string nome)
        {
            universidade.setNome(nome);
        }
    
} t_aluno, Aluno; //Forma de definir vários apelidos para a sua struct

#endif