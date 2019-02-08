#include <iostream>
#include <string.h>

using namespace std;

main(int argc, char const *argv[])
{
    int vetor[100];

    int vetorDeclarado[4] = {1, 2, 3, 4}; 

    for(int ss = 0; ss < 100; ss++)
    {
        vetor[ss] = ss;
        cout << vetor[ss] << endl;
    }

    
    for(int i = 0; i < 4; i++)
    {
        cout << vetorDeclarado[i] << endl;
    }
    cout << endl << endl << endl;

    cout <<  "Imprimindo o segundo elemento" << endl;
    cout << vetorDeclarado[1] << endl << endl;

    cout << "Utilzando a função sizeof para saber o tamanho do vetor" << endl;
    cout << "Lembrando que um inteiro tem 4 bits" << endl;
    cout << (sizeof(vetor)/4) << endl << endl;


    cout << "Estudando agora um vetor de caracteres" << endl;

    char vetorNome[] = {'l', 'u', 'c', 'a', 's', '\0'};
    cout << vetorNome << endl;

    cout<< endl<< endl<< endl;
    cout << "Estudando agora um vetor de caracteres com aspas duplas " << endl;
    
    char vetorNomeVecCaracteres[] = "Lucas" ;
    cout << vetorNomeVecCaracteres << endl << endl << endl;

    cout << "Estudando agora um tipo String" << endl;
    
    string vetorNomeString = "Lucas" ;
    cout << vetorNomeString + " Aqui é um tipo String" << endl << endl << endl;

    return 0;
}
