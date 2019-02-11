#include <iostream>

using namespace std;

class No
{
    private:
        int v;
        No *prox;
    public:
        No (int v)
        {
            this->v = v;
            this->prox = NULL;
        }

        int obterValor()
        {
            return v;
        }

        No* obterProx()
        {
            return prox;
        }

        void setProx(No* p)
        {
            prox = p;
        }
};

class Lista
{
    private:
        No* cabeca; //Primeiro elemento da lista
        No* cauda;  //Ultimo elemento da lista
    public:
        Lista()
        {
            cabeca = NULL;
            cauda = NULL;
        }
        Lista(int v)
        {
            cabeca = new No(v);
            cauda = cabeca;
        }
        virtual ~Lista()
        {
            delete cabeca; //O destrutor deleta apenas a cabeca devido a alocação de memoria na linha 46
        }

        void mostrar()
        {
            cout << "\nImprimindo todos os elementos...\n";
            No *c = cabeca;

            if (this->vazia())
                cout << "A lista NAO possui elementos!! \n";
            else
            {
                while(c)
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

        void inserir_inicio(int v)
        {
            //Criando um novo nó
            No *novo_no = new No(v);

            //Como inserimos no início, a referência para o próximo nó, será para a "ANTIGA cabeca"
            novo_no->setProx(cabeca);

            //Setando a cabeca para o novo_no
            cabeca = novo_no;
        }

        void inserir_final(int v)
        {
            //Criando um novo nó
            No *novo_no = new No(v);

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

        int tamanho()
        {
            if (this->vazia()) {
                return 0;
            }
            //loop para contagem dos nós
            No *c = cabeca;
            int tam; //contador
            do
            {
                c = c->obterProx(); //Vai obtendo o proximo até que a lista termine
                tam++;
            }
            while(c);
        }
};



int main (int agrc, const char* agrv[])
{
    return 0;
}