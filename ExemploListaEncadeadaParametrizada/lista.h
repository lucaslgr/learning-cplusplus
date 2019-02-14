#ifndef _LISTA_H_
#define _LISTA_H_

#include <iostream>

using namespace std;

//classe NO
template <class T>
class No
{
  private:
    T v;
    No *prox;

  public:
    No(T v)
    {
        this->v = v;
        this->prox = NULL;
    }

    T obterValor()
    {
        return v;
    }

    No *obterProx()
    {
        return prox;
    }

    void setProx(No *p)
    {
        prox = p;
    }
};

//classe Lista
template <class T>
class Lista
{
  private:
    No<T> *cabeca; //Primeiro elemento da lista
    No<T> *cauda;  //Ultimo elemento da lista
  public:
    //Construtor
    Lista()
    {
        cabeca = NULL;
        cauda = NULL;
    }

    //Construtor
    Lista(T v)
    {
        cabeca = new No<T>(v);
        cauda = cabeca;
    }

    //Destrutor
    virtual ~Lista()
    {
        delete cabeca; //O destrutor deleta apenas a cabeca devido a alocação de memoria na linha 46
    }

    //Mostrar todos elementos
    void mostrar()
    {
        cout << "\nImprimindo todos os elementos...\n";
        No<T> *c = cabeca;

        if (this->vazia())
            cout << "A lista NAO possui elementos!! \n";
        else
        {
            while (c)
            {
                cout << c->obterValor() << endl;
                c = c->obterProx();
            }
            cout << endl;
        }
    }

    //Testa se a lista esta vazia
    bool vazia()
    {
        return (cabeca == NULL); //Se houver elemento retorna FALSE, se não tiver, retorna TRUE
    }

    //Insere elementos no incio
    void inserir_inicio(T v)
    {
        //Criando um novo nó
        No<T> *novo_no = new No<T>(v);

        //Como inserimos no início, a referência para o próximo nó, será para a "ANTIGA cabeca"
        novo_no->setProx(cabeca);

        //Setando a cabeca para o novo_no
        cabeca = novo_no;
    }

    //Insere elementos no final
    void inserir_final(T v)
    {
        //Criando um novo nó
        No<T> *novo_no = new No<T>(v);

        if (this->vazia())
        {
            cabeca = novo_no;
            cauda = novo_no;
        }
        else
        {
            cauda->setProx(novo_no);
            cauda = novo_no;
        }
    }

    //Retorna o tamanho da lista
    int tamanho()
    {
        if (this->vazia())
        {
            return 0;
        }
        //loop para contagem dos nós
        No<T> *c = cabeca;
        int tam; //contador
        do
        {
            c = c->obterProx(); //Vai obtendo o proximo até que a lista termine
            tam++;
        } while (c);
        return tam;
    }

    //Retorna true or false referente se existe o valor na lista
    bool existe(int v)
    {
        No<T> *c = cabeca;
        bool resposta = false;
        while (c)
        {
            if (c->obterValor() == v)
            {
                resposta = true;
                return resposta;
            }
            else
                c = c->obterProx();
        }

        return resposta;
    }

    //Remove um elemento do final da lista
    void remover() //remocao do final
    {
        if (!this->vazia())
        {
            //se houver só 1 elemento
            if (cabeca->obterProx() == NULL)
            {
                cabeca = NULL;
            }
            //se houver 2 elementos
            else if (cabeca->obterProx()->obterProx() == NULL)
            {
                cabeca->setProx(NULL);
            }
            //se houver mais de 2 elementos
            else
            {
                No<T> *ant_ant = cabeca;
                No<T> *ant = cabeca->obterProx();
                No<T> *corrente = cabeca->obterProx()->obterProx();

                while (corrente)
                {
                    No<T> *aux = ant;
                    ant = corrente;
                    ant_ant = aux;
                    corrente = corrente->obterProx(); //Ficar apontando para o próximo até que seja NULL
                }

                delete ant_ant->obterProx(); //Liberando memória do último elemento
                ant_ant->setProx(NULL);      //Setando NULL no último elemento
                cauda = ant_ant;             //Atualizando a cauda para apontar para o último elemento
            }
        }
    }
};

#endif