#include <iostream>
#include <string.h>

using namespace std;

class ClasseMae
{
    public:
        virtual void mostrarMensagem()
        {
            cout << "Ola, sou a classe mae" << endl;
        }
};

class ClasseFilha : public ClasseMae
{
    public:
        // A palavra chave virtual é como a palavra chave abstract,
        //permite que está seja sobrescrita de acordo com a função da classes herdeiras (classe filha)
        virtual void mostrarMensagem()                                   
        {
            cout << "Ola, sou a classe filha" << endl;
        }
};

void foo(ClasseMae* p)
{
	p->mostrarMensagem();
}

int main(int argc, char *argv[])
{
	ClasseMae mae;
	ClasseFilha filha;

	foo(&mae);
	foo(&filha);
	return 0;
}
