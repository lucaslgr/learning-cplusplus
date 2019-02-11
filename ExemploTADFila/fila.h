#ifndef _FILA_H_
#define _FILA_H_
#include <iostream>
#include <list>

using namespace std;

template <class T>
class Fila
{
  private:
    list<T> fila;

  public:
    //Insere um elemento no final da fila
    void inserir(const T &e)
    {
        fila.push_back(e);
    }
    //Testa se a fila está vazia
    bool vazia()
    {
        return fila.empty();
    }

    T remover()
    {
        if (!this->vazia())
        {
            T e = fila.front(); //Pq pega o elemento?
            fila.pop_front();
            return e;
        }
        else
            throw "Fila vazia!!";
    }

    T frente()
    {
        if (!this->vazia())
        {
            return fila.front();
        }
        else
            throw "Fila vazia!!!";
    }

    T final()
    {
        if (!this->vazia())
        {
            return fila.back();
        }
        else
            throw "Fila vazia!!!";
    }
};