#include <iostream>
#include "pilhaDeque.h"

PilhaDeque::PilhaDeque()
{
    std::cout << "Construtor chamado" << std::endl;
}

PilhaDeque::~PilhaDeque()
{
    d.~Deque();
    std::cout << "Destrutor chamado" << std::endl;
}

int PilhaDeque::tamanho()
{
    return d.tamanho();
}

char PilhaDeque::buscaFim()
{
    return d.buscaFim();
}

void PilhaDeque::insereFim(char t)
{
    d.insereFim(t);
}

char PilhaDeque::removeFim()
{
    return d.removeFim();
}