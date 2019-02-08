class Pilha
{
    private:
        int *vet;
        int max_tamPilha;
        int topo_Pilha;

    public:
        Pilha();

        ~Pilha();
        
        void push_back(int e); //Empilhar

        void pop_back(); //Desempilhar

        int getTopo();

        int vazia();
};