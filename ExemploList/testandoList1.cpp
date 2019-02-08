#include <iostream>
#include <list>

using namespace std;

bool par(const int &n)
{
    return(n % 2 == 0)? true : false;
}
/*
Usando na funcao list.sort()
Essa funcao deve ter os parametros bool compare_nocase (const std::string& first, const std::string& second)
Que receberá dois parâmetors, o primeiro elemento e o segundo da lista respectivamente e deve
retornar TRUE SE O PRIMEIRO ELEMENTO DEVE SER DEPOIS DO SEGUNDO e 
FALSE SE O O PRIMEIRO ELEMENTO DEVE SER PRIMEIRO QUE O SEGUNDO
*/
bool comparar_tamanho(const string &str1, const string &str2)
{
    //Se o tamanho da primeira string deve vir antes, então retorna true
    return( (str1.length() < str2.length() ) ? true : false );
}


int main()
{
    list<int> l1; // lista de inteiros vazia
    list<int> l2(3, 10); //três inteiros com o valor 10
    list<int>::iterator it;

    // Inserindo elementos em l1 - push_back e push_front
    l1.push_back(10); //l1: 10
    l2.push_front(20); //l1: 20, 10
    l1.push_back(30); //l1: 20, 10, 30

    cout << "Mostrando os elementos de l1: \n";
    for(it = l1.begin(); it != l1.end() ; it++)
        cout << *it << endl;

    cout << "Mostrando os elementos de l2: \n";
    for (it = l2.begin(); it != l2.end(); it++)
        cout << *it << endl;


    //Acessando o primeiro e último elemento de l1 - front e back
    cout << "\nPrimeiro elemento de l1: " << l1.front();
    cout << "\nUltimo elemento de l1: " << l1.back();

    cout << "\nTamanho de l1: " << l1.size() << endl;

    //l1 : 20, 10, 30
    //removendo o primeiro elemento de l1
    l1.pop_front(); // remove o 20
    //removendo o último elemento de l1
    l1.pop_back(); //remove o 30

    cout << "\nMostrando novamente os elemento de l1:\n";
    for(it = l1.begin(); it != l1.end(); it++)
        cout << *it << endl;

    //Removendo todos os elementos de 12
    while(!l2.empty())
        l2.pop_front();
    
    cout << "\nNovo tamanho de l2: " << l2.size() << endl;

    //Atribuindo elementos a l2 - funcao assign
    int vet[] = {1, 2, 3, 4};

    l2.assign(vet, (vet  + 3) );
    cout << "\nMostrando os elementos de l2: \n";
    for (it = l2.begin(); it != l2.end(); it++)
        cout << *it << endl;

    //Inserindo um elemento em l2 com a função insert
    l2.insert(l2.begin(), 100);
    cout << "\nMostrando os elementos de l2: \n";
    for (it = l2.begin(); it != l2.end(); it++)
        cout << *it << endl;
    
    it = l2.begin();
    it++; //apontando para o segundo endereço
    l2.insert(it, 200);
    cout << "\nElementos de l2:\n";
    for(it = l2.begin(); it != l2.end(); it++)
    {
        cout << *it << endl;
    }
    
    //Inserindo duas vezes o valor 50 na primeira posicao
    l2.insert(l2.begin(), 2, 50);
    cout << "\nElementos de l2:\n";
    for (it = l2.begin(); it != l2.end(); it++)
    {
        cout << *it << endl;
    }

    //Apaga os dois primeiros números
    list<int>::iterator it2 = l2.begin();
    it2++;
    it2++;
    l2.erase(l2.begin(), it2);
    cout << "\nElementos de l2:\n";
    for (it = l2.begin(); it != l2.end(); it++)
    {
        cout << *it << endl;
    }

    //Remover todos os elementos - função clear
    l2.clear();
    cout << "\nNovo tamanho de l2: " << l2.size() << endl;

    //Função splice - transfere elementos de uma lista para outra
    list<int> lista1(2, 10), lista2(2, 20);
    it = lista1.begin();
    it++; //Apontando para segunda posicao
    //transfere elementos de lista2 para lista1
    lista1.splice(it, lista2); //Insere todos os elementos da lista 2 a partir da primeira posicao da lista 1
    cout << "\nElementos da lista1:  \n";
    for (it = lista1.begin(); it != lista1.end(); it++)
        cout << *it << endl;
    
    cout <<"\nTamanho de lista2: " << lista2.size() << endl;

    //Remover todos os elementos iguais a um determinado valor -> function remove
    lista1.remove(20);
    cout << "\nElementos da lista1 sem os elementos de valor = 20:  \n";
    for (it = lista1.begin(); it != lista1.end(); it++)
        cout << *it << endl;

    //Função remove_if, que remove se ocorrer determinada condição
    int vet2[] = {6, 8, 10, 5, 20, 21};
    list<int> lista3(vet2, vet2 + 6);
    cout << "\nElementos da lista3 antes da remocao:\n";
    for (it = lista3.begin(); it != lista3.end(); it++)
        cout << *it << endl;
    
    //Removendo todos os elementos pares da lista 3
    //list.remove_if(funcao que testa CADA elemento da lista e retorna true para remocao ou false para NAO reomcao)
    lista3.remove_if(par); //Nota que essa é uma função assincrona

    cout << "\nElementos da lista3 apos a remocao:\n";
    for (it = lista3.begin(); it != lista3.end(); it++)
        cout << *it << endl;

    // Trabalhando com a ordenação de listas
    int vet3[] = {17, 60, 5, 30, 50};
    list<int> lista4 (vet3, vet3 + 5);
    //A funcao .sort() ordena os elementos crescentemente POR PADRÃO
    lista4.sort();
    cout << "\nElementos da lista4 ordenados crescentemente:\n";
    for (it = lista4.begin(); it != lista4.end(); it++)
        cout << *it << endl;

    //Ordenando strings
    list<string> lista5;
    list<string>::iterator it5;
    lista5.push_back("Python");
    lista5.push_back("C++");
    lista5.push_back("Ruby");
    lista5.push_back("Haskell");
    lista5.sort();
    cout << "\nElementos STRING da lista5 ordenados crescentemente:\n";
    for (it5 = lista5.begin(); it5 != lista5.end(); it5++)
        cout << *it5 << endl;

    //Ordenando usando um criterio DEFINIDO A SUA ESCOLHA
    //Exemplo: ordenando pelo tamanho da string
    list<string> lista6;
    list<string>::iterator it6 = lista6.begin();
    lista6.splice(it6, lista5);

    lista6.sort(comparar_tamanho);
    cout << "\nElementos STRING da lista6 ordenados de acordo com a funcao comparar_tamanho:\n";
    for (it6 = lista6.begin(); it6 != lista6.end(); it6++)
        cout << *it6 << " - Tamanho: " << (*it6).length() << endl;

    return 0;
}