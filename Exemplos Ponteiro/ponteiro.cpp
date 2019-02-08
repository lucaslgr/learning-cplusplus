#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int* vet = new int[10]; //Declarando um ponteiro que apontará para um espaço de memória de 10 inteiro
                            //Foi alocado o espaço de 10 inteiros neste ponteiros


    int aux[10];   //Declarando um vetor de inteiros normal de 10 posições

    *(vet + 0) = 10; //Acessando o primeiro índice do vetore vet usando o * para utilizar um ponteiro
    *(vet + 1) = 20; //Assim por diante
    *(vet + 2) = 30;

    cout << *(vet + 0) << endl;
    cout << *(vet + 1) << endl;
    cout << *(vet + 2) << endl<< endl<< endl;


    aux[0] = 10;
    aux[1] = 20;
    aux[2] = 30;

    cout << *(aux + 0) << endl;
    cout << *(aux + 1) << endl;
    cout << *(aux + 2) << endl<< endl<< endl;

    cout << "Decobrindo até onde vai o vetor utilizando sizeof(vetor)/sizeof(int) "<< endl;

    int tamanhoVetorAux = (sizeof(aux)/sizeof(int));

    cout << "Vetor aux: " << tamanhoVetorAux << endl;
    cout << "Vetor vet: " << sizeof(vet)/sizeof(int) << endl << endl << endl;

    //Liberando a memória do meu ponteiro
    delete[] vet;
    vet = NULL;

    cout<< "After I cleaned the variables vectors aux and vet" << endl;
    cout<< "Value of vet: " << vet << endl;
    cout<< "Value of aux: " << aux << endl; 
    
    return 0;
}