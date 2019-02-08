#include <fstream>
#include <iostream>

using namespace std;

main(int agrc, const char* agrv[])
{
    ifstream in("teste.txt");
    char c;

    while(true){
        in >> c;
        // .fail testa se tem algum caractere para ser lido e retorna um booleano
        if (in.fail()) {
            break;
        }
        cout << c;
    }
    
    return 0;
}