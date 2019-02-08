/*
Estudando: try, catch e throw.
Note: Quando try for executado e captar algum erro, será lançado com throw e captado com catch uma variável
ou mensagem, se for uma mensagem->string, ela deverá ser captada com um const char*, que é um ponteiro de
char pois o throw a retornará como o endereço de memória de um vetor de char-> char[].
Note: Quando o loop cai em um catch ele acusa o erro e o código main termina ali.
*/

#include <iostream>

using namespace std;

//Função divisao apenas para teste do try, throw e catch
int divisao(double a, double b)
{
    if (b == 0)
        throw "Nao e possivel a divisao por zero!!";
    else     
        return (a/b);
}

//Função fatorial apenas para teste do try, throw e catch
int fat(int n)
{
    if (n < 0) {
        /*
        A palavra chave throw é um retorno de resposta do tipo ERRO que retorna 
        um endereço de memória para um const char[] que é captado automaticamente pela função catch
        */
        throw "Numero negativo!!";
    }
    if (n==0 || n == 1) {
        return 1;
    }
    return n * fat(n - 1);
}

int main(int agrc, char *argv[])
{
    try
    {
        cout << "Fatorial de 5: " << fat(5) << endl;
        //cout << "Fatorial de -5: " << fat(-5) << endl;
        cout << "Divisao 5 / 0: " << divisao(5,0) << endl;
    }
    //catch para capturar a exceção específica, o parâmetro recebe: const char* e = char[] msg
    catch (const char *errorMsg)
    {
        cerr << "Erro: " << errorMsg << endl;
    }
    //Esse catch capta QUALQUER ERRO não definido 
    catch(...)
    {
        cerr << "Qualquer erro" << endl;
    }
    return 0;
}