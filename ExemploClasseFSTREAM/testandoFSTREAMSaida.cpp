//Abrir um arquivo de saída
#include <iostream>
#include <fstream>

using namespace std;

main(int agrc, const char* argv[])
{
    ofstream output("saida.txt");

    //Adicionando texto ao arquivo
    output << "Aprendendo C++" << endl;
    output << "www.google.com.br" << endl;

    return 0;
}