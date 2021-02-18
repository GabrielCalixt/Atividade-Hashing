#include <iostream>
#include "Diretorio.h"
#include "Balde.h"
#include <cstdlib>
using namespace std;

vector<string> geraPseudoChaves(int n, int t);
vector<string>  geraPseudoChavesIdigual(int n, int t);

int main()
{
    int M, t, N;
    cout<< "Digite o valor de M" << endl;
    cin >> M;
    cout << "Digite o tamanho das pseudochaves" << endl;
    cin >> t;
    cout << "Digite o valor de N"<< endl;
    cin >> N;
    Diretorio d = Diretorio(M, M, t);
    cout << "oi";
    //teste 1
    vector<string> chaves = geraPseudoChaves(N, t);
    for(int i=0; i < chaves.size(); i++)
    cout << chaves[i] << endl;
    vector<string> chavesIDigual= geraPseudoChavesIdigual(N, t);

    for(int i = 0; i<N; i++){
        d.inserirChave(chaves[i]);
    }
    for(int i = 0; i<N; i++){
        d.inserirChave(chavesIDigual[i]);
    }
}

vector<string>  geraPseudoChaves(int n, int t){
    vector<string> chaves;
    vector<char> chave;
    for(int i =0; i<n; i++){
        for(int j = 0; j<t; j++){
            int aux = rand()% 1;
            chave.push_back(aux);
        }
        string s(chave.begin(), chave.end());
        chaves.push_back(s);
        chave.clear();
    }
    return chaves;
}

vector<string>  geraPseudoChavesIdigual(int n, int t){
    vector<string> chaves;
    for(int i =0; i<n; i++){
        vector<char> chave;
        for(int j = 0; j<t; j++){
            if(j==t-2) chave.push_back(1);
            else if(j==t-1) chave.push_back(1);
            else chave.push_back(rand()% 1);
        }
        string s(chave.begin(), chave.end());
        chaves.push_back(s);
        chave.clear();
    }
    return chaves;
}

