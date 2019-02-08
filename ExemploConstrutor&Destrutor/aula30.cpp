#include <iostream>
#include <string.h>

using namespace std;

class Pessoa
{
private:
	char nome[100];
	int idade;
	int* parentes;
public:
	Pessoa(const char* nome, int idade)
	{
		strcpy(this->nome, nome);
		this->idade = idade;
		parentes = new int[100];
		cout << "Entrou no construtor: " << nome << endl;
	}
	char * getNome()
	{
		return nome;
	}
	int getIdade()
	{
		return idade;
	}
	~Pessoa()
	{
		cout << "Entrou no destrutor: " << nome << endl;
		delete[] parentes;
	}
};

int main(int argc, char *argv[])
{
	Pessoa pessoas[3] =
	{
		{"joao", 30}, {"maria", 20}, {"pedro", 40},
	};

	//cout << "Nome: " << p.getNome() << endl;
	//cout << "Idade: " << p.getIdade() << endl;
	return 0;
}
