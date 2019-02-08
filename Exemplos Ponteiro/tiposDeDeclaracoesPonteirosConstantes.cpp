#include <iostream>

using namespace std;

main (int argc, char *agrv[]) {

    const int vet[] = {1, 2, 3 };

    const int* p1 = &vet[0]; // A delcaração do p1 é a mesma da declaração do p2, não tem diferença entre elas
    int const* p2 = &vet[1]; // o ponteiro p1 e p2 podem ser inicializados depois pois o ponteiro ou seja
                             // o ENDEREÇO PODE para onde eles apontam pode ser alterado mas o VALOR NÃO
    
    int* const p3 = new int[3]; //Já o ponteiro p3 TEM que ser inicializado assim que ele é declarado pois ele NÃO PODE
                                //alterar o endereço que ele aponta, MAS PODE ALTERAR O VALOR.

    
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl << endl;


    int p[] = {1, 2, 3};
    int* pTeste = new int[3];
    pTeste[0] = p[0];
    pTeste[1] = p[1];
    pTeste[2] = p[2];

    cout << "*(pTeste + 0): " << *(pTeste + 3) << endl; //OK
    cout << "pTeste[0]: "<< pTeste[3]<< endl << endl;   //OK

    /*
    Duas maneiras de atribuir um valor a um ponteiro que aponta para um vetor 
    1ª:  p3[0] = valor;
    2ª:  *p3 = valor;
    */

    *p3 = 1;
    cout << "*(p3 + 0): " << *(p3 + 0) << endl << endl;
    cout << "p3[0]: "<< p3[0]<< endl << endl;

    cout<< "*(p3 + 0) == *p3[0] : " << (*(p3 + 0) == p3[0]) << endl;

    return 0;
}