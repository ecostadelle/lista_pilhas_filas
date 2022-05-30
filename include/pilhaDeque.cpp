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

bool PilhaDeque::empty()
{
    return (d.tamanho()==0);
}

char PilhaDeque::top()
{
    return d.buscaFim();
}

void PilhaDeque::push(char t)
{
    d.insereFim(t);
}

char PilhaDeque::pop()
{
    return d.removeFim();
}