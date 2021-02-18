#ifndef DIRETORIO_H
#define DIRETORIO_H

#include "Balde.h"
#include <iostream>
using namespace std;
#include <string>
#include <math.h>
#include <vector>

class Diretorio
{
    public:
        Diretorio(int tam, int p, int pseudo);
        ~Diretorio();
        void inserirChave(string chave);
        bool buscarChave(string chave);
        void dividirBalde(string diretorio);
        void duplicarDiretorio();
        int hashingReverso(string chav);
        string hashing(int chave);


    private:
        vector <Balde*> baldes;
        int tamBalde;
        int profundidadeGlobal;
        int tamPseudoChave;
        int numeroBaldes;
        int numChaves;
};

#endif // DIRETORIO_H
