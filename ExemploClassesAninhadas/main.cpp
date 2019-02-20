#include <iostream>

using namespace std;

class A 
{
    public:
        class B
        {
            private:
                int var;
            
            public:
                B(int var)
                {
                    this->var = var;
                }

                int getVar()
                {
                    return var;
                }
        };
};

void displayPointer(int *prt)
{
    // int a;
    // cin >> a ;

    cout << *prt << endl;
}

int main (int agrc, char* agrv[])
{
    A::B obj(10); //Instanciando um objeto

    cout << obj.getVar() << endl;


    int *prt_INT;

    displayPointer(prt_INT);

    return 0;
}