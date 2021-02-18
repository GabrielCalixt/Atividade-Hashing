#include "Diretorio.h"
#include <iostream>

using namespace std;

Diretorio::Diretorio(int t, int p, int pseudo)
{
    this->tamBalde = t;
    this->profundidadeGlobal = p;
    this->tamPseudoChave = pseudo;
    baldes.push_back(new Balde(t));
    //baldes[1]->setId(1);
    this->numeroBaldes = 1;
}

Diretorio::~Diretorio()
{
    //dtor
}

bool Diretorio::buscarChave(string chave){
    int i =0;
    string id = chave.substr(0, profundidadeGlobal/2);
    int aux = hashingReverso(id); //aplica a fucnao de hashing
    while( i< profundidadeGlobal){ //identificando o balde
        if(aux == baldes[i]->getId()){
            for(int j = 0; j < tamBalde; j++){
                if (baldes[i]->getChave(j) == chave) return true; //busca a pseudochave no balde
            }
        }
    }
    return false;

}

string Diretorio::hashing(int chave){

    string binario;
    while(chave!=0) {
        binario=(chave%2==0 ?"0":"1")+binario;
        chave/=2;
    }
    while(binario.length() < tamPseudoChave){
        binario.append(1, (char) '0');
    }
    return binario;
}

int Diretorio::hashingReverso(string chave){
    int decimal;
    for( int i=0; i < chave.length(); i++ ) decimal += pow( 2,chave.length()-1-i )*(chave[i]-'0');
    return decimal;
}

void Diretorio::inserirChave(string chave){
    //aplicar hashing sobre chave
    //profundidade do diretorio
    //acessa o balde
    //analisa se ha espaco, se sim insere chave
    //se nao duplica o diretorio e realiza divisao do balde e incrementa profundidade
    string id = chave.substr(0, profundidadeGlobal/2);
    int aux = hashingReverso(id);
    int i= 0;
    while(i <profundidadeGlobal){
        if(aux == baldes[i]->getId()){
            for (int j = 0; j< tamBalde; j++){
                if(baldes[i]->getOcupacao() < baldes[i]->getTam()){
                    baldes[i]->setChave(chave, baldes[i]->getOcupacao());
                    baldes[i]->setOcupacao(baldes[i]->getOcupacao()+1);
                }
                else {
                    if(numeroBaldes == profundidadeGlobal){
                        duplicarDiretorio();
                        baldes.push_back(new Balde(tamBalde));
                        baldes[numeroBaldes-1]->setChave(chave, 1);
                        numeroBaldes++;
                        //reajuste de ponteiros????
                    }
                    else{
                        baldes.push_back(new Balde(tamBalde));
                        baldes[numeroBaldes-1]->setChave(chave, 1);
                        numeroBaldes++;
                    }
                }
            }

        }
    }

}

void Diretorio::dividirBalde(string Diretorio){

}

void Diretorio::duplicarDiretorio(){
    this->profundidadeGlobal = profundidadeGlobal*2;
}

