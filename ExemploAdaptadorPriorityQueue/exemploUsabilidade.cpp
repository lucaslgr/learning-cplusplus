#include <iostream>
#include <queue>

using namespace std;

class Pessoa
{
    private:
        string nome;
        int idade;
    
    public:
        Pessoa(string nome, int idade)
        {
            this->nome = nome;
            this->idade = idade;
        }

        string getNome()
        {
            return this->nome;
        }

        int getIdade()
        {
            return this->idade;
        }
};

struct CompIdade //Definindo o critério de ordenação da priority_queue
{
    bool operator() (Pessoa &p1, Pessoa &p2) //Sobrecarga de operador
    {   
        return p1.getIdade() < p2.getIdade(); //Critério de prioridade será de quem tem a maior idade
    }
};

int main()
{
    // Primeiro argumento de tipo -> Tipo dos elementos da queue
    // Segundo argumento de tipo  -> Conteiner de elementos da queue
    // Terceiro argumento de tipo -> Passando o critério de ordenação da queue
    priority_queue< Pessoa, vector<Pessoa>, CompIdade > pq_FilaBanco; //Declaracao

    Pessoa p1("Joao", 40), p2("Maria", 55), p3("Pedro", 22);

    pq_FilaBanco.push(p1);
    pq_FilaBanco.push(p2);
    pq_FilaBanco.push(p3);

    Pessoa pessoa = pq_FilaBanco.top();

    cout << "Nome: " << pessoa.getNome() << endl;
    cout << "Idade: " << pessoa.getIdade() << endl;

    return 0;
}