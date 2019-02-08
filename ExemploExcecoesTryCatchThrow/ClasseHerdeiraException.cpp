#include <iostream>
#include <string.h>
#include <exception>

using namespace std;

class ExcecaoCustomizada : public exception
{
    protected:
        char msg[100];
    public:
        ExcecaoCustomizada(const char* e)
        {
            strcpy(msg, e);
        }

        virtual const char* what()
        {
            return msg;
        }
};

int fat (int n)
{
    if (n < 0) {
        throw ExcecaoCustomizada("Numero negativo!!");
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return (n * fat(n - 1));
}

int main (int agrc, const char *agrv[])
{
    try
    {
        cout << "Fatorial de 5: " << fat(5) << endl;
        cout << "Fatorial de -5: " << fat(-5) << endl;
    }
    catch(ExcecaoCustomizada e)
    {
        std::cerr << "Erro:" << e.what() << '\n';
    }
    catch(...)
    {
        cerr << "Qualquer erro!" << endl;
    }
    
    return 0;
}