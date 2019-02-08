#include <iostream>
#include "pilha.h"

using namespace std;

int main(int argc, char *argv[])
{
	int tam;

	cout << "Informe o tamanho da sua pilha: " << endl;
	cin >> tam ;

	Pilha<int> p(tam);

	p.empilhar(2);
	p.empilhar(3);
	p.empilhar(4);
	
	//p.desempilhar();
	if(p.vazia())
		cout << "Pilha vazia!\n";
	else
		cout << "Pilha NAO vazia!\n";
	if(p.getTopo() != -1)
		cout << "Topo: " << p.getTopo() << endl;
	else
		cout << "A pilha esta vazia!!\n";

	cout<< "Tamanho do tipo escohido para o TYPE EM BITS: " << p.retornaTamanhoDoTipoEscolhido() << endl;

	/*
	//Teste Lucas (Nada haver com o objetivo do programa)
	cout << endl << endl << endl;
	int auxiliar = 9;
	int* const variavelTeste = &auxiliar;
	cout << "Valor do ponteiro: " << variavelTeste << endl;
	cout << "Valor do ponteiro: " << *variavelTeste << endl;
	*variavelTeste = 8;
	cout << "Valor do ponteiro: " << variavelTeste << endl;
	cout << "Valor do ponteiro: " << *variavelTeste << endl;
	*/

	return 0;
}