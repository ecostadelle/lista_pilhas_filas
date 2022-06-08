#ifndef _OBTER_MINIMO_HPP_
#define _OBTER_MINIMO_HPP_

#include <stack>

class PilhaMin
{
private:
    std::stack<int> pilhaPrincipal;
    std::stack<int> pilhaAuxiliar;

public:
    // incluir variáveis necessárias
    int topo();
    int desempilha();
    void empilha(int t);
    int obterMinimo();
    // mais métodos auxiliares
    bool vazio();
};

#include "obterMinimo.cpp"

#endif