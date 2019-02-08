#include <iostream>
#include <string.h>

using namespace std;

main (int argc, char const* argv[]) {
    
    const int* p2; //P2 é do tipo que altera o endereço mas não altera o valor
    const int *p2; //Igual a declaração de cima

    int const* p3; //P3 é do mesmo tipo de p2
    int const *p3; //Igual a declaração de cima


    int sample = 2;
    int* const p1 = &sample;  // P1 é do tipo que não altera o endereço mas altera o valor,
                    // e NECESSARIAMENTE tem que ser inicializado junto com a sua declaração


    return 0;
}

