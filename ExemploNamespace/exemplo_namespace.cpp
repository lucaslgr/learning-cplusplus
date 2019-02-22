/*
Descrição:
O namespace é utilizado para determinar onde exatamente pertence um determinado conjunto de
dados pré-estabelecidos, como bibliotecas, funções e variáveis. O objetivo do namespace é 
permitir a utilização de métodos com o mesmo nome que pertençam a bibliotecas que estão contidas
em namespa ces diferentes.
*/

/*
Como definir a utilização do namesapce?
Existem duas formas, sendo elas:
 1ª -> using namespace ns1; 
    Essa forma define que todo o código abaixo da sua declaração utilizará este namespace.

 2ª -> ns1::num; OU ns2::num;
    Essa forma define a utilização de um determinado namespace APENAS naquele termo no qual foi
    implementado juntamente com o operador de escopo :: .
*/

#include <iostream>

namespace ns1
{
    int num = 42;
    
    class A
    {
        public:
            void imprimir()
            {
                std::cout << "Ola, sou a classe A do namespace ns1" << std::endl;
            }
    };
}

namespace ns2
{
    int num = 50;

    class A
    {
      public:
        void imprimir()
        {
            std::cout << "Ola, sou a classe A do namespace ns2" << std::endl;
        }
    };
}

// using namespace ns1; // Usando esse namespace, num terá valor de 42
// using namespace ns2; // Usando esse namespace, num terá valor de 50

int main(int agrc, char *argv[])
{
    std::cout << ns1::num << std::endl;

    ns1::A ns1A; //Declarando a variável ns1A do tipo ns1::A
    ns2::A ns2A; //Declarando a variável ns2A do tipo ns2::A

    ns1A.imprimir();
    ns2A.imprimir();

    return 0;
}