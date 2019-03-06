/*
    ESTUDO DA CLASSE MAP
    - Características:
     -> É uma classe que armazena os elementos de forma que eles possuam uma combinação de chave e valor
     -> As chaves são únicos para identificar os elementos.
     -> Enquanto os valores armazenam o conteúdo associado a uma determinada chave

    - Sintaxe:
    map<tipo do valor , tipo da chave> = mapa{
        {valor, chave},
        {valor, chave}
    };
*/

#include <iostream>
#include <map>

using namespace std;

int main(int agrc, const char *agrv[])
{
    //PRMEIRA MANEIRA DE UTILIZAR
    pair<int, string> pares[] = //Inicializando um vetor de pares
    {
        make_pair(1, "Lucas"),
        make_pair(2, "Maria"),
        make_pair(3, "Joaozin")
    };

    map<int, string> mapa1(pares, pares + 3);

    // CONSULTANDO OS DADOS
    // SINTAXE: mapa[chave] -> retorna o valor correspondente aquela chave
    cout << mapa1[1] << endl;
    cout << mapa1[2] << endl;
    cout << mapa1[3] << endl;
    //FIM DA PRMEIRA MANEIRA DE UTILIZAR


    cout << "\n\n\n";


    //SEGUNDA MANEIRA DE UTILIZAR
    map<int, string> mapa2; //Declaracao
    
    //Inserindo elementos
    mapa2[1] = "Lucas";
    mapa2[2] = "Joao";
    mapa2[3] = "Maria";

    //Acessando e printando as informações
    cout << mapa2[1] << endl;
    cout << mapa2[2] << endl;
    cout << mapa2[3] << endl;
    //FIM DA MANEIRA DE UTILIZAR

    //Utilizando a função at, que retorna uma referência de um 
    //determinado valor, passando como argumento a sua respectiva chave
    mapa2.at(2) = "Noeh";
    cout << "\nPrintando o valor alterado com a funcao at:\n"<<mapa2[2] << endl;
    
    //Limpando o map
    mapa2.clear();

    //Testando se o mapa esta vazio
    if(mapa2.empty())
        cout << "Mapa2 vazio!\n" << endl;
    else
        cout << "Mapa2 NAO vazio!\n" << endl;

    
    //Utilizando a funcao map.cout para identificar se um determinado valor pertence ao map
    //a partir do argumento que é uma key
    if (mapa1.count(1) == true)
        cout << "1 eh elemento do mapa \n";
    else
        cout << "1 NAO eh elemento do mapa\n";


    //Percorrendo um map usando o iterator
    map<int, string>::iterator it;
    for(it = mapa1.begin(); it != mapa1.end(); it++)
        cout << "A chave "<< it->first << " => " << it->second << endl;

    
    //Funcao find, que retorna um iterator para um elemento de acordo com a chave passada como argumento

    it = mapa1.find(2); //Pegando o iterator que aponta para o elemento de chave = 2
    mapa1.erase(it); //Apagando o elemento referente a chave especficada

    cout << "\n\n\n\n" ;

    //Mostrando todos elementos
    /*
        o iterator de um map acessa a chave de um elemento com o método first e acessa o valor
        do elemento com o método second, ex:

            std::map<int, string>::iterator it;
            it = mapa.begin();

            cout << "Printando a chave: " << it->first" << endl;
            cout << "Printando o valor: " << it->second << endl;
    */
    for (it = mapa1.begin(); it != mapa1.end(); it++)
        cout << "A chave " << it->first << " => " << it->second << endl;


    //Testando se uma chave existe usando a função find que busca em todos os elementos até o último caso não encontre
    if (mapa1.find(2) == mapa1.end())
        cout << "\nChave 2 NAO existe!\n";
    else
        cout <<"\nChave 2 existe!\n";
    
    
    /* Inserindo elementos, 1ª forma:
            ->Usando a função insert para inserir elementos de um map em uma determinada posicao de acordo com a sua chave
    */
    // it = mapa1.begin(); //Pegando endereço para o início do map
    // mapa1.insert(pair<int, string>(2, "maria")); //Usando a funcao pair para criar um elemento da map, ou seja, um par

    /* Inserindo elementos, 2ª forma:
            ->Usando o operador [] e passando a key e o valor do elemento pelo operador de atribuição =, exemplo:
                mapa[1 /KEY/ ] = "lucas" /Valor/ 
    */

    mapa1[2] = "Maria"; //Inserindo no map, o valor Maria em um elemento com a key = 2

    //Mostrando todos elementos de um map usando o iterator
    for(it = mapa1.begin(); it != mapa1.end(); it++)
        cout << "A chave " << it->first << " => " << it->second << endl;
    cout << endl << endl << endl;


    /*
        - Multimap, são mapas onde você pode ter vários elementos com chaves equivalentes
        - Utilizando multimap:
            -> Declaração, ex:
                multimap<int, string> mm;

                mm.insert(pair<int, string>(1, "python 2 "));
                mm.insert(pair<int, string>(1, "python 3 "));
    */

    multimap<int, string> mm; //Declarando um multimap

    //Inserindo elementos através do pair
    mm.insert(pair<int, string>(1, "python 2"));
    mm.insert(pair<int, string>(1, "python 3"));
    mm.insert(pair<int, string>(2, "C"));
    mm.insert(pair<int, string>(2, "C++"));
    mm.insert(pair<int, string>(3, "ruby"));

    multimap<int, string>::iterator it_mm = mm.begin();

    /*
        - Lembrando que o iterator é um ponteiro que aponta para o endereço de memória de um objeto map neste caso
    */

    while(it_mm != mm.end())
    {
        cout << "Key => " << (*it_mm).first << " Valor => " << (*it_mm).second << endl;
        it_mm++;
    }

     cout << endl << endl << endl;
    // FIM - multimap



    /*
        Funções da map, lower_bound(min_key) e upper_bound(max_key)
            Descrição: retorna o endereço para os elementos cujas as chaves vão dos limites específicados como mínimo no 
            lower_bound e máximo no upper_bound
    */

    multimap<int, string> mm_1; //Declarando um multimap

    //Inserindo elementos através do pair
    mm_1.insert(pair<int, string>(1, "python 2"));
    mm_1.insert(pair<int, string>(1, "python 3"));
    mm_1.insert(pair<int, string>(3, "C"));
    mm_1.insert(pair<int, string>(4, "C++"));
    mm_1.insert(pair<int, string>(4, "ruby"));

    multimap<int, string>::iterator it_low, it_up, it_mm_AUX; //Declarando os iteradores

    it_low = mm_1.lower_bound(2); //Atribuindo o endereço do elemento cuja chave = 2
    it_up = mm_1.upper_bound(4);  //Atribuindo o endereço do elemento cuja chave = 4

    //Imprimindo elementos referenciados de it_low até it_up
    for (it_mm_AUX = it_low; it_mm_AUX != it_up; ++it_mm_AUX)
        cout << it_mm_AUX->first << " => " << it_mm_AUX->second << endl;

    return 0;
}