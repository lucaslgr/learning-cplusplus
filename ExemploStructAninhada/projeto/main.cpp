#include <iostream>
#include "aluno.h"

int main(int agrc, const char *agrv[])
{
    Aluno aluno1 = Aluno("Lucas", "CEFET-MG");
    t_aluno *ptr_aluno;

    ptr_aluno = &aluno1;

    ptr_aluno->setNome("Lucas");
    ptr_aluno->setUniversidade("CEFET-MG");

    cout << "Aluno: " << ptr_aluno->obterNome() << endl;
    cout << "Universidade: " << ptr_aluno->obterUniversidade() << endl;

    return 0;
}