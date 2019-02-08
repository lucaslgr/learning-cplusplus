//Sobrecarga do operador =
#include <iostream>
#include <string.h>

using namespace std;

//Número complexo
class Pessoa 
{
    private:
        char* nome;
        int id;
    public:

        void inicializar (const char* novoNome, int novoID)
        {
            int tam = strlen(novoNome) + 1; //É adicionado +1 devido ao caracterer nulo
            nome = new char[tam];
            strcpy(nome, novoNome);
            id = novoID;
        }

        Pessoa (const char* novoNome, int novoID)
        {
            inicializar(novoNome, novoID);
        }

        void destruir ()
        {
            delete[] nome;
            nome = 0;
        }
        
        virtual ~Pessoa ()
        {
            destruir();
        }

        const char* getNome()
        {
            return this->nome;
        }

        int getID()
        {
            return this->id;
        }

        void mudarNome(char l)
        {
            this->nome[0] = l;
        }

        //Sobrecarga do operador
        Pessoa& operator=(Pessoa &p)
        {
            if (this != &p) {
                destruir();

                inicializar(p.nome, p.id);
            }

            return *this;
        }
};

main (int agrc, const char* argv[])
{
    
    Pessoa p1("marcos", 1), p2("pedro", 2);

    p1 = p2;

    p1.mudarNome('A');

    cout << "Nome:" << p1.getNome() << endl << "ID: " << p1.getID() << endl;
    cout << "Nome:" << p2.getNome() << endl << "ID: " << p2.getID() << endl;
    return 0;
}