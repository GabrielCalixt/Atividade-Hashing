#include "Balde.h"
#include <iostream>
using namespace std;

Balde::Balde(int tam)
{
    this->tam = tam;
    this->ocupacao = 0;
    this->interior = new string[tam];
}

Balde::~Balde()
{
    delete[] interior;
}

int Balde::getTam(){
    return tam;
}



void Balde::setId(int i){
    this->id = i;
}

int Balde::getId(){
    return id;
}

string Balde::getChave(int i){
    return interior[i];
}

void Balde::setChave(string chave, int i){
    interior[i]= chave;
    ocupacao++;
}

bool Balde::baldeCheio()
{
    return ( this->ocupacao == this->tam );
}
