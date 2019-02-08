#include <iostream>
#include <list>

using namespace std;

template<class T>
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
        bool vazia ()
        {
            return fila.empty();
        }

        T remover()
        {
            if (!this->vazia()) {
                T e = fila.front(); //Pq pega o elemento?
                fila.pop_front();
                return e;
            }
            else
                throw "Fila vazia!!";
        }

        T frente()
        {
            if (!this->vazia()) {
                return fila.front();
            }
            else
                throw "Fila vazia!!!";
        }

        T final()
        {
            if (!this->vazia()) {
                return fila.back();
            }
            else
                throw "Fila vazia!!!";        
        }
};

int main (int agrc, const char* agrv[])
{
    Fila<double> f1;
    // const char *prtString = "Teste";
    // cout << &prtString << endl;

    cout
        << "ANTES de inserir elementos...\n";

    if (f1.vazia())
        cout << "Fila vazia !! \n";
    else
        cout << "Fila NAO vazia !! \n";

    try
    {
        double e = f1.remover(); //Tentando remover um elemento da fila obedecendo a ordem FIFO
        cout << "Removido o elemento: " << e << endl;
    }
    catch(const char *prtErro)
    {
        std::cerr << "Erro: " << prtErro << '\n'; //Printando a mensagem de erro
    }

    f1.inserir(5.63);
    f1.inserir(3.1);
    f1.inserir(5.22);
    f1.inserir(3.51);

    cout << "\nDepois de inserir elementos...\n";

    if (f1.vazia())
        cout << "Fila vazia!!\n";
    else
        cout << "Fila NÃO vazia!!\n";

    // Mostrando o elemento da frente
    try
    {
        cout << "Elemento da frente:" << f1.frente() << endl;
    }
    catch (const char *prtErro)
    {
        std::cerr << "Erro: " << prtErro << '\n';
    }

    // Mostrando o elemento do final
    try
    {
        cout << "Elemento da final:" << f1.final() << endl;
    }
    catch (const char *prtErro)
    {
        std::cerr << "Erro: " << prtErro << '\n';
    }

    //Remocao de elemento
    // Removendo um elemento
    try
    {
       double valorRemovido = f1.remover();
       cout << "Removido o elemento:" << valorRemovido << endl;
    }
    catch (const char *prtErro)
    {
        std::cerr << "Erro: " << prtErro << '\n';
    }

    //Printando NOVAMNETE agora quem será o elemento da frente
    // Mostrando o elemento da frente
    try
    {
        cout << "Elemento da frente:" << f1.frente() << endl;
    }
    catch (const char *prtErro)
    {
        std::cerr << "Erro: " << prtErro << '\n';
    }


    cout << "\n\n\n" << "Fila de strings: " << endl;

    //Declarando agora uma fila do tipo std::string
    Fila<string> f2;
    f2.inserir("c++");
    f2.inserir("python");
    f2.inserir("ruby");

    //Imprimendo o elmento da frente
    try
    {
        cout << "Elemento da frente:" << f2.frente() << endl;
    }
    catch (const char *prtErro)
    {
        std::cerr << "Erro: " << prtErro << '\n';
    }

    //Imprimendo o elmento do final
    try
    {
        cout << "Elemento da frente:" << f2.final() << endl;
    }
    catch (const char *prtErro)
    {
        std::cerr << "Erro: " << prtErro << '\n';
    }

    return 0;
}