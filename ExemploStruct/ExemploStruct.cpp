#include <iostream>
#include <string.h>

using namespace std;

typedef struct pessoa
{
	char nome[];
	int idade;
} p_Pessoa;
	
int main(int argc, char *argv[])
{
	p_Pessoa pessoas[100];
	p_Pessoa *p;
	
	p = &pessoas[0]; //Dizendo para o ponteiro de struct que ele apontará para o endereço de pessoas[0]
	
	char nome1[] = "Lucas";
	//p->nome = "Lucas";
	//pessoas[1].nome = {'L','u','c','a','s'};
	//pessoas[2].nome = {'Z','u','c','a','s'};
	
	cout<<p->nome<<endl;
	cout<<nome1[0]<<endl;
	cout<<pessoas[2].nome<<endl;
	
	return 0;
}