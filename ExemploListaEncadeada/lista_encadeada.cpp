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
        //Construtor
        Lista()
        {
            cabeca = NULL;
            cauda = NULL;
        }

        //Construtor
        Lista(int v)
        {
            cabeca = new No(v);
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

        //Insere elementos no incio
        void inserir_inicio(int v)
        {
            //Criando um novo nó
            No *novo_no = new No(v);

            //Como inserimos no início, a referência para o próximo nó, será para a "ANTIGA cabeca"
            novo_no->setProx(cabeca);

            //Setando a cabeca para o novo_no
            cabeca = novo_no;
        }

        //Insere elementos no final
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

        //Retorna o tamanho da lista
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
            return tam;
        }

        //Retorna true or false referente se existe o valor na lista
        bool existe(int v)
        {
            No *c = cabeca;
            bool resposta = false;
            while(c)
            {
                if (c->obterValor() == v) {
                    resposta = true;
                    return resposta;
                }
                else 
                    c = c->obterProx();
            }

            return resposta;
        }

        void remover() //remocao do final
        {
            if (!this->vazia()) {
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
                    No  *ant_ant = cabeca;
                    No  *ant = cabeca->obterProx();
                    No  *corrente = cabeca->obterProx()->obterProx();

                    while(corrente)
                    {
                        No *aux = ant;
                        ant = corrente;
                        ant_ant = aux;
                        corrente = corrente->obterProx(); //Ficar apontando para o próximo até que seja NULL
                    }

                    delete ant_ant->obterProx(); //Liberando memória do último elemento
                    ant_ant->setProx(NULL); //Setando NULL no último elemento
                    cauda = ant_ant; //Atualizando a cauda para apontar para o último elemento
                }
            }
            
        }
};



int main (int agrc, const char* agrv[])
{
    Lista l1;

    if (l1.vazia())
        cout << "Lista vazia!!\n";
    else
    {
        cout << "Lista NÃO vazia!!\n";
    }

    l1.mostrar();

    if (l1.existe(10)) 
        cout << "\nO elemento 10 existe na lista!!\n";   
    else
        cout <<"O elemento 10 nao existe na lista!!";

    l1.inserir_final(10);
    l1.inserir_final(20);
    l1.inserir_final(30);
    l1.inserir_final(40);
    l1.inserir_final(50);
    l1.inserir_inicio(60); //ps: inserido no inicio

    l1.mostrar();

    if (l1.vazia())
        cout << "Lista vazia!!\n";
    else
    {
        cout << "Lista NAO vazia!!\n";
    }

    if (l1.existe(10))
        cout << "\nO elemento 10 existe na lista!!\n";
    else
        cout << "O elemento 10 nao existe na lista!!";

    l1.remover();
    l1.mostrar();

    cout << "Tamanho da lista: " << l1.tamanho() << endl;

    return 0;
}