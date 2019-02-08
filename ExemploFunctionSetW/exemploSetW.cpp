/*
A Função setw faz uma impressão de forma ORGANIZADA dos dados, tendo como parametro um 
espaçamento, que é dado pelo NÚMERO de caracteres de espaço você quer dar
*/
#include <iostream>
#include <iomanip>
 
using namespace std;
 
class Pessoa
{
public:
	string nome;
	int idade;
 
	Pessoa(const string& nome, const int& idade)
	{
		this->nome.assign(nome);
		this->idade = idade;
	}
};
 
int main(int argc, char *argv[])
{
	Pessoa p1("Maria da Silva", 20);
	Pessoa p2("Pedro Souza", 34);
	Pessoa p3("Felipe da Silva", 28);
	
	cout << setw(20) << "Nome da pessoa" << setw(10) << "Idade" << endl; 
	cout << setw(20) << p1.nome << setw(10) << p1.idade << endl;
	cout << setw(20) << p2.nome << setw(10) << p2.idade << endl; 
	cout << setw(20) << p3.nome << setw(10) << p3.idade << endl; 
	
	return 0;
}