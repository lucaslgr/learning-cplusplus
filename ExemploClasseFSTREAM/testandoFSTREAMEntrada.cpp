// Abrir um arquivo para entrada
// Ler o conteúdo desse arquivo
#include <iostream>
#include <fstream>

using namespace std;

main (int agrc,const char *argv[])
{
    // Abrindo um arquivo para entrada
    ifstream inChar("teste.txt");

    //Printando CADA caractere com um char
    char c ;

    cout << "\n Mostrando cada caractere: \n";
    while(inChar.good()){ //.good signfica "enquanto for possível extrair caractere do arquivo"
        c = inChar.get();
        cout << c;
    }
    //FIM - Printando CADA caractere com um char

    ifstream inString("teste.txt");

    //Printnado tudo de uma vez com uma STRING
    
    string textoCompleto;

    while (inString.good())
    {
        textoCompleto.push_back(inString.get());
    }

    cout << endl
         << endl
         << "\n Mostrando a string completa: \n"
         << textoCompleto << endl;
    // FIM - Printando CADA caractere com um char

    return 0;
}