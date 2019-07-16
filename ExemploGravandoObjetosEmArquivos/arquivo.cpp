#include <iostream>
#include <fstream> //ofstream e ifstream
#include <string>

using namespace std;

class Pessoa
{
    private:
        string nome;
        int idade;
    public:
        Pessoa(){};
        Pessoa(string nome, int idade)
        {
            this->nome = nome;
            this->idade = idade;
        }
        virtual ~Pessoa(){};

        string & getNome()
        {
            return nome;
        }
        int getIdade()
        {
            return idade;
        }

        void setNome( string& nome)
        {
            this->nome = nome;
        }

        void setIdade(int idade)
        {
            this->idade = idade;
        }

        //A keyword friend define que uma classe é amiga de outra, logo a classe pode acessar métodos e atributos da classe que ela é amiga
        //Sobrecarga de operador de inserção de dados "<<" que pega os DOIS argumetos, a esquerda e a direita
        //ostream = output stream
        friend ostream& operator<<(ostream &os, const Pessoa &p)
        {
            //escrever cada membro
            os << "\n" << p.nome << "\n";
            os << p.idade;
            return os;
        }

        //Sobrecarga do operador de extração de dados ">>"
        // istream = input stream
        friend istream& operator>>(istream &is, Pessoa &p)
        {
            //ler cada membro
            is >> p.nome >> p.idade;
            return is;
        }
};

char menu()
{
    char resp;
    cout << endl << endl;
    cout << "Digite 1 para inserir pessoas\n";
    cout << "Digite 2 para listar pessoas\n";
    cout << "Digite 0 para sair\n";
    cout << "Opcao: " ;
    cin >> resp;
    return resp;
}

int main(int agrc, char* agrv[])
{
    char resp;

    while (true)
    {
        resp = menu();
        if (resp == '1')
        {
            Pessoa pessoa;
            string nome;
            int idade;

            // app = append (adiciona ao final do arquivo)
            ofstream ofs("arquivo.txt", fstream::app);
            cout << "\nDgite o nome da pessoa: ";
            cin >> nome;
            cout << "\nDigite a idade da pessoa: ";
            cin >> idade;
            cout << endl;

            //seta o nome e a idade
            pessoa.setNome(nome);
            pessoa.setIdade(idade);

            //Escrevendo o objeto no arquivo
            ofs << pessoa;

            ofs.close();
        }
        else if(resp == '2')
        {
            Pessoa p;
            ifstream ifs("arquivo.txt");

            cout << "\nListando pessoas...\n\n";

            //verifica se o arquivo existe e se é possível ler
            if (ifs.good())
            {
                //eof = end of file
                //enquanto NAO chegar no final do arquivo
                while (!ifs.eof())
                {
                    ifs >> p; //Faz a extração dos dados

                    //mostrar os dados
                    cout << "Nome: " << p.getNome() << endl;
                    cout << "Idade: " << p.getIdade() << endl;
                }
                ifs.close();
            }
            else
            {
                cout << "Falha ao abrir o arquivo!\n\n";
            }
            
        }
        else if(resp == '0')
        {
            cout << "\nBye!...\n\n";
            break;
        }
        else
        {
            cout << "\nOpcao invalida. Tente novamente\n\n";
        }
    }
    return 0;
}