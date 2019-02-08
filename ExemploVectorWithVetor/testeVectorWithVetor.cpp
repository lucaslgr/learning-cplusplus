#include <iostream>
#include <vector>
#include <string>

using namespace std;

main(int argc, char const *argv[])
{
    int ss = 0;
    int tt = 0;
    
    cout << "Aqui estamos testando o ss +=1: " << endl;
    while (ss < 5) {
        ss += 1;
        cout << ss << endl << endl;
    }

    cout << "Aqui estamos testando o tt++: " << endl;
    while (tt < 5) {
        tt ++;
        cout << tt << endl << endl;
    }
    

    cout << "We conclusion that is the shame thing" << endl << endl << endl;

    string vetorAux[] = {"1", "2", "30", "40"};


    vector<string> vectorStringTeste1;
    vectorStringTeste1.assign(vetorAux, vetorAux + 4);
    // vectorStringTeste1.push_back("Teste");
    cout << vectorStringTeste1[0] << endl ;//<< endl<< endl << vectorStringTeste1.size();
    cout << vectorStringTeste1[1] << endl ;
    cout << vectorStringTeste1[2] << endl ;
    cout << vectorStringTeste1[3] << endl ;

    cout<< endl<< endl<< endl;
    cout<< "endereços de memória da segunda posição do vetor" << endl;
    cout<< (vetorAux + 2)<< endl;
    cout<< &vetorAux[2] << endl;
    cout<< endl<< endl<< endl;
    cout<< "Logo temos: "<< endl;
    cout<< " &vetorAux[2] == (vetorAux + 2) : " << ( &vetorAux[2] == (vetorAux + 2) )<< endl;
    cout<< " vetorAux[2] == *(vetorAux + 2) : " << ( vetorAux[2] == *(vetorAux + 2) )<< endl;

    for (int i = 0; i < vectorStringTeste1.size(); i++)
    {
        cout << vectorStringTeste1[i]<< endl;
    }
    cout<< endl<< endl<< endl;

    return 0;
}
