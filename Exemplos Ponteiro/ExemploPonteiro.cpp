#include <iostream>

using namespace std;

void foo(int* number)
{
	*number = 20;
}

int main(int argc, char** argv)
{
	int var = 10;
	int* pvar;
	
	pvar = &var; //Inicializando a variável ponteiro, para apontar para onde eu indicar (sendo do mesmo tipo)
	
	//mostrando o conteúdo da variável do ponteiro
	cout << *pvar << endl;
	
	*pvar +=20;
	
	foo(&var);
	
	cout<<*pvar<<endl;

	cout<<*pvar<<endl;
	
	cout<<var<<endl;
	
	return 0;
}

