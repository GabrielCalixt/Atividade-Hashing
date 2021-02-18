#ifndef BALDE_H
#define BALDE_H

#include <iostream>
using namespace std;

class Balde
{
    public:
        Balde(int tam);
        ~Balde();
        int getTam();
        void setId(int i);
        int getId();
        string getChave(int indice);
        void setChave(string chave, int i);
        void setOcupacao(int i){ this->ocupacao = i;};
        int getOcupacao(){ return ocupacao;};
        bool baldeCheio();

    private:
        int tam;
        string *interior;
        int id;
        int ocupacao;

};

#endif // BALDE_H
