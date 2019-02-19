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

int main (int agrc, char* agrv[])
{
    A::B obj(10); //Instanciando um objeto

    cout << obj.getVar() << endl;

    return 0;
}