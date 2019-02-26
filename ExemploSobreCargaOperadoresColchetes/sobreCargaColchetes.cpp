/*
    SOBRECARREGANDO O OPERADOR DE ÍNDICE [ ] "Colchetes"

    - Objetivos:
        -> Não permitir que o usuário tente accessar índices negativos do vetor (Pois não existe)
*/

#include <iostream>
#include <stdlib.h> //Função exit(1);

using namespace std;

class Vetor
{
    private:
        int MAX;
        int *vet, *vet_pos;

    public:
        Vetor(int max = 100) //Se não for passado um tamanho, será atribuído 100 como padrão
        {
            if (max < 0)
            {
                cerr << "Erro: Nao eh possível alocar um tamanho negativo, informe um valor maior do que 0" << endl;
                exit(1); //Fução para abortar o programa, é da biblioteca stdlib.h
            }
            else if ( max > 1000000) 
            {
                cerr << "Erro: Nao eh possível alocar um espaço maior que um milhão" << endl;
                exit(1);
            }
            
            //Se não entrou em nenhum dos casos acima, podemos atribuir os valores ao MAX
            this->MAX = max;


            //Alocando espaço
            vet = (int*)malloc( MAX * sizeof(int));
            vet_pos = (int*)malloc(MAX * sizeof(int));

            for (int i = 0; i < MAX; i++) //Inicializando o v_pos com ZEROS
                vet_pos[i] = 0;         
        }

        //Destrutor para desalocar
        ~Vetor()
        {
            delete[] vet;
        }

        //Função inserir elementos
        bool inserir(int elemento, int posicao)
        {
            if (posicao < MAX && posicao >= 0)
            {
                vet[posicao] = elemento;
                vet_pos[posicao] = 1; //Se inserir elemento no vetor, o vet_pos recebe valor = 1 nessa mesma posicao
                return true; //Retorna true e encerra a funcao
            }
            return false;
        }

        int& operator[] (int i)
        {
            if (i < 0 || i > MAX) // Pegando posicao negativa OU uma posicao que não exista
            {
                cerr << "Erro: Acesso invalido ao vetor. \n";
                exit(1);
            }
            else if(vet_pos[i] == 0) //Captando a condição de quando o usuário tenta acessar uma posição VAZIA do vetor
            {
                cerr << "Erro: Nesta posicao nao existe nenhum elemento.\n";
                exit(1);
            }
            return vet[i]; // Se não entrar em cima ele retornará o valor do vetor NESSA POSIÇÃO
        }

        int tam()
        {
            int cont = 0;

            for(int i = 0; i < MAX; i++) //Roda todos elementos do vetor
            {
                if (vet_pos[i] == 1) //Conta apenas as posicoes que possuem elementos
                {
                    cont++;
                }
            }
            return cont;
        }
};

int main (int agrc, const char *agrv[])
{
    Vetor v(10); //Usando o construtor

    if (v.inserir(10, 0)) //Insere o elemento 10 na posicao 0
        cout << "Elemento inserido com sucesso!\n";
    else
        cout << "Erro ao inserir o elemento!\n";

    if (v.inserir(11, 2)) //Insere o elemento 10 na posicao 0
        cout << "Elemento inserido com sucesso!\n";
    else
        cout << "Erro ao inserir o elemento!\n";

    if (v.inserir(12, 10)) //Aqui vai dar erro, pois o elemento vai da posicao 0 há posição 9
        cout << "Elemento inserido com sucesso!\n";
    else
        cout << "Erro ao inserir o elemento!\n";


    //Testando a sobrecarga de operador [] da nossa classe
    cout << "Primeiro elemento: " << v[0] << endl;
    //cout << "Segundo elemento: " << v[1] << endl; //Aqui ele vai printar um lixo, pois não inserimos nenhum elemento na segunda posicao
    cout << "Terceiro elemento: " << v[2] << endl;

    //Tamanho do vetor
    cout << "Tamanho do vetor: " << v.tam() << endl;

    return 0;
}