//Sobrecarga do operador +
#include <iostream>

using namespace std;

//Número complexo
class Complexo {
    
    //Membros
    public:    
        int numReal;
        int numIMG;
        int num3;

    //Construtor
    Complexo (int numReal, int numImg)
    {
        this->numReal = numReal;
        this->numIMG = numImg;
    }

    //Sobrecarga do operador +
    //O operador nada mais é que uma função que é acionada pelo primeiro membro, ou em outras palavras
    //pelo membro que está ao lado direito do operador
    Complexo operator+ (Complexo &numComplexo2)
    {
        return Complexo(this->numReal + numComplexo2.numReal, this->numIMG + numComplexo2.numIMG);
    }
   
};


main (int agrc, const char* argv[])
{
    Complexo numComplexo1 = Complexo(2, 3);
    Complexo numComplexo2 = Complexo(1, 1);

    Complexo numComplexo3 = numComplexo1 + numComplexo2;
    //OU, que é a memsa coisa
    //numComplexo3 = numComplexo1.operator+(numComplexo2);

    cout << "Número complexo 3: "<< endl;
    cout << "Parte real: "<< numComplexo3.numReal <<  endl<< "Parte imaginária: "<< numComplexo3.numIMG << endl << endl;

    return 0;
}