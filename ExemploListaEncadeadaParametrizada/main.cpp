#include <iostream>
#include "lista.h"


int main(int agrc, const char *agrv[])
{
    Lista<string> lstring;

    lstring.inserir_final("python");
    lstring.inserir_final("C++");
    lstring.inserir_final("ruby");
    lstring.inserir_final("haskell");

    lstring.mostrar();

    if (lstring.vazia()) {
        cout << "Lista vazia!!!\n";
    }
    else
    {
        cout<< "Lista nao vazia!!!\n";
    }

    lstring.remover();

    lstring.mostrar();

    cout << "Tamanho da lista: " << lstring.tamanho() << endl;

    return 0;
}