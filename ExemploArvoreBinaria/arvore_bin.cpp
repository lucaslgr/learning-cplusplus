#include <iostream>

using namespace std;

class No
{
    private:
        No *No_Left, *No_Right;
        int key;
    
    public:
        No(int key)
        {
            this->key = key;
            No_Left = NULL;
            No_Right = NULL;
        }

        int getkey()
        {
            return this->key;
        }
        
        No* getLeft()
        {
            return this->No_Left;
        }

        No *getRight()
        {
            return this->No_Right;
        }

        void setLeft(No *noLeft)
        {
            this->No_Left = noLeft;
        }

        void setRight(No *noRight)
        {
            this->No_Right = noRight;
        }
};


class Arvore
{
    private:
        No *Root;
    
    public:
        Arvore()
        {
            Root = NULL;
        }

        void inserir(int key)
        {
            if (Root == NULL)
            {
                Root = new No(key);
            }
            else
            {
                inserirAux(Root, key);
            }
        }

        void inserirAux(No *no, int key)
        {
            if (key < no->getkey())
            {
                if (no->getLeft() == NULL) {
                    No *novo_no = new No(key);
                    no->setLeft(novo_no);
                }
                else
                {
                    inserirAux(no->getLeft(), key);
                }
            }
            else if (key > no->getkey())
            {
                if (no->getRight() == NULL)
                {
                    No *novo_no = new No(key);
                    no->setRight(novo_no);
                }
                else
                {
                    inserirAux(no->getRight(), key);
                }
            }
        }

        No *getRoot()
        {
            return this->Root;
        }

        void emOrdem(No* no)
        {
            if (no != NULL) 
            {
                emOrdem(no->getLeft());
                cout << no->getkey() << " ";
                emOrdem(no->getRight());
            }
            
        }
};

int main(int agrc, char *agrv[])
{
    Arvore tree1;

    tree1.inserir(8);
    tree1.inserir(10);
    tree1.inserir(14);
    tree1.inserir(13);
    tree1.inserir(3);
    tree1.inserir(1);
    tree1.inserir(6);
    tree1.inserir(4);
    tree1.inserir(7);

    cout << "Percorrendo em ordem..." << endl;
    tree1.emOrdem(tree1.getRoot());

    return 0;
}